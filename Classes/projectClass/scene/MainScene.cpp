//
//  MainScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#include "MainScene.h"

//USING_NS_CC;
//
//Scene* MainScene::createScene()
//{
//    // 'scene' is an autorelease object
//    auto scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    auto layer = MainScene::create();
//    
//    // add layer as a child to scene
//    scene->addChild(layer);
//    
//    // return the scene
//    return scene;
//}

bool MainScene::init()
{
    if(!ccxGameNode::init()) return false;

//    auto sprite = Sprite::create("HelloWorld.png");
//    
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
    
//
//    addSpritePlist("UI_Images-hd.plist");
//    addSpritePlist("Source_Yemac-hd.plist");
    
//
//    auto df = Sprite::create("UI_NormalBG.png");
////    df->setPosition(screenCenter);
//    addChild(df);
//
    
    return true;
}

void MainScene::onEnter()
{
    ccxGameNode::onEnter();
   
    setClass();
}

void MainScene::setClass()
{
    UIMainScene* ui = UIMainScene::create();
    addChild(ui);

}

