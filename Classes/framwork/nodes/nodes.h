#ifndef test_nodes_h
#define test_nodes_h

#include "cocos2d.h"

USING_NS_CC;

template <typename T>
class spriteNode : public Sprite
{
public:
    static T* create (void)
    {
        T* obj = new (std::nothrow) T ();
        if (obj && obj->init())
        {
            obj->autorelease();
            return obj;
        }
        CC_SAFE_DELETE(obj);
        return nullptr;
    }
};

template <typename T>
class nodeNode : public Node
{
public:
    static T* create (void)
    {
        T* obj = new (std::nothrow) T ();
        if (obj && obj->init())
        {
            obj->autorelease();
            return obj;
        }
        CC_SAFE_DELETE(obj);
        return nullptr;
    }
};

template <typename T>
class layerNode : public Layer
{
public:
    static T* create (void)
    {
        T* obj = new (std::nothrow) T ();
        if (obj && obj->init())
        {
            obj->autorelease();
            return obj;
        }
        CC_SAFE_DELETE(obj);
        return nullptr;
    }
};

#endif
