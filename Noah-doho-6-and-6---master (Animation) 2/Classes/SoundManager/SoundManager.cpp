//
//  SoundManager.cpp
//  Noah360univarsal
//
//  Created by Neil D on 17/09/13.
#include "SoundManager.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;
SoundManager* SoundManager::m_mySingleton = NULL;
SoundManager::SoundManager():sound_narrator_id(0),soundFX(0),sound_background_id(0),sound_instractunalnoah_id(0),arr_instractunalNoah(NULL)
{
    arr_instractunalNoah=CCArray::create();
    arr_instractunalNoah->retain();
}
SoundManager* SoundManager::sharedSoundManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new SoundManager();
    }
    //Return the singleton object
    return m_mySingleton;
}
#pragma mark -
#pragma mark play sound
#pragma mark -
unsigned int SoundManager::playSoundEffect(const char* filename,bool islooping)
{
    
    //    if (this->isEffectPlaying(soundFX))
    //    {
    //        SimpleAudioEngine::sharedEngine()->stopEffect(soundFX);
    //        soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename, islooping);
    //    }
    //    else
    //    {
    soundFX=0;
    soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename, islooping);
    //    }
    
    //set if mute
    // CCString *str=CCString::createWithFormat("%s",filename);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //      string s = str->m_sString;
    //      size_t f1 = s.find(".mp3");
    //      s.replace(f1, std::string(".mp3").length(), ".ogg");
    //      size_t f2 = s.find(".ogg");
    //      s.replace(f2, std::string(".ogg").length(), ".ogg");
    //      size_t f3 = s.find(".wav");
    //      s.replace(f3, std::string(".wav").length(), ".ogg");
    //     if (CCFileUtils::sharedFileUtils()->isFileExist(s))
    //     {
    //         CCLog("%s",s.c_str());
    //     }
    //    size_t f4 = s.find(".ogg");
    //    s.replace(f4, std::string(".ogg").length(), ".mp3");
    //    size_t f5 = s.find(".ogg");
    //    s.replace(f5, std::string(".ogg").length(), ".ogg");
    //    size_t f6 = s.find(".ogg");
    //    s.replace(f6, std::string(".ogg").length(), ".wav");
#endif
    if (GameManager::sharedGameManager()->getmutedFX())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(soundFX);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(soundFX);
#endif
    }
    //soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename);
    return soundFX;
}
void SoundManager::stopSoundEffect(unsigned int stop_sound)
{
    SimpleAudioEngine::sharedEngine()->stopEffect(stop_sound);
}
bool SoundManager::isEffectPlaying( unsigned int stop_sound)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(stop_sound);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(stop_sound);
#endif
}
void SoundManager::stopAllEffect()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(soundFX);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_instractunalnoah_id);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_narrator_id);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_background_id);
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
#pragma mark -
#pragma mark Load sounds
#pragma mark -
void SoundManager::loadSondEffect(int scene)
{
    SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/playful_sweep_20.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/nextButtoPressed.mp3");
    switch (scene)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/ambient.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Annehelm Scream.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Boo Crowd.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/choke.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Crash Metal 5.ogg");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Annehelm Scream.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Boo Crowd.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/choke.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Crash Metal 5.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/drunk.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/drunk.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeIn.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeOut.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeOut.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeOut.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireLong.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Horror Crazy People.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Horror Crazy People.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/mean.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/mean.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/narratorScene2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/narratorScene1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Smash Glass.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Smash Glass.ogg");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/thief.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/thief.ogg");
            
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3");
            
            break;
        }
        case 2:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/ambient.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Annehelm Scream.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Boo Crowd.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/choke.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Crash Metal 5.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/drunk.ogg");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Annehelm Scream.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Boo Crowd.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/choke.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Crash Metal 5.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/drunk.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeOut.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeIn.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireFadeOut.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/fireLong.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Horror Crazy People.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Smash Glass.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/thief.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/mean.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/narratorScene2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/narratorScene1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/Smash Glass.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 1 and 2/thief.ogg");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3");
            break;
        }
        case 3:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 3/doveFlap.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/forceFieldHumm.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/Impact laser.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/explosionNear.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/explosionFar.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/PHAZE DOWN.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/fireballExplosionMidair.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/doveSkaw.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/noahCantBelieve.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/noahDontKnow.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/noahDontUnderstand.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/doveFlap.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/fireballLaunchFar.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/fireballLaunchNear.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/fireballLaunchFar.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/fireballLaunchNear.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/narratorScene3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/instructionalNoahScene3-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/instructionalNoahScene3-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 3/instructionalNoahScene3-3.mp3");
            break;
        }
        case 4:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 4/narratorScene4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 4/instructionalNoahScene4-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 4/instructionalNoahScene4-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 4/instructionalNoahScene4-3.mp3");
            break;
        }
        case 5:
        {
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/forceFieldHumm.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/instructionalNoahScene5-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/instructionalNoahScene5-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/instructionalNoahScene5-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/narratorScene5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 5/scene5BackgroundMusic.mp3");
            break;
        }
        case 6:
        {
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Bus_School_Horn.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/ELEPHANT.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/fieldWhistle.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/instructionalNoahScene6-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/instructionalNoahScene6-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/instructionalNoahScene6-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/instructionalNoahScene6-4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/narratorScene6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_1.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_2.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_1.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_2.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_3.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 6/Whoosh_3.ogg");
            break;
        }
        case 7:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 7/instructionalNoahScene7-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 7/instructionalNoahScene7-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 7/narratorScene7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 7/rushingFloodwaters.mp3");
            break;
        }
        case 8:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/crowdBooing.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone8.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/arkPieceDone9.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/gamePiano.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/HOUSE Impact.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/magic_flourish_04.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/magic_flourish_05.mp3");
            // SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/magicZing.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkBuildFinished.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkDeck1Done.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkDeck2Done.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkFrameDone.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkStarting.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/pieceToPlace.mp3");
            break;
        }
        case 9:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/gamePiano.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/instructionalNoahScene8-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/instructionalNoahScene8-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/crowdBooing.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/crowdBooing.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whimpyGuy7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend8.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/gurlFriend9.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/whiteBeard7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/blackbeard.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 8/burns.mp3");
            
            
            break;
        }
        case 10:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/AllTheOthers.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/BackRattleSnake.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/CamelRisingHump.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/ChameleonAppear.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/CrocodileChomp.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/DucksMix.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/ElephantFade.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/Goat.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/instructionalNoahScene10-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/instructionalNoahScene10-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/instructionalNoahScene10-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/KangarooBoingUp.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/Mantis.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/narratorScene10.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/noah_scene_10_ver3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/OtterChuckle.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/PelicanHallo.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/PigROTFL.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/PorcupineOhNo.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/PossumChatter.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/SheepBaah.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/Tiger.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 10/ZebraWhinny.mp3");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 10/scene10BackgroundMusic.mp3");
            break;
        }
        case 11:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 9/noahArkBuildFinished.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/scene11Instructions.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/NoahGreatjob.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/jingle.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/cerdito.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/elefante.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/gallina.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/gato.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/leon.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/mono.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/oveja.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/panda.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/rana.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/vaca.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/Bell Transition.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/wrong match deny.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/card flip.caf");
            
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/scene11Instructions.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/NoahGreatjob.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/jingle.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/cerdito.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/elefante.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/gallina.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/gato.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/leon.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/mono.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/oveja.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/panda.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/rana.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/vaca.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/Bell Transition.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/wrong match deny.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 11/card flip.ogg");
            
            break;
        }
        case 12:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/WATER RISING.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/Cloud 1_raindrop with reverb.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/Cloud 2_multiple drops no pitch drop with reverb.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/wind.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/thunder1.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/thunder2.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/wind.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/thunder1.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/thunder2.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/instructionalNoahScene12-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/instructionalNoahScene12-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 12/scene12Narrator.mp3");
            break;
        }
        case 13:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/animalFalling.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/loadTheBoatCheer.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/short_flourish_09.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_boa.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_cat.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_chiken.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_cow.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_elephant.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_goat.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_husky.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_komodo.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_lion.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_monkey.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_panda.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_panther.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_peacock.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_pig.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/LTB_sheep.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/animalSplash.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/final victory cheer.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/rubberBoing.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/RubberRubb.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/scene13BackgroundMusic.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/scene13Congratulations.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/scene13CongratulationsMinor.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/scene13Instructions.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/splat.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 13/victory.mp3");
            break;
        }
        case 14:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmA.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmB.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmC.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmD.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmE.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmF.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmG.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmMOON.mp3");
            
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_A.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_B.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_C.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_D.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_E.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_F.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_G.mp3");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_MOON.mp3");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/scene14Narrator.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_A.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_B.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_C.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_D.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_E.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_F.m4a");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_G.m4a");
            
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/acoustic_MOON.m4a");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/coolmallet_MOON.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/instructionalNoahScene14-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/instructionalNoahScene14-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 14/NighBackgroundMusic.caf");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 14/NighBackgroundMusic.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 14/scene14Narrator.ogg");
            break;
        }
        case 15:
        {
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/instructionalNoahScene15-2.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/oceanAmbience.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/splashFromFish.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/fishingNoahGotFish.caf");
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/fishingNoahGotFish.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/instructionalNoahScene15-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/instructionalNoahScene15-2.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/instructionalNoahScene15-3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/narratorScene15.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/oceanAmbience.ogg");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 15/splashFromFish.ogg");
            break;
        }
        case 16:
        {
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/narratorScene16.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16DoveTakeFlight.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16IdleDove.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16NoahInstruction.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16NoahOnTouch5.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16onTouch.caf");
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/areYouReadyGo.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/narratorScene16.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/raincloud sound fx.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16DoveTakeFlight.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16IdleDove.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16NoahInstruction.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16NoahOnTouch5.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 16/scene16onTouch.ogg");
            break;
        }
        case 17:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/narratorScene17_2.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/narratorScene17_1.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/hiFivePow.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/arkCrashing.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/animalBouncing.caf");
            
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/narratorScene17_2.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/narratorScene17_1.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/hiFivePow.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/arkCrashing.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/animalBouncing.ogg");
            
            break;
        }
        case 18:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/bearTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/hippoTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/rabbitTouchedSound1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/rabbitTouchedSound2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/racoonTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound3.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound4.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound5.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound6.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound7.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/snakeTouchedSound8.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmA.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmB.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmC.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmD.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmE.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmF.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmG.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/StlDmMOON.mp3");
            break;
        }
        case 19:
        {
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/scene17cNarrator.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/instructionalNoahScene17c-1.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/instructionalNoahScene17c-2.mp3");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/countryMorning.caf");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/flowerChime.caf");
            
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/countryMorning.ogg");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Sound/Scene 17/flowerChime.ogg");
            break;
        }
        default:
        {
            break;
        }
    }
}
#pragma mark -
#pragma mark Remove sounds
#pragma mark -
void SoundManager::unLoadSoundEffect(int scene)
{
    SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/playful_sweep_20.mp3");
    SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/nextButtoPressed.mp3");
    
    switch (scene)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Annehelm Scream.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Boo Crowd.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/choke.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Crash Metal 5.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/drunk.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeOut.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Horror Crazy People.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/mean.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Smash Glass.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/thief.caf");
            
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/ambient.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Annehelm Scream.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Boo Crowd.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/choke.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Crash Metal 5.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/drunk.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeIn.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeOut.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireLong.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Horror Crazy People.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/mean.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/narratorScene2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/narratorScene1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Smash Glass.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/thief.ogg");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3");
            
            break;
        }
        case 2:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Annehelm Scream.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Boo Crowd.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/choke.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Crash Metal 5.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/drunk.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeOut.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Horror Crazy People.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/mean.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Smash Glass.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/thief.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Smash Glass.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/thief.caf");
            
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/ambient.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Annehelm Scream.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Boo Crowd.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/choke.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Crash Metal 5.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/drunk.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeIn.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireFadeOut.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/fireLong.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Horror Crazy People.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/mean.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/narratorScene2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/narratorScene1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Philhelm Whimper.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/Smash Glass.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 1 and 2/thief.ogg");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3");
            break;
        }
        case 3:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/fireballLaunchFar.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/fireballLaunchNear.caf");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 3/doveFlap.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/forceFieldHumm.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/Impact laser.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/explosionNear.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/explosionFar.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/PHAZE DOWN.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/fireballExplosionMidair.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/doveSkaw.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/noahCantBelieve.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/noahDontKnow.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/noahDontUnderstand.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/doveFlap.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/fireballLaunchFar.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/fireballLaunchNear.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/narratorScene3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/instructionalNoahScene3-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/instructionalNoahScene3-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 3/instructionalNoahScene3-3.mp3");
            break;
        }
        case 4:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 4/narratorScene4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 4/instructionalNoahScene4-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 4/instructionalNoahScene4-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 4/instructionalNoahScene4-3.mp3");
            break;
        }
        case 5:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/forceFieldHumm.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/instructionalNoahScene5-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/instructionalNoahScene5-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/instructionalNoahScene5-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/narratorScene5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 5/scene5BackgroundMusic.mp3");
            break;
        }
        case 6:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_1.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_2.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_3.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/scene5BackgroundMusic.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Bus_School_Horn.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/ELEPHANT.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/fieldWhistle.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/instructionalNoahScene6-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/instructionalNoahScene6-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/instructionalNoahScene6-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/instructionalNoahScene6-4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/narratorScene6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_1.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_2.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 6/Whoosh_3.ogg");
            break;
        }
        case 7:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 7/instructionalNoahScene7-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 7/instructionalNoahScene7-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 7/narratorScene7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 7/rushingFloodwaters.mp3");
            break;
        }
        case 8:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/crowdBooing.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone8.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/arkPieceDone9.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/gamePiano.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/HOUSE Impact.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/magic_flourish_04.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/magic_flourish_05.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkBuildFinished.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkDeck1Done.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkDeck2Done.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkFrameDone.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkStarting.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/pieceToPlace.mp3");
            break;
        }
        case 9:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/gamePiano.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/instructionalNoahScene8-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/instructionalNoahScene8-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/crowdBooing.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whimpyGuy7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend8.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/gurlFriend9.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/whiteBeard7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/blackbeard.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 8/burns.mp3");
            
            
            break;
        }
        case 10:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/AllTheOthers.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/BackRattleSnake.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/CamelRisingHump.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/ChameleonAppear.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/CrocodileChomp.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/DucksMix.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/ElephantFade.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/Goat.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/instructionalNoahScene10-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/instructionalNoahScene10-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/instructionalNoahScene10-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/KangarooBoingUp.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/Mantis.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/narratorScene10.mp3");
            // SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/noah_scene_10_ver3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/OtterChuckle.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/PelicanHallo.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/PigROTFL.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/PorcupineOhNo.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/PossumChatter.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/SheepBaah.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/Tiger.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 10/ZebraWhinny.mp3");
            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/Scene 10/scene10BackgroundMusic.mp3");
            break;
        }
        case 11:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 9/noahArkBuildFinished.mp3");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/scene11Instructions.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/NoahGreatjob.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/jingle.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/cerdito.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/elefante.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/gallina.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/gato.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/leon.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/mono.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/oveja.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/panda.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/rana.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/vaca.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/Bell Transition.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/wrong match deny.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/card flip.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/scene11Instructions.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/NoahGreatjob.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/jingle.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/cerdito.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/elefante.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/gallina.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/gato.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/leon.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/mono.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/oveja.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/panda.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/rana.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/vaca.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/Bell Transition.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/wrong match deny.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 11/card flip.ogg");
            
            break;
        }
        case 12:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/wind.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/thunder1.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/thunder2.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/WATER RISING.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/Cloud 1_raindrop with reverb.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/Cloud 2_multiple drops no pitch drop with reverb.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/wind.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/thunder1.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/thunder2.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/instructionalNoahScene12-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/instructionalNoahScene12-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 12/scene12Narrator.mp3");
            break;
        }
        case 13:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/loadTheBoatCheer.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/short_flourish_09.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/animalFalling.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/loadTheBoatCheer.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/short_flourish_09.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_boa.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_cat.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_chiken.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_cow.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_elephant.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_goat.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_husky.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_komodo.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_lion.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_monkey.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_panda.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_panther.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_peacock.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_pig.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/LTB_sheep.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/animalSplash.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/final victory cheer.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/rubberBoing.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/RubberRubb.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/scene13BackgroundMusic.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/scene13Congratulations.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/scene13CongratulationsMinor.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/NighBackgroundMusic.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/NighBackgroundMusic.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/scene13Instructions.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/splat.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 13/victory.mp3");
            break;
        }
        case 14:
        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_A.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_B.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_C.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_D.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_E.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_F.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_G.mp3");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_MOON.mp3");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmA.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmB.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmC.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmD.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmE.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmF.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmG.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmMOON.mp3");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_A.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_B.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_C.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_D.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_E.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_F.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_G.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/acoustic_MOON.m4a");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/coolmallet_MOON.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/instructionalNoahScene14-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/instructionalNoahScene14-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 14/scene14Narrator.ogg");
            break;
        }
        case 15:
        {
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/fishingNoahGotFish.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/instructionalNoahScene15-2.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/oceanAmbience.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/splashFromFish.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/fishingNoahGotFish.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/instructionalNoahScene15-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/instructionalNoahScene15-2.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/instructionalNoahScene15-3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/narratorScene15.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/oceanAmbience.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/scene15BackMusic.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 15/splashFromFish.ogg");
            break;
        }
        case 16:
        {
            
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/narratorScene16.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16DoveTakeFlight.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16IdleDove.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16NoahInstruction.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16NoahOnTouch5.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16onTouch.caf");
            
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/areYouReadyGo.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/narratorScene16.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/raincloud sound fx.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16DoveTakeFlight.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16IdleDove.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16NoahInstruction.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16NoahOnTouch5.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 16/scene16onTouch.ogg");
            break;
        }
        case 17:
        {
            
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/narratorScene17_2.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/narratorScene17_1.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/hiFivePow.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/arkCrashing.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/animalBouncing.caf");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/narratorScene17_2.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/narratorScene17_1.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/hiFivePow.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/arkCrashing.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/animalBouncing.ogg");
            
            break;
        }
        case 18:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/bearTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/hippoTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/rabbitTouchedSound1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/rabbitTouchedSound2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/racoonTouchedSound.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound3.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound4.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound5.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound6.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound7.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/snakeTouchedSound8.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmA.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmB.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmC.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmD.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmE.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmF.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmG.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/StlDmMOON.mp3");
            break;
        }
        case 19:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/scene17cNarrator.mp3");
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/instructionalNoahScene17c-1.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/instructionalNoahScene17c-2.mp3");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/countryMorning.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/flowerChime.ogg");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/countryMorning.caf");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Sound/Scene 17/flowerChime.caf");
            break;
        }
        default:
        {
            break;
        }
    }
    CCLog("unload sound effect callled");
    SimpleAudioEngine::sharedEngine()->end();
}
#pragma mark -
#pragma mark Background sound
#pragma mark -
void SoundManager::startBackgroundSound()
{
    int scene=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    TargetPlatform platForm = CCApplication::sharedApplication()->getTargetPlatform();
    
    switch (scene)
    {
        case 0:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/noah_scene_10_ver3.mp3", true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/noah_scene_10_ver3.mp3", true);
            }
            
            break;
        }
        case 1:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
            }
            
            break;
        }
        case 2:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
                
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
            }
            
            break;
        }
        case 3:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 1 and 2/GuitarBackgound.mp3", true);
            }
            
            break;
        }
        case 4:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3", true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3", true);
            }
            
            break;
        }
        case 5:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            
            break;
        }
        case 6:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            
            break;
        }
        case 7:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            
            break;
        }
        case 8:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 9/gamePiano.mp3",true);
                
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 9/gamePiano.mp3",true);
                
            }
            
            break;
        }
        case 9:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 9/gamePiano.mp3",true);
                
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 9/gamePiano.mp3",true);
                
            }
            break;
        }
        case 10:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/noah_scene_10_ver3.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/noah_scene_10_ver3.mp3",true);
            }
            
            break;
        }
        case 11:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 11/scene11BackgroundMusic.mp3");
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 11/scene11BackgroundMusic.ogg",true);
            }
            break;
        }
        case 12:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/scene10BackgroundMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/scene10BackgroundMusic.mp3",true);
            }
            
            break;
        }
        case 13:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 13/scene13BackgroundMusic.mp3",false);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 13/scene13BackgroundMusic.mp3",false);
            }
            
            break;
        }
        case 14:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 5/scene5BackgroundMusic.mp3",true);
            }
            
            break;
        }
        case 15:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",true);
            }
            
            break;
        }
        case 16:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 13/scene13BackgroundMusic.mp3",false);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 13/scene13BackgroundMusic.mp3",false);
            }
            
            break;
        }
        case 17:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",true);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",true);
            }
            
            break;
        }
        case 18:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 17/scene18BacgroundMusic.mp3",false);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 17/scene18BacgroundMusic.mp3",false);
            }
            
            break;
        }
        case 19:
        {
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",false);
            }
            else
            {
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 15/scene15BackMusic.mp3",false);
            }
            
            
            break;
        }
        default:
        {
            break;
        }
    }
}
void SoundManager::stopBackgroundSound()
{
    CCLOG("Stoped background music");
    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
}
bool SoundManager::is_backgroundMusicPlaying()
{
    return  SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
}
#pragma mark -
#pragma mark Play Narrator
#pragma mark -
void SoundManager::startNarrator()
{
    
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    
    int scene=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    CCLOG("scene %d",scene);
    switch (scene)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 1 and 2/narratorScene1.mp3");
            
            break;
        }
        case 2:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 1 and 2/narratorScene2.mp3");
            break;
        }
        case 3:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 3/narratorScene3.mp3");
            break;
        }
        case 4:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 4/narratorScene4.mp3");
            break;
        }
        case 5:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 5/narratorScene5.mp3");
            break;
        }
        case 6:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 6/narratorScene6.mp3");
            break;
        }
        case 7:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 7/narratorScene7.mp3");
            break;
        }
        case 8:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 8/narratorScene8.mp3");
            break;
        }
        case 9:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 8/narratorScene8.mp3");
            
            break;
        }
        case 10:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 10/narratorScene10.mp3");
            break;
        }
        case 11:
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 11/scene11Instructions.caf");
            }
            else
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 11/scene11Instructions.ogg");
            }
            
            break;
        }
        case 12:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 12/scene12Narrator.mp3");
            break;
        }
        case 13:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 13/scene13Instructions.mp3");
            break;
        }
        case 14:
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 14/scene14Narrator.caf");
            }
            else
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 14/scene14Narrator.ogg");
            }
            
            break;
        }
        case 15:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 15/narratorScene15.mp3");
            break;
        }
        case 16:
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 16/narratorScene16.caf");
            }
            else
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 16/narratorScene16.ogg");
            }
            
            break;
        }
        case 17:
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 17/narratorScene17_1.caf");
            }
            else
            {
                sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 17/narratorScene17_1.ogg");
            }
            
            break;
        }
        case 18:
        {
            break;
        }
        case 19:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 17/scene17cNarrator.mp3");
            break;
        }
        default:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Sound/Scene 17/noah_scene_10_ver3.mp3");
            break;
        }
    }
    //set if mute
    if (GameManager::sharedGameManager()->getmutedNarrator())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(sound_narrator_id);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(sound_narrator_id);
#endif
    }
}
void SoundManager::stopNarrator()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_narrator_id);
}
bool SoundManager::isNarratorPlaying()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(sound_narrator_id);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(sound_narrator_id);
#endif
}
#pragma mark -
#pragma mark set effect volume
#pragma mark -
void SoundManager::setEffectVolume(float volume)
{
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
}
float SoundManager::getEffectVolume()
{
    return  SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}
#pragma mark -
#pragma mark  background musicvolume
#pragma mark -
void SoundManager::set_Backgound_MusicVolume(float volume)
{
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
}
float SoundManager::get_Backgrond_MusicVolume()
{
    return  SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}
#pragma mark -
#pragma mark  instractunal noah
#pragma mark -
unsigned int SoundManager::startInstractunalNoah(CCString *name)
{
    sound_instractunalnoah_id=SimpleAudioEngine::sharedEngine()->playEffect(name->getCString(), false);
    //set if mute
    if (GameManager::sharedGameManager()->getmutedFX())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(sound_instractunalnoah_id);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //        SimpleAudioEngine::sharedEngine()->setEffectMute(sound_instractunalnoah_id);
#endif
    }
    return sound_instractunalnoah_id;
}
void SoundManager::stopInstractunalNoah()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_instractunalnoah_id);
}
bool SoundManager::isInstractunalNoahplaying()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(sound_instractunalnoah_id);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    return SimpleAudioEngine::sharedEngine()->isEffectPlaying(sound_instractunalnoah_id);
#endif
}