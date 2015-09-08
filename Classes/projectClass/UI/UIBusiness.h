//
//  UIBusiness.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#ifndef __YemacDesign__UIBusiness__
#define __YemacDesign__UIBusiness__

#include <stdio.h>
#include "CustomUI.h"

class UIBusiness : public CustomUI
{
private:
    
public:

    virtual void onEnter();
    virtual void setUI();
    
    CREATE_FUNC(UIBusiness);
};


#endif /* defined(__YemacDesign__UIBusiness__) */
