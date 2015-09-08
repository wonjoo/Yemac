//
//  UIImgDataParser.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 7. 9..
//
//

#include "UIImgDataParser.h"

UIImgDataParser* UIImgDataParser::clone() const
{
    UIImgDataParser* copy = new (std::nothrow) UIImgDataParser();
    copy->_BG = _BG;
    copy->_popUpView = _popUpView;
    copy->_popUpSelect = _popUpSelect;
    copy->_TopTitleBar = _TopTitleBar;
    copy->_TopMenuBar = _TopMenuBar;
    copy->_ImageBoxUp = _ImageBoxUp;
    copy->_ImageBoxDown = _ImageBoxDown;
    copy->_bottomBG = _bottomBG;
    copy->_recycleBin = _recycleBin;
    copy->_close = _close;
    copy->_imgClipBG = _imgClipBG;
    
    
    copy->autorelease();
    return copy;
}