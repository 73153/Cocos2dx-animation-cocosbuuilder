//
//  fuelGaugeNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__fuelGaugeNode__
#define __Noah360__fuelGaugeNode__

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
class fuelGaugeNode: public cocos2d::CCNode
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(fuelGaugeNode, create);
    fuelGaugeNode();
    virtual ~fuelGaugeNode();
    virtual void onEnter();
    
    float timeInAnimation;
    CCSprite* mainImage;
    CCSprite* redRect;
    CCSprite* greenRect;
    void Stop();
    void ResetFuelConsuption();
    void StartFuelConsuption();
    bool  initwithtimer(float newtime);
    static fuelGaugeNode* create(float newtime);
};
#endif /* defined(__Noah360__fuelGaugeNode__) */
