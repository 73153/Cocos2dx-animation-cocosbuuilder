//
//  FlyingDoveNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__FlyingDoveNode__
#define __Noah360__FlyingDoveNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
/*
 * Note: for some pretty hard fucked up reason, the order of inheritance is important!
 * When CCLayer is the 'first' inherited object:
 * During runtime the method call to the (pure virtual) 'interfaces' fails jumping into a bogus method or just doing nothing:
 *  #0    0x000cf840 in non-virtual thunk to HelloCocos....
 *  #1    ....
 *
 * This thread describes the problem:
 * http://www.cocoabuilder.com/archive/xcode/265549-crash-in-virtual-method-call.html
 */
USING_NS_CC;
USING_NS_CC_EXT;
class FlyingDoveNode: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(FlyingDoveNode, create);
    FlyingDoveNode();
    virtual ~FlyingDoveNode();
    virtual void onEnter();
    virtual bool init();
  
    CCSprite* body;
    CCSprite* wings;
    CCSprite* feet1;
    CCSprite* feet2;
    int numverOfWingsFlaps;
    float feet_YPos;
    bool doveIsFLying;

    CCSize screenSize;
    CC_SYNTHESIZE(bool, hasTakeOff, hasTakeOff);
    CC_SYNTHESIZE(bool, doveLost, doveLost);
    CC_SYNTHESIZE_RETAIN(CCNode*, moveXNode, moveXNode);
    CC_SYNTHESIZE_RETAIN(CCNode*, moveYNode, moveYNode);
    void WasDoveTouch();
    void LiftOff();
    void Accelerate(float acc);
    void ResetDove();
    void MoveToStartPosition();
    void StartMoving();
    void StopMoving();
    void LostGame();
    void GetDoveDown();
    void FlapWingsLikeCraZy(float dt);
    void suspendAllActions();
    void LetItFLy();
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__FlyingDoveNode__) */
