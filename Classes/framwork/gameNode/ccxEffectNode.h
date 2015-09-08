#ifndef AnEraser_ccxEffectNode_h
#define AnEraser_ccxEffectNode_h

#include "ccxSoundNode.h"
#include "effectCreateDirectly.h"

template <typename T>
class CC_DLL ccxEffectNode : public ccxSoundNode <T>
{
public:
    virtual bool init (void)
    {
        if (!ccxSoundNode<T>::init()) return false;
        
        return true;
    }
    
    virtual void onEnter (void)
    {
        ccxSoundNode<T>::onEnter();
    }
    
    virtual void onExit (void)
    {
        ccxSoundNode<T>::onExit();
    }
    
#pragma mark-
#pragma mark effectCreateDirectly
    
    virtual effectCreateDirectly* setEffect (const char* imgLastNum, cocos2d::Point pt, float fps)
    {
        effectCreateDirectly* fa = effectCreateDirectly::create();
        fa->createWithEffect(imgLastNum, pt, fps);
        this->addChild(fa);
        return fa;
    }
};

#endif












