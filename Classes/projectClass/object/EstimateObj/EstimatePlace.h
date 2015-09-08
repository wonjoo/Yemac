//
//  EstimatePlace.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 24..
//
//

#ifndef __YemacDesign__EstimatePlace__
#define __YemacDesign__EstimatePlace__

#include <stdio.h>
#include "ccxGameNode.h"

class EstimatePlace : public ccxGameNode<EstimatePlace>
{
private:
    ListView* _lvFirst;
    ListView* _lvSecond;
    Vector<ui::Button*> _vFirstButton;
    Vector<ui::Button*> _vSecondButton;
    
    int _nTypeNum;
public:
    virtual void onEnter();
    //첫번째 공간을 선택한다.
    virtual void setFirstPlaceSelect();
    //그다음 세분화된 공간선택.
    virtual void setSecondPlaceSelect();
    virtual void setFirstSelect();
    virtual void setSecondSelect();
    virtual Vector<__String*>  setSecondSelectListInfo();
    virtual void setExplainLabel();
    virtual void firstPlaceAction();
    //첫번째 버튼선택시 호출
    virtual void firstPlaceActionCallBack();
    virtual void secondPlaceAction();
    virtual void setTypeLabel(int typeNum, const char* name);
    virtual void buttonCallBack(Ref* sender);
    virtual void SecondbuttonCallBack(Ref* sender);
    
};

#endif /* defined(__YemacDesign__EstimatePlace__) */
