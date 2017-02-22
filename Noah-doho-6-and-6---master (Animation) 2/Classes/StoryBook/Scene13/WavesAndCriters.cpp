//
//  WavesAndCriters.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "WavesAndCriters.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
WavesAndCriters::WavesAndCriters():mAnimationManager(NULL)
{
    prevWaveMidY2=0.0f;
    prevWaveMidY1=0.0f;
}
WavesAndCriters::~WavesAndCriters()
{
  
}
bool WavesAndCriters::init()
{
    if (CCNode::init())
    {
        
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0, true);
        size=CCDirector::sharedDirector()->getWinSize();

    waterBack =CCSprite::createWithSpriteFrameName("WAVE_BACK_TEMPLATE.png");
    waterMid =CCSprite::createWithSpriteFrameName("WAVE_MID_TEMPLATE.png");
    waterFront =CCSprite::createWithSpriteFrameName("WAVE_FORE_TEMPLATE.png");
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        waterBack->setPosition(ccp((512*(size.width/1024)), (374*(size.height/768))));
        waterMid->setPosition(ccp((512*(size.width/1024)), (324*(size.height/768))));
        waterFront->setPosition(ccp((512*(size.width/1024)), (94*(size.height/768))));
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if (size.width==1136||size.width==960)
        {
            waterBack->setPosition(ccp((512*(size.width/1024)), (374*(size.height/768))));
            waterMid->setPosition(ccp((512*(size.width/1024)), (324*(size.height/768))));
            waterFront->setPosition(ccp((512*(size.width/1024)), (94*(size.height/768))));
        }
        else
        {
            waterBack->setPosition(ccp((512*(size.width/1024)), (404*(size.height/768))));
            waterMid->setPosition(ccp((512*(size.width/1024)), (354*(size.height/768))));
            waterFront->setPosition(ccp((512*(size.width/1024)), (144*(size.height/768))));
        }
        #endif
        waterMid->setScale(1/0.75f);
        waterBack->setScale(1/0.75f);
        waterFront->setScale(1/0.75f);
        
        snorkelAnimals =CCArray::create();
        snorkelAnimals->retain();
        
        polvo = Octopus::create();
        
        kWhale=Orca::create();
        kWhale->setPosition(ccpAdd(waterFront->getPosition(), ccp((-512*(size.width/1024)),80*(size.height/768))));

        snorkelNode=CCNode::create();
        snorkelNode->retain();
        snorkelNode->setPosition(ccp(0, 0));
        this->addChild(waterBack,10);
        polvo->setVisible(false);
        if (GameManager::sharedGameManager()->GetAchievmentIsActive(InkyAchievmentID))
        {
                //this->addChild(polvo,15);
                polvo->setVisible(true);
        }
        this->addChild(polvo,15);
        this->addChild(snorkelNode, 17);
        this->addChild(waterMid,20);
        this->addChild(kWhale,25);
        this->addChild(waterFront, 30);

        
        
        float d = 1.7 + (((rand() % 2)*1.0)/10.0);
        
        float disX = 80.0 + ((rand() % 20)*1.0);
        float disY = 4.0 + ((rand() % 4)*1.0);
        
        ccBezierConfig bezier;
        bezier.controlPoint_1 = ccp(disX, 0);
        bezier.controlPoint_2 = ccp(disX, disY*(size.height/768));
        bezier.endPosition = ccp(0,disY);
        ccBezierConfig bezier2;
        bezier2.controlPoint_1 = ccp(-disX, 0);
        bezier2.controlPoint_2 = ccp(-disX, -disY*(size.height/768));
        bezier2.endPosition = ccp(0,-disY);
        CCBezierBy *bezierForward=CCBezierBy::create(d, bezier);
        CCBezierBy *bezierBack=CCBezierBy::create(d, bezier2);
      

        CCRepeatForever *rep = CCRepeatForever::create(CCSequence::create(bezierForward,bezierBack,NULL));
        waterBack->runAction(rep);
        
        float dM = 2.2 + (((rand() % 4)*1.0)/10.0);
        
        float disXM = 240.0 *(size.width/1024)+ ((rand() % 20)*1.0);
        float disYM = 24.0 + ((rand() % 12)*1.0);
        
        ccBezierConfig bezierM;
        bezierM.controlPoint_1 = ccp(disXM, 0);
        bezierM.controlPoint_2 = ccp(disXM, disYM*(size.height/768));
        bezierM.endPosition = ccp(0,disYM);
        ccBezierConfig bezier2M;
        bezier2M.controlPoint_1 = ccp(-disXM, 0);
        bezier2M.controlPoint_2 = ccp(-disXM, -disYM*(size.height/768));
        bezier2M.endPosition = ccp(0,-disYM);
        
        CCBezierBy *bezierForwardM=CCBezierBy::create(dM, bezierM);
        CCBezierBy *bezierBackM=CCBezierBy::create(dM, bezier2M);
        CCRepeatForever *repM = CCRepeatForever::create(CCSequence::create(bezierForwardM,bezierBackM,NULL));
        waterMid->runAction(repM);
        
        
        float dF = 2.6 + (((rand() % 2)*1.0)/10.0);
        
        float disXF = 240.0*(size.width/1024) + ((rand() % 20)*1.0);
        float disYF = 24.0 + ((rand() % 12)*1.0);
        
        ccBezierConfig bezierF;
        bezierF.controlPoint_1 = ccp(disXF, 0);
        bezierF.controlPoint_2 = ccp(disXF, disYF*(size.height/768));
        bezierF.endPosition = ccp(0,disYF);
        ccBezierConfig bezier2F;
        bezier2F.controlPoint_1 = ccp(-disXF, 0);
        bezier2F.controlPoint_2 = ccp(-disXF, -disYF*(size.height/768));
        bezier2F.endPosition = ccp(0,-disYF);
        
        
        CCBezierBy *bezierForwardF=CCBezierBy::create(dF, bezierF);
        CCBezierBy *bezierBackF=CCBezierBy::create(dF, bezier2F);
        CCRepeatForever *repF = CCRepeatForever::create(CCSequence::create(bezierForwardF,bezierBackF,NULL));
        waterFront->runAction(repF);
        

    
       
        return true;
    }
    return false;
}
void WavesAndCriters::onEnter()
{
    CCNode::onEnter();
}
void WavesAndCriters::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCNode::onExit();
}
void WavesAndCriters::EndEverything()
{
    this->unscheduleAllSelectors();
    waterBack->stopAllActions();
    waterMid->stopAllActions();
    waterFront->stopAllActions();
    kWhale->stopAllActions();
    kWhale->EndEverything();
    polvo->stopAllActions();
    polvo->EndEverything();
}
void WavesAndCriters::StartToTick()
{
    this->schedule(schedule_selector(WavesAndCriters::tick),1/12.0f);
}
void WavesAndCriters::StartWaves()
{
    waterMid->resumeSchedulerAndActions();
    waterFront->resumeSchedulerAndActions();
    waterBack->resumeSchedulerAndActions();

    kWhale->stopAllActions();
    kWhale->StartOrca();
    kWhale->setPosition(ccpAdd(waterFront->getPosition(), ccp((-512*(size.width/1024)),(80*(size.height/768)))));
    polvo->stopAllActions();

    polvo->setPosition(ccpAdd(waterMid->getPosition(), ccp((280*(size.width/1024)),(120*(size.height/768)))));
    polvo->runAction(CCSequence::create(CCEaseIn::create(CCMoveTo::create(0.6f, ccp(polvo->getPositionX(),waterMid->getPositionY()+(120*(size.height/768)))), 2),CCCallFunc::create(this, callfunc_selector(WavesAndCriters::StartToTick)),NULL));
                       
}
void WavesAndCriters::PauseWaveActions(float dt)
{
    this->unschedule(schedule_selector(WavesAndCriters::tick));
    this->unschedule(schedule_selector(WavesAndCriters::PauseWaveActions));

    waterMid->pauseSchedulerAndActions();
    waterFront->pauseSchedulerAndActions();
    waterBack->pauseSchedulerAndActions();
}
void WavesAndCriters::StartStoped()
{
    this->schedule(schedule_selector(WavesAndCriters::PauseWaveActions));
    polvo->setPosition(ccpAdd(waterMid->getPosition(), ccp((280*(size.width/1024)),(-480*(size.height/768)))));

    kWhale->StopOrca();
    kWhale->setPosition(ccpAdd(waterFront->getPosition(), ccp((-512*(size.width/1024)),(80*(size.height/768)))));
}
void WavesAndCriters::StartMoved()
{
    kWhale->StartOrca();
    kWhale->setPosition(ccpAdd(waterFront->getPosition(), ccp((-512*(size.width/1024)),(80*(size.height/768)))));
    polvo->setPosition(ccpAdd(waterMid->getPosition(), ccp((280*(size.width/1024)),(120*(size.height/768)))));
    this->schedule(schedule_selector(WavesAndCriters::tick),1/12.0f);

}

void WavesAndCriters::StopWaves()
{
    this->schedule(schedule_selector(WavesAndCriters::tick));
        this->schedule(schedule_selector(WavesAndCriters::PauseWaveActions));
    
    polvo->stopAllActions();

    polvo->setPosition(ccpAdd(waterMid->getPosition(), ccp((280*(size.width/1024)),(-480*(size.height/768)))));
    polvo->runAction(CCEaseIn::create(CCMoveTo::create(0.6f, ccp(polvo->getPositionX(),waterMid->getPositionY()-(480*(size.height/768)))), 2));
    
    kWhale->stopAllActions();
    kWhale->StopOrca();
    kWhale->setPosition(ccpAdd(waterFront->getPosition(), ccp((-512*(size.width/1024)),(80*(size.height/768)))));
}

void WavesAndCriters::RemoveSnorkelAnimal()
{
    snorkelNode->removeChild((CCNode*)snorkelAnimals->objectAtIndex(0), true);
    snorkelAnimals->removeObjectAtIndex(0);
}
void WavesAndCriters::MoveSnorkelAnimal(float dt)
{
    this->unschedule(schedule_selector(WavesAndCriters::MoveSnorkelAnimal));
    CCSprite* snorkelAnimal =CCSprite::createWithSpriteFrameName(CCString::createWithFormat("1%s.png",loadAnimal->getname()->getCString())->getCString());
    snorkelAnimal->retain();
    CCSprite* snorkel=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("1%sSnorkel.png",loadAnimal->getname()->getCString())->getCString());

    snorkel->retain();
    
    snorkelAnimal->setScale((1/0.75f)/2);
    snorkel->setScale((1/0.75f)/2);
    
    if (strcmp(loadAnimal->getname()->getCString(),"monkey" ) ||strcmp(loadAnimal->getname()->getCString(),"sheep"))
    {
        snorkelAnimal->setPosition(ccp(loadAnimal->getimage()->getPositionX(),(-16*(size.height/768))));
        snorkel->setPosition(ccp(loadAnimal->getimage()->getPositionX(),(-16*(size.height/768))));
    }
    else
    {
        snorkelAnimal->setPosition(ccp(loadAnimal->getimage()->getPositionX(),0));
        snorkel->setPosition(ccp(loadAnimal->getimage()->getPositionX(),0));
    }
    snorkelNode->addChild(snorkelAnimal);
    snorkelAnimals->addObject(snorkelAnimal);
    snorkelNode->addChild(snorkel);
    snorkelAnimals->addObject(snorkel);

    if (loadAnimal->getPositionX() <= (512*(size.width/1024)))
    {
        snorkelAnimal->runAction(CCSequence::create(CCMoveTo::create(3.2f, ccp((-200*(size.width/1024)), snorkelAnimal->getPositionY())),CCCallFunc::create(this, callfunc_selector(WavesAndCriters::RemoveSnorkelAnimal)),NULL));
        snorkel->runAction(CCSequence::create(CCMoveTo::create(3.2f, ccp((-200*(size.width/1024)), snorkelAnimal->getPositionY())),NULL));
    }
    else
    {
        snorkelAnimal->runAction(CCSequence::create(CCMoveTo::create(3.2f, ccp((1224*(size.width/1024)), snorkelAnimal->getPositionY())),CCCallFunc::create(this, callfunc_selector(WavesAndCriters::RemoveSnorkelAnimal)),NULL));
        snorkel->runAction(CCSequence::create(CCMoveTo::create(3.2f, ccp((1224*(size.width/1024)), snorkelAnimal->getPositionY())),NULL));
    }
}
void WavesAndCriters::AddSnorkelAnimal(LaunchingAnimal* lAnimal)
{
    loadAnimal = lAnimal;
    loadAnimal->retain();
    this->schedule(schedule_selector(WavesAndCriters::MoveSnorkelAnimal), 0.8f);
}
void WavesAndCriters::tick(float dt)
{

  // polvo->setPosition(ccp(polvo->getPositionX(), prevWaveMidY2 + 120*(screen_height/768)));
    snorkelNode->setPosition(ccp(snorkelNode->getPositionX(),prevWaveMidY2+82*(size.height/768)));
    prevWaveMidY2 = prevWaveMidY1;
    prevWaveMidY1 = waterMid->getPositionY();
}
bool WavesAndCriters::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return false;
    CCPoint point =touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    CCPoint touchPointWhale  =kWhale->getimage()->convertToNodeSpace(point);
    CCRect rect1 = CCRectMake(0, 0, kWhale->getimage()->getContentSize().width, kWhale->getimage()->getContentSize().height);
    
    if (rect1.containsPoint(touchPointWhale))
    {
        GameManager::sharedGameManager()->AddPoints(3, point, this);
        return false;
    }
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(snorkelAnimals, pobj)
    {
        CCSprite *snorkelImage=(CCSprite*)pobj;
        CCRect rect=CCRect(0,0, snorkelNode->getContentSize().width, snorkelNode->getContentSize().height);
        CCPoint touchpointimage=snorkelImage->convertToNodeSpace(point);
        if (rect.containsPoint(touchpointimage))
        {
            GameManager::sharedGameManager()->AddPoints(3, point, this);
            return false;
        }
    }
    return false;
}
