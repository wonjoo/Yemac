//
//  EstimatePhoto.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 20..
//
//

#ifndef __YemacDesign__EstimatePhoto__
#define __YemacDesign__EstimatePhoto__

#include <stdio.h>
#include "ccxGameNode.h"

class EstimatePhoto : public ccxGameNode<EstimatePhoto>
{
private:
    
public:
    virtual bool init();
    virtual void onEnter();
    virtual void setExplainLabel();
    virtual void removeExplainLabel();
    virtual void setPhotoPlace();
    virtual void takePhotoCallback(Ref* sender);
};

#endif /* defined(__YemacDesign__EstimatePhoto__) */
