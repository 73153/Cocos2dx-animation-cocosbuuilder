//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene10Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../StoryBook/Scene10/BoardingTheArkNodeLoader.h"
#include "../../GameManager/common_function.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene10Layer::Scene10Layer():mAnimationManager(NULL)
{
    //CCLog("Scene 10 opened");
}
Scene10Layer::~Scene10Layer()
{
     SoundManager::sharedSoundManager()->stopNarrator();
     //CCLog("Scene 10 closed");
}
void Scene10Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
   CCLayer::onExit();
}
void Scene10Layer::onEnter()
{
    this->setTouchEnabled(true);
        SoundManager::sharedSoundManager()->startBackgroundSound();
    this->addBoardingNode();
  
    CCLayer::onEnter();
}
void Scene10Layer::addBoardingNode()
{
    CCNode *boardingArkNode = NULL;
    std::map<std::string, CCNodeLoader*> loader_map;
    loader_map.insert(std::make_pair("BoardingTheArkNode", BoardingTheArkNodeLoader::loader()));
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
            CCLog("scale 2 ipad retina");
            boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNode_ipad.ccbi",loader_map);
        }
         break;
        case 2:
        if (CCDirector::sharedDirector()->getWinSize().width==1136)
        {
                CCLog("scale 2 iphone5");
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNode.ccbi",loader_map);
        }
        else
        {
                CCLog("scale 2 ipad");
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNode_ipad.ccbi",loader_map);
        }
        break;
        case 3:
        {
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            if (screen_width<960&&screen_height<640)
            {
                CCLog("scale 3");
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNodeandroid.ccbi",loader_map);
            }
            else if (screen_width>960&&screen_height<=640)
            {
                 boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNode.ccbi",loader_map);
            }
            else
            {
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNodeiphone4.ccbi",loader_map);
            }
            #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNodeiphone4.ccbi",loader_map);
            #endif
        }
        break;
        case 4:
        {
                boardingArkNode = loadCCBFile("sub_ccb_scene10/BoardingTheArkNodeiphone4.ccbi",loader_map);
        }
        break;
        default:
            break;
    }
    if (boardingArkNode)
    {
        CCObject *obj=NULL;
        CCARRAY_FOREACH(this->getChildren(),obj)
        {
            CCNode *objnode=(CCNode*)obj;
            if (objnode->getTag()==11)
            {
                this->reorderChild(objnode, -2);
            }
        }
        this->addChild(boardingArkNode,-1);
        boardingArkNode->setPosition(ccp(1,1));
        if (CCDirector::sharedDirector()->getWinSize().width==1136)
        {
            boardingArkNode->setPosition(ccpAdd(boardingArkNode->getPosition(), ccp(0,95)));
        }
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        if (screen_width<960&&screen_height<640)
        {
          // boardingArkNode->setPosition(ccpAdd(boardingArkNode->getPosition(), ccp(0,95)));
        }
        else if (screen_width>960&&screen_height<=640)
        {
           boardingArkNode->setPosition(ccpAdd(boardingArkNode->getPosition(), ccp(0,95)));
        }
        else
        {
           
        }
         boardingArkNode->setPosition(ccp(0,1));
        #endif
    }
    //footer
    if (CCDirector::sharedDirector()->getWinSize().width!=1136)
    {
        CCNode *node=this->getChildByTag(555);
        node->setPosition(ccpAdd(node->getPosition(), ccp(0,25)));
    }
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene10Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene10Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene10Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
     CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene10Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene10Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene10Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene10Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Scene10Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}