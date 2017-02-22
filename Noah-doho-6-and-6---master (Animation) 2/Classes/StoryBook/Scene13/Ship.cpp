//
//  Ship.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "Ship.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
Ship::Ship():open(false),anim(NULL)
{
    animalsOnBoard=CCArray::create();
    animalsOnBoard->retain();
}
Ship::~Ship()
{
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
}
bool Ship::init()
{
    if (CCNode::init())
    {
      	cask =CCSprite::createWithSpriteFrameName("arkBiggerDoors4.png");
		topHouse =CCSprite::createWithSpriteFrameName("arkTopHouse.png");
        size=CCDirector::sharedDirector()->getWinSize();
        commonNode =CCNode::create();
        commonNode->addChild(cask,20);
        commonNode->addChild(topHouse,5);
        this->addChild(commonNode);
        open = true;
        commonNode->setPosition(ccp(0, 0));
        cask->setPosition(ccp(0, 0));
        topHouse->setPosition(ccp(0, 0));
        this->setPosition(ccp(512*(size.width/1024), (768*(size.height/768))-(280*(size.height/768))));
        return true;
    }
    return false;
}
void Ship::onEnter()
{
    CCNode::onEnter();
}
void Ship::EndEverything()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    cask->stopAllActions();
}
void Ship::SetSmallAnimals(CCArray* smallAnimalArray)
{

    CCString *small_name=(CCString*)smallAnimalArray->objectAtIndex(0);
    CCString *str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal1 =CCSprite::createWithSpriteFrameName(str->getCString());
    
   
    small_name=(CCString*)smallAnimalArray->objectAtIndex(0);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
     CCSprite* smallAnimal2 =CCSprite::createWithSpriteFrameName(str->getCString());
    
    small_name=(CCString*)smallAnimalArray->objectAtIndex(1);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal3=CCSprite::createWithSpriteFrameName(str->getCString());

    small_name=(CCString*)smallAnimalArray->objectAtIndex(1);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal4 =CCSprite::createWithSpriteFrameName(str->getCString());

    small_name=(CCString*)smallAnimalArray->objectAtIndex(2);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal5 =CCSprite::createWithSpriteFrameName(str->getCString());

    small_name=(CCString*)smallAnimalArray->objectAtIndex(2);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal6 =CCSprite::createWithSpriteFrameName(str->getCString());

    small_name=(CCString*)smallAnimalArray->objectAtIndex(3);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal7 =CCSprite::createWithSpriteFrameName(str->getCString());

    small_name=(CCString*)smallAnimalArray->objectAtIndex(3);
    str=CCString::createWithFormat("small%s.png",small_name->getCString());
    CCSprite* smallAnimal8 =CCSprite::createWithSpriteFrameName(str->getCString());
        
    smallAnimal1->setScale(1/0.75);
    smallAnimal2->setScale(1/0.75);
    smallAnimal3->setScale(1/0.75);
    smallAnimal4->setScale(1/0.75);
    smallAnimal5->setScale(1/0.75);
    smallAnimal6->setScale(1/0.75);
    smallAnimal7->setScale(1/0.75);
    smallAnimal8->setScale(1/0.75);
    
    smallAnimal5->setPosition(ccp(-(cask->getContentSize().width/2 - (23*(size.width/1024))), cask->getContentSize().height/2 - (40*(size.height/768)) + smallAnimal5->getContentSize().height/2));
    smallAnimal3->setPosition(ccp(-(cask->getContentSize().width/2 - (50*(size.width/1024))), cask->getContentSize().height/2 - (44*(size.height/768)) + smallAnimal3->getContentSize().height/2));
    smallAnimal1->setPosition(ccp(-(cask->getContentSize().width/2 - (100*(size.width/1024))), cask->getContentSize().height/2 - (28*(size.height/768)) + smallAnimal1->getContentSize().height/2));
    smallAnimal7->setPosition(ccp(-(cask->getContentSize().width/2 - (140*(size.width/1024))), cask->getContentSize().height/2 - (48*(size.height/768))  + smallAnimal7->getContentSize().height/2));
    smallAnimal8->setPosition( ccp(-(cask->getContentSize().width/2 - (180*(size.width/1024))), cask->getContentSize().height/2 - (28*(size.height/768))  + smallAnimal8->getContentSize().height/2));
    smallAnimal2->setPosition(ccp(-(cask->getContentSize().width/2 - (216*(size.width/1024))), cask->getContentSize().height/2 - (30*(size.height/768))  + + smallAnimal2->getContentSize().height/2));
    smallAnimal4->setPosition(ccp(-(cask->getContentSize().width/2 - (244*(size.width/1024))), cask->getContentSize().height/2 - (46*(size.height/768))  + + smallAnimal4->getContentSize().height/2));
    smallAnimal6->setPosition(ccp(-(cask->getContentSize().width/2 - (300*(size.width/1024))), cask->getContentSize().height/2 - (40*(size.height/768))  + + smallAnimal6->getContentSize().height/2));

    animalsOnBoard->addObject(smallAnimal1);
        animalsOnBoard->addObject(smallAnimal2);
        animalsOnBoard->addObject(smallAnimal3);
        animalsOnBoard->addObject(smallAnimal4);
        animalsOnBoard->addObject(smallAnimal5);
        animalsOnBoard->addObject(smallAnimal6);
        animalsOnBoard->addObject(smallAnimal7);
        animalsOnBoard->addObject(smallAnimal8);
    CCLOG("animals on Board :%d",animalsOnBoard->count());
}
void Ship::SetIsOpen()
{
    open = true;
}
void Ship::SetIsClosed()
{
    open = false;
}
void Ship::SartGentleRumble(float dt)
{
    this->unschedule(schedule_selector(Ship::SartGentleRumble));
    this->runAction(CCRepeatForever::create(CCSequence::create(CCEaseOut::create(CCRotateTo::create(1.2f, 4), 2),CCEaseOut::create(CCRotateTo::create(1.2f, 0), 2),CCEaseOut::create(CCRotateTo::create(1.2f, -4), 2),CCEaseOut::create(CCRotateTo::create(1.2f, 0), 2),NULL)));
    this->runAction(CCRepeatForever::create(CCSequence::create(CCEaseOut::create(CCMoveBy::create(1.2f, ccp(0,-10)), 2),CCEaseOut::create(CCMoveBy::create(1.2f, ccp(0,20)), 2),CCEaseOut::create(CCMoveBy::create(1.2f, ccp(0,-10)), 2),NULL)));
}
void Ship::SwitchDoorsOpen(float dt)
{
    this->unschedule(schedule_selector(Ship::SwitchDoorsOpen));
    if (open)
    {
        CCAnimation* animation = CCAnimation::create();
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors4.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors3.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors2.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors1.png"));

        animation->setRestoreOriginalFrame(false);
        animation->setDelayPerUnit(0.6f/ 7);
        CCAnimate* action = CCAnimate::create(animation);
        action->setDuration(0.12f);
        cask->runAction(CCSequence::create(action,CCCallFunc::create(this, callfunc_selector(Ship::SetIsClosed)),NULL));
        this->schedule(schedule_selector(Ship::SwitchDoorsOpen), 2.0f);
    }
    else
    {
        CCAnimation* animation = CCAnimation::create();
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors1.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors2.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors3.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors4.png"));
        animation->setDelayPerUnit(0.6f/ 7);
        animation->setRestoreOriginalFrame(false);
        CCAnimate* action = CCAnimate::create(animation);
        action->setDuration(0.12f);

       cask->runAction(CCSequence::create(action,CCCallFunc::create(this, callfunc_selector(Ship::SetIsOpen)),NULL));
        this->schedule(schedule_selector(Ship::SwitchDoorsOpen), 20.0f);
    }
}
void Ship::GetShipMoving(float dt)
{
    this->unschedule(schedule_selector(Ship::GetShipMoving));
    float dD3 = 10.0 + (((rand() % 30)*1.0)/10.0);
    float disXD3 = (512.0*(size.width/1024)) + ((rand() % 10)*1.0);
    float disYD3 = (12.0 *(size.height/768))+ ((rand() % 6)*1.0);
    
    ccBezierConfig bezierD3;
    bezierD3.controlPoint_1 = ccp(disXD3, 0);
    bezierD3.controlPoint_2 = ccp(disXD3, disYD3);
    bezierD3.endPosition = ccp(0,disYD3);
    ccBezierConfig bezier2D3;
    bezier2D3.controlPoint_1 = ccp(-disXD3, 0);
    bezier2D3.controlPoint_2 = ccp(-disXD3, -disYD3);
    bezier2D3.endPosition = ccp(0,-disYD3);
    CCBezierBy *bezierForwardD3 = CCBezierBy::create(dD3, bezierD3);
    
    CCBezierBy *bezierBackD3 =CCBezierBy::create(dD3, bezier2D3);
    CCSequence *seq=CCSequence::create(bezierForwardD3,bezierBackD3,NULL);
    CCRepeatForever *rep=CCRepeatForever::create(seq);
    this->runAction(rep);
}
void Ship::StopBoat(bool ShouldRemovePlume)
{
    if (plume && ShouldRemovePlume)
    {
        plume->stopSystem();
        commonNode->removeChild(plume,true);
    }
    cask->stopAllActions();
    this->stopAllActions();
    this->unscheduleAllSelectors();
    if (open)
    {
//        CCSpriteFrameCache *frame=CCSpriteFrameCache::sharedSpriteFrameCache();
//        CCArray *shipClosingFrames=CCArray::create();
//        shipClosingFrames->addObject(frame->spriteFrameByName("arkBiggerDoors4.png"));
//        shipClosingFrames->addObject(frame->spriteFrameByName("arkBiggerDoors3.png"));
//
//        shipClosingFrames->addObject(frame->spriteFrameByName("arkBiggerDoors2.png"));
//
//        shipClosingFrames->addObject(frame->spriteFrameByName("arkBiggerDoors1.png"));
//        cocos2d::CCAnimation *pAnimation=CCAnimation::createWithSpriteFrames(shipClosingFrames);
//        pAnimation->setRestoreOriginalFrame(false);
//        CCAnimate *anim=CCAnimate::create(pAnimation);
//        anim->setDuration(0.12f);
//        cask->runAction(CCSequence::create(anim,CCCallFunc::create(this, callfunc_selector(Ship::SetIsClosed)),NULL));
        CCAnimation* animation = CCAnimation::create();
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors4.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors3.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors2.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors1.png"));
        animation->setDelayPerUnit(1.0f/12);
        animation->setRestoreOriginalFrame(true);
        CCAnimate* action = CCAnimate::create(animation);
        cask->runAction(CCSequence::create(action,CCCallFunc::create(this, callfunc_selector(Ship::SetIsClosed)),NULL));
        
        
    }
    float timeToStartPos =  ((512.0f*(size.width/1024)) - this->getPositionX())/(512.0f*(size.width/1024))*1.6f;
    if (timeToStartPos < 0)
    {
        timeToStartPos *=-1;
    }
    float timeToStartRot =  (this->getRotation())/4*1.2f;
    if (timeToStartRot < 0)
    {
        timeToStartRot *=-1;
    }
    this->runAction(CCEaseInOut::create(CCMoveTo::create(timeToStartPos, ccp((512*(size.width/1024)), (768*(size.height/768)-280*(size.height/768)))),2));
    this->runAction(CCEaseInOut::create(CCRotateTo::create(timeToStartRot, 0),2));
    this->schedule(schedule_selector(Ship::SartGentleRumble), MAX(timeToStartRot, timeToStartPos));
}
void Ship::StartBoat()
{
    cask->stopAllActions();
    this->stopAllActions();
    this->unscheduleAllSelectors();
    commonNode->runAction(CCEaseInOut::create(CCMoveTo::create(0.8f, ccp(0,0)), 2));
    float timeToStartPos =  ((512.0f*(size.width/1024)) - this->getPositionX())/(512.0f*(size.width/1024))*1.6f;
    if (timeToStartPos < 0)
    {
        timeToStartPos *=-1;
    }
    float timeToStartRot =  (this->getRotation())/4*1.2f;
    if (timeToStartRot < 0)
    {
        timeToStartRot *=-1;
    }
    this->runAction(CCEaseInOut::create(CCMoveTo::create(timeToStartPos, ccp((512*(size.width/1024)),(768*(size.height/768))-(280*(size.height/768)))), 2));
    this->runAction(CCEaseInOut::create(CCRotateTo::create(timeToStartRot, 0), 2));
    this->schedule(schedule_selector(Ship::GetShipMoving),MAX(timeToStartPos, timeToStartRot));
    CCRotateBy *rot1a=CCRotateBy::create(0.6, 5);
    CCRotateBy *rot2a=CCRotateBy::create(0.6, -5);
    CCRotateBy *rot3a=CCRotateBy::create(0.6, -5);
    CCRotateBy *rot4a=CCRotateBy::create(0.6, 5);
    CCSequence *seq2a=CCSequence::create(rot1a,rot2a,rot3a,rot4a,NULL);

    CCRepeatForever *repAA = CCRepeatForever::create(seq2a);
    this->runAction(repAA);
    this->schedule(schedule_selector(Ship::SwitchDoorsOpen));
}
void Ship::StartStopedBoat()
{
    cask->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkBiggerDoors1.png"));
    this->schedule(schedule_selector(Ship::SartGentleRumble));
}
bool Ship::AnimalEnteredArk(LaunchingAnimal* animal)
{
    if (!open)
        return false;
    
    if (GameManager::sharedGameManager()->isTouchOnArea(animal->getimage()->getPosition(),this->getPosition(), 120*(size.width/1024), 70*(size.height/768)))
    {
        commonNode->addChild((CCSprite*)animalsOnBoard->objectAtIndex(animal->getindex()),15);
        //CCLog("animal entered on ark");
        return true;
    }
    return false;
}
bool Ship::AnimalHitArk(LaunchingAnimal*animal)
{
  return GameManager::sharedGameManager()->isTouchOnArea(ccpAdd(animal->getimage()->getPosition(), ccp(0, -60*(size.height/768))),this->getPosition(), (340*(size.width/1024)), (120*(size.height/768)));
}
void Ship::RemoveAllAnimals()
{
    CCObject *Pobj=NULL;
    CCARRAY_FOREACH(animalsOnBoard, Pobj)
    {
        CCSprite *animal=(CCSprite *)Pobj;
        commonNode->removeChild(animal, true);
    }
    animalsOnBoard->removeAllObjects();
}
void Ship::updateArkFromAccelerometer(float xAcc)
{
    if ((commonNode->getPositionX() < -(900*(size.width/1024)) && xAcc < 0) || ( commonNode->getPositionX() >= (900*(size.width/1024)) && xAcc > 0))
    {
        return;
    }
   
    if (isnan(xAcc)||isinf(xAcc)||xAcc>1||xAcc<-1)
    {
        xAcc=0.0;
    }
    CCDirector* pDir = CCDirector::sharedDirector();
    CCPoint ptNow  = commonNode->getPosition();
    CCPoint ptTemp = pDir->convertToUI(ptNow);
    ptTemp.x = ptTemp.x - xAcc*4;
    CCPoint ptNext = pDir->convertToGL(ptTemp);
    commonNode->setPosition(ptNext.x,ptNext.y);
}
void Ship::PlayPlume()
{
    plume =CCParticleSystemQuad::create("VICTORY STARS_0002.plist");
    plume->setPosition(ccp(0,10));
    plume->retain();
    commonNode->addChild(plume,4);

}
