//
//  Orca.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "Orca.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
Orca::Orca():mAnimationManager(NULL)
{

  
}
Orca::~Orca()
{

}
bool Orca::init()
{
    if (CCNode::init())
    {
        size=CCDirector::sharedDirector()->getWinSize();
        image = CCSprite::createWithSpriteFrameName("orca.png");
        image->setPosition(ccp(-140*(size.width/1024), 0));
        this->addChild(image);
        return true;
    }
    return false;
}
void Orca::onEnter()
{
   
    CCNode::onEnter();
}
void Orca::StopOrca()
{
    orcaShouldStop = true;
}
void Orca::StartOrca()
{
    orcaShouldStop = false;
    image->stopAllActions();
    image->setPosition(ccp(0, 0));
    image->setRotation(180);
    image->runAction(CCRepeatForever::create(CCSequence::create(CCRotateBy::create(3.0f, 360),CCMoveBy::create(0.4f, ccp(300.0f*(size.width/1024), 0)),CCCallFunc::create(this, callfunc_selector(Orca::TestForOrcaMov)),NULL)));
    
}
void Orca::EndEverything()
{
    this->unscheduleAllSelectors();
    image->stopAllActions();
}
void Orca::TestForOrcaMov()
{
    if (orcaShouldStop)
    {
        image->stopAllActions();
        image->setPosition(ccp(-140*(size.width/1024), 0));
    }
    if (image->getPositionX() >= 1024*(size.width/1024))
    {
        image->setPosition(ccpAdd(image->getPosition(), ccp(-1164*(size.width/1024),0)));
    }
}