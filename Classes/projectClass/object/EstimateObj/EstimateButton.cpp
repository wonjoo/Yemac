//
//  EstimateBottomButton.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 19..
//
//

#include "EstimateButton.h"

bool EstimateButton::init()
{
    if(!ccxGameNode::init()) return false;
    _delegate = nullptr;
    
    return true;
}

void EstimateButton::onEnter()
{
    ccxGameNode::onEnter();
    setMenuButton();
}

void EstimateButton::setUI()
{
    
}

void EstimateButton::setMenuButton()
{
    
    auto prev = setLabelSystemTTFUnAdd("Prev", 20, ratioPosition(0, 0));
    prev->setColor(Color3B::BLACK);
    auto camera = setLabelSystemTTFUnAdd("Camera", 20, ratioPosition(0, 0));
    camera->setColor(Color3B::BLACK);
    auto next = setLabelSystemTTFUnAdd("Next", 20, ratioPosition(0, 0));
    next->setColor(Color3B::BLACK);
    auto select = setLabelSystemTTFUnAdd("Select", 20, ratioPosition(0, 0));
    select->setColor(Color3B::BLACK);
    
    auto prevItem = MenuItemLabel::create(prev, CC_CALLBACK_1(EstimateButton::buttonCallBack, this));
    prevItem->setTag(TAG_ESTIMATE_PREV);
    prevItem->setPosition(ratioPosition(15, 5));
    auto cameraItem = MenuItemLabel::create(camera, CC_CALLBACK_1(EstimateButton::buttonCallBack, this));
    cameraItem->setPosition(ratioPosition(45, 5));
    auto nextItem = MenuItemLabel::create(next, CC_CALLBACK_1(EstimateButton::buttonCallBack, this));
    nextItem->setTag(TAG_ESTIMATE_NEXT);
    nextItem->setPosition(ratioPosition(80, 5));
    auto selectItem = MenuItemLabel::create(select, CC_CALLBACK_1(EstimateButton::buttonCallBack, this));
    selectItem->setPosition(ratioPosition(45, 5));
    selectItem->setEnabled(false);
    selectItem->setOpacity(0);
    
    auto menu = Menu::create(prevItem,cameraItem,nextItem,selectItem, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
    
    
}

void EstimateButton::enableNextButton()
{
    
}

void EstimateButton::enablePrevButton()
{
    
}

void EstimateButton::enableSelectButton()
{
    
}

void EstimateButton::enableCameraButton()
{
    
}

void EstimateButton::buttonCallBack(cocos2d::Ref *sender)
{
    if(_delegate != nullptr)
    {
        _delegate->didFinishSelectedButton(sender);
    }
}



























