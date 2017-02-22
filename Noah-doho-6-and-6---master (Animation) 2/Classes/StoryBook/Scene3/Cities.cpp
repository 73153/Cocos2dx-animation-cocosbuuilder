//
//  Cities.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "Cities.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define FireballFlyTime 1.0f
#define FireballCity2Scale 0.3f

Cities::Cities():mAnimationManager(NULL)
{

  
}
Cities::~Cities()
{

}

void Cities::onEnter()
{
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Cities::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Cities::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler Cities::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler Cities::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Cities::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Cities::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void Cities::stopSwallingTouchs()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

}
void Cities::FinishanimatingFireball()
{
    fireball->setOpacity(0);
    fireball->setPosition(CCPointZero);
    fireballIsAnimating = false;
    if (glowingForceField2->getOpacity()> 0)
    {
        glowingForceField2->runAction(CCFadeOut::create(0.1f));

        if (SoundManager::sharedSoundManager()->isEffectPlaying(electricHum))
        {
            forceField2->runAction(CCFadeIn::create(0.1f));
        }
    }
    if (glowingForceField1->getOpacity() > 0)
    {
        glowingForceField1->runAction(CCFadeOut::create(0.1f));
        if (SoundManager::sharedSoundManager()->isEffectPlaying(electricHum))
        {
            forceField1->runAction(CCFadeIn::create(0.1f));
        }
    }
}
void Cities::tick(float dt)
{
    if (fireballIsAnimating)
    {
        return;
    }
    if(ccpDistance(fireball->getPosition(), city1->getPosition()) <= 60 && forceField1->getOpacity()>=80)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);
        fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this,callfunc_selector(Cities::FinishanimatingFireball)),NULL));
        float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
        this->schedule(schedule_selector(Cities::LaunchFireball), nextLaunchTime);
        
#warning set pinch value
        SoundManager::sharedSoundManager()->playSoundEffect("Impact laser.mp3",false);
//        [[SimpleAudioEngine sharedEngine] playEffect:@"Impact laser.mp3" pitch:1 pan:1 gain:1];
        glowingForceField1->runAction(CCFadeIn::create(0.1f));
        forceField1->runAction(CCFadeOut::create(0.1f));
        forceFieldExplosion->setPosition(ccpAdd(fireball->getPosition(), ccp(20, 20)));
        forceFieldExplosion->setScale(1.0);
        forceFieldExplosion->runAction(CCSequence::create(CCFadeIn::create(0.1),CCDelayTime::create(0.4f),CCFadeOut::create(0.1f),NULL));
        return;
    }
    if(ccpDistance(fireball->getPosition(), city2->getPosition()) <= 20 && forceField2->getOpacity()>=80)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);
      fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this,callfunc_selector(Cities::FinishanimatingFireball)),NULL));
      float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
          SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/Impact laser.mp3",false);
        //[[SimpleAudioEngine sharedEngine] playEffect:@"Impact laser.mp3" pitch:1 pan:1 gain:0.4f];
        this->schedule(schedule_selector(Cities::LaunchFireball), nextLaunchTime);
        glowingForceField2->runAction(CCFadeIn::create(0.1f));
        forceField2->runAction(CCFadeOut::create(0.1f));
        forceFieldExplosion->setPosition(ccpAdd(fireball->getPosition(), ccp(-10, 10)));
        forceFieldExplosion->setScaleY(0.4f);
        forceFieldExplosion->setScaleX(-0.4f);
        forceFieldExplosion->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCDelayTime::create(0.1),CCFadeOut::create(0.1f),NULL));
        return;
    }
}
void Cities::ExplodeCity1()
{
    fireball->setOpacity(0);
    fireball->setPosition(CCPointZero);

    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/explosionNear.mp3",false);

    
    explodingCity1= CCAnimation::createWithSpriteFrames(explodingCity1Frames);

    float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
    this->schedule(schedule_selector(Cities::LaunchFireball), nextLaunchTime);

    CCAnimate *anim=CCAnimate::create(explodingCity1);
    anim->setDuration(0.6f);
    city1->runAction(anim);
}
void Cities::ExplodeCity2()
{
    fireball->setOpacity(0);
    fireball->setPosition(CCPointZero);
    city2->setOpacity(255);
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/explosionFar.mp3",false);
    explodingCity2 = CCAnimation::createWithSpriteFrames(explodingCity2Frames);
    float nextLaunchTime = (rand()%1000 + rand()%1000 + 4001)/1000.0f;
     this->schedule(schedule_selector(Cities::LaunchFireball), nextLaunchTime);
    CCAnimate *anim=CCAnimate::create(explodingCity2);
    anim->setDuration(0.6f);
    city2->runAction(CCSequence::create(anim,CCFadeOut::create(0.001f),NULL));
}
void Cities::LaunchFireball(float dt)
{
    this->unschedule(schedule_selector(Cities::LaunchFireball));
    
    int targetCity = rand()%2 + 1;
    
    //if forcefield is active, then only the other city can launch fireballs
    if (forceField1->getOpacity()>=180)
        targetCity=1;
        if (forceField2->getOpacity()>=180)
            targetCity=2;
            
            fireball->setOpacity(255);
            
            ccBezierConfig bezzier;
    switch (targetCity) {
        case 1:
            fireball->setScale(FireballCity2Scale);
            fireball->setRotation(-30);
            fireball->setPosition(city2->getPosition());
            
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballLaunchFar.caf", false);
           // [[SimpleAudioEngine sharedEngine] playEffect:@"fireballLaunchFar.caf"];
            
            bezzier.controlPoint_1 = ccp(city2->getPositionX(), city2->getPositionY());
            bezzier.controlPoint_2 = ccp((city2->getPositionX() + city1->getPositionX())/2, city2->getPositionY() + 160);
            bezzier.endPosition = ccp(city1->getPositionX(), city1->getPositionY());
            fireball->runAction(CCSequence::create(CCSpawn::create(CCBezierTo::create(FireballFlyTime, bezzier),CCScaleTo::create(FireballFlyTime, 1.0f),CCRotateBy::create(FireballFlyTime, -150),CCCallFunc::create(this, callfunc_selector(Cities::ExplodeCity1)),NULL),NULL));

          
            
            break;
        case 2:
            fireball->setScale(1.0f);
            fireball->setRotation(0);
            fireball->setPosition(city1->getPosition());

            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballLaunchNear.caf", false);
            
            bezzier.controlPoint_1 = ccp(city1->getPositionX(), city1->getPositionY());
            bezzier.controlPoint_2 = ccp((city2->getPositionX() + city1->getPositionX())/2, city2->getPositionY() + 160);
            bezzier.endPosition = ccp(city2->getPositionX(), city2->getPositionY());
            fireball->runAction(CCSequence::create(CCSpawn::create(CCBezierTo::create(FireballFlyTime, bezzier),CCScaleTo::create(FireballFlyTime, FireballCity2Scale),CCRotateBy::create(FireballFlyTime, 120),CCCallFunc::create(this, callfunc_selector(Cities::ExplodeCity2)),NULL),NULL));
           break;
        default:
            break;
    }
}
bool Cities::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCPoint touchPoint = touch->getLocationInView();
    touchPoint=CCDirector::sharedDirector()->convertToGL(touchPoint);
    if (GameManager::sharedGameManager()->isNodeAtPoint(city1,touchPoint))
    {
        forceField1->runAction(CCFadeIn::create(0.1f));
        //[electricHum setGain:1];
        // [electricHum play];
        return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(city2,touchPoint))
    {
        forceField2->runAction(CCFadeIn::create(0.1f));
        //[electricHum setGain:1];
        //[electricHum play];
        return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fireball,touchPoint) && !fireballIsAnimating)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);

        fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this, callfunc_selector(Cities::FinishanimatingFireball)),NULL));
        float nextLaunchTime = (rand()%1000 + rand()%1000 + 4001)/1000.0f;
        this->schedule(schedule_selector(Cities::LaunchFireball),nextLaunchTime);
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballExplosionMidair.mp3", false);
        //[[SimpleAudioEngine sharedEngine] playEffect:@"" pitch:1 pan:1 gain:1];
        //[delegate ShouldAddPoint:touchPoint];
        return true;
    }
    return false;
}
void Cities::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

}