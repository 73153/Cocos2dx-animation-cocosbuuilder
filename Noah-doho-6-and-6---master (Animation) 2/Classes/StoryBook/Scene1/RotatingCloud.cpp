//
//  RotatingCloud.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "RotatingCloud.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define RandTimeBetweenLightings 251
#define RandTimeAfterLightings 51
#define RotatingTime 18.0f
#define ScaleIncreasingSpeed 0.28;
#define OffsetIncreasingSpeed 45.0f;
#define RotatingCloudFinishScale 4.2f
#define RotatingCloudStartScale 0.8f
#define RotatingCloudFinishScale 4.2f
#define FadeOutgRotatingCloudTime 0.8f
#define FadeIngRotatingCloudTime 0.4f
#define TotalTimeRotatingCloudAction 12.0f
#define FinishingRotatingCloudOffset 540.0f
RotatingCloud::RotatingCloud()
{

}
RotatingCloud::RotatingCloud(float scale,float rotation,float offset)
{
    // Set to autorelease
    startOffset = offset;
    hasFinishedRotating = false;
    this->setRotation(rotation);

    cloud1=CCSprite::createWithSpriteFrameName("DARK-CLOUD.png");
    cloud2=CCSprite::createWithSpriteFrameName("DARK-CLOUD.png");
    cloud3=CCSprite::createWithSpriteFrameName("DARK-CLOUD.png");
    cloud4=CCSprite::createWithSpriteFrameName("DARK-CLOUD.png");
    cloud1->setPosition(CCPoint(-offset,0));
    cloud2->setPosition(CCPoint(0,offset));
    cloud3->setPosition(CCPoint(offset,0));
    cloud4->setPosition(CCPoint(0,-offset));
    
    cloud1->setScale(scale);
    cloud2->setScale(scale);
    cloud3->setScale(scale);
    cloud4->setScale(scale);
    
    cloud1->setRotation(0);
    cloud2->setRotation(90);
    cloud3->setRotation(180);
    cloud4->setRotation(270);

    whiteCloud1=CCSprite::createWithSpriteFrameName("DARK-LIGHTNING-WHITE.png");
    whiteCloud2=CCSprite::createWithSpriteFrameName("DARK-LIGHTNING-WHITE.png");
    whiteCloud3=CCSprite::createWithSpriteFrameName("DARK-LIGHTNING-WHITE.png");
    whiteCloud4=CCSprite::createWithSpriteFrameName("DARK-LIGHTNING-WHITE.png");
    
    whiteCloud1->setPosition(CCPoint(-offset,0));
    whiteCloud2->setPosition(CCPoint(0,offset));
    whiteCloud3->setPosition(CCPoint(offset,0));
    whiteCloud4->setPosition(CCPoint(0,-offset));
    
    whiteCloud1->setScale(scale);
    whiteCloud2->setScale(scale);
    whiteCloud3->setScale(scale);
    whiteCloud4->setScale(scale);
    
    whiteCloud1->setRotation(0);
    whiteCloud2->setRotation(90);
    whiteCloud3->setRotation(180);
    whiteCloud4->setRotation(270);
    
    whiteCloud1->setOpacity(0);
    whiteCloud2->setOpacity(0);
    whiteCloud3->setOpacity(0);
    whiteCloud4->setOpacity(0);
    //Setting the z Scale is very Important!
    this->addChild(cloud1);
    this->addChild(cloud2);
    this->addChild(cloud3);
    this->addChild(cloud4);
    this->addChild(whiteCloud1);
    this->addChild(whiteCloud2);
    this->addChild(whiteCloud3);
    this->addChild(whiteCloud4);
    this->runAction(CCRepeatForever::create(CCRotateBy::create(RotatingTime, 360.0f)));
    timeToFinishCloudAction = TotalTimeRotatingCloudAction * (FinishingRotatingCloudOffset-offset)/FinishingRotatingCloudOffset;
    float timeToLightning = (rand()%RandTimeBetweenLightings + rand()%RandTimeBetweenLightings + rand()%RandTimeBetweenLightings + RandTimeBetweenLightings )/2000.0f;
    timeToLightning=0.50f;
    this->schedule(schedule_selector(RotatingCloud::ShowLightning), timeToLightning);
    cloudActionTimer = 0.0f;
    this->schedule(schedule_selector(RotatingCloud::tick));
  
}
RotatingCloud::~RotatingCloud()
{

}
void RotatingCloud::onEnter()
{
    CCNode::onEnter();
}
void RotatingCloud::onExit()
{
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void RotatingCloud::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN RotatingCloud::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler RotatingCloud::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler RotatingCloud::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool RotatingCloud::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool RotatingCloud::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void RotatingCloud::RestartCloudMotion()
{

    hasFinishedRotating = true;
    cloud1->stopAllActions();
    cloud2->stopAllActions();
    cloud3->stopAllActions();
    cloud4->stopAllActions();
}
void RotatingCloud::tick(float dt)
{
    float offsetDif = dt*OffsetIncreasingSpeed;
    float scale1=cloud1->getScale()+dt*ScaleIncreasingSpeed;
    cloud1->setScale(scale1);
    scale1=cloud2->getScale()+dt* ScaleIncreasingSpeed;
    cloud2->setScale(scale1);
    scale1=cloud3->getScale()+dt* ScaleIncreasingSpeed;
    cloud3->setScale(scale1);
    scale1=cloud4->getScale()+dt* ScaleIncreasingSpeed;
    cloud4->setScale(scale1);
    scale1=whiteCloud1->getScale()+dt* ScaleIncreasingSpeed;
    whiteCloud1->setScale(scale1);
    scale1=whiteCloud2->getScale()+dt* ScaleIncreasingSpeed;
    whiteCloud2->setScale(scale1);
    scale1=whiteCloud3->getScale()+dt* ScaleIncreasingSpeed;
    whiteCloud3->setScale(scale1);
    scale1=whiteCloud4->getScale()+dt* ScaleIncreasingSpeed;
    whiteCloud4->setScale(scale1);
    
                          
    cloud1->setPosition(ccpAdd(cloud1->getPosition(),ccp(-offsetDif,0)));
    cloud2->setPosition(ccpAdd(cloud2->getPosition(),ccp(0,offsetDif)));
    cloud3->setPosition(ccpAdd(cloud3->getPosition(),ccp(offsetDif,0)));
    cloud4->setPosition(ccpAdd(cloud4->getPosition(),ccp(0,-offsetDif)));
    whiteCloud1->setPosition(ccpAdd(whiteCloud1->getPosition(),ccp(-offsetDif,0)));
    whiteCloud2->setPosition(ccpAdd(whiteCloud2->getPosition(),ccp(0,offsetDif)));
    whiteCloud3->setPosition(ccpAdd(whiteCloud3->getPosition(),ccp(offsetDif,0)));
    whiteCloud4->setPosition(ccpAdd(whiteCloud4->getPosition(),ccp(0,-offsetDif)));
    
    if (cloud1->getScale() >= RotatingCloudFinishScale)
    {
        this->unschedule(schedule_selector(RotatingCloud::tick));
        hasFinishedRotating = true;
    }
}
void RotatingCloud::ResetScaleAndPosition()
{
    hasFinishedRotating = false;
    cloud1->setScale(RotatingCloudStartScale);
    cloud2->setScale( RotatingCloudStartScale);
    cloud3->setScale(RotatingCloudStartScale);
    cloud4->setScale(RotatingCloudStartScale);
    whiteCloud1->setScale(RotatingCloudStartScale);
    whiteCloud2->setScale(RotatingCloudStartScale);
    whiteCloud3->setScale(RotatingCloudStartScale);
    whiteCloud4->setScale(RotatingCloudStartScale);
    
    cloud1->setPosition(ccp(0,0));
    cloud2->setPosition(ccp(0,0));
    cloud3->setPosition(ccp(0,0));
    cloud4->setPosition(ccp(0,0));
    whiteCloud1->setPosition(ccp(0,0));
    whiteCloud2->setPosition(ccp(0,0));
    whiteCloud3->setPosition(ccp(0,0));
    whiteCloud4->setPosition(ccp(0,0));
    
    cloud1->runAction(CCFadeIn::create(FadeIngRotatingCloudTime));
    cloud2->runAction(CCFadeIn::create(FadeIngRotatingCloudTime));
    cloud3->runAction(CCFadeIn::create(FadeIngRotatingCloudTime));
    cloud4->runAction(CCFadeIn::create(FadeIngRotatingCloudTime));
    
    timeToFinishCloudAction = TotalTimeRotatingCloudAction;
    cloudActionTimer = 0.0f;
    this->schedule(schedule_selector(RotatingCloud::tick));
}
void RotatingCloud::ShowLightning(float dt)
{
    int randCloud1 = rand()%2;
    int randCloud2 = rand()%2;
    int randCloud3 = rand()%2;
    int randCloud4 = rand()%2;
    
    float timeToUnightning;
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
         timeToUnightning= (rand()%RandTimeAfterLightings + rand()%RandTimeAfterLightings +rand()%RandTimeAfterLightings )/1000.0f;
    }
    else
     timeToUnightning= (rand()%RandTimeAfterLightings + rand()%RandTimeAfterLightings +rand()%RandTimeAfterLightings )/1000.0f;
    if (randCloud1==1)
    {
        cloud1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
       whiteCloud1->runAction(CCSequence::create(CCFadeIn::create(timeToUnightning/2),CCFadeOut::create(timeToUnightning),NULL));
    }
    if (randCloud2 == 1)
    {
        cloud2->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
        whiteCloud2->runAction(CCSequence::create(CCFadeIn::create(timeToUnightning/2),CCFadeOut::create(timeToUnightning),NULL));
    }
    if (randCloud3 == 1)
    {
        cloud3->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
        whiteCloud3->runAction(CCSequence::create(CCFadeIn::create(timeToUnightning/2),CCFadeOut::create(timeToUnightning),NULL));
    }
    if (randCloud4 == 1)
    {
        cloud4->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
        whiteCloud4->runAction(CCSequence::create(CCFadeIn::create(timeToUnightning/2),CCFadeOut::create(timeToUnightning),NULL));
    }
    this->unschedule(schedule_selector(RotatingCloud::ShowLightning));
    this->schedule(schedule_selector(RotatingCloud::HideLightning),timeToUnightning);
}
void RotatingCloud::HideLightning(float dt)
{
    int repeatLighting = rand()%2;

    cloud1->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
    cloud2->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
    cloud3->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));
    cloud4->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DARK-LIGHTNING.png"));

    this->unschedule(schedule_selector(RotatingCloud::HideLightning));
    float timeToLightning;
    if (repeatLighting==1)
        timeToLightning = (rand()%RandTimeBetweenLightings + rand()%RandTimeBetweenLightings + rand()%RandTimeBetweenLightings + RandTimeBetweenLightings )/2000.0f;
    else
        timeToLightning = (rand()%RandTimeAfterLightings + rand()%RandTimeAfterLightings + rand()%RandTimeAfterLightings )/2000.0f;
    this->schedule(schedule_selector(RotatingCloud::ShowLightning),timeToLightning);
}
void RotatingCloud::EndAll()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    cloud1->stopAllActions();
    cloud2->stopAllActions();
    cloud3->stopAllActions();
    cloud4->stopAllActions();
    whiteCloud1->stopAllActions();
    whiteCloud1->stopAllActions();
    whiteCloud1->stopAllActions();
    whiteCloud1->stopAllActions();
    this->unschedule(schedule_selector(RotatingCloud::ShowLightning));

}
