//
//  EstimateStyle.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 25..
//
//

#include "EstimateStyle.h"

void EstimateStyle::onEnter()
{
    ccxGameNode::onEnter();
    setExplainLabel();
    
}

void EstimateStyle::setExplainLabel()
{
    auto lb = setLabelSystemTTFUnAdd("원하는 스타일을 가져오세요.", 20, ratioPosition(50, 90));
    lb->setColor(Color3B::BLUE);
    addChild(lb);
}
