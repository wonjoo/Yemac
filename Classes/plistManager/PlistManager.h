//
//  plistManager.h
//  AnEraser
//
//  Created by LeeWonJoo on 2015. 4. 21..
//
//

#ifndef __AnEraser__PlistManager__
#define __AnEraser__PlistManager__

#include "sceneBase.h"
#include "SingletonClass.h"

USING_NS_CC;

class PlistManager : public SingletonClass<PlistManager>
{
private:

public:
    
#pragma mark - readToDocumentsFunc
    //읽어오기 document (array)
    virtual __Array* readToDocumentArrayPlistWithFileName(const char* fileName);
    
    //읽어오기 document (dictionary)
    virtual __Dictionary* readToDocumentDicPlistWithFileName(const char* fileName);
#pragma mark - readToBundleFunc
    //읽어오기 bundle (array)
    virtual __Array* readToBundleArrayPlistWithFileName(const char* fileName);

    //읽어오기 bundle (dictionary)
    virtual __Dictionary* readToBundleDicPlistWithFileName(const char* fileName);
#pragma mark - writeRemoveFunc
    //저장 document dic
    virtual bool writeToDocumentDicPlistWithFileName(const char* fileName, __Dictionary* data);
    //피리스트 날린다.
    virtual bool removeToDocumentPlistWithFileName(const char* fileName);

    //읽어오기 bundle (ValueVector)
    ValueVector readToBundleValueVectorPlistWithFileName(const char* fileName);
    
    __String* getWratablePath();
    
    //번들 피리스트가 있는지 확인한다
    bool checkToDocumentDicPlistWithFileName(const char* fileName);
   // virtual void onEnter();
    
};

#endif /* defined(__AnEraser__plistManager__) */










