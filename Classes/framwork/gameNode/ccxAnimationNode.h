#ifndef AnEraser_ccxAnimationNode_h
#define AnEraser_ccxAnimationNode_h

#include "ccxEffectNode.h"
#include "animation.h"


template <typename T>
class CC_DLL ccxAnimationNode : public ccxEffectNode <T>
{
private:
    
public:
    virtual bool init (void)
    {
        if (!ccxEffectNode<T>::init()) return false;
        
        return true;
    }
    
    virtual void onEnter (void)
    {
        ccxEffectNode<T>::onEnter();
    }
    
    virtual void onExit (void)
    {
        ccxEffectNode<T>::onExit();
    }
    
#pragma mark -
#pragma mark actionAnimation
    
    virtual animation* setAnimation (Sprite* target, float delayFerUnit, bool loop, const char* images, ...)
    {
        va_list args;
        va_start(args, images);
        
        std::vector<const char*> vImages;
        
        for (const char* arg = images; arg != NULL; arg = va_arg(args, char*))
        {
            vImages.push_back(arg);
        }
        
        animation* ani = new animation;
        ani->setAnimation(target, delayFerUnit, loop, vImages);
        return ani;
    }
    
    virtual animation* setAnimation (Sprite* target, float delayFerUnit, bool loop, std::vector<const char*>vImages)
    {
        animation* ani = new animation;
        ani->setAnimation(target, delayFerUnit, loop, vImages);
        return ani;
    }
    
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgLastName, float fps, bool loop)
    {
        frameAnimation* fa = new frameAnimation;
        fa->setAnimation(target, imgLastName, fps, loop);
        this->addChild(fa);
        return fa;
    }
    
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgLastName, float fps, int repeatCount)
    {
        frameAnimation* fa = new frameAnimation;
        fa->setAnimation(target, imgLastName, fps, repeatCount);
        this->addChild(fa);
        return fa;
    }
    
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, bool loop)
    {
        frameAnimation* fa = new frameAnimation;
        fa->setAnimation(target, imgFirstName, imgLastName, fps, loop);
        this->addChild(fa);
        return fa;
    }
    
    virtual frameAnimation* setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, int repeatCount)
    {
        frameAnimation* fa = new frameAnimation;
        fa->setAnimation(target, imgFirstName, imgLastName, fps, repeatCount);
        this->addChild(fa);
        return fa;
    }
};

#endif
















