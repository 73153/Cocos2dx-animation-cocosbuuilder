//
//  DreamFloadBack.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "DreamFloadBack.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define timeForLoop1 20.0f
DreamFloadBack::DreamFloadBack():mAnimationManager(NULL)
{

}
DreamFloadBack::~DreamFloadBack()
{
    
}
void DreamFloadBack::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    CCNode::onExit();
}
void DreamFloadBack::onEnter()
{
    CCLog("DreamFloadBack");
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene7Backgrounds_android.plist", "Scene7Backgrounds.pvr.ccz");
    #elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
       CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene7Backgrounds.plist", "Scene7Backgrounds.pvr.gz");
    #endif
    

    screenSize = CCDirector::sharedDirector()->getWinSize();
    bacground1 =CCSprite::createWithSpriteFrameName("scene7ScrollingBackground1.png");
    bacground2 =CCSprite::createWithSpriteFrameName("scene7ScrollingBackground2.png");
    bacground1->setScaleY(657.0f/435.0f);
    bacground2->setScaleY( 657.0f/435.0f);
    bacground1->setScaleX(1406.0f/1400.0f);
    posY2 =screenSize.height -( bacground1->getContentSize().height/2*bacground1->getScaleY());
    bacground1->setPosition(ccp(screenSize.width/2 + bacground1->getContentSize().width/2,posY2));
    bacground2->setPosition(ccp(screenSize.width/2 - bacground1->getContentSize().width/2,posY2));
    this->addChild(bacground1,1);
    this->addChild(bacground2,2);
   // bacground1->setOpacity(0);
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void DreamFloadBack::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN DreamFloadBack::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler DreamFloadBack::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler DreamFloadBack::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool DreamFloadBack::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool DreamFloadBack::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void DreamFloadBack::StartRotation()
{
    float totalMov = screenSize.width + bacground1->getContentSize().width;
    float waintingMov = bacground1->getContentSize().width - screenSize.width;
    float finalPos= screenSize.width + bacground1->getContentSize().width/2;
    float startPos1 = screenSize.width/2 + bacground1->getContentSize().width/2;
    float startPos2 = screenSize.width/2 - bacground1->getContentSize().width/2;
    float waintingTime1 =(timeForLoop1*waintingMov)/totalMov;
    float movment1 = timeForLoop1*(finalPos - startPos1)/totalMov;
    float movment2 = timeForLoop1*(finalPos - startPos2)/totalMov;
    bacground1->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(movment1, ccp(finalPos, posY2)),CCMoveTo::create(0,ccp(-bacground1->getContentSize().width/2, posY2)),CCDelayTime::create(waintingTime1),CCMoveTo::create(timeForLoop1-movment1, ccp(startPos1, posY2)),NULL)));
    bacground2->runAction(CCRepeatForever::create(CCSequence::create(CCMoveTo::create(movment2, ccp(finalPos, posY2)),CCMoveTo::create(0,ccp(-bacground1->getContentSize().width/2, posY2)),CCDelayTime::create(waintingTime1),CCMoveTo::create(timeForLoop1-movment2, ccp(startPos2, posY2)),NULL)));
}
void DreamFloadBack::ResetBackground()
{
    bacground1->stopAllActions();
    bacground2->stopAllActions();
    bacground1->setPosition(ccp(screenSize.width/2 + bacground1->getContentSize().width/2,posY2));
    bacground2->setPosition(ccp(screenSize.width/2 - bacground1->getContentSize().width/2,posY2));
}

