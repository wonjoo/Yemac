//
//  EstimatePlace.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 24..
//
//

#include "EstimatePlace.h"

void EstimatePlace::onEnter()
{
    ccxGameNode::onEnter();
    
    setExplainLabel();
    setFirstSelect();
    setFirstPlaceSelect();
    
}

void EstimatePlace::setFirstPlaceSelect()
{
    _lvFirst = ui::ListView::create();
    
    for(ui::Button* button : _vFirstButton)
    {
        _lvFirst->setItemModel(button);
        _lvFirst->pushBackCustomItem(button);
        _lvFirst->setSize(Size(button->getContentSize().width + 1, screenSizeY-110));
    }
    
    _lvFirst->setItemsMargin(2);
    _lvFirst->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    
//    _lvFirst->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    _lvFirst->setBackGroundColor(Color3B::BLUE);
    _lvFirst->setBounceEnabled(false);
    _lvFirst->setPosition(Vec2(screenSizeX/2 - _lvFirst->getContentSize().width/2, 5));
    addChild(_lvFirst);
}

void EstimatePlace::setSecondPlaceSelect()
{
    if(_lvSecond != nullptr)_lvSecond->removeFromParent();
    
    _lvSecond = ui::ListView::create();
    
    for(ui::Button* button : _vSecondButton)
    {
        _lvSecond->setItemModel(button);
        _lvSecond->pushBackCustomItem(button);
        _lvSecond->setSize(Size(button->getContentSize().width + 1, screenSizeY-110));
    }
    
    _lvSecond->setItemsMargin(2);
    _lvSecond->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    
//    _lvSecond->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    _lvSecond->setBackGroundColor(Color3B::BLUE);
    _lvSecond->setBounceEnabled(false);
    _lvSecond->setPosition(Vec2(screenSizeX/2, 5));
    _lvSecond->setVisible(false);
    addChild(_lvSecond);
}

void EstimatePlace::setFirstSelect()
{
    for(int i=0;i<3;i++)
    {
        auto button = ui::Button::create("UI_TopMenuBG-hd.png");
        button->setBright(true);
        button->setZoomScale(0.1f);
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
        
        _vFirstButton.pushBack(button);
        
        setTypeLabel(0, i==0 ? "주거공간": i==1? "상업공간": "사무공간");
    }
}

void EstimatePlace::setSecondSelect()
{
    Vector<__String*> vInfo = setSecondSelectListInfo();
    if(_vSecondButton.size() > 0) _vSecondButton.clear();
    
    for(int i = 0 ; i < vInfo.size(); i++)
    {
        auto button = ui::Button::create("UI_TopMenuBG-hd.png");
        button->setBright(true);
        button->setZoomScale(0.1f);
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    
                    SecondbuttonCallBack(sender);
                    break;
                default:
                    break;
            }
        });
        
        _vSecondButton.pushBack(button);
        
        setTypeLabel(1, vInfo.at(i)->getCString());
    }
}

Vector<__String*> EstimatePlace::setSecondSelectListInfo()
{
    Vector<__String*> v;
    
    if(_nTypeNum == 0)
    {
        v.pushBack(__String::createWithFormat("전체"));
        v.pushBack(__String::createWithFormat("거실"));
        v.pushBack(__String::createWithFormat("방"));
        v.pushBack(__String::createWithFormat("부엌"));
        v.pushBack(__String::createWithFormat("욕실"));
        v.pushBack(__String::createWithFormat("발코니"));
        v.pushBack(__String::createWithFormat("현관"));
    }
    else if(_nTypeNum == 1)
    {
        v.pushBack(__String::createWithFormat("카페"));
        v.pushBack(__String::createWithFormat("매장"));
        v.pushBack(__String::createWithFormat("식당"));
        v.pushBack(__String::createWithFormat("학원"));
        v.pushBack(__String::createWithFormat("기타"));
    }
    else
    {
        v.pushBack(__String::createWithFormat("전체"));
        v.pushBack(__String::createWithFormat("사무실"));
        v.pushBack(__String::createWithFormat("회의실"));
        v.pushBack(__String::createWithFormat("기타"));
    }

    
    return v;
}

void EstimatePlace::setExplainLabel()
{
    auto lb = setLabelSystemTTFUnAdd("이 공간은 어디입니까?", 20, ratioPosition(50, 90));
    lb->setColor(Color3B::BLUE);
    addChild(lb);
}

void EstimatePlace::firstPlaceAction()
{
    auto action_0 = MoveTo::create(0.1f, Vec2(5, 5));
    auto delay = DelayTime::create(0.1f);
    auto callback = CallFunc::create(CC_CALLBACK_0(EstimatePlace::firstPlaceActionCallBack, this));
    auto action = Sequence::create(action_0, delay, callback, NULL);
    _lvFirst->runAction(action);
}

void EstimatePlace::firstPlaceActionCallBack()
{
    log("firstCall");
    
    setSecondSelect();
    setSecondPlaceSelect();
    
    secondPlaceAction();
}
void EstimatePlace::secondPlaceAction()
{
    auto action_0 = Show::create();
    _lvSecond->runAction(action_0);
}


void EstimatePlace::setTypeLabel(int typeNum, const char *name)
{
    Button* button;
    if(typeNum == 0)
    {
        button = static_cast<Button*>(_vFirstButton.back());
    }
    else
    {
        button = static_cast<Button*>(_vSecondButton.back());
    }
    
    auto lb = setLabelSystemTTFUnAdd(name, 25, ratioTargetPosition(button->getContentSize(), 50, 50));
    //    lb->setColor(Color3B::BLACK);
    button->addChild(lb);
}

void EstimatePlace::buttonCallBack(cocos2d::Ref *sender)
{
    log("secondselect");
    
    auto btn = static_cast<Button*>(sender);
    
    auto lb = static_cast<Label*>(btn->getChildren().at(0));
    if(lb->getString().compare("주거공간") == 0)
    {
        log("%d",lb->getString().compare("주거공간"));
        _nTypeNum = 0;
    }
    else if(lb->getString().compare("상업공간") == 0)
    {
        _nTypeNum = 1;
    }
    else
    {
        _nTypeNum = 2;
    }
    
    
    firstPlaceAction();
}
void EstimatePlace::SecondbuttonCallBack(cocos2d::Ref *sender)
{
    log("secondbtn");
    
}
//void MenuBoxManager::setListView()
//{
//    ui::ListView* lv = ui::ListView::create();
//
//    for(ui::Button* button : _vButton)
//    {
//        lv->setItemModel(button);
//        lv->pushBackCustomItem(button);
//    }
//
//    lv->setItemsMargin(10);
//    lv->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
//    lv->setSize(Size(screenSizeX, screenSizeY-110));
//    //    lv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    //    lv->setBackGroundColor(Color3B::BLUE);
//    lv->setBounceEnabled(true);
//    lv->setPosition(Vec2(5, 50));
//    addChild(lv);
//}
//
//void MenuBoxManager::setBox()
//{
//
//    for(int i=0;i<3;i++)
//    {
//        auto button = ui::Button::create("images/UIButtons/Main_BoxUp-hd.png", "images/UIButtons/Main_BoxDown-hd.png", "images/UIButtons/Main_BoxDown-hd.png");
//        button->setTitleText("text");
//        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
//            switch (type)
//            {
//                case ui::Widget::TouchEventType::BEGAN:
//                    break;
//                case ui::Widget::TouchEventType::ENDED:
//
//                    buttonCallBack(sender);
//                    break;
//                default:
//                    break;
//            }
//        });
//
//        _vButton.pushBack(button);
//
//        setTypeTitle("TEST");
//        setTypeInfo("고딕>엔틱");
//        setPrice(1000);
//        setImageWithName("room1.png");
//    }
//}


