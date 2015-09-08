//
//  InfoImagePageView.h
//  YemacDesign
//
//  Created by LeeWonJoo on 2015. 8. 17..
//
//

#ifndef __YemacDesign__InfoImagePageView__
#define __YemacDesign__InfoImagePageView__

#include <stdio.h>
#include "ccxGameNode.h"
#include "ImageInfoParser.h"

class InfoImagePageVeiw : public ccxGameNode<InfoImagePageVeiw>
{
private:
    Label* _lbPageNum;
public:
    virtual bool init();
    virtual void onEnter();
    //서브 이미지 정보 출력
    virtual void setPageView();
    //페이지 뷰 콜백 - 페이지 넘길시 우측 하단에 페이지 정보 출력
    virtual void pageviewCallBack(Ref* sender);
};


#endif /* defined(__YemacDesign__InfoImagePageView__) */
