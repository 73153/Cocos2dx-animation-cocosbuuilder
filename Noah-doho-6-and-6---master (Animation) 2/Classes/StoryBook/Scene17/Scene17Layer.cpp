//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene17Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene17Layer::Scene17Layer():mAnimationManager(NULL),ark(NULL),dust1(NULL),dust2(NULL),mountainOverlay(NULL),palmtreeOverlay(NULL),pow(NULL),orangutan(NULL),boa(NULL),hifive(NULL)
{
    isPlaying=false;
    isEnabled=false;
    shouldJump = false;
    boaTouched = false;
    oraguntanTouched =false;
    narrator2=0;
      //CCLog("Scene 17 opened");
}
Scene17Layer::~Scene17Layer()
{
     //CCLog("Scene 17 closed");
}
void Scene17Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
     
    CCLayer::onExit();
}
void Scene17Layer::onEnter()
{
    this->setTouchEnabled(true);
    winsize=CCDirector::sharedDirector()->getWinSize();
    if (winsize.width==1136.0f)
    {
        CCNode *bg=this->getChildByTag(11);
        bg->setPosition(ccpAdd(bg->getPosition(),ccp(49,0)));
        //ark->setPosition(CCPointMake(423,315));
        mountainOverlay->setPosition(ccpAdd(mountainOverlay->getPosition(), ccp(40,-40)));
        palmtreeOverlay->setPosition(ccpAdd(palmtreeOverlay->getPosition(), ccp(22,-20)));
    }
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        CCNode *bg=this->getChildByTag(11);
        bg->setPosition(ccpAdd(bg->getPosition(),ccp(0,0)));
        //ark->setPosition(CCPointMake(423,315));
        mountainOverlay->setPosition(ccpAdd(mountainOverlay->getPosition(), ccp(40,-40)));
        palmtreeOverlay->setPosition(ccpAdd(palmtreeOverlay->getPosition(), ccp(22,-20)));
       // CCNode *bg=this->getChildByTag(11);
        //bg->setPosition(ccpAdd(bg->getPosition(),ccp(49,0)));
        //ark->setPosition(CCPointMake(423,315));
      //  bg->setPosition(ccpAdd(bg->getPosition(),ccp(0,0)));
    //    mountainOverlay->setPosition(ccpAdd(mountainOverlay->getPosition(), ccp(40,-40)));
    //    palmtreeOverlay->setPosition(ccpAdd(palmtreeOverlay->getPosition(), ccp(22,-20)));
    #endif
    SoundManager::sharedSoundManager()->startBackgroundSound();
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene17Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
    platform = CCApplication::sharedApplication()->getTargetPlatform();

}
SEL_CallFuncN Scene17Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene17Layer::onNarratorStart);
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onAnimationCompleted", Scene17Layer::onAnimationCompleted);

    
    return NULL;
}
SEL_MenuHandler Scene17Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene17Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
      //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene17Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dust1", CCSprite *, this->dust1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dust2", CCSprite *, this->dust2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pow", CCSprite *, this->pow);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "boa", CCSprite *, this->boa);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "orangutan", CCSprite *, this->orangutan);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ark", CCSprite *, this->ark);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mountainOverlay", CCSprite *, this->mountainOverlay);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "palmtreeOverlay", CCSprite *, this->palmtreeOverlay);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "hifive", CCLayerColor *, this->hifive);
    return false;
}
bool Scene17Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene17Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
    isEnabled=false;
    this->schedule(schedule_selector(Scene17Layer::tick), 4.6f, 0, 0);
}
void Scene17Layer::tick(CCTime t)
{
    if (SoundManager::sharedSoundManager()->isNarratorPlaying())
    {
        CCLOG("playing first narrator");
        isEnabled=false;
    }
    else
    {
        isEnabled=true;
    }
    if (isEnabled==true)
    {
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {
            narrator2=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/narratorScene17_2.caf", false);
        }
        else
        {
        narrator2=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/narratorScene17_2.ogg", false);
        }
        isEnabled=false;
        isPlaying=false;
    }
    if (!SoundManager::sharedSoundManager()->isEffectPlaying(narrator2))
    {
           isPlaying=true;
    }
}
void Scene17Layer::onAnimationCompleted(CCNode* sender)
{
    isPlaying=false;
}
void Scene17Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (!SoundManager::sharedSoundManager()->isNarratorPlaying())
    {
        if (GameManager::sharedGameManager()->isNodeAtPoint(boa, location))
        {
            boaTouched = true;
            if (!shouldJump)
            {
                this->schedule(schedule_selector(Scene17Layer::ClearFreshTouch), 0.1f);
                shouldJump = true;
            }
        }
        if (GameManager::sharedGameManager()->isNodeAtPoint(orangutan, location))
        {
            oraguntanTouched = true;
            if (!shouldJump)
            {
                this->schedule(schedule_selector(Scene17Layer::ClearFreshTouch), 0.1f);
                shouldJump = true;
            }
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(hifive, location))
        {
            oraguntanTouched = true;
            boaTouched = true;
            if (!shouldJump)
            {
                this->schedule(schedule_selector(Scene17Layer::ClearFreshTouch), 0.1f);
                shouldJump = true;
            }
        }
       
    }

}
void Scene17Layer::ClearFreshTouch(float dt)
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        isPlaying = true;
        this->unschedule(schedule_selector(Scene17Layer::ClearFreshTouch));
        if (boaTouched && oraguntanTouched)
        {
          mAnimationManager->runAnimationsForSequenceNamed("jumping_animal");
        }
        else if (boaTouched) {
            mAnimationManager->runAnimationsForSequenceNamed("jumping_boa");
        }
        else if (oraguntanTouched) {
           mAnimationManager->runAnimationsForSequenceNamed("jumping_orangutan");
        }
        shouldJump = false;
        boaTouched = false;
        oraguntanTouched =false;
    }
}