//
//  EstimateUserInfo.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 25..
//
//

#ifndef __YemacDesign__EstimateUserInfo__
#define __YemacDesign__EstimateUserInfo__

#include "ccxGameNode.h"

#define TAG_REQUEST_BOX 0

class EstimateUserInfo : public ccxGameNode<EstimateUserInfo>, public ui::EditBoxDelegate
{
private:
    Label* _lbRequest;
public:
    virtual void onEnter();
    
    virtual void setBG();
    virtual void setExplainLabel();
    virtual void setAddressInputBox();
    virtual void setSizeInputBox();
    virtual void setRequestInputBox();
 
    virtual void editBoxEditingDidBegin(ui::EditBox* editBox);
    virtual void editBoxEditingDidEnd(ui::EditBox* editBox);
    virtual void editBoxTextChanged(ui::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(ui::EditBox* editBox);
};

#endif /* defined(__YemacDesign__EstimateUserInfo__) */
