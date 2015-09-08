//
//  ButtonDelegate.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 19..
//
//

#include "ButtonDelegate.h"


using namespace cocos2d;

static ButtonType* sharedSelect = nullptr;

ButtonType::ButtonType()
{
    _delegate = nullptr;
}

ButtonType* ButtonType::getInstance()
{
    if(sharedSelect == nullptr)
    {
        sharedSelect = new ButtonType();
    }
    return sharedSelect;
}

void ButtonType::setSelectedType(const char* typeName)
{
    if(_delegate != nullptr)
    {
        _delegate->didFinishButtonType(typeName);
    }
}