//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene5Layer.h"
#include "../../GameManager/GameManager.h"
#include "../Footer/FooterLayerLoader.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene5Layer::Scene5Layer():mAnimationManager(NULL),glowingArk(NULL),is_glowing(false)
{
     //CCLog("Scene 5 opened");
}
Scene5Layer::~Scene5Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
    CC_SAFE_RELEASE(mAnimationManager);
}
void Scene5Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void Scene5Layer::onEnter()
{
    setTouchEnabled(true);
    SoundManager::sharedSoundManager()->startBackgroundSound();
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        CCNode *node_bg=this->getChildByTag(123);
        node_bg->setPosition(ccpAdd(node_bg->getPosition(),ccp(0, 45)));
        glowingArk->setPosition(ccpAdd(glowingArk->getPosition(), ccp(0,45)));
    }
    glowingArk->runAction(CCFadeTo::create(0.0, 0.0f));
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene5Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene5Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene5Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene5Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene5Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene5Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mAnimationManager", CCBAnimationManager *, this->mAnimationManager);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "glowingArk", CCSprite *, this->glowingArk);
   return false;
}
bool Scene5Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene5Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
#pragma mark -
#pragma Touch Delegate
#pragma mark -
void Scene5Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    if (is_glowing==false)
    {
        //CCLog("touch begin");
        is_glowing=true;
        glowingArk->runAction(CCFadeIn::create(0.8f));
        sound_force_field=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 5/forceFieldHumm.mp3", true);
        
    }
}
void Scene5Layer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
//    if (is_glowing==false)return;
    is_glowing=false;
    //CCLog("touch end");
    glowingArk->stopAllActions();
    glowingArk->runAction(CCFadeTo::create(0.6, 0.0f));
    if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_force_field))
    SoundManager::sharedSoundManager()->stopSoundEffect(sound_force_field);

}
void Scene5Layer::ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    this->ccTouchesEnded(pTouches, pEvent);
    //CCLog("touch cancel");
}