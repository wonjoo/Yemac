//
//  EstimatePhoto.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 20..
//
//

#include "EstimatePhoto.h"

bool EstimatePhoto::init()
{
    if(!ccxGameNode::init()) return false;
    
        
        
    return true;
}

void EstimatePhoto::onEnter()
{
    ccxGameNode::onEnter();
    setExplainLabel();
    setPhotoPlace();
}

void EstimatePhoto::setExplainLabel()
{
    auto lb = setLabelSystemTTFUnAdd("인테리어 할 공간을 사진으로 찍으세요.", 20, ratioPosition(50, 90));
    lb->setColor(Color3B::BLUE);
    lb->setTag(TAG_PHOTO_LABEL);
    addChild(lb);
}

void EstimatePhoto::removeExplainLabel()
{
    Label* lb = static_cast<Label*>(getChildByTag(TAG_PHOTO_LABEL));
    if(!lb) return;
    lb->removeFromParent();
}


void EstimatePhoto::setPhotoPlace()
{
    auto button = ui::Button::create("Estimate_Photo-hd.png");
    button->setPosition(ratioPosition(50, 55));
    button->setZoomScale(0.0f);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                takePhotoCallback(sender);
                break;
            default:
                break;
        }
    });
    addChild(button);
}

void EstimatePhoto::takePhotoCallback(cocos2d::Ref *sender)
{
    log("load photo");
    removeExplainLabel();
}












