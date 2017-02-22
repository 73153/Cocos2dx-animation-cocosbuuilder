//
//  TapToFlapNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__TapToFlapNode__
#define __Noah360__TapToFlapNode__

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
class TapToFlapNode: public cocos2d::CCNode
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TapToFlapNode, create);
    TapToFlapNode();
    virtual ~TapToFlapNode();
    virtual void onEnter();
    
    CCSprite* title;
    CCSprite* hand;
    
    void AppearAndAnimate();
    void HideAll();
    void Stop();
  };
#endif /* defined(__Noah360__TapToFlapNode__) */
