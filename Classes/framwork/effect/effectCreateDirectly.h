#ifndef __test__effectCreateDirectly__
#define __test__effectCreateDirectly__

#include "nodes.h"

USING_NS_CC;

class CC_DLL effectCreateDirectly : public spriteNode <effectCreateDirectly>
{
private:
    __Array* _arrFrame;
    
    float _count;
    float _fps;
    
    int _imgFirstNum;
    int _imgLastNum;
    int _index;
    
public:
//    static effectCreateDirectly* create (void);
    virtual effectCreateDirectly* createWithEffect (const char* lastName, Vec2 pt, float fps);
    virtual __Array* getSpriteStrSource (__String* strSource);
    virtual void update(float delta);
    
    effectCreateDirectly ();
    virtual ~effectCreateDirectly ();
};



#endif /* defined(__test__effectCreateDirectly__) */









