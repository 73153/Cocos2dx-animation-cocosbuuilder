//
//  CloudContainer.cpp
//  Noah360
//
//  Created by Neil D on 24/09/13.
//
//
#include "WickedFire.h"
#define StartFireSize 0.1f
#define StartFireOpacity 51
#define InitFireTime 2.0f
#define ExtingFireTime 0.8f
#include "../../GameManager/GameManager.h"
WickedFire::WickedFire():fire(NULL),smoke(NULL),firefx(NULL)
{
    // Set to autorelease
    fireSoundStatus = 0;

}
WickedFire::~WickedFire()
{

}
void WickedFire::onExit()
{
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
}
void WickedFire::onEnter()
{
    fireSoundStatus=0;
    isExtinguished = false;
    this->schedule(schedule_selector(WickedFire::tick), 1/60.0f);
    fire->setOpacity(0);
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void WickedFire::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN WickedFire::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler WickedFire::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler WickedFire::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool WickedFire::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fire", CCSprite *, this->fire);
    return false;
}
bool WickedFire::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void WickedFire::tick(CCTime dt)
{
    switch (fireSoundStatus)
    {
        case 1:
            //            [continousFire stop];
            //            [extingFire stop];
            //            [startFire play];
            fireSoundStatus++;
            break;
        case 2:
            //            if (!startFire.isPlaying) {
            //                [continousFire play];
            //                fireSoundStatus = 6;
            //            }
            break;
        case 3:
            //            [continousFire stop];
            //            [extingFire play];
            fireSoundStatus++;
            break;
            
        default:
            break;
    }
}
void WickedFire::InitFire()
{
    fireSoundStatus = 1;
    firefx=CCParticleSystemQuad::create("fireFx.plist");
    smoke=CCParticleSystemQuad::create("smoke.plist");
    firefx->retain();
    smoke->retain();
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
            firefx->setScale(2);
            smoke->setScale(2);
            break;
        }
        case 2:
            firefx->setScale(1);
            smoke->setScale(1);
            break;
        case 3:
        {
            firefx->setScale(1);
            smoke->setScale(1);
            break;
        }
        default:
            break;
    }
    firefx->setSpeed(100);
    firefx->setPosVar(ccp(40,20));
    firefx->setStartSizeVar(50);
    firefx->setStartSize(30);
    firefx->setPosition(fire->getPosition());
    smoke->setPosition(fire->getPosition());
    this->addChild(smoke,2);
    this->addChild(firefx,3);
}
void WickedFire::RestartFire()
{
    fireSoundStatus = 1;
    smoke->setLife(1.2f);
    smoke->setLifeVar(1.2f);
    firefx->setSpeed(100);
    firefx->setStartSizeVar(50);
    firefx->setStartSize(30);
    firefx->setPosVar(ccp(40,10));
    isExtinguished = false;
}
void WickedFire::ExtingFire()
{
    fireSoundStatus = 3;
    smoke->setLife(0.3f);
    smoke->setLifeVar(0.2f);
    firefx->setSpeed(40);
    firefx->setStartSizeVar(10);
    firefx->setStartSize(4);
    firefx->setPosVar(ccp(5,5));
    isExtinguished = true;
}
void WickedFire::StopSounds()
{
    this->unscheduleAllSelectors();
}