//
//  EstmateScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#include "EstimateScene.h"

void EstimateScene::onEnter()
{
    ccxGameNode::onEnter();
    UIEstimateScene* ui = UIEstimateScene::create();
    addChild(ui);
}