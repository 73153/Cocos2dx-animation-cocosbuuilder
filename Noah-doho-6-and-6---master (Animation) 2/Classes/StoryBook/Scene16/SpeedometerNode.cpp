//
//  SpeedometerNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "SpeedometerNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define TimeToReturnToZero 8.4f
#define TimeToIncreaseSpeed 0.3f
#define RotationToIncreaseSpeed 20.0f
#define MinRotation -24
#define MaxRotation 250
SpeedometerNode::SpeedometerNode()
{

  
}
SpeedometerNode::~SpeedometerNode()
{

}
void SpeedometerNode::onEnter()
{
    CCNode::onEnter();
}
SpeedometerNode* SpeedometerNode::create(CCObject *obj,SEL_CallFuncO selector)
{
    SpeedometerNode* ret = new SpeedometerNode();
    if (ret)
    {
        if (ret->initSpeedometerNode(obj,selector))
        {
            ret->autorelease();
        }
        else
        {
            delete ret;
            ret = NULL;
        }
    }
    return ret;
}
bool SpeedometerNode::initSpeedometerNode(CCObject *obj,SEL_CallFuncO selector)
{
    if (CCNode::init())
    {
        parent=obj;
        selected=selector;
        background =CCSprite::createWithSpriteFrameName("speedometer.png");
        needle=CCSprite::createWithSpriteFrameName("speedNeedle.png");
        background->setPosition(CCPointZero);
        background->setPosition(CCPointZero);
        needle->setPosition(CCPointZero);
        needle->setRotation(MinRotation);
        background->setOpacity(0);
        needle->setOpacity(0);
        this->addChild(background,0);
        this->addChild(needle,1);
        needle->setRotation(MinRotation);
                return true;
    }
    return false;
}
bool SpeedometerNode::init()
{
    if (CCNode::init())
    {
        
        return true;
    }
    return false;
}
void SpeedometerNode::ResetSpeedometer()
{
    background->setPosition(CCPointZero);
    needle->setPosition(CCPointZero);
    needle->setRotation(MinRotation);
    background->setOpacity(0);
    needle->setOpacity(0);
}
void SpeedometerNode::GetBackToZero()
{
    float timeToRotate = TimeToReturnToZero *(needle->getRotation() - MinRotation)/(MaxRotation - MinRotation);
    needle->runAction(CCRotateBy::create(timeToRotate, MinRotation - needle->getRotation()));
}
void SpeedometerNode::WeHaveLiftOff()
{
    background->runAction(CCFadeOut::create(0.3f));
    needle->runAction(CCFadeOut::create(0.3f));
    this->runAction(CCCallFuncO::create(parent, selected, this));
}
void SpeedometerNode::IncreaseSpeed()
{
    needle->stopAllActions();
    if ((needle->getRotation() + RotationToIncreaseSpeed) >=MaxRotation)
    {
        //Will lift off after this
        float timeToRotate = TimeToIncreaseSpeed * (MaxRotation - needle->getRotation())/(RotationToIncreaseSpeed);
        needle->runAction(CCSequence::create(CCRotateTo::create(timeToRotate, MaxRotation),CCCallFunc::create(this, callfunc_selector(SpeedometerNode::WeHaveLiftOff)),NULL));
    }
    else
    {
        needle->runAction(CCSequence::create(CCRotateBy::create(TimeToIncreaseSpeed, RotationToIncreaseSpeed),CCCallFunc::create(this, callfunc_selector(SpeedometerNode::GetBackToZero)),NULL));
    }
}
void SpeedometerNode::Start()
{
    background->runAction(CCFadeIn::create(0.3f));
    needle->runAction(CCFadeIn::create(0.3f));
    needle->setOpacity(255);
}
