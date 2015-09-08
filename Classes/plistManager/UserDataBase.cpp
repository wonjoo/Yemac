//
//  UserDataBase.cpp
//  AnEraser
//
//  Created by LeeWonJoo on 2015. 4. 23..
//
//

#include "UserDataBase.h"

UserDataBase::UserDataBase()
{
    if(!_dicBundleData)    _dicBundleData = __Dictionary::create();
    if(!_dicDocumentData)    _dicDocumentData = __Dictionary::create();
    
}
UserDataBase::~UserDataBase()
{
    if(_dicBundleData)
    {
        CC_SAFE_DELETE(_dicBundleData);
    }
    if(_dicDocumentData)
    {
        CC_SAFE_DELETE(_dicDocumentData);
    }
    
    
}

void UserDataBase::YemicInitDats()
{
    //번들 피리스트 불러옴
    _dicBundleData = PLIST_MANAGER->readToBundleDicPlistWithFileName("YemacBundleData-v1.0.0");
    
    __Array* arrData = getArrData("space");
    Ref* refStr;
    //피리스트에서 데이터 가져온다!
    CCARRAY_FOREACH(arrData, refStr)
    {
        _vSpaceList.pushBack(static_cast<__String*>(refStr));
    }
    
    arrData = getArrData("atmosphere");
    CCARRAY_FOREACH(arrData, refStr)
    {
        _vAirList.pushBack(static_cast<__String*>(refStr));
    }
    
    arrData = getArrData("price");
    CCARRAY_FOREACH(arrData, refStr)
    {
        _vPriceList.pushBack(static_cast<__String*>(refStr));
    }
    
    splitImageInfo();
    initDocumentData();
    _vDocData.pushBack(PLIST_MANAGER->readToDocumentDicPlistWithFileName("YemacDocument"));
    
}

__Array* UserDataBase::getArrData(const char *keyName)
{
    return static_cast<__Array*>(_dicBundleData->objectForKey(keyName));
}

__Array* UserDataBase::getImageInfo()
{
    return static_cast<__Array*>(_dicBundleData->objectForKey("sourceInfo"));
}

void UserDataBase::splitImageInfo()
{
    __Array* arrImageData = getImageInfo();
    Ref* rImageInfo;
    
    __Dictionary* dicImageData;
    CCARRAY_FOREACH(arrImageData, rImageInfo)
    {
        //피리스트에 있는 정보를 데이터 파서로 옮겨 벡터에 저장한다.
        dicImageData = static_cast<__Dictionary*>(rImageInfo);
        setTotalImageInfo(dicImageData);
    }
}

void UserDataBase::setTotalImageInfo(__Dictionary *dicImageData)
{
    ImageInfoParser* imgParser = new ImageInfoParser;
    imgParser->setidx(static_cast<__String*>(dicImageData->objectForKey("idx")));
    imgParser->settitle(static_cast<__String*>(dicImageData->objectForKey("title")));
    imgParser->setspace(static_cast<__String*>(dicImageData->objectForKey("space")));
    imgParser->setair(static_cast<__String*>(dicImageData->objectForKey("air")));
    imgParser->setprice(static_cast<__String*>(dicImageData->objectForKey("price")));
    imgParser->setimgName(static_cast<__String*>(dicImageData->objectForKey("ImgName")));
    imgParser->setsubImgName(static_cast<__Array*>(dicImageData->objectForKey("subImgName")));
    imgParser->setexplain(static_cast<__String*>(dicImageData->objectForKey("explain")));
    imgParser->setsave(static_cast<__String*>(dicImageData->objectForKey("save")));
    
    _vTotalImageInfo.pushBack(imgParser);
}

Vector<ImageInfoParser*> UserDataBase::getTotalImageInfo()
{
    return _vTotalImageInfo;
}

void UserDataBase::initDocumentData()
{
    __Dictionary* dic = __Dictionary::create();
    
    dic->setObject(__String::create(""), "infoIdx");
    dic->setObject(__Dictionary::create(), "storage");
    if(PLIST_MANAGER->checkToDocumentDicPlistWithFileName("YemacDocument"))
    {
        return;
    }
    PLIST_MANAGER->writeToDocumentDicPlistWithFileName("YemacDocument", dic);
    
}

void UserDataBase::setDocInfoIdx(__String* idx)
{
    __Dictionary* dicTemp = _vDocData.at(0);
    
    dicTemp->setObject(idx, "infoIdx");
    
    PLIST_MANAGER->writeToDocumentDicPlistWithFileName("YemacDocument", dicTemp);
    _vDocData.replace(0, PLIST_MANAGER->readToDocumentDicPlistWithFileName("YemacDocument"));
}
__String* UserDataBase::getDocInfoIdx()
{
    return static_cast<__String*>(_vDocData.at(0)->objectForKey("infoIdx"));
}
void UserDataBase::setDocStorageList(__String* saveIdx)
{
    __Dictionary* dicTemp = _vDocData.at(0);
    
    __Dictionary* dicData;
    dicData = dynamic_cast<__Dictionary*>(dicTemp->objectForKey("storage"));
    dicData->setObject(saveIdx, saveIdx->getCString());
    
    dicTemp->setObject(dicData, "storage");
    
    PLIST_MANAGER->writeToDocumentDicPlistWithFileName("YemacDocument", dicTemp);
    _vDocData.replace(0, PLIST_MANAGER->readToDocumentDicPlistWithFileName("YemacDocument"));
}
Vector<__String*> UserDataBase::getDocStorageList()
{
    __Dictionary* dic = static_cast<__Dictionary*>( _vDocData.at(0)->objectForKey("storage"));
    
    //키가저오기
    
    DictElement* dicEle;
    Vector<__String*> vStr;
    
    CCDICT_FOREACH(dic, dicEle)
    {
        __String* rKey = static_cast<__String*>(dicEle->getObject());
        __String* str = static_cast<__String*>(dic->objectForKey(rKey->getCString()));
        
        vStr.pushBack(static_cast<__String*>(str));
    }
    return vStr;
}

void UserDataBase::removeDocStorageList(cocos2d::__String *saveIdx)
{
    __Dictionary* dicTemp = _vDocData.at(0);
    
    __Dictionary* dicSaveData = static_cast<__Dictionary*>(dicTemp->objectForKey("storage"));
    
    dicSaveData->removeObjectForKey(saveIdx->getCString());
    
    dicTemp->setObject(dicSaveData, "storage");
    
    PLIST_MANAGER->writeToDocumentDicPlistWithFileName("YemacDocument", dicTemp);
    _vDocData.replace(0, PLIST_MANAGER->readToDocumentDicPlistWithFileName("YemacDocument"));
}



















