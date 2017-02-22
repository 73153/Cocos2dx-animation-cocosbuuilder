//
//  BranchNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "BranchNode.h"
#include "../../SoundManager/SoundManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
BranchNode::BranchNode():image_(NULL),shouldBeRemoved_1(false)
{
}
BranchNode::~BranchNode()
{

}
void BranchNode::onEnter()
{
    CCNode::onEnter();
}
BranchNode* BranchNode::create(branchType newType)
{
    BranchNode* ret = new BranchNode();
    if (ret)
    {
        if (ret->initBranchNode(newType))
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
bool BranchNode::initBranchNode(branchType newType)
{
    if (BranchNode::init())
    {
        this->type_ = newType;
        switch (this->type_)
        {
            case green:
                this->image_ =CCSprite::createWithSpriteFrameName("Leafbranch_sm.png");
                break;
            case red:
                this->image_ =CCSprite::createWithSpriteFrameName("redLeafbranch_sm.png");
                break;
            case cloud:
            {
                this->image_ =CCSprite::createWithSpriteFrameName("CLOUD-4.png");
                thunderCloudFrames=CCArray::create();
                CCSpriteFrameCache *frame= CCSpriteFrameCache::sharedSpriteFrameCache();
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING.png"));
                
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING-EXTREME.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING-EXTREME.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING-EXTREME.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4-LIGHTNING.png"));
                thunderCloudFrames->addObject(frame->spriteFrameByName("CLOUD-4.png"));
                float randTime = (rand()%1000+1000.0f)/1000.0f;
                

                this->schedule(schedule_selector(BranchNode::Rumble),randTime);
                
            }
                break;
            default:
                this->image_ = CCSprite::createWithSpriteFrameName("Leafbranch_sm.png");
                break;
        }
        this->addChild(this->image_);
        
        
        return true;
    }
    return false;
}
bool BranchNode::isPointOnImage(CCPoint point)
{
    if (GameManager::sharedGameManager()->isNodeAtPoint(this->image_, point))
    {
    //    NSLog(@"positionX:%0.4f  positionY:%0.4f  --- imagePosX:%0.4f  imagePosY:%0.4f",point.x, point.y, self.image.position.x,self.image.position.y);
    }
    return GameManager::sharedGameManager()->isNodeAtPoint(this->image_, point);
}
void BranchNode::setToRemove()
{
    this->shouldBeRemoved_1=true;
    this->unscheduleAllSelectors();

}
void BranchNode::Rumble(float dt)
{
    this->unschedule(schedule_selector(BranchNode::Rumble));
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/raincloud sound fx.mp3",false);
    float randTime = (rand()%1000+5000.0f)/1000.0f;
//    CCAnimation* animation = CCAnimation::createWithSpriteFrames(thunderCloudFrames);
//    animation->setRestoreOriginalFrame(true);
//    animation->setDelayPerUnit(0.3/11);
//    CCAnimate* action = CCAnimate::create(animation);
//    action->setDuration(0.3f);
//    this->image_->runAction(action);
    this->schedule(schedule_selector(BranchNode::Rumble),randTime);
    
}