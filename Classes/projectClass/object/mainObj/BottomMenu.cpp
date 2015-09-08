//
//  BottomMenu.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#include "BottomMenu.h"
#include "StorageScene.h"
#include "EstimateScene.h"


bool BottomMenu::init()
{
    if(!ccxGameNode::init()) return false;
    
    return true;
}

void BottomMenu::onEnter()
{
    ccxGameNode::onEnter();
    
    setInfo();
}

void BottomMenu::setInfo()
{
//    auto titleBG = getTitleSprite();
//    for(int i = 0 ; i < 3 ; i++)
//    {
//        auto menu = setSprite("UI_BottomMenuBG.png");
//        menu->setPosition(Vec2(menu->getContentSize().width/2 + (menu->getContentSize().width * i), menu->getContentSize().height/2));
//        addChild(menu);
//        
//        auto menuName = setLabelSystemTTFUnAdd(i==0?"보관함":i==1?"견적요청":"견적함", 18, Vec2(menu->getContentSize().width/2, menu->getContentSize().height/2));
//        menuName->setColor(Color3B::WHITE);
//        menu->addChild(menuName);
//        
//        _vMenu.pushBack(menu);
//    }
    //수정매뉴
    for(int i = 0 ; i < 2 ; i++)
    {
        auto menu = Sprite::create("UI_BottomMenuBigBG.png");
        menu->setPosition(Vec2(menu->getContentSize().width/2 + (menu->getContentSize().width * i), menu->getContentSize().height/2));
        addChild(menu);
        
        auto menuName = setLabelSystemTTFUnAdd(i==0 ? "보관함" : "업체정보", 20, Vec2(menu->getContentSize().width/2, menu->getContentSize().height/2 - 15));
        menuName->setColor(Color3B::WHITE);
        menu->addChild(menuName);
        
        auto buttonHome = Sprite::create(i==0?"UI_Storage_Up.png":"UI_Home_Up.png");
        buttonHome->setTag(i==0?TAG_BTOM_BUTTON_STORAGE:TAG_BTOM_BUTTON_HOME);
        buttonHome->setScale(0.8f);
        buttonHome->setPosition(Vec2(menuName->getPositionX(), menuName->getPositionY() + menuName->getContentSize().height/2 + buttonHome->getContentSize().height/2 - 2));
        menu->addChild(buttonHome);
        
        
        _vMenu.pushBack(menu);
    }
}

void BottomMenu::addDownImage(Point pt)
{
    for(Sprite* bg : _vMenu)
    {
        if(bg->getBoundingBox().containsPoint(pt))
        {
            bg->getChildren().at(0)->setColor(Color3B::GRAY);
            
            
            if(bg->getChildByTag(TAG_BTOM_BUTTON_HOME))
            {
                auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_BTOM_BUTTON_HOME));
               btnImg->setColor(Color3B::GRAY);
            }
            else if(bg->getChildByTag(TAG_BTOM_BUTTON_STORAGE))
            {
                auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_BTOM_BUTTON_STORAGE));
                btnImg->setColor(Color3B::GRAY);
            }
        }
    }
}
void BottomMenu::addNormalImage(Point pt)
{
    for(Sprite* bg : _vMenu)
    {
        bg->getChildren().at(0)->setColor(Color3B::WHITE);

        if(bg->getChildByTag(TAG_BTOM_BUTTON_HOME))
        {
            auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_BTOM_BUTTON_HOME));
            btnImg->setColor(Color3B::WHITE);
        }
        else if(bg->getChildByTag(TAG_BTOM_BUTTON_STORAGE))
        {
            auto btnImg = static_cast<Sprite*>(bg->getChildByTag(TAG_BTOM_BUTTON_STORAGE));
            btnImg->setColor(Color3B::WHITE);
        }
    }
}

void BottomMenu::setReplaceScene(Point pt)
{
    for(Sprite* bg : _vMenu)
    {
        if(bg->getBoundingBox().containsPoint(pt))
        {
            auto lb = (Label*)bg->getChildren().at(0);
            log("%d",lb->getString().compare("보관함"));
            if(lb->getString().compare("보관함") == 0)
            {
                Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, StorageScene::createScene()));
            }
            else if(lb->getString().compare("업체정보") == 0)
            {
                Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, BusinessInfomationScene::createScene()));
            }
        }
    }
}

void BottomMenu::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    addDownImage(pt);
}
void BottomMenu::onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
{
    
}
void BottomMenu::onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    setReplaceScene(pt);
    addNormalImage(pt);
}









