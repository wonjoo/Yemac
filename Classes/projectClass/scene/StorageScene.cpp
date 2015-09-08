//
//  StorageScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#include "StorageScene.h"

bool StorageScene::init()
{
    if(!ccxGameNode::init()) return false;
    
    return true;
}

void StorageScene::onEnter()
{
    ccxGameNode::onEnter();
    setClass();
}

void StorageScene::setClass()
{
    UIStorageScene* ui = UIStorageScene::create();
    addChild(ui);
    
}
