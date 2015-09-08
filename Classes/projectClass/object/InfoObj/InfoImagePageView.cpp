//
//  InfoImagePageView.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#include "InfoImagePageView.h"

bool InfoImagePageVeiw::init()
{
    if(!ccxGameNode::init()) return false;
    
    return true;
}

void InfoImagePageVeiw::onEnter()
{
    ccxGameNode::onEnter();
    
    setPageView();
}

void InfoImagePageVeiw::setPageView()
{
    auto mountBG = Sprite::create("Main_BoxDown.png");
    mountBG->setPosition(Vec2(screenSizeX/2, screenSizeY -( mountBG->getContentSize().height/2 + GET_TOP_TITLE_SIZE/2 + 5)));
    addChild(mountBG);

    PageView* page = PageView::create();
    page->setTouchEnabled(true);
    page->setContentSize(mountBG->getContentSize());

    //선택한 이미지 정보 출력.
    Vector<ImageInfoParser*> vImgInfo = static_cast<Vector<ImageInfoParser*>>(USER_DB->getTotalImageInfo());
    
    __String* currentStr = USER_DB->getDocInfoIdx();
    __Array* arrSubImage;
    for(ImageInfoParser* imgInfo : vImgInfo)
    {
        if(currentStr->compare(imgInfo->getidx()->getCString()) == 0)
        {
            log("add");
        arrSubImage = static_cast<__Array*>(imgInfo->getsubImgName());
        }
    }
    
    
    
    
    for (int i = 0; i < arrSubImage->count(); i++) {
        // Layout 생성
        auto layout = Layout::create();
        layout->setContentSize(mountBG->getContentSize());
        
        // ImageView를 생성하고 Layout에 add함
        auto imageView = ImageView::create(StringUtils::format("%s", static_cast<__String*>(arrSubImage->getObjectAtIndex(i))->getCString()));
        imageView->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
        imageView->setPosition(Vec2(2, 2));
        layout->addChild(imageView);
    
        // Layout을 PageView에 add함
        page->addPage(layout);
    }

    // 이벤트 리스너를 추가
    page->addEventListener(CC_CALLBACK_1(InfoImagePageVeiw::pageviewCallBack, this));
    mountBG->addChild(page);
    
    _lbPageNum = setLabelSystemTTFUnAdd(__String::createWithFormat("%ld / %ld",page->getCurPageIndex() + 1, page->getPages().size())->getCString(), 20, Vec2(mountBG->getContentSize().width * 90 /100, mountBG->getContentSize().height * 10 /100));
    mountBG->addChild(_lbPageNum);
    log("setpageview");
}

void InfoImagePageVeiw::pageviewCallBack(Ref* sender)
{
    auto pageView = dynamic_cast<PageView*>(sender);
    int a = (int)pageView->getCurPageIndex();
    int b = (int)pageView->getPages().size();
    _lbPageNum->setString(__String::createWithFormat("%d / %d",a + 1, b)->getCString());
//        log("%ld", pageView->getCurPageIndex() + 1);
}






