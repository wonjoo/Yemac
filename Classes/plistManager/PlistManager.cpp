//
//  plistManager.cpp
//  AnEraser
//
//  Created by LeeWonJoo on 2015. 4. 21..
//
//

#include "PlistManager.h"

#pragma mark - readToDocumentsFunc
//읽어오기 document (array)
__Array* PlistManager::readToDocumentArrayPlistWithFileName(const char* fileName)
{
    return __Array::createWithContentsOfFileThreadSafe((FileUtils::getInstance()->getWritablePath() + (__String::createWithFormat("%s.plist",fileName))->getCString()).c_str());
}
//읽어오기 document (dictionary)
__Dictionary* PlistManager::readToDocumentDicPlistWithFileName(const char* fileName)
{
    return __Dictionary::createWithContentsOfFileThreadSafe((FileUtils::getInstance()->getWritablePath() + (__String::createWithFormat("%s.plist",fileName))->getCString()).c_str());
}

#pragma mark - readToBundleFunc
//읽어오기 bundle (array)
__Array* PlistManager::readToBundleArrayPlistWithFileName(const char* fileName)
{
    return __Array::createWithContentsOfFileThreadSafe((__String::createWithFormat("%s.plist",fileName))->getCString());
}

//읽어오기 bundle (dictionary)
__Dictionary* PlistManager::readToBundleDicPlistWithFileName(const char* fileName)
{
    return __Dictionary::createWithContentsOfFileThreadSafe((__String::createWithFormat("%s.plist",fileName))->getCString());

}
#pragma mark - writeRemoveFunc
//저장 document dic
bool PlistManager::writeToDocumentDicPlistWithFileName(const char* fileName, __Dictionary* data)
{
    std::string writablePath = FileUtils::getInstance()->getWritablePath();
    //딕셔너리로 피리스트 만들기 + 새성 경로
    std::string fullPath = writablePath +
    (__String::createWithFormat("%s.plist",fileName))->getCString();
    if(data->writeToFile(fullPath.c_str()))
    {
        log("see the plist file at %s", fullPath.c_str());
        return true;
    }
    else
    {
        log("write plist file failed");
        return false;
    }
}

//피리스트 날린다.
bool PlistManager::removeToDocumentPlistWithFileName(const char* fileName)
{
    std::string writablePath = FileUtils::getInstance()->getWritablePath();
    //딕셔너리로 피리스트 만들기 + 새성 경로
    std::string fullPath = writablePath + (__String::createWithFormat("%s.plist",fileName))->getCString();
    if(FileUtils::getInstance()->removeFile(fullPath.c_str()))
    {
        log("PlistManager:: Remove plistfile.");
        return true;
    }
    else
    {
        log("PlistManager:: can't find plistfile.");
        return false;
    }
}

//읽어오기 bundle (ValueVector)
ValueVector PlistManager::readToBundleValueVectorPlistWithFileName(const char* fileName)
{
    return FileUtils::getInstance()->getValueVectorFromFile((__String::createWithFormat("%s.plist",fileName))->getCString());
}

__String* PlistManager::getWratablePath()
{
    log("%s",FileUtils::getInstance()->getWritablePath().c_str());
    return __String::create(FileUtils::getInstance()->getWritablePath());
}


bool PlistManager::checkToDocumentDicPlistWithFileName(const char* fileName)
{
    __Dictionary* dic;
    dic = __Dictionary::createWithContentsOfFileThreadSafe((FileUtils::getInstance()->getWritablePath() + (__String::createWithFormat("%s.plist",fileName))->getCString()).c_str());
    std::string writablePath = FileUtils::getInstance()->getWritablePath();
    std::string fullPath = writablePath +
    (__String::createWithFormat("%s.plist",fileName))->getCString();
    log("see the plist file at %s", fullPath.c_str());
    if(dic->count() < 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//void PlistManager::onEnter()
//{

//    //번들 피리스트 읽기
//    ValueVector vec = FileUtils::getInstance()->getValueVectorFromFile("anEraser.plist");
//    std::string vec_0 = vec.at(0).asString();
//    std::string filepath;
//    //도큐멘트 주소.
//    filepath = FileUtils::getInstance()->getWritablePath();
//
//    //도큐멘트 주소.
//    log("%s",filepath.c_str());
//
//    //값 읽기
//    log("%s",(__String::create(vec.at(0).asString())->getCString()));
//
//    ValueMap map;

//    auto arr = __Array::createWithContentsOfFile("anEraser.plist");
//
//    __String* str = (__String*)arr->getObjectAtIndex(0);
//    log("bundle:: %s", str->getCString());
//
//    UserDefault::getInstance()->setStringForKey("strKey", "stirngData");
//
//    //    log("%s",)
//
//
//    //딕셔너리 만들기.
//    auto root = __Dictionary::create();
//    auto string = __String::create("create string value");
//    root->setObject(string, "strKey");
//    //피리스트 생성경로
//    std::string writablePath = FileUtils::getInstance()->getWritablePath();
//    //딕셔너리로 피리스트 만들기 + 새성 경로
//    std::string fullPath = writablePath + "text.plist";
//
//    if(root->writeToFile(fullPath.c_str()))
//        log("see the plist file at %s", fullPath.c_str());
//    else
//        log("write plist file failed");
//
//    auto sharedFileUtils = FileUtils::getInstance();
//    bool isExist = false;
//    isExist = sharedFileUtils->isFileExist(writablePath);
//
//    //파일 경로와 이름으로 딕셔너리 생성 및 데이터 가져오기.
//    auto loadDictInDict = __Dictionary::createWithContentsOfFile(fullPath.c_str());
//
//    loadDictInDict->objectForKey("strKey");
//    //스트링 값 가져오기.
//    auto boolValue = (__String*)loadDictInDict->objectForKey("strKey");
//    log("data :: %s",boolValue->getCString());
//    log("%s",writablePath.c_str());



//
//    auto sharedFileUtils = FileUtils::getInstance();
//    bool isExist = false;
//    isExist = sharedFileUtils->isFileExist(plist 경로);
//
//
//    - plist에서 데이터 가져오기
//
//    // 루트 딕셔너리 접근
//    auto loadDict = __Dictionary::createWithContentsOfFile(fullPath.c_str());
//    // 루트 딕셔너리 내 딕셔너리 접근
//    auto loadDictInDict = (__Dictionary*)loadDict->objectForKey("dictInDict, Hello World");
//    // 타입에 상관없이 String으로 저장.

//    - plist의 생성
//
//    auto root = Dictionary::create();
//    // 값 삽입auto string = String::create("string element value");
//    root->setObject(string, "string element key");
//    // 배열 삽입
//    auto array = Array::create();
//    // 배열 내 딕셔너리 삽입
//    auto dictInArray = Dictionary::create();
//    dictInArray->setObject(String::create("string in dictInArray value 0"), "string in dictInArray key 0");
//    dictInArray->setObject(String::create("string in dictInArray value 1"), "string in dictInArray key 1");
//    array->addObject(dictInArray);
//    // 배열 내 값 삽입
//    array->addObject(String::create("string in array"));
//    // 배열 내 배열 삽입
//    auto arrayInArray = Array::create();arrayInArray->addObject(String::create("string 0 in arrayInArray"));
//    arrayInArray->addObject(String::create("string 1 in arrayInArray"));
//    array->addObject(arrayInArray); root->setObject(array, "array");
//    // 딕셔너리 삽입
//    auto dictInDict = Dictionary::create();
//    // 딕셔너리 내 문자열 삽입
//    dictInDict->setObject(String::create("string in dictInDict value"), "string in dictInDict key");
//    // 딕셔너리 내 boolean 삽입
//    auto booleanObject = Bool::create(true);dictInDict->setObject(booleanObject, "bool");
//    // 딕셔너리 내 int 삽입
//    auto intObject = Integer::create(1024);dictInDict->setObject(intObject, "integer");
//    // 딕셔너리 내 float 삽입
//    auto floatObject = Float::create(1024.1024f);dictInDict->setObject(floatObject, "float");
//    // 딕셔너리 내 double 삽입
//    auto doubleObject = Double::create(1024.123);dictInDict->setObject(doubleObject, "double");
//    root->setObject(dictInDict, "dictInDict, Hello World");
//    // 데이터를 plist에 쓰기
//    std::string writablePath = FileUtils::getInstance()->getWritablePath();
//    std::string fullPath = writablePath + "text.plist";
//    if(root->writeToFile(fullPath.c_str()))
//        log("see the plist file at %s", fullPath.c_str());
//    else
//        log("write plist file failed");
//
//
//    - plist 존재 여부 확인
//
//    auto sharedFileUtils = FileUtils::getInstance();
//    bool isExist = false;
//    isExist = sharedFileUtils->isFileExist(plist 경로);
//
//
//    - plist에서 데이터 가져오기
//
//    // 루트 딕셔너리 접근
//    auto loadDict = __Dictionary::createWithContentsOfFile(fullPath.c_str());
//    // 루트 딕셔너리 내 딕셔너리 접근
//    auto loadDictInDict = (__Dictionary*)loadDict->objectForKey("dictInDict, Hello World");
//    // 타입에 상관없이 String으로 저장.
//    auto boolValue = (__String*)loadDictInDict->objectForKey("bool");
//    log("%s",boolValue->getCString());
//    auto floatValue = (__String*)loadDictInDict->objectForKey("float");
//    log("%s",floatValue->getCString());
//    auto intValue = (__String*)loadDictInDict->objectForKey("integer");
//    log("%s",intValue->getCString());
//    auto doubleValue = (__String*)loadDictInDict->objectForKey("double");
//    log("%s",doubleValue->getCString());




//}






















