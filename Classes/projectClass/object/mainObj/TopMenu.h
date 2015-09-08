//
//  TopMenu.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#ifndef __YemacDesign__TopMenu__
#define __YemacDesign__TopMenu__

#include <stdio.h>
#include "ccxGameNode.h"
#include "UISubList.h"
#include "ImageInfoParser.h"
#include "MenuBoxManager.h"

class TopMenu : public ccxGameNode<TopMenu>, public UISubListDelegate
{
private:
    Vector<Sprite*> _vMenu;
public:
    
    TopMenu(){};
    virtual ~TopMenu(){};
    
    virtual bool init();
    virtual void onEnter();
    //메뉴바 세팅.
    virtual void setInfo();
    //탑타이틀을 중심으로 탑메뉴바의 위치를 정하기 위한 타이틀바위 위치와 이미지 크기를 가져온다.
    virtual Sprite* getTitleSprite();
    
    virtual void addDownImage(Point pt);
    virtual void addNormalImage(Point pt);
    //메뉴 선택시 서브 리스트를 가져온다.
    virtual void didFinishSelectedSubList(cocos2d::Ref *sender);
    //서브 리스트 호출.
    virtual void setCurrentList(Button* btn, Vector<__String*> vList);
    //메뉴선택이 가격일경우 사용
    virtual __String* getPurePriceNum(__String* str);
  
    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesMoved(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event);

};

#endif /* defined(__YemacDesign__TopMenu__) */
