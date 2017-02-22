//
//  SquatingNoah.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.

#include "SquatingNoah.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define distanceFlower 10
SquatingNoah::SquatingNoah():mAnimationManager(NULL),is_anim_completed(false),ispause(false)
{
    
}
SquatingNoah::~SquatingNoah()
{

}
void SquatingNoah::onEnter()
{
    CCNode::onEnter();
}
bool SquatingNoah::init()
{
    if (CCNode::init())
    {
        is_anim_completed=false;
        //this->schedule(schedule_selector(SquatingNoah::noah_pauses), 1);
        return true;
        
    }
    return false;
}
void SquatingNoah::noah_pauses()
{
//    CCLOG("pauses");
//    ispause=!ispause;
//    if (ispause)
//        CCDirector::sharedDirector()->getActionManager()->pauseTarget(this);
//    else
//        CCDirector::sharedDirector()->getActionManager()->resumeTarget(this);
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void SquatingNoah::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN SquatingNoah::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "OnAnimationCompletion", SquatingNoah::OnAnimationCompletion);
    return NULL;
}
SEL_MenuHandler SquatingNoah::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler SquatingNoah::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool SquatingNoah::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool SquatingNoah::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void SquatingNoah::OnAnimationCompletion()
{
    this->is_anim_completed=true;
}