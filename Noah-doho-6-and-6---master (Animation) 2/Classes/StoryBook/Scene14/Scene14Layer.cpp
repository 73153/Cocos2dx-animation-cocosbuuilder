//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene14Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"

#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene14Layer::Scene14Layer():mAnimationManager(NULL)
{
      //CCLog("Scene 14 opened");
}
Scene14Layer::~Scene14Layer()
{
    CC_SAFE_RELEASE(mAnimationManager);
     //CCLog("Scene 14 closed");
}
void Scene14Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
 
    CCLayer::onExit();
}
void Scene14Layer::onEnter()
{
    
    SoundManager::sharedSoundManager()->startBackgroundSound();
    this->setTouchEnabled(true);
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene14Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene14Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "splash_faded", Scene14Layer::splash_faded);
    return NULL;
}
SEL_MenuHandler Scene14Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene14Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene14Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mAnimationManager", CCBAnimationManager *, this->mAnimationManager);
    return false;
}
bool Scene14Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Callfunctionselector
#pragma mark -
void Scene14Layer::splash_faded(CCNode* sender)
{
    //CCScene *splash_scene=GameManager::sharedGameManager()->get_scene("HomeLayer.ccbi", "HomeLayer", HomeLayerLoader::loader(), CCScene::create());
//    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,splash_scene));
}
#pragma mark -
#pragma animationManaget
void Scene14Layer::setAnimationManager(cocos2d::extension::CCBAnimationManager *animationManager)
{
    if (animationManager)
    {
        CC_SAFE_RELEASE_NULL(mAnimationManager);
        mAnimationManager = animationManager;
        CC_SAFE_RETAIN(animationManager);
    }
}