//
//  FlyingDoveNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "FlyingDoveNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define TimeToReturnToZero 6.6f
#define TimeToIncreaseSpeed 0.6f
#define MoveToIncreaseSpeed 50.0f*(screen_height/768)
#define MinHigh 40*(screen_height/768)
#define MaxHigh 680*(screen_height/768)
FlyingDoveNode::FlyingDoveNode():mAnimationManager(NULL),doveIsFLying(false),hasTakeOff(false),doveLost(false),feet_YPos(0.0f)
{
  
}
FlyingDoveNode::~FlyingDoveNode()
{

}
void FlyingDoveNode::onEnter()
{
    CCNode::onEnter();
}
bool FlyingDoveNode::init()
{
    if (CCNode::init())
    {
        screenSize =CCDirector::sharedDirector()->getWinSize();
		body =CCSprite::createWithSpriteFrameName("scene16DoveBody.png");
		wings =CCSprite::createWithSpriteFrameName("scene16DoveWing1.png");
		feet1 =CCSprite::createWithSpriteFrameName("DOVE_FOOT-1.png");
		feet2 =CCSprite::createWithSpriteFrameName("DOVE_FOOT-1.png");
        moveXNode =CCNode::create();
        moveYNode =CCNode::create();
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
              
                feet_YPos=-80.0f;
            }
            break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    
                    feet_YPos=-100.0f;
                }
                else
                {
                    feet_YPos=-80.0f;
                }
            }
            break;
            case 3:
            {
                feet_YPos=-95.0f;
            }
            break;
            case 4:
            {
                feet_YPos=-95.0f;
            }
                break;
            default:
                break;
        }
        body->setPosition(ccp(0,0));
        wings->setPosition(ccp(0,0));
        feet1->setPosition(ccp(-15*(screenSize.width/1024),feet_YPos*(screenSize.height/768)));
        feet2->setPosition(ccp(15*(screenSize.width/1024),feet_YPos*(screenSize.height/768)));
        feet2->setScaleX(-1);

       

        moveXNode->setPosition( ccp(screen_width/2,0));
        moveYNode->setPosition(ccp(0, (12*screen_height/100) + wings->getContentSize().height/2));
       // moveYNode->setPosition(ccp(0, screen_height-(440*(screen_height/1024)) - wings->getContentSize().height/2));
        // screenSize.height - 440 - wings.contentSize.height/2
        moveXNode->addChild(feet1,1);
        moveXNode->addChild(feet2 ,1);
        moveXNode->addChild(body ,10);
        moveXNode->addChild(wings ,20);
        moveYNode->addChild(moveXNode);
        this->addChild(moveYNode,20);
        return true;
    }
    return false;
}
void FlyingDoveNode::MoveToStartPosition()
{
    CCSize screenSize =CCDirector::sharedDirector()->getWinSize();
    moveXNode->stopAllActions();
    moveYNode->stopAllActions();

    moveXNode->runAction(CCMoveTo::create(1.6, ccp(screenSize.width/2,0)));
     moveYNode->setPosition(ccp(0, (12*screen_height/100) + wings->getContentSize().height/2));
    moveYNode->runAction(CCMoveTo::create(1.6,ccp(0, (12*screen_height/100) + wings->getContentSize().height/2)));
    body->runAction(CCRotateTo::create(1.6f, 0));
    wings->runAction(CCRotateTo::create(1.6f, 0));

    feet1->setOpacity(255);
    feet2->setOpacity(255);
    feet1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-1.png"));
    feet2->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-1.png"));

    feet1->runAction(CCMoveTo::create(0.4, ccp(-15*(screenSize.width/1024), feet_YPos*(screenSize.height/768))));
    feet2->runAction(CCMoveTo::create(0.4, ccp(15*(screenSize.width/1024),feet_YPos*(screenSize.height/768))));
    this->unscheduleAllSelectors();

}
void FlyingDoveNode::ResetDove()
{
    doveLost = false;
    doveIsFLying = false;
    hasTakeOff = false;
    numverOfWingsFlaps = 0;
}
void FlyingDoveNode::LostGame()
{
    doveLost = true;
}
void FlyingDoveNode::GetDoveDown()
{
    float timeToMove = TimeToReturnToZero *(moveYNode->getPositionY() - MinHigh)/(MaxHigh - MinHigh);
    moveYNode->runAction(CCSequence::create(CCMoveTo::create(timeToMove, ccp(0, MinHigh)),CCCallFunc::create(this, callfunc_selector(FlyingDoveNode::LostGame)),NULL));
    feet1->stopAllActions();
    feet2->stopAllActions();
}
void FlyingDoveNode::WasDoveTouch()
{
    if (doveLost)
    {
        return;
    }
    if (doveIsFLying)
    {
        moveYNode->stopAllActions();
        if ((this->getPositionY() + MoveToIncreaseSpeed) >=MaxHigh)
        {
            //Will lift off after this
            float timeToMove = TimeToIncreaseSpeed * (MaxHigh - this->getPositionY())/(MoveToIncreaseSpeed);
            moveYNode->runAction(CCSequence::create(CCMoveBy::create(timeToMove, ccp(0, MaxHigh-this->getPositionY())),CCCallFunc::create(this, callfunc_selector(FlyingDoveNode::GetDoveDown)),NULL));
        }
        else
        {
            moveYNode->runAction(CCSequence::create(CCMoveBy::create(TimeToIncreaseSpeed, ccp(0, MoveToIncreaseSpeed)),CCCallFunc::create(this, callfunc_selector(FlyingDoveNode::GetDoveDown)),NULL));
        }
    }
    else if(!hasTakeOff && feet1->numberOfRunningActions() == 0)
    {
        this->StartMoving();
    }
    CCAnimation* pAnimation = CCAnimation::create();
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing3.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing3.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->setRestoreOriginalFrame(true);
    pAnimation->setDelayPerUnit(0.6/10);
    CCAnimate *anim=CCAnimate::create(pAnimation);
    anim->setDuration(0.6f);
    wings->runAction(anim);
}
void FlyingDoveNode::FlapWingsLikeCraZy(float dt)
{
    numverOfWingsFlaps++;
    CCAnimation* pAnimation = CCAnimation::create();
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing3.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing3.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing2.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("scene16DoveWing1.png"));
    pAnimation->setDelayPerUnit(0.3/10);
    pAnimation->setRestoreOriginalFrame(true);
    CCAnimate *anim=CCAnimate::create(pAnimation);
    anim->setDuration(0.3f);
    wings->runAction(anim);
    if (numverOfWingsFlaps >= 3)
    {
        this->unschedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy));
        numverOfWingsFlaps = 0;
        this->schedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy),0.8f);
    }
    else
    {
        this->unschedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy));
        this->schedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy),0.3f);
    }
}
void FlyingDoveNode::suspendAllActions()
{
    this->unschedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy));
    feet1->stopAllActions();
    feet2->stopAllActions();
}
void FlyingDoveNode::LetItFLy()
{
    doveIsFLying = true;
    this->unschedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy));
    this->GetDoveDown();
}
void FlyingDoveNode::LiftOff()
{
    feet1->stopAllActions();
    feet2->stopAllActions();
    feet1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
    
    feet2->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
    
    feet1->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(-15*(screenSize.width/1024),-40*(screenSize.height/768) )),CCFadeOut::create(0.1f),NULL));
    feet2->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(15*(screenSize.width/1024),-40*(screenSize.height/768) )),CCFadeOut::create(0.1f),NULL));

    hasTakeOff = true;
    this->schedule(schedule_selector(FlyingDoveNode::FlapWingsLikeCraZy));
    moveYNode->runAction(CCSequence::create(CCEaseInOut::create(CCMoveTo::create(2.4f, ccp(0, 520*(screenSize.height/768))), 2.0),CCCallFunc::create(this, callfunc_selector(FlyingDoveNode::LetItFLy)),NULL));

}
void FlyingDoveNode::StopMoving()
{
    feet1->stopAllActions();
    feet2->stopAllActions();
    feet1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
    feet1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
}
void FlyingDoveNode::StartMoving()
{
    feet1->stopAllActions();
    feet2->stopAllActions();
    CCAnimation* pAnimation = CCAnimation::create();
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-1.png"));
    pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
    pAnimation->setRestoreOriginalFrame(true);
    pAnimation->setDelayPerUnit(0.3/2);
    CCAnimate* pAction = CCAnimate::create(pAnimation);
    pAction->setDuration(0.3f);
    feet1->runAction(CCRepeatForever::create(pAction));
    CCAnimation* animation = CCAnimation::create();
    animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-2.png"));
    animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DOVE_FOOT-1.png"));
    animation->setRestoreOriginalFrame(true);
    animation->setDelayPerUnit(0.3/2);
    CCAnimate* action = CCAnimate::create(animation);
    action->setDuration(0.3f);
    feet2->runAction(CCRepeatForever::create(action));
}
void FlyingDoveNode::Accelerate(float acc)
{
    if (doveLost)
    {
        return;
    }
    if (doveIsFLying)
    {
        //CCLOG("%f",acc);
        if (isnan(acc)||isinf(acc)||acc>1||acc<-1)
        {
            acc=0.0;
        }
        if ((moveXNode->getPositionX() < (17.5*screen_width/100) && acc > 0) || ( moveXNode->getPositionX() >=(85*screen_width/100) && acc < 0))
        {
            return;
        }
        body->setRotation(-acc*60);
        wings->setRotation(-acc*60);
        CCDirector* pDir = CCDirector::sharedDirector();
        CCPoint ptNow  = moveXNode->getPosition();
        CCPoint ptTemp = pDir->convertToUI(ptNow);
        if(GameManager::sharedGameManager()->get_devise_resolution()==2)
        {
            ptTemp.x = ptTemp.x - acc*15;
        }
        else
        {
            ptTemp.x = ptTemp.x - acc*25;
        }
        TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
        if(platform == kTargetAndroid)
        {
             ptTemp.x = ptTemp.x - acc*35;
        }
        
        CCPoint ptNext = pDir->convertToGL(ptTemp);
        moveXNode->setPosition(ptNext.x,ptNext.y);
    }
}