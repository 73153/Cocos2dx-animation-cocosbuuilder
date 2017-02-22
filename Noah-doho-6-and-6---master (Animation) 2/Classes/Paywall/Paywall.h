//
//   Paywall.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#ifndef __Noah360__Paywall__
#define __Noah360__Paywall__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class  Paywall: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD( Paywall, create);
     Paywall();
    virtual ~ Paywall();
    virtual void onEnter();
    virtual bool init();
    virtual void onExit();
    
    CC_SYNTHESIZE_RETAIN(CCSprite*, bg_paywall, bg_paywall);
};
#endif /* defined(__Noah360__Paywall__) */
