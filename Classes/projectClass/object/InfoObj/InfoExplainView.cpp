//
//  InfoExplainView.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#include "InfoExplainView.h"

void InfoExplainView::onEnter()
{
    ccxGameNode::onEnter();
    setUI();
}

void InfoExplainView::setUI()
{
    auto box = Sprite::create("Main_BoxDown.png");
    box->setScale(1.0f, 1.2f);
    box->setPosition(ratioPosition(50, 25));
    addChild(box);
    
    setInfo(box);
    
}

void InfoExplainView::setInfo(Sprite* box)
{
    Vector<ImageInfoParser*> vImgInfo = USER_DB->getTotalImageInfo();
    
    for(ImageInfoParser* imgInfo : vImgInfo)
    {
        log("%s",USER_DB->getDocInfoIdx()->getCString());
        log("%s",imgInfo->getidx()->getCString());
        if(USER_DB->getDocInfoIdx()->compare(imgInfo->getidx()->getCString()) != 0) continue;
        auto space = setLabelSystemTTFUnAdd(imgInfo->getspace()->getCString(), 20, ratioTargetPosition(box->getContentSize(), 15, 85));
        space->setColor(Color3B::BLACK);
        box->addChild(space);
        
        auto image = setLabelSystemTTFUnAdd(imgInfo->getair()->getCString(), 20, ratioTargetPosition(box->getContentSize(), 50, 85));
        image->setColor(Color3B::BLACK);
        box->addChild(image);
        
        auto price = setLabelSystemTTFUnAdd(__String::createWithFormat("%s 만원", imgInfo->getprice()->getCString())->getCString(), 20, ratioTargetPosition(box->getContentSize(), 75, 85));
        price->setColor(Color3B::BLACK);
        box->addChild(price);
        
        auto line = setLabelSystemTTFUnAdd("--------------------------------", 20, ratioTargetPosition(box->getContentSize(), 50, 75));
        line->setColor(Color3B::BLACK);
        box->addChild(line);
        
        auto title = setLabelSystemTTFUnAdd("설명", 20, ratioTargetPosition(box->getContentSize(), 15, 65));
        title->setColor(Color3B::BLACK);
        box->addChild(title);
        
        auto sub = setLabelSystemTTFUnAdd(__String::createWithFormat("%s", imgInfo->getexplain()->getCString())->getCString(), 20, ratioTargetPosition(box->getContentSize(), 5, 55));
        sub->setColor(Color3B::BLACK);
        sub->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
        sub->setAlignment(TextHAlignment::LEFT, TextVAlignment::TOP);
        sub->setDimensions(box->getContentSize().width * 80 / 100, box->getContentSize().height * 55 / 100);
        box->addChild(sub);
    }
}













