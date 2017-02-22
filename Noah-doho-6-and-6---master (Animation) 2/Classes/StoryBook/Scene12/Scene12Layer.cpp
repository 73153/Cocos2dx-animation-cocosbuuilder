//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene12Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene12Layer::Scene12Layer():mAnimationManager(NULL),raincloudnode_(NULL)
{
     //CCLog("Scene 12 opened");
}
Scene12Layer::~Scene12Layer()
{
     SoundManager::sharedSoundManager()->stopNarrator();
     //CCLog("Scene 12 closed");
}
void Scene12Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    CCLayer::onExit();
}
void Scene12Layer::onEnter()
{
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    this->setTouchEnabled(true);
    SoundManager::sharedSoundManager()->startBackgroundSound();
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene12Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene12Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
   // CCLOG("on loaded called");
}
SEL_CallFuncN Scene12Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
     CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene12Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene12Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene12Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene12Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "raincloudnode_", RainCloudNode*, raincloudnode_);
    return false;
}
bool Scene12Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
