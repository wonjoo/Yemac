#include "ccxButton.h"

//생성자
ccxButton::ccxButton(const char* upImageName, const char* downIamgeName, Point position,
       SEL_CallFunc actionBegan)
{
    _touchState = touchState_normal;
    _upImageName = upImageName;
    _downImageName = downIamgeName;
    _actionBegan = actionBegan;
    
    _btnImage = setSprite(upImageName);
    _btnImage->setPosition(position);
    this->addChild(_btnImage);
}

//소멸자
ccxButton::~ccxButton()
{
    
}
bool ccxButton::init()
{
    if (!Layer::init()) return false;
    
//    setTouch();
    return true;
}

bool ccxButton::init(const char* upImageName, const char* downIamgeName, Point position,
                     SEL_CallFunc actionBegan)
{
    if (!Layer::init()) return false;
    
    setTouch();
    
    _touchState = touchState_normal;
    _upImageName = upImageName;
    _downImageName = downIamgeName;
    _actionBegan = actionBegan;
    
    _btnImage = setSprite(upImageName);
    _btnImage->setPosition(position);
    this->addChild(_btnImage);
    
    return true;
}

ccxButton* ccxButton::create(const char* upImageName, const char* downIamgeName, Point position, SEL_CallFunc actionBegan)
{
    ccxButton *ret = new (std::nothrow) ccxButton();
    if (ret && ret->init(upImageName, downIamgeName, position, actionBegan))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

void ccxButton::onEnter()
{
    ccxSoundNode::onEnter();
}

void ccxButton::onExit()
{
    ccxSoundNode::onExit();
}

void ccxButton::addDownImage()
{
    _touchState = touchState_down;
    _btnImage->setTextureRect(this->getSpriteFrameRect(_downImageName));
}

void ccxButton::addNormalImage()
{
    _touchState = touchState_normal;
    _btnImage->setTextureRect(this->getSpriteFrameRect(_upImageName));
}

void ccxButton::onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
{
    Point location = touches[0]->getLocation();
    
    if (_btnImage->getBoundingBox().containsPoint(location))
    {
        addDownImage();
//        CallFunc* callback = CallFunc::create(std::bind(_actionBegan, this->getParent()));
//        //FiniteTimeAction* callback = CallFunc::create(std::bind(_actionBegan, this->getParent()));
//        this->runAction(callback);
        //CallFunc* callback = CallFunc::create(CC_CALLBACK_0(_actionBegan, this->getParent()));
        //CallFunc::create(CC_CALLBACK_0(_actionBegan, this->getParent()));
    }
}

void ccxButton::onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
{
    Point location = touches[0]->getLocation();
    
    if (_btnImage->getBoundingBox().containsPoint(location) && _touchState == touchState_normal)
    {
        addDownImage();
    }
    
    if (!_btnImage->getBoundingBox().containsPoint(location) && _touchState == touchState_down)
    {
        addNormalImage();
    }
}

void ccxButton::onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
{
    Point location = touches[0]->getLocation();
    
    if (_btnImage->getBoundingBox().containsPoint(location))
    {
        addNormalImage();
        CallFunc* callback = CallFunc::create(std::bind(_actionBegan, this->getParent()));
        this->runAction(callback);
        log("ccxButton:: touchEnded");
    }
}


















