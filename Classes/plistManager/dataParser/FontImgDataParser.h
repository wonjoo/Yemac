//
//  FontImgDataParser.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 7. 9..
//
//

#ifndef __YemacDesign__FontImgDataParser__
#define __YemacDesign__FontImgDataParser__

#include <cocos2d.h>

USING_NS_CC;

class CC_DLL FontImgDataParser : public Ref, public Clonable
{
private:
    
public:
    CC_SYNTHESIZE(__Array*, _arrSpaceList, arrSpaceList);
    CC_SYNTHESIZE(__Array*, _arrAtmList, arrAtmList);
    CC_SYNTHESIZE(__Array*, _arrPriceList, arrPriceList);
    CC_SYNTHESIZE(const char*, _spaceSelectTitle, spaceSelectTitle);
    CC_SYNTHESIZE(const char*, _atmSelectTitle, atmSelectTitle);
    CC_SYNTHESIZE(const char*, _priceSelectTitle, priceSelectTitle);

    virtual FontImgDataParser* clone() const override;
    
};
#endif /* defined(__YemacDesign__FontImgDataParser__) */
