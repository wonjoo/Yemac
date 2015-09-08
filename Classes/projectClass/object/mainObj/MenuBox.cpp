//
//  MenuBox.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#include "MenuBox.h"

bool MenuBox::init()
{
    if(!Sprite::init()) return false;
    
    setTouch();
    
    _normalBoxName = "Main_BoxUp.png";
    _downBoxName = "Main_BoxDown.png";
    
    this->setSpriteFrame(_normalBoxName);
    
    return true;
}

void MenuBox::onEnter()
{
    Sprite::onEnter();
    
    
}


void MenuBox::addDownImage(Point pt)
{
    if(this->getBoundingBox().containsPoint(pt))
    {
        this->setSpriteFrame(_downBoxName);
    }
}
void MenuBox::addNormalImage(Point pt)
{
    this->setSpriteFrame(_normalBoxName);
}

void MenuBox::setTouch(void)
{
    listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(MenuBox::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(MenuBox::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(MenuBox::onTouchesEnded, this);
    this->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
}

void MenuBox::removeTouch (void)
{
    //        this->getEventDispatcher()->removeAllEventListeners();
    this->getEventDispatcher()->removeEventListener(listener);
}

void MenuBox::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    addDownImage(pt);
}
void MenuBox::onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
{
    
}
void MenuBox::onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
{
    Point pt = touches.at(0)->getLocation();
    
    addNormalImage(pt);
}



