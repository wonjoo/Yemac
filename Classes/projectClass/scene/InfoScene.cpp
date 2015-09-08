//
//  InfoScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#include "InfoScene.h"

void InfoScene::onEnter()
{
    ccxGameNode::onEnter();
    setUI();
}

void InfoScene::setUI()
{
    UIInfoScene* ui = UIInfoScene::create();
    addChild(ui);
}