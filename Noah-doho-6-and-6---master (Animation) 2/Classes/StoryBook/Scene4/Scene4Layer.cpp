//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene4Layer.h"
#include "SimpleAudioEngine.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene4Layer::Scene4Layer():mAnimationManager(NULL),noah_1prayed(NULL),noah_1_back(NULL)
{
    touch_next=false;
     ////CCLog("Scene 4 opened");
}
Scene4Layer::~Scene4Layer()
{
     SoundManager::sharedSoundManager()->stopNarrator();
     ////CCLog("Scene 4 closed");
}
void Scene4Layer::onEnter()
{
    this->setTouchEnabled(true);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    this->noah_1prayed->setFontName("Published-iOS/fonts/Portland LDO.ttf");
    this->noah_1_back->setFontName("Published-iOS/fonts/Portland LDO.ttf");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    this->noah_1prayed->setFontName("Palatino");
    this->noah_1_back->setFontName("Palatino");
#endif

    
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            this->noah_1prayed->setFontSize(70);
            this->noah_1_back->setFontSize(70);
            break;
        case 2:
            this->noah_1prayed->setFontSize(40);
            this->noah_1_back->setFontSize(40);
            break;
        case 3:
            this->noah_1prayed->setFontSize(40);
            this->noah_1_back->setFontSize(40);
            break;
        case 4:
            this->noah_1prayed->setFontSize(30);
            this->noah_1_back->setFontSize(30);
            break;
            
        default:
            break;
    }


    SoundManager::sharedSoundManager()->startBackgroundSound();
    this->schedule(schedule_selector(Scene4Layer::tick));

    CCLayer::onEnter();
}
void Scene4Layer::onExit()
{
        
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
     
    CCLayer::onExit();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene4Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    //CCLOG("on loaded called");
}
SEL_CallFuncN Scene4Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene4Layer::onNarratorStart);
     return NULL;
}
SEL_MenuHandler Scene4Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    ////CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene4Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    ////CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene4Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "noah_1prayed", CCLabelTTF *, this->noah_1prayed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "noah_1_back", CCLabelTTF *, this->noah_1_back);
    return false;
}
bool Scene4Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    ////CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene4Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
void Scene4Layer::tick(CCTime dt)
{
    ////CCLog("%u",sound_background_id);
}
#pragma mark -
#pragma mark Touch delegate
#pragma mark -
void Scene4Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    if (SoundManager::sharedSoundManager()->isNarratorPlaying())
    {
       
    }
    else
    {
        if (touch_next==false)
        {
            touch_next=true;
            GameManager::sharedGameManager()->gotoNextScene();
        }
    }
}
void Scene4Layer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    
}
