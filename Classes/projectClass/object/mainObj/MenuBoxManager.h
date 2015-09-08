//
//  MenuBoxManager.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 14..
//
//

#ifndef __YemacDesign__MenuBoxManager__
#define __YemacDesign__MenuBoxManager__

#include <stdio.h>
#include "ccxGameNode.h"
#include "MenuBox.h"
#include "ImageInfoParser.h"
#include "UISubList.h"

class MenuBoxManager : public ccxGameNode<MenuBoxManager>
{
private:
    ListView* _lv;
    Vector<ui::Button*> _vButton;
    Point _tempPoint;
    Size _tempSize;
public:
    virtual bool init();
    virtual void onEnter();
    //리스트뷰 생성.
    virtual void setListView();
    //리스트뷰에 넣을 버튼을 백터로 여러개 생성.
    virtual void setBoxWithList(Vector<ImageInfoParser*> imgInfo);
    //리스트뷰에 넣을 버튼을 하나씩 생성.
    virtual void setBoxWithImgInfo(ImageInfoParser* imgInfo);
    //서브리스트 지우기
    virtual void removeSubList(Ref* sender);
    //박스선택시 호출되는 함수.
    virtual void buttonCallBack(Ref* sender);
    //버튼 박스에 정보를 입력한다.
    virtual void setImageWithName(Button* button, const char* ImgName);
    virtual void setTypeTitle(Button* button, const char* title);
    virtual void setTypeInfo(Button* button, const char* info);
    virtual void setPrice(Button* button, int price);
    virtual void removeListViewChildren();
};

#endif /* defined(__YemacDesign__MenuBoxManager__) */
