//
//  BusinessInfomationScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#include "BusinessInfomationScene.h"

void BusinessInfomationScene::onEnter()
{
    ccxGameNode::onEnter();
    UIBusiness* ui = UIBusiness::create();
    addChild(ui);
}