//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene2Layer.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/common_function.h"
#include "../../GameManager/GameManager.h"
#include "../Scene2/WikedCityLoader.h"
#include "../Scene2/WickedFireLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene2Layer::Scene2Layer():mAnimationManager(NULL),wikedCity(NULL)
{
    //CCLog("Scene 2 opened");
}
Scene2Layer::~Scene2Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
     //CCLog("Scene 2 closed");
}
void Scene2Layer::onEnter()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene2.plist");
    SoundManager::sharedSoundManager()->startBackgroundSound();
    this->addWickedCity();
    this->wikedCity->EnableInteractions();
    CCLayer::onEnter();
}
void Scene2Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void Scene2Layer::addWickedCity()
{
    CCNode *node=NULL;
    std::map<std::string, CCNodeLoader*> loader_map;
    loader_map.insert(std::make_pair("WikedCity", WikedCityLoader::loader()));
    loader_map.insert(make_pair("WickedFire", WickedFireLoader::loader()));
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
            CCLog("Wicked City Case 1");
            node =  loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity.ccbi",loader_map);
        }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                CCLog("Wicked City Case 2 iphone 5");
                node = loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone5.ccbi",loader_map);
            }
            else
            {
                CCLog("Wicked City Case 2  ipad normal");
                node=  loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity.ccbi",loader_map);
            }
        }
            break;
        case 3:
        {
            CCLog("Wicked City Case 3 iphone 4");
            CCLog("scale 3");
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                node = loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone5.ccbi",loader_map);
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                node= loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone.ccbi",loader_map);
        #endif
           
       }
            break;
        case 4:
        {
            CCLog("Wicked City Case 3 iphone 4");
            CCLog("scale 3");
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                    node = loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone.ccbi",loader_map);
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                    node= loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone.ccbi",loader_map);
        #endif
            
        }
            break;
        default:
            break;
    }
    if (node)
    {
        this->wikedCity=(WikedCity*)node;
        this->addChild(this->wikedCity,-1);
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                this->wikedCity->setPosition(ccp(1,1));
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                this->wikedCity->setPosition(ccp(1,1));
        #endif
    }
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene2Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene2Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
     CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene2Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene2Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene2Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene2Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Scene2Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene2Layer::onNarratorStart(CCNode* sender)
{
     //wikedCity->GetCityToNormal();
    SoundManager::sharedSoundManager()->startNarrator();
}