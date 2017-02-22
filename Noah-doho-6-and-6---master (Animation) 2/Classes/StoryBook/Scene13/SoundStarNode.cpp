//
//  SoundStarNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "SoundStarNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
SoundStarNode::SoundStarNode():mAnimationManager(NULL)
{
    
    
}
SoundStarNode* SoundStarNode::create(CCString *type,bool draggable)
{
    SoundStarNode* ret = new SoundStarNode();
    if (ret)
    {
        if (ret->initSoundStarNode(type,draggable))
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
bool SoundStarNode::initSoundStarNode(CCString *type,bool draggable)
{
    if (SoundStarNode::init())
    {
        starType =CCString::create(type->getCString());
        starType->retain();
        imageOnSound = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("COLORFUL_STAR_%s.png",starType->getCString())->getCString());
        imageNormal =
        CCSprite::createWithSpriteFrameName(CCString::createWithFormat("STAR_%s.png",starType->getCString())->getCString());
        
        this->addChild(imageOnSound,20);
        this->addChild(imageNormal,5);
        isPlaying = false;
        isDrag = false;
        
        imageOnSound->setOpacity(0);
        imageOnSound->setPosition(ccp(0,0));
        imageNormal->setPosition(ccp(0,0));
        return true;
    }
    return false;
}
SoundStarNode::~SoundStarNode()
{
    
}
void SoundStarNode::onEnter()
{
    CCNode::onEnter();
}
void SoundStarNode::SetNotIsPlaying()
{
    isPlaying = false;
}
bool  SoundStarNode::TestForTouch(CCPoint point)
{
    //point = ccpSub(self.position, point);
    if (GameManager::sharedGameManager()->isNodeAtPoint(imageNormal,point))
    {
        isPlaying = true;
        isDrag = true;
        //point = ccpSub(point,this->getPosition());
		//whereTouch=point;//ccpSub(imageNormal->getPosition(), point);
        float time = 0.2f* ((255-imageOnSound->getOpacity())/255);
        imageOnSound->stopAllActions();
        imageNormal->stopAllActions();
        imageOnSound->runAction(CCSequence::create(CCSpawn::create(CCFadeIn::create(time),
                                                                   CCScaleTo::create(time, 1.1f),CCDelayTime::create(0.8f),NULL),
                                                   CCSpawn::create(
                                                                   CCFadeOut::create(0.2f),NULL),
                                                   CCScaleTo::create(0.2f, 1.0f),CCCallFunc::create(this, callfunc_selector(SoundStarNode::SetNotIsPlaying)),NULL));
        imageNormal->runAction(CCSequence::create(CCScaleTo::create(time, 1.1f),CCDelayTime::create(0.8f),CCScaleTo::create(0.2f, 1.0f),NULL));
        TargetPlatform platForm = CCApplication::sharedApplication()->getTargetPlatform();
        
        CCString *str;
        str=CCString::createWithFormat("Sound/Scene 17/StlDm%s.mp3",starType->getCString());
        CCLOG("%s",str->getCString());
     
        
        if (GameManager::sharedGameManager()->GetAchievmentIsActive(GuitarStarsAchievmentID))
        {
            if (SoundManager::sharedSoundManager()->isEffectPlaying(star_sound))
            {
                SoundManager::sharedSoundManager()->stopSoundEffect(star_sound);

                if(platForm==kTargetIpad || platForm==kTargetIphone)
                {
                    star_sound=SoundManager::sharedSoundManager()->playSoundEffect(str->getCString(),false);
                }
                else
                {
                    star_sound= SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 14/acoustic_%s.m4a",starType->getCString())->getCString(), false);
                }
                
            }
        }
       
            SoundManager::sharedSoundManager()->stopSoundEffect(star_sound);
            
            if(platForm==kTargetIpad || platForm==kTargetIphone)
            {
                star_sound=SoundManager::sharedSoundManager()->playSoundEffect(str->getCString(),false);
            }
            else
            {
                star_sound= SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 14/acoustic_%s.m4a",starType->getCString())->getCString(), false);
            }

     
        return true;
    }
    return false;
}
void  SoundStarNode::touchMoved(CCPoint point,CCSprite* moonImage)
{
    if (isDrag)
    {
        //point = ccpSub(point,this->getPosition());
        if (moonImage->boundingBox().intersectsRect(imageNormal->boundingBox()))
        {
            return;
        }
        point=this->convertToNodeSpace(point);
        //        imageNormal->setPosition(ccpAdd(point,whereTouch));
        //        imageOnSound->setPosition(ccpAdd(point,whereTouch));
        imageNormal->setPosition(point);
        imageOnSound->setPosition(point);
    }
}
void  SoundStarNode::touchEnded()
{
    isDrag = false;
}