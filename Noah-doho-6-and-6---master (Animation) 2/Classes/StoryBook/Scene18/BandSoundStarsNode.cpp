//
//  BandSoundStarsNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "BandSoundStarsNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

BandSoundStarsNode::BandSoundStarsNode():mAnimationManager(NULL),starType(NULL),sound(0)
{

  
}
BandSoundStarsNode* BandSoundStarsNode::create(CCString *type, bool draggable)
{
    BandSoundStarsNode* ret = new BandSoundStarsNode();
    if (ret)
    {
        if (ret->initSoundStarsNode(type,draggable))
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
bool BandSoundStarsNode::initSoundStarsNode(CCString *type, bool draggable)
{
    if (BandSoundStarsNode::init())
    {
        starType =CCString::create(type->getCString());
        starType->retain();
		imageOnSound = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("Scene16/COLORFUL_STAR_%s.png",starType->getCString())->getCString());
		imageNormal = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("Scene16/STAR_%s.png",starType->getCString())->getCString());
		this->addChild(imageNormal,5);
        this->addChild(imageOnSound,20);
        imageOnSound->setOpacity(0);
        imageOnSound->setPosition(CCPointZero);
        imageNormal->setPosition(CCPointZero);
        return true;
    }
    return false;
}
BandSoundStarsNode::~BandSoundStarsNode()
{

}
void BandSoundStarsNode::onEnter()
{

    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void BandSoundStarsNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN BandSoundStarsNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler BandSoundStarsNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler BandSoundStarsNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool BandSoundStarsNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
   
    return false;
}
bool BandSoundStarsNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void BandSoundStarsNode::SetNotIsPlaying()
{
    isPlaying=false;
}
bool BandSoundStarsNode::TestForTouch(CCPoint point)
{
    if (GameManager::sharedGameManager()->isNodeAtPoint(imageNormal, point))
    {
        isPlaying = true;
        isDrag = true;
		whereTouch=ccpSub(imageNormal->getPosition(), point);
        float time = 0.2f* (255-imageOnSound->getOpacity())/255;
        imageOnSound->stopAllActions();
        imageNormal->stopAllActions();

        CCSpawn *spwn=CCSpawn::create(CCFadeIn::create(time),CCScaleTo::create(time,1.1),NULL);
        CCSpawn *spwn1=CCSpawn::create(CCFadeOut::create(0.2f),CCScaleTo::create(0.2f,1.0),NULL);
        CCCallFunc *fn=CCCallFunc::create(this, callfunc_selector(BandSoundStarsNode::SetNotIsPlaying));
        CCSequence *sq=CCSequence::create(spwn,CCDelayTime::create(0.8f),spwn1,fn,NULL);
        
        imageOnSound->runAction(sq);
        imageNormal->runAction(CCSequence::create(CCScaleTo::create(time, 1,1),CCDelayTime::create(0.8f),CCScaleTo::create(0.2f, 1.0f),NULL));
        CCString *str;
            str=CCString::createWithFormat("Sound/Scene 17/StlDm%s.mp3",starType->getCString());
        CCLOG("%s",str->getCString());
        if (SoundManager::sharedSoundManager()->isEffectPlaying(sound))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(sound);
          sound=SoundManager::sharedSoundManager()->playSoundEffect(str->getCString(),false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(sound);
            sound=SoundManager::sharedSoundManager()->playSoundEffect(str->getCString(),false);
        }
        
        return true;
    }
    return false;
}
void BandSoundStarsNode::touchMoved(CCPoint point,CCSprite*moonImage)
{

}
void BandSoundStarsNode::touchEnded()
{
    isDrag = false;

}