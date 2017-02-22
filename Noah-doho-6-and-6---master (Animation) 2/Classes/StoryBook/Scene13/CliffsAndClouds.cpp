//
//  CliffsAndClouds.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "CliffsAndClouds.h"
#include "../../SoundManager/SoundManager.h"
#include "CCEditBox.h"


CliffsAndClouds::CliffsAndClouds():mAnimationManager(NULL)
{

  
}
CliffsAndClouds::~CliffsAndClouds()
{

}
bool CliffsAndClouds::init()
{
    if (CCNode::init())
    {
        
        size=CCDirector::sharedDirector()->getWinSize();
        CCSprite *bg =CCSprite::createWithSpriteFrameName("Scene13_14Background.png");
        
        cloud1=CCSprite::createWithSpriteFrameName("cloud-1.png");
        cloud2=CCSprite::createWithSpriteFrameName("cloud-2.png");
        bg->setPosition(ccp(512*(size.width/1024),(545*(size.height/768))));
      
        cloud1->setPosition(ccp(740*(size.width/1024), (768*(size.height/768)-77*(size.height/768))));
        cloud2->setPosition(ccp(440*(size.width/1024), 768*(size.height/768)-117*(size.height/768)));
        
        bg->setScale(1/0.75);
        cloud1->setScale(1/0.75);
        cloud2->setScale(1/0.75);
        this->addChild(bg,0);
        this->addChild(cloud1,10);
        this->addChild(cloud2,10);
        
        
        float dC1 = 1.0 + (((rand() % 30)*1.0)/10.0);
        
        float disXC1 = 30.0 + ((rand() % 10)*1.0);
        float disYC1 = 12.0 + ((rand() % 6)*1.0);
        
        ccBezierConfig bezierC1;
        bezierC1.controlPoint_1 = ccp(disXC1, 0);
        bezierC1.controlPoint_2 = ccp(disXC1, disYC1);
        bezierC1.endPosition = ccp(0,disYC1);
        ccBezierConfig bezier2C1;
        bezier2C1.controlPoint_1 = ccp(-disXC1, 0);
        bezier2C1.controlPoint_2 = ccp(-disXC1, -disYC1);
        bezier2C1.endPosition = ccp(0,-disYC1);
        
        CCBezierBy *bezierForwardC1 =CCBezierBy::create(dC1, bezierC1);
        CCBezierBy *bezierBackC1 =CCBezierBy::create(dC1, bezier2C1);
        
        CCSequence *seq2c1=CCSequence::create(bezierForwardC1,bezierBackC1,NULL);
        CCRepeatForever *rep=CCRepeatForever::create(seq2c1);
        cloud1->runAction(rep);
        
        
        
        float dC2 = 1.0 + (((rand() % 30)*1.0)/10.0);
        
        float disXC2 = 10.0 + ((rand() % 10)*1.0);
        float disYC2 = 6.0 + ((rand() % 6)*1.0);
        
        ccBezierConfig bezierC2;
        bezierC2.controlPoint_1 = ccp(disXC2, 0);
        bezierC2.controlPoint_2 = ccp(disXC2, disYC2);
        bezierC2.endPosition = ccp(0,disYC2);
        ccBezierConfig bezier2C2;
        bezier2C2.controlPoint_1 = ccp(-disXC2, 0);
        bezier2C2.controlPoint_2 = ccp(-disXC2, -disYC2);
        bezier2C2.endPosition = ccp(0,-disYC2);
        CCBezierBy *bezierForwardC2 =CCBezierBy::create(dC2, bezierC2);
        CCBezierBy *bezierBackC2 =CCBezierBy::create(dC2, bezier2C2);

        CCSequence *seq2C2=CCSequence::create(bezierForwardC2,bezierBackC2,NULL);
        CCRepeatForever *repC2=CCRepeatForever::create(seq2C2);
        cloud2->runAction(repC2);
        return true;
    }
    return false;
}
void CliffsAndClouds::onEnter()
{
    CCNode::onEnter();
}
void CliffsAndClouds::EndEverything()
{
    this->unscheduleAllSelectors();
    cloud1->stopAllActions();
    cloud2->stopAllActions();

}
void CliffsAndClouds::HideClouds()
{
    cloud1->runAction(CCFadeOut::create(0.6f));
    cloud2->runAction(CCFadeOut::create(0.6f));
}
void CliffsAndClouds::ShowClouds()
{
    cloud1->runAction(CCFadeIn::create(0.6f));
    cloud2->runAction(CCFadeIn::create(0.6f));

}
void CliffsAndClouds::SetCloudsInvisible()
{
    cloud1->setOpacity(0);
    cloud2->setOpacity(0);
}
