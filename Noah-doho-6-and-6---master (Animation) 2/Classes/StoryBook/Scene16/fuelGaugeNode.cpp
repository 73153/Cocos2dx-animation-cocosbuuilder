//
//  fuelGaugeNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "fuelGaugeNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
fuelGaugeNode::fuelGaugeNode()
{

  
}
fuelGaugeNode::~fuelGaugeNode()
{

}
void fuelGaugeNode::onEnter()
{
    CCNode::onEnter();
}
void fuelGaugeNode::StartFuelConsuption()
{
    float greenHeight = greenRect->getContentSize().height;
    float redHeight = redRect->getContentSize().height;
    float totalHeight = redHeight + greenHeight;
    float timeForGreen = timeInAnimation*greenHeight/totalHeight;
    float timeForRed = timeInAnimation*redHeight/totalHeight;
    
    greenRect->runAction(CCScaleTo::create(timeForGreen, 1, 0));
    redRect->runAction(CCSequence::create(CCDelayTime::create(timeForGreen),CCScaleTo::create(timeForRed, 1,0),NULL));
}
void fuelGaugeNode::ResetFuelConsuption()
{
    this->Stop();
    greenRect->setScaleY(1);
    redRect->setScaleY(1);
}
void fuelGaugeNode::Stop()
{
    greenRect->stopAllActions();
    redRect->stopAllActions();
}
bool  fuelGaugeNode::initwithtimer(float newtime)
{
    if (fuelGaugeNode::init())
    {
        timeInAnimation = newtime;
        mainImage=CCSprite::createWithSpriteFrameName("fuelGauge.png");
        redRect=CCSprite::createWithSpriteFrameName("fuelGaugeRed.png");
        greenRect=CCSprite::createWithSpriteFrameName("fuelGaugeGreen.png");
        mainImage->setPosition(CCPointZero);
        #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            if (screen_width<=960&&screen_height<=640)
            {
                //CCLOG("medium resolution phone");
                redRect->setPosition(ccp(6*(screen_width/1024),-125*(screen_height/768)));
                greenRect->setPosition(ccp(6*(screen_width/1024),redRect->getPositionY()-redRect->getContentSize().height+3*(greenRect->getContentSize().height/4)));
            // redRect->setPosition(ccp(6*(screen_width/1024),-101*(screen_height/768)));
            // greenRect->setPosition(ccp(6*(screen_width/1024),-49*(screen_height/768)));
            }
            else if(screen_height>=640)
            {
                CCLOG("High resolution phone");
                redRect->setPosition(ccp(6*(screen_width/1024),-109));
                greenRect->setPosition(ccp(6*(screen_width/1024),-57));
            }
            else
            {
                CCLOG("tablet resoltion");
                redRect->setPosition(ccp(6*(screen_width/1024),-99*(screen_height/768)));
                greenRect->setPosition(ccp(6*(screen_width/1024),-46*(screen_height/768)));
            }
        #elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            if (screen_width==960&&screen_height==640)
            {
                redRect->setPosition(ccp(6*(screen_width/1024),-101));
                greenRect->setPosition(ccp(6*(screen_width/1024),-49));
            }
            else if (screen_height==640&&screen_width==1136)
            {
                redRect->setPosition(ccp(6*(screen_width/1024),-109));
                greenRect->setPosition(ccp(6*(screen_width/1024),-57));
            }
            else
            {
                redRect->setPosition(ccp(6*(screen_width/1024),-99*(screen_height/768)));
                greenRect->setPosition(ccp(6*(screen_width/1024),-46*(screen_height/768)));
            }
       
        #endif
        redRect->setAnchorPoint(CCPointMake(0.5, 0));
        greenRect->setAnchorPoint(ccp(0.5, 0));
        //mainImage->setAnchorPoint(ccp(0.5, 0));
        mainImage->setVisible(true);
        redRect->setVisible(true);
        greenRect->setVisible(true);
        this->addChild(greenRect,1);
        this->addChild(redRect,5);
        this->addChild(mainImage,10);
        return true;
    }
    return false;
}
fuelGaugeNode* fuelGaugeNode::create(float newtime)
{
    fuelGaugeNode* ret = new fuelGaugeNode();
    if (ret)
    {
        if (ret->initwithtimer(newtime))
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

