//
//  EstimateBottomButton.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 19..
//
//

#ifndef __YemacDesign__EstimateBottomButton__
#define __YemacDesign__EstimateBottomButton__

#include <stdio.h>
#include "ccxGameNode.h"
#include "platform/CCPlatformMacros.h"


//버튼관련 딜리게이트
class EstimateButtonDelegate
{
public:
    virtual void didFinishSelectedButton(Ref* sender)=0;
    virtual ~EstimateButtonDelegate(){};
};


class EstimateButton : public ccxGameNode<EstimateButton>
{
private:
    
public:
    
    virtual bool init();
    virtual void onEnter();
    
    virtual void setUI();
    //견적요청 버튼 세팅
    virtual void setMenuButton();
    virtual void enableNextButton();
    virtual void enablePrevButton();
    virtual void enableSelectButton();
    virtual void enableCameraButton();
    
    CC_SYNTHESIZE(EstimateButtonDelegate*, _delegate, delegate);
    virtual void buttonCallBack(Ref* sender);
};
#endif /* defined(__YemacDesign__EstimateBottomButton__) */







