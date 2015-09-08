//
//  EstimateUserInfo.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 25..
//
//

#include "EstimateUserInfo.h"

void EstimateUserInfo::onEnter()
{
    ccxGameNode::onEnter();
    
    setBG();
    setExplainLabel();
    setAddressInputBox();
    setSizeInputBox();
    setRequestInputBox();
}

void EstimateUserInfo::setBG()
{
    auto bg = Sprite::create("Estimate_UserInfo_BG.png");
    bg->setPosition(screenSizeX/2, screenSizeY/2);
    addChild(bg);
    
}

void EstimateUserInfo::setExplainLabel()
{
    auto lb = setLabelSystemTTFUnAdd("이제 마지막 단계입니다.", 20, ratioPosition(50, 90));
    lb->setColor(Color3B::GRAY);
    addChild(lb);
}

//주소
void EstimateUserInfo::setAddressInputBox()
{
    
    auto editbox = EditBox::create(Size(300, 30), ui::Scale9Sprite::create());
//    "images/UIButtons/UI_TopMenuBG-hd.png"
    editbox->setPosition(ratioPosition(50, 63));
    editbox->setPlaceHolder("상세주소입력");                        //처음 보여주는 문자열
    editbox->setMaxLength(100);                                //최대로 입력받을수 잇는 문자의 길이
    editbox->setPlaceholderFontColor(Color3B::GRAY);        //문자열 색변경
    editbox->setFontColor(Color3B::BLACK);                    //입력한 문자열 색변경

    //키보드 오른쪽하단 enter키를 search로 변경
    editbox->setReturnType(EditBox::KeyboardReturnType::DONE);
    this->addChild(editbox);
    editbox->setDelegate(this);
    
}
//평수
void EstimateUserInfo::setSizeInputBox()
{
    auto editbox = EditBox::create(Size(300, 30), ui::Scale9Sprite::create());
    editbox->setPosition(ratioPosition(50, 52.5f));
    editbox->setPlaceHolder("공사할 공간의 면적(평수)");
    editbox->setMaxLength(100);
    editbox->setPlaceholderFontColor(Color3B::GRAY);
    editbox->setFontColor(Color3B::BLACK);
    editbox->setPlaceholderFontSize(10);
    editbox->setReturnType(EditBox::KeyboardReturnType::DONE);
    editbox->setInputMode(EditBox::InputMode::NUMERIC);

    this->addChild(editbox);
    editbox->setDelegate(this);
    
}


//요청사항
void EstimateUserInfo::setRequestInputBox()
{
    auto editbox = EditBox::create(Size(300, 30), ui::Scale9Sprite::create());
    editbox->setPosition(ratioPosition(50, 42));
    editbox->setPlaceHolder("세부 요청사항을 작성해주세요.");                            editbox->setMaxLength(100);
    editbox->setPlaceholderFontColor(Color3B::GRAY);
    editbox->setFontColor(Color3B::BLACK);
    editbox->setReturnType(EditBox::KeyboardReturnType::DONE);
    editbox->setPlaceholderFontSize(20);
    editbox->setTag(TAG_REQUEST_BOX);
    editbox->setDelegate(this);
    this->addChild(editbox);
    
    _lbRequest = setLabelSystemTTFUnAdd("", 20, ratioPosition(50, 44));
    _lbRequest->setAnchorPoint(Vec2(0.5f, 1.0f));
    _lbRequest->setAlignment(TextHAlignment::LEFT, TextVAlignment::TOP);
    _lbRequest->setDimensions(300, 100);
    _lbRequest->setColor(Color3B::BLACK);
    addChild(_lbRequest);
    
}


void EstimateUserInfo::editBoxEditingDidBegin(ui::EditBox* editBox)
{
    log("begin");
}
void EstimateUserInfo::editBoxEditingDidEnd(ui::EditBox* editBox)
{
    log("end");
}
void EstimateUserInfo::editBoxTextChanged(ui::EditBox* editBox, const std::string& text)
{
     log("textchange");
    if(editBox->getTag() == TAG_REQUEST_BOX)
    {
    
    }
}
void EstimateUserInfo::editBoxReturn(ui::EditBox* editBox)
{
    log("return");
    if(editBox->getTag() == TAG_REQUEST_BOX)
    {
        _lbRequest->setString(editBox->getText());
        editBox->setText("");
    }
}










