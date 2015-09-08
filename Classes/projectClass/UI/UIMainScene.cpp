//
//  UIMainScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#include "UIMainScene.h"
#include "BusinessInfomationScene.h"
#include "ImageInfoParser.h"


bool UIMainScene::init()
{
    if(!CustomUI::init()) return false;
    
    
    return true;
}

void UIMainScene::onEnter()
{
    CustomUI::onEnter();
    
    setUI();
}

void UIMainScene::setUI()
{
    srand((int)time(NULL));
    setNormalBG();
    MenuBoxManager* boxList = MenuBoxManager::create();
    
    Vector<ImageInfoParser*> totalImg = USER_DB->getTotalImageInfo();
    Vector<ImageInfoParser*> randomImg;
    
    //메인하면에 이미지를 렌덤으로 출력하기 위한 포문.
    int maxNum = totalImg.back()->getidx()->intValue();
    for(int i = 0 ; i < maxNum ; i++)
    {
        ImageInfoParser* ranImg = totalImg.at(rand()%(maxNum - i));
        
        randomImg.pushBack(ranImg);

        totalImg.eraseObject(ranImg);
    }
    boxList->setTag(TAG_MENUBOX);
    boxList->setBoxWithList(randomImg);
    addChild(boxList);
    setTopTitle("갤러리");
    setBottomMenu();
//    setBusinessInfoButton();
    setTopMenu();
}

void UIMainScene::setTopMenu()
{
    addChild(TopMenu::create());
}

void UIMainScene::setBottomMenu()
{
    addChild(BottomMenu::create());
}

void UIMainScene::setBusinessInfoButton()
{
    auto button = ui::Button::create("UI_Home_Up-hd.png", "UI_Home_Down-hd.png", "UI_Home_Down-hd.png");
    button->setPosition(ratioPosition(95, 98));
    button->cocos2d::Node::setScale(0.8f);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, BusinessInfomationScene::createScene()));
                break;
            default:
                break;
        }
    });
    addChild(button);
}


void UIMainScene::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocationInView();
    log("touchMain");
}
void UIMainScene::onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
{
    //        CCLOG("ccxGameNode::중~~~~");
    Point pt = touches.at(0)->getLocationInView();
    log("touchMain");
}





















