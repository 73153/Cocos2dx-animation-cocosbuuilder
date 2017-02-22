//
//  TipsLayer.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.

#include "TipsLayer.h"
#include "../SoundManager/SoundManager.h"
#include "../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width
TipsLayer::TipsLayer():current_tips(0)
{
    
}
TipsLayer::~TipsLayer()
{

}
void TipsLayer::onExit()
{
    CCNode::onExit();
}
void TipsLayer::onEnter()
{
    CCNode::onEnter();
}
bool TipsLayer::init()
{
    if (CCNode::init())
    {
        current_tips=1;
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("tips.plist");
        tipsholder=CCSprite::createWithSpriteFrameName("tips_1.png");
        this->addChild(tipsholder,1);
        
        tips_pointer_1=CCSprite::create("tips_arrow.png");
        this->addChild(tips_pointer_1);
        tips_pointer_2=CCSprite::create("tips_arrow.png");
        this->addChild(tips_pointer_2);
        tipsholder->setOpacity(0);
        tips_pointer_1->setOpacity(0);
        tips_pointer_2->setOpacity(0);
        
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
                break;
            case 2:
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    tips_pointer_1->setScale(0.6);
                    tips_pointer_2->setScale(0.6);
                }
                else
                {
                }
                break;
            case 3:
                tips_pointer_1->setScale(0.7);
                break;
            default:
                
                break;
        }

        return true;
    }
    return false;
}
void  TipsLayer::start_tips()
{
//    show_tips(current_tips);
    this->runAction(CCSequence::create(CCDelayTime::create(1.0),CCCallFunc::create(this, callfunc_selector(TipsLayer::show_tips)),NULL));
}
void TipsLayer::show_tips(int tips_id)
{
    GameManager::sharedGameManager()->get_header()->setis_tips_showing(true);
    show_tip_1();
    return;
    switch (tips_id)
    {
        case 1:
           
            break;
        case 2:
            show_tip_2();
            break;
        case 3:
            show_tip_3();
            break;
        case 4:
            show_tip_4();
            break;
        default:
            break;
    }
}
void  TipsLayer::show_tip_1()
{
    
    tipsholder->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("tips_1.png"));
    tipsholder->setPosition(ccp(screen_width/2, 12*(screen_height/100)+tipsholder->getContentSize().height/2));

    CCPoint p=GameManager::sharedGameManager()->get_header()->getlblpoints()->getPosition();
    tips_pointer_1->setAnchorPoint(ccp(0.5, 1));
    tips_pointer_1->setPosition(p);
       tips_pointer_1->setRotation(-45);

    
  
    CCTargetedAction *t1 = CCTargetedAction::create(tipsholder, CCFadeIn::create(1.0));
    CCTargetedAction *t2 = CCTargetedAction::create(tips_pointer_1, CCFadeIn::create(1.0));
    CCTargetedAction *t3 = CCTargetedAction::create(tipsholder, CCFadeOut::create(1.0));
    CCTargetedAction *t4 = CCTargetedAction::create(tips_pointer_1, CCFadeOut::create(1.0));

    CCSequence* seq = (CCSequence*)CCSequence::create(t1, t2,CCDelayTime::create(3.2),t4,t3,CCDelayTime::create(0.2),CCCallFunc::create(this, callfunc_selector(TipsLayer::show_tip_2)), NULL);
    this->runAction(seq);
}
void  TipsLayer::show_tip_2()
{
    tipsholder->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("tips_2.png"));
    tips_pointer_1->setAnchorPoint(ccp(0.5, 1));
 
    CCPoint p=GameManager::sharedGameManager()->get_header()->getstore()->getPosition();
    CCSize size=GameManager::sharedGameManager()->get_header()->getstore()->getContentSize();
    CCPoint pstore=CCPointMake(p.x+size.width/2, p.y-size.height/2);
    tips_pointer_1->setPosition(pstore);
        tips_pointer_1->setRotation(30);
    CCTargetedAction *t1 = CCTargetedAction::create(tipsholder, CCFadeIn::create(1.0));
    CCTargetedAction *t2 = CCTargetedAction::create(tips_pointer_1, CCFadeIn::create(1.0));
    CCTargetedAction *t3 = CCTargetedAction::create(tipsholder, CCFadeOut::create(1.0));
    CCTargetedAction *t4 = CCTargetedAction::create(tips_pointer_1, CCFadeOut::create(1.0));
    CCSequence* seq = (CCSequence*)CCSequence::create(t1, t2,CCDelayTime::create(3.2),t4,t3,CCCallFunc::create(this, callfunc_selector(TipsLayer::show_tip_3)), NULL);
    this->runAction(seq);
}
void  TipsLayer::show_tip_3()
{
    tips_pointer_1->setOpacity(0);
    tips_pointer_2->setOpacity(0);
    tipsholder->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("tips_3.png"));
    tipsholder->setPosition(ccp(screen_width-tipsholder->getContentSize().width/3,tipsholder->getPositionY()));
    CCTargetedAction *t1 = CCTargetedAction::create(tipsholder, CCFadeIn::create(1.0));
     CCTargetedAction *t2 = CCTargetedAction::create(tipsholder, CCFadeOut::create(1.0));
    CCSequence* seq = (CCSequence*)CCSequence::create(t1,CCDelayTime::create(3.8),t2,CCCallFunc::create(this, callfunc_selector(TipsLayer::show_tip_4)),NULL);
    this->runAction(seq);
    
}
void  TipsLayer::show_tip_4()
{
    tipsholder->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("tips_4.png"));
    tipsholder->setPosition(ccp(screen_width/2-tipsholder->getContentSize().width/4, 12*(screen_height/100)+tipsholder->getContentSize().height/4));
    
    tips_pointer_1->setAnchorPoint(ccp(0.5, 1));
    CCPoint p=GameManager::sharedGameManager()->get_header()->getlbl_current_level()->getPosition();
    tips_pointer_1->setPosition(p);
    tips_pointer_1->setRotation(-15);

    tips_pointer_2->setAnchorPoint(ccp(0.5, 1));
    CCPoint p1=GameManager::sharedGameManager()->get_header()->getlbl_ark_tap()->getPosition();
    tips_pointer_2->setPosition(p1);
    tips_pointer_2->setRotation(15);
    
    CCTargetedAction *t1 = CCTargetedAction::create(tipsholder, CCFadeIn::create(1.0));
    CCTargetedAction *t2 = CCTargetedAction::create(tips_pointer_1, CCFadeIn::create(1.0));
    CCTargetedAction *t3 = CCTargetedAction::create(tips_pointer_2, CCFadeIn::create(1.0));
    
    CCTargetedAction *t4 = CCTargetedAction::create(tips_pointer_1, CCFadeOut::create(1.0));
    CCTargetedAction *t5 = CCTargetedAction::create(tips_pointer_2, CCFadeOut::create(1.0));
    CCTargetedAction *t6 = CCTargetedAction::create(tipsholder, CCFadeOut::create(1.0));

    CCSequence* seq = (CCSequence*)CCSequence::create(CCDelayTime::create(0.3),t1, t2,t3,CCDelayTime::create(2.8),t4,t5,t6,CCCallFunc::create(this, callfunc_selector(TipsLayer::completed_tips)), NULL);
    this->runAction(seq);
}
void TipsLayer::completed_tips()
{
    GameManager::sharedGameManager()->get_header()->setis_tips_showing(false);
}