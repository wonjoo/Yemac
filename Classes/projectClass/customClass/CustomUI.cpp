
#include "CustomUI.h"
#include "MainScene.h"


void CustomUI::setNormalBG()
{
    auto bg = Sprite::create("UI_NormalBG.png");
    bg->setPosition(screenCenter);
    addChild(bg);
}

void CustomUI::setTopTitle(const char* titleName)
{
    TopTitle* title = TopTitle::create(titleName);
    title->setTag(TAG_TITLE);
    this->addChild(title);
}


void CustomUI::setCloseButton()
{
    auto button = ui::Button::create("UI_CloseUp-hd.png", "UI_CloseDown-hd.png", "UIButtonsUI_CloseDown-hd.png");
    button->setPosition(ratioPosition(93, 96));
//    button->cocos2d::Node::setScale(0.8f);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2f, MainScene::createScene()));
                break;
            default:
                break;
        }
    });
    addChild(button);
}













