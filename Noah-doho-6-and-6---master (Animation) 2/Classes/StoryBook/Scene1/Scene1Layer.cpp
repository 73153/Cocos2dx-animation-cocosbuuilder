//
//  HelloCocosBuilderLayer.cpp
//  Demo
//
//  Created by Neil D on 20/05/13.
#include "Scene1Layer.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
#include "../../GameManager/common_function.h"
#include "../Scene2/WikedCityLoader.h"
#include "../Scene2/WickedFireLoader.h"
#define TimeForWikedCityToSetIn 6.6f
USING_NS_CC;
USING_NS_CC_EXT;
Scene1Layer::Scene1Layer():mAnimationManager(NULL),cloudContainer(NULL)
{
   //CCLog("constructor called");       
}
Scene1Layer::~Scene1Layer()
{
   //CCLog("destracture called");
}
void  Scene1Layer::onExit()
{
    CCLayer::onExit();
}
void Scene1Layer::onExitTransitionDidStart()
{
    this->removeChild(wikedCity,true);
    cloudContainer->EndAll();
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
}
void Scene1Layer::onEnter()
{
    this->setTouchEnabled(true);
    SoundManager::sharedSoundManager()->startBackgroundSound();
    //initial settings...
    this->init_settings();
    this->addWickedCity();
    CCLayer::onEnter();
    //reorder background
    //node1 is background
    CCNode *node1=this->getChildByTag(11);
    //node2 is cloud container
    CCNode *node2=this->getChildByTag(22);
    this->reorderChild(node1, -1);
    this->reorderChild(node2, 0);
    this->schedule(schedule_selector(Scene1Layer::StartWikedCity),10.8f);
    this->schedule(schedule_selector(Scene1Layer::EndRotatingClouds),8.0f);
}
void Scene1Layer::init_settings()
{
     CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("LightningClouds.plist");
    screenSize=CCDirector::sharedDirector()->getWinSize();
}
void Scene1Layer::addWickedCity()
{
    CCNode *node=NULL;
    std::map<std::string, CCNodeLoader*> loader_map;
    loader_map.insert(std::make_pair("WikedCity", WikedCityLoader::loader()));
    loader_map.insert(make_pair("WickedFire", WickedFireLoader::loader()));
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            node =  loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity.ccbi",loader_map);
            break;
        case 2:
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                node = loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone5.ccbi",loader_map);
            }
            else
            {
                node=  loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity.ccbi",loader_map);
            }
            break;
        case 3:
        {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                    node = loadCCBFile("StoryCCBFiles/Scene2Layer_WikedCity_iphone5.ccbi",loader_map);
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
        this->addChild(this->wikedCity,-2);
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        this->wikedCity->setPosition(ccp(1,1));
    #endif

        
    }
}
#pragma mark -
#pragma mark ccb methods
void Scene1Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene1Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
   CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene1Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene1Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene1Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
bool Scene1Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cloudContainer", CloudContainer *, this->cloudContainer);
     return false;
}
bool Scene1Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene1Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
    cloudContainer->setambient(SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/ambient.mp3", true));
}
void Scene1Layer::StartWikedCity(float  dt)
{
    this->unscheduleAllSelectors();
    wikedCity->StartZoomOnCity();
    CCNode *node=this->getChildByTag(11);
    node->runAction(CCSequence::create(CCFadeOut::create(TimeForWikedCityToSetIn),CCCallFunc::create(this,callfunc_selector(Scene1Layer::EnableInteractions)),CCCallFunc::create(wikedCity,callfunc_selector(WikedCity::EnableInteractions)),NULL));
}
void Scene1Layer::EndRotatingClouds(float dt)
{
    this->unschedule(schedule_selector(Scene1Layer::EndRotatingClouds));
    cloudContainer->unscheduleAllSelectors();
    cloudContainer->stopAllActions();
    cloudContainer->EndZoomIn();
}
void Scene1Layer::EnableInteractions()
{
    cloudContainer->unscheduleAllSelectors();
    cloudContainer->stopAllActions();
     this->removeChild(cloudContainer,true);
}