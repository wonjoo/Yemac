//
//  StorageScene.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 15..
//
//

#ifndef __YemacDesign__StorageScene__
#define __YemacDesign__StorageScene__

#include <stdio.h>
#include "ccxGameNode.h"
#include "UIStorageScene.h"

class StorageScene : public ccxGameNode<StorageScene>
{
private:
    
public:
    
    virtual bool init();
    virtual void onEnter();
    virtual void setClass();
};

#endif /* defined(__YemacDesign__StorageScene__) */
