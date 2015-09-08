//
//  FontImgDataParser.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 7. 9..
//
//

#include "FontImgDataParser.h"

FontImgDataParser* FontImgDataParser::clone() const
{
    FontImgDataParser* copy = new (std::nothrow) FontImgDataParser();
    if(!copy->_arrSpaceList) copy->_arrSpaceList = __Array::create();
    if(!copy->_arrAtmList) copy->_arrAtmList = __Array::create();
    if(!copy->_arrPriceList) copy->_arrPriceList = __Array::create();
    
    copy->_arrSpaceList = _arrSpaceList;
    copy->_arrAtmList = _arrAtmList;
    copy->_arrPriceList = _arrPriceList;
    copy->_spaceSelectTitle = _spaceSelectTitle;
    copy->_atmSelectTitle = _atmSelectTitle;
    copy->_priceSelectTitle = _priceSelectTitle;
    
    
    copy->autorelease();
    return copy;
}