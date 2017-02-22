//
//  RainDrop.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "RainDrop.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
RainDrop* RainDrop::RainDropWithimagename(CCString* adropname)
{
    RainDrop* pBall = new RainDrop();
    pBall->initWithSpriteFrameName(adropname->getCString());
    pBall->autorelease();
    return pBall;
}
RainDrop::RainDrop()
{
    //CCLog("Header Layer called");
}
RainDrop::~RainDrop()
{

}
void RainDrop::onEnter()
{
    
   CCSprite::onEnter();
}
void RainDrop::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}