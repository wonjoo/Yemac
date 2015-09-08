#ifndef __test__button__
#define __test__button__

#include "ccxSoundNode.h"

class ccxButton : public ccxSoundNode<ccxButton>
{
private:
    typedef enum
    {
        touchState_normal,
        touchState_down
    } touchState;
    
    touchState _touchState;
//    Sprite* _btnImage;
    const char* _upImageName;
    const char* _downImageName;
    
    //셀렉터~
    SEL_CallFunc _actionBegan;
    
public:
    CC_SYNTHESIZE(Sprite*, _btnImage, btnImage);
    
    ccxButton() {};
    ccxButton(const char* upImageName, const char* downIamgeName, Point position,
           SEL_CallFunc actionBegan);
    virtual ~ccxButton();
    
    virtual bool init();
    virtual bool init(const char* upImageName, const char* downIamgeName, Point position,
                      SEL_CallFunc actionBegan);
    
    static ccxButton* create(const char* upImageName, const char* downIamgeName, Point position,
                      SEL_CallFunc actionBegan);
    virtual void onEnter();
    virtual void onExit();
    virtual void addDownImage();
    virtual void addNormalImage();
    
    //touch
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event);
    
    
//    ccMenuCallback
};

#endif /* defined(__test__button__) */






