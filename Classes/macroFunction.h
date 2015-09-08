#ifndef test_macroFunction_h
#define test_macroFunction_h

#define FPS (1.0f / 60.0f)

#define ccp(x, y) Vec2(x, y)
#define screenSize Director::getInstance()->getVisibleSize()
#define screenSizeX Director::getInstance()->getVisibleSize().width
#define screenSizeY Director::getInstance()->getVisibleSize().height
#define screenCenter ccp(screenSizeX / 2, screenSizeY / 2)
#define screenZero Vec2::ZERO

//#define YES true
//#define NO false

#define nil nullptr

#include "PlistManager.h"
#include "UserDataBase.h"

#define PLIST_MANAGER PlistManager::getInstance()
#define USER_DB UserDataBase::getInstance()
#define USER_DB_IMGNAME USER_DB->getUIImageNames()

#define GET_TOP_TITLE_SIZE 100


#pragma mark -TAG

#define TAG_TITLE 0
#define TAG_TITLE_BG 1
#define TAG_MENU_BOX_TITLE 2
#define TAG_BUTTON_STATE 3
#define TAG_PHOTO_LABEL 4
#define TAG_ESTIMATE_PREV 5
#define TAG_ESTIMATE_NEXT 6
#define TAG_SUB_LIST 7
#define TAG_MENUBOX 8
#define TAG_MENUBOXLIST 9
#define TAG_BTOM_BUTTON_HOME 10
#define TAG_BTOM_BUTTON_STORAGE 11
#define TAG_TOP_BUTTON_SPACE 12
#define TAG_TOP_BUTTON_MOOD 13
#define TAG_TOP_BUTTON_PRICE 14

#define TAG_STORAGE_BOX 100
#define TAG_MAIN_BOX 500

#pragma mark - enum





#endif













