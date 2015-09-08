//
//  ImageInfoParser.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 9. 1..
//
//

#include "ImageInfoParser.h"

ImageInfoParser* ImageInfoParser::clone() const
{
    ImageInfoParser* copy = new (std::nothrow) ImageInfoParser();
    copy->setidx(_idx);
    copy->settitle(_title);
    copy->setspace(_space);
    copy->setair(_air);
    copy->setprice(_price);
    copy->setimgName(_imgName);
    copy->setsubImgName(_subImgName);
    copy->setexplain(_explain);
    copy->setsave(_save);
    
    copy->autorelease();
    return copy;
}