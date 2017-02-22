//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene11Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene11Layer::Scene11Layer():matchgamenode_(NULL)
{
     //CCLog("Scene 11 opened");
}
Scene11Layer::~Scene11Layer()
{
     SoundManager::sharedSoundManager()->stopNarrator();
     //CCLog("Scene 11 closed");
}
void Scene11Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
   
    CCLayer::onExit();
}
void Scene11Layer::onEnter()
{
    this->setTouchEnabled(true);
    SoundManager::sharedSoundManager()->stopBackgroundSound();

    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        CCNode *node=this->getChildByTag(11);
        node->setPosition(ccpAdd(node->getPosition(), ccp(0,80 )));
    }
    SoundManager::sharedSoundManager()->startBackgroundSound();
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene11Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene11Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene11Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene11Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene11Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene11Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "matchgamenode_", MatchGameNode *, this->matchgamenode_);
    return false;
}
bool Scene11Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void  Scene11Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}