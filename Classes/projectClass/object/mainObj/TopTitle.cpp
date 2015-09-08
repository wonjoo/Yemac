//
//  TopTitle.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#include "TopTitle.h"


bool TopTitle::init(const char* titleName)
{
    if(!ccxGameNode::init()) return false;
    
    setInfo(titleName);

    return true;
}

TopTitle* TopTitle::create(const char* titleName)
{
    TopTitle *ref = new (std::nothrow) TopTitle();
    if (ref && ref->init(titleName))
    {
        ref->autorelease();
        return ref;
    }
    else
    {
        CC_SAFE_DELETE(ref);
        return nullptr;
    }
}

void TopTitle::setInfo(const char* titleName)
{
    auto bg = Sprite::create("UI_TopTitleBG.png");
    bg->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    bg->setPosition(Vec2(0, screenSizeY));
    bg->setTag(TAG_TITLE_BG);
    addChild(bg);
    
    auto title = setLabelSystemTTFUnAdd(titleName, "나눔고딕", 30,Vec2(bg->getContentSize().width/2, bg->getContentSize().height/2));
    title->setColor(Color3B::WHITE);
    bg->addChild(title);
}



















