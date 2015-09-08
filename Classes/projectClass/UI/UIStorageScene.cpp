//
//  UIStorageScene.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#include "UIStorageScene.h"
#include "MainScene.h"



bool UIStorageScene::init()
{
    if(!CustomUI::init()) return false;
    _bReadyToRemove = false;
    
    return true;
}

void UIStorageScene::onEnter()
{
    CustomUI::onEnter();
    
    setUI();
}

void UIStorageScene::setUI()
{
    setNormalBG();
    _boxList = StorageBoxManager::create();
    addChild(_boxList);
    setTopTitle("보관함");
    setCloseButton();
    setTrashCan(ratioPosition(7, 96));
    

}

void UIStorageScene::setTrashCan(Point position)
{
    auto button = ui::Button::create("Storage_TrashUp-hd.png", "Storage_TrashDown-hd.png", "Storage_TrashDown-hd.png");
    button->setPosition(position);
//    button->setScale(0.8f);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                
                if(!_bReadyToRemove)
                {
                    setTrashImage();
                }
                else if(_bReadyToRemove)
                {
                    removeTrashImage();
                }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
}

void UIStorageScene::setTrashImage()
{
    _bReadyToRemove = true;
    
    _boxList->setbRemoveBox(true);
    for(ui::Button* button : _boxList->getvButton())
    {
        auto mountLayer = LayerColor::create(Color4B(230, 230, 230, 150));
        mountLayer->setContentSize(button->getContentSize());
        button->addChild(mountLayer);
        
        auto trashSprite = Sprite::create("Storage_BigTrash-hd.png");
        trashSprite->setPosition(mountLayer->getContentSize()/2);
        mountLayer->addChild(trashSprite);
        
        _vTrashLayer.pushBack(mountLayer);
    }
}

void UIStorageScene::removeTrashImage()
{
    _bReadyToRemove = false;
    _boxList->setbRemoveBox(false);
    
    for(auto layer : _vTrashLayer)
    {
        layer->removeFromParent();
    }
}

void UIStorageScene::removeToTrash(Point pt)
{
    for(auto layer : _vTrashLayer)
    {
        if(layer->getBoundingBox().containsPoint(pt))
        {
            layer->getParent()->removeFromParent();
            log("remove");
        }
    }
}

void UIStorageScene::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocationInView();
}
void UIStorageScene::onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocationInView();
    
//    removeToTrash(pt);
}










