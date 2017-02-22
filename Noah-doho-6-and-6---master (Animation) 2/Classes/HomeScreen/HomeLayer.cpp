//
//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.

#include "HomeLayer.h"
#include "../GameManager/GameManager.h"
#include "../GameManager/common_function.h"
#include "../SoundManager/SoundManager.h"
#include "../HomeScreen/NoahAnimation/SquatingNoahLoader.h"
#include "../SplashVideo/WrapperClass.h"
USING_NS_CC;
USING_NS_CC_EXT;
HomeLayer::HomeLayer():mAnimationManager(NULL),startBtn(NULL),missionBtn(NULL),settingsBtn(NULL),ispause(false),is_setting_animating(false),is_mission_animating(false)
{
   CCLog("constructor called");
}
HomeLayer::~HomeLayer()
{
    CCLog("destracture called");
}
void HomeLayer::onExit()
{
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void HomeLayer::onEnter()
{
    this->setTouchEnabled(true);
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//        WrapperClass::getShared()->playVideo("sampleVideo");
//    #endif
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("HeaderAssets.plist");
    
    hair=(CCSprite*)this->getChildByTag(100);
    beared=(CCSprite*)this->getChildByTag(101);
    leftHandTopSafety=(CCSprite*)this->getChildByTag(102);
   menuHero=(CCMenu*)this->getChildByTag(104);
    hairBtn=(CCMenuItemImage*)menuHero->getChildByTag(1);

    helmetBtn=(CCMenuItemImage*)menuHero->getChildByTag(2);

    bearBtn=(CCMenuItemImage*)menuHero->getChildByTag(3);

    leftTopArmorBtn=(CCMenuItemImage*)menuHero->getChildByTag(4);

//    SoundManager::sharedSoundManager()->stopBackgroundSound();
//    SoundManager::sharedSoundManager()->startBackgroundSound();
//    screenSize=CCDirector::sharedDirector()->getWinSize();
//    this->animate_noah();
//      this->setmenu_items();
//    switch (GameManager::sharedGameManager()->get_devise_resolution())
//    {
//        case 1:
//        {
//            
//            break;
//        }
//        case 2:
//        {
//            CCNode *node=this->getChildByTag(11);
//            if (screen_width==1136)
//            {
//                node->getChildByTag(1)->setScale(0.90);
//                node->getChildByTag(2)->setScale(0.90);
//                node->getChildByTag(3)->setScale(0.90);
//                whyBtn->setScale(0.90);
//                whoBtn->setScale(0.90);
//                socialOnBtn->setScale(0.90);
//                muteNarratorBtn->setScale(0.90);
//                muteSoundFXBtn->setScale(0.90);
//                socialOnBtn->setScale(0.90);
//                feedbackBtn->setScale(0.90);
//                whyBtn->setEnabled(false);
//                whoBtn->setEnabled(false);
//                socialOnBtn->setEnabled(false);
//                muteNarratorBtn->setEnabled(false);
//                muteSoundFXBtn->setEnabled(false);
//                socialOnBtn->setEnabled(false);
//                feedbackBtn->setEnabled(false);
////                whyBtn->setVisible(false);
////                whoBtn->setVisible(false);
////                socialOnBtn->setVisible(false);
////                muteNarratorBtn->setVisible(false);
////                muteSoundFXBtn->setVisible(false);
////                socialOnBtn->setVisible(false);
////                feedbackBtn->setVisible(false);
//
//            }
//            else
//            {
//            
//            }
//            break;
//        }
//        case 3:
//        {
//            break;
//        }
//        case 4:
//        {
//            break;
//        }
//        default:
//            break;
//    }
//    whyBtn->setEnabled(false);
//    whoBtn->setEnabled(false);
//    socialOnBtn->setEnabled(false);
//    muteNarratorBtn->setEnabled(false);
//    muteSoundFXBtn->setEnabled(false);
//    socialOnBtn->setEnabled(false);
//    feedbackBtn->setEnabled(false);
//    arkGlow=CCSprite::create("menuArkGlow.png");
//    this->addChild(arkGlow, 24, 24);
//    arkGlow->setOpacity(0);
//    this->schedule(schedule_selector(HomeLayer::tick), 1/60);
//    ispause=false;
    //this->schedule(schedule_selector(HomeLayer::pauses_squashing_noah), 2);
    CCLayer::onEnter();
}
void HomeLayer::onMenuAnimComplete()
{
    CCPoint mission_position=CCPointMake(missionBtn->getPositionX()+missionBtn->getContentSize().width/2,missionBtn->getPositionY());
    whyBtn->setPosition(mission_position);
    whoBtn->setPosition(mission_position);
//    whyBtn->setPosition(ccp(missionBtn->getPositionX()/2+missionBtn->getContentSize().width/2, missionBtn->getPositionY()/2+missionBtn->getContentSize().height/2));
//    whoBtn->setPosition(ccp(missionBtn->getPositionX()/2+missionBtn->getContentSize().width/2, missionBtn->getPositionY()/2+missionBtn->getContentSize().height/2));

}
void HomeLayer::pauses_squashing_noah()
{
    ispause=!ispause;
    if (ispause)
    {
        CCArray* childs = noah_anim_node->getChildren();
        CCObject* child;
        CCARRAY_FOREACH(childs, child)
        {
            CCNode *sprite = (CCNode *)child;
            sprite -> pauseSchedulerAndActions();
        }
    }
    else
    {
        CCArray* childs = noah_anim_node->getChildren();
        CCObject* child;
        CCARRAY_FOREACH(childs, child)
        {
            CCNode *sprite = (CCNode *)child;
            sprite -> resumeSchedulerAndActions();
        }
    }
}
void HomeLayer::setmenu_items()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene8.plist");
    CCArray *arr_why=CCArray::create();
    arr_why->addObject(CCString::create("Scene8/whyPage1.png"));
    arr_why->addObject(CCString::create("Scene8/whyPage2.png"));
    arr_why->addObject(CCString::create("Scene8/whyPage3.png"));
    arr_why->addObject(CCString::create("Scene8/whyPage4.png"));
    arr_why->addObject(CCString::create("Scene8/whyPage5.png"));
    arr_why->addObject(CCString::create("Scene8/whyPage6.png"));
    
    CCArray *arr_who=CCArray::create();
    arr_who->addObject(CCString::create("Scene8/whoPage1.png"));
    arr_who->addObject(CCString::create("Scene8/whoPage2.png"));
    arr_who->addObject(CCString::create("Scene8/whoPage3.png"));
    arr_who->addObject(CCString::create("Scene8/whoPage4.png"));
    arr_who->addObject(CCString::create("Scene8/whoPage5.png"));
    arr_who->addObject(CCString::create("Scene8/whoPage6.png"));

    infoCardWhy=InfoCardNode::create(arr_why, CCString::create("Scene8/whyPageCommon.png"));
    infoCardWho=InfoCardNode::create(arr_who, CCString::create("Scene8/whoPageCommon.png"));

    if (screenSize.height<768)
    {
        infoCardWhy->setScale(0.9);
        infoCardWho->setScale(0.9);
    }
    infoCardWhy->setPosition(CCPoint(846*(screenSize.width/1024),342*(screenSize.height/768)));
    infoCardWho->setPosition(CCPoint(846*(screenSize.width/1024),342*(screenSize.height/768)));
    infoCardWho->setPosition(ccpAdd(infoCardWho->getPosition(), ccp(0,3* infoCardWho->getnextGlow()->getContentSize().height/4)));
     infoCardWhy->setPosition(ccpAdd(infoCardWhy->getPosition(), ccp(0,3* infoCardWhy->getnextGlow()->getContentSize().height/4)));

    this->addChild(infoCardWho, 11, -1);
    this->addChild(infoCardWhy, 11, -1);
    if (GameManager::sharedGameManager()->getmutedFX())
    {
        muteSoundFXBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOff.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOff.png"), this, menu_selector(HomeLayer::muteSoundFXBtnPressed));
      
    }
    else
    {
        muteSoundFXBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOn.png"), this, menu_selector(HomeLayer::muteSoundFXBtnPressed));
    }
    if (GameManager::sharedGameManager()->getmutedNarrator())
    {
        muteNarratorBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOff.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOff.png"), this, menu_selector(HomeLayer::muteNarratorBtnPressed));
        
    }
    else
    {
        muteNarratorBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOn.png"), this, menu_selector(HomeLayer::muteNarratorBtnPressed));
    }
    
    feedbackBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/feedbackBtn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/feedbackBtn.png"), this, menu_selector(HomeLayer::feedbackBtnPressed));
   
    if (GameManager::sharedGameManager()->getSocial())
    {
        socialOnBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOn.png"), this, menu_selector(HomeLayer::parentTipsBtnPressed));
    }
    else
    {
        socialOnBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOff.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOff.png"), this, menu_selector(HomeLayer::parentTipsBtnPressed));
    }
    muteNarratorBtn->setEnabled(false);
    feedbackBtn->setEnabled(false);
    muteSoundFXBtn->setEnabled(false);
    socialOnBtn->setEnabled(false);
    whyBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/whyBtn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/whyBtn.png"),this,menu_selector(HomeLayer::whyBtnPressed));
    whoBtn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/whoBtn.png"), CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/whoBtn.png"),this,menu_selector(HomeLayer::whoBtnPressed));
    whyBtn->setPosition(ccp(missionBtn->getPositionX()/2+missionBtn->getContentSize().width/2, missionBtn->getPositionY()/2+missionBtn->getContentSize().height/2));
    whoBtn->setPosition(ccp(missionBtn->getPositionX()/2+missionBtn->getContentSize().width/2, missionBtn->getPositionY()/2+missionBtn->getContentSize().height/2));
    
    muteNarratorBtn->setPosition(ccp(settingsBtn->getPositionX()/2+settingsBtn->getContentSize().width/2, settingsBtn->getPositionY()/2+settingsBtn->getContentSize().height/2));
    muteSoundFXBtn->setPosition(ccp(settingsBtn->getPositionX()/2+settingsBtn->getContentSize().width/2, settingsBtn->getPositionY()/2+settingsBtn->getContentSize().height/2));
   
    feedbackBtn->setPosition(ccp(settingsBtn->getPositionX()/2+settingsBtn->getContentSize().width/2, settingsBtn->getPositionY()/2+settingsBtn->getContentSize().height/2));
    socialOnBtn->setPosition(ccp(settingsBtn->getPositionX()/2+settingsBtn->getContentSize().width/2, settingsBtn->getPositionY()/2+settingsBtn->getContentSize().height/2));
    menuUp=CCMenu::create(muteNarratorBtn,muteSoundFXBtn,feedbackBtn,socialOnBtn,whoBtn,whyBtn,NULL);
    menuUp->retain();
    menuUp->setPosition(ccp(0,0));

    this->addChild(menuUp,this->getChildByTag(11)->getZOrder()-1);

}
void HomeLayer::playSoundForTitleEntrance()
{
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/titleEntrance.mp3", false);
}
void HomeLayer::StopAll()
{
    this->stopAllActions();
    this->unscheduleAllSelectors();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
}
void HomeLayer::playStartingAnimation(float dt)
{
    this->unschedule(schedule_selector(HomeLayer::playStartingAnimation));
    helmetBtn->setVisible(true);
    hairBtn->setVisible(true);
    bearBtn->setVisible(true);
    leftTopArmorBtn->setVisible(true);
//    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
//    if (mAnimationManager)
//    {
//        mAnimationManager->runAnimationsForSequenceNamed("Default Timeline");
//    }
}

void  HomeLayer::tick(float dt)
{
    if (noah_anim_node)
    {
        if (noah_anim_node->getis_anim_completed())
        {
            mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
            if (mAnimationManager)
            {
                mAnimationManager->runAnimationsForSequenceNamedTweenDuration("menu_side_anim", 0.80f);
                this->reorderChild(noah_anim_node,-2);
                this->unschedule(schedule_selector(HomeLayer::tick));
            }
        }
    }
}
void HomeLayer::animate_noah()
{
    noah_anim_node = NULL;
    std::map<std::string, CCNodeLoader*> loader_map;
    loader_map.insert(std::make_pair("SquatingNoah", SquatingNoahLoader::loader()));
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
         CCLOG("SquatingNoah");
            noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah.ccbi", loader_map);
            break;
        }
        case 2:
        {
            
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                CCLOG("SquatingNoah_iphone_5");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah_iphone_5.ccbi", loader_map);
            }
            else
            {
                CCLOG("SquatingNoah");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah.ccbi", loader_map);
            }
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                CCLOG("SquatingNoah_iphone_5");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah_iphone_5.ccbi", loader_map);
            }
            else
            {
                CCLOG("SquatingNoah");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah.ccbi", loader_map);
            }
        #endif
          
            break;
        }
        case 3:
        {
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            if (CCDirector::sharedDirector()->getWinSize().width==1136)
            {
                CCLOG("SquatingNoah_iphone_5");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah_iphone_5.ccbi", loader_map);
            }
            else
            {
                CCLOG("SquatingNoah");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah_iphone_5.ccbi", loader_map);
            }
            #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                CCLOG("SquatingNoah_iphone_4");
                noah_anim_node = (SquatingNoah*)loadCCBFile("SquatingNoah_iphone_4.ccbi", loader_map);
            #endif

            break;
        }
        default:
            break;
    }
    if (noah_anim_node)
    {
        this->addChild(noah_anim_node);
    }
}
#pragma mark -
#pragma mark action methods
#pragma mark -

void HomeLayer::onHair_clicked(cocos2d::CCNode *sender)
{
    
    hairBtn->setOpacity(30);
  helmetBtn->setOpacity(255);
   hair->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("HeaderAssets/helmat.png"));
}
void HomeLayer::onHelmet_clicked(cocos2d::CCNode *sender)
{
    helmetBtn->setOpacity(30);
hairBtn->setOpacity(255);
//    helmetBtn->setVisible(false);
//    bearBtn->setVisible(true);
//    leftTopArmorBtn->setVisible(true);
//    hairBtn->setVisible(true);
    hair->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("HeaderAssets/front_hair.png"));
}
void HomeLayer::onBeared_clicked(cocos2d::CCNode *sender)
{
    if(beared->isVisible()){
        bearBtn->setOpacity(255);
        beared->setVisible(false);
    }
    else{
        beared->setVisible(true);
        bearBtn->setOpacity(30);

    }
}
void HomeLayer::onleftHandSafety_clicked(cocos2d::CCNode *sender)
{
   
    if(leftHandTopSafety->isVisible())
        leftHandTopSafety->setVisible(false);
    else
        leftHandTopSafety->setVisible(true);
}
void HomeLayer::onSword_clicked(cocos2d::CCNode *sender)
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {

        mAnimationManager->runAnimationsForSequenceNamedTweenDuration("time", 0.3f);

        this->schedule(schedule_selector(HomeLayer::playStartingAnimation), 1.7f);
    }
    helmetBtn->setVisible(false);
    hairBtn->setVisible(false);
    bearBtn->setVisible(false);
    leftTopArmorBtn->setVisible(false);
}



void HomeLayer::onPlayButtonClicked(CCNode* sender)
{ 
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/menuPlaySound.mp3", false);
    GameManager::sharedGameManager()->gotoScene(1);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
}
void HomeLayer::onSettingButtonClicked(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    if (infoCardWhy->getimage()->getOpacity()!= 0)
    {
        infoCardWhy->Disapear();
    }
    if (infoCardWho->getimage()->getOpacity()!= 0)
    {
        infoCardWho->Disapear();
    }
    CCPoint mission_position=CCPointMake(missionBtn->getPositionX()+missionBtn->getContentSize().width/2,missionBtn->getPositionY());
    CCPoint setting_position=CCPointMake(settingsBtn->getPositionX()+settingsBtn->getContentSize().width/2,settingsBtn->getPositionY());
    if (!muteNarratorBtn->isEnabled())
    {
        CCPoint midPoint2 = ccp(500*(screenSize.width/1024),screenSize.height - 255);
        narrator_btn= CCTargetedAction::create(muteNarratorBtn,CCSequence::create(CCDelayTime::create(0.0f),CCEaseElasticOut::create(this->BuildBezierAction(muteNarratorBtn->getPosition(), midPoint2, CCPoint(590*(screenSize.width/1024), screen_height-225*(screenSize.height/768)), 1.0f-0.08), 0.8f),NULL));
        CCTargetedAction *SoundFX_btn= CCTargetedAction::create(muteSoundFXBtn,CCSequence::create(CCDelayTime::create(0.08f),CCEaseElasticOut::create(this->BuildBezierAction(muteSoundFXBtn->getPosition(), midPoint2, CCPoint(590*(screenSize.width/1024), screen_height-345*(screenSize.height/768)), 1.0f-0.06), 0.8f),NULL));
        CCTargetedAction *feedback_btn= CCTargetedAction::create(feedbackBtn,CCSequence::create(CCDelayTime::create(0.06f),CCEaseElasticOut::create(this->BuildBezierAction(feedbackBtn->getPosition(), midPoint2, CCPoint(590*(screenSize.width/1024), screen_height-465*(screenSize.height/768)), 1.0f-0.0f), 0.8f),NULL));
        CCTargetedAction *socialOn_btn= CCTargetedAction::create(socialOnBtn,CCSequence::create(CCDelayTime::create(0.04f),CCEaseElasticOut::create(this->BuildBezierAction(socialOnBtn->getPosition(), midPoint2, CCPoint(590*(screenSize.width/1024), screen_height-585*(screenSize.height/768)), 1.0f-0.04f), 0.8f),NULL));
        CCSpawn* spwn = (CCSpawn*)CCSpawn::create(narrator_btn, SoundFX_btn, feedback_btn, socialOn_btn, NULL);
        muteNarratorBtn->setEnabled(true);
        muteSoundFXBtn->setEnabled(true);
        feedbackBtn->setEnabled(true);
        socialOnBtn->setEnabled(true);
        is_setting_animating=true;
        this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_setting)),NULL));
        if (whyBtn->isEnabled())
        {
           CCPoint midPoint3 = ccp(500*(screenSize.width/1024),screenSize.height - 395);
           why_btn= CCTargetedAction::create(whyBtn,this->BuildBezierAction(whyBtn->getPosition(), midPoint3, mission_position,0.6f));
           CCTargetedAction *who_btn= CCTargetedAction::create(whoBtn,this->BuildBezierAction(whoBtn->getPosition(), midPoint3, mission_position, 0.6f));
           CCSpawn* spwn = (CCSpawn*)CCSpawn::create(why_btn,who_btn, NULL);
            is_mission_animating=true;
           this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_mission)),NULL));
           whyBtn->setEnabled(false);
           whoBtn->setEnabled(false);
        }
    }
    else
    {
        CCPoint midPoint3 = ccp(500*(screenSize.width/1024),screenSize.height - 255);
        narrator_btn= CCTargetedAction::create(muteNarratorBtn,this->BuildBezierAction(muteNarratorBtn->getPosition(), midPoint3, setting_position, 0.6f));
        CCTargetedAction *muteSoundFX_btn= CCTargetedAction::create(muteSoundFXBtn,this->BuildBezierAction(muteSoundFXBtn->getPosition(), midPoint3,setting_position, 0.6f));
        CCTargetedAction *feedback_btn= CCTargetedAction::create(feedbackBtn,this->BuildBezierAction(feedbackBtn->getPosition(), midPoint3, setting_position, 0.6f));
        CCTargetedAction *socialOn_btn= CCTargetedAction::create(socialOnBtn,this->BuildBezierAction(socialOnBtn->getPosition(), midPoint3, setting_position, 0.6f));
        CCSpawn* spwn = (CCSpawn*)CCSpawn::create(narrator_btn,muteSoundFX_btn,feedback_btn,socialOn_btn,NULL);
        is_setting_animating=true;
        this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_setting)),NULL));
        muteNarratorBtn->setEnabled(false);
        muteSoundFXBtn->setEnabled(false);
        feedbackBtn->setEnabled(false);
        socialOnBtn->setEnabled(false);
        
    }
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/arkOrganicSwosh.mp3", false);
}
void HomeLayer::onMissionButtonClicked(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
 
    if (infoCardWhy->getimage()->getOpacity()!= 0)
    {
        infoCardWhy->Disapear();
    }
    if (infoCardWho->getimage()->getOpacity()!= 0)
    {
        infoCardWho->Disapear();
    }
    CCPoint mission_position=CCPointMake(missionBtn->getPositionX()+missionBtn->getContentSize().width/2,missionBtn->getPositionY());
    CCPoint setting_position=CCPointMake(settingsBtn->getPositionX()+settingsBtn->getContentSize().width/2,settingsBtn->getPositionY());
    if (!whyBtn->isEnabled())
    {
        CCPoint midPoint2 = ccp(500*(screenSize.width/1024),missionBtn->getPositionY()-missionBtn->getContentSize().height);
       
        CCActionInterval *action=this->BuildBezierAction(whyBtn->getPosition(),midPoint2, ccp(590*(screenSize.width/1024),screenSize.height - 337*(screenSize.height/768)), 1.0f-0.12f);
        why_btn= CCTargetedAction::create(whyBtn,CCSequence::create(CCDelayTime::create(0.004f),CCEaseElasticInOut::create(action, 0.8f),NULL));

        CCActionInterval *action1=this->BuildBezierAction(whoBtn->getPosition(),midPoint2, ccp(590*(screenSize.width/1024),screenSize.height - 462*(screenSize.height/768)), 1.0f-0.05f);
      
        CCTargetedAction *who_Btn= CCTargetedAction::create(whoBtn,CCSequence::create(CCDelayTime::create(0.002f),CCEaseElasticInOut::create(action1, 0.8f),NULL));
        CCSpawn *spwn=CCSpawn::create(why_btn,who_Btn,NULL);
        is_mission_animating=true;
        this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_mission)),NULL));
        whyBtn->setEnabled(true);
        whoBtn->setEnabled(true);
        if(muteNarratorBtn->isEnabled())
        {
            CCPoint midPoint3 = ccp(500*(screenSize.width/1024),screenSize.height - 255);
            CCTargetedAction *muteNarrator_btn= CCTargetedAction::create(muteNarratorBtn,this->BuildBezierAction(muteNarratorBtn->getPosition(), midPoint3, setting_position, 0.6f));
            CCTargetedAction *muteSoundFX_btn= CCTargetedAction::create(muteSoundFXBtn,this->BuildBezierAction(muteSoundFXBtn->getPosition(), midPoint3, setting_position, 0.6f));
            CCTargetedAction *feedback_btn= CCTargetedAction::create(feedbackBtn,this->BuildBezierAction(feedbackBtn->getPosition(), midPoint3, setting_position, 0.6f));
            CCTargetedAction *socialOn_btn= CCTargetedAction::create(socialOnBtn,this->BuildBezierAction(socialOnBtn->getPosition(), midPoint3,setting_position, 0.6f));
            CCSpawn *spwn=CCSpawn::create(muteNarrator_btn,muteSoundFX_btn,feedback_btn,socialOn_btn,NULL);
            is_setting_animating=true;
            this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_setting)),NULL));
            muteNarratorBtn->setEnabled(false);
            muteSoundFXBtn->setEnabled(false);
            feedbackBtn->setEnabled(false);
            socialOnBtn->setEnabled(false);
          }
    }
    else
    {
        CCPoint midPoint3 = ccp(500*(screenSize.width/1024),missionBtn->getPositionY()-missionBtn->getContentSize().height);
        why_btn= CCTargetedAction::create(whyBtn,this->BuildBezierAction(whyBtn->getPosition(),midPoint3, mission_position, 0.6));
        CCTargetedAction *who_Btn= CCTargetedAction::create(whoBtn,this->BuildBezierAction(whoBtn->getPosition(),midPoint3, mission_position, 0.6));
        CCSpawn *spwn=CCSpawn::create(why_btn,who_Btn,NULL);
        is_mission_animating=true;
        this->runAction(CCSequence::create(spwn,CCCallFunc::create(this, callfunc_selector(HomeLayer::toggle_mission)),NULL));
        whyBtn->setEnabled(false);
        whoBtn->setEnabled(false);
    }
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/arkOrganicSwosh.mp3", false);
}
void HomeLayer::toggle_setting()
{
    is_setting_animating=false;
}
void HomeLayer::toggle_mission()
{
    is_mission_animating=false;
}
void HomeLayer::muteNarratorBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    
    this->makeArkGlow(muteNarratorBtn->getPosition());
    if (GameManager::sharedGameManager()->getmutedNarrator())
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
        GameManager::sharedGameManager()->saveMutedNarrator(false);
        muteNarratorBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOn.png"));
        muteNarratorBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOn.png"));
    }
    else
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/unslected_star_node.mp3", false);
        GameManager::sharedGameManager()->saveMutedNarrator(true);
        muteNarratorBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOff.png"));
        muteNarratorBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteNarratorBtnOff.png"));
    }
}
void HomeLayer::muteSoundFXBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    this->makeArkGlow(muteSoundFXBtn->getPosition());
    if (GameManager::sharedGameManager()->getmutedFX())
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
        GameManager::sharedGameManager()->saveMutedFX(false);
        muteSoundFXBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOn.png"));
        muteSoundFXBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOn.png"));
    }
    else
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/unslected_star_node.mp3", false);
        GameManager::sharedGameManager()->saveMutedFX(true);
        muteSoundFXBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOff.png"));
        muteSoundFXBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/muteFxBtnOff.png"));
    }
}
void HomeLayer::feedbackBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    this->makeArkGlow(feedbackBtn->getPosition());
    if (infoCardWhy->getimage()->getOpacity()!= 0)
    {
        infoCardWhy->Disapear();
    }
    if (infoCardWho->getimage()->getOpacity()!= 0)
    {
        infoCardWho->Disapear();
    }
     SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
    GameManager::sharedGameManager()->trySendAnEmail(TalktoUs);
}
void HomeLayer::parentTipsBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
    return;
    CCLog("parent tips button pressed");
     this->makeArkGlow(socialOnBtn->getPosition());
    if (GameManager::sharedGameManager()->getSocial())
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
        GameManager::sharedGameManager()->saveSocial(false);
        socialOnBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOff.png"));
        socialOnBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOff.png"));
    }
    else
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/unslected_star_node.mp3", false);
        GameManager::sharedGameManager()->saveSocial(true);
        socialOnBtn->setSelectedImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOn.png"));
        socialOnBtn->setNormalImage(CCSprite::createWithSpriteFrameName("Home_screen_menu_animation/socialOn.png"));
    }

       SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
}
//about us buttons
void HomeLayer::whyBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/textSwitch.mp3",false);
    this->makeArkGlow(whyBtn->getPosition());
    if (infoCardWho->getimage()->getOpacity() != 0)
    {
        infoCardWho->Disapear();
    }
    if (infoCardWhy->getimage()->getOpacity()== 0)
    {
        infoCardWhy->Appear();
    }
    else
    {
        infoCardWhy->Disapear();
    }
}
void HomeLayer::whoBtnPressed(CCNode* sender)
{
    if (is_mission_animating||is_setting_animating)
        return;
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/textSwitch.mp3",false);
    this->makeArkGlow(whoBtn->getPosition());
    if (infoCardWhy->getimage()->getOpacity()!= 0)
    {
        infoCardWhy->Disapear();
    }
    if (infoCardWho->getimage()->getOpacity()== 0)
    {
        infoCardWho->Appear();
    }
    else
    {
        infoCardWho->Disapear();
    }
}
void HomeLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
//    
//    if (infoCardWhy->TestForTouch(location)&&infoCardWhy->getimage()->getOpacity()!= 0)
//    {
//        this->feedbackBtnPressed(NULL);
//    }
}
#pragma mark -
#pragma mark social sharing
#pragma mark -
void HomeLayer::onGift_it_clicked(CCNode* sender)
{
    if (GameManager::sharedGameManager()->getSocial())
    {
        GameManager::sharedGameManager()->gift_an_app();
    }
}
void HomeLayer::trySendAnEmail(CCObject* pSender)
{
    if (GameManager::sharedGameManager()->getSocial())
    {
        GameManager::sharedGameManager()->trySendAnEmail(share_mail);
    }
}
void HomeLayer::trySendAnEmailInApp(CCObject* pSender)
{
    if (GameManager::sharedGameManager()->getSocial())
    {
        GameManager::sharedGameManager()->trySendAnEmailInApp(share_mail);
    }
}
void HomeLayer::trySendATweet(CCObject* pSender)
{
    if (GameManager::sharedGameManager()->getSocial())
    {
        GameManager::sharedGameManager()->trySendATweet();
    }
}
void HomeLayer::tryPostOnFB(CCObject* pSender)
{
    if (GameManager::sharedGameManager()->getSocial())
    {
        GameManager::sharedGameManager()->tryPostOnFB();
    }
}
void HomeLayer::makeArkGlow(CCPoint point)
{
    arkGlow->setPosition(point);
    arkGlow->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCFadeOut::create(0.1f),NULL));
}
CCActionInterval* HomeLayer::BuildBezierAction(CCPoint mid1,CCPoint mid2,CCPoint final,float time)
{
    ccBezierConfig bezzier;
    bezzier.controlPoint_1 = mid1;
    bezzier.controlPoint_2 = mid2;
    bezzier.endPosition = final;
    CCActionInterval *ac=CCBezierTo::create(time, bezzier);
    return ac;
}
#pragma mark -
#pragma mark ccb methods
void HomeLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN HomeLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
 

    
    return NULL;
}
SEL_MenuHandler HomeLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onPlayButtonClicked", HomeLayer::onPlayButtonClicked);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onSettingButtonClicked",HomeLayer::onSettingButtonClicked );
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onMissionButtonClicked",HomeLayer::onMissionButtonClicked );
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"trySendAnEmail",HomeLayer::trySendAnEmail );
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"trySendAnEmailInApp",HomeLayer::trySendAnEmailInApp );
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"trySendATweet", HomeLayer::trySendATweet);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"tryPostOnFB", HomeLayer::tryPostOnFB);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onGift_it_clicked", HomeLayer::onGift_it_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onHair_clicked", HomeLayer::onHair_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onHelmet_clicked", HomeLayer::onHelmet_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onleftHandSafety_clicked", HomeLayer::onleftHandSafety_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onBeared_clicked", HomeLayer::onBeared_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,"onSword_clicked", HomeLayer::onSword_clicked);

    
    return NULL;
}
SEL_CCControlHandler HomeLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
bool HomeLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "startBtn", CCMenuItemImage *, this->startBtn);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "missionBtn", CCMenuItemImage *, this->missionBtn);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingsBtn", CCMenuItemImage*,this->settingsBtn);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "hair",CCSprite *, this->hair);


    return false;
}

bool HomeLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
