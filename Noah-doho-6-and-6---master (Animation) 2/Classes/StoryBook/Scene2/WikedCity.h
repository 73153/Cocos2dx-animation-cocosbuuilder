//
//  WikedCity.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__WikedCity__
#define __Noah360__WikedCity__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

#include "../../StoryBook/Scene2/WickedFire.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class WikedCity: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener,public CCTargetedTouchDelegate
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WikedCity, create);
    WikedCity();
    virtual ~WikedCity();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    
    float halfWidth;
    float halfHeight;
    CCSprite* city;
    CCSprite* background;
    CCSprite* thief;
    CCSprite* mean;
    CCSprite* drunk;
    CCSprite* choke;
    
    WickedFire* fire1;
    WickedFire* fire2;
    WickedFire* fire3;
    WickedFire* fire4;
    
    CCMenuItem* window1;
    CCMenuItem* window2;
    CCMenuItem* window3;
    CCMenuItem* window4;
    CCMenuItem* window5;
    CCMenuItem* window6;
    CCMenuItem* window7;
    CCMenuItem* window8;
    CCMenuItem* window9;
    CCMenu* windows;
    
    bool interactionsEnabled;
    unsigned int  narrator;
    unsigned int continousFire;
    unsigned int  extingFire;
    unsigned int  startFire;
    
    int numberOfExtinguishedFires;
    int prevNumberOfExtinguishedFires;
    
    CCParticleSystemQuad *touchHereFX_1;
    CCParticleSystemQuad *touchHereFX_2;
    CCParticleSystemQuad *touchHereFX_3;
    CCParticleSystemQuad *touchHereFX_4;
    CCArray* windowArray;
    CCSprite* windowToshow;
    
    void StartZoomOnCity();
    void EnableInteractions();
    void DisableInteractions();
    void StopSounds();
    void WindowWasPressed(CCObject *psender);
    void GetCityToNormal();
    void PlayNarrator(CCTime dt);
    void ShowWindow(CCTime dt);
    void PlayWindowSound();
    void show_tips();
    CCSize screenSize;

    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__WikedCity__) */
