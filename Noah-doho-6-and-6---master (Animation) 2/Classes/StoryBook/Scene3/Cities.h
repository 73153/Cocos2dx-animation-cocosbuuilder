//
//  Cities.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__Cities__
#define __Noah360__Cities__

#include <iostream>

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Cities: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener,public CCTargetedTouchDelegate
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Cities, create);
    Cities();
    virtual ~Cities();
    virtual void onEnter();

    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

    CCSize screenSize;
    CCSprite* city1;
    CCSprite* city2;
    CCSprite* forceField1;
    CCSprite* forceField2;
    CCSprite* glowingForceField1;
    CCSprite* glowingForceField2;
    CCSprite* forceFieldExplosion;
    CCSprite* fireball;
    
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
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    int next_speech;
};
#endif /* defined(__Noah360__Cities__) */
