//
//  UISubList.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 31..
//
//

#include "UISubList.h"

bool UISubList::init()
{
    if(!ccxGameNode::init()) return false;
    
    _delegate = nullptr;
    
    return true;
}

void UISubList::onEnter()
{
    ccxGameNode::onEnter();
    
    
    //    setSubListBG();
    //    setBoxSIInfos();
    //    setBox();
    //    setListView();
    //    moveAction();
}

void UISubList::initSpaceList()
{
    log("InitList");
    setSubListBG();
    setBoxWithText(USER_DB->getvSpaceList());
    setListView();
    moveAction();
}
void UISubList::initAirList()
{
    log("InitList");
    setSubListBG();
    setBoxWithText(USER_DB->getvAirList());
    setListView();
    moveAction();
}
void UISubList::initPriceList()
{
    log("InitList");
    setSubListBG();
    setBoxWithPriceText(USER_DB->getvPriceList());
    setListView();
    moveAction();
}

void UISubList::setSubListBG()
{
    _sSubBG = Sprite::create("UI_Sub_ListBG.png");
    _sSubBG->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    _sSubBG->setPosition(Vec2(screenSizeX + screenSizeX/4, screenSizeY - GET_TOP_TITLE_SIZE));
    addChild(_sSubBG);
}

void UISubList::moveAction()
{
    auto action_0 = FadeIn::create(0.2f);
    auto action_1 = MoveTo::create(0.2f, Vec2(screenSizeX/2 + screenSizeX/4, screenSizeY - GET_TOP_TITLE_SIZE));
    auto spawn = Spawn::create(action_0, action_1, NULL);
    _sSubBG->runAction(spawn);
}


void UISubList::setListView()
{
    ui::ListView* lv = ui::ListView::create();
    
    for(ui::Button* button : _vButton)
    {
        lv->setItemModel(button);
        lv->pushBackCustomItem(button);
    }
    
    lv->setItemsMargin(1);
    lv->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    lv->setSize(Size(_sSubBG->getContentSize().width, _sSubBG->getContentSize().height));
    //    lv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    lv->setBackGroundColor(Color3B::BLUE);
    lv->setBounceEnabled(true);
    lv->setPosition(Vec2(0, -5));
    _sSubBG->addChild(lv);
}

void UISubList::setBoxWithText(Vector<__String*> vStr)
{
    for(int i = 0 ; i < vStr.size() ; i++)
    {
        auto button = ui::Button::create("UI_Sub_ListBox-hd.png");
        button->setScale(0.9f);
        button->setZoomScale(0.05f);
        button->setTitleText(vStr.at(i)->getCString());
        button->setTitleFontSize(20);
        
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    
                    buttonCallBack(sender);
                    break;
                default:
                    break;
            }
        });
        
        _vButton.pushBack(button);
        
    }
}

void UISubList::setBoxWithPriceText(Vector<__String*> vStr)
{
    for(int i = 0 ; i < vStr.size() ; i++)
    {
        auto button = ui::Button::create("UI_Sub_ListBox-hd.png");
        button->setScale(0.9f);
        button->setZoomScale(0.05f);
//        if(vStr.at(i)->compare("100") == 0)
//        {
//            button->setTitleText(__String::createWithFormat("%s만원 이하",vStr.at(i)->getCString())->getCString());
//        }
//        else if(vStr.at(i)->compare("5000") == 0)
//        {
//            button->setTitleText(__String::createWithFormat("%s만원 이상",vStr.at(i)->getCString())->getCString());
//        }
//        else if(vStr.at(i)->compare("전체") == 0)
//        {
//            button->setTitleText(vStr.at(i)->getCString());
//        }
//        else
//        {
//            button->setTitleText(__String::createWithFormat("~%s 만원",vStr.at(i)->getCString())->getCString());
//        }
        __Array* compStr = vStr.at(i)->componentsSeparatedByString(",");
        Ref* rStr;
        __String* str = __String::create("");
        CCARRAY_FOREACH(compStr, rStr)
        {
            str->append(static_cast<__String*>(rStr)->getCString());
        }
        button->setName(static_cast<__String*>(compStr->getObjectAtIndex(1))->getCString());
        button->setTitleText(str->getCString());
        button->setTitleFontSize(20);
        
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    
                    buttonCallBack(sender);
                    break;
                default:
                    break;
            }
        });
        
        _vButton.pushBack(button);
    }
}

void UISubList::buttonCallBack(cocos2d::Ref *sender)
{
    log("subMenu");
    
    if(_delegate != nullptr)
    {
        _delegate->didFinishSelectedSubList(sender);
    }
    removeFromParent();
}










