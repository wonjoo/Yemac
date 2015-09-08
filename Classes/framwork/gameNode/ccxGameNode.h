#ifndef __AnEraser__ccxGameNode__
#define __AnEraser__ccxGameNode__

#include "sceneBase.h"
#include "macroFunction.h"
#include "extensions/cocos-ext.h"
#include "ui/UIListView.h"
#include "ui/UIPageView.h"
#include "ui/UIImageView.h"
#include "UI/UIEditBox/UIEditBox.h"
#include "ui/UIButton.h"


USING_NS_CC;
using namespace std;
using namespace ui;

template <typename T>
class CC_DLL ccxGameNode : public sceneBase <T>
{
private:
    float _screenSizeX;
    float _screenSizeY;
    EventListenerTouchAllAtOnce* listener;
    
public:
    virtual bool init(void)
    {
        if (!Layer::init()) return false;
        
        _screenSizeX = Director::getInstance()->getVisibleSize().width;
        _screenSizeY = Director::getInstance()->getVisibleSize().height;
        
        
        return true;
    }
    
    virtual void onEnter(void)
    {
        Layer::onEnter();
        setTouch();
    }
    
    virtual void onExit(void)
    {
        Layer::onExit();
        removeTouch();
    }
    
    virtual Point ratioPosition(float x, float y)
    {
        //가운대를 중심으로 포지션을 잡는다.
        //입력되는 값은 -100~100사이
        float ratioX = screenSizeX / 100;
        float ratioY = screenSizeY / 100;
        
        //                if([self isPad])
        //                {
        //                    ratiox = screenSizeX / 200;
        //                    ratiox = screenSizeY / 200;
        //                }
        
        return ccp(ratioX * x , ratioY * y);
        
        //        return Vec2(screenCenter.x + (screenCenter.x * ratioX) / 100, screenCenter.y + ((screenCenter.y * ratioY) / 100));
    }
    virtual Point ratioTargetPosition(Size target, float x, float y)
    {
        //가운대를 중심으로 포지션을 잡는다.
        //입력되는 값은 -100~100사이
        float ratioX = target.width / 100;
        float ratioY = target.height / 100;
        
        //                if([self isPad])
        //                {
        //                    ratiox = screenSizeX / 200;
        //                    ratiox = screenSizeY / 200;
        //                }
        
        return ccp(ratioX * x , ratioY * y);
        
        //        return Vec2(screenCenter.x + (screenCenter.x * ratioX) / 100, screenCenter.y + ((screenCenter.y * ratioY) / 100));
    }
    
    virtual Point ratioPointWithPt(Point pt)
    {
        float ratioX = screenSizeX / 100;
        float ratioY = screenSizeY / 100;
        
        return ccp( pt.x * ratioX , pt.y * ratioY);
    }
    
    virtual Point unRatioPointWithPt(Point pt)
    {
        float ratioX = screenSizeX / 100;
        float ratioY = screenSizeY / 100;
        
        return ccp( pt.x/ratioX , pt.y / ratioY);
    }
   
    
#pragma mark-
#pragma mark sprite
    virtual void addSpritePlist(const char* plist)
    {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
    }
    
    virtual Sprite* createSprite(const char* name)
    {
        return Sprite::create(name);
    }
    
    virtual Sprite* setSprite(const char* name)
    {
        return Sprite::createWithSpriteFrameName(name);
    }
    
    virtual Rect getSpriteBoundingBox(const char* name)
    {
        return (Rect)(setSprite(name)->getBoundingBox());
    }
    
    virtual Rect getSpriteFrameRect(const char* name)
    {
        return SpriteFrameCache::getInstance()->getSpriteFrameByName(name)->getRect();
    }
    
#pragma mark-
#pragma mark label
    virtual Label* setLabelSystemTTF (const char* string, const char* fontName, float size, Vec2 pt)
    {
        Label* label = Label::createWithSystemFont(string, fontName, size);
        label->setColor(Color3B::BLACK);
        label->setPosition(pt);
        this->addChild(label);
        return label;
    }
    virtual Label* setLabelSystemTTFUnAdd (const char* string, const char* fontName, float size, Vec2 pt)
    {
        Label* label = Label::createWithSystemFont(string, fontName, size);
        label->setColor(Color3B::BLACK);
        label->setPosition(pt);
        return label;
    }
    virtual Label* setLabelSystemTTFUnAdd (const char* string, float size, Vec2 pt)
    {
        Label* label = Label::createWithSystemFont(string, "산들고딕", size);
        label->setPosition(pt);
        return label;
    }
    virtual Label* setLabelTTF (const char* string, const char* fontName, float size, Vec2 pt)
    {
        Label* label = Label::createWithTTF(string, fontName, size);
        label->setPosition(pt);
        this->addChild(label);
        return label;
    }
    
    virtual Label* setLabelBMFont (const char* fntFileName, const char* string, Vec2 pt)
    {
        Label* label = Label::createWithBMFont(fntFileName, string);
        label->setPosition(pt);
        this->addChild(label);
        return label;
    }
    
    virtual Label* setLabelCharMap (const char* pngFileName, int itemWidth, int itemHeight, const char* string, Vec2 pt)
    {
        Label* label = Label::createWithCharMap(pngFileName, itemWidth, itemHeight, '.');
        label->setString(string);
        label->setPosition(pt);
        this->addChild(label);
        return label;
    }
    
#pragma mark-
#pragma mark touch
    virtual void setTouch(void)
    {
        listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(ccxGameNode::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(ccxGameNode::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(ccxGameNode::onTouchesEnded, this);
        listener->onTouchesCancelled = CC_CALLBACK_2(ccxGameNode::onTouchesCancelled, this);
        this->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    }
    
    virtual void removeTouch (void)
    {
        //        this->getEventDispatcher()->removeAllEventListeners();
        this->getEventDispatcher()->removeEventListener(listener);
    }
    
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event)
    {
        //        CCLOG("ccxGameNode::시작~~~~");
    }
    
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event)
    {
        //        CCLOG("ccxGameNode::중~~~~");
    }
    
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event)
    {
        //        CCLOG("ccxGameNode::끝~~~~");
    }
    
    virtual void onTouchesCancelled(const vector<Touch*> &touches, Event *unused_event)
    {
        //        CCLOG("ccxGameNode::취소~~~~");
    }
};

#endif  /*defined(__AnEraser__ccxGameNode__) */

