//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene16Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define startScale 0.0091f
#define startPositionY 28.0f
#define endScale 1.1f
Scene16Layer::Scene16Layer():interactionsEnabled(false),waytingForNarrator(false),isPlaying(false)
{
 
}
Scene16Layer::~Scene16Layer()
{
 
}
void Scene16Layer::onEnter()
{
    this->setTouchEnabled(true);
    this->setAccelerometerEnabled(true);
    waytingForNarrator = true;
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    screenSize =CCDirector::sharedDirector()->getWinSize();
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    thunderCount=0;
    oliveCount = 0;
    #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene16Images_android.plist", "Scene16Images.pvr.ccz");
    #elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("scene16Images.plist", "scene16Images.pvr.gz");
    #endif
    gradient=CCSprite::createWithSpriteFrameName("scene16SkyGrad.png");
    clouds1=CCSprite::createWithSpriteFrameName("scene16Clouds.png");
    clouds2=CCSprite::createWithSpriteFrameName("scene16Clouds.png");
    leftFloor=CCSprite::createWithSpriteFrameName("scene16ArkFloor.png");
    rightFloor=CCSprite::createWithSpriteFrameName("scene16ArkFloor.png");
    doveShadow=CCSprite::createWithSpriteFrameName("scene16DoveShadow.png");
    restartButton=CCSprite::create("replayButton.png");
    restartButton->setPosition(ccp(screenSize.width/2, screenSize.height/2));
    restartButton->setOpacity(0);
    rightArkLine=CCSprite::create("arkInnerDeckLinesRight.png");
    leftArkLine=CCSprite::create("arkInnerDeckLinesLeft.png");
    tiltToStir=CCSprite::create("TILT_IPAD_TO_STEER_SM.png");
    dove =FlyingDoveNode::create();
    lightSign =LightSignNode::create(this,callfuncO_selector(Scene16Layer::ShouldStartDove));
    speedmometer =SpeedometerNode::create(this,callfuncO_selector(Scene16Layer::DoveShouldLiftOff) );
    floorNode =CCNode::create();
    rightArkLineNode =CCNode::create();
    rightArkLineNode->retain();
    leftArkLineNode =CCNode::create();
    leftArkLineNode->retain();
    fuelGauge = fuelGaugeNode::create(72.0f);
    tapToFly = TapToFlapNode::create();
    rightFloor->setScaleX(-1);
    rightArkLine->setScale(startScale);
    leftArkLine->setScale(endScale*startPositionY/140.0f);

    clouds2->setOpacity(0);
    tiltToStir->setOpacity(0);
    tiltToStir->setPosition(ccp(screenSize.width/2, screenSize.height/2 + 200*(screen_height/768)));
    gradient->setPosition(ccp(screenSize.width/2, screenSize.height - gradient->getContentSize().height/2));
    clouds1->setPosition( ccp(screenSize.width/2,(12*screen_height/100)+clouds1->getContentSize().height/2));
    clouds2->setPosition(ccp(screenSize.width/2, (12*screen_height/100)+clouds2->getContentSize().height/2));
 
    leftFloor->setPosition(ccp(screenSize.width/2 - leftFloor->getContentSize().width/2, (12*screen_height/100) + leftFloor->getContentSize().height/2));
    rightFloor->setPosition( ccp(screenSize.width/2 + rightFloor->getContentSize().width/2,(12*screen_height/100) + leftFloor->getContentSize().height/2));
    doveShadow->setPosition( ccp(330*(screen_width/1024) + doveShadow->getContentSize().width/2,(12*screen_height/100) + doveShadow->getContentSize().height/2));
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
            rightArkLine->setPosition( ccp(screenSize.width/2 + rightArkLine->getContentSize().width/2*rightArkLine->getScale(),screen_height-512*(screen_height/768) - rightArkLine->getContentSize().height/2));
            leftArkLine->setPosition(ccp(screenSize.width/2 - leftArkLine->getContentSize().width/2*leftArkLine->getScale(),screen_height-512*(screen_height/768) -leftArkLine->getContentSize().height/2));
        }
        break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                rightArkLine->setPosition( ccp(screenSize.width/2 + rightArkLine->getContentSize().width/2*rightArkLine->getScale(),(35*screen_height/100) + rightArkLine->getContentSize().height/2));
                leftArkLine->setPosition(ccp(screenSize.width/2 - leftArkLine->getContentSize().width/2*leftArkLine->getScale(),(35*screen_height/100) + leftArkLine->getContentSize().height/2));

            }
            else
            {
                rightArkLine->setPosition( ccp(screenSize.width/2 + rightArkLine->getContentSize().width/2*rightArkLine->getScale(),screen_height-512*(screen_height/768) - rightArkLine->getContentSize().height/2));
                leftArkLine->setPosition(ccp(screenSize.width/2 - leftArkLine->getContentSize().width/2*leftArkLine->getScale(),screen_height-512*(screen_height/768) -leftArkLine->getContentSize().height/2));
  
            }
        }
        break;
        case 3:
        {
            rightArkLine->setPosition( ccp(screenSize.width/2 + rightArkLine->getContentSize().width/2*rightArkLine->getScale(),(35*screen_height/100) + rightArkLine->getContentSize().height/2));
            leftArkLine->setPosition(ccp(screenSize.width/2 - leftArkLine->getContentSize().width/2*leftArkLine->getScale(),(35*screen_height/100) + leftArkLine->getContentSize().height/2));

        }
        break;
        case 4:
        {
            rightArkLine->setPosition( ccp(screenSize.width/2 + rightArkLine->getContentSize().width/2*rightArkLine->getScale(),(35*screen_height/100) + rightArkLine->getContentSize().height/2));
            leftArkLine->setPosition(ccp(screenSize.width/2 - leftArkLine->getContentSize().width/2*leftArkLine->getScale(),(35*screen_height/100) + leftArkLine->getContentSize().height/2));
        }
        break;
        default:
            break;
    }
    rightArkLineNode->setPosition(ccp(0,0));
    leftArkLineNode->setPosition(ccp(0,-startPositionY));
    dove->setPosition(ccp(0,0));
    floorNode->setPosition(ccp(0,0));
    lightSign->setPosition(ccp(screenSize.width/2, screenSize.height - 184*(screen_height/768)));
    speedmometer->setPosition(ccp(screenSize.width/2, screenSize.height - 184*(screen_height/768)));
    fuelGauge->setPosition(ccp(37*(screen_width/1024), 454*(screen_height/768)));
    tapToFly->setPosition(ccp(0, 0));
    
    this->addChild(gradient,10);
    this->addChild(clouds1,22);
    this->addChild(clouds2,20);
    this->addChild(floorNode,30);
    floorNode->addChild(leftFloor,30);
    floorNode->addChild(rightFloor,30);
    floorNode->addChild(leftArkLineNode,40);
    floorNode->addChild(rightArkLineNode,40);
    rightArkLineNode->addChild(rightArkLine,10);
    leftArkLineNode->addChild(leftArkLine,10);
    floorNode->addChild(doveShadow,50);
    this->addChild(dove,50);
    this->addChild(lightSign,60);
    this->addChild(fuelGauge,60);
    this->addChild(speedmometer,70);
    this->addChild(restartButton,80);
    this->addChild(tiltToStir,80);
    this->addChild(tapToFly,45);
    this->schedule(schedule_selector(Scene16Layer::tick), 1/60);
    this->schedule(schedule_selector(Scene16Layer::PlayNarrator),1.0f);
    isPlaying = true;
    branches =CCArray::create();
    branches->retain();
    CCLayer::onEnter();
}
void Scene16Layer::onExit()
{
    CCObject *obj=NULL;
    CCARRAY_FOREACH(branches, obj)
    {
        BranchNode *objbranch=(BranchNode*)obj;
        this->removeChild(objbranch, true);
    }
//    branches->removeAllObjects();
//    dove->unscheduleAllSelectors();
//    fuelGauge->Stop();
//    speedmometer->unscheduleAllSelectors();
//    lightSign->unscheduleAllSelectors();
//    leftArkLine->stopAllActions();
//    leftArkLineNode->stopAllActions();
//    rightArkLine->stopAllActions();
//    rightArkLineNode->stopAllActions();
//    this->unscheduleAllSelectors();
//    this->stopAllActions();
//    this->removeAllChildrenWithCleanup(true);
//    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene16Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    platform = CCApplication::sharedApplication()->getTargetPlatform();

    CCLOG("on loaded called");
}
SEL_CallFuncN Scene16Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler Scene16Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene16Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene16Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Scene16Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void  Scene16Layer::ResetScene()
{
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    this->unscheduleAllSelectors();
    interactionsEnabled = false;
    waytingForNarrator = false;
    isPlaying = true;
    numberOfTouches = 0;
    thunderCount = 0;
    oliveCount = 0;
    floorNode->setPosition(ccp(0,0));
    rightArkLine->setScale(startScale);
    leftArkLine->setScale( endScale*startPositionY/140.0f);
    rightArkLineNode->setPosition(0,0);
    leftArkLineNode->setPosition(ccp(0,-startPositionY));
//    clouds1->setPosition( ccp(screenSize.width/2, screenSize.height - clouds1->getContentSize().height/2));
//    clouds2->setPosition(ccp(screenSize.width/2, screenSize.height - clouds2->getContentSize().height/2));
    clouds2->setOpacity(0);
    restartButton->setOpacity(0);
    tiltToStir->setOpacity(0);
    leftArkLine->stopAllActions();
    leftArkLineNode->stopAllActions();
    rightArkLineNode->stopAllActions();
    rightArkLine->stopAllActions();
    clouds1->stopAllActions();
    clouds2->stopAllActions();
    fuelGauge->ResetFuelConsuption();
    this->schedule(schedule_selector(Scene16Layer::tick),1/60);
    this->schedule(schedule_selector(Scene16Layer::PlayNarrator),1.0f);
}
void Scene16Layer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
        CCTouch *touch = (CCTouch*)pTouches->anyObject();
        CCPoint location = touch->getLocationInView();
        location=CCDirector::sharedDirector()->convertToGL(location);
        if (!isPlaying && !dove->getdoveLost())
        {
            if (interactionsEnabled)
            {
                numberOfTouches ++;
                dove->WasDoveTouch();
                if (!dove->gethasTakeOff())
                {
                    speedmometer->IncreaseSpeed();
                                
                }
                if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_touch))
                {
                    SoundManager::sharedSoundManager()->stopSoundEffect(sound_touch);
                }
                if (platform == kTargetIpad || platform ==kTargetIphone)
                {
                    sound_touch=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16onTouch.caf", false);
                }
                else
                {
                     sound_touch=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16onTouch.ogg", false);
                }
              this->schedule(schedule_selector(Scene16Layer::IncreaseSpeed));
            }
        }
        if (dove->getdoveLost())
        {
            if (GameManager::sharedGameManager()->isNodeAtPoint(restartButton, location))
            {
                dove->ResetDove();
                speedmometer->ResetSpeedometer();
                lightSign->ResetLights();
                
                this->ResetScene();
            }
        }
}
void Scene16Layer::InstructionGo()
{
    //this->make_noah_appear_without_bg();
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setwithSound(false);
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
    GameManager::sharedGameManager()->get_header()->SwitchOnInstructionalNoah(0.8f, 2);
}
void Scene16Layer::InstructionAreYouReady()
{
    //this->make_noah_appear_without_bg();
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setwithSound(false);
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
    GameManager::sharedGameManager()->get_header()->SwitchOnInstructionalNoah(0.1f, 0);
    this->runAction(CCSequence::create(CCDelayTime::create(0.1f+0.9f),CCCallFunc::create(this,callfunc_selector(Scene16Layer::InstructionGo)),NULL));
}
void Scene16Layer::make_noah_appear_without_bg()
{
    int angle =2;//rand()%4;
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
    //GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->MakeNoahAppearWithoutBackground();
}
void Scene16Layer::StartCloud2()
{
    float time2 = 24.0f;
    //    if (clouds2->getOpacity()== 0)
    //    {
    clouds2->runAction(CCFadeIn::create(time2/6));
    //    }
    clouds2->runAction(CCSequence::create(CCEaseIn::create(CCScaleTo::create(time2, 4.0f),2),CCScaleTo::create(0, 1.0f),NULL));
    //  CCSequence *seq1=CCSequence::create(CCEaseIn::create(CCScaleTo::create(time2, 4.0f),2),CCScaleTo::create(0, 1.0f),NULL);
    // CCSequence *seq2=CCSequence::create(CCDelayTime::create(time2*3/6),CCCallFunc::create(this, callfunc_selector(Scene16Layer::StartCloud1)),CCDelayTime::create(time2*2/6),CCFadeOut::create(time2/6),NULL);
    clouds2->runAction(CCSequence::create(CCDelayTime::create(time2*3/6),CCCallFunc::create(this, callfunc_selector(Scene16Layer::StartCloud1)),CCDelayTime::create(time2*2/6),CCFadeOut::create(time2/6),NULL));
    // CCSpawn *spwn=CCSpawn::create(seq1,seq2,NULL);
    // clouds2->runAction(spwn);
}
void Scene16Layer::StartCloud1()
{
    float time2 = 24.0f;
    if (clouds1->getOpacity()== 0)
    {
        clouds1->runAction(CCFadeIn::create(time2/6));
    }
    
    clouds1->runAction(CCSequence::create(CCEaseIn::create(CCScaleTo::create(time2, 4.0f), 2),CCScaleTo::create(0, 1.0f),NULL));
    //CCSequence *seq1=CCSequence::create(CCEaseIn::create(CCScaleTo::create(time2, 4.0f), 2),CCScaleTo::create(0, 1.0f),NULL);
    //CCSequence *seq2=CCSequence::create(CCDelayTime::create(time2*(3/6)),CCCallFunc::create(this, callfunc_selector(Scene16Layer::StartCloud2)),CCDelayTime::create(time2*(2/6)),CCFadeOut::create(time2/6),NULL);
    clouds1->runAction(CCSequence::create(CCDelayTime::create(time2*3/6),CCCallFunc::create(this, callfunc_selector(Scene16Layer::StartCloud2)),CCDelayTime::create(time2*2/6),CCFadeOut::create(time2/6),NULL));
    //CCSpawn *spwn=CCSpawn::create(seq1,seq2,NULL);
    //clouds1->runAction(spwn);
}
void Scene16Layer::StartFlightMovements()
{
    this->StartCloud1();
}
void Scene16Layer::TestForOliveBranchCatch()
{
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(branches,pobj)
    {
        BranchNode *branchNode=(BranchNode*)pobj;
        if(branchNode->getshouldBeRemoved_1()==true)
        {
            if (branchNode->isPointOnImage(ccp(dove->getmoveXNode()->getPositionX(), dove->getmoveYNode()->getPositionY())))
                {
                    
                    switch (branchNode->gettype_())
                    {
                    case green:
                        GameManager::sharedGameManager()->AddPoints(1, branchNode->getimage_()->getPosition(), this);
                        branches->removeObject(branchNode);
                        this->removeChild(branchNode ,true);
                        return;
                        break;
                    case red:
                        GameManager::sharedGameManager()->AddPoints(10, branchNode->getimage_()->getPosition(), this);
                        branches->removeObject(branchNode);
                        this->removeChild(branchNode ,true);
                        return;
                        break;
                    default:
                        {
                            this->unschedule(schedule_selector(Scene16Layer::WaitForMusicToEnd));
                            this->GameHasEnded();
                       }
                        return;
                        break;
                }
                }
            else
            {
                branches->removeObject(branchNode);
                this->removeChild(branchNode,true);
                return;
            }
        }
    }
}
void Scene16Layer::setMovmentForSprite(BranchNode* branchNode)
{
    float randx =(rand()%7600 + 1320.0f)/10.0f;
    if (branchNode->gettype_()==cloud)
    {
        branchNode=(BranchCloudNode*)branchNode;
    }
    float randy =(rand()%4400 + 2000.0f)/10.0f;
    branchNode->getimage_()->setPosition(ccp(randx*(screen_width/1024),randy*(screen_height/768)));
    branchNode->getimage_()->setScale(0.04f);
    branchNode->getimage_()->setOpacity(0);
    branchNode->getimage_()->runAction(CCSequence::create(CCFadeIn::create(0.2f),CCEaseExponentialIn::create(CCScaleTo::create(4.8f, 1.0f)),CCCallFunc::create(branchNode, callfunc_selector(BranchNode::setToRemove)),CCCallFunc::create(this, callfunc_selector(Scene16Layer::TestForOliveBranchCatch)),CCFadeOut::create(0.2f),NULL));
}
void Scene16Layer::StartOliveBranch(float dt)
{
    this->unschedule(schedule_selector(Scene16Layer::StartOliveBranch));
    thunderCount +=1;
    oliveCount +=1;
    bool shouldShowThunder = false;
    if (thunderCount >= 7)
    {
        if (rand()%2 == 0)
        {
            thunderCount = 0;
            shouldShowThunder = true;
        }
    }
    if (shouldShowThunder)
    {
        //Show Thunder clouds
        BranchNode *thunderCloud=BranchNode::create(cloud);
        //BranchNode* thunderCloud =BranchNode::create(cloud);
        this->addChild(thunderCloud,25);
        branches->addObject(thunderCloud);
        this->setMovmentForSprite(thunderCloud);
    }
    else if (oliveCount >= 10)
    {
        if (rand()%2 == 0)
        {
            //Show Red Branch
            oliveCount = 0;
            BranchNode* redBranch = BranchNode::create(red);
            this->addChild(redBranch,25);
            branches->addObject(redBranch);
            this->setMovmentForSprite(redBranch);
        }
    }
    else
    {
        //Show Green Branch
        BranchNode* oliveBranch =BranchNode::create(green);
        this->addChild(oliveBranch,25);
        branches->addObject(oliveBranch);
        this->setMovmentForSprite(oliveBranch);
      
    }
    float randTime = (rand()%2000+ 600.0f)/1000.0f;
    this->schedule(schedule_selector(Scene16Layer::StartOliveBranch),randTime);
}
void Scene16Layer::ShowTiltToStir()
{
    tiltToStir->runAction(CCSequence::create(CCFadeIn::create(0.3f),CCRotateTo::create(0.4f, -30.0f),CCRotateTo::create(0.8f,30.0f),CCRotateTo::create(0.8f,-30.0f),CCRotateTo::create(0.8f,30.0f),CCRotateTo::create(0.4f,0.0f),CCFadeOut::create(0.3f),NULL));
}
void Scene16Layer::DoveShouldLiftOff()
{
    if (SoundManager::sharedSoundManager()->isEffectPlaying(idleDove))
        SoundManager::sharedSoundManager()->stopSoundEffect(idleDove);

    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        dovetakeoff=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16DoveTakeFlight.caf", false);
    }
    else
    {
         dovetakeoff=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16DoveTakeFlight.ogg", false);
    }
    this->ShowTiltToStir();
    dove->LiftOff();
    floorNode->runAction(CCSequence::create(CCEaseInOut::create(CCMoveTo::create(2.4f, ccp(0,-220*(screen_height/768))), 2.0f),NULL));
    float randTime = (rand()%2000+ 600.0f)/1000.0f;
    this->schedule(schedule_selector(Scene16Layer::StartOliveBranch),randTime);
}
void Scene16Layer::MakeRestartAppear()
{
    restartButton->setOpacity(255);
}
void Scene16Layer::GameHasEnded()
{
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(branches, pobj)
    {
        BranchNode *branchnode=(BranchNode*)pobj;
        this->removeChild(branchnode, true);
    }
    branches->removeAllObjects();
    if (SoundManager::sharedSoundManager()->isEffectPlaying(dovetakeoff))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(dovetakeoff);
    }
    this->unschedule(schedule_selector(Scene16Layer::StartOliveBranch));
    dove->setdoveLost(true);
    dove->MoveToStartPosition();
    floorNode->runAction(CCSequence::create(CCEaseInOut::create(CCMoveTo::create(2.4f, ccp(0, 0)), 2),CCCallFunc::create(this,callfunc_selector(Scene16Layer::MakeRestartAppear)),NULL));
}
void Scene16Layer::WaitForMusicToEnd(float dt)
{
    if (!SoundManager::sharedSoundManager()->is_backgroundMusicPlaying())
    {
        this->GameHasEnded();
        this->unschedule(schedule_selector(Scene16Layer::WaitForMusicToEnd));
        return;
    }
    if (dove->getdoveLost())
    {
        this->GameHasEnded();
        this->unschedule(schedule_selector(Scene16Layer::WaitForMusicToEnd));
        return;
    }
}
void Scene16Layer::ShouldStartDove()
{
    SoundManager::sharedSoundManager()->startBackgroundSound();
    tapToFly->AppearAndAnimate();
    fuelGauge->StartFuelConsuption();
    this->schedule(schedule_selector(Scene16Layer::WaitForMusicToEnd));
    this->runAction(CCSequence::create(CCDelayTime::create(0.2f),CCCallFunc::create(speedmometer, callfunc_selector(SpeedometerNode::Start)),NULL));
    interactionsEnabled = true;
    isPlaying = false;
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        idleDove=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16IdleDove.caf", true);
    }
    else
    {
        idleDove=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 16/scene16IdleDove.ogg", true);
    }
    this->StartFlightMovements();
}
void Scene16Layer::WaitForSpeechToEnd(float dt)
{
    //CCLog("speech completed");
    if (!interactionsEnabled && !waytingForNarrator)
    {
//        if (SoundManager::sharedSoundManager()->isNarratorPlaying())
//        {
            this->unschedule(schedule_selector(Scene16Layer::WaitForSpeechToEnd));
            lightSign->Start();
            this->runAction(CCSequence::create(CCDelayTime::create(1.2f),CCCallFunc::create(this, callfunc_selector(Scene16Layer::InstructionAreYouReady)),NULL));
            this->runAction(CCSequence::create(CCDelayTime::create(1.2f),CCCallFunc::create(lightSign, callfunc_selector(LightSignNode::StartLightChange)),NULL));
//        }
    }
}
void Scene16Layer::PlayNarrator(float dt)
{
    this->unschedule(schedule_selector(Scene16Layer::PlayNarrator));
    SoundManager::sharedSoundManager()->startNarrator();
    interactionsEnabled = false;
    waytingForNarrator = false;
    this->schedule(schedule_selector(Scene16Layer::WaitForSpeechToEnd), 6.0, 0, 6.0);
    // this->schedule(schedule_selector(Scene16Layer::WaitForSpeechToEnd), 1.0f);
}
void Scene16Layer::IncreaseSpeed(float dt)
{
    linesSpeed += 580*dt;
    increaseSpeedTimer+=dt;
    if (increaseSpeedTimer >= 0.8f || linesSpeed >= 1400.0f)
    {
        this->unschedule(schedule_selector(Scene16Layer::IncreaseSpeed));
        increaseSpeedTimer = 0;
    }
}
void Scene16Layer::didAccelerate(CCAcceleration* pAccelerationValue)
{
    static float prevX=0, prevY=0;
    #define kFilterFactor 1.0f
	// don't use filter. the code is here just as an example
	float accelX = (float) pAccelerationValue->x * kFilterFactor + (1- kFilterFactor)*prevX;
	accelY = (float) pAccelerationValue->y * kFilterFactor + (1- kFilterFactor)*prevY;
	prevX = accelX;
   // accelY =  accelY*(accelX/(sqrt(accelX*accelX)));
	prevY = accelY;
    accelY =  accelX*(accelY/(sqrt(accelY*accelY)));
}
void Scene16Layer::DoveWasTouched(CCObject *pobject)
{
    
}
void Scene16Layer::tick(float dt)
{
    clouds1->setPosition(ccp(clouds1->getPositionX(),screen_height-(clouds1->getContentSize().height - clouds1->getContentSize().height/2*clouds1->getScale())));
    clouds2->setPosition(ccp(clouds2->getPositionX(),screen_height-(clouds2->getContentSize().height - clouds2->getContentSize().height/2*clouds2->getScale())));
    /* if (screen_height>=768)
     {
     clouds1->setPosition(ccp(clouds1->getPositionX(),(12*screen_height/100)+(clouds1->getContentSize().height + clouds1->getContentSize().height/2*clouds1->getScale())));
     clouds2->setPosition( ccp(clouds2->getPositionX(),(12*screen_height/100)+clouds2->getContentSize().height + clouds2->getContentSize().height/2*clouds2->getScale()));
     }
     else
     {
     clouds1->setPosition(ccp(clouds1->getPositionX(),(12*screen_height/100)+(clouds1->getContentSize().height/2 + clouds1->getContentSize().height/2*clouds1->getScale())));
     clouds2->setPosition( ccp(clouds2->getPositionX(),(12*screen_height/100)+clouds2->getContentSize().height/2 + clouds2->getContentSize().height/2*clouds2->getScale()));
     }*/
    dove->Accelerate(accelY);
    if (linesSpeed > 0)
    {
        if(leftArkLineNode->getPositionY()<=-140.0f)
        {
            leftArkLine->setScale(startScale);
            leftArkLineNode->setPosition(0,0);
        }
        else
        {
            leftArkLineNode->setPosition(ccp(0,leftArkLineNode->getPositionY()-linesSpeed*dt*leftArkLine->getScale()));
            leftArkLine->setScale(leftArkLineNode->getPositionY()*1.10f/(-140.0f*screen_height/768));
            if (leftArkLine->getScale() < startScale)
            {
                leftArkLine->setScale(startScale);
            }
        }
        if(rightArkLineNode->getPositionY()<=-140.0f)
        {
            rightArkLine->setScale(startScale);
            rightArkLineNode->setPosition(ccp(0, 0));
        }
        else
        {
            rightArkLineNode->setPosition(ccp(0, rightArkLineNode->getPositionY()-linesSpeed*dt*rightArkLineNode->getScale()));
            rightArkLine->setScale(rightArkLineNode->getPositionY()*1.10f/(-140.0f*screen_height/768));
            if (rightArkLine->getScale()< startScale)
            {
                rightArkLine->setScale(startScale);
            }
        }
        linesSpeed -= 400*dt;
        if(linesSpeed<0)
        {
            CCLog("stop moving");
            linesSpeed = 0;
            dove->StopMoving();
            this->unschedule(schedule_selector(Scene16Layer::IncreaseSpeed));
        }
    }
    rightArkLine->setPosition(ccp(screenSize.width/2 + (rightArkLine->getContentSize().width/2)*rightArkLine->getScale(),rightArkLine->getPositionY()));
    leftArkLine->setPosition(ccp(screenSize.width/2 - (leftArkLine->getContentSize().width/2)*leftArkLine->getScale(),leftArkLine->getPositionY()));
}