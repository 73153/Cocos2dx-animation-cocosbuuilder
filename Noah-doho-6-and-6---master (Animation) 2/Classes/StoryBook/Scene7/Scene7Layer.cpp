//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene7Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene7Layer::Scene7Layer():mAnimationManager(NULL),dreamFloadcity_(NULL),dreamFloadWater_(NULL),background(NULL)
{
    isAnimationRunning=false;
    toggle=false;
}
Scene7Layer::~Scene7Layer()
{
   
   
}
bool Scene7Layer::init()
{
    if (CCLayer::init())
    {
        return true;
    }
    return false;
}
void Scene7Layer::onExit()
{
    SoundManager::sharedSoundManager()->stopNarrator();
     
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
     
    CCLayer::onExit();
}
void Scene7Layer::onEnter()
{
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCLog("Test Check");
    //CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene7images.plist");
    screenSize=CCDirector::sharedDirector()->getWinSize();
    this->setTouchEnabled(true);
    whiteOverlay = CCSprite::create("whiteBackground.png");
    this->addChild(whiteOverlay,3);
    whiteOverlay->setPosition(ccp(screenSize.width/2, screenSize.height-whiteOverlay->getContentSize().height/2));
    whiteOverlay->setOpacity(255);
    whiteOverlay->runAction(CCSequence::create(CCDelayTime::create(1.0),CCFadeOut::create(0.2f),NULL));
    CCLayer::onEnter();
    SoundManager::sharedSoundManager()->startBackgroundSound();
       toggle=true;

}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene7Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
    
}
SEL_CallFuncN Scene7Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene7Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene7Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene7Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene7Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dreamFloadcity_", DreamFloadCity *, this->dreamFloadcity_);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dreamFloadWater_", DreamFloadWater *, this->dreamFloadWater_);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "background", DreamFloadBack *, this->background);
    
 

    return false;
}
bool Scene7Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Touch delegate
#pragma mark -
void Scene7Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{

    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (GameManager::sharedGameManager()->isNodeAtPoint(dreamFloadWater_->getpalm1(), location)||GameManager::sharedGameManager()->isNodeAtPoint(dreamFloadWater_->getpalm2(), location))
    {


        //CCLog("touch the palm");
        GameManager::sharedGameManager()->AddPoints(10, location,this);
        #warning add star points from here
        //CCLog("Touched Palm");
        return;
    }
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        if (isAnimationRunning)
        {//restart Animation
            this->stopAllActions();
            dreamFloadcity_->stop_animation();
            dreamFloadWater_->ResetFload();
            background->ResetBackground();
            isAnimationRunning= false;
        }
        else
        {
            isAnimationRunning= true;
            this->runAction(CCSequence::create(CCCallFunc::create(dreamFloadWater_, callfunc_selector(DreamFloadWater::StartFload)),CCDelayTime::create(0.40f),CCCallFunc::create(dreamFloadcity_, callfunc_selector(DreamFloadCity::start_animation)),CCDelayTime::create(3.8f),CCCallFunc::create(background,callfunc_selector(DreamFloadBack::StartRotation)),NULL));
        }
        
        if (toggle)
        {
           
            
        }
        else
        {
            

        }
        toggle=!toggle;
    }
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene7Layer::onNarratorStart(CCNode* sender)
{
   SoundManager::sharedSoundManager()->startNarrator();
}
