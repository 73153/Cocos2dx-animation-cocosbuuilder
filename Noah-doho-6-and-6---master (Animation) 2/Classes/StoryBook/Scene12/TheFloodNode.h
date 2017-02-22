//
//  TheFloodNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__TheFloodNode__
#define __Noah360__TheFloodNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class TheFloodNode: public cocos2d::CCNode
{

public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TheFloodNode, create);
        TheFloodNode();
        virtual ~TheFloodNode();
        virtual void onEnter();
    CCSprite *image1;
    CCSprite *image2;
    CCSize winsize;
    CC_SYNTHESIZE(float, width, width);
    CC_SYNTHESIZE(float, height, height);
    void flood_came();
};
#endif /* defined(__Noah360__TheFloodNode__) */
