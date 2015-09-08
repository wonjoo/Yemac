//
//  CustomUI.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#ifndef __YemacDesign__CustomUI__
#define __YemacDesign__CustomUI__

#include "ccxGameNode.h"
#include "TopTitle.h"

class CustomUI : public ccxGameNode<CustomUI>
{
    private:
    
    public:
    
    virtual void setNormalBG();
    virtual void setTopTitle(const char* titleName);
    virtual void setCloseButton();
    
    void moveToScene(Scene* scene);
    
    CREATE_FUNC(CustomUI);
};

#endif /* defined(__YemacDesign__CustomUI__) */
