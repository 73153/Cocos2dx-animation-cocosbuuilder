//
//  BranchCloudNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "BranchCloudNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
BranchCloudNode::BranchCloudNode()
{

  
}
BranchCloudNode::~BranchCloudNode()
{

}
BranchCloudNode* BranchCloudNode::create(branchType newType)
{
    BranchCloudNode* ret = new BranchCloudNode();
    if (ret)
    {
        if (ret->initBranchCloud(newType))
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
bool BranchCloudNode::initBranchCloud(branchType newType)
{
    if (BranchNode::init())
    {
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
        this->schedule(schedule_selector(BranchCloudNode::Rumble),randTime);
        return true;
    }
    return false;
}
void BranchCloudNode::onEnter()
{
    CCNode::onEnter();
}
void BranchCloudNode::Rumble(float dt)
{
    this->unschedule(schedule_selector(BranchCloudNode::Rumble));
    //CCLog("cloud sound");
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/raincloud sound fx.mp3",false);
    float randTime = (rand()%1000+5000.0f)/1000.0f;
    this->schedule(schedule_selector(BranchCloudNode::Rumble),randTime);

}