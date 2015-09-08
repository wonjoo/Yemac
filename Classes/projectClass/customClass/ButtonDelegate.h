//
//  ButtonDelegate.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 19..
//
//

#ifndef __YemacDesign__ButtonDelegate__
#define __YemacDesign__ButtonDelegate__

#include <stdio.h>
#include "platform/CCPlatformMacros.h"
#include "cocos2d.h"


NS_CC_BEGIN

//선택한 타입을 전달해줄 딜리게이트 생성.
class ButtonTypeDelegate
{
public:
    virtual void didFinishButtonType(const char* typeName) = 0;
    virtual ~ButtonTypeDelegate() {};
    
};

class CC_DLL ButtonType
{
private:
    
public:
    CC_SYNTHESIZE(ButtonTypeDelegate*, _delegate, delegate)
    
    ButtonType();
    static ButtonType* getInstance();
    
    virtual void setSelectedType(const char* typeName);
    
};
NS_CC_END

#endif /* defined(__YemacDesign__ButtonDelegate__) */







