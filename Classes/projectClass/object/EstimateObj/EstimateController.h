//
//  EstimateController.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 20..
//
//

#ifndef __YemacDesign__EstimateController__
#define __YemacDesign__EstimateController__

#include <stdio.h>
#include "ccxGameNode.h"
#include "EstimatePhoto.h"
#include "EstimatePlace.h"
#include "EstimateStyle.h"
#include "EstimatePrice.h"
#include "EstimateUserInfo.h"

class EstimateController : public ccxGameNode<EstimateController>
{
private:
    Size _pageSize;
//    PageView* _page;
    int _nMaxPage;
public:
    CC_SYNTHESIZE(PageView*, _page, page);
    virtual bool init();
    virtual void onEnter();
    virtual void setMidViews();
    virtual void midViewCallBack(Ref* sender);
    
};


#endif /* defined(__YemacDesign__EstimateController__) */
