//
//  UIInfoScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#include "UIInfoScene.h"


bool UIInfoScene::init()
{
    if(!CustomUI::init()) return false;
    
    return true;
}

void UIInfoScene::onEnter()
{
    CustomUI::onEnter();
    setUI();
}

void UIInfoScene::setUI()
{
    setNormalBG();
    setTopTitle("설명서");
    InfoImagePageVeiw* pageview = InfoImagePageVeiw::create();
    addChild(pageview);
    InfoExplainView* explain = InfoExplainView::create();
    addChild(explain);
    InfoLikeBox* box = InfoLikeBox::create();
    addChild(box);
    
    
    setCloseButton();
}
