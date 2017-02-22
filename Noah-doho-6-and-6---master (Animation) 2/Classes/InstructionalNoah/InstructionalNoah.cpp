//
//  InstructionalNoah.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.

#include "InstructionalNoah.h"
#include "../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width
#define InstructionalNoahXOffset 200
#define InstructionalNoahYOffset 27*(WINHEIGHT/768)
#define InstructionalNoahYOffset2 87*(WINHEIGHT/768)
#define GoglesXOffset 28*(WINWIDTH/1024)
InstructionalNoah::InstructionalNoah():withSound(false)
{
    
}
InstructionalNoah::~InstructionalNoah()
{

}
void InstructionalNoah::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    CCNode::onExit();
}
void InstructionalNoah::onEnter()
{
    doNotAutomaticallyDisappear=false;
    CCNode::onEnter();
}
bool InstructionalNoah::init()
{
    if (CCNode::init())
    {
        screenSize = CCDirector::sharedDirector()->getWinSize();
        bacground=CCSprite::create("whiteBackground.png");
        bacground->setScale(3);
        blackStripe =CCSprite::create("blackBar.png");
        head=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahHead2.png");
        body=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahBody.png");
        eyeLids=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahHalfBlink.png");
        leftHand=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahLeftOpenHand.png");
        rightHand=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahRightOpenHand.png");
        leftSleeve=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahLeftSleeve.png");
        leftArm=CCSprite::createWithSpriteFrameName("Scene3_city_b/instrNoahLeftArm.png");
        goggles=CCSprite::createWithSpriteFrameName("Scene3_city_b/instructionalNoahGoggles.png");
        bacground->setPosition(ccp(screenSize.width/2, screenSize.height/2));
        blackStripe->setPosition(ccp(0, blackStripe->getContentSize().height/2));
        body->setPosition(ccp(0,-body->getContentSize().height/2));
        head->setPosition(ccp(0,-head->getContentSize().height/2));
        eyeLids->setPosition(ccp(0,eyeLids->getContentSize().height/2 - InstructionalNoahYOffset));
        leftHand->setPosition(ccp(0,-leftHand->getContentSize().height/2));
        rightHand->setPosition(ccp(0,-rightHand->getContentSize().height/2));
        leftSleeve->setPosition(ccp(0,-leftSleeve->getContentSize().height/2));
        leftArm->setPosition(ccp(0, leftArm->getContentSize().height/2-InstructionalNoahYOffset));
        goggles->setPosition(ccp(-GoglesXOffset,body->getPositionY()+body->getContentSize().height/2-goggles->getContentSize().height/2));
        //body->setAnchorPoint(ccp(0.5,0.5));

    #warning iphone
//        head->setAnchorPoint(ccp(0.5,0.5));
//        head->setAnchorPoint(this->getAnchorPoint());
//        eyeLids->setAnchorPoint(ccp(0.55,0.5));
//        leftHand->setAnchorPoint(ccp(-0.85,0.3));
//        rightHand->setAnchorPoint(ccp(1.9,0.3));
//        leftSleeve->setAnchorPoint(ccp(-0.86,-0.14));
//        leftArm->setAnchorPoint(ccp(0.05,0.33));
        //goggles->setAnchorPoint(ccp(0.2,0.4));

        leftArm->setOpacity(0);
        eyeLids->setOpacity(0);
        bacground->setOpacity(0);
        goggles->setOpacity(0);
//        eyeLids->setVisible(false);
//        head->setVisible(false);
        this->addChild(bacground,0);
        this->addChild(body,2);
        this->addChild(goggles,6);
        this->addChild(leftHand,4);
        this->addChild(rightHand,4);
        this->addChild(leftSleeve,4);
        this->addChild(leftArm,10);
        this->addChild(blackStripe,9);
        this->addChild(head,15);
        this->addChild(eyeLids,16);
        eyeLidsFrames=CCArray::create();
        eyeLidsFrames->retain();
        CCSpriteFrameCache *frame=CCSpriteFrameCache::sharedSpriteFrameCache();
        eyeLidsFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHalfBlink.png"));
        eyeLidsFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahFullBlink.png"));
        eyeLidsFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHalfBlink.png"));
        headFrames=CCArray::create();
        headFrames->retain();
        headFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHead3.png"));
        headFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHead2.png"));
        headFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHead4.png"));
        headFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHead3.png"));
        headFrames->addObject(frame->spriteFrameByName("Scene3_city_b/instrNoahHead2.png"));
        withSound = true;
        return true;
    }
    return false;
}
void InstructionalNoah::HideEyeLids()
{
    if (eyeLids->getOpacity() != 0)
    {
        eyeLids->setOpacity(0);
        float timeToBlink = (rand()%7500 + 500)/2000.0f;
        this->schedule(schedule_selector(InstructionalNoah::BlinkEyeis), timeToBlink);
    }
}
void InstructionalNoah:: BlinkEyeis(float dt)
{
    this->unschedule(schedule_selector(InstructionalNoah::BlinkEyeis));
    eyeLids->setOpacity(255);
    cocos2d::CCAnimation *pAnimation=CCAnimation::createWithSpriteFrames(eyeLidsFrames);
    pAnimation->setRestoreOriginalFrame(true);
    CCAnimate *animate=CCAnimate::create(pAnimation);
    animate->setDuration(0.10f);
    eyeLids->runAction(CCSequence::create(animate,CCCallFunc::create(this, callfunc_selector(InstructionalNoah::HideEyeLids)),NULL));
}
void InstructionalNoah:: WaitForSpeechToEnd(float dt)
{
    if (!SoundManager::sharedSoundManager()->isInstractunalNoahplaying())
    {
        head->stopAllActions();
        head->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahHead1.png"));
        this->unschedule(schedule_selector(InstructionalNoah::WaitForSpeechToEnd));
        if (!doNotAutomaticallyDisappear)
            this->MakeNoahDisappear();
        isPlaying = false;
    }
}
void InstructionalNoah::WaitTimeToDisapear(float dt)
{
    this->unschedule(schedule_selector(InstructionalNoah::WaitTimeToDisapear));
    this->MakeNoahDisappear();
}
void InstructionalNoah:: ReplaceSleeves()
{
    leftSleeve->setOpacity(0);
    leftHand->setOpacity(0);
    leftArm->setOpacity(255);
    eyeLids->setPosition(ccp(0,eyeLids->getContentSize().height/2-InstructionalNoahYOffset));
    float timeToBlink = (rand()%2000 + 2000)/2000.0f;
    this->schedule(schedule_selector(InstructionalNoah::BlinkEyeis),timeToBlink);
    cocos2d::CCAnimation *pAnimation=CCAnimation::createWithSpriteFrames(headFrames);
    pAnimation->setRestoreOriginalFrame(true);
    pAnimation->setDelayPerUnit(1.0f/headFrames->count());
    CCAnimate *animate=CCAnimate::create(pAnimation);
    animate->setDuration(1.0f);
    head->runAction(CCRepeatForever::create(animate));
    if (withSound)
    {
        if (SoundManager::sharedSoundManager()->getarr_instractunalNoah()->count()==0) return; // no speechs to sound
        int speechToPlay = rand()%SoundManager::sharedSoundManager()->getarr_instractunalNoah()->count();
        CCString *str=(CCString*)SoundManager::sharedSoundManager()->getarr_instractunalNoah()->objectAtIndex(speechToPlay);
        SoundManager::sharedSoundManager()->startInstractunalNoah(CCString::createWithFormat("%s",str->getCString()));
        this->schedule(schedule_selector(InstructionalNoah::WaitForSpeechToEnd));
    }
    else
    {
     this->schedule(schedule_selector(InstructionalNoah::WaitForSpeechToEnd),timePresent);
    }
}
void InstructionalNoah:: DontReplaceSleeves()
{
     //leftSleeve->setOpacity(255);
    eyeLids->setPosition(ccp(0,eyeLids->getContentSize().height/2-InstructionalNoahYOffset2));
    float timeToBlink = (rand()%2000 + 2000)/2000.0f;
    this->schedule(schedule_selector(InstructionalNoah::BlinkEyeis),timeToBlink);
    CCAnimation *panimation=CCAnimation::createWithSpriteFrames(headFrames);
    panimation->setRestoreOriginalFrame(true);
    panimation->setDelayPerUnit(1.0f/headFrames->count());
    CCAnimate *aniamte=CCAnimate::create(panimation);
    aniamte->setDuration(1.0f);
    head->runAction(CCRepeatForever::create(aniamte));
    if (withSound)
    {
        if (SoundManager::sharedSoundManager()->getarr_instractunalNoah()->count()==0) return;
        int speechToPlay = rand()%SoundManager::sharedSoundManager()->getarr_instractunalNoah()->count();
        CCString *str=(CCString*)SoundManager::sharedSoundManager()->getarr_instractunalNoah()->objectAtIndex(speechToPlay);
        SoundManager::sharedSoundManager()->startInstractunalNoah(CCString::createWithFormat("%s",str->getCString()));
        this->schedule(schedule_selector(InstructionalNoah::WaitForSpeechToEnd));
    }
    else
    {
        this->schedule(schedule_selector(InstructionalNoah::WaitForSpeechToEnd),timePresent);
    }
}
void InstructionalNoah:: PullUpBody()
{
    this->reorderChild(rightHand, 6);
    this->reorderChild(leftHand, 6);
    rightHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahRightClosedHand.png"));
    leftHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahLeftClosedHand.png"));
    rightHand->stopAllActions();
    leftHand->stopAllActions();
    leftHand->setPosition(ccp(0,leftHand->getContentSize().height/2-InstructionalNoahYOffset));
    rightHand->setPosition(ccp(0,rightHand->getContentSize().height/2 - InstructionalNoahYOffset));
    if (randoomAnimation)
    {
        CCLog("with sleeves");
        leftSleeve->setOpacity(0);
        leftSleeve->runAction(CCMoveTo::create(0.3f,ccp(0, leftSleeve->getContentSize().height/2-InstructionalNoahYOffset)));
        goggles->runAction(
                           CCSequence::create(
                                              CCMoveTo::create(0.3f, ccp(-GoglesXOffset,body->getContentSize().height/2-InstructionalNoahYOffset/2+body->getContentSize().height/2-goggles->getContentSize().height/2)),NULL));
        body->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(0, body->getContentSize().height/2-InstructionalNoahYOffset)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::ReplaceSleeves)),NULL));
        head->runAction(CCMoveTo::create(0.3f,ccp(0,body->getContentSize().height/2-InstructionalNoahYOffset)));
    }
    else
    {
        CCLog("no sleeves");
       goggles->runAction(CCSequence::create(CCMoveTo::create(0.225, ccp(-GoglesXOffset, body->getContentSize().height/2-InstructionalNoahYOffset2+body->getContentSize().height/2-goggles->getContentSize().height/2)),NULL));
       body->runAction(CCSequence::create(CCMoveTo::create(0.225f,ccp(0,body->getContentSize().height/2-InstructionalNoahYOffset2)),CCCallFunc::create(this,callfunc_selector(InstructionalNoah::DontReplaceSleeves)),NULL));
      head->runAction(CCMoveTo::create(0.225,ccp(0, body->getContentSize().height/2- InstructionalNoahYOffset2)));
    }
}
void InstructionalNoah:: LowerHands()
{
    rightHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahrightClosingHand.png"));
    leftHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahLeftClosingHand.png"));
    rightHand->runAction(CCSequence::create(CCMoveTo::create(0.075f, ccp(0, rightHand->getContentSize().width/2-60*(screenSize.height/768)-InstructionalNoahYOffset)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::PullUpBody)),NULL));
    leftHand->runAction(CCMoveTo::create(0.075f, ccp(0, leftHand->getContentSize().height/2-60*(screenSize.height/768)-InstructionalNoahYOffset)));
}
void InstructionalNoah:: MakeNoahAppearWithoutBackground()
{
    isPlaying = true;
    randoomAnimation = rand()%2;
    blackStripe->setOpacity(255);
    leftSleeve->setOpacity(0);
    rightHand->runAction(CCSequence::create(CCMoveTo::create(0.3f,ccp(0,rightHand->getContentSize().height/2-InstructionalNoahYOffset)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::LowerHands)),NULL));
    leftHand->runAction(CCSequence::create(CCMoveTo::create(0.3f,ccp(0,rightHand->getContentSize().height/2-InstructionalNoahYOffset)),NULL));
}
void InstructionalNoah:: MakeNoahAppear()
{
    isPlaying = true;
    randoomAnimation = rand()%2;
    blackStripe->setOpacity(255);
    leftSleeve->setOpacity(0);
    rightHand->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(0,rightHand->getContentSize().height/2-InstructionalNoahYOffset)),CCCallFunc::create(this,callfunc_selector(InstructionalNoah::LowerHands)),NULL));
    leftHand->runAction(CCMoveTo::create(0.3f, ccp(0,rightHand->getContentSize().height/2-InstructionalNoahYOffset)));
    bacground->runAction(CCFadeTo::create(0.3f, 180));
}
void InstructionalNoah:: MakeBarDisapear()
{
    blackStripe->setOpacity(0);
    bacground->runAction(CCFadeTo::create(0.3f, 0));
}
void InstructionalNoah:: PullDownHands()
{
   rightHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahRightOpenHand.png"));
   leftHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahLeftOpenHand.png"));
   rightHand->runAction(CCMoveTo::create(0.3f, ccp(0,-rightHand->getContentSize().height/2)));
   leftHand->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(0, -rightHand->getContentSize().height/2)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::MakeBarDisapear)),NULL));
}
void InstructionalNoah:: UpperHands()
{
    this->reorderChild(rightHand, 4);
    this->reorderChild(leftHand,4);
    rightHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahrightClosingHand.png"));
    leftHand->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene3_city_b/instrNoahLeftClosingHand.png"));
    rightHand->runAction(CCSequence::create(CCMoveTo::create(0.075, ccp(0, rightHand->getContentSize().height/2-InstructionalNoahYOffset)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::PullDownHands)),NULL));
    leftHand->runAction(CCMoveTo::create(0.075, ccp(0,rightHand->getContentSize().height/2- InstructionalNoahYOffset)));
}
void InstructionalNoah::MakeNoahDisappear()
{
    eyeLids->setOpacity(0);
    eyeLids->stopAllActions();
    this->unschedule(schedule_selector(InstructionalNoah::BlinkEyeis));
    randoomAnimation=true;
    if (randoomAnimation)
    {
        leftSleeve->setOpacity(0);
        leftHand->setOpacity(255);
        leftArm->setOpacity(0);
        leftSleeve->runAction(CCMoveTo::create(0.3f, ccp(0, -leftSleeve->getContentSize().height/2)));
        goggles->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(-GoglesXOffset, -body->getContentSize().height/2+body->getContentSize().height/2-goggles->getContentSize().height/2)),NULL));
        body->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(0, -body->getContentSize().height/2)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::UpperHands)),NULL));
        head->runAction(CCMoveTo::create(0.3f, ccp(0,-head->getContentSize().height/2)));
    }
    else
    {
        goggles->runAction(CCSequence::create(CCMoveTo::create(0.225f, ccp(-GoglesXOffset, -body->getContentSize().height/2+body->getContentSize().height/2-goggles->getContentSize().height/2)),NULL));
        body->runAction(CCSequence::create(CCMoveTo::create(0.255f, ccp(0,-body->getContentSize().height/2)),CCCallFunc::create(this, callfunc_selector(InstructionalNoah::UpperHands)),NULL));
        head->runAction(CCMoveTo::create(0.225f, ccp(0, -head->getContentSize().height/2)));
    }
}
void InstructionalNoah::WithGoggles()
{
    goggles->setOpacity(255);
}
void InstructionalNoah:: StopPlaying()
{
    if (isPlaying)
    {
        isPlaying = false;
        if (SoundManager::sharedSoundManager()->isInstractunalNoahplaying())
        {
            SoundManager::sharedSoundManager()->stopInstractunalNoah();
        }
    }
}