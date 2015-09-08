//
//  InfoLikeBox.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#include "InfoLikeBox.h"

bool InfoLikeBox::init()
{
    if(!ccxGameNode::init()) return false;
    
    
    
    
    return true;
}

void InfoLikeBox::onEnter()
{
    ccxGameNode::onEnter();
    
    Vector<__String*> vStr = USER_DB->getDocStorageList();
    
    for(__String* str : vStr)
    {
        if(str->compare(USER_DB->getDocInfoIdx()->getCString()) == 0)
        {
            _bIsLike = true;
            break;
        }
        else if(str->compare(USER_DB->getDocInfoIdx()->getCString()) != 0)
        {
            _bIsLike = false;
        }
    }
    
    
    setUI();
}

void InfoLikeBox::setUI()
{
    if(_bIsLike)
    {
        auto button = ui::Button::create("Info_LikeButtonUp_Selected-hd.png", "Info_LikeButtonDown-hd.png");
        button->setPosition(ratioPosition(50, 51.5f));
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    likeButtonCallBack(sender);
                    break;
                default:
                    break;
            }
        });
        
        auto buttonState = setLabelSystemTTFUnAdd("LIKE", 30, Vec2(button->getContentSize()/2));
        buttonState->setColor(Color3B::WHITE);
        buttonState->setTag(TAG_BUTTON_STATE);
        button->addChild(buttonState);
        
        addChild(button);
    }
    else
    {
        auto button = ui::Button::create("Info_LikeButtonUp_Normal-hd.png", "Info_LikeButtonDown-hd.png", "Info_LikeButtonDown-hd.png");
        button->setPosition(ratioPosition(50, 51.5f));
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    likeButtonCallBack(sender);
                    break;
                default:
                    break;
            }
        });
        
        auto buttonState = setLabelSystemTTFUnAdd("LIKE IT!!", 30, Vec2(button->getContentSize()/2));
        buttonState->setColor(Color3B::BLACK);
        buttonState->setTag(TAG_BUTTON_STATE);
        button->addChild(buttonState);
        
        addChild(button);
    }
}

void InfoLikeBox::likeButtonCallBack(cocos2d::Ref *sender)
{
    if(_bIsLike)
    {
        //만약 라이크가 아니라면
        auto button = static_cast<ui::Button*>(sender);
        button->loadTextures("Info_LikeButtonUp_Normal-hd.png", "Info_LikeButtonDown-hd.png");
        auto lb = static_cast<Label*>(button->getChildByTag(TAG_BUTTON_STATE));
        lb->setString("LIKE IT!!");
        lb->setColor(Color3B::BLACK);
        removeLikeList();
        _bIsLike = false;
    }
    else
    {
        //만약 라이크면
        auto button = static_cast<ui::Button*>(sender);
        button->loadTextures("Info_LikeButtonUp_Selected-hd.png", "Info_LikeButtonDown-hd.png");
        auto lb = static_cast<Label*>(button->getChildByTag(TAG_BUTTON_STATE));
        lb->setString("LIKE");
        lb->setColor(Color3B::WHITE);
        saveLikeList();
        _bIsLike = true;
    }
}

void InfoLikeBox::saveLikeList()
{
    USER_DB->setDocStorageList(USER_DB->getDocInfoIdx());
    
}

void InfoLikeBox::removeLikeList()
{
    USER_DB->removeDocStorageList(USER_DB->getDocInfoIdx());
}













