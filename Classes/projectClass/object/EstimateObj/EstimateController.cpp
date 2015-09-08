//
//  EstimateController.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 20..
//
//

#include "EstimateController.h"


bool EstimateController::init()
{
    if(!ccxGameNode::init()) return false;
    
    return true;
}

void EstimateController::onEnter()
{
    ccxGameNode::onEnter();
    setMidViews();
}

void EstimateController::setMidViews()
{
    auto mountBG = Sprite::create("UI_NormalBG.png");
    mountBG->setPosition(Vec2(mountBG->getContentSize().width/2, mountBG->getContentSize().height/2));
    addChild(mountBG);
    _pageSize = mountBG->getContentSize();
    
    _page = PageView::create();
    _page->setTouchEnabled(true);
    _page->setContentSize(mountBG->getContentSize());
    
    
    
    
    // Layout 생성
    auto layout = Layout::create();
    layout->setContentSize(mountBG->getContentSize());
    // ImageView를 생성하고 Layout에 add함
    
    auto photo = EstimatePhoto::create();
    photo->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    photo->setPosition(Vec2(2, 2));
    layout->addChild(photo);
    // Layout을 PageView에 add함
    _page->addPage(layout);
    _nMaxPage++;
    
    auto place = EstimatePlace::create();
    place->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    place->setPosition(Vec2(2, 2));
    layout->addChild(place);
    // Layout을 PageView에 add함
    _page->addPage(layout);
    _nMaxPage++;
    
    auto style = EstimateStyle::create();
    style->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    style->setPosition(Vec2(2, 2));
    layout->addChild(style);
    // Layout을 PageView에 add함
    _page->addPage(layout);
    _nMaxPage++;
    
    auto price = EstimatePrice::create();
    price->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    price->setPosition(Vec2(2, 2));
    layout->addChild(price);
    // Layout을 PageView에 add함
    _page->addPage(layout);
    _nMaxPage++;
    
    auto info = EstimateUserInfo::create();
    info->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    info->setPosition(Vec2(2, 2));
    layout->addChild(info);
    // Layout을 PageView에 add함
    _page->addPage(layout);
    _nMaxPage++;

//    for (int i = 0; i < 3; i++)
//    {
//        // Layout 생성
//        auto layout = Layout::create();
//        layout->setSize(mountBG->getContentSize());
//        // ImageView를 생성하고 Layout에 add함
//        auto imageView = ImageView::create(StringUtils::format("images/source/sample_%d.png", i));
//        imageView->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
//        imageView->setPosition(Vec2(2, 2));
//        layout->addChild(imageView);
//
//        // Layout을 PageView에 add함
//        page->addPage(layout);
//    }

// 이벤트 리스너를 추가
_page->addEventListener(CC_CALLBACK_1(EstimateController::midViewCallBack, this));
mountBG->addChild(_page);

//    _lbPageNum = setLabelSystemTTFUnAdd(__String::createWithFormat("%ld / %ld",page->getCurPageIndex() + 1, page->getPages().size())->getCString(), 20, Vec2(mountBG->getContentSize().width * 90 /100, mountBG->getContentSize().height * 10 /100));
//    mountBG->addChild(_lbPageNum);
log("setpageview");
}

void EstimateController::midViewCallBack(cocos2d::Ref *sender)
{
    log("page");
}














