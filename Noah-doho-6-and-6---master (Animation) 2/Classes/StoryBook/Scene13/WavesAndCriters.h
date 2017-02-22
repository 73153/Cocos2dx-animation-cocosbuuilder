//
//  WavesAndCriters.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__WavesAndCriters__
#define __Noah360__WavesAndCriters__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "LaunchingAnimal.h"
#include "Octopus.h"
#include "Orca.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class WavesAndCriters: public cocos2d::CCNode,public CCTargetedTouchDelegate
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WavesAndCriters, create);
    WavesAndCriters();
    virtual ~WavesAndCriters();
    virtual void onEnter();
    virtual void onExit();
    virtual bool init();

    
    
	CCSprite *waterBack;
	CCSprite *waterMid;
	CCSprite *waterFront;
    Octopus *polvo;
    Orca *kWhale;
    CCNode* snorkelNode;
    
    float prevWaveMidY1;
    float prevWaveMidY2;
    
    CCArray *snorkelAnimals;
    LaunchingAnimal* loadAnimal;
    CCSize size;
    void StopWaves();
    void StartWaves();
    void StartStoped();
    void StartMoved();
    void AddSnorkelAnimal(LaunchingAnimal *lAnimal);
    void EndEverything();
    void StartToTick();
    void tick(float dt);
    void PauseWaveActions(float dt);
    void MoveSnorkelAnimal(float dt);
    void RemoveSnorkelAnimal();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);

private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    
};
#endif /* defined(__Noah360__WavesAndCriters__) */
