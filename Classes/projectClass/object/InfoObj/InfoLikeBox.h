//
//  InfoLikeBox.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 18..
//
//

#ifndef __YemacDesign__InfoLikeBox__
#define __YemacDesign__InfoLikeBox__

#include <stdio.h>
#include "ccxGameNode.h"

class InfoLikeBox : public ccxGameNode<InfoLikeBox>
{
private:
    bool _bIsLike;
public:
    
    virtual bool init();
    virtual void onEnter();
    virtual void setUI();
    //버튼 콜백(보관함 저장 등등)
    virtual void likeButtonCallBack(Ref* sender);
    //도큐멘터리에 정보 인덱스 저장
    virtual void saveLikeList();
    //도큐멘터리에 정보 인덱스 삭제
    virtual void removeLikeList();
};

#endif /* defined(__YemacDesign__InfoLikeBox__) */
