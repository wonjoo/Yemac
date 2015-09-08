//
//  InfoScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#ifndef __YemacDesign__InfoScene__
#define __YemacDesign__InfoScene__

#include <stdio.h>
#include "ccxGameNode.h"
#include "UIInfoScene.h"

class InfoScene : public ccxGameNode<InfoScene>
{
private:
    
public:
    virtual void onEnter();
    virtual void setUI();
};

#endif /* defined(__YemacDesign__InfoScene__) */
