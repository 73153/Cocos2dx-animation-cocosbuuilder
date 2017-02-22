//
//  Ship.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__Ship__
#define __Noah360__Ship__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene13/LaunchingAnimal.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Ship: public cocos2d::CCNode{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Ship, create);
    Ship();
    virtual ~Ship();
    virtual void onEnter();
    virtual bool init();
    
    
    CCSprite *cask;
    CCSprite *topHouse;
    CCNode* commonNode;
    CCSize size;
    CCParticleSystemQuad* plume;
    CCArray* animalsOnBoard;
    CC_SYNTHESIZE(bool, open, open);
    CC_SYNTHESIZE_RETAIN(CCAnimation*, anim, anim);
    void EndEverything();
    bool AnimalEnteredArk(LaunchingAnimal* animal);
    bool AnimalHitArk(LaunchingAnimal*animal);
    void StopBoat(bool ShouldRemovePlume);
    void StartBoat();
    void StartStopedBoat();
    void SetSmallAnimals(CCArray* smallAnimalArray);
    void RemoveAllAnimals();
    void updateArkFromAccelerometer(float xAcc);
    void PlayPlume();
    void SartGentleRumble(float dt);
    void SwitchDoorsOpen(float dt);
    void SetIsOpen();
    void SetIsClosed();
    void GetShipMoving(float dt);
    
};
#endif /* defined(__Noah360__Ship__) */
