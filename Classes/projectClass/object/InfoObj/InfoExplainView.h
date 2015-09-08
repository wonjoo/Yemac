//
//  InfoExplainView.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#ifndef __YemacDesign__InfoExplainView__
#define __YemacDesign__InfoExplainView__

#include <stdio.h>
#include "ccxGameNode.h"
#include "ui/UIRichText.h"
#include "ImageInfoParser.h"

class InfoExplainView : public ccxGameNode<InfoExplainView>
{
private:
    
public:
    virtual void onEnter();
    virtual void setUI();
    //설명창 백그라운드 이미지와 정보 필요.
    virtual void setInfo(Sprite* box);
    
};

#endif /* defined(__YemacDesign__InfoExplainView__) */
