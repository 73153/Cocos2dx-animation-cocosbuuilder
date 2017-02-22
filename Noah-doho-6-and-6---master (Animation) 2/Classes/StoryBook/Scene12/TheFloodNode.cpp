//
//  TheFloodNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "TheFloodNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define LightningOpacity 200
TheFloodNode::TheFloodNode()
{
    //CCLog("Header Layer called");
}
TheFloodNode::~TheFloodNode()
{

}
void TheFloodNode::onEnter()
{
    CCNode::onEnter();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            CCLOG("Android fetch");
            image1 = CCSprite::create("RISING-WATER-1.png");
            image2 = CCSprite::create("RISING-WATER-1.png");
            image1->setScale(4.0);
            image2->setScaleX(-4.4);
            image2->setScaleY(4.0);
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if (CCDirector::sharedDirector()->getWinSize().width==960)
        {
            image1 = CCSprite::create("RISING-WATER-1.png");
            image2 = CCSprite::create("RISING-WATER-1.png");
            image1->setScale(4.0);
            image2->setScaleX(-4.4);
            image2->setScaleY(4.0);
        }
        else
        {
            image1 = CCSprite::create("RISING-WATER.png");
            image2 = CCSprite::create("RISING-WATER.png");
            image1->setScale(2.0);
            image2->setScaleX(-2.02);
            image2->setScaleY(2.0);
        }
    #endif
      CCLOG("RainCloudNode::TheFloodNode::completed");
    winsize=CCDirector::sharedDirector()->getWinSize();
    if (image1||image2)
    {
    width = image1->getContentSize().width * image1->getScaleX();
    height = image1->getContentSize().height * image1->getScaleY();
    image1->setPosition(ccp(winsize.width - width/2,-height/2));
    image2->setPosition(ccp(winsize.width - 3*width/2, -height/2));
    this->addChild(image1,10);
    this->addChild(image2,10);
    image1->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(4.0f, ccp(winsize.width+width/2,-height/2 )),CCMoveTo::create(0.0f, ccp(winsize.width-3*width/2,-height/2 )),CCMoveTo::create(4.0f,ccp(winsize.width-width/2, -height/2)),NULL)));
    image2->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(4.0f, ccp(winsize.width-width/2,-height/2 )),CCMoveTo::create(4.0f, ccp(winsize.width+width/2-100,-height/2 )),CCMoveTo::create(0.0f,ccp(winsize.width-3*width/2, -height/2)),NULL)));
    }

}
void TheFloodNode::flood_came()
{
    CCLOG("TheFloodNode::flood_came");
    image1->setScale(2.0f);
    image2->setScaleX(-2.02);
    image2->setScaleY(2.0);
    width = image1->getContentSize().width * image1->getScaleX();
    height = image1->getContentSize().height * image1->getScaleY();
    image1->setPosition(ccp(1024-width/2, -height/2));
    image2->setPosition(ccp(1024-3*width/2, -height/2));
    image1->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(4.0f, ccp(1024+ width/2,-height/2)),CCMoveTo::create(0.0f, ccp(1024-3*width/2,-height/2)),CCMoveTo::create(4.0f, ccp(1024-width/2,-height/2)),NULL)));
    
    image2->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(4.0f, ccp(1024 - width/2,-height/2)),CCMoveTo::create(4.0f, ccp(1024 + width/2,-height/2)),CCMoveTo::create(0.0f, ccp(1024 - 3*width/2,-height/2)),NULL)));
}