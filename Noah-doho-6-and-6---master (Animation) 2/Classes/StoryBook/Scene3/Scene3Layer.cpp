//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene3Layer.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define FireballFlyTime 1.0f
#define FireballCity2Scale 0.3f
Scene3Layer::Scene3Layer():mAnimationManager(NULL),city1(NULL),city2(NULL),forceField1(NULL),forceField2(NULL),glowingForceField1(NULL),glowingForceField2(NULL),forceFieldExplosion(NULL),fireball(NULL)
{

}
Scene3Layer::~Scene3Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
}
void Scene3Layer::onExit()
{
     
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void Scene3Layer::onEnter()
{
    CCLayer::onEnter();
    fireballIsAnimating=false;
    SoundManager::sharedSoundManager()->startBackgroundSound();
    this->setTouchEnabled(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene3Images_android.plist","Scene3Images.pvr.ccz");
    #elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene3Images.plist", "Scene3Images.pvr.gz");
    #endif
    screenSize=CCDirector::sharedDirector()->getWinSize();
    bacground=CCSprite::create("meet_the_noah.png");
    bacground->setPosition(ccp(screenSize.width/2,screenSize.height-bacground->getContentSize().height/2));
    this->addChild(bacground,2);
    noah=NoahAndDove::create();
    this->addChild(noah, 20);
    city1 =CCSprite::createWithSpriteFrameName("city1-1.png");
    city2 =CCSprite::createWithSpriteFrameName("city2-1.png");
    forceField1 =CCSprite::createWithSpriteFrameName("FORCEFIELD.png");
    forceField2 =CCSprite::createWithSpriteFrameName("DISTANT_FORCEFIELD.png");
    glowingForceField1 =CCSprite::createWithSpriteFrameName("FORCEFIELD-HIT.png");
    glowingForceField2 =CCSprite::createWithSpriteFrameName("DISTANT_FORCEFIELD_HIT.png");
    forceFieldExplosion =CCSprite::createWithSpriteFrameName("FORCEFIELD-EXPLOSION_B.png");
    fireball =CCSprite::createWithSpriteFrameName("fireball.png");
    fireball->setOpacity(0);
    city2->setOpacity( 0);
    forceField1->setOpacity( 0);
    forceField2->setOpacity(0);
    glowingForceField1->setOpacity(0);
    glowingForceField2->setOpacity(0);
    forceFieldExplosion->setOpacity(0);
    forceField1->setScale(0.71f);
    glowingForceField1->setScale(0.71f);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    if (screen_height<=640&&screen_width<=960)
    {
    city1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 450*(screenSize.height/768) + city1->getContentSize().height/2));
    city2->setPosition( ccp(407*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 269*(screenSize.height/768) + city2->getContentSize().height/2));
    forceField1->setPosition(ccp(134*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 449*(screenSize.height/768) + city1->getContentSize().height/2));
    forceField2->setPosition( ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 269*(screenSize.height/768) + city2->getContentSize().height/2));
    glowingForceField1->setPosition(ccp(134*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 449*(screenSize.height/768) + city1->getContentSize().height/2));
    glowingForceField2->setPosition(ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 269*(screenSize.height/768) + city2->getContentSize().height/2));
    }
    else if (screen_height>640&&screen_width>960)
    {
        city1->setPosition(ccp(110*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 439*(screenSize.height/768) + city1->getContentSize().height/2));
        forceField1->setPosition(ccp(112*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 438*(screenSize.height/768) + city1->getContentSize().height/2));
        glowingForceField1->setPosition(ccp(112*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 438*(screenSize.height/768) + city1->getContentSize().height/2));
        
        city2->setPosition( ccp(399*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 242*(screenSize.height/768) + city2->getContentSize().height/2));
        forceField2->setPosition( ccp(401*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 244*(screenSize.height/768) + city2->getContentSize().height/2));
        glowingForceField2->setPosition(ccp(401*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 244*(screenSize.height/768) + city2->getContentSize().height/2));
    }
    else
    {
        city1->setPosition(ccp(134*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 369*(screenSize.height/768) + city1->getContentSize().height/2));
        city2->setPosition( ccp(407*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 200*(screenSize.height/768) + city2->getContentSize().height/2));
        forceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 368*(screenSize.height/768) + city1->getContentSize().height/2));
        forceField2->setPosition( ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 202*(screenSize.height/768) + city2->getContentSize().height/2));
        glowingForceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 368*(screenSize.height/768) + city1->getContentSize().height/2));
        glowingForceField2->setPosition(ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 202*(screenSize.height/768) + city2->getContentSize().height/2));
    }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (screen_height==640&&screen_width==1136)
    {
        city1->setPosition(ccp(134*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 480*(screenSize.height/768) + city1->getContentSize().height/2));
        city2->setPosition( ccp(407*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 270*(screenSize.height/768) + city2->getContentSize().height/2));
        forceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 479*(screenSize.height/768) + city1->getContentSize().height/2));
        forceField2->setPosition( ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 272*(screenSize.height/768) + city2->getContentSize().height/2));
        glowingForceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 479*(screenSize.height/768) + city1->getContentSize().height/2));
        glowingForceField2->setPosition(ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 272*(screenSize.height/768) + city2->getContentSize().height/2));
    }
    else if (screen_height==640&&screen_width==960)
    {
        city1->setPosition(ccp(110*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 439*(screenSize.height/768) + city1->getContentSize().height/2));
        forceField1->setPosition(ccp(112*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 438*(screenSize.height/768) + city1->getContentSize().height/2));
        glowingForceField1->setPosition(ccp(112*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 438*(screenSize.height/768) + city1->getContentSize().height/2));
        
        city2->setPosition( ccp(399*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 242*(screenSize.height/768) + city2->getContentSize().height/2));
        forceField2->setPosition( ccp(401*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 244*(screenSize.height/768) + city2->getContentSize().height/2));
        glowingForceField2->setPosition(ccp(401*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 244*(screenSize.height/768) + city2->getContentSize().height/2));
    }
    else
    {
        city1->setPosition(ccp(134*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 369*(screenSize.height/768) + city1->getContentSize().height/2));
        city2->setPosition( ccp(407*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 200*(screenSize.height/768) + city2->getContentSize().height/2));
        forceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 368*(screenSize.height/768) + city1->getContentSize().height/2));
        forceField2->setPosition( ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 202*(screenSize.height/768) + city2->getContentSize().height/2));
        glowingForceField1->setPosition(ccp(136*(screenSize.width/1024) + city1->getContentSize().width/2,screenSize.height - 368*(screenSize.height/768) + city1->getContentSize().height/2));
        glowingForceField2->setPosition(ccp(409*(screenSize.width/1024) + city2->getContentSize().width/2,screenSize.height - 202*(screenSize.height/768) + city2->getContentSize().height/2));
    }
#endif
    this->addChild(city1,10);
    this->addChild(city2,10);
    this->addChild(forceField1,10);
    this->addChild(forceField2,10);
    this->addChild(glowingForceField1,14);
    this->addChild(glowingForceField2,14);
    this->addChild(forceFieldExplosion,15);
    this->addChild(fireball,18);
    float nextLaunchTime = (rand()%1000 + rand()%1000 + 4001)/1000.0f;
    this->schedule(schedule_selector(Scene3Layer::LaunchFireball), nextLaunchTime);
    this->set_frames();
    this->schedule(schedule_selector(Scene3Layer::tick),1/60);
}
void Scene3Layer::set_frames()
{
    //Exploding animations
    explodingCity1Frames = CCArray::create();
    explodingCity1Frames->retain();
    explodingCity2Frames = CCArray::create();
    explodingCity2Frames->retain();
    explodingFireBallFrames = CCArray::create();
    explodingFireBallFrames->retain();
    CCSpriteFrameCache *framecache=CCSpriteFrameCache::sharedSpriteFrameCache();
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-1.png"));
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-2.png"));
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-3.png"));
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-4.png"));
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-5.png"));
    explodingCity1Frames->addObject(framecache->spriteFrameByName("city1-6.png"));
    
    explodingCity2Frames->addObject(framecache->spriteFrameByName("city2-1.png"));
    explodingCity2Frames->addObject(framecache->spriteFrameByName("city2-2.png"));
    explodingCity2Frames->addObject(framecache->spriteFrameByName("city2-3.png"));
    explodingCity2Frames->addObject(framecache->spriteFrameByName("city2-4.png"));
    explodingCity2Frames->addObject(framecache->spriteFrameByName("city2-5.png"));
    
    
    
    explodingFireBallFrames->addObject(framecache->spriteFrameByName("FIREBALL-EXPLODE_1.png"));
    explodingFireBallFrames->addObject(framecache->spriteFrameByName("FIREBALL-EXPLODE_2.png"));
    explodingFireBallFrames->addObject(framecache->spriteFrameByName("FIREBALL-EXPLODE_3.png"));
    explodingFireBallFrames->addObject(framecache->spriteFrameByName("FIREBALL-EXPLODE_4.png"));
    explodingFireBallFrames->addObject(framecache->spriteFrameByName("FIREBALL-EXPLODE_5.png"));
    
    
    
    
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene3Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene3Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene3Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene3Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene3Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene3Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "city1", CCSprite *, this->city1);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "city2", CCSprite *, this->city2);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "forceField1", CCSprite *, this->forceField1);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "forceField2", CCSprite *, this->forceField2);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "glowingForceField1", CCSprite *, this->glowingForceField1);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "forceFieldExplosion", CCSprite *, this->forceFieldExplosion);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fireball", CCSprite *, this->fireball);
    //  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "glowingForceField2", CCSprite *, this->glowingForceField2);
    return false;
}
bool Scene3Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene3Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
void Scene3Layer::FinishanimatingFireball()
{
    fireball->setOpacity(1);
    fireball->setPosition(CCPointZero);
    fireballIsAnimating = false;
    if (glowingForceField2->getOpacity()> 0)
    {
        glowingForceField2->runAction(CCFadeOut::create(0.1f));
        
        if (SoundManager::sharedSoundManager()->isEffectPlaying(electricHum))
        {
            forceField2->runAction(CCFadeIn::create(0.1f));
        }
    }
    if (glowingForceField1->getOpacity() > 0)
    {
        glowingForceField1->runAction(CCFadeOut::create(0.1f));
        if (SoundManager::sharedSoundManager()->isEffectPlaying(electricHum))
        {
            forceField1->runAction(CCFadeIn::create(0.1f));
        }
    }
}
void Scene3Layer::tick(float dt)
{
    if (fireballIsAnimating)
    {
        return;
    }
    if(ccpDistance(fireball->getPosition(), city1->getPosition()) <= 60 && forceField1->getOpacity()>=80)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);
        fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this,callfunc_selector(Scene3Layer::FinishanimatingFireball)),NULL));
        float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
        this->schedule(schedule_selector(Scene3Layer::LaunchFireball), nextLaunchTime);
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/Impact laser.mp3",false);
        glowingForceField1->runAction(CCFadeIn::create(0.1f));
        forceField1->runAction(CCFadeOut::create(0.1f));
        forceFieldExplosion->setPosition(ccpAdd(fireball->getPosition(), ccp(20, 20)));
        forceFieldExplosion->setScale(1.0);
        forceFieldExplosion->runAction(CCSequence::create(CCFadeIn::create(0.1),CCDelayTime::create(0.4f),CCFadeOut::create(0.1f),NULL));
        return;
    }
    if(ccpDistance(fireball->getPosition(), city2->getPosition()) <= 20 && forceField2->getOpacity()>=80)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);
        fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this,callfunc_selector(Scene3Layer::FinishanimatingFireball)),NULL));
        float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/Impact laser.mp3",false);
        //[[SimpleAudioEngine sharedEngine] playEffect:@"Impact laser.mp3" pitch:1 pan:1 gain:0.4f];
        this->schedule(schedule_selector(Scene3Layer::LaunchFireball), nextLaunchTime);
        glowingForceField2->runAction(CCFadeIn::create(0.1f));
        forceField2->runAction(CCFadeOut::create(0.1f));
        forceFieldExplosion->setPosition(ccpAdd(fireball->getPosition(), ccp(-10, 10)));
        forceFieldExplosion->setScaleY(0.4f);
        forceFieldExplosion->setScaleX(-0.4f);
        forceFieldExplosion->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCDelayTime::create(0.1),CCFadeOut::create(0.1f),NULL));
        return;
    }
}
void Scene3Layer::ExplodeCity1()
{
    fireball->setOpacity(0);
    fireball->setPosition(CCPointZero);
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/explosionNear.mp3",false);
    CCAnimation* animation = CCAnimation::create();
    for( int i=1;i<7;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "city1-%d.png", i);
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(szName));
    }
    animation->setDelayPerUnit(0.6f/ 7);
    animation->setRestoreOriginalFrame(true);
    
    CCAnimate* action = CCAnimate::create(animation);
    city1->runAction(CCSequence::create(action,NULL));
    
    float nextLaunchTime = (rand()%1000 +rand()%1000 + 4001)/1000.0f;
    this->schedule(schedule_selector(Scene3Layer::LaunchFireball), nextLaunchTime);
    
}
void Scene3Layer::ExplodeCity2()
{
    fireball->setOpacity(0);
    fireball->setPosition(CCPointZero);
    city2->setOpacity(255);
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/explosionFar.mp3",false);
    explodingCity2 = CCAnimation::createWithSpriteFrames(explodingCity2Frames);
    explodingCity2->setDelayPerUnit(0.6/explodingCity2Frames->count());
    float nextLaunchTime = (rand()%1000 + rand()%1000 + 4001)/1000.0f;
    this->schedule(schedule_selector(Scene3Layer::LaunchFireball), nextLaunchTime);
    CCAnimate *anim=CCAnimate::create(explodingCity2);
    anim->setDuration(0.6f);
    city2->runAction(CCSequence::create(anim,CCFadeOut::create(0.001f),NULL));
}
void Scene3Layer::LaunchFireball(float dt)
{
    this->unschedule(schedule_selector(Scene3Layer::LaunchFireball));
    int targetCity = rand()%2 + 1;
    //if forcefield is active, then only the other city can launch fireballs
    if (forceField1->getOpacity()>=180)
        targetCity=1;
    if (forceField2->getOpacity()>=180)
        targetCity=2;
    
    fireball->setOpacity(255);
    ccBezierConfig bezzier;
    switch (targetCity)
    {
        case 1:
            fireball->setScale(FireballCity2Scale);
            fireball->setRotation(-30);
            fireball->setPosition(city2->getPosition());
            
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballLaunchFar.caf", false);
            // [[SimpleAudioEngine sharedEngine] playEffect:@"fireballLaunchFar.caf"];
            
            bezzier.controlPoint_1 = ccp(city2->getPositionX(), city2->getPositionY());
            bezzier.controlPoint_2 = ccp((city2->getPositionX() + city1->getPositionX())/2, city2->getPositionY() + 160*(screenSize.height/768));
            bezzier.endPosition = ccp(city1->getPositionX(), city1->getPositionY());
            fireball->runAction(CCSequence::create(CCSpawn::create(CCBezierTo::create(FireballFlyTime, bezzier),CCScaleTo::create(FireballFlyTime, 1.0f),CCRotateBy::create(FireballFlyTime, -150),NULL),CCCallFunc::create(this, callfunc_selector(Scene3Layer::ExplodeCity1)),NULL));
            break;
        case 2:
            fireball->setScale(1.0f);
            fireball->setRotation(0);
            fireball->setPosition(city1->getPosition());
            
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballLaunchNear.caf", false);
            
            bezzier.controlPoint_1 = ccp(city1->getPositionX(), city1->getPositionY());
            bezzier.controlPoint_2 = ccp((city2->getPositionX() + city1->getPositionX())/2, city2->getPositionY() + 160*(screenSize.height/768));
            bezzier.endPosition = ccp(city2->getPositionX(), city2->getPositionY());
            fireball->runAction(CCSequence::create(CCSpawn::create(CCBezierTo::create(FireballFlyTime, bezzier),CCScaleTo::create(FireballFlyTime, FireballCity2Scale),CCRotateBy::create(FireballFlyTime, 120),NULL),CCCallFunc::create(this, callfunc_selector(Scene3Layer::ExplodeCity2)),NULL));
            break;
        default:
            break;
    }
}
void  Scene3Layer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    
    CCTouch* pTouch =(CCTouch*) pTouches->anyObject();
    CCPoint touchPoint = pTouch->getLocationInView();
    touchPoint=CCDirector::sharedDirector()->convertToGL(touchPoint);
    bool forceFieldActive = GameManager::sharedGameManager()->GetAchievmentIsActive(ForceFieldAchievmentID);
    if (GameManager::sharedGameManager()->isNodeAtPoint(city1,touchPoint)&&forceFieldActive)
    {
        forceField1->runAction(CCFadeIn::create(0.1f));
        electricHum=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 5/forceFieldHumm.mp3",true);
        //[electricHum setGain:1];
        // [electricHum play];
        
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(city2,touchPoint)&&forceFieldActive)
    {
        forceField2->runAction(CCFadeIn::create(0.1f));
        electricHum=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 5/forceFieldHumm.mp3",true);
        //[electricHum setGain:1];
        //[electricHum play];
        return ;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fireball,touchPoint) && !fireballIsAnimating)
    {
        fireball->stopAllActions();
        fireballIsAnimating = true;
        CCAnimation *animation= CCAnimation::createWithSpriteFrames(explodingFireBallFrames);
        animation->setDelayPerUnit(0.6f/explodingFireBallFrames->count());
        animation->setRestoreOriginalFrame(true);
        CCAnimate *anim=CCAnimate::create(animation);
        anim->setDuration(0.6f);
        
        fireball->runAction(CCSequence::create(anim,CCCallFunc::create(this, callfunc_selector(Scene3Layer::FinishanimatingFireball)),NULL));
        float nextLaunchTime = (rand()%1000 + rand()%1000 + 4001)/1000.0f;
        this->schedule(schedule_selector(Scene3Layer::LaunchFireball),nextLaunchTime);
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/fireballExplosionMidair.mp3", false);
        
        GameManager::sharedGameManager()->AddPoints(5,touchPoint,this);
        //[[SimpleAudioEngine sharedEngine] playEffect:@"" pitch:1 pan:1 gain:1];
        //[delegate ShouldAddPoint:touchPoint];
    }
}
void Scene3Layer:: ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    SoundManager::sharedSoundManager()->stopSoundEffect(electricHum);
    if (forceField2->getOpacity()> 0)
    {
        if (!fireballIsAnimating)
        {
            forceField2->runAction(CCFadeTo::create(0.1f, 0));
            if (glowingForceField2->getOpacity()>0) {
                
                glowingForceField2->stopAllActions();
                glowingForceField2->runAction(CCFadeTo::create(0.1f, 0));
            }
        }
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/PHAZE DOWN.mp3", false);
    }
    if (forceField1->getOpacity()> 0)
    {
        if (!fireballIsAnimating)
        {
            forceField1->runAction(CCFadeTo::create(0.1f, 0));
            if (glowingForceField1->getOpacity() > 0)
            {
                glowingForceField1->stopAllActions();
                glowingForceField1->runAction(CCFadeTo::create(0.1f, 0));
            }
        }
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 3/PHAZE DOWN.mp3", false);
    }
}