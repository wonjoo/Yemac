#include "animation.h"
#include "macroFunction.h"

#pragma mark -
#pragma mark actionAnimation
animation::animation (void)
{
    if (this->getdelegate()) this->setdelegate(nullptr);
}

animation::~animation (void)
{
    if (this->getdelegate()) this->setdelegate(nullptr);
}

animation* animation::setAnimation (Sprite* target, float delayPerUnit, bool loop, const char* images, ...)
{
    _sprite = target;
    
    va_list args;
    va_start(args, images);
    
    Vector<SpriteFrame*> vImageFrame;
    for (const char* arg = images; arg != NULL; arg = va_arg(args, char*))
    {
        vImageFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(arg));
    }
    
    Animation* animation = Animation::createWithSpriteFrames(vImageFrame);
    animation->setDelayPerUnit(delayPerUnit);
    
    auto animate = Animate::create(animation);
    auto aniBegan = CallFunc::create(CC_CALLBACK_0(animation::animationBegan, this));
    auto aniEnded = CallFunc::create(CC_CALLBACK_0(animation::animationEnded, this));
    auto loopSequence = Sequence::create(aniBegan, animate,  aniEnded, NULL);
    auto repeatForever = RepeatForever::create(loopSequence);
    repeatForever->setTag(tagAniRepeatForever);
    auto remove = CallFunc::create(CC_CALLBACK_0(animation::removeAnimation, this));
    auto nonLoopSequence = Sequence::create(aniBegan, animate, aniEnded, remove, NULL);
    
    (loop ? target->runAction(repeatForever) : target->runAction(nonLoopSequence));
    
    return this;
}

animation* animation::setAnimation (Sprite* target, float delayPerUnit, bool loop, std::vector<const char*> vImages)
{
    _sprite = target;
    
    cocos2d::Vector<SpriteFrame*> vImageFrame;
    
    for (__String str : vImages)
    {
         vImageFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(str.getCString()));
    }

    Animation* animation = Animation::createWithSpriteFrames(vImageFrame);
    animation->setDelayPerUnit(delayPerUnit);
    
    auto animate = Animate::create(animation);
    auto aniBegan = CallFunc::create(CC_CALLBACK_0(animation::animationBegan, this));
    auto aniEnded = CallFunc::create(CC_CALLBACK_0(animation::animationEnded, this));
    auto loopSequence = Sequence::create(aniBegan, animate,  aniEnded, NULL);
    auto repeatForever = RepeatForever::create(loopSequence);
    repeatForever->setTag(tagAniRepeatForever);
    auto remove = CallFunc::create(CC_CALLBACK_0(animation::removeAnimation, this));
    auto nonLoopSequence = Sequence::create(aniBegan, animate, aniEnded, remove, NULL);
    
    (loop ? target->runAction(repeatForever) : target->runAction(nonLoopSequence));
    
    return this;
}

void animation::animationBegan (void)
{
    if (!this->getdelegate()) return;
    this->getdelegate()->animationBegan(this);
}

void animation::animationEnded (void)
{
    if (!this->getdelegate()) return;
    this->getdelegate()->animationEnded(this);
}

void animation::removeAnimation (void)
{
    this->stopAnimation();
    delete this;
}

void animation::stopAnimation (void)
{
    if (_sprite->getActionByTag(tagAniRepeatForever))
    {
        _sprite->stopActionByTag(tagAniRepeatForever);
    }
}

#pragma mark -
#pragma mark frameAnimation
frameAnimation::frameAnimation (void)
: _sprite (nullptr)
, _loop (false)
, _index (0)
, _count (0)
, _period (0)
, _repeatCount (0)
, _imgFirstNum (0)
, _imgLastNum (0)
, _selectCallbackSource (-1)
, _fps (0.0f)
, _selectCallbackSourceImgName (nullptr)
, _delegate (nullptr)
{
    if (this->getdelegate() == nullptr) this->setdelegate(nullptr);
}

frameAnimation::~frameAnimation (void)
{
    if (this->getdelegate() != nullptr) this->setdelegate(nullptr);
}

frameAnimation* frameAnimation::setAnimation (Sprite* target, const char* imgLastName, float fps, bool loop)
{
    if (!Layer::create()) return NULL;
    
    _sprite = target;
    _loop = loop;
    _fps = fps;
    
    __Array* arrSource;
    arrSource = getSpriteStrSource(__String::create(imgLastName));
    
    _imgLastNum = ((__String*)arrSource->getObjectAtIndex(1))->intValue();
    
    for (int i = _imgFirstNum; i < _imgLastNum + 1; i++)
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName((__String::createWithFormat("%s_%04d.%s", ((__String*)arrSource->getObjectAtIndex(0))->getCString(), i, ((__String*)arrSource->getObjectAtIndex(2))->getCString()))->getCString());
        
        _arrAnimation.pushBack(frame);
    }
    
    this->schedule(schedule_selector(frameAnimation::onDraw), FPS);
    
    return this;
}

frameAnimation* frameAnimation::setAnimation (Sprite* target, const char* imgLastName, float fps, int repeatCount)
{
    if (!Layer::create()) return NULL;
    
    _sprite = target;
    _loop = false;
    _repeatCount = repeatCount;
    _selectCallbackSource = -1;
    _fps = fps;
    
    __Array* arrSource;
    arrSource = getSpriteStrSource(__String::create(imgLastName));
    
    _imgLastNum = ((__String*)arrSource->getObjectAtIndex(1))->intValue();
    
    for (int i = _imgFirstNum; i < _imgLastNum + 1; i++)
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName((__String::createWithFormat("%s_%04d.%s", ((__String*)arrSource->getObjectAtIndex(0))->getCString(), i, ((__String*)arrSource->getObjectAtIndex(2))->getCString()))->getCString());
        
        _arrAnimation.pushBack(frame);
    }
    
    this->schedule(schedule_selector(frameAnimation::onDraw), FPS);
    
    return this;
}

frameAnimation* frameAnimation::setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, bool loop)
{
    if (!Layer::create()) return NULL;
    
    _sprite = target;
    _loop = loop;
    _selectCallbackSource = -1;
    _fps = fps;
    
    __Array* arrFirstSource;
    arrFirstSource = getSpriteStrSource(__String::create(imgFirstName));
    
    __Array* arrLastSource;
    arrLastSource = getSpriteStrSource(__String::create(imgLastName));
    
    _imgFirstNum = ((__String*)arrFirstSource->getObjectAtIndex(1))->intValue();
    _imgLastNum = ((__String*)arrLastSource->getObjectAtIndex(1))->intValue();
    
    for (int i = _imgFirstNum; i < _imgLastNum + 1; i++)
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName((__String::createWithFormat("%s_%04d.%s", ((__String*)arrLastSource->getObjectAtIndex(0))->getCString(), i, ((__String*)arrLastSource->getObjectAtIndex(2))->getCString()))->getCString());
        
        _arrAnimation.pushBack(frame);
    }
    
    this->schedule(schedule_selector(frameAnimation::onDraw), FPS);
    
    return this;
}

frameAnimation* frameAnimation::setAnimation (Sprite* target, const char* imgFirstName, const char* imgLastName, float fps, int repeatCount)
{
    if (!Layer::create()) return NULL;
    
    _sprite = target;
    _loop = false;
    _repeatCount = repeatCount;
    _selectCallbackSource = -1;
    _fps = fps;
    
    __Array* arrFirstSource;
    arrFirstSource = getSpriteStrSource(__String::create(imgFirstName));
    
    __Array* arrLastSource;
    arrLastSource = getSpriteStrSource(__String::create(imgLastName));
    
    _imgFirstNum = ((__String*)arrFirstSource->getObjectAtIndex(1))->intValue();
    _imgLastNum = ((__String*)arrLastSource->getObjectAtIndex(1))->intValue();
    
    for (int i = _imgFirstNum; i < _imgLastNum + 1; i++)
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName((__String::createWithFormat("%s_%04d.%s", ((__String*)arrLastSource->getObjectAtIndex(0))->getCString(), i, ((__String*)arrLastSource->getObjectAtIndex(2))->getCString()))->getCString());
        
        _arrAnimation.pushBack(frame);
    }
    
    this->schedule(schedule_selector(frameAnimation::onDraw), FPS);
    
    return this;
}

void frameAnimation::onDraw(float delta)
{
    _count += delta;
    
    if (_count > _fps)
    {
        if (_selectCallbackSource == _index)
        {
            if (this->getdelegate()) this->getdelegate()->animationSelectSource(this);
        }
        _index++;
        
        if (_index > _imgLastNum - _imgFirstNum)
        {
            if (!_loop)
            {
                _period++;
                if (_repeatCount < _period)
                {
                    if (this->getdelegate()) this->getdelegate()->animationEnded(this);
                    this->removeFromParent();
                }
            }
            _index = 0;
        }
        else
        {
            if (_period <= 0)
            {
                if (this->getdelegate()) this->getdelegate()->animationBegan(this);
                _period++;
            }
        }
        
        _sprite->setTextureRect(_arrAnimation.at(_index)->getRect());
        
        _count = 0;
    }
}

void frameAnimation::setselectCallbackSourceImgName(const char* imgName)
{
    __Array* arrSource;
    arrSource = getSpriteStrSource(__String::create(imgName));
    _selectCallbackSource = ((__String*)arrSource->getObjectAtIndex(1))->intValue();
}

const char* frameAnimation::getselectCallbackSourceImgName(void)
{
    return _selectCallbackSourceImgName;
}

__Array* frameAnimation::getSpriteStrSource (__String* strSource)
{
    __Array* str1 = strSource->componentsSeparatedByString(".");
    __String* name1 = ((__String*)str1->getObjectAtIndex(0));
    __String* type = ((__String*)str1->getObjectAtIndex(1));
    
    __Array* str2 = name1->componentsSeparatedByString("_");
    __String* name2 = ((__String*)str2->getObjectAtIndex(0));
    __String* number = ((__String*)str2->getObjectAtIndex(1));
    
    return __Array::create(name2, number, type, NULL);
}





























