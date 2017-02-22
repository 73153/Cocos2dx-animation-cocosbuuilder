//
//  InstructionalNoah.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__InstructionalNoah__
#define __Noah360__InstructionalNoah__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class InstructionalNoah: public cocos2d::CCNode
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(InstructionalNoah, create);
    InstructionalNoah();
    virtual ~InstructionalNoah();
    virtual void onEnter();
    virtual bool init();
    virtual void onExit();
    CCSize screenSize;
    CCSprite* body;
    CCSprite* head;
    CCSprite* eyeLids;
    CCSprite* leftHand;
    CCSprite* rightHand;
    CCSprite* leftSleeve;
    CCSprite* blackStripe;
    CCSprite* leftArm;
    CCSprite* goggles;
    CCArray *eyeLidsFrames;
    CCArray *headFrames;
    CC_SYNTHESIZE_RETAIN(CCSprite *, bacground, bacground);
    CC_SYNTHESIZE(bool, withSound, withSound);
    CC_SYNTHESIZE(bool, isPlaying, isPlaying);
    CC_SYNTHESIZE(float, timePresent, timePresent);
    CC_SYNTHESIZE(bool, doNotAutomaticallyDisappear, doNotAutomaticallyDisappear);
    CC_SYNTHESIZE_RETAIN(CCArray *, instructionalNoahSpeechsList, instructionalNoahSpeechsList);
    unsigned int  instructionalNoahSpeech;
    void HideEyeLids();
    void BlinkEyeis(float dt);
    void WaitForSpeechToEnd(float dt);
    void WaitTimeToDisapear(float dt);
    void ReplaceSleeves();
    void DontReplaceSleeves();
    void PullUpBody();
    void LowerHands();
    void MakeNoahAppearWithoutBackground();
    void MakeNoahAppear();
    void MakeBarDisapear();
    void PullDownHands();
    void UpperHands();
    void MakeNoahDisappear();
    void WithGoggles();
    void StopPlaying();
    int randoomAnimation;
};
#endif /* defined(__Noah360__InstructionalNoah__) */
