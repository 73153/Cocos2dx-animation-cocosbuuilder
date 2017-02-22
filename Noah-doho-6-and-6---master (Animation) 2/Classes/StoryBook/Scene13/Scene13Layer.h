//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene13Layer__
#define __Demo__Scene13Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CliffsAndClouds.h"
#include "WavesAndCriters.h"
#include "RubberBand.h"
#include "Ship.h"
#include "SoundStarArrayNode.h"


//#include "../HomeScreen/homeLayerLoader.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Scene13Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene13Layer, create);
        Scene13Layer();
        virtual ~Scene13Layer();
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
    CCMenuItemImage* nextButton;
    CCMenuItemImage* prevButton;
    CCMenu* menu;
	CCSprite *slingShotPoles;
	CCSprite *blackOverlayer;
    CCLabelTTF* timerLabel;
    CCLabelTTF* pointsLabel;
    
    CliffsAndClouds *bacground;
      WavesAndCriters *waves;
      RubberBand *band;
      Ship* ship;
     LaunchingAnimal *animalToLaunch;
      SoundStarArrayNode* starNode;
    
    bool isTouching;
    bool interactionsEnabled;
    bool waytingForNarrator;
    
    CCArray  *animalsInReserve;
    CCArray  *animlasLeftForSling;
    CCArray  *animalsMissed;
    
    CCNode* commonNode;
    
    bool gameHasStoped;
    float accelY;
    
    float timer;
    int points;
    
    int animalsOnArkCounter;
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    void shouldAddPoints(int points ,CCPoint pos);
    void RemoveAllAnimals();
    void PlayNarrator(float  dt);
    void tick(float  dt);
    void AnimalFinalDestination();
    void LaunchAnimal();
    void UpdateTimerLabel();
    void GetNextAnimalToLaunch();
    void FillAnimalOnReserve();
    void onPrevious_scene_clicked(CCObject* pSender);
    void onNext_scene_clicked(CCObject* pSender);
    
    void make_noah_appear_without_bg();
    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
