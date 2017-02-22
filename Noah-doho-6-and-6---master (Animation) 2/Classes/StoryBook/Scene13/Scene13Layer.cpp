//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene13Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene13Layer::Scene13Layer():mAnimationManager(NULL),animalToLaunch(NULL)
{
    interactionsEnabled=false;
    gameHasStoped=false;
    waytingForNarrator=false;
}
Scene13Layer::~Scene13Layer()
{

}
void Scene13Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void Scene13Layer::onEnter()
{
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    screenSize = CCDirector::sharedDirector()->getWinSize();
    this->setAccelerometerEnabled(true);
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene13_14_1_android.plist", "Scene13_14_1.pvr.ccz");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene13_14_2_android.plist", "Scene13_14_2.pvr.ccz");
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene13_14_1.plist", "Scene13_14_1.pvr.gz");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene13_14_2.plist", "Scene13_14_2.pvr.gz");
#endif
    
 
    this->setTouchEnabled(true);
    timerLabel = CCLabelTTF::create("72", "GillSans", 42);
    if (GameManager::sharedGameManager()->get_devise_resolution()==1)
    {
        timerLabel->setFontSize(84);
    }
    timerLabel->setColor(ccc3(206, 160, 172));
    commonNode =CCNode::create();
    commonNode->retain();
  
    slingShotPoles =CCSprite::createWithSpriteFrameName("poles.png");
    bacground=CliffsAndClouds::create();
    waves=WavesAndCriters::create();
	blackOverlayer = CCSprite::create("openingBackground.png");
    blackOverlayer->setScale(21.0f);
     blackOverlayer->setPosition(ccp(screenSize.width/2, screenSize.height/2));
    band=RubberBand::create();
    ship =Ship::create();
    starNode =SoundStarArrayNode::create();
   
   // waves.delegate = self;
    slingShotPoles->setPosition(ccp(512*(screenSize.width/1024), 120*(screenSize.height/768)));
    bacground->setPosition(ccp(0, 0));
    waves->setPosition(ccp(0,0));
    band->setPosition(ccp(0, 0));
   
    timerLabel->setPosition(ccp(512*(screenSize.width/1024), 720*(screenSize.height/768)));
    
    slingShotPoles->setScale(1/0.75f);
    animalsMissed=CCArray::create();
    animalsMissed->retain();
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()== 14)
    {
        blackOverlayer->setOpacity(120);
        commonNode->setPosition(ccp(0,-240*(screenSize.height/768)));
        starNode->setPosition(ccp(0, 640*(screenSize.height/768)));
        bacground->SetCloudsInvisible();
   
        SoundManager::sharedSoundManager()->startBackgroundSound();
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/NighBackgroundMusic.caf", true);
        ship->StartStopedBoat();
        waves->StartStoped();
        gameHasStoped = true;
        timerLabel->setOpacity(0);
    }
    else
    {
        blackOverlayer->setOpacity(0);
        commonNode->setPosition(ccp(0,0));
        starNode->setPosition(ccp(0, 1024*(screenSize.height/768)));
        SoundManager::sharedSoundManager()->stopBackgroundSound();
        SoundManager::sharedSoundManager()->startBackgroundSound();

        //[waves StartWaves];
        this->FillAnimalOnReserve();
        ship->StartBoat();
        waves->StartMoved();
        animalsInReserve=GameManager::sharedGameManager()->shuffle_array(animalsInReserve, animalsInReserve->count());
        this->GetNextAnimalToLaunch();
        timerLabel->setOpacity(255);
    }
    commonNode->addChild(bacground,10);
    commonNode->addChild(ship,15);
    commonNode->addChild(waves,20);
    commonNode->addChild(slingShotPoles,25);
    commonNode->addChild(timerLabel,25);
    commonNode->addChild(band,40);
    this->addChild(commonNode,10);
    this->addChild(starNode,20);
    this->addChild(blackOverlayer,15);
    this->schedule(schedule_selector(Scene13Layer::PlayNarrator),1.0f);
    this->schedule(schedule_selector(Scene13Layer::tick),1/60);
    timer = 72.0f;
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene13Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
   
}
SEL_CallFuncN Scene13Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler Scene13Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onNext_scene_clicked", Scene13Layer::onNext_scene_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPrevious_scene_clicked", Scene13Layer::onPrevious_scene_clicked);
   
    return NULL;
}
SEL_CCControlHandler Scene13Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
bool Scene13Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Scene13Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{

    bool bRet = false;
    return bRet;
}
void Scene13Layer::shouldAddPoints(int points ,CCPoint pos)
{
    //[commonUI AddPoints:pointsToAdd :pos];
}
void Scene13Layer::RemoveAllAnimals()
{
    CCObject *obj=NULL;
    CCARRAY_FOREACH(animlasLeftForSling,obj)
    {
        CCSprite *animal=(CCSprite *)obj;
        commonNode->removeChild(animal,true);
    }
    animlasLeftForSling->removeAllObjects();
    animalsMissed->removeAllObjects();
}
void Scene13Layer::PlayNarrator(float  dt)
{
    this->unschedule(schedule_selector(Scene13Layer::PlayNarrator));
    SoundManager::sharedSoundManager()->startNarrator();
    interactionsEnabled = false;
    waytingForNarrator = false;
}
void Scene13Layer::tick(float  dt)
{
    if (!interactionsEnabled && !waytingForNarrator)
    {
        if (!SoundManager::sharedSoundManager()->isNarratorPlaying())
        {
            interactionsEnabled = true;
            GameManager::sharedGameManager()->get_header()->MakeInteractionsEnabled();

        }
    }
    if (timer > 0)
    {
        timer-= dt;
        if (timer <= 0 && !gameHasStoped)
        {
            //Game has Ended!! Stop Everything!!!
            if (animalsInReserve->count() == 0 && animalsMissed->count() == 0)
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 13/scene13Congratulations.mp3"));
            }
            else
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 13/scene13CongratulationsMinor.mp3"));
            }
            GameManager::sharedGameManager()->get_header()->MakeInteractionsEnabled();
            this->make_noah_appear_without_bg();
            ship->StopBoat(false);
            waves->StopWaves();
            gameHasStoped = true;
        }
        else
        {
            this->UpdateTimerLabel();
        }
    }
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue() == 14)
    {
        ship->updateArkFromAccelerometer(accelY);
        return;
    }
    timerLabel->setPosition(bacground->getcloud2()->getPosition());   
}
void Scene13Layer::make_noah_appear_without_bg()
{
    int angle = 0;//arc4random()%4;
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setRotation(angle*90);
    int offsetValue;
    switch (angle)
    {
        case 0:
            offsetValue = rand()%600-300;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,0));
            break;
        case 2:
            offsetValue = rand()%600-300;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,screen_height+5));
            break;
        case 1:
            offsetValue = rand()%400-200;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(0-5,screen_height/2+offsetValue));
            
            break;
        case 3:
            offsetValue = rand()%400-200;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width+5,screen_height/2+offsetValue));
            
            break;
            
        default:
            break;
    }
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->MakeNoahAppearWithoutBackground();
}
void Scene13Layer::UpdateTimerLabel()
{
    timerLabel->setString(CCString::createWithFormat("%0.f",timer)->getCString());
}
void Scene13Layer::AnimalFinalDestination()
{
    if (animalsMissed->count())
    {
        animalsInReserve->insertObject(animalsMissed->lastObject(), 0);
        animalsMissed->removeLastObject();
    }
    if (ship->AnimalEnteredArk(animalToLaunch))
    {
       CCSprite *sprt=(CCSprite*)animlasLeftForSling->objectAtIndex(animalToLaunch->getindex());
       sprt->setOpacity(0);
       GameManager::sharedGameManager()->AddPoints(5, animalToLaunch->getimage()->getPosition(), this);
        TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/short_flourish_09.caf", false);
        }
        else
        {
              SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/short_flourish_09.ogg", false);
        }
    
        CCParticleSystemQuad* loadedFX=CCParticleSystemQuad::create("Scene13LoadedFX.plist");
        loadedFX->retain();
        loadedFX->setPosition(animalToLaunch->getimage()->getPosition());
        this->addChild(loadedFX,40);
        if (GameManager::sharedGameManager()->get_devise_resolution()==1)
        {
            loadedFX->setScale(2.0);
        }
        animalsOnArkCounter ++;
        if (animalsOnArkCounter == 5)
        {
            GameManager::sharedGameManager()->AddPoints(5, animalToLaunch->getimage()->getPosition(), this);
            animalsOnArkCounter = 0;
        }
        if (animalsInReserve->count() == 0 && animalsMissed->count() == 0)
        {
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 13/scene13Congratulations.mp3"));
            this->make_noah_appear_without_bg();
            commonNode->removeChild(animalToLaunch, true);
            TargetPlatform platForm = CCApplication::sharedApplication()->getTargetPlatform();
            if(platForm==kTargetIphone || platForm==kTargetIpad)
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/loadTheBoatCheer.caf",false);
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/NighBackgroundMusic.caf", false);
            }
            else
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/loadTheBoatCheer.ogg",false);
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/NighBackgroundMusic.caf", false);
                
            }
         

            ship->PlayPlume();
            timerLabel->setOpacity(0);
            ship->StopBoat(false);
            waves->StopWaves();
            gameHasStoped = true;
            return;
        }
    }
    else
    {
       if (ship->AnimalHitArk(animalToLaunch))
       {
            //Animal Missed the ark doors, but hit the ark, splat!
            animalsOnArkCounter = 0;
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/splat.mp3", false);
        }
       else
       {
            //Animal Missed the ark altogether, splash!
            animalsOnArkCounter = 0;
            CCParticleSystemQuad* splashFX= CCParticleSystemQuad::create("Scene13SplashFX.plist");
            splashFX->retain();
            splashFX->setPosition(animalToLaunch->getimage()->getPosition());
          
            this->addChild(splashFX,40);
           
            if (animalToLaunch->getimage()->getScale()> 0.4f)
            {
                
                splashFX->setScale(0.5f);
                
            }
            else if (animalToLaunch->getimage()->getScale() > 0.16f)
            {
                splashFX->setScale(0.36f);
            }
            else
            {
                splashFX->setScale(0.16f);
            }
           if (GameManager::sharedGameManager()->get_devise_resolution()==1)
           {
               splashFX->setScale(splashFX->getScale()*2);
           }
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/animalSplash.mp3", false);
            waves->AddSnorkelAnimal(animalToLaunch);
        }
        animalsMissed->insertObject(animalToLaunch, 0);
    }
    animalToLaunch->ResetAnimal();
    this->GetNextAnimalToLaunch();
}
void Scene13Layer::GetNextAnimalToLaunch()
{
    if(animalsInReserve->count() == 0)
    {
        animalToLaunch = (LaunchingAnimal*)animalsMissed->lastObject();
        commonNode->removeChild(animalToLaunch,true);
        if (animalToLaunch)
        {
            commonNode->addChild(animalToLaunch,30);
             animalsMissed->removeLastObject();
        }
    }
    else
    {
        commonNode->removeChild(animalToLaunch,true);
        animalToLaunch =(LaunchingAnimal*) animalsInReserve->lastObject();
        animalToLaunch->retain();
        if (animalToLaunch)
        {
            animalsInReserve->removeLastObject();
            commonNode->addChild(animalToLaunch,30);
        }
    }
}
void Scene13Layer::FillAnimalOnReserve()
{
    CCArray *animalsNames=CCArray::create();
    animalsNames->addObject(CCString::create("pig"));
    animalsNames->addObject(CCString::create("cow"));
    animalsNames->addObject(CCString::create("goat"));
    animalsNames->addObject(CCString::create("sheep"));
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(GameManager::sharedGameManager()->getstarStoreElements(),pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        CCString *str_Id=(CCString*)dict->objectForKey("groupId");
        CCString *str_status=(CCString*)dict->objectForKey("status");
        int groud_id=atoi(str_Id->getCString());
        int status_id=atoi(str_status->getCString());
        if (groud_id==GroupIDLoadingAnimals&&status_id==elementStatusBoughtSelected)
        {
            animalsNames->addObject(CCString::createWithFormat("%s",dict->valueForKey("fileName")->getCString()));
        }
    }
    animalsNames=GameManager::sharedGameManager()->shuffle_array(animalsNames, animalsNames->count());
    animalsNames=GameManager::sharedGameManager()->shuffle_array(animalsNames, animalsNames->count());
    animalsInReserve=CCArray::create();
    animalsInReserve->retain();
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(0),0));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(0),1));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(1),2));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(1),3));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(2),4));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(2),5));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(3),6));
    animalsInReserve->addObject(LaunchingAnimal::create((CCString*)animalsNames->objectAtIndex(3),7));
  
    CCString *str=(CCString*)animalsNames->objectAtIndex(0);
    CCSprite* smallAnimal1 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    
    str=(CCString*)animalsNames->objectAtIndex(0);
    CCSprite* smallAnimal2= CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(1);
    CCSprite* smallAnimal3 =CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(1);
    CCSprite* smallAnimal4 =CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(2);
    CCSprite* smallAnimal5 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(2);
    CCSprite* smallAnimal6 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(3);
    CCSprite* smallAnimal7 =CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    str=(CCString*)animalsNames->objectAtIndex(3);
    CCSprite* smallAnimal8 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("small%s.png",str->getCString())->getCString());
    
    smallAnimal1->setPosition(ccp(302*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal2->setPosition(ccp(362*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal3->setPosition(ccp(422*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal4->setPosition(ccp(482*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal5->setPosition(ccp(542*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal6->setPosition(ccp(602*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal7->setPosition(ccp(662*(screen_width/1024), 40*(screen_height/768)));
    smallAnimal8->setPosition(ccp(722*(screen_width/1024), 40*(screen_height/768)));
    
    smallAnimal1->setScale(1/0.75);
    smallAnimal2->setScale(1/0.75);
    smallAnimal3->setScale(1/0.75);
    smallAnimal4->setScale(1/0.75);
    smallAnimal5->setScale(1/0.75);
    smallAnimal6->setScale(1/0.75);
    smallAnimal7->setScale(1/0.75);
    smallAnimal8->setScale(1/0.75);

    commonNode->addChild(smallAnimal1,45);
    commonNode->addChild(smallAnimal2,45);
    commonNode->addChild(smallAnimal3,45);
    commonNode->addChild(smallAnimal4,45);
    commonNode->addChild(smallAnimal5,45);
    commonNode->addChild(smallAnimal6,45);
    commonNode->addChild(smallAnimal7,45);
    commonNode->addChild(smallAnimal8,45);
    ship->SetSmallAnimals(animalsNames);
    animlasLeftForSling=CCArray::create();
    animlasLeftForSling->retain();
    animlasLeftForSling->addObject(smallAnimal1);
    animlasLeftForSling->addObject(smallAnimal2);
    animlasLeftForSling->addObject(smallAnimal3);
    animlasLeftForSling->addObject(smallAnimal4);
    animlasLeftForSling->addObject(smallAnimal5);
    animlasLeftForSling->addObject(smallAnimal6);
    animlasLeftForSling->addObject(smallAnimal7);
    animlasLeftForSling->addObject(smallAnimal8);
}
void Scene13Layer::LaunchAnimal()
{
    this->unschedule(schedule_selector(Scene13Layer::LaunchAnimal));
    float time =animalToLaunch->LaunchAnimal();
    if (time != 0)
    {
        this->runAction(CCSequence::create(CCDelayTime::create(time),CCCallFunc::create(this, callfunc_selector(Scene13Layer::AnimalFinalDestination)),NULL));
        band->LetGoBand();
        CCLOG("launch time:%f",time);
    }
    else
    {
        CCLOG("time:%f",time);
    }
}
void Scene13Layer::didAccelerate(CCAcceleration* pAccelerationValue)
{
    static float prevX=0, prevY=0;
    	//#define kFilterFactor 0.05f
    #define kFilterFactor 1.0f
	// don't use filter. the code is here just as an example
    float accelX = (float) pAccelerationValue->x * kFilterFactor + (1- kFilterFactor)*prevX;
	accelY = (float) pAccelerationValue->y * kFilterFactor + (1- kFilterFactor)*prevY;
	prevX = accelX;
    //accelY =  accelY*(accelX/(sqrt(accelX*accelX)));
	prevY = accelY;
    accelY =  accelX*(accelY/(sqrt(accelY*accelY)));
   
   
}
void Scene13Layer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    CCLOG("GameManager::sharedGameManager()->getcurrent_scene().getValue() %d",GameManager::sharedGameManager()->getcurrent_scene().getValue());
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
    {
        if (GameManager::sharedGameManager()->isNodeAtPoint(animalToLaunch->getimage(), location))
        {
            isTouching = true;
        }
    }
    else
    starNode->testForTouchOnStar(location);
}
void Scene13Layer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (gameHasStoped)
    {
        starNode->touchMoved(location);
        return;
    }
    if (isTouching)
    {
        animalToLaunch->getimage()->setPosition(band->HandleTouch(location));
    }
}
void Scene13Layer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (isTouching&&GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
    {
        this->runAction(CCCallFunc::create(this, callfunc_selector(Scene13Layer::LaunchAnimal)));
    }
	isTouching = false;
	starNode->touchEnded();
}
void Scene13Layer::onPrevious_scene_clicked(CCObject* pSender)
{
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/nextButtoPressed.mp3", false);   
}
void Scene13Layer::onNext_scene_clicked(CCObject* pSender)
{
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/nextButtoPressed.mp3", false);
}