//
//  BottomMenu.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#ifndef __YemacDesign__BottomMenu__
#define __YemacDesign__BottomMenu__

#include <stdio.h>
#include "ccxGameNode.h"
#include "BusinessInfomationScene.h"

class BottomMenu : public ccxGameNode<BottomMenu>
{
private:
    Vector<Sprite*> _vMenu;
public:
    virtual bool init();
    virtual void onEnter();
    //메뉴바 세팅.
    virtual void setInfo();
 
    virtual void addDownImage(Point pt);
    virtual void addNormalImage(Point pt);
    //버튼콜백 씬전환.
    virtual void setReplaceScene(Point pt);
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event);
};

#endif /* defined(__YemacDesign__BottomMenu__) */
