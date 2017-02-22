//  Created by Neil D on 20/05/13.
#include "Scene15Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene15Layer::Scene15Layer():mAnimationManager(NULL),gradient(NULL),clouds(NULL),sun(NULL),fishingNoah(NULL),fishie1(NULL),fishie2(NULL),fishie3(NULL),fishie4(NULL),fishie5(NULL)
{
    interactionsEnabled = false;
    waytingForNarrator = false;
    sunIsTouched=false;
    isPlaying=false;
}
Scene15Layer::~Scene15Layer()
{
    SoundManager::sharedSoundManager()->stopNarrator();
}
void Scene15Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void Scene15Layer::onEnter()
{
    this->setTouchEnabled(true);
    screenSize=CCDirector::sharedDirector()->getWinSize();
    this->set_scene();
    CCLayer::onEnter();
}
void Scene15Layer::set_scene()
{
    waytingForNarrator = true;
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    screenSize =CCDirector::sharedDirector()->getWinSize();
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("scene15Images_android.plist", "scene15Images.pvr.ccz");
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("scene15Images.plist", "scene15Images.pvr.gz");
#endif
    bacground =CCSprite::createWithSpriteFrameName("scene15Back.png");
    gradient=CCSprite::createWithSpriteFrameName("scene15Gradient.png");
    clouds =CCSprite::createWithSpriteFrameName("scene15Clouds.png");
    sun=CCSprite::createWithSpriteFrameName("scene15Sun.png");
    lightArk=CCSprite::createWithSpriteFrameName("scene15Ark.png");
    darkArk=CCSprite::createWithSpriteFrameName("scene15DarkArk.png");
    
    lightSea=CCSprite::createWithSpriteFrameName("scene15Sea.png");
    darkSea=CCSprite::createWithSpriteFrameName("scene15SeaDark.png");
    fishingNoah=CCSprite::createWithSpriteFrameName("fishingPose_1.png");
    fishie1=CCSprite::createWithSpriteFrameName("hereFishie.png");
    fishie2=CCSprite::createWithSpriteFrameName("hereFishie.png");
    fishie3=CCSprite::createWithSpriteFrameName("hereFishie.png");
    fishie4=CCSprite::createWithSpriteFrameName("hereFishie.png");
    fishie5=CCSprite::createWithSpriteFrameName("hereFishie.png");
    
    maxSunY =(12*screen_height/100) + darkSea->getContentSize().height/2+sun->getContentSize().height/2;
    sun->setPosition(ccp(sun->getContentSize().width/2,maxSunY));
    minSunY = maxSunY - 355*(screen_height/768);
    bacground->setPosition(ccp(screenSize.width/2,(14*screen_height/100) + bacground->getContentSize().height/2));
    gradient->setPosition( ccp(screenSize.width/2, screenSize.height - gradient->getContentSize().height/2));
    clouds->setPosition(ccp(screenSize.width/2, (12*screen_height/100) + clouds->getContentSize().height/2));
    
    
    lightArk->setPosition(ccp(685*(screen_width/1024) + lightArk->getContentSize().width/2,(12*screen_height/100)+lightArk->getContentSize().height/2));
    darkArk->setPosition(ccp(685*(screen_width/1024) + darkArk->getContentSize().width/2,(12*screen_height/100)+darkArk->getContentSize().height/2));
    
    
    lightSea->setPosition(ccp(screenSize.width/2,(12*screen_height/100) + lightSea->getContentSize().height/2));
    darkSea->setPosition(ccp(screenSize.width/2,(12*screen_height/100) + darkSea->getContentSize().height/2));
    
    
    //fishingNoah->setPosition(ccp(298*(screen_width/1024) + fishingNoah->getContentSize().width/2,screenSize.height - 44*(screen_height/768) - fishingNoah->getContentSize().height/2));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    fishingNoah->setPosition(ccp(280*(screen_width/1024) + fishingNoah->getContentSize().width/2,fishingNoah->getContentSize().height/2+(12*screen_height/100)-66*(screen_height/768)));
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (screen_width==1136)
    {
        fishingNoah->setPosition(ccp(280*(screen_width/1024) + fishingNoah->getContentSize().width/2,fishingNoah->getContentSize().height/2+(12*screen_height/100)-66*(screen_height/768)));
        
    }
    else if (screen_width==960||screen_height==640)
    {
        fishingNoah->setPosition(ccp(260*(screen_width/1024) + fishingNoah->getContentSize().width/2,fishingNoah->getContentSize().height/2+(12*screen_height/100)-56*(screen_height/768)));
        
    }
    else
        
        fishingNoah->setPosition(ccp(289*(screen_width/1024) + fishingNoah->getContentSize().width/2,fishingNoah->getContentSize().height/2+(12*screen_height/100)-44*(screen_height/768)));
#endif
    
    fishie1->setPosition( ccp(screen_width/2,60*(screen_height/768)));
    fishie2->setPosition(ccp(screen_width/2,60*(screen_height/768)));
    fishie3->setPosition(ccp(screen_width/2,60*(screen_height/768)));
    fishie4->setPosition(ccp(screen_width/2,60*(screen_height/768)));
    fishie5->setPosition(ccp(screen_width/2,60*(screen_height/768)));
    this->addChild(bacground, 10);
    this->addChild(gradient, 20);
    this->addChild(sun, 25);
    this->addChild(clouds,30);
    this->addChild(lightSea ,40);
    this->addChild(darkSea ,45);
    this->addChild(lightArk ,50);
    this->addChild(darkArk ,51);
    this->addChild(fishingNoah,60);
    this->addChild(fishie1,70);
    this->addChild(fishie2 ,70);
    this->addChild(fishie3 ,70);
    this->addChild(fishie4 ,70);
    this->addChild(fishie5 ,70);
    
    darkArk->setOpacity(0);
    darkSea->setOpacity(0);
    gradient->setOpacity(0);
    
    SoundManager::sharedSoundManager()->startBackgroundSound();
    
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        oceanSound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/oceanAmbience.caf", true);
    }
    else
    {
        oceanSound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/oceanAmbience.ogg", true);
    }
    
    
    this->schedule(schedule_selector(Scene15Layer::tick),1/60);
    float randTime = (rand()%2000 + 6000)/1000.0f;
    this->schedule(schedule_selector(Scene15Layer::jumpFishie),randTime);
    
    possibleFishies.push_back("hereFishie.png");
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(GameManager::sharedGameManager()->getstarStoreElements(), pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        if (dict->valueForKey("groupId")->intValue()== GroupIDFishes && dict->valueForKey("status")->intValue() == elementStatusBoughtSelected)
        {
            possibleFishies.push_back(dict->valueForKey("fileName")->getCString());
        }
    }
    
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene15Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene15Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    platform = CCApplication::sharedApplication()->getTargetPlatform();
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene15Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene15Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene15Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene15Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene15Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gradient", CCSprite *, this->gradient);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "clouds", CCSprite *, this->clouds);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sun", CCSprite *, this->sun);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gradient", CCSprite *, this->gradient);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gradient", CCSprite *, this->gradient);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gradient", CCSprite *, this->gradient);
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "touch_son", CCLayerColor *, this->touch_son);
    return false;
}
bool Scene15Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void Scene15Layer::SplashFishEntrie()
{
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.caf", false);
    }
    else
    {        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.ogg", false);
        
    }
}
void Scene15Layer::SplashFish(CCSprite* fishie)
{
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.caf", false);
    }
    else
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.ogg", false);
    }
    fishie->setOpacity(0);
}
float fgRangeRand( float min, float max )
{
    float rnd = ((float)rand()/(float)RAND_MAX);
    return rnd*(max-min)+min;
}
void Scene15Layer::GetTrajectoryFishie(CCSprite* fishie)
{
    fishie->setScale(1.5);
    CCLOG("Get trajectory fish");
    float startXOffset = (fgRangeRand(0, 640) - 240.0f);
    float startYOffset = (60.0f -fgRangeRand(0, 90));
    float startXDif = (fgRangeRand(0, 120) + 120);
    float startYMax = (fgRangeRand(0,280) + 620);
    CCLOG("\n%f %f %f %f\n",startXOffset,startYOffset,startXDif,startYMax);
    if (rand()%2)
    {
        startXDif=startXDif*-1;
    }
    float rand5=(fgRangeRand(0, 600))/600.0f;
    float randTime = rand5;
    
    ccBezierConfig bezzier;
    fishie->setPosition(ccp(screen_width/2 + startXOffset - startXDif, startYOffset*(screen_height/768)));
    bezzier.controlPoint_1 = fishie->getPosition();
    bezzier.controlPoint_2 = ccp(screen_width/2 + startXOffset,startYMax*(screen_height/768));
    bezzier.endPosition = ccp(screen_width/2 + startXOffset + startXDif, 60*(screen_height/768));
    
    CCActionInterval*  bezierTo1 = CCBezierTo::create(1.8, bezzier);
    CCCallFuncN *cal_fn_N=CCCallFuncN::create(this, callfuncN_selector(Scene15Layer::SplashFish));
    CCCallFunc *call_f=CCCallFunc::create(this, callfunc_selector(Scene15Layer::SplashFishEntrie));
    CCSpawn *spwn=CCSpawn::create(bezierTo1,CCRotateBy::create(1.8f, 270),NULL);
    
    CCSequence *seq=CCSequence::create(CCDelayTime::create(randTime),call_f,spwn,cal_fn_N,CCScaleTo::create(randTime, 1),NULL);
    fishie->runAction(seq);
    random_shuffle( possibleFishies.begin(), possibleFishies.end() );
    CCString  *str=CCString::create(this->possibleFishies[0].c_str());
    fishie->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
}
void Scene15Layer::jumpFishie(float dt)
{
    
    this->unschedule(schedule_selector(Scene15Layer::jumpFishie));
    fishie1->setOpacity(255);
    this->GetTrajectoryFishie(fishie1);
    
    if (rand()%2 == 1) {
        fishie2->setOpacity(255);
        this->GetTrajectoryFishie(fishie2);
    }
    
    if (rand()%2 == 1) {
        fishie3->setOpacity(255);
        this->GetTrajectoryFishie(fishie3);
    }
    if (rand()%3 == 1) {
        fishie4->setOpacity(255);
        this->GetTrajectoryFishie(fishie4);
    }
    if (rand()%4 == 1) {
        fishie5->setOpacity(255);
        this->GetTrajectoryFishie(fishie5);
    }
    float randTime = (rand()%2000 + 6000)/1000.0f;
    this->schedule(schedule_selector(Scene15Layer::jumpFishie), randTime);
}
void Scene15Layer::PlayFish(float  dt)
{
    this->unschedule(schedule_selector(Scene15Layer::PlayFish));
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.caf", false);
    }
    else
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/splashFromFish.ogg", false);
    }
}
void Scene15Layer::PlayNoahFished(float dt)
{
    this->unschedule(schedule_selector(Scene15Layer::PlayNoahFished));
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        noahFished=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/fishingNoahGotFish.caf", false);
    }
    else
    {
        noahFished=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 15/fishingNoahGotFish.ogg", false);
        
    }
    this->schedule(schedule_selector(Scene15Layer::WaitForNoahToEnd),1/60);
}
void Scene15Layer::WaitForNoahToEnd(float dt)
{
    if (!SoundManager::sharedSoundManager()->isEffectPlaying(noahFished))
    {
        this->unschedule(schedule_selector(Scene15Layer::WaitForNoahToEnd));
        isPlaying = false;
    }
}
bool Scene15Layer::isTouchOnFishie(CCSprite* fishie,CCPoint point)
{
    if(GameManager::sharedGameManager()->isNodeAtPoint(fishie, point)&& fishie->getOpacity() != 0)
    {
        GameManager::sharedGameManager()->AddPoints(1, point,this);
        fishie->stopAllActions();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        fishie->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(740*(screen_width/1024), 650*(screen_height/768))),CCFadeOut::create(0.1f),NULL));
        
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        
        if (screen_width==1136)
        {
            fishie->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(740*(screen_width/1024), 650*(screen_height/768))),CCFadeOut::create(0.1f),NULL));
        }
        else if (screen_width==960)
        {
            fishie->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(740*(screen_width/1024), 650*(screen_height/768))),CCFadeOut::create(0.1f),NULL));
        }
        else
        {
            fishie->runAction(CCSequence::create(CCMoveTo::create(0.4f, ccp(768*(screen_width/1024), 540*(screen_height/768))),CCFadeOut::create(0.1f),NULL));
        }
#endif
        return true;
    }
    return false;
}
void Scene15Layer::tick(float dt)
{
    float newY;
    if (sunIsTouched==false)
    {
        //CCLog("opacity changed");
        newY=maxSunY;
    }
    else
        newY = sun->getPositionY();
    
    int newOpacity = 255 - (newY - minSunY)*1.0f/(maxSunY - minSunY) * 255;
    gradient->setOpacity(newOpacity);
    darkSea->setOpacity(newOpacity);
    darkArk->setOpacity( newOpacity);
}
#pragma mark -
#pragma mark Touch Delegate
#pragma mark -
void Scene15Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *touch=(CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (!isPlaying)
    {
        CCPoint p;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        p=ccp(719*(screen_width/1024), 100*(screen_height/768));
        
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //Patch for noah touch position..
        if (screen_width==1136)
        {
            p=ccp(719*(screen_width/1024), 70*(screen_height/768));
        }
        else if (screen_width==960)
        {
            p=ccp(719*(screen_width/1024), 100*(screen_height/768));
        }
        else
        {
            p=ccp(719*(screen_width/1024), 164*(screen_height/768));
        }
#endif
        if (GameManager::sharedGameManager()->isTouchOnAreaFromGimp(location, p, 76, 116))
        {
            CCAnimation* animation = CCAnimation::create();
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_5.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_6.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fishingPose_1.png"));
            
            animation->setDelayPerUnit(1.0f/12);
            animation->setRestoreOriginalFrame(true);
            CCAnimate* action = CCAnimate::create(animation);
            action->setDuration(0.8f);
            fishingNoah->runAction(CCSequence::create(action,NULL));
            this->schedule(schedule_selector(Scene15Layer::PlayFish), 0.2f);
            this->schedule(schedule_selector(Scene15Layer::PlayNoahFished), 0.8f);
            isPlaying = true;
            return;
        }
    }
    if (this->isTouchOnFishie(fishie1, location)||this->isTouchOnFishie(fishie2, location)||this->isTouchOnFishie(fishie3, location)||
        this->isTouchOnFishie(fishie4, location)||
        this->isTouchOnFishie(fishie5, location)||this->isTouchOnFishie(fishie5, location))
    {
        
    }
    if( GameManager::sharedGameManager()->isNodeAtPoint(sun, location))
    {
        sunIsTouched = true;
        whereTouch=ccpSub(sun->getPosition(), location);
    }
}
void Scene15Layer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    sunIsTouched = false;
    sun->runAction(CCEaseBounceOut::create(CCMoveTo::create(0.4f, ccp(sun->getContentSize().width/2, maxSunY))));
}
void Scene15Layer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    sunIsTouched = false;
    sun->runAction(CCEaseBounceOut::create(CCMoveTo::create(0.4f, ccp(sun->getContentSize().width/2, maxSunY))));
}
void Scene15Layer::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch;
    touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (!sunIsTouched)
        return;
    float newY = (location.y + whereTouch.y);
    if ( newY > minSunY && newY < maxSunY)
    {
        sun->setPosition(ccp(sun->getPositionX(),newY));
    }
}