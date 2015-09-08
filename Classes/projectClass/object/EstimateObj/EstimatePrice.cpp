//
//  EstimatePrice.cpp
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 25..
//
//

#include "EstimatePrice.h"

void EstimatePrice::onEnter()
{
    ccxGameNode::onEnter();
    
    setExplainLabel();
    setPriceList();
    setPriceListBox();
}

void EstimatePrice::setPriceListBox()
{
    ListView* lvFirst = ui::ListView::create();
    
    for(ui::Button* button : _vPriceButton)
    {
        lvFirst->setItemModel(button);
        lvFirst->pushBackCustomItem(button);
        lvFirst->setSize(Size(button->getContentSize().width + 1, screenSizeY-110));
    }
    
    lvFirst->setItemsMargin(2);
    lvFirst->setGravity(cocos2d::ui::ListView::Gravity::BOTTOM);
    
    //    _lvFirst->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    //    _lvFirst->setBackGroundColor(Color3B::BLUE);
    lvFirst->setBounceEnabled(false);
    lvFirst->setPosition(Vec2(screenSizeX/2 - lvFirst->getContentSize().width/2, 5));
    addChild(lvFirst);
    
}


void EstimatePrice::setPriceList()
{
    Vector<__String*> list = setPirceListInfo();
    
    for(int i = 0 ; i < list.size(); i++)
    {
        auto button = ui::Button::create("images/UIButtons/UI_TopMenuBG-hd.png");
        button->setBright(true);
        button->setZoomScale(0.1f);
        button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    
                    priceButtonCallback(sender);
                    break;
                default:
                    break;
            }
        });
        
        _vPriceButton.pushBack(button);
        
        setPriceLabel(list.at(i)->getCString());
    }
}

Vector<__String*> EstimatePrice::setPirceListInfo()
{
    Vector<__String*> list;
    
    list.pushBack(__String::createWithFormat("500 만 이하"));
    list.pushBack(__String::createWithFormat("1000만원"));
    list.pushBack(__String::createWithFormat("2000만원"));
    list.pushBack(__String::createWithFormat("3000만원"));
    list.pushBack(__String::createWithFormat("4000만원"));
    list.pushBack(__String::createWithFormat("5000만원"));
    
    return list;
}

void EstimatePrice::setPriceLabel(const char *name)
{
    auto button = static_cast<Button*>(_vPriceButton.back());
    auto lb = setLabelSystemTTFUnAdd(name, 25, ratioTargetPosition(button->getContentSize(), 50, 50));
    //    lb->setColor(Color3B::BLACK);
    button->addChild(lb);
}

void EstimatePrice::setExplainLabel()
{
    auto lb = setLabelSystemTTFUnAdd("정확한 견적을 위해 생각하고 있는 예산을 설정하세요.", 20, ratioPosition(50, 90));
    lb->setColor(Color3B::BLUE);
    
    lb->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
    lb->setDimensions(240,50);
    addChild(lb);
}

void EstimatePrice::priceButtonCallback(cocos2d::Ref *sender)
{
    log("priceButtonCall");
    
    
}












