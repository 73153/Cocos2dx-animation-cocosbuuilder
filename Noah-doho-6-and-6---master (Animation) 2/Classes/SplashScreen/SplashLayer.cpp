//  SplashLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "SplashLayer.h"
#include "../HomeScreen/homeLayerLoader.h"
#include "../GameManager/GameManager.h"
#include "../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
SplashLayer::SplashLayer():sprt(NULL)
{
    CCLog("constructor called");
}
SplashLayer::~SplashLayer()
{
    CCLog("destracture called");
}
void SplashLayer::onExit()
{
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void SplashLayer::onEnter()
{
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void SplashLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN SplashLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "splash_faded", SplashLayer::splash_faded);
    return NULL;
}
SEL_MenuHandler SplashLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler SplashLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool SplashLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool SplashLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Callfunctionselector
#pragma mark -
void SplashLayer::splash_faded(CCNode* sender)
{
   CCScene *home_scene=GameManager::sharedGameManager()->get_scene("HomeLayer.ccbi", "HomeLayer", HomeLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,home_scene));
}