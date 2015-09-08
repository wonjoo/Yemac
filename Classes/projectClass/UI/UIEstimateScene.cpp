//
//  UIEstmateScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#include "UIEstimateScene.h"

bool UIEstimateScene::init()
{
    if(!CustomUI::init()) return false;
    
    return true;
}

void UIEstimateScene::onEnter()
{
    CustomUI::onEnter();
    setuI();
}

void UIEstimateScene::setuI()
{
    setNormalBG();

    _midView = EstimateController::create();
    addChild(_midView);
    
    auto buttons = EstimateButton::create();
    buttons->setdelegate(this);
    addChild(buttons);
    
    setTopTitle("견적요청");
    setCloseButton();
}

void UIEstimateScene::didFinishSelectedButton(cocos2d::Ref *sender)
{
    auto btn = static_cast<Label*>(sender);
    
    switch (btn->getTag()) {
        case TAG_ESTIMATE_PREV:
            if(_midView->getpage()->getCurPageIndex() == 0) return;
            _midView->getpage()->scrollToPage(_midView->getpage()->getCurPageIndex() - 1);
            log("prevPage");
            break;
        case TAG_ESTIMATE_NEXT:
            if(_midView->getpage()->getCurPageIndex() > _midView->getpage()->getPages().size()) return;
            _midView->getpage()->scrollToPage(_midView->getpage()->getCurPageIndex() + 1);
            log("nextPage");
            break;
            
        default:
            break;
    }
}







