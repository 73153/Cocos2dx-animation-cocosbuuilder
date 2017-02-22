//
//  Octopus.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "Octopus.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
Octopus::Octopus():mAnimationManager(NULL)
{

  
}
Octopus::~Octopus()
{

}
bool Octopus::init()
{
    if (CCNode::init())
    {
        head = CCSprite::createWithSpriteFrameName("octopusHead.png");
        arm1=CCSprite::createWithSpriteFrameName("octopusTentacle1.png");
        arm2=CCSprite::createWithSpriteFrameName("octopusTentacle2.png");
        arm3 =CCSprite::createWithSpriteFrameName("octopusTentacle3.png");
        arm4 =CCSprite::createWithSpriteFrameName("octopusTentacle4.png");
        arm5=CCSprite::createWithSpriteFrameName("octopusTentacle5.png");
        arm6=CCSprite::createWithSpriteFrameName("octopusTentacle6.png");
        commonNode = CCNode::create();
        size=CCDirector::sharedDirector()->getWinSize();
        
        head->setPosition(ccp(0,0));
        arm1->setPosition( ccp(0,-72*(size.height/768)));
        arm2->setPosition(ccp(-10*(size.width/1024),-72*(size.height/768)));
        arm3->setPosition(ccp(0,-62*(size.height/768)));
        arm4->setPosition(ccp(-12*(size.width/1024),-82*(size.height/768)));
        arm5->setPosition(ccp(-15*(size.width/1024),-78*(size.height/768)));
        arm6->setPosition(ccp(16*(size.width/1024),-72*(size.height/768)));
        commonNode->setPosition(ccp(0,0));
        this->addChild(commonNode,10);
        commonNode->addChild(head,20);
        commonNode->addChild(arm1,10);
        commonNode->addChild(arm2,10);
        commonNode->addChild(arm3,10);
        commonNode->addChild(arm4,10);
        commonNode->addChild(arm5,10);
        commonNode->addChild(arm6,10);
      
        return true;
    }
    return false;
}
void Octopus::onEnter()
{
  
    this->GetRandomMovment(arm1);
    this->GetRandomMovment(arm2);
    this->GetRandomMovment(arm3);
    this->GetRandomMovment(arm4);
    this->GetRandomMovment(arm5);
    this->GetRandomMovment(arm6);
    commonNode->runAction(CCRepeatForever::create(CCSequence::create(CCEaseInOut::create(CCMoveTo::create(12.0f, ccp(-560*(size.width/1024), 0)), 2),CCEaseInOut::create(CCMoveTo::create(12.0f, ccp(0, 0)), 2),NULL)));
   CCNode::onEnter();
}
void Octopus::EndEverything()
{
    
    this->unscheduleAllSelectors();
    commonNode->stopAllActions();
    commonNode->removeAllChildrenWithCleanup(true);
    arm1->stopAllActions();
        arm2->stopAllActions();
        arm3->stopAllActions();
        arm4->stopAllActions();
        arm5->stopAllActions();
        arm6->stopAllActions();
}
void Octopus::GetRandomMovment(CCSprite* image)
{
    float randomTime = (rand()%800+1601)/1200.0f;
    int randDirection = rand()%2;
    if (randDirection)
    {
        image->runAction(CCRepeatForever::create(CCSequence::create(CCEaseIn::create(CCRotateTo::create(randomTime/2.0f, 10), 2),CCEaseOut::create(CCRotateTo::create(randomTime/2.0f, 0), 2),CCEaseIn::create(CCRotateTo::create(randomTime/2.0f, -10), 2),CCEaseOut::create(CCRotateTo::create(randomTime/2.0f, 0), 2),NULL)));
        
       
    }
    else
    {
        image->runAction(CCRepeatForever::create(CCSequence::create(CCEaseIn::create(CCRotateTo::create(randomTime/2.0f, -10), 2),CCEaseOut::create(CCRotateTo::create(randomTime/2.0f, 0), 2),CCEaseIn::create(CCRotateTo::create(randomTime/2.0f, 10), 2),CCEaseOut::create(CCRotateTo::create(randomTime/2.0f, 0), 2),NULL)));
    }
    randDirection = rand()%2;
    if (randDirection)
    {
        
        image->runAction(CCSequence::create(CCScaleTo::create(randomTime/3.3f, 0.9f),CCScaleTo::create(randomTime/3.3f, 1.0f),CCScaleTo::create(randomTime/3.3f, 1.1f),CCScaleTo::create(randomTime/3.3f, 1.0f),NULL));
        
    }
    else
    {
        image->runAction(CCSequence::create(CCScaleTo::create(randomTime/3.3f, 1.1),CCScaleTo::create(randomTime/3.3f, 1.0f),CCScaleTo::create(randomTime/3.3f, 0.9),CCScaleTo::create(randomTime/3.3f, 1.0f),NULL));
    }
}
