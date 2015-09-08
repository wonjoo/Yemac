//
//  UIMainScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#ifndef __YemacDesign__UIMainScene__
#define __YemacDesign__UIMainScene__

#include "CustomUI.h"
#include "TopMenu.h"
#include "BottomMenu.h"
#include "MenuBoxManager.h"

class UIMainScene : public CustomUI
{
    private:
    
    public:
    virtual bool init();
    virtual void onEnter();
    virtual void setUI();
    virtual void setTopMenu();
    virtual void setBottomMenu();
    virtual void setBusinessInfoButton();
    
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event);
    
    
    CREATE_FUNC(UIMainScene);
};

#endif /* defined(__YemacDesign__UIMainScene__) */
