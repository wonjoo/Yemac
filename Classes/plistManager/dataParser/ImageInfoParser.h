//
//  ImageInfoParser.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 9. 1..
//
//

#ifndef __YemacDesign__ImageInfoParser__
#define __YemacDesign__ImageInfoParser__


#include <cocos2d.h>

USING_NS_CC;

class CC_DLL ImageInfoParser : public Ref, public Clonable
{
private:
    
public:
    CC_SYNTHESIZE(__String*, _idx, idx);
    CC_SYNTHESIZE(__String*, _title, title);
    CC_SYNTHESIZE(__String*, _space, space);
    CC_SYNTHESIZE(__String*, _air, air);
    CC_SYNTHESIZE(__String*, _price, price);
    CC_SYNTHESIZE(__String*, _imgName, imgName);
    CC_SYNTHESIZE(__Array*, _subImgName, subImgName);
    CC_SYNTHESIZE(__String*, _explain, explain);
    CC_SYNTHESIZE(bool, _save, save);
    
    virtual ImageInfoParser* clone() const override;
    
};

#endif /* defined(__YemacDesign__ImageInfoParser__) */
