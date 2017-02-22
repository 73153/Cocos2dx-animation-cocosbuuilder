//
//  NoahAndDove.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__NoahAndDove__
#define __Noah360__NoahAndDove__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class NoahAndDove: public cocos2d::CCNode,public CCTargetedTouchDelegate
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(NoahAndDove, create);
    NoahAndDove();
    virtual ~NoahAndDove();
    virtual void onEnter();
    virtual void onExit();
    virtual bool init();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCSize screenSize;
    CCSprite * head;
    CCSprite * body;
    CCSprite * leftHandStaff;
    CCSprite * leftForeHarm;
    CCSprite * leftLowerSleeve;
    CCSprite * leftUpperSleeve;
    CCSprite * rightSleeve;
    CCSprite * rightHand;
    CCSprite * dove;
    
 
    
    CCAnimation *doveShakeHead;
    CCAnimation *doveFlapWings;
    CCArray *doveShakeHeadFrames;
    CCArray *doveFlapWingsFrames;
    
   
    bool runningAnimation;
    bool firstAnimation;
    
    CCPoint upperToLowerSleeve;
    CCPoint sleeveToForearm;
    CCPoint forearmToHand;
    CCPoint handToDove;
    
    int lastSentence;
    
    unsigned int  noahSpeech;
    CC_SYNTHESIZE(bool,interactionsEnabled,interactionsEnabled);
    CC_SYNTHESIZE(bool,isPlaying,isPlaying);
public:
    
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

    void tick(float  dt);
    void EnableInteractions();
    void stopSwallingTouchs();
    void ChangeBackNoahFace();
    void MakeFeathersAppear(float  dt);
    void RunRandomNoahAnimation();
    void WaitForSpeechToEnd(float dt);

    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Noah360__NoahAndDove__) */
