//
//  UIBusiness.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#include "UIBusiness.h"


void UIBusiness::onEnter()
{
    CustomUI::onEnter();
    setUI();
}
void UIBusiness::setUI()
{
    setNormalBG();
    setTopTitle("업체정보");
    
    addChild(setLabelSystemTTFUnAdd("업체 정보가 없습니다.", 30, ratioPosition(50, 50)));
    
    setCloseButton();
}