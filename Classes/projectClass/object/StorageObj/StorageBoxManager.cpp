//
//  StorageBoxManager.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#include "StorageBoxManager.h"
#include "InfoScene.h"

bool StorageBoxManager::init()
{
    if(!ccxGameNode::init()) return false;
    _bRemoveBox = false;
    return true;
}

void StorageBoxManager::onEnter()
{
    ccxGameNode::onEnter();
    
    setBox();
    
    
    setListView();
    
}

void StorageBoxManager::setListView()
{
    _lv = ui::ListView::create();
    
    for(ui::Button* button : _vButton)
    {
        _lv->setItemModel(button);
        _lv->pushBackCustomItem(button);
    }
    
    _lv->setItemsMargin(10);
    _lv->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    _lv->setSize(Size(screenSizeX, screenSizeY));
    //    lv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    //    lv->setBackGroundColor(Color3B::BLUE);
    _lv->setBounceEnabled(true);
    _lv->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    _lv->setPosition(Vec2(5, screenSizeY - (GET_TOP_TITLE_SIZE/2 + 5)));
    addChild(_lv);
}



void StorageBoxManager::setBox()
{
    Vector<__String*> storageList = USER_DB->getDocStorageList();
    Vector<ImageInfoParser*> vImgData = USER_DB->getTotalImageInfo();
    
    Vector<ImageInfoParser*> vStorageImgData;
    Vector<__Dictionary*> vDicImgData;
    for(ImageInfoParser* imgInfo : vImgData)
    {
        for(__String* idxList : storageList)
        {
            if(imgInfo->getidx()->compare(idxList->getCString()) == 0)
            {
                vStorageImgData.pushBack(imgInfo);
            }
        }
    }
    
    for(ImageInfoParser* storageImgData : vStorageImgData)
    {
        auto button = ui::Button::create("Main_BoxUp-hd.png", "Main_BoxDown-hd.png", "Main_BoxDown-hd.png");
        button->setTitleText("text");
        button->setTag(TAG_STORAGE_BOX + storageImgData->getidx()->intValue());
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    if(_bRemoveBox)
                    {
                        removeAction(sender);
                    }
                    else
                    {
                        buttonCallBack(sender);
                    }
                    
                    break;
                default:
                    break;
            }
        });
        
        _vButton.pushBack(button);
        
        setImageWithName(storageImgData->getimgName()->getCString());
        setTypeTitle(storageImgData->gettitle()->getCString());
        setTypeInfo(__String::createWithFormat("%s / %s",storageImgData->getspace()->getCString(), storageImgData->getair()->getCString())->getCString());
        setPrice(storageImgData->getprice()->intValue());
        
        
        //            setImageWithName("sample_0.png");
        //            setTypeTitle("TEST");
        //            setTypeInfo("고딕>엔틱");
        //            setPrice(1000);
    }
}

void StorageBoxManager::removeAction(Ref* sender)
{
    auto button = (ui::Button*)sender;
    
    auto action_0 = ScaleTo::create(0.3f, 0.0f);
    auto action_1 = FadeOut::create(0.3f);
    auto spawn = Spawn::create(action_0, action_1, NULL);
    auto callback = CallFuncN::create(CC_CALLBACK_1(StorageBoxManager::removeBox, this));
    auto sequence = Sequence::create(spawn,callback, NULL);
    button->runAction(sequence);
}

void StorageBoxManager::removeBox(Ref* sender)
{
    auto button = (ui::Button*)sender;
    
    USER_DB->removeDocStorageList(__String::createWithFormat("%d",button->getTag() - TAG_STORAGE_BOX));
    
    _lv->removeItem(_vButton.getIndex(button));
    _vButton.eraseObject(button);
}


void StorageBoxManager::buttonCallBack(Ref* sender)
{
    auto button = (ui::Button*)sender;
    
    USER_DB->setDocInfoIdx(__String::createWithFormat("%d",button->getTag() - TAG_STORAGE_BOX));
    
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, InfoScene::createScene()));
    log("%s", button->getTitleText().c_str());
}

void StorageBoxManager::setImageWithName(const char* ImgName)
{
    //    auto lbInfo = button->getChildByTag(TAG_MENU_BOX_TITLE);
    
    auto button = static_cast<ui::Button*>(_vButton.back());
    //이미지를 박스크기에 맞게 자르기 위한 임시 이미지
    
    auto tempSprite  =  Sprite::create("Main_BoxDown-hd.png");
    //이미지를 라벨을 뺀 크기로 만든다.
    Rect rc = tempSprite->getTextureRect();
    tempSprite->setTextureRect(Rect(rc.origin.x, rc.origin.y, rc.size.width- 5, rc.size.height - 5));
    
    auto layout = Layout::create();
    layout->setSize(Size(tempSprite->getTextureRect().size.width,
                         tempSprite->getTextureRect().size.height));
    // ImageView를 생성하고 Layout에 add함
    auto imageView = ImageView::create(StringUtils::format("%s",ImgName));
    imageView->setTextureRect(tempSprite->getTextureRect());
    imageView->setPosition(Vec2(button->getContentSize().width/2, button->getContentSize().height - (tempSprite->getContentSize().height/2 + 2)));
    layout->addChild(imageView);
    
    button->addChild(layout);
}

void StorageBoxManager::setTypeTitle(const char* title)
{
    auto button = static_cast<ui::Button*>(_vButton.back());
    __String* cTitle = __String::createWithFormat("%s",title);
    auto lbTitle = Label::createWithSystemFont(cTitle->getCString(), "나눔고딕", 20);
    lbTitle->setColor(Color3B::WHITE);
    lbTitle->setAnchorPoint(Vec2(0, 0));
    lbTitle->setPosition(Vec2((button->getContentSize().width * 5 / 100), (button->getContentSize().height * 15)/ 100));
    lbTitle->setTag(TAG_MENU_BOX_TITLE);
    _tempPoint = lbTitle->getPosition();
    _tempSize = lbTitle->getContentSize();
    button->addChild(lbTitle);
    
}

void StorageBoxManager::setTypeInfo(const char* info)
{
    auto button = static_cast<ui::Button*>(_vButton.back());
    __String* cInfo = __String::createWithFormat("%s",info);
    auto lbInfo = Label::createWithSystemFont(cInfo->getCString(), "나눔고딕", 15);
    lbInfo->setColor(Color3B::WHITE);
    lbInfo->setAnchorPoint(Vec2(0, 0));
    lbInfo->setPosition(Vec2((button->getContentSize().width * 5 / 100), (button->getContentSize().height * 5)/ 100));
    button->addChild(lbInfo);
}

void StorageBoxManager::setPrice(int price)
{
    auto button = static_cast<ui::Button*>(_vButton.back());
    __String* cPrice = __String::createWithFormat("%d 만원",price);
    auto lbPrice = Label::createWithSystemFont(cPrice->getCString(), "나눔고딕", 20);
    lbPrice->setColor(Color3B::WHITE);
    lbPrice->setAnchorPoint(Vec2(1, 0));
    lbPrice->setPosition(Vec2(button->getContentSize().width - (button->getContentSize().width * 5 / 100), (button->getContentSize().height * 5)/100));
    button->addChild(lbPrice);
}

