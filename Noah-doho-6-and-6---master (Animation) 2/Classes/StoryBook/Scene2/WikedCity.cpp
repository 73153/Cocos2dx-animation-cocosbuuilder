//
//  WikedCity.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "WikedCity.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
#include "../../GameManager/common_function.h"
#include "../../StoryBook/Scene2/WickedFireLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;

#define cityOffsetY 113
#define TimeForWikedCityToSetIn 6.6f
#define spickyOffsetY 60
WikedCity::WikedCity():mAnimationManager(NULL),city(NULL),background(NULL),thief(NULL),mean(NULL),drunk(NULL),choke(NULL),fire1(NULL),fire2(NULL),fire3(NULL),fire4(NULL)
{
    windowArray=CCArray::create();
    windowArray->retain();
    windowToshow=CCSprite::create();
    windowToshow->retain();
}
WikedCity::~WikedCity()
{
    
}
void WikedCity::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void WikedCity::onEnter()
{
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    halfWidth = screenSize.width/2;
    halfHeight = screenSize.height/2;
    
    
    windowToshow = (CCSprite*)windowArray->randomObject();
//    if (newWindow)
//    {
//        while (windowToshow==newWindow)
//        {
//            windowArray=GameManager::sharedGameManager()->shuffle_array(windowArray, windowArray->count());
//            newWindow=(CCSprite*)windowArray->lastObject();
//        }
//    }
//    windowToshow = newWindow;
    windowArray->addObject(mean);
    windowArray->addObject(choke);
    windowArray->addObject(drunk);
    windowArray->addObject(thief);
    mean->setOpacity(0);
    choke->setOpacity(0);
    drunk->setOpacity(0);
    thief->setOpacity(0);
   
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void WikedCity::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN WikedCity::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler WikedCity::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler WikedCity::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool WikedCity::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "city", CCSprite *, this->city);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "background", CCSprite *, this->background);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "thief", CCSprite *, this->thief);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mean", CCSprite *, this->mean);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "drunk", CCSprite *, this->drunk);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "choke", CCSprite *, this->choke);

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fire1", WickedFire *, this->fire1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fire2", WickedFire *, this->fire2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fire3", WickedFire *, this->fire3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fire4", WickedFire *, this->fire4);
    return false;
}
bool WikedCity::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void WikedCity::EnableInteractions()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    interactionsEnabled = true;
    fire1->InitFire();
    fire2->InitFire();
    fire3->InitFire();
    fire4->InitFire();
    continousFire=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireLong.mp3", true);
    
    touchHereFX_1=CCParticleSystemQuad::create("touchHere2SecneEffect.plist");
    touchHereFX_1->retain();
    touchHereFX_2=CCParticleSystemQuad::create("touchHere2SecneEffect.plist");
     touchHereFX_2->retain();
    touchHereFX_3=CCParticleSystemQuad::create("touchHere2SecneEffect.plist");
     touchHereFX_3->retain();
    touchHereFX_4=CCParticleSystemQuad::create("touchHere2SecneEffect.plist");
     touchHereFX_4->retain();
    this->addChild(touchHereFX_1,22);
    this->addChild(touchHereFX_2,22);
    this->addChild(touchHereFX_3,22);
    this->addChild(touchHereFX_4,22);
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        mean->setPosition(ccpAdd(mean->getPosition(), ccp(0, -mean->getContentSize().height/3.5)));
        thief->setPosition(ccpAdd(thief->getPosition(), ccp(0, -thief->getContentSize().height/3.5)));
        drunk->setPosition(ccpAdd(drunk->getPosition(), ccp(0, -drunk->getContentSize().height/3.5)));
        choke->setPosition(ccpAdd(choke->getPosition(), ccp(0, -choke->getContentSize().height/3.5)));
    #endif
    touchHereFX_1->setPosition(mean->getPosition());
    touchHereFX_2->setPosition(thief->getPosition());
    touchHereFX_3->setPosition(choke->getPosition());
    touchHereFX_4->setPosition(drunk->getPosition());
    float randTime = (rand()%4000 + 4000.0f)/1000.0f;
    this->schedule(schedule_selector(WikedCity::ShowWindow),randTime);
}
#warning show tips
void WikedCity::show_tips()
{
    if (CCUserDefault::sharedUserDefault()->getBoolForKey("Tips")==false)
    {
        GameManager::sharedGameManager()->get_header()->onToggleClicked(NULL);
        GameManager::sharedGameManager()->get_header()->start_showing_tips();
        CCUserDefault::sharedUserDefault()->setBoolForKey("Tips",true);
        CCUserDefault::sharedUserDefault()->flush();
    }
    
}
void WikedCity::DisableInteractions()
{
    interactionsEnabled = false;
}
void WikedCity::StopSounds()
{
    SoundManager::sharedSoundManager()->stopSoundEffect(continousFire);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    city->stopAllActions();
    background->stopAllActions();
    windowToshow->stopAllActions();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);    
}
void WikedCity::WindowWasPressed(CCObject *psender)
{
    int soundToplay = rand()%7 +1;
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();

    switch (soundToplay)
    {
        case 1:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Annehelm Scream.caf", false);
            }
            else
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Annehelm Scream.ogg", false);
            }
            
            break;
        case 2:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Boo Crowd.caf", false);
            }
            else
            {  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Boo Crowd.ogg", false);
            }
          
            break;
        case 3:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Crash Metal 5.caf", false);
            }
            else
            {  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Crash Metal 5.ogg", false);
            }
          
            break;
        case 4:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Horror Crazy People.caf", false);
            }
            else
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Horror Crazy People.ogg", false);
            }
            
            break;
        case 5:
            if(platform==kTargetIpad || platform==kTargetIphone)
            { SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.caf", false);
            }
            else
            { SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Jerremyhelm Evil Laugh.ogg", false);
            }
            
            break;
        case 6:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Philhelm Whimper.caf", false);
            }
            else
            {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Philhelm Whimper.ogg", false);
            }
            
            
            break;
        case 7:
            if(platform==kTargetIpad || platform==kTargetIphone)
            {   SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Smash Glass.caf", false);
            }
            else
            {   SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/Smash Glass.ogg", false);
            }
         
            break;
            
        default:
            break;
    }
}
void WikedCity::GetCityToNormal()
{
    city->setRotation(0.0f);
    city->setScale(1.0);
    background->setScale(2.2f);
    city->setPosition(ccp(0, cityOffsetY));
    this->schedule(schedule_selector(WikedCity::PlayNarrator), 0.8f);
   
}
void WikedCity::ShowWindow(CCTime dt)
{
    this->unschedule(schedule_selector(WikedCity::ShowWindow));
    CCSprite* newWindow = (CCSprite*)windowArray->randomObject();
    if (newWindow)
    {
        while (windowToshow==newWindow)
        {
            windowArray=GameManager::sharedGameManager()->shuffle_array(windowArray, windowArray->count());
            newWindow=(CCSprite*)windowArray->lastObject();
        }
    }
    windowToshow = newWindow;
        windowToshow->runAction(CCSequence::create(CCFadeIn::create(0.16),CCCallFunc::create(this, callfunc_selector(WikedCity::PlayWindowSound)),CCDelayTime::create(1.0f),CCFadeOut::create(0.16f),NULL));
    float randTime = (rand()%3600 + 3200.0f)/1000.0f;
    this->schedule(schedule_selector(WikedCity::ShowWindow), randTime);
}
void WikedCity::PlayWindowSound()
{
    if (windowToshow)
    {
        TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {
            if(windowToshow==mean)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/mean.caf", false);
                }
                else
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/mean.ogg", false);
                }
            }
            if(windowToshow ==choke)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/choke.caf", false);
                }
                else
                {SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/choke.ogg", false);
                }
                
            }
            if(windowToshow==thief)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/thief.caf", false);
                }
                else
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/thief.ogg", false);
                }
                
                
            }
            if(windowToshow ==drunk)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/drunk.caf", false);
                }
                else
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/drunk.ogg", false);
                }
                
            }
        }
        else
        {
            if(windowToshow==mean)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                     SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/mean.caf", false);
                }
                else
                {
                     SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/mean.ogg", false);
                }
               
                
            }
            if(windowToshow ==choke)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/choke.caf", false);
                }
                else
                { SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/choke.ogg", false);
                }
               
            }
            if(windowToshow==thief)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                       SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/thief.caf", false);
                }
                else
                {
                       SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/thief.ogg", false);
                }
             
                
            }
            if(windowToshow ==drunk)
            {
                if(platform==kTargetIpad || platform==kTargetIphone)
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/drunk.caf", false);
                }
                else
                {
                    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/drunk.ogg", false);
                }
                
            }
        }
    }
}
void WikedCity::PlayNarrator(CCTime dt)
{
    this->unschedule(schedule_selector(WikedCity::PlayNarrator));
    GameManager::sharedGameManager()->setcurrent_scene(2);
    GameManager::sharedGameManager()->set_footer_text(2);
    SoundManager::sharedSoundManager()->startNarrator();
}
bool WikedCity::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();

    CCPoint point =touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    if (windowToshow)
    {
        if (GameManager::sharedGameManager()->isNodeAtPoint(windowToshow, point)&&windowToshow->getOpacity()>= 100)
        {
            //Should Increase a point
            GameManager::sharedGameManager()->AddPoints(5,this->getPosition(), this);
            CCLOG("window touched");
            return true;
        }
        
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fire1->getfire(), point))
    {
        numberOfExtinguishedFires++;
        fire1->ExtingFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.caf", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.ogg", false);
        }
        
       return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fire2->getfire(), point))
    {
        numberOfExtinguishedFires++;
        fire2->ExtingFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
             SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.caf", false);
        }
        else
        {
             SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.ogg", false);
        }
       
        return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fire3->getfire(), point))
    {
        numberOfExtinguishedFires++;
        fire3->ExtingFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.caf", false);
        }
        else
        {   SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.ogg", false);
        }
     
        return true;
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(fire4->getfire(), point))
    {
        numberOfExtinguishedFires++;
        fire4->ExtingFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
              SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.caf", false);
        }
        else
        {  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeOut.ogg", false);
        }
      
        return true;
    }
    return false;
}
void WikedCity::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();

    /* do your stuff here */
    CCPoint touchPoint =touch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    if(fire1->getisExtinguished() && GameManager::sharedGameManager()->isNodeAtPoint(fire1->getfire(), touchPoint))
    {
        fire1->RestartFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
               SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.mp3", false);
        }
        else
        {
               SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.ogg", false);
        }
     
        numberOfExtinguishedFires -- ;
        prevNumberOfExtinguishedFires = numberOfExtinguishedFires;
    }
    if(fire2->getisExtinguished()  && GameManager::sharedGameManager()->isNodeAtPoint( fire2->getfire(),touchPoint))
    {
        fire2->RestartFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
                 SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.mp3", false);
        }
        else
        {
                 SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.ogg", false);
        }
   
        
        numberOfExtinguishedFires -- ;
        prevNumberOfExtinguishedFires = numberOfExtinguishedFires;
    }
    if(fire3->getisExtinguished()  && GameManager::sharedGameManager()->isNodeAtPoint( fire3->getfire(),touchPoint))
    {
        fire3->RestartFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
             SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.mp3", false);
        }
        else
        {
             SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.ogg", false);
        }
       
        
        numberOfExtinguishedFires -- ;
        prevNumberOfExtinguishedFires = numberOfExtinguishedFires;
    }
    if(fire4->getisExtinguished()  && GameManager::sharedGameManager()->isNodeAtPoint( fire4->getfire(),touchPoint))
    {
        fire4->RestartFire();
        if(platform==kTargetIpad || platform==kTargetIphone)
        {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.mp3", false);
        }
        else
        {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 1 and 2/fireFadeIn.ogg", false);
        }
    
        numberOfExtinguishedFires -- ;
        prevNumberOfExtinguishedFires = numberOfExtinguishedFires;
    }
    
   // continousFire.pitch = (4-numberOfExtinguishedFires)/4;
}
void WikedCity::StartZoomOnCity()
{
//    city->runAction(CCSpawn::create(CCEaseOut::create(CCMoveTo::create(TimeForWikedCityToSetIn, ccp(0, 0)), 2.0),CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 1.0f), 2.0),NULL));
    city->setScale(0.7);
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            {
             city->runAction(CCSpawn::create(CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 1.0f), 2.0),NULL));
            }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                city->runAction(CCSpawn::create(CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 1.0f), 2.0),NULL));
            }
            else
            {
                city->runAction(CCSpawn::create(CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 1.0f), 2.0),NULL));
            }
        }
            break;
        case 3:
            {
                  city->runAction(CCSpawn::create(CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 1.0f), 2.0),NULL));
            }
            break;
        default:
            
            break;
    }
    //background->runAction(CCEaseOut::create(CCScaleTo::create(TimeForWikedCityToSetIn, 2.2), 2));
    //Start Second Narration
        this->show_tips();
    
    this->schedule(schedule_selector(WikedCity::PlayNarrator),4.2);
}
