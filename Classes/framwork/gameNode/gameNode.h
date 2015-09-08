#ifndef __AnEraser__gameNode__
#define __AnEraser__gameNode__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class gameNode : Layer
{
private:
    
public:
    static Scene* createScene();
    CREATE_FUNC(gameNode);
    
public:
    virtual bool init(void);
    virtual void onEnter(void);
    virtual void onExit(void);
};


#endif /* defined(__test__gameNode__) */
