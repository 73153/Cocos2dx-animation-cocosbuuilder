//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene16Layer__
#define __Demo__Scene16Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene16/BranchCloudNode.h"
#include "../Scene16/BranchNode.h"
#include "../Scene16/FlyingDoveNode.h"
#include "../Scene16/fuelGaugeNode.h"
#include "../Scene16/LightSignNode.h"
#include "../Scene16/SpeedometerNode.h"
#include "../Scene16/TapToFlapNode.h"

//#include "../HomeScreen/homeLayerLoader.h"
 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene16Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene16Layer, create);
        Scene16Layer();
        virtual ~Scene16Layer();
        virtual void onEnter();
    virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
      virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    CCSize screenSize;
	CCSprite * gradient;
	CCSprite * clouds1;
	CCSprite * clouds2;
	CCSprite * leftFloor;
	CCSprite * rightFloor;
	CCSprite * doveShadow;
    
    CCSprite * tiltToStir;
    CCSprite * touchToFlap;
    
    CCSprite* restartButton;
    CCSprite * rightArkLine;
    CCSprite * leftArkLine;
    
    CCNode * floorNode;
    CCNode * rightArkLineNode;
    CCNode * leftArkLineNode;
    fuelGaugeNode * fuelGauge;
    TapToFlapNode * tapToFly;
    TargetPlatform platform;

	SpeedometerNode * speedmometer;
	LightSignNode * lightSign;
    FlyingDoveNode * dove;
    unsigned int sound_touch;
    unsigned int  narrator;
    unsigned int  speech;
    unsigned int idleDove;
    unsigned int noahinstruction;
    unsigned int dovetakeoff;
    unsigned int backgroundMusic;
    bool interactionsEnabled;
    bool waytingForNarrator;
    bool isPlaying;
    
    int numberOfTouches;
    float accelY;
    float linesSpeed;
    float increaseSpeedTimer;
    int thunderCount;
    int oliveCount;
    
    CCArray* branches;
    void  ResetScene();
    void InstructionGo();
    void InstructionAreYouReady();
    void make_noah_appear_without_bg();
    void StartCloud2();
    void StartCloud1();
    void StartFlightMovements();
    void TestForOliveBranchCatch();
    void tick(float dt);
    void DoveWasTouched(CCObject *pobject);
    void IncreaseSpeed(float dt);
  
    void PlayNarrator(float dt);
    void WaitForSpeechToEnd(float dt);
    void setMovmentForSprite(BranchNode* branchNode);
    void StartOliveBranch(float dt);
    void WaitForMusicToEnd(float dt);
    void GameHasEnded();
    void ShowTiltToStir();
    void DoveShouldLiftOff();
    void MakeRestartAppear();
    void ShouldStartDove();
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
