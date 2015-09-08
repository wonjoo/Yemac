//
//  UISubList.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 31..
//
//

#ifndef __YemacDesign__UISubList__
#define __YemacDesign__UISubList__

#include <stdio.h>
#include "ccxGameNode.h"

class UISubListDelegate
{
public:
    virtual void didFinishSelectedSubList(Ref* sender)=0;
    virtual ~UISubListDelegate(){};
  
};

class UISubList : public ccxGameNode<UISubList>
{
private:
    Sprite* _sSubBG;
    Vector<Button*> _vButton;
 
public:
      CC_SYNTHESIZE(UISubListDelegate*, _delegate, delegate);

    virtual void initSpaceList();
    virtual void initAirList();
    virtual void initPriceList();
    
    virtual bool init();
    virtual void onEnter();
    virtual void setSubListBG();
    virtual void moveAction();
    virtual void setListView();
    virtual void setBoxWithText(Vector<__String*> vStr);
    virtual void setBoxWithPriceText(Vector<__String*> vStr);
    virtual void buttonCallBack(Ref* sender);
    
  
};








#endif /* defined(__YemacDesign__UISubList__) */
