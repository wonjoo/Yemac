//
//  StorageBoxManager.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#ifndef __YemacDesign__StorageBoxManager__
#define __YemacDesign__StorageBoxManager__

#include <stdio.h>
#include "ccxGameNode.h"
#include "MenuBox.h"
#include "ui/UIListView.h"
#include "ImageInfoParser.h"


class StorageBoxManager : public ccxGameNode<StorageBoxManager>
{
private:
//    ui::ListView* _lv;
//    Vector<ui::Button*> _vButton;
    Point _tempPoint;
    Size _tempSize;
public:
    CC_SYNTHESIZE(bool, _bRemoveBox, bRemoveBox);
    CC_SYNTHESIZE(Vector<ui::Button*> , _vButton, vButton);
    CC_SYNTHESIZE(ui::ListView*, _lv, lv);
    
    
    virtual bool init();
    virtual void onEnter();
    virtual void setListView();
    virtual void setBox();
    virtual void removeAction(Ref* sender);
    virtual void removeBox(Ref* sender);
    virtual void buttonCallBack(Ref* sender);
    virtual void setImageWithName( const char* ImgName);
    virtual void setTypeTitle( const char* title);
    virtual void setTypeInfo( const char* info);
    virtual void setPrice(int price);
};
#endif /* defined(__YemacDesign__StorageBoxManager__) */
