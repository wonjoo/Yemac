#ifndef test_sceneBase_h
#define test_sceneBase_h

#include <cocos2d.h>
#include "macroFunction.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

template <typename T>
class sceneBase : public Layer
{
public:
    static Scene* createScene(void)
    {
        auto scene = Scene::create();
        auto layer = T::create();
        scene->addChild(layer);
        return scene;
    }
    
    static T* create(void)
    {
        auto scene = new (std::nothrow) T();
        if (scene && scene->init())
        {
            scene->autorelease();
            return scene;
        }
        else
        {
            CC_SAFE_DELETE (scene);
            return nullptr;
        }
    }
};

#endif









