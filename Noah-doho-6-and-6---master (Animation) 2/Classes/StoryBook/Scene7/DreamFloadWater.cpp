//
//  DreamFloadWater.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "DreamFloadWater.h"
#include "../../SoundManager/SoundManager.h"
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width
#define FlowYOffset 112*(WINHEIGHT/768)
#define arcXoffset 130*(WINWIDTH/1024)
#define arcYoffset 80*(WINHEIGHT/768)
#define palm1Xoffset 320*(WINWIDTH/1024)
#define palm1Yoffset -20*(WINHEIGHT/768)
#define palm2Xoffset -200
#define palm2Yoffset 80*(WINHEIGHT/768)

#define towerXoffset 400*(WINWIDTH/1024)
#define towerYoffset -50*(WINHEIGHT/768)
#define flagXoffset -500*(WINWIDTH/1024)
#define flagYoffset -110*(WINHEIGHT/768)
#define passByYoffset 220*(WINHEIGHT/768)
USING_NS_CC;
USING_NS_CC_EXT;
DreamFloadWater::DreamFloadWater():mAnimationManager(NULL)
{
    //CCLog("Header Layer called");
}
DreamFloadWater::~DreamFloadWater()
{
  //CCLog("Header Layer removed");
}
void DreamFloadWater::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void DreamFloadWater::onEnter()
{
    screenSize = CCDirector::sharedDirector()->getWinSize();
    waveNumber = 4;
    
    
    inComingFloadWater =CCSprite::createWithSpriteFrameName("floodwater0.png");
    floadWater1 =CCSprite::createWithSpriteFrameName("floodwater1.png");
   

    topFloadWater =CCSprite::createWithSpriteFrameName("topWave2.png");
    midFloadWater=CCSprite::createWithSpriteFrameName("midWave2.png");
    botFloadWater=CCSprite::createWithSpriteFrameName("botWave2.png");
    palm1=CCSprite::createWithSpriteFrameName("palm-tree_1.png");
    palm2=CCSprite::createWithSpriteFrameName("palm-tree_2.png");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // inComingFloadWater->setScaleY(1+(1-0.9375));
    //floadWater1->setScaleY(1+(1-0.9375));
    topFloadWater->setScaleX(1+(1.2-0.9375));
    midFloadWater->setScaleX(1+(1.2-0.9375));
    botFloadWater->setScaleX(1+(1.2-0.9375));
#endif
      //flag=LoadItem::create(CCString::create("floatingFlag.png"));
        flag=CCSprite::createWithSpriteFrameName("floatingFlag.png");
        tower=LoadItem::create(CCString::create("floatingTower.png"));
       //tower=CCSprite::createWithSpriteFrameName("floatingTower.png");
        arc=CCSprite::createWithSpriteFrameName("ark.png");

    inComingFloadWater->setPosition(ccp( screenSize.width + inComingFloadWater->getContentSize().width/2,FlowYOffset + inComingFloadWater->getContentSize().height/2));
    floadWater1->setPosition(ccpAdd(inComingFloadWater->getPosition(), ccp(inComingFloadWater->getContentSize().width/2+ floadWater1->getContentSize().width/2,0)));
    topFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ topFloadWater->getContentSize().width/2,0)));
    midFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ midFloadWater->getContentSize().width/2,0)));
    botFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ botFloadWater->getContentSize().width/2,0)));
    arc->setPosition( ccpAdd(topFloadWater->getPosition(), ccp(arcXoffset,arcYoffset)));
    palm1->setPosition( ccpAdd(floadWater1->getPosition(), ccp(palm1Xoffset,palm1Yoffset)));
    palm2->setPosition( ccpAdd(floadWater1->getPosition(), ccp(palm2Xoffset,palm2Yoffset)));
    tower->setPosition( ccpAdd(inComingFloadWater->getPosition(), ccp(towerXoffset,towerYoffset)));
    flag->setPosition( ccpAdd(inComingFloadWater->getPosition(), ccp(flagXoffset,flagYoffset)));
    //tower.position = ccp(screenSize.width/2, screenSize.height/2);
    
    this->addChild(inComingFloadWater,3);
    this->addChild(floadWater1,3);
    this->addChild(topFloadWater,3);
    this->addChild(midFloadWater,5);
    this->addChild(botFloadWater,7);
    this->addChild(arc,4);
    this->addChild(palm1,6);
    this->addChild(palm2,6);
    this->addChild(tower,6);
    this->addChild(flag,6);
    palm1->setRotation(40);
    palm2->setRotation(-60);
    arc->runAction(CCRepeatForever::create(CCSequence::create(CCEaseInOut::create(CCRotateTo::create(0.4f, 3), 2),CCEaseInOut::create(CCRotateTo::create(0.4f, -3),2),NULL)));
   CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void DreamFloadWater::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN DreamFloadWater::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler DreamFloadWater::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler DreamFloadWater::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool DreamFloadWater::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool DreamFloadWater::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void DreamFloadWater::tick(float dt)
{
    floadWater1->setPosition(ccpSub(botFloadWater->getPosition(), ccp(floadWater1->getContentSize().width/2+ botFloadWater->getContentSize().width/2,0)));
    inComingFloadWater->setPosition(ccpSub(floadWater1->getPosition(), ccp(inComingFloadWater->getContentSize().width/2+ floadWater1->getContentSize().width/2,0)));
    arc->setPosition(ccpAdd(botFloadWater->getPosition(), ccp(arcXoffset,arcYoffset)));
//    palm1->setPosition(ccpAdd(floadWater1->getPosition(), ccp(palm1Xoffset,palm1Yoffset)));
//    palm2->setPosition(ccpAdd(floadWater1->getPosition(), ccp(palm2Xoffset,palm2Yoffset)));
   // floadWater1->setPosition(ccpAdd(inComingFloadWater->getPosition(), ccp(inComingFloadWater->getContentSize().width/2+ floadWater1->getContentSize().width/2,0)));
   // floadWater2->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ floadWater2->getContentSize().width/2,0)));
}
void DreamFloadWater::passSomethingBy(float dt)
{
    int randomThing = rand()%2;
    float randtime = (rand()%1000 +1000.0f)/500.0f;
    switch (randomThing)
    {
        case 0:
            //palm1
            palm1->setPosition(ccpAdd(ccp(-palm1->getContentSize().width,0), ccp(0,passByYoffset)));
            palm1->stopAllActions();
            palm1->runAction(CCMoveTo::create(randtime, ccpAdd(ccp(screenSize.width + palm1->getContentSize().width,0), ccp(0,passByYoffset))));
            
            break;
        case 1:
            //palm2
            palm2->setPosition( ccpAdd(ccp(-palm2->getContentSize().width,0), ccp(0,passByYoffset)));
            palm2->runAction(CCMoveTo::create(randtime,ccpAdd(ccp(screenSize.width + palm2->getContentSize().width,0), ccp(0,passByYoffset))));
            break;
        case 2:
            //tower
            tower->setPosition(ccpAdd(ccp(-tower->getContentSize().width,0), ccp(0,passByYoffset)));
            tower->runAction(CCMoveTo::create(randtime, ccpAdd(ccp(screenSize.width + tower->getContentSize().width,0), ccp(0,passByYoffset))));
            break;
            
        default:
            break;
    }
}
void DreamFloadWater::ChangeWave(float dt)
{
    waveNumber--;
    if (waveNumber < 1) waveNumber =3;
    
    CCString *str=CCString::createWithFormat("topWave%d.png",waveNumber);
    CCString *str1=CCString::createWithFormat("midWave%d.png",waveNumber);
    CCString *str2=CCString::createWithFormat("botWave%d.png",waveNumber);
    topFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
    midFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str1->getCString()));
    botFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str2->getCString()));
}
void DreamFloadWater::GetWavesAnimating()
{
    float randtime = (rand()%8000 +4000.0f)/1000.0f;
    this->schedule(schedule_selector(DreamFloadWater::ChangeWave),0.1f);
    this->schedule(schedule_selector(DreamFloadWater::passSomethingBy),randtime);
    this->unschedule(schedule_selector(DreamFloadWater::tick));
}
void DreamFloadWater::StartFload()
{
    this->schedule(schedule_selector(DreamFloadWater::tick));
    tower->runAction(CCMoveTo::create(3.0f,ccp(-screenSize.width + towerXoffset,tower->getPositionY())));
    flag->runAction(CCMoveTo::create(3.0f,ccp(-screenSize.width + flagXoffset,flag->getPositionY())));
    if (SoundManager::sharedSoundManager()->isEffectPlaying(waveSound))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(waveSound);
    }
    waveSound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 7/rushingFloodwaters.mp3", false);
    topFloadWater->runAction(CCSequence::create(CCEaseOut::create(CCMoveTo::create(5.5f, ccp(screenSize.width/2, floadWater1->getPositionY())), 1.65f),NULL));
    midFloadWater->runAction(CCSequence::create(CCEaseOut::create(CCMoveTo::create(5.5f, ccp(screenSize.width/2, floadWater1->getPositionY())), 1.65f),NULL));
    botFloadWater->runAction(CCSequence::create(CCEaseOut::create(CCMoveTo::create(5.5f, ccp(screenSize.width/2, floadWater1->getPositionY())), 1.65f),CCCallFunc::create(this, callfunc_selector(DreamFloadWater::GetWavesAnimating)),NULL));
}
void DreamFloadWater::ResetFload()
{
    this->unschedule(schedule_selector(DreamFloadWater::ChangeWave));
    this->unschedule(schedule_selector(DreamFloadWater::passSomethingBy));
    topFloadWater->stopAllActions();
    midFloadWater->stopAllActions();
    botFloadWater->stopAllActions();
    palm1->stopAllActions();
    palm2->stopAllActions();
    tower->stopAllActions();

    SoundManager::sharedSoundManager()->stopSoundEffect(waveSound);
    
    inComingFloadWater->setPosition(ccp( screenSize.width + inComingFloadWater->getContentSize().width/2,FlowYOffset + inComingFloadWater->getContentSize().height/2));
    floadWater1->setPosition(ccpAdd(inComingFloadWater->getPosition(), ccp(inComingFloadWater->getContentSize().width/2+ floadWater1->getContentSize().width/2,0)));
    topFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ topFloadWater->getContentSize().width/2,0)));
    midFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ botFloadWater->getContentSize().width/2,0)));
    botFloadWater->setPosition(ccpAdd(floadWater1->getPosition(), ccp(floadWater1->getContentSize().width/2+ botFloadWater->getContentSize().width/2,0)));
    topFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("topWave2.png"));
    midFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("midWave2.png"));
    botFloadWater->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("botWave2.png"));

    arc->setPosition(ccpAdd(botFloadWater->getPosition(), ccp(arcXoffset,arcYoffset)));
    palm1->setPosition(ccpAdd(floadWater1->getPosition(), ccp(palm1Xoffset, palm1Yoffset)));
    palm2->setPosition(ccpAdd(floadWater1->getPosition(), ccp(palm2Xoffset, palm2Yoffset)));
    tower->setPosition(ccpAdd(inComingFloadWater->getPosition(), ccp(towerXoffset, towerYoffset)));
    
   // tower->setPosition(ccpAdd(inComingFloadWater->getPosition(), ccp(flagXoffset, flagYoffset)));
}
void  DreamFloadWater::StopSounds()
{
    SoundManager::sharedSoundManager()->stopSoundEffect(waveSound);
}
