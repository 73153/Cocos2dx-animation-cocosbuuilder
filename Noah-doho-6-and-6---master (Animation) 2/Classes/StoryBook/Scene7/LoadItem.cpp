//
//  LoadItem.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "LoadItem.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define timeForLoop1 20.0f
#define timeForRotation 0.2f
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width
#define YOffsetItem 40*(WINHEIGHT/768)
LoadItem::LoadItem()
{

}
LoadItem* LoadItem::create(CCString *name)
{
    LoadItem* ret = new LoadItem();
    if (ret)
    {
        if (ret->initLoadItem(name))
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
bool LoadItem::initLoadItem(CCString *name)
{
    if (CCNode::init())
    {
        image =CCSprite::createWithSpriteFrameName(name->getCString());
        CCRepeatForever  *rep_tower=CCRepeatForever::create(CCSequence::create(CCEaseOut::create(CCMoveBy::create(timeForRotation, ccp(0,YOffsetItem)), 2.0),CCEaseIn::create(CCMoveBy::create(timeForRotation, ccp(0,-YOffsetItem)), 2.0),CCEaseOut::create(CCMoveBy::create(timeForRotation, ccp(0,-YOffsetItem)), 2.0),CCEaseIn::create(CCMoveBy::create(timeForRotation, ccp(0,YOffsetItem)), 2.0),NULL));
        rep_tower->retain();
        CCRepeatForever  *rep_rotete=CCRepeatForever::create(CCRotateBy::create(6.0f, 360));
        rep_rotete->retain();
        image->runAction(rep_tower);
        image->runAction(rep_rotete);
        this->addChild(image);
        return true;
        
    }
    return false;
}
LoadItem::~LoadItem()
{
    
}
void LoadItem::onEnter()
{
   // bacground1->setOpacity(0);
    CCNode::onEnter();
}
void LoadItem::onExit()
{
//    this->stopAllActions();
//    this->unscheduleAllSelectors();
//    this->removeAllChildrenWithCleanup(true);
}

