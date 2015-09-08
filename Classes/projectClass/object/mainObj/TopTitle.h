//
//  TopTitle.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#ifndef __YemacDesign__TopTitle__
#define __YemacDesign__TopTitle__

#include <stdio.h>
#include "ccxGameNode.h"



class TopTitle : public ccxGameNode<TopTitle>
{
private:
    Sprite* _sTitleBG;
    Label* _lbTitle;
    
public:
    TopTitle(){};
    virtual ~TopTitle(){};
    //상단에 보여지는 타이틀 정보.
    virtual bool init(const char* titleName);
    static TopTitle* create(const char* titleName);

    virtual void setInfo(const char* titleName);
    
};

#endif /* defined(__YemacDesign__TopTitle__) */









