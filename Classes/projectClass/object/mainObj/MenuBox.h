//
//  MenuBox.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#ifndef __YemacDesign__MenuBox__
#define __YemacDesign__MenuBox__

#include <stdio.h>
#include "ccxGameNode.h"
#include <cocos2d.h>

USING_NS_CC;

class MenuBox : public Sprite
{
private:
    const char* _normalBoxName;
    const char* _downBoxName;
    EventListenerTouchAllAtOnce* listener;

public:
    //사용되지 않는 클래스
    MenuBox(){};
    virtual ~MenuBox(){removeTouch();};
    
    virtual bool init();
    virtual void onEnter();
    
    virtual void addDownImage(Point pt);
    virtual void addNormalImage(Point pt);
    
    void setTouch(void);
    void removeTouch (void);
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event);
    
    CREATE_FUNC(MenuBox);
};

#endif /* defined(__YemacDesign__MenuBox__) */
