//
//  MenuBoxManager.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#include "MenuBoxManager.h"
#include "InfoScene.h"


bool MenuBoxManager::init()
{
    if(!ccxGameNode::init()) return false;
    
    
    
    return true;
}

void MenuBoxManager::onEnter()
{
    ccxGameNode::onEnter();
    
}

void MenuBoxManager::setListView()
{
    _lv = ui::ListView::create();
    
    for(ui::Button* button : _vButton)
    {
        _lv->setItemModel(button);
        _lv->pushBackCustomItem(button);
    }
    _lv->setTag(TAG_MENUBOXLIST);
    _lv->setItemsMargin(10);
    _lv->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    _lv->setSize(Size(screenSizeX, screenSizeY - 150));
    //    auto btnTemp = _vButton.at(0);
    //    _lv->setSize(Size(screenSizeX, btnTemp->getContentSize().height * _vButton.size()));
    //리스트 사이즈 확인 테스트용
    //        _lv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    //        _lv->setBackGroundColor(Color3B::BLUE);
    _lv->setBounceEnabled(true);
    _lv->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    _lv->setPosition(Vec2(5, screenSizeY - (GET_TOP_TITLE_SIZE + 5)));
    addChild(_lv);
}

void MenuBoxManager::setBoxWithList(Vector<ImageInfoParser*> imgInfo)
{
    if(_vButton.size() > 0)
    {
        log("ButtonVector has data will be remove");
        _vButton.clear();
    }
    if(getChildByTag(TAG_MENUBOXLIST))
    {
        getChildByTag(TAG_MENUBOXLIST)->removeFromParent();
    }
    for(int i = 0 ; i < imgInfo.size() ; i++)
    {
        ImageInfoParser* info = static_cast<ImageInfoParser*>(imgInfo.at(i));
        
        auto button = ui::Button::create("Main_BoxUp-hd.png", "Main_BoxDown-hd.png", "Main_BoxDown-hd.png");
        //        button->setTitleText("text");
        button->setTag(TAG_MAIN_BOX + info->getidx()->intValue());
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
        
        
        
        
        setTypeTitle(button, info->gettitle()->getCString());
        setTypeInfo(button, __String::createWithFormat("%s / %s",info->getspace()->getCString(),info->getair()->getCString())->getCString());
        setPrice(button, __String::createWithFormat("%s", info->getprice()->getCString())->intValue());
        setImageWithName(button, __String::createWithFormat("%s", info->getimgName()->getCString())->getCString());
        
        _vButton.pushBack(button);
    }
    setListView();
}
void MenuBoxManager::setBoxWithImgInfo(ImageInfoParser* imgInfo)
{
    auto button = ui::Button::create("Main_BoxUp-hd.png", "Main_BoxDown-hd.png", "Main_BoxDown-hd.png");
    //        button->setTitleText("text");
    button->setTag(TAG_MAIN_BOX + imgInfo->getidx()->intValue());
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
    button->setTouchEnabled(true);
    setTypeTitle(button, imgInfo->gettitle()->getCString());
    setTypeInfo(button, __String::createWithFormat("%s / %s",imgInfo->getspace()->getCString(),imgInfo->getair()->getCString())->getCString());
    setPrice(button, __String::createWithFormat("%s", imgInfo->getprice()->getCString())->intValue());
    setImageWithName(button, __String::createWithFormat("%s", imgInfo->getimgName()->getCString())->getCString());
    
    _vButton.pushBack(button);
}

void MenuBoxManager::removeSubList(Ref* sender)
{
    log("in remove sublist");
    if(getParent()->getChildByTag(TAG_SUB_LIST))
    {
        UISubList* sublist = static_cast<UISubList*>(getParent()->getChildByTag(TAG_SUB_LIST));
        sublist->removeFromParent();
    }
    
    
}

void MenuBoxManager::buttonCallBack(Ref* sender)
{
    //메인화면 박스 선택시 정보화면 으로 바뀜
    auto button = (ui::Button*)sender;
//    log("button tag %d", button->getTag());
    USER_DB->setDocInfoIdx(__String::createWithFormat("%d",button->getTag() - TAG_MAIN_BOX));
//    log("save infoIdx : %d",button->getTag() - TAG_MAIN_BOX);
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, InfoScene::createScene()));
}

void MenuBoxManager::setImageWithName(Button* button, const char* ImgName)
{
    //    auto lbInfo = button->getChildByTag(TAG_MENU_BOX_TITLE);
    
    //이미지를 박스크기에 맞게 자르기 위한 임시 이미지
    
    auto tempSprite  =  Sprite::create("Main_BoxDown-hd.png");
    //이미지를 라벨을 뺀 크기로 만든다.
    Rect rc = tempSprite->getTextureRect();
    tempSprite->setTextureRect(Rect(rc.origin.x, rc.origin.y, rc.size.width- 6, rc.size.height - (_tempPoint.y + _tempSize.height)));
    
    auto layout = Layout::create();
    layout->setSize(Size(tempSprite->getTextureRect().size.width,
                         tempSprite->getTextureRect().size.height));
    // ImageView를 생성하고 Layout에 add함
    auto imageView = ImageView::create(StringUtils::format("%s",ImgName));
    //    imageView->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    //    imageView->setPosition(Vec2(2, 2));
    imageView->setTextureRect(tempSprite->getTextureRect());
    imageView->setPosition(Vec2(button->getContentSize().width/2, button->getContentSize().height - (tempSprite->getContentSize().height/2 + 2)));
    layout->addChild(imageView);
    
    button->addChild(layout);
}

void MenuBoxManager::setTypeTitle(Button* button, const char* title)
{
    __String* cTitle = __String::createWithFormat("%s",title);
    auto lbTitle = Label::createWithSystemFont(cTitle->getCString(), "나눔고딕", 20);
    lbTitle->setColor(Color3B::BLACK);
    lbTitle->setAnchorPoint(Vec2(0, 0));
    lbTitle->setPosition(Vec2((button->getContentSize().width * 5 / 100), (button->getContentSize().height * 15)/ 100));
    lbTitle->setTag(TAG_MENU_BOX_TITLE);
    _tempPoint = lbTitle->getPosition();
    _tempSize = lbTitle->getContentSize();
    button->addChild(lbTitle);
    
}

void MenuBoxManager::setTypeInfo(Button* button, const char* info)
{
    __String* cInfo = __String::createWithFormat("%s",info);
    auto lbInfo = Label::createWithSystemFont(cInfo->getCString(), "나눔고딕", 15);
    lbInfo->setColor(Color3B::BLACK);
    lbInfo->setAnchorPoint(Vec2(0, 0));
    lbInfo->setPosition(Vec2((button->getContentSize().width * 5 / 100), (button->getContentSize().height * 5)/ 100));
    button->addChild(lbInfo);
}

void MenuBoxManager::setPrice(Button* button, int price)
{
    __String* cPrice = __String::createWithFormat("%d 만원",price);
    auto lbPrice = Label::createWithSystemFont(cPrice->getCString(), "나눔고딕", 20);
    lbPrice->setColor(Color3B::BLACK);
    lbPrice->setAnchorPoint(Vec2(1, 0));
    lbPrice->setPosition(Vec2(button->getContentSize().width - (button->getContentSize().width * 5 / 100), (button->getContentSize().height * 5)/100));
    button->addChild(lbPrice);
}

void MenuBoxManager::removeListViewChildren()
{
    _lv->removeFromParent();
    _vButton.clear();
}



























