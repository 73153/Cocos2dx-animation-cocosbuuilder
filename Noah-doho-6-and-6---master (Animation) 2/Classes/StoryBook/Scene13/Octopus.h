//
//  Octopus.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__Octopus__
#define __Noah360__Octopus__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Octopus: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Octopus, create);
    Octopus();
    virtual ~Octopus();
    virtual void onEnter();
    virtual bool init();
   
    
    
    CCSprite* head;
    CCSprite* arm1;
    CCSprite* arm2;
    CCSprite* arm3;
    CCSprite* arm4;
    CCSprite* arm5;
    CCSprite* arm6;
    CCSize size;
    CCNode* commonNode;
    void EndEverything();
    void GetRandomMovment(CCSprite* image);
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__Octopus__) */
