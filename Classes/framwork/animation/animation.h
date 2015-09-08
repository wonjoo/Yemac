#ifndef __test__animation__
#define __test__animation__

#include "cocos2d.h"

USING_NS_CC;

#define tagAniRepeatForever 100

class actionAnimationDelegate;
class frameAnimationDelegate;

#pragma mark -
#pragma mark actionAnimation
class CC_DLL animation
{
private:
    Sprite* _sprite;
    
public:
    CC_SYNTHESIZE(actionAnimationDelegate*, _delegate, delegate);
    
    virtual animation* setAnimation (Sprite* target, float delayPerUnit, bool loop, const char* images, ...) CC_REQUIRES_NULL_TERMINATION;
    virtual animation* setAnimation (Sprite* target, float delayPerUnit, bool loop, std::vector<const char*> vImages);
   
    virtual void animationBegan (void);
    virtual void animationEnded (void);
    virtual void removeAnimation (void);
    virtual void stopAnimation (void);
    
    animation (void);
    virtual ~animation (void);
};

#pragma mark -
#pragma mark frameAnimation
class CC_DLL frameAnimation : public Node
{
private:
    cocos2d::Vector<SpriteFrame*> _arrAnimation;
    Sprite* _sprite;
    
    float _count;
    float _fps;
    
    int _imgFirstNum;
    int _imgLastNum;
    int _index;
    int _repeatCount;
    int _period;
    int _selectCallbackSource;
    
    bool _loop;

public:
    CC_SYNTHESIZE(frameAnimationDelegate*, _delegate, delegate);
    CC_PROPERTY(const char*, _selectCallbackSourceImgName, selectCallbackSourceImgName);
    
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgLastName, float fps, bool loop);
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgLastName, float fps, int repeatCount);
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, bool loop);
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, int repeatCount);
    
    virtual __Array* getSpriteStrSource (__String* strSource);
    
    virtual void onDraw (float delta);
    
    frameAnimation (void);
    virtual ~frameAnimation (void);
};

#pragma mark -
#pragma mark delegate
class CC_DLL animationDelegate
{
public:
    virtual void animationBegan (void* sender);
    virtual void animationEnded (void* sender);
};

class CC_DLL actionAnimationDelegate
{
public:
    virtual void animationBegan (animation* sender);
    virtual void animationEnded (animation* sender);
};

class CC_DLL frameAnimationDelegate
{
public:
    virtual void animationBegan (frameAnimation* sender);
    virtual void animationEnded (frameAnimation* sender);
    virtual void animationSelectSource (frameAnimation* sender);
};



#endif /* defined(__test__animation__) */








