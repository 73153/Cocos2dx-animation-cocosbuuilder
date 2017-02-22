//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.

#ifndef __Demo__Scene15Layer__
#define __Demo__Scene15Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdlib.h> /* rand, srand */
#include <stdio.h>  /* printf (for this example) */
#include <time.h>   /* time */
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
class Scene15Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene15Layer, create);
        Scene15Layer();
        virtual ~Scene15Layer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

        void onNarratorStart(CCNode* sender);
    TargetPlatform platform;

    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    
    void SplashFishEntrie();
    void SplashFish(CCSprite* fishie);
    void GetTrajectoryFishie(CCSprite* fishie);
    void jumpFishie(float dt);
    void PlayFish(float  dt);
    void PlayNoahFished(float dt);
    bool isTouchOnFishie(CCSprite* fishie,CCPoint point);


    void PlayNarrator(float dt);
    void tick(float dt);
    void set_scene();
    void WaitForNoahToEnd(float dt);
    
    CCSize screenSize;
    CCSprite * bacground;
    CCSprite * gradient;
	CCSprite * clouds;
	CCSprite * sun;
	CCSprite * lightArk;
	CCSprite * darkArk;
	CCSprite * lightSea;
	CCSprite * darkSea;
	CCSprite * fishingNoah;
	CCSprite * fishie1;
	CCSprite * fishie2;
	CCSprite * fishie3;
	CCSprite * fishie4;
	CCSprite * fishie5;

    unsigned int narrator;
    unsigned int speech;
    unsigned int oceanSound;
    unsigned int noahFished;

    int maxSunY;
    int minSunY;


    std::vector<std::string> possibleFishies;
    bool interactionsEnabled;
    bool waytingForNarrator;
    bool isPlaying;

    bool sunIsTouched;
    
	CCPoint whereTouch;
    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
