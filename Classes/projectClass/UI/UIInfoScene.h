//
//  UIInfoScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#ifndef __YemacDesign__UIInfoScene__
#define __YemacDesign__UIInfoScene__

#include <stdio.h>
#include "CustomUI.h"
#include "InfoImagePageView.h"
#include "InfoExplainView.h"
#include "InfoLikeBox.h"

class UIInfoScene : public CustomUI
{
private:
    
public:
    virtual bool init();
    virtual void onEnter();
    virtual void setUI();
    
    
    CREATE_FUNC(UIInfoScene);
};

#endif /* defined(__YemacDesign__UIInfoScene__) */
