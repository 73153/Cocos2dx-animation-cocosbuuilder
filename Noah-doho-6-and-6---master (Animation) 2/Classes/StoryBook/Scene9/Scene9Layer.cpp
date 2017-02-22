//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene9Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene9Layer::Scene9Layer():mAnimationManager(NULL),burns(NULL),dude(NULL),blackBeard(NULL),grandpa(NULL),gurlfriend(NULL)
{
    sound_people=0;
    started_playing=false;
    //CCLog("Scene 9 opened");
}
Scene9Layer::~Scene9Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
    //CCLog("Scene 9 closed");
}
void Scene9Layer::onExit()
{
     
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    CCLayer::onExit();
}
void Scene9Layer::onEnter()
{
    this->setTouchEnabled(true);
    this->load_sounds();
    SoundManager::sharedSoundManager()->startBackgroundSound();
    CCLayer::onEnter();
}
void  Scene9Layer::load_sounds()
{
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy1.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy2.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy3.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy4.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy5.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy6.mp3");
    whimpyGuySpeeches.push_back("Sound/Scene 8/whimpyGuy7.mp3");
   
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend1.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend2.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend3.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend4.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend5.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend6.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend7.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend8.mp3");
    womenSpeeches.push_back("Sound/Scene 8/gurlFriend9.mp3");
   
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard1.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard2.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard3.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard4.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard5.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard6.mp3");
    whiteBeardSpeeches.push_back("Sound/Scene 8/whiteBeard7.mp3");
    SoundManager::sharedSoundManager()->loadSondEffect(GameManager::sharedGameManager()->getcurrent_scene().getValue());
}
void Scene9Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    if (!SoundManager::sharedSoundManager()->isNarratorPlaying()&&started_playing==false)
    {
        CCTouch *touch = (CCTouch*)pTouches->anyObject();
        CCPoint location = touch->getLocationInView();
        location=CCDirector::sharedDirector()->convertToGL(location);
        //dude..
        if (GameManager::sharedGameManager()->isNodeAtPoint(dude, location))
        {
                dude->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/dude_speaking.png"));
                this->playsound(CCString::create("Sound/Scene 8/burns.mp3"));
                started_playing=true;
                this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
         }
         //burns
        else if (GameManager::sharedGameManager()->isNodeAtPoint(burns, location))
        {
             started_playing=true;
             random_shuffle( whimpyGuySpeeches.begin(), whimpyGuySpeeches.end() );
             CCString  *str=CCString::create(this->whimpyGuySpeeches[0].c_str());
             this->playsound(str);
             this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
             burns->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/burns_animating.png"));
            }
            //Gurl
        else if (GameManager::sharedGameManager()->isNodeAtPoint(gurlfriend, location))
        {
                started_playing=true;
                random_shuffle( womenSpeeches.begin(), womenSpeeches.end() );
                CCString  *str=CCString::create(this->womenSpeeches[0].c_str());
                this->playsound(str);
                this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
                gurlfriend->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/girl_friend_animate.png"));
            }
            //BlackBeard
        else if (GameManager::sharedGameManager()->isNodeAtPoint(blackBeard, location))
        {
                started_playing=true;
                this->playsound(CCString::create("Sound/Scene 8/blackbeard.mp3"));
                this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
                blackBeard->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/black_beard_animate.png"));
            }
            //Grandpa
        else if (GameManager::sharedGameManager()->isNodeAtPoint(grandpa, location))
        {
                started_playing=true;
                random_shuffle( whiteBeardSpeeches.begin(), whiteBeardSpeeches.end() );
                CCString  *str=CCString::create(this->whiteBeardSpeeches[0].c_str());
                this->playsound(str);
                this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
                grandpa->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/grandpa_animating.png"));
            }
        else
        {
            started_playing=true;
            this->playsound(CCString::create("Sound/Scene 8/crowdBooing.mp3"));
            this->schedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
        }
      }
}
void Scene9Layer::playsound(CCString *str_path)
{
    //CCLog("%s",str_path->getCString());
    SoundManager::sharedSoundManager()->setEffectVolume(1);
    SoundManager::sharedSoundManager()->stopSoundEffect(sound_people);
    sound_people=SoundManager::sharedSoundManager()->playSoundEffect(str_path->getCString(), false);
    //CCLog("%d",sound_people);
}
void Scene9Layer::WaitForSpeechToEnd(CCTime  dt)
{
    if (!SoundManager::sharedSoundManager()->isEffectPlaying(sound_people))
    {
       
       this->unschedule(schedule_selector(Scene9Layer::WaitForSpeechToEnd));
        started_playing=false;
       dude->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/dude_normal.png"));
       burns->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/burns_normal.png"));
       gurlfriend->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/girl_friend_normal.png"));
       blackBeard->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/black_beard_normal.png"));
       grandpa->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene9/grandpa_normal.png"));
    }
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene9Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene9Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene9Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
     CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene9Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene9Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene9Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene9Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "burns", CCSprite *, this->burns);
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dude", CCSprite *, this->dude);
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "blackBeard", CCSprite *, this->blackBeard);
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "grandpa", CCSprite *, this->grandpa);
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gurlfriend", CCSprite *, this->gurlfriend);
    return false;
}
bool Scene9Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
