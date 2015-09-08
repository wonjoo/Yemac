//
//  MainScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 13..
//
//

#ifndef __YemacDesign__MainScene__
#define __YemacDesign__MainScene__

#include "ccxGameNode.h"
#include "UIMainScene.h"
//#include "cocos2d.h"

class MainScene : public ccxGameNode<MainScene>
{
    private:
    
    

    public:
    
//    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void onEnter();
    virtual void setClass();

};


#endif /* defined(__YemacDesign__MainScene__) */
