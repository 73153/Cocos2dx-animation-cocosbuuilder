//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene6Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene6Layer::Scene6Layer():mAnimationManager(NULL),arkCompareNode_(NULL)
{
     //CCLog("Scene 6 opened");
}
Scene6Layer::~Scene6Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
    CC_SAFE_RELEASE(mAnimationManager);
    //CCLog("Scene 6 closed");
}
void Scene6Layer::onExit()
{
     
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
     

    CCLayer::onExit();
}

void Scene6Layer::onEnter()
{
    this->setTouchEnabled(true);
    is_narrator_playing=0;
    SoundManager::sharedSoundManager()->startBackgroundSound();
   // this->schedule(schedule_selector(Scene6Layer::tick));
    this->scheduleOnce(schedule_selector(Scene6Layer::tick), 5);
    CCLayer::onEnter();
}
void Scene6Layer::tick(CCTime dt)
{
    is_narrator_playing=1;
//    if (SoundManager::sharedSoundManager()->isNarratorPlaying())
//            is_narrator_playing=1;
//    
//    if (!SoundManager::sharedSoundManager()->isNarratorPlaying()&&is_narrator_playing==1)
//    {
//        is_narrator_playing=2;
//    }
}
#pragma mark -
#pragma mark Touch delegate
#pragma mark -
void Scene6Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    if(SoundManager::sharedSoundManager()->isNarratorPlaying())
        return;
    if(SoundManager::sharedSoundManager()->isInstractunalNoahplaying())
        return;
    if(arkCompareNode_->getis_comparing())
        return;
    if(is_narrator_playing!=1)
        return;
    
    arkCompareNode_->setis_comparing(true);
    arkCompareNode_->compare_next_object();
}
void Scene6Layer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene6Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene6Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene6Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene6Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene6Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene6Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "arkCompareNode_", ArkCompareNode *, this->arkCompareNode_);
    return false;
}
bool Scene6Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene6Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}