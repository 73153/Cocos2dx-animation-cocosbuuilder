//
//  TapToFlapNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "TapToFlapNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
TapToFlapNode::TapToFlapNode()
{

  
}
TapToFlapNode::~TapToFlapNode()
{

}
void TapToFlapNode::onEnter()
{

    CCSize screenSize =CCDirector::sharedDirector()->getWinSize();
    title=CCSprite::createWithSpriteFrameName("tap to flap graphic.png");
    hand=CCSprite::createWithSpriteFrameName("INSTRUCTIONAL-TAP-WARP_1.png");
    title->setPosition(ccp(826*(screenSize.width/1024)+title->getContentSize().width/2, screenSize.height-(308*(screenSize.height/768))-title->getContentSize().height/2));
    
    hand->setPosition(ccp(719*(screenSize.width/1024)+hand->getContentSize().width/2, screenSize.height-(358*(screenSize.height/768))-hand->getContentSize().height/2));

    this->addChild(title,1);
    this->addChild(hand,1);
    title->setOpacity(0);
    hand->setOpacity(0);
    
    CCNode::onEnter();
}
void TapToFlapNode::HideAll()
{
    title->runAction(CCFadeOut::create(0.2f));
    hand->runAction(CCFadeOut::create(0.2f));
}
void TapToFlapNode::AppearAndAnimate()
{
    title->runAction(CCFadeIn::create(0.2f));
   CCAnimation* animation = CCAnimation::create();
   animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("INSTRUCTIONAL-TAP-WARP_1.png"));
   animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("INSTRUCTIONAL-TAP-WARP_2.png"));
   animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("INSTRUCTIONAL-TAP-WARP_3.png"));
   animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("INSTRUCTIONAL-TAP-WARP_2.png"));
    animation->setDelayPerUnit(0.6f/ 7);
    animation->setRestoreOriginalFrame(true);
    CCAnimate* action = CCAnimate::create(animation);
    action->setDuration(0.3f);
    hand->runAction(CCSequence::create(CCFadeIn::create(0.2f),CCRepeat::create(action, 10),CCCallFunc::create(this,callfunc_selector(TapToFlapNode::HideAll)),NULL));
 //   slingShotBand->runAction(CCSequence::create(action,NULL));
 
    
    
    
    
    
   
}
void TapToFlapNode::Stop()
{
    title->stopAllActions();
    hand->stopAllActions();
}
