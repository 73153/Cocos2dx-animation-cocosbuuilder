//
//  DreamFloadWater.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__DreamFloadWater__
#define __Noah360__DreamFloadWater__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "LoadItem.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class DreamFloadWater: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(DreamFloadWater, create);
    DreamFloadWater();
    virtual ~DreamFloadWater();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
 	CCSize screenSize;
    CCSprite * inComingFloadWater;
    CCSprite * floadWater1;
    
    CCSprite * topFloadWater;
    CCSprite * midFloadWater;
    CCSprite * botFloadWater;
    CCSprite * arc;
//    LoadItem * flag;
    LoadItem * tower;
    CCSprite * flag;
//    CCSprite * tower;
    
    CC_SYNTHESIZE(CCSprite*, palm1, palm1);
    CC_SYNTHESIZE(CCSprite*, palm2, palm2);

    int waveNumber;
    unsigned int waveSound;
    //ccb function callback
public:
//    void start_animation();
//    void stop_animation();
    void StartFload();
    void ResetFload();
    void StopSounds();
    void GetWavesAnimating();
    void ChangeWave(float dt);
    void passSomethingBy(float dt);
    void tick(float dt);
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
  
};
#endif /* defined(__Noah360__DreamFloadWater__) */
