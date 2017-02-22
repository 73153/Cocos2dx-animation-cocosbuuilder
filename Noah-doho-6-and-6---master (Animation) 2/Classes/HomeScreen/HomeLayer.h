//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
#ifndef __Demo__HelloCocosBuilderLayer__
#define __Demo__HelloCocosBuilderLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../HomeScreen/NoahAnimation/SquatingNoah.h"
#include "../HomeScreen/NoahAnimation/InfoCardNode.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HomeLayer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
    public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(HomeLayer, create);
    
    HomeLayer();
    virtual ~HomeLayer();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

    void onMenuAnimComplete();
    void pauses_squashing_noah();
    void tick(float dt);
    void playStartingAnimation(float dt);
    void animate_noah();
    SquatingNoah *noah_anim_node;
    InfoCardNode   *infoCardWhy;
    InfoCardNode   *infoCardWho;
    //menu selector methods
    void onPlayButtonClicked(CCNode* sender);
    void onSettingButtonClicked(CCNode* sender);
    void onMissionButtonClicked(CCNode* sender);
    void toggle_setting();
    void toggle_mission();
    CCTargetedAction *narrator_btn;
    CCTargetedAction *why_btn;
    bool is_setting_animating;
    bool is_mission_animating;
    //setting buttons
    void muteNarratorBtnPressed(CCNode* sender);
    void muteSoundFXBtnPressed(CCNode* sender);
    void feedbackBtnPressed(CCNode* sender);
    void parentTipsBtnPressed(CCNode* sender);
    void makeArkGlow(CCPoint point);
    void playSoundForTitleEntrance();
    void StopAll();
    bool ispause;
    //about us buttons
    void whyBtnPressed(CCNode* sender);
    void whoBtnPressed(CCNode* sender);
   //social sharing...
    void trySendAnEmail(CCObject* pSender);
    void trySendAnEmailInApp(CCObject* pSender);
    void trySendATweet(CCObject* pSender);
    void tryPostOnFB(CCObject* pSender);
    void onGift_it_clicked(CCNode* sender);
    void onHair_clicked(CCNode* sender);
    void onHelmet_clicked(CCNode* sender);
    void onBeared_clicked(CCNode* sender);
    void onleftHandSafety_clicked(CCNode* sender);
    void onSword_clicked(CCNode* sender);



    
    private:
    
    CCSize screenSize;
    CCSprite* doorBang;
    CCSprite* arkGlow;
    
    CCSprite* giftItText;
    CCSprite* tellAFriendText;
    
    CCNode* slideInNode;
    CCNode* slideUpNode;

    CC_SYNTHESIZE_RETAIN(CCSprite*, hair, hair);
    CC_SYNTHESIZE_RETAIN(CCSprite*, beared, beared);
    CC_SYNTHESIZE_RETAIN(CCSprite*, leftHandTopSafety, leftHandTopSafety);

    CCMenu* menu;
    CCMenu* menuUp;
    CCMenu* menuArkButons;
    
    
    CCMenu* menuHero;

    CCMenuItemImage* helmetBtn;
    CCMenuItemImage* hairBtn;
    CCMenuItemImage* bearBtn;
    CCMenuItemImage* leftTopArmorBtn;

    
    CCMenuItemImage* startBtn;
    CCMenuItemImage* missionBtn;
    CCMenuItemImage* settingsBtn;
    
    CCMenuItemSprite* muteNarratorBtn;
    CCMenuItemSprite* muteSoundFXBtn;
    CCMenuItem* feedbackBtn;
    CCMenuItemSprite* socialOnBtn;

    CCMenuItem* whyBtn;
    CCMenuItem* whoBtn;

    CCMenuItem* twitterBtn;
    CCMenuItem* facebookBtn;
    CCMenuItem* emailBtn;
    CCMenuItem* giftAppBtn;
    
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    CCActionInterval* BuildBezierAction(CCPoint mid1,CCPoint mid2,CCPoint final,float time);
    void setmenu_items();
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
