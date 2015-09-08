//
//  TopMenu.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#include "TopMenu.h"
#include "TopTitle.h"


bool TopMenu::init()
{
    if(!ccxGameNode::init()) return false;
    return true;
}

void TopMenu::onEnter()
{
    ccxGameNode::onEnter();
    setInfo();
}
void TopMenu::setInfo()
{
    auto titleBG = getTitleSprite();
    for(int i = 0 ; i < 3 ; i++)
    {
        auto menu = Sprite::create("UI_TopMenuBG.png");
        menu->setPosition(Vec2(menu->getContentSize().width/2 + (menu->getContentSize().width * i), titleBG->getPosition().y - (titleBG->getContentSize().height + menu->getContentSize().height/2)));
        addChild(menu);
        
        auto menuName = setLabelSystemTTFUnAdd(i==0?"공간":i==1?"분위기":"가격", 18, Vec2(menu->getContentSize().width/2, menu->getContentSize().height/2 - 15));
        menuName->setColor(Color3B::WHITE);
        menu->addChild(menuName);
        
        auto btnStorage = Sprite::create(i==0?"UI_Space_Up.png":i==1?"UI_Mood_Up.png":"UI_Price_Up.png");
        btnStorage->setTag(i==0 ? TAG_TOP_BUTTON_SPACE:i==1 ?TAG_TOP_BUTTON_MOOD : TAG_TOP_BUTTON_PRICE);
        btnStorage->setScale(0.8f);
        btnStorage->setPosition(Vec2(menuName->getPositionX(), menuName->getPositionY() + menuName->getContentSize().height/2 + btnStorage->getContentSize().height/2 - 2));
        menu->addChild(btnStorage);
        
        
        
        _vMenu.pushBack(menu);
    }
}

Sprite* TopMenu::getTitleSprite()
{
    auto bg = Sprite::create("UI_TopTitleBG.png");
    bg->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    bg->setPosition(Vec2(0, screenSizeY));
    return bg;
}

void TopMenu::addDownImage(Point pt)
{
    for(Sprite* bg : _vMenu)
    {
        if(bg->getBoundingBox().containsPoint(pt))
        {
            bg->getChildren().at(0)->setColor(Color3B::GRAY);
            
            if(bg->getChildByTag(TAG_TOP_BUTTON_SPACE))
            {
                auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_SPACE));
                btnImg->setColor(Color3B::GRAY);
            }
            else if(bg->getChildByTag(TAG_TOP_BUTTON_MOOD))
            {
                auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_MOOD));
                btnImg->setColor(Color3B::GRAY);
            }
            else if(bg->getChildByTag(TAG_TOP_BUTTON_PRICE))
            {
                auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_PRICE));
                btnImg->setColor(Color3B::GRAY);
            }
        }
    }
}
void TopMenu::addNormalImage(Point pt)
{
    
    for(Sprite* bg : _vMenu)
    {
        if(bg->getBoundingBox().containsPoint(pt))
        {
            //메뉴가 터치되고 안에서 업되면 메뉴실행.
            auto lbMenu = static_cast<Label*>(bg->getChildren().at(0));
            if(getParent()->getChildByTag(TAG_SUB_LIST))
            {
                UISubList* list = static_cast<UISubList*>(getParent()->getChildByTag(TAG_SUB_LIST));
                list->removeFromParent();
                log("removeList");
            }
            else if(lbMenu->getString().compare("공간") == 0)
            {
                log("%s",lbMenu->getString().c_str());
                UISubList* list = UISubList::create();
                list->setTag(TAG_SUB_LIST);
                list->initSpaceList();
                list->setdelegate(this);
                getParent()->addChild(list);
            }
            else if(lbMenu->getString().compare("분위기") == 0)
            {
                log("%s",lbMenu->getString().c_str());
                UISubList* list = UISubList::create();
                list->setTag(TAG_SUB_LIST);
                list->initAirList();
                list->setdelegate(this);
                getParent()->addChild(list);
            }
            else if(lbMenu->getString().compare("가격") == 0)
            {
                log("%s",lbMenu->getString().c_str());
                UISubList* list = UISubList::create();
                list->setTag(TAG_SUB_LIST);
                list->initPriceList();
                list->setdelegate(this);
                getParent()->addChild(list);
            }
            else
            {
                
            }
            
        }
        
        //글시 색깔바꾼다.
        bg->getChildren().at(0)->setColor(Color3B::WHITE);
        if(bg->getChildByTag(TAG_TOP_BUTTON_SPACE))
        {
            auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_SPACE));
            btnImg->setColor(Color3B::WHITE);
        }
        else if(bg->getChildByTag(TAG_TOP_BUTTON_MOOD))
        {
            auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_MOOD));
            btnImg->setColor(Color3B::WHITE);
        }
        else if(bg->getChildByTag(TAG_TOP_BUTTON_PRICE))
        {
            auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_TOP_BUTTON_PRICE));
            btnImg->setColor(Color3B::WHITE);
        }
    }
}

void TopMenu::didFinishSelectedSubList(cocos2d::Ref *sender)
{
    auto btn = static_cast<Button*>(sender);
    
    
    
    if(btn->getTitleText().compare("전체") == 0 || btn->getName().compare(getPurePriceNum(USER_DB->getvPriceList().at(0))->getCString()) == 0)
    {
        //만약 선택한 버튼이 전체이면 들어옴
        auto menuBox =  static_cast<MenuBoxManager*>(getParent()->getChildByTag(TAG_MENUBOX));
        menuBox->removeListViewChildren();
        
        //디비에 있는 이미지 중에서 버튼과 일치하는 목록을 리스트 박스에 추가한다.
        for(ImageInfoParser* imageData : USER_DB->getTotalImageInfo())
        {
            menuBox->setBoxWithImgInfo(imageData);
        }
        menuBox->setListView();
    }
    else
    {
        //아닐경우
        setCurrentList(btn, USER_DB->getvSpaceList());
        setCurrentList(btn, USER_DB->getvAirList());
        setCurrentList(btn, USER_DB->getvPriceList());
    }
}

void TopMenu::setCurrentList(Button* btn, Vector<__String*> vList)
{
    
    for(int i = 0 ; i < vList.size() ; i++)
    {
        const char* text = vList.at(i)->getCString();
        
        if(btn->getTitleText().compare(text) == 0 || btn->getName().compare(getPurePriceNum(__String::createWithFormat("%s",text))->getCString()) == 0)
        {
            //            log("btntitle: %s, text:%s",btn->getTitleText().c_str(),text);
            //            log("%d",btn->getTitleText().compare(text));
            //중간에 붙어있는 리스트 박스
            auto menuBox =  static_cast<MenuBoxManager*>(getParent()->getChildByTag(TAG_MENUBOX));
            menuBox->removeListViewChildren();
            
            //디비에 있는 이미지 중에서 버튼과 일치하는 목록을 리스트 박스에 추가한다.
            for(ImageInfoParser* imageData : USER_DB->getTotalImageInfo())
            {
                if(imageData->getspace()->compare(btn->getTitleText().c_str()) == 0)
                {
                    menuBox->setBoxWithImgInfo(imageData);
                }
                else if(imageData->getair()->compare(btn->getTitleText().c_str()) == 0)
                {
                    menuBox->setBoxWithImgInfo(imageData);
                }
                //디비에 있는 이미지 중에서 버튼과 일치하는 목록을 리스트 박스에 추가한다.
                if(imageData->getprice()->compare(btn->getName().c_str()) == 0)
                {
                    menuBox->setBoxWithImgInfo(imageData);
                }
                log("%s", btn->getName().c_str());
            }
            menuBox->setListView();
        }
    }
}

__String* TopMenu::getPurePriceNum(__String* str)
{
    
    __Array* arrCompStr = str->componentsSeparatedByString(",");
    if(arrCompStr->count() > 2)
    {
        __String* str = static_cast<__String*>(arrCompStr->getObjectAtIndex(1));
        return str;
    }
    else
    {
        return __String::create("");
    }
}

void TopMenu::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    addDownImage(pt);
}
void TopMenu::onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
{
    
}
void TopMenu::onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    
    addNormalImage(pt);
}


















