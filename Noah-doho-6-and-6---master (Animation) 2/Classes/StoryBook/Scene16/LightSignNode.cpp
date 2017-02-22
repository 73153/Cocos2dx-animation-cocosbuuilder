//
//  LightSignNode.cpp
//  Noah360
//  Created by Neil D on 03/10/13.

#include "LightSignNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
LightSignNode::LightSignNode()
{
}
LightSignNode::~LightSignNode()
{

}
void LightSignNode::onEnter()
{
   CCNode::onEnter();
}
LightSignNode* LightSignNode::create(CCObject *obj,SEL_CallFuncO selector)
{
    LightSignNode* ret = new LightSignNode();
    if (ret)
    {
        if (ret->initLightSignNode(obj,selector))
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
bool LightSignNode::initLightSignNode(CCObject *obj,SEL_CallFuncO selector)
{
    if (CCNode::init())
    {
        parent=obj;
        selected=selector;
        background = CCSprite::createWithSpriteFrameName("stoplight.png");
        grenLight = CCSprite::createWithSpriteFrameName("greeen_stoplight.png");
        yellowLight= CCSprite::createWithSpriteFrameName("yellow_stoplight.png");
        redLight= CCSprite::createWithSpriteFrameName("red_stoplight.png");
        background->setPosition(CCPointZero);
        grenLight->setPosition(CCPointZero);
        yellowLight->setPosition(CCPointZero);
        redLight->setPosition(CCPointZero);
        
        grenLight->setOpacity(0);
        yellowLight->setOpacity(0);
        
        this->addChild(background, 0);
        this->addChild(grenLight, 1);
        this->addChild(yellowLight, 1);
        this->addChild(redLight,1);
        return true;
    }
    return false;
}
void LightSignNode::ResetLights()
{
    background->setOpacity(255);
    redLight->setOpacity( 255);
    grenLight->setOpacity( 0);
    yellowLight->setOpacity( 0);
}
void LightSignNode::FinishLights()
{
#warning delegate...
    //delegate for make fly off...
    //CCLog("Light Finished");
    this->runAction(CCCallFuncO::create(parent, selected, this));
    background->runAction(CCFadeOut::create(0.2f));
    grenLight->runAction(CCFadeOut::create(0.2f));
}
void LightSignNode::StartLightChange()
{
    float timeToStayOn = 0.8f;
    float timeToFade = 0.1f;
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/areYouReadyGo.mp3", false);
    redLight->runAction(CCFadeOut::create(timeToFade));
    yellowLight->runAction(CCSequence::create(CCDelayTime::create(timeToFade),CCFadeIn::create(timeToFade),CCDelayTime::create(timeToStayOn),CCFadeOut::create(timeToFade),NULL));
    grenLight->runAction(CCSequence::create(CCDelayTime::create(timeToFade+timeToFade+timeToStayOn+timeToStayOn),CCFadeIn::create(timeToFade),CCDelayTime::create(timeToStayOn),CCCallFunc::create(this, callfunc_selector(LightSignNode::FinishLights)),NULL));
}
void LightSignNode::Start()
{
    //    [background runAction:[CCFadeIn actionWithDuration:0.2f]];
    //    [redLight runAction:[CCFadeIn actionWithDuration:0.2f]];
}
