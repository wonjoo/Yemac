//
//  EstimatePrice.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 25..
//
//

#ifndef __YemacDesign__EstimatePrice__
#define __YemacDesign__EstimatePrice__

#include "ccxGameNode.h"

class EstimatePrice : public ccxGameNode<EstimatePrice>
{
private:
    Vector<Button*> _vPriceButton;
public:
    virtual void onEnter();
    virtual void setPriceListBox();
    virtual void setPriceList();
    virtual Vector<__String*> setPirceListInfo();
    virtual void setExplainLabel();
    virtual void setPriceLabel(const char* name);
    virtual void priceButtonCallback(Ref* sender);
};

#endif /* defined(__YemacDesign__EstimatePrice__) */
