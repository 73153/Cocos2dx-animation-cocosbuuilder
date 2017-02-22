//  HeaderLayer.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
#include "HeaderLayer.h"
#include "../../GameManager/GameManager.h"

#include "../../SoundManager/SoundManager.h"
#include "../../StarStore/StarStoreLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
HeaderLayer::HeaderLayer():mAnimationManager(NULL),layer_bar(NULL),toggle(false),menu_toggle(false),lblpoints(NULL),lbl_ark_tap(NULL),lbl_current_level(NULL),star(NULL),isTips(false),is_tips_showing(false),store(NULL),upgrade(NULL),later(NULL),is_paywall_opened(false)
{
    CCLog("Header Layer called");
}
HeaderLayer::~HeaderLayer()
{
     CCLog("Header Layer removed");
}
void HeaderLayer::onEnter()
{
    CCNode::onEnter();
    upgrade->setVisible(false);
    later->setVisible(false);
    screenSize=CCDirector::sharedDirector()->getWinSize();
    later->setEnabled(false);
    upgrade->setEnabled(false);
    later->setVisible(false);
    later->setOpacity(0);
    this->label_settings();
    this->initialse_noah();
    this->initialise_tips();
    platForm = CCApplication::sharedApplication()->getTargetPlatform();
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==2)
    {
        if (CCUserDefault::sharedUserDefault()->getBoolForKey("Tips")==false)
        {
            this->onToggleClicked(NULL);
            start_showing_tips();
            CCUserDefault::sharedUserDefault()->setBoolForKey("Tips",true);
            CCUserDefault::sharedUserDefault()->flush();
        }
    }
}
void HeaderLayer::onExit()
{
    SoundManager::sharedSoundManager()->setEffectVolume(1);
    SoundManager::sharedSoundManager()->set_Backgound_MusicVolume(1);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    CCNode::onExit();
}
void HeaderLayer::add_noah_sounds()
{
    SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
    switch (GameManager::sharedGameManager()->getcurrent_scene().getValue())
    {
        case 0:
        {
       
            break;
        }
        case 1:
        {
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3"));
               break;
        }
        case 2:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3"));
            break;
        case 3:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 3/instructionalNoahScene3-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 1 and 2/instructionalNoahScene2-3.mp3"));
            break;
        case 4:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-3.mp3"));
            break;
        case 5:
            
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 5/instructionalNoahScene5-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 5/instructionalNoahScene5-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 5/instructionalNoahScene5-3.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 4/instructionalNoahScene4-3.mp3"));

            break;
        case 6:
//            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-2.mp3"));
//            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-3.mp3"));
//             SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-4.mp3"));
            break;
        case 7:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 7/instructionalNoahScene7-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 7/instructionalNoahScene7-2.mp3"));
            break;
        case 8:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 9/noahArkStarting.mp3"));
              break;
        case 9:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 8/instructionalNoahScene8-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 8/instructionalNoahScene8-2.mp3"));
            break;
        case 10:
            
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 10/instructionalNoahScene10-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 10/instructionalNoahScene10-2.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 10/instructionalNoahScene10-3.mp3"));
              break;
        case 11:
            if(platForm==kTargetIphone || platForm==kTargetIpad)
            {
                  SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 11/NoahGreatjob.caf"));
            }
            else
            {
                  SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 11/NoahGreatjob.ogg"));
            }
              break;
        case 12:
            
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 12/instructionalNoahScene12-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 12/instructionalNoahScene12-2.mp3"));
                       break;
        case 13:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 13/scene13Congratulations.mp3"));
                        break;
        case 14:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 14/instructionalNoahScene14-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 14/instructionalNoahScene14-2.mp3"));
            break;

        case 15:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 15/instructionalNoahScene15-1.mp3"));
            if(platForm==kTargetIphone || platForm==kTargetIpad)
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 15/instructionalNoahScene15-2.caf"));
            }
            else
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 15/instructionalNoahScene15-2.caf"));
            }
      
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 15/instructionalNoahScene15-3.mp3"));
            break;
        case 16:
            if(platForm==kTargetIphone || platForm==kTargetIpad)
            {
                 SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 16/scene16NoahInstruction.caf"));
            }
            else
            {
                 SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 16/scene16NoahInstruction.ogg"));
            }
            
            break;
        case 17:
            if(platForm==kTargetIphone || platForm==kTargetIpad)
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17-1.caf"));
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17-2.caf"));
            }
            else
            {
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17-1.ogg"));
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17-2.ogg"));
            }
         
            break;
        case 18:
            
            break;
        case 19:
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17c-1.mp3"));
            SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 17/instructionalNoahScene17c-2.mp3"));
            break;
            
        default:
            break;
    }
}
void HeaderLayer::label_settings()
{
    toggle=true;
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        CCNode *img=(CCNode*)this->getChildByTag(11);
        if (img)
        {
            img->getChildByTag(12)->setScale(1.3);
        }
    }
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    this->lblpoints->setFontName("fonts/MyriadPro-Bold.ttf");
    this->lbl_current_level->setFontName("fonts/MyriadPro-Bold.ttf");
    this->lbl_ark_tap->setFontName("fonts/MyriadPro-Bold.ttf");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    this->lblpoints->setFontName("MyriadPro-Bold");
    this->lbl_current_level->setFontName("MyriadPro-Bold");
    this->lbl_ark_tap->setFontName("MyriadPro-Bold");
#endif

   
    lblpoints->enableShadow(CCSizeMake(2, 2),0.6, 10);
    lblpoints->enableStroke(ccGRAY, 0.8);
    lbl_ark_tap->enableShadow(CCSizeMake(2, 2),0.6, 10);
    lbl_ark_tap->enableStroke(ccGRAY, 0.8);
    lbl_current_level->enableShadow(CCSizeMake(2, 2),0.6, 10);
    lbl_current_level->enableStroke(ccGRAY, 0.8);
    lbl_ark_tap->setString(CCString::createWithFormat("%d",GameManager::sharedGameManager()->getarkHits())->getCString());
    lbl_current_level->setString(CCString::createWithFormat("%d",GameManager::sharedGameManager()->getlevel())->getCString());
    lblpoints->setString(CCString::createWithFormat("%d",GameManager::sharedGameManager()->getpoints())->getCString());
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
        {
            this->lbl_ark_tap->setFontSize(52);
            this->lbl_current_level->setFontSize(52);
            this->lblpoints->setFontSize(52);
            break;
        }
        case 2:
        {
            this->lbl_ark_tap->setFontSize(32);
            this->lbl_current_level->setFontSize(32);
            this->lblpoints->setFontSize(32);
            break;
        }
        case 3:
        {
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                        this->lbl_ark_tap->setFontSize(32);
                        this->lbl_current_level->setFontSize(32);
                        this->lblpoints->setFontSize(32);
            #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                        this->lbl_ark_tap->setFontSize(24);
                        this->lbl_current_level->setFontSize(24);
                        this->lblpoints->setFontSize(24);
            #endif
            break;
        }
        case 4:
        {
            this->lbl_ark_tap->setFontSize(23);
            this->lbl_current_level->setFontSize(23);
            this->lblpoints->setFontSize(23);
            break;
        }
        default:
            break;
    }
    menu_toggle=true;
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void HeaderLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN HeaderLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler HeaderLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onToggleClicked", HeaderLayer::onToggleClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onMenuClicked", HeaderLayer::onMenuClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onMenuItemClicked", HeaderLayer::onMenuItemClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onHomeItemClicked", HeaderLayer::onHomeItemClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onStoreClicked", HeaderLayer::onStoreClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onTalk_toUSClicked", HeaderLayer::onTalk_toUSClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onCrossClicked", HeaderLayer::onCrossClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onTipsClicked", HeaderLayer::onTipsClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onUpgradeNowClicked", HeaderLayer::onUpgradeNowClicked);
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onLaterNowClicked", HeaderLayer::onLaterNowClicked);
   return NULL;
}
SEL_CCControlHandler HeaderLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool HeaderLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "layer_bar", CCLayer *, this->layer_bar);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lbl_ark_tap", CCLabelTTF *, this->lbl_ark_tap);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lbl_current_level", CCLabelTTF *, this->lbl_current_level);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lblpoints", CCLabelTTF *, this->lblpoints);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "star",CCSprite *, this->star);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "store",CCMenuItemImage *, this->store);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "later",CCMenuItemImage *, this->later);
   CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "upgrade",CCMenuItemImage *, this->upgrade);

    return false;
}
bool HeaderLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void HeaderLayer::onToggleClicked(cocos2d::CCObject *pSender)
{
    if (is_tips_showing)
        return;
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    menu_toggle=true;
    if (mAnimationManager)
    {
        if (toggle)
        {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                    mAnimationManager->runAnimationsForSequenceNamed("toggle_iphone4");
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                    switch (GameManager::sharedGameManager()->get_devise_resolution())
                    {
                        case 1:
                        {
                            CCLOG("SquatingNoah");
                             mAnimationManager->runAnimationsForSequenceNamed("toggle");
                            break;
                        }
                        case 2:
                            if (CCDirector::sharedDirector()->getWinSize().width==1136)
                            {
                                CCLOG("SquatingNoah_iphone_5");
                               mAnimationManager->runAnimationsForSequenceNamed("toggle_iphone5"); 
                            }
                            else
                            {
                                mAnimationManager->runAnimationsForSequenceNamed("toggle");
                             
                            }
                            break;
                        case 3:
                        {
                             mAnimationManager->runAnimationsForSequenceNamed("toggle_iphone4"); 
                         
                            break;
                        }
                        default:
                            break;
                    }
        #endif
        }
        else
        {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                    mAnimationManager->runAnimationsForSequenceNamed("toggle_back_iphone4");
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                    switch (GameManager::sharedGameManager()->get_devise_resolution())
                    {
                        case 1:
                        {
                            mAnimationManager->runAnimationsForSequenceNamed("toggle_back");
                            break;
                        }
                        case 2:
                        {
                            if (CCDirector::sharedDirector()->getWinSize().width==1136)
                            {
                               mAnimationManager->runAnimationsForSequenceNamed("toggle_back_iphone5");
                            }
                            else
                            {
                               mAnimationManager->runAnimationsForSequenceNamed("toggle_back");
                                
                            }
                            break;
                        }
                        case 3:
                        {
                            mAnimationManager->runAnimationsForSequenceNamed("toggle_back_iphone4"); 
                            break;
                        }
                        default:
                            break;
                    }
        #endif
        }
        toggle=!toggle;
    }
}
void HeaderLayer::onMenuClicked(cocos2d::CCObject * pSender)
{

    upgrade->setEnabled(false);
    upgrade->setPosition(ccp(0,-upgrade->getContentSize().height));
    if (is_tips_showing)
        return;
    toggle=true;
    CCLog("%d",menu_toggle);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        if (menu_toggle)
        {
                #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                mAnimationManager->runAnimationsForSequenceNamed("menu_present_iphone5");
                #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                switch (GameManager::sharedGameManager()->get_devise_resolution())
                {
                case 1:
                {
                  mAnimationManager->runAnimationsForSequenceNamed("menu_present");  break;
                }
                case 2:
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                        CCLOG("SquatingNoah_iphone_5");
                       mAnimationManager->runAnimationsForSequenceNamed("menu_present_iphone5");
                }
                else
                {
                     mAnimationManager->runAnimationsForSequenceNamed("menu_present");
                        
                    }
                break;
                case 3:
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_present_iphone4");                    break;
                }
                default:
                    break;
            }
                #endif
        }
        else
        {
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone5");

             #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            switch (GameManager::sharedGameManager()->get_devise_resolution())
            {
                case 1:
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                    break;
                }
                case 2:
                    if (CCDirector::sharedDirector()->getWinSize().width==1136)
                    {
                        mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone5");
                    }
                    else
                    {
                        mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                    }
                    break;
                case 3:
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone4");
                    break;
                }
                default:
                    break;
            }

            #endif
        }
        menu_toggle=!menu_toggle;
    }
    CCLog("%d",menu_toggle);
}
void HeaderLayer::onMenuItemClicked(cocos2d::CCObject * pSender)
{
    if (menu_toggle==true)
        return;
      menu_toggle=false;

//    switch (GameManager::sharedGameManager()->get_devise_resolution())
//    {
//        case 1:
//        {
//            mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
//            break;
//        }
//        case 2:
//            if (CCDirector::sharedDirector()->getWinSize().width==1136)
//            {
//                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone5");
//            }
//            else
//            {
//                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
//            }
//            break;
//        case 3:
//        {
//            mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone4");
//            break;
//        }
//        default:
//            break;
//    }
//    menu_toggle=!menu_toggle;
    CCMenuItemImage *img=(CCMenuItemImage*)pSender;
    int tag=img->getTag();
    if (!GameManager::sharedGameManager()->is_next_scene_available(tag))
    {
        //this->show_paywall();
        //   return;
    }
    GameManager::sharedGameManager()->remove_unused_data();
    GameManager::sharedGameManager()->gotoScene(tag);
}
void HeaderLayer::onHomeItemClicked(cocos2d::CCObject * pSender)
{
    GameManager::sharedGameManager()->remove_unused_data();
    GameManager::sharedGameManager()->gotoScene(0);
}
void HeaderLayer::onStoreClicked(cocos2d::CCObject * pSender)
{
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *splash_scene=GameManager::sharedGameManager()->get_scene("StarStoreLayer.ccbi", "StarStoreLayer", StarStoreLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(0.5f, splash_scene));
}
void HeaderLayer::onTalk_toUSClicked(cocos2d::CCObject * pSender)
{
    GameManager::sharedGameManager()->trySendAnEmail(Feedback);
}
void HeaderLayer::onCrossClicked(cocos2d::CCObject * pSender)
{
   if (is_paywall_opened)
   {
        upgrade->setPosition(ccp(0,upgrade->getContentSize().height));      
    }
   mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
   if (mAnimationManager)
   {
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                break;
            }
            case 2:
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone5");
                }
                else
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                }
                break;
            case 3:
            {
                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone4");
                break;
            }
            default:
                break;
        }
        menu_toggle=!menu_toggle;
    }
}
#pragma mark -
#pragma mark -Paywall
#pragma makr -
void HeaderLayer::show_paywall()
{
    if (isTips)
        return;
    is_paywall_opened=true;
    SoundManager::sharedSoundManager()->stopAllEffect();
//    SoundManager::sharedSoundManager()->setEffectVolume(0);
//    SoundManager::sharedSoundManager()->set_Backgound_MusicVolume(0);
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    if (this->getChildByTag(1234))
        return;
    instructionalNoah->setVisible(false);
    instructionalNoahark->setVisible(false);
    layer_bar->getZOrder();
    paywall=Paywall::create();
    this->addChild(paywall, layer_bar->getZOrder()+1,1234);
    this->reorderChild(this->getChildByTag(11),paywall->getZOrder()+3);
    this->reorderChild(this->getChildByTag(333),paywall->getZOrder()+2);
    upgrade->setVisible(true);
    later->setVisible(true);
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()!=13)
    {
        later->setVisible(false);
        later->setEnabled(false);
        if (screen_width==1136)
            upgrade->setPosition(ccpAdd(upgrade->getPosition(), ccp(upgrade->getContentSize().width/6, upgrade->getContentSize().height/2)));
        else
            upgrade->setPosition(ccpAdd(upgrade->getPosition(), ccp(upgrade->getContentSize().width/6, upgrade->getContentSize().height)));
    }
    else
    {
        paywallsound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Noah_paywall.mp3", false);
        SoundManager::sharedSoundManager()->stopBackgroundSound();
    }
    this->reorderChild(this->getChildByTag(45), paywall->getZOrder()+1);
}
void HeaderLayer::onUpgradeNowClicked(cocos2d::CCObject * pSender)
{
    is_paywall_opened=false;
    if (upgrade->isVisible()==false)
        return;
}
void HeaderLayer::onLaterNowClicked(cocos2d::CCObject * pSender)
{
    is_paywall_opened=false;
    if (later->isVisible()==false)
        return
     
        
    instructionalNoah->setVisible(true);
    instructionalNoahark->setVisible(true);
    SoundManager::sharedSoundManager()->setEffectVolume(1);
    SoundManager::sharedSoundManager()->set_Backgound_MusicVolume(1);
    SoundManager::sharedSoundManager()->startBackgroundSound();
    SoundManager::sharedSoundManager()->stopSoundEffect(paywallsound);
    paywall->setVisible(false);
    this->removeChildByTag(1234, true);
    upgrade->setVisible(false);
    later->setVisible(false);

}
#pragma mark -
#pragma mark Tips
#pragma mark -
void HeaderLayer::onTipsClicked(cocos2d::CCObject * pSender)
{
    if (is_paywall_opened==true)
        return;

    isTips=true;
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    mAnimationManager->setAnimationCompletedCallback(this, callfunc_selector(HeaderLayer::animationCompleted));
    if (mAnimationManager)
    {
        
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                break;
            }
            case 2:
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone5");
                }
                else
                {
                    mAnimationManager->runAnimationsForSequenceNamed("menu_dismis");
                }
                break;
            case 3:
            {
                mAnimationManager->runAnimationsForSequenceNamed("menu_dismis_iphone4");
                break;
            }
            default:
                break;
        }
        menu_toggle=!menu_toggle;
    }
}
void HeaderLayer::animationCompleted(cocos2d::CCObject * pSender)
{
    if (isTips)
    {
        CCLog("animation completed");
        this->onToggleClicked(NULL);
        this->start_showing_tips();
        isTips=false;
        
    }
}
void HeaderLayer::initialise_tips()
{
    tips=TipsLayer::create();
    this->addChild(tips, 1200, 0);
}
void HeaderLayer::start_showing_tips()
{
    tips->start_tips();
}
#pragma mark -
#pragma mark instractunal noah
#pragma mark -
void HeaderLayer::initialse_noah()
{
    this->add_noah_sounds();
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene3_city_b.plist");
    instructionalNoah=InstructionalNoah::create();
    this->addChild(instructionalNoah,1100);

    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==16)
    {
        //instructionalNoah->setwithSound(false);
        instructionalNoah->WithGoggles();       
    }

    instructionalNoahark =InstructionalNoahark::create(this, callfuncO_selector(HeaderLayer::intructionahNoahBtnPressed));
    this->addChild(instructionalNoahark, 1119, 0);
    this->GetNewInstructionalNoahPosition();
    instructionalNoahark->setPosition(ccp(-200,-200));
    interactionsEnabled=false;
    int stage=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    if (stage==6||stage==8||stage==11||stage==13||stage==18||stage==16)
    {
        instructionalNoahark->setIsEnabled(false);
        instructionalNoahark->setVisible(false);
        this->shouldShowInstructionalBtn();
        this->GetNewInstructionalNoahPosition();
    }
    else
    {
        this->schedule(schedule_selector(HeaderLayer::tick),2);
    }
}
bool HeaderLayer::shouldShowInstructionalBtn()
{
    switch (GameManager::sharedGameManager()->getcurrent_scene().getValue())
    {
        case 8:
        case 11:
        case 13:
        case 18:
        case 16:
           // instructionalNoah->setwithSound(false);
            instructionalNoah->setVisible(false);
            instructionalNoahark->setVisible(false);
            return false;
            break;
        default:
            return true;
    }
}
void HeaderLayer::AddArkHit()
{
    int level = GameManager::sharedGameManager()->getlevel();
    GameManager::sharedGameManager()->AddArkTouch();
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/playful_sweep_20.mp3", false);
    if (level != GameManager::sharedGameManager()->getlevel())
    {
       /* [reachedNewLevel runAction:[CCSequence actions:
                                    [CCFadeIn actionWithDuration:0.1f],
                                    [CCEaseElasticInOut actionWithAction:[CCScaleTo actionWithDuration:0.4f scale:1.0f]],
                                    [CCDelayTime actionWithDuration:1.2f],
                                    [CCFadeOut actionWithDuration:0.3f],
                                    [CCScaleTo actionWithDuration:0.1f scale:0.2f],nil]];*/
    }
}
void HeaderLayer::intructionahNoahBtnPressed(cocos2d::CCObject * pSender)
{
    if (!interactionsEnabled) return;

    if (SoundManager::sharedSoundManager()->isInstractunalNoahplaying())
        return;

    instructionalNoah->setVisible(true);
    this->SwitchOnInstructionalNoah();
    if(instructionalNoahark->getblackArkIsSet())
    {
        CCLog("constant 20 points");
        GameManager::sharedGameManager()->AddPoints(20, instructionalNoahark->getPosition(), this);
    }
    else
    {
        CCLog("points from plist");
        GameManager::sharedGameManager()->AddPoints(GameManager::sharedGameManager()->GetGroupAchievmentIsActiveStars(GroupIDArks), instructionalNoahark->getPosition(), this);
    }
    this->AddArkHit();
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/SH_Ark_effect.mp3", false);
    GameManager::sharedGameManager()->AddPoints(4);
}
void HeaderLayer::GetNewInstructionalNoahPosition()
{
    if (!this->shouldShowInstructionalBtn())
    {
        return;
    }
    int newAngle = rand()%4;
    while (newAngle == noahAngle)
    {
        newAngle = rand()%4;
    }
    noahAngle = newAngle;
    GameManager::sharedGameManager()->setnoahCounter(1+GameManager::sharedGameManager()->getnoahCounter());
    bool arkWillBeBlack = false;
    if (GameManager::sharedGameManager()->getnoahCounter() >= 9)
    {
        if (rand()%3 == 0)
        {
            instructionalNoahark->SetBlackArk();
            arkWillBeBlack = true;
            GameManager::sharedGameManager()->setnoahCounter(0);
        }
    }
    if (instructionalNoahark->getblackArkIsSet() && !arkWillBeBlack)
    {
        instructionalNoahark->SetNormalArk();
    }
    instructionalNoah->setRotation(0);
    instructionalNoah->setVisible(false);
    instructionalNoahark->setRotation(noahAngle*90);
    instructionalNoahark->MakeVisibleAgain();
    switch (noahAngle)
    {
        case 1:
            noahOffsetValue = rand()%500-200.0f;
           instructionalNoah->setRotation(180);
           instructionalNoah->setPosition(ccp(screenSize.width/2 + noahOffsetValue*(screenSize.width/1024),screenSize.height+7));
            instructionalNoahark->setPosition(ccp( 240 + noahOffsetValue,screenSize.height));
            break;
        case 3:
            noahOffsetValue = rand()%500-200.0f;
            instructionalNoah->setRotation(0);
            instructionalNoah->setPosition(ccp(screenSize.width/2 + noahOffsetValue*(screenSize.width/1024),0));
            instructionalNoahark->setPosition(ccp(screenSize.width/2 - 240*(screenSize.width/1024) + noahOffsetValue*(screenSize.width/1024),0));
            break;
        case 0:
            noahOffsetValue = rand()%300-100.0f;
            instructionalNoah->setPosition(ccp(0-7,screenSize.height/2 + noahOffsetValue));
            instructionalNoahark->setPosition(ccp(0,screenSize.height/2 - 240*(screenSize.height/768) + noahOffsetValue*(screenSize.height/768)));
            instructionalNoah->setRotation(90);
            break;
        case 2:
            noahOffsetValue = rand()%300-100.0f;
             instructionalNoah->setRotation(270);
            instructionalNoah->setPosition(ccp(screenSize.width+7,screenSize.height/2 + noahOffsetValue*(screenSize.height/768)));
            instructionalNoahark->setPosition(ccp(screenSize.width,screenSize.height/2 + 240*(screenSize.height/768) + noahOffsetValue*(screenSize.height/768)));
            
            break;
        default:
            break;
    }
}
void HeaderLayer::MoveStaffButton(float dt)
{
    if (!this->shouldShowInstructionalBtn()&&SoundManager::sharedSoundManager()->isNarratorPlaying())
    {
        return;
    }
    this->GetNewInstructionalNoahPosition();
    switch (noahAngle)
    {
        case 1:
            instructionalNoahark->runAction(CCSequence::create(CCMoveTo::create(0.7f, ccp(screenSize.width/2+210*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),screenSize.height)),CCMoveTo::create(1.5f, ccp(screenSize.width/2-210*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),screenSize.height)),CCMoveTo::create(0.7f, ccp(screenSize.width/2-240*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),screenSize.height+instructionalNoahark->getflashyImage()->getContentSize().height/2)),CCMoveTo::create(0, ccp(-200, -200)),NULL));
            break;
        case 3:
             instructionalNoahark->runAction(
                                             CCSequence::create(
                                                                CCMoveTo::create(0.7f, ccp(screenSize.width/2-210*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),0)),
                                                                CCMoveTo::create(1.5f, ccp(screenSize.width/2+210*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),0)),
                                                                CCMoveTo::create(0.7f, ccp(screenSize.width/2+240*(screenSize.width/1024)+noahOffsetValue*(screenSize.width/1024),-instructionalNoahark->getflashyImage()->getContentSize().height/2)),
                                                                CCMoveTo::create(0, ccp(-200, -200)),NULL));
          
            break;
        case 0:
            instructionalNoahark->runAction(
                                            CCSequence::create(
                                                               CCMoveTo::create(0.7f, ccp(0,screenSize.height/2-210*(screenSize.width/1024)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(1.5f, ccp(0,screenSize.height/2+210*(screenSize.width/1024)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(0.7f, ccp(-instructionalNoahark->getflashyImage()->getContentSize().height/2,screenSize.height/2+240*(screenSize.width/1024)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(0, ccp(-200, -200)),NULL));

           
            break;
        case 2:
            instructionalNoahark->runAction(
                                            CCSequence::create(
                                                               CCMoveTo::create(0.7f, ccp(screenSize.width,screenSize.height/2+210*(screenSize.height/768)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(1.5f, ccp(screenSize.width,screenSize.height/2-210*(screenSize.height/768)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(0.7f, ccp(screenSize.width+instructionalNoahark->getflashyImage()->getContentSize().height/2,screenSize.height/2-240*(screenSize.height/768)+noahOffsetValue*(screenSize.height/768))),
                                                               CCMoveTo::create(0, ccp(-200, -200)),NULL));
        
            break;
        default:
            break;
    }
}
void HeaderLayer::MakeInteractionsEnabled()
{
    if (interactionsEnabled) return;
    interactionsEnabled = true;
    noahAngle = 0;
    noahOffsetValue = rand()%500-200.0f;
    if (instructionalNoah)
    {
        instructionalNoah->setPosition(ccp(screenSize.width/2 + noahOffsetValue*(screenSize.width/1024),0));
        this->schedule(schedule_selector(HeaderLayer::MoveStaffButton),26);
        
    }
}
void HeaderLayer::SwitchOnInstructionalNoah()
{
    instructionalNoah->MakeNoahAppear();
}
void HeaderLayer::SwitchOnInstructionalNoah(float timePresent,int angle)
{
    instructionalNoah->settimePresent(timePresent);
    instructionalNoah->MakeNoahAppearWithoutBackground();
    noahAngle = angle;
    instructionalNoah->setRotation(noahAngle*90);
    instructionalNoahark->setRotation(noahAngle*90);
    instructionalNoahark->setVisible(false);
    switch (noahAngle)
    {
        case 0:
            noahOffsetValue = rand()%500-200.0f;
            instructionalNoah->setPosition(ccp(screenSize.width/2 + noahOffsetValue,0));
            instructionalNoahark->setPosition(ccp(screenSize.width/2 + 240 + noahOffsetValue,10-instructionalNoahark->getflashyImage()->getContentSize().height/2));
            break;
        case 2:
            noahOffsetValue = rand()%500-200.0f;
            instructionalNoah->setPosition(ccp(screenSize.width/2 + noahOffsetValue,screenSize.height+7));
            instructionalNoahark->setPosition(ccp(screenSize.width/2 - 240 + noahOffsetValue,screenSize.height+instructionalNoahark->getflashyImage()->getContentSize().height/2));
            break;
        case 1:
            noahOffsetValue = rand()%300-100.0f;
            instructionalNoah->setPosition(ccp(0-7,screenSize.height/2 + noahOffsetValue));
            instructionalNoahark->setPosition(ccp(-instructionalNoahark->getflashyImage()->getContentSize().height/2,screenSize.height/2 - 240 + noahOffsetValue));
            break;
        case 3:
            noahOffsetValue = rand()%300-100.0f;
            instructionalNoah->setPosition( ccp(screenSize.width+7,screenSize.height/2 + noahOffsetValue));
            instructionalNoahark->setPosition(ccp(screenSize.width + instructionalNoahark->getflashyImage()->getContentSize().height/2,screenSize.height/2 + 240 + noahOffsetValue));
            break;
            
        default:
            break;
    }
}
void HeaderLayer::SwitchOnInstructionalNoahWithoutBackGround()
{
    instructionalNoah->MakeNoahAppearWithoutBackground();
}
void HeaderLayer::SwitchOffInstructionalNoah()
{
    instructionalNoah->MakeNoahDisappear();
}
void HeaderLayer::tick(float dt)
{
    if (!interactionsEnabled&&this->shouldShowInstructionalBtn()&&!SoundManager::sharedSoundManager()->isNarratorPlaying())
    {
        this->unschedule(schedule_selector(HeaderLayer::tick));
        this->MakeInteractionsEnabled();
    }
}