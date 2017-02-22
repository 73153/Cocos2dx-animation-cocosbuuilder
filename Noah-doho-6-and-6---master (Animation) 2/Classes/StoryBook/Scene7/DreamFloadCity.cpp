//
//  DreamFloadCity.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "DreamFloadCity.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
DreamFloadCity::DreamFloadCity():mAnimationManager(NULL)
{
    //CCLog("Header Layer called");
   
}
DreamFloadCity::~DreamFloadCity()
{
     // CC_SAFE_RELEASE(mAnimationManager);
     //CCLog("Header Layer removed");
}
void DreamFloadCity::onExit()
{
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
}
void DreamFloadCity::onEnter()
{
   CCNode::onEnter();
}

#pragma mark -
#pragma mark ccb functions
#pragma mark -
void DreamFloadCity::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN DreamFloadCity::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler DreamFloadCity::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler DreamFloadCity::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool DreamFloadCity::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool DreamFloadCity::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void DreamFloadCity::start_animation()
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("animate_city");
    }
}
void DreamFloadCity::stop_animation()
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("reset_city");
    }
}

