//
//  HeaderLayer.h
//  Noah360
//
//  Created by Neil D on 03/10/13.

#ifndef __Noah360__HeaderLayer__
#define __Noah360__HeaderLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../InstructionalNoah/InstructionalNoah.h"
#include "../../InstructionalNoah/InstructionalNoahark.h"
#include  "../../Paywall/Paywall.h"
#include "../../Tips/TipsLayer.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class HeaderLayer: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(HeaderLayer, create);
    HeaderLayer();
    virtual ~HeaderLayer();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    void tryPostOnFB(CCObject* pSender);
    
    //ccb function callback
    void onToggleClicked(cocos2d::CCObject * pSender);
    void onMenuClicked(cocos2d::CCObject * pSender);
    void onMenuItemClicked(cocos2d::CCObject * pSender);

    void onHomeItemClicked(cocos2d::CCObject * pSender);
    void onStoreClicked(cocos2d::CCObject * pSender);
    void onTalk_toUSClicked(cocos2d::CCObject * pSender);
    void onCrossClicked(cocos2d::CCObject * pSender);
    void onTipsClicked(cocos2d::CCObject * pSender);
    
    void animationCompleted(cocos2d::CCObject * pSender);
    bool isTips;
    CC_SYNTHESIZE(bool,is_tips_showing, is_tips_showing);
    bool tryIsInternetConnection();
    bool toggle;
    
    CC_SYNTHESIZE(bool,menu_toggle, menu_toggle);
    void label_settings();
    CC_SYNTHESIZE(CCLabelTTF *, lbl_ark_tap, lbl_ark_tap);
    CC_SYNTHESIZE(CCLabelTTF *, lbl_current_level, lbl_current_level);
    CC_SYNTHESIZE(CCLabelTTF *, lblpoints, lblpoints);
    CC_SYNTHESIZE_RETAIN(InstructionalNoah*, instructionalNoah, instructionalNoah);
    CC_SYNTHESIZE_RETAIN(CCSprite*, star, star);
    CC_SYNTHESIZE_RETAIN(CCMenuItemImage*, store, store);

    
    //paywall
    CC_SYNTHESIZE(bool, is_paywall_opened, is_paywall_opened);
    unsigned int paywallsound;
    Paywall *paywall;
    void show_paywall();
    void onUpgradeNowClicked(cocos2d::CCObject * pSender);
    void onLaterNowClicked(cocos2d::CCObject * pSender);
    CC_SYNTHESIZE_RETAIN(CCMenuItemImage*, upgrade, upgrade);
    CC_SYNTHESIZE_RETAIN(CCMenuItemImage*, later, later);
    
    //tips
    void initialise_tips();
    TipsLayer *tips;
    void  start_showing_tips();
    
    TargetPlatform platForm;
   
    //instractunal noah
    void initialse_noah();
    InstructionalNoahark* instructionalNoahark;
    void intructionahNoahBtnPressed(cocos2d::CCObject * pSender);
    bool interactionsEnabled;
    bool shouldShowInstructionalBtn();
    void AddArkHit();
    void MakeInteractionsEnabled();
    void GetNewInstructionalNoahPosition();
    void SwitchOnInstructionalNoah();
    void SwitchOnInstructionalNoah(float timePresent,int angle);
    void SwitchOnInstructionalNoahWithoutBackGround();
    void SwitchOffInstructionalNoah();
    void MoveStaffButton(float dt);
    void tick(float dt);
    void add_noah_sounds();
    int noahAngle;
    float noahOffsetValue;
    CCSize screenSize;
    //cclayer
    CCLayer *layer_bar;

    cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Noah360__HeaderLayer__) */
