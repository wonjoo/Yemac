#include "effectCreateDirectly.h"

effectCreateDirectly::effectCreateDirectly ()
: _arrFrame (nullptr)
, _count (0.0f)
, _fps (0.0f)
, _imgFirstNum (0)
, _imgLastNum (0)
, _index (0)
{
    if (_arrFrame == nullptr)
    {
        _arrFrame = new __Array;
        _arrFrame->init();
    }
}

effectCreateDirectly::~effectCreateDirectly ()
{
    if (_arrFrame != nullptr) delete _arrFrame;
}

/*
effectCreateDirectly* effectCreateDirectly::create (void)
{
    effectCreateDirectly* ecd = new (std::nothrow) effectCreateDirectly ();
    if (ecd && ecd->init())
    {
        ecd->autorelease();
        return ecd;
    }
    CC_SAFE_DELETE(ecd);
    return nullptr;
}
 */

effectCreateDirectly* effectCreateDirectly::createWithEffect (const char* lastName, Vec2 pt, float fps)
{
    _fps = fps;
    
    __Array* arrSource = getSpriteStrSource(__String::create(lastName));
    _imgLastNum = ((__String*)arrSource->getObjectAtIndex(1))->intValue();
    
    for (int i = _imgFirstNum; i < _imgLastNum + 1; i++)
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName((__String::createWithFormat("%s_%04d.%s", ((__String*)arrSource->getObjectAtIndex(0))->getCString(), i, ((__String*)arrSource->getObjectAtIndex(2))->getCString()))->getCString());
        
        if (i == 0) this->setSpriteFrame(frame);
        _arrFrame->addObject(frame);
    }
    
    this->setPosition(pt);
    this->scheduleUpdate();
    
    return this;
}

void effectCreateDirectly::update(float delta)
{
    _count += delta;
    
    if (_count > _fps)
    {
        _index++;
        if (_index >= _imgLastNum)
        {
            this->unscheduleUpdate();
            this->removeFromParent();
            return;
        }
        
        this->setSpriteFrame(((SpriteFrame*)_arrFrame->getObjectAtIndex(_index)));
        _count = 0;
    }
}

__Array* effectCreateDirectly::getSpriteStrSource (__String* strSource)
{
    __Array* str1 = strSource->componentsSeparatedByString(".");
    __String* name1 = ((__String*)str1->getObjectAtIndex(0));
    __String* type = ((__String*)str1->getObjectAtIndex(1));
    
    __Array* str2 = name1->componentsSeparatedByString("_");
    __String* name2 = ((__String*)str2->getObjectAtIndex(0));
    __String* number = ((__String*)str2->getObjectAtIndex(1));
    
    return __Array::create(name2, number, type, NULL);
}









