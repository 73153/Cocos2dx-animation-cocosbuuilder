//  NoahAndDove.cpp
//  Noah360
//  Created by Neil D on 03/10/13.
#include "NoahAndDove.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
NoahAndDove::NoahAndDove():mAnimationManager(NULL),head(NULL),body(NULL),leftHandStaff(NULL),leftForeHarm(NULL),leftLowerSleeve(NULL),leftUpperSleeve(NULL),rightSleeve(NULL),rightHand(NULL),dove(NULL)
{
  
}
NoahAndDove::~NoahAndDove()
{

}
bool NoahAndDove::init()
{
    if (CCNode::init())
    {
        screenSize=CCDirector::sharedDirector()->getWinSize();
        runningAnimation = false;
        interactionsEnabled =false;
        isPlaying=false;
        head = CCSprite::createWithSpriteFrameName("noahHead1.png");
        body = CCSprite::createWithSpriteFrameName("noahBody.png");
        leftUpperSleeve=CCSprite::createWithSpriteFrameName("leftUpperSleeve.png");
        leftLowerSleeve=CCSprite::createWithSpriteFrameName("leftLowerSleeve.png");
        leftForeHarm=CCSprite::createWithSpriteFrameName("leftForearm.png");
        leftHandStaff =CCSprite::createWithSpriteFrameName("leftHandAndStaff.png");
        rightHand=CCSprite::createWithSpriteFrameName("rightHand.png");
        rightSleeve=CCSprite::createWithSpriteFrameName("rightSleeve.png");
        dove=CCSprite::createWithSpriteFrameName("dove-rest.png");

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        this->setPosition(ccp(80, -95));
        head->setPosition(ccp(600*(screen_width/1024) + head->getContentSize().width/2,screenSize.height - 307*(screen_height/768) + 3*head->getContentSize().height/4));
        body->setPosition(ccp(555*(screen_width/1024) + body->getContentSize().width/2,screenSize.height - 644*(screen_height/768) + body->getContentSize().height/2));//C
        leftLowerSleeve->setPosition(ccp(723*(screen_width/1024) + leftLowerSleeve->getContentSize().width/2,screenSize.height - 490*(screen_height/768)  + leftLowerSleeve->getContentSize().height/2));//C
        leftUpperSleeve->setPosition(ccp(658*(screen_width/1024) + leftUpperSleeve->getContentSize().width/2,screenSize.height - 440*(screen_height/768)  + leftUpperSleeve->getContentSize().height/2));//C
        leftForeHarm->setPosition(ccp(750*(screen_width/1024) + leftForeHarm->getContentSize().width/2,screenSize.height - 436*(screen_height/768)  + leftForeHarm->getContentSize().height/2));//C
        leftHandStaff->setPosition( ccp(715*(screen_width/1024) + leftHandStaff->getContentSize().width/2,screenSize.height - 625*(screen_height/768) + leftHandStaff->getContentSize().height/2));//C
        rightHand->setPosition(ccp(478*(screen_width/1024) + rightHand->getContentSize().width/2,screenSize.height - 455*(screen_height/768)  + rightHand->getContentSize().height/2));//C
        rightSleeve->setPosition(ccp(537*(screen_width/1024) + rightSleeve->getContentSize().width/2,screenSize.height - 470*(screen_height/768)  + rightSleeve->getContentSize().height/2));
        dove->setPosition(ccp(685*(screen_width/1024) + dove->getContentSize().width/2,screenSize.height - 225*(screen_height/768)  + 3.1*dove->getContentSize().height/4));
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if (screenSize.height==640&&screenSize.width==960)
        {
            //CCLog("iphone 4");
            this->setPosition(ccp(0, 0));
            head->setPosition(ccp(596*(1024/960) + head->getContentSize().width/2,screenSize.height - 307 + head->getContentSize().height/2));
            body->setPosition(ccp(555*(1024/960) + body->getContentSize().width/2,screenSize.height - 614 + body->getContentSize().height/2));//C
            leftLowerSleeve->setPosition(ccp(723*(1024/960) + leftLowerSleeve->getContentSize().width/2,screenSize.height - 490 + leftLowerSleeve->getContentSize().height/2));//C
            leftUpperSleeve->setPosition(ccp(658*(1024/960) + leftUpperSleeve->getContentSize().width/2,screenSize.height - 440 + leftUpperSleeve->getContentSize().height/2));//C
            leftForeHarm->setPosition(ccp(750*(1024/960) + leftForeHarm->getContentSize().width/2,screenSize.height - 436 + leftForeHarm->getContentSize().height/2));//C
            leftHandStaff->setPosition( ccp(715*(1024/960) + leftHandStaff->getContentSize().width/2,screenSize.height - 625 + leftHandStaff->getContentSize().height/2));//C
            rightHand->setPosition(ccp(478*(1024/960) + rightHand->getContentSize().width/2,screenSize.height - 455 + rightHand->getContentSize().height/2));//C
            rightSleeve->setPosition(ccp(537*(1024/960) + rightSleeve->getContentSize().width/2,screenSize.height - 470 + rightSleeve->getContentSize().height/2));
                dove->setPosition(ccp(685*(1024/960) + dove->getContentSize().width/2,screenSize.height - 255 + dove->getContentSize().height/2));
        }
        else if (screen_height==640&&screen_width==1136)
        {
            //CCLog("iphone 5");
            this->setPosition(ccp(80, 0));
            head->setPosition(ccp(600*(1024/960) + head->getContentSize().width/2,screenSize.height - 307*(768/640) + head->getContentSize().height/2));
            body->setPosition(ccp(555*(1024/960) + body->getContentSize().width/2,screenSize.height - 644*(768/640) + body->getContentSize().height/2));//C
            leftLowerSleeve->setPosition(ccp(723*(1024/960) + leftLowerSleeve->getContentSize().width/2,screenSize.height - 490*(768/640) + leftLowerSleeve->getContentSize().height/2));//C
            leftUpperSleeve->setPosition(ccp(658*(1024/960) + leftUpperSleeve->getContentSize().width/2,screenSize.height - 440*(768/640) + leftUpperSleeve->getContentSize().height/2));//C
            leftForeHarm->setPosition(ccp(750*(1024/960) + leftForeHarm->getContentSize().width/2,screenSize.height - 436*(768/640) + leftForeHarm->getContentSize().height/2));//C
            leftHandStaff->setPosition( ccp(715*(1024/960) + leftHandStaff->getContentSize().width/2,screenSize.height - 625*(768/640) + leftHandStaff->getContentSize().height/2));//C
            rightHand->setPosition(ccp(478*(1024/960) + rightHand->getContentSize().width/2,screenSize.height - 455*(768/640) + rightHand->getContentSize().height/2));//C
            rightSleeve->setPosition(ccp(537*(1024/960) + rightSleeve->getContentSize().width/2,screenSize.height - 470*(768/640) + rightSleeve->getContentSize().height/2));
            dove->setPosition(ccp(685*(1024/960) + dove->getContentSize().width/2,screenSize.height - 225*(768/640) + dove->getContentSize().height/2));
        }
        else
        {
            //CCLog("ipad");
            this->setPosition(ccp(65*(screen_width/1024), 0));
            head->setPosition(ccp(596*(screenSize.width/1024) + head->getContentSize().width/2,screenSize.height - 307*(screenSize.height/768) + head->getContentSize().height/2));
            body->setPosition(ccp(555*(screenSize.width/1024) + body->getContentSize().width/2,screenSize.height - 614*(screenSize.height/768) + body->getContentSize().height/2));//C
            leftLowerSleeve->setPosition(ccp(723*(screenSize.width/1024) + leftLowerSleeve->getContentSize().width/2,screenSize.height - 490*(screenSize.height/768) + leftLowerSleeve->getContentSize().height/2));//C
            leftUpperSleeve->setPosition(ccp(658*(screenSize.width/1024) + leftUpperSleeve->getContentSize().width/2,screenSize.height - 440*(screenSize.height/768) + leftUpperSleeve->getContentSize().height/2));//C
            leftForeHarm->setPosition(ccp(750*(screenSize.width/1024) + leftForeHarm->getContentSize().width/2,screenSize.height - 436*(screenSize.height/768) + leftForeHarm->getContentSize().height/2));//C
            leftHandStaff->setPosition( ccp(715*(screenSize.width/1024) + leftHandStaff->getContentSize().width/2,screenSize.height - 625*(screenSize.height/768) + leftHandStaff->getContentSize().height/2));//C
            rightHand->setPosition(ccp(478*(screenSize.width/1024) + rightHand->getContentSize().width/2,screenSize.height - 455*(screenSize.height/768) + rightHand->getContentSize().height/2));//C
            rightSleeve->setPosition(ccp(537*(screenSize.width/1024) + rightSleeve->getContentSize().width/2,screenSize.height - 470*(screenSize.height/768) + rightSleeve->getContentSize().height/2));
            dove->setPosition(ccp(685*(screenSize.width/1024) + dove->getContentSize().width/2,screenSize.height - 255*(screenSize.height/768) + dove->getContentSize().height/2));
        }
   #endif
        this->addChild(head, 4);
        this->addChild(body, 2);
        this->addChild(leftUpperSleeve, 3);
        this->addChild(leftLowerSleeve, 4);
        this->addChild(leftForeHarm, 5);
        this->addChild(leftHandStaff, 6);
        this->addChild(rightHand, 0);
        this->addChild(rightSleeve, 1);
        this->addChild(dove, 7);
        //Getting relative Positions
        upperToLowerSleeve= ccpSub(leftLowerSleeve->getPosition(), leftUpperSleeve->getPosition());
        sleeveToForearm= ccpSub(leftForeHarm->getPosition(), leftLowerSleeve->getPosition());
        forearmToHand = ccpSub(leftHandStaff->getPosition(), leftForeHarm->getPosition());
        handToDove = ccpSub(dove->getPosition(), leftHandStaff->getPosition());
       // CCSpriteFrameCache *sprt=CCSpriteFrameCache::sharedSpriteFrameCache();
        
     


        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
       
        this->schedule(schedule_selector(NoahAndDove::tick), 1/30.0f);
        
        return true;
    }
    return false;
}
void NoahAndDove::onEnter()
{
    CCNode::onEnter();
    this->schedule(schedule_selector(NoahAndDove::tick));
}
void NoahAndDove::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void NoahAndDove::tick(float dt)
{
    if (!firstAnimation)
    {
        leftLowerSleeve->setPosition(ccpAdd(leftUpperSleeve->getPosition(),ccpRotateByAngle(upperToLowerSleeve, ccp(0,0), -leftUpperSleeve->getRotation()*M_PI/180)));
        leftForeHarm->setPosition(ccpAdd(leftLowerSleeve->getPosition(),ccpRotateByAngle(sleeveToForearm, ccp(0,0), -leftLowerSleeve->getRotation()*M_PI/180)));
    }
    leftHandStaff->setPosition(ccpAdd(leftForeHarm->getPosition(),ccpRotateByAngle(forearmToHand, ccp(0,0), -leftForeHarm->getRotation()*M_PI/180)));
    dove->setPosition(ccpAdd(leftHandStaff->getPosition(),ccpRotateByAngle(handToDove, ccp(0,0), -leftHandStaff->getRotation()*M_PI/180)));
}
void NoahAndDove::EnableInteractions()
{
    interactionsEnabled = true;
    runningAnimation = false;
    firstAnimation = false;
    head->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("noahHead1.png"));
}
void NoahAndDove::stopSwallingTouchs()
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}
void NoahAndDove::ChangeBackNoahFace()
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0, false);
}
void NoahAndDove::MakeFeathersAppear(float  dt)
{
    CCParticleSystemQuad* feathers= CCParticleSystemQuad::create("doveFeather.plist");
    feathers->retain();
    if (GameManager::sharedGameManager()->get_devise_resolution()==1)
    {
        feathers->setScale(2.0f);
    }
    feathers->setAutoRemoveOnFinish(true);
    feathers->setPosition(ccpAdd(dove->getPosition(),ccp(0,90)));
    this->addChild(feathers, 38);
    this->unschedule(schedule_selector(NoahAndDove::MakeFeathersAppear));
}
void NoahAndDove::RunRandomNoahAnimation()
{
    isPlaying = true;
    int noahAnimationType = rand()%1000+1;
    firstAnimation = true;
    if (noahAnimationType >= 500)
    {
        firstAnimation = true;
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/doveSkaw.mp3", false);
        this->schedule(schedule_selector(NoahAndDove::MakeFeathersAppear),0.2f);
        
        leftUpperSleeve->runAction(CCSequence::create(CCScaleTo::create(0.4, 0.8f, 0.2f),CCDelayTime::create(1.4f),CCScaleTo::create(0.4, 1.0f, 1.0f),NULL));
        
        leftLowerSleeve->runAction(CCSequence::create(CCEaseInOut::create(CCMoveBy::create(0.4f,ccp(-12*(screen_width/1024), 100*(screen_height/768))), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(12*(screen_width/1024), -100*(screen_height/768))), 2),NULL));
        leftForeHarm->runAction(CCSequence::create(CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(-12*(screen_width/1024), 112*(screen_height/768))), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(12*(screen_width/1024), -112*(screen_height/768))), 2),NULL));
        
        rightSleeve->runAction(CCSequence::create(CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f,ccp(0, 34*(screen_height/768))), 2),CCRotateBy::create(0.4, 8),NULL),CCDelayTime::create(1.4f),CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f,ccp(0, -34*(screen_height/768))), 2),CCRotateBy::create(0.4, -8),NULL),NULL));
        
        rightHand->runAction(CCSequence::create(CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.3f,ccp(-60*(screen_width/1024),60*(screen_height/768))), 2),CCRotateBy::create(0.4, 33),NULL),CCDelayTime::create(1.4f),CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.3f,ccp(60*(screen_width/1024),-60*(screen_height/768))), 2),CCRotateBy::create(0.4, -33),NULL),CCCallFunc::create(this, callfunc_selector(NoahAndDove::EnableInteractions)),NULL));
    }
    else
    {
        firstAnimation = false;
        leftUpperSleeve->runAction(CCSequence::create(CCEaseInOut::create(CCRotateBy::create(0.4f, -20.0f), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCRotateBy::create(0.4f, 20.0f), 2),NULL));

        leftLowerSleeve->runAction(CCSequence::create(CCEaseInOut::create(CCRotateBy::create(0.4f, 10.0f), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCRotateBy::create(0.4f, -10.0f), 2),NULL));

        leftForeHarm->runAction(CCSequence::create(CCEaseInOut::create(CCRotateBy::create(0.4f, 20.0f), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCRotateBy::create(0.4f, -20.0f), 2),NULL));

        leftHandStaff->runAction(CCSequence::create(CCEaseInOut::create(CCRotateBy::create(0.4f, 20.0f), 2),CCDelayTime::create(1.4f),CCEaseInOut::create(CCRotateBy::create(0.4f, -20.0f), 2),NULL));

        rightSleeve->runAction(CCSequence::create(CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(0, 12)), 2),CCEaseInOut::create(CCRotateBy::create(0.4f, 8), 2),NULL),CCDelayTime::create(1.4f),CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(0, -12)), 2),CCEaseInOut::create(CCRotateBy::create(0.4f, -8), 2),NULL),NULL));
        
        rightHand->runAction(CCSequence::create(CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(-32,20)), 2),CCEaseInOut::create(CCRotateBy::create(0.4f, 8), 2),NULL),CCDelayTime::create(1.4f),CCSpawn::create(CCEaseInOut::create(CCMoveBy::create(0.4f, ccp(32,-20)), 2),CCEaseInOut::create(CCRotateBy::create(0.4f, -8), 2),NULL),NULL));
    }
    
    noahAnimationType = rand()%3+1;
    switch (noahAnimationType)
    {
        case 1:
            head->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("noahHead2.png"));
            break;
        case 2:
            head->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("noahHead3.png"));
            break;
        case 3:
            head->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("noahHead4.png"));
            break;
        default:
            break;
    }
    noahAnimationType = rand()%4+1;
    while (lastSentence == noahAnimationType)
    {
        noahAnimationType = rand()%4+1;
        if (SoundManager::sharedSoundManager()->isEffectPlaying(noahSpeech))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(noahSpeech);
        }
    }
    switch (noahAnimationType)
    {
        case 1:
            noahSpeech=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/noahCantBelieve.mp3", false);
            break;
        case 2:
            noahSpeech=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/noahDontKnow.mp3", false);
            break;
        case 3:
            noahSpeech=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/noahDontUnderstand.mp3", false);
            break;
        case 4:
            noahSpeech=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/noahGoingToObey.mp3", false);
            break;
        default:
            break;
    }
    this->schedule(schedule_selector(NoahAndDove::WaitForSpeechToEnd));
    lastSentence = noahAnimationType;
}
void NoahAndDove::WaitForSpeechToEnd(float dt)
{
    if (!SoundManager::sharedSoundManager()->isEffectPlaying(noahSpeech))
    {
        this->unschedule(schedule_selector(NoahAndDove::WaitForSpeechToEnd));
        isPlaying = false;
        runningAnimation=false;
    }
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void NoahAndDove::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN NoahAndDove::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler NoahAndDove::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler NoahAndDove::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool NoahAndDove::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool NoahAndDove::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
bool NoahAndDove::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if (runningAnimation || isPlaying)
        return false;
    CCPoint touchPoint = touch ->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    if (GameManager::sharedGameManager()->isNodeAtPoint(head, touchPoint)||GameManager::sharedGameManager()->isNodeAtPoint(body, touchPoint))
    {
        runningAnimation = true;
        this->RunRandomNoahAnimation();
        return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(dove, touchPoint))
    {
        runningAnimation = true;
        int doveAnimationType = rand()%2+1;
        if (doveAnimationType == 1)
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/doveFlap.mp3",false);
            CCAnimation* animation = CCAnimation::create();
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake5.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake5.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake4.png"));
             animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-headShake1.png"));
            animation->setDelayPerUnit(1.0f/12);
            animation->setRestoreOriginalFrame(true);
            CCAnimate* action = CCAnimate::create(animation);
            dove->runAction(CCSequence::create(action,CCCallFunc::create(this, callfunc_selector(NoahAndDove::EnableInteractions)),NULL));
            
            
        }
        else
        {
             SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/doveSkaw.mp3",false);
            CCAnimation* animation = CCAnimation::create();
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("dove-flaping4.png"));
            animation->setDelayPerUnit(1.0f/12);
            animation->setRestoreOriginalFrame(true);
            CCAnimate* action = CCAnimate::create(animation);
            dove->runAction(CCSequence::create(action,CCCallFunc::create(this, callfunc_selector(NoahAndDove::EnableInteractions)),NULL));
       }
        return true;
    }
    return false;
}
void NoahAndDove::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

}