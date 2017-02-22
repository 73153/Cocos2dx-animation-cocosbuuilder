//
//  BoardingTheArkNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__BoardingTheArkNode__
#define __Noah360__BoardingTheArkNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class BoardingTheArkNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener,public CCTargetedTouchDelegate
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BoardingTheArkNode, create);
    BoardingTheArkNode();
    virtual ~BoardingTheArkNode();
    virtual void onEnter();
    virtual void onExit();

    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    //ccb function callback
public:
    void tick(CCTime  dt);
    void compare_next_object();
    void swith_on_instractunal_noah();
    CC_SYNTHESIZE(bool, is_comparing, is_comparing);
    unsigned int is_noah_instracting;

    CCSize screenSize;
    void iselephantCompleted();
    bool is_elephantanimating;
    CCLayer * layer_camel;
	CCSprite * camelFace;
	CCSprite * camelHidingHump;
	CCSprite * camelRisingHump;
	CCSprite * camelWater;
    
	CCSprite * croc;
    
	CCSprite * cangaru;
	CCSprite * cangaruHidingLayer;
	
    CCSprite * pelican;
    
	CCSprite * pig;
    
	CCSprite * porcupine;
    
      CCLayer * layer_possum;
	CCSprite * possum;
    
	CCSprite * elephantWater1;
	CCSprite * elephantWater2;

    
    CCLayer *mentis;
    CCLayer *RatleSnake;
    CCLayer *Goat;
   
    CCLayer *Sheep;
    CCLayer *Ducks;
    CCLayer *Tiger;
    CCLayer *Croc;
    CCLayer *Zebra;
    CCLayer *Elephant;
    CCLayerColor *other;
    CCLayerColor *allother;
    
    CCArray* camelFaceFrames;
    CCArray* crocFrames;
    CCArray* cangaruFrames;
    CCArray* pelicanFrames;
    CCArray* pigFrames;
    CCArray* porcupineFrames;
    CCArray* possumFrames;
    CCArray* elephantFrames;
    
    bool isPlaying;
    void CamelTouched();
    void StopIsPlaying(CCTime dt);
    void CrocTouched();
    void CangaruTouched();
    void PelicanTouched();
    void PigTouched();
    void PorcupineTouched();
    void PossumTouched();
    void ElephantTouched();
    void EndAllSchedulers();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
  
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    int next_speech;
};
#endif /* defined(__Noah360__BoardingTheArkNode__) */
