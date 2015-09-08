//
//  UIEstmateScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#ifndef __YemacDesign__UIEstmateScene__
#define __YemacDesign__UIEstmateScene__

#include <stdio.h>
#include "CustomUI.h"
#include "EstimateButton.h"
#include "EstimateController.h"

class UIEstimateScene : public CustomUI, public EstimateButtonDelegate
{
private:
    EstimateController* _midView;
public:
    virtual bool init();
    virtual void onEnter();
    virtual void setuI();
    //견적함에서 버튼 콜백(페이지 넘김, 선택 등등)
    void didFinishSelectedButton(cocos2d::Ref *sender);
    
    CREATE_FUNC(UIEstimateScene)
};

#endif /* defined(__YemacDesign__UIEstmateScene__) */
