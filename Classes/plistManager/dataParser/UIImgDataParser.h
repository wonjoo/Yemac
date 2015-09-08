;//
//  UIImgDataParser.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 7. 9..
//
//

#ifndef __YemacDesign__UIImgDataParser__
#define __YemacDesign__UIImgDataParser__

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class CC_DLL UIImgDataParser : public Ref, public Clonable
{
private:
    
public:
    CC_SYNTHESIZE(const char*, _BG, BG);
    //top
    CC_SYNTHESIZE(const char*, _popUpView, popUpView);
    CC_SYNTHESIZE(const char*, _popUpSelect, popUpSelect);
    CC_SYNTHESIZE(const char*, _TopTitleBar, TopTitleBar);
    CC_SYNTHESIZE(const char*, _TopMenuBar, TopMenuBar);
    //mid
    CC_SYNTHESIZE(const char*, _ImageBoxUp, ImageBoxUp);
    CC_SYNTHESIZE(const char*, _ImageBoxDown, ImageBoxDown);
    //bottom
    CC_SYNTHESIZE(const char*, _bottomBG, bottomBG);
    CC_SYNTHESIZE(const char*, _recycleBin, recycleBin);
    CC_SYNTHESIZE(const char*, _close, close);
    CC_SYNTHESIZE(const char*, _imgClipBG, imgClipBG);
    
    
    virtual UIImgDataParser* clone() const override;
    
};
#endif /* defined(__YemacDesign__UIImgDataParser__) */
