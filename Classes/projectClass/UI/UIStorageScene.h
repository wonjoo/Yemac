//
//  UIStorageScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#ifndef __YemacDesign__UIStorageScene__
#define __YemacDesign__UIStorageScene__

#include <stdio.h>
#include "CustomUI.h"
#include "StorageBoxManager.h"

class UIStorageScene : public CustomUI
{
private:
    StorageBoxManager* _boxList;
    Vector<LayerColor*> _vTrashLayer;
    bool _bReadyToRemove;
public:
    virtual bool init();
    virtual void onEnter();
    virtual void setUI();
    virtual void setTrashCan(Point position);
    virtual void setTrashImage();
    virtual void removeTrashImage();
    virtual void removeToTrash(Point pt);

    virtual void onTouchesBegan(const vector<Touch*> &touches, Event *unused_event);
    virtual void onTouchesEnded(const vector<Touch*> &touches, Event *unused_event);
  
    CREATE_FUNC(UIStorageScene);
};

#endif /* defined(__YemacDesign__UIStorageScene__) */
