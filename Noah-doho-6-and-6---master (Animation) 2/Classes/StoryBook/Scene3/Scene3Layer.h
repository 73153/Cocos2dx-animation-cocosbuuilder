//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene3Layer__
#define __Demo__Scene3Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../GameManager/GameManager.h"
#include "../Footer/FooterLayerLoader.h"

#include "../Scene3/NoahAndDove.h"
 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene3Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene3Layer, create);
        Scene3Layer();
        virtual ~Scene3Layer();
        virtual void onEnter();
        virtual void onExit();
    
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        //animation manager
        void setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager);
    //start narrator
    void onNarratorStart(CCNode* sender);

    CCSize screenSize;
	
    CCSprite* bacground;
    CCSprite* city1;
    CCSprite* city2;
    CCSprite* forceField1;
    CCSprite* forceField2;
    CCSprite* glowingForceField1;
    CCSprite* glowingForceField2;
    CCSprite* forceFieldExplosion;
    CCSprite* fireball;
    NoahAndDove *noah;
    CCAnimation *explodingCity1;
    CCAnimation *explodingCity2;
    unsigned int  electricHum;
    CCArray *explodingCity1Frames;
    CCArray *explodingCity2Frames;
    CCArray *explodingFireBallFrames;
    bool fireballIsAnimating;

    void stopSwallingTouchs();
    void tick(float dt);
    void FinishanimatingFireball();
    void ExplodeCity1();
    void ExplodeCity2();
    void LaunchFireball(float dt);
    void set_frames();
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    
    private:
   cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
