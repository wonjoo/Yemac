#ifndef AnEraser_ccxSoundNode_h
#define AnEraser_ccxSoundNode_h

#include "ccxGameNode.h"
#include <SimpleAudioEngine.h>

using namespace CocosDenshion;

template <typename T>
class CC_DLL ccxSoundNode : public ccxGameNode <T>
{
private:
    cocos2d::ValueMap _vmSounds;
    
public:
    virtual bool init(void)
    {
        if (!ccxGameNode<T>::init()) return false;
        
        return true;
    }
    
    virtual void onEnter (void)
    {
        ccxGameNode<T>::onEnter();
    }
    
    virtual void onExit (void)
    {
        ccxGameNode<T>::onExit();
    }
    
#pragma mark-
#pragma mark Background
    
    //백그라운드 로딩~~~
    void preloadBgm (const char* fileName)
    {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic(fileName);
    }
    
    //백그라운드 플레이
    void playBgm (const char* fileName, bool loop)
    {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(fileName, loop);
    }
    
    //백그라운드 정지
    void stopBgm (bool release)
    {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic(release);
    }
    
    //백그라운드 일시정지
    void pauseBgm (void)
    {
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    }
    
    //백그라운드 일시정지 후 재시작..
    void resumeBgm (void)
    {
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
    
    //백그라운드 되감기
    void rewindBgm (void)
    {
        SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
    }
    
    //백그라운드 볼륨
    float getBgmVolume (void)
    {
        return SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
    }
    
    void setBgmVolume (float volume)
    {
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
    }
    
    //백그라운드 플레이 중이냐?
    bool isBgmPlaying (void)
    {
        SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    }

#pragma mark-
#pragma mark Effect
    
    //이펙트 로딩~~~
    void preloadEffect (const char* fileName)
    {
        SimpleAudioEngine::getInstance()->preloadEffect(fileName);
    }
    
    //이펙트 캐쉬에서 삭제한다
    void unloadEffectSound (const char* fileName)
    {
        SimpleAudioEngine::getInstance()->unloadEffect(fileName);
    }
    
    //이펙트 플레이
    void playEffect (const char* fileName, bool loop)
    {
        SimpleAudioEngine::getInstance()->playEffect(fileName, loop);
    }
    
    //이펙트 플레이 + 아이뒤 리턴
    int playEffectSoundValueID (const char* fileName, bool loop)
    {
        return SimpleAudioEngine::getInstance()->playEffect(fileName, loop);
    }
    
    void playManageEffectSound (const char* fileName, bool loop)
    {
        int sid = playEffectSoundValueID (fileName, loop);
        if (sid < 0)
        {
            log("soundID not found");
            return;
        }
        _vmSounds[fileName] = Value(sid);
    }
    
    //이펙트 정지
    void stopManageEffectSound (const char* fileName)
    {
        int sid = getEffectSoundID (fileName);
        if (sid < 0)
        {
            log("soundID not found");
            return;
        }
        SimpleAudioEngine::getInstance()->stopEffect(sid);
        _vmSounds.erase(fileName);
    }
    
    //이펙트 볼륨 셋업
    void setEffectSoundVolume (float volume)
    {
        SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
    }
    
    //이펙트 볼륨 가져오기
    float getEffectSoundVolume (void)
    {
        return SimpleAudioEngine::getInstance()->getEffectsVolume();
    }
    
    //이펙트 일시정지
    void pauseEffectSound (const char* fileName)
    {
        int sid = getEffectSoundID (fileName);
        if (sid < 0)
        {
            log("soundID not found");
            return;
        }
        
        SimpleAudioEngine::getInstance()->pauseEffect(sid);
    }
    
    //일시정지된 이펙트 다시 재생
    void resumeEffectSound (const char* fileName)
    {
        int sid = getEffectSoundID (fileName);
        if (sid < 0)
        {
            log("soundID not found");
            return;
        }
        
        SimpleAudioEngine::getInstance()->resumeEffect(sid);
    }
    
    //모든 이펙트 정지
    void stopAllEffectSound (void)
    {
        SimpleAudioEngine::getInstance()->stopAllEffects();
    }
    
    //모든 이펙트 일시 정지
    void pauseAllEffectSound (void)
    {
        SimpleAudioEngine::getInstance()->pauseAllEffects();
    }
    
    //일시 정지된 이펙트 모두 다시 재생
    void resumeAllEffectSound (void)
    {
        SimpleAudioEngine::getInstance()->resumeAllEffects();
    }
    
    //이펙트 아이디 반환
    int getEffectSoundID (const char* fileName)
    {
        if (_vmSounds.find(fileName) != _vmSounds.end())
        {
            return _vmSounds.find(fileName);
        }
        else return -1;
    }
};

#endif

















