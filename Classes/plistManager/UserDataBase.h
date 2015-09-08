//
//  UserDataBase.h
//  AnEraser
//
//  Created by LeeWonJoo on 2015. 4. 23..
//
//

#ifndef __AnEraser__UserDataBase__
#define __AnEraser__UserDataBase__

#include "SingletonClass.h"
#include "macroFunction.h"
#include "ImageInfoParser.h"


class UserDataBase : public SingletonClass<UserDataBase>
{
private:
    __Dictionary* _dicBundleData;
    __Dictionary* _dicDocumentData;
    Vector<ImageInfoParser*> _vTotalImageInfo;
    Vector<__Dictionary*> _vDocData;
public:
    //공간에 대한 정보(방,주방 등)
    CC_SYNTHESIZE(Vector<__String*>, _vSpaceList, vSpaceList);
    //분위기에 대한 정보(클래식, 등등)
    CC_SYNTHESIZE(Vector<__String*>, _vAirList, vAirList);
    //가격에 대한 정보(100만 500만)
    CC_SYNTHESIZE(Vector<__String*>, _vPriceList, vPriceList);
    
//    CC_SYNTHESIZE(Vector<ImageInfoParser*>, _vRoomInfo, vRoomInfo);
    
    
    UserDataBase();
    virtual ~UserDataBase();
    
    virtual void YemicInitDats();
    virtual __Array* getArrData(const char* keyName);
    virtual __Array* getImageInfo();
    virtual void splitImageInfo();
    virtual void setTotalImageInfo(__Dictionary* dicImageData);
    virtual Vector<ImageInfoParser*> getTotalImageInfo();
    //document관련
    //도큐멘트에있는 정보 인잇
    virtual void initDocumentData();
    //도큐멘트에 선택한 정보의 인덱스 넘버를 저장
    virtual void setDocInfoIdx(__String* idx);
    //도큐멘트에 선택한 정보의 인덱스를 가져온다.
    virtual __String* getDocInfoIdx();
    //보관함에 저장시 사용되는 함수.
    virtual void setDocStorageList(__String* saveIdx);
    //보관함에 사용될 도큐멘트 저장 리스트
    virtual Vector<__String*> getDocStorageList();
    //보관함에 있는 목록 삭제시 사용되는 함수.
    virtual void removeDocStorageList(__String* saveIdx);
};





#endif /* defined(__AnEraser__UserDataBase__) */
