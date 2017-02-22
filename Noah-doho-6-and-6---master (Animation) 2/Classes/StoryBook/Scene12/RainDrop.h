//
//  RainDrop.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__RainDrop__
#define __Noah360__RainDrop__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class RainDrop: public cocos2d::CCSprite
{

public:
        RainDrop();
        virtual ~RainDrop();
        virtual void onEnter();
        CC_SYNTHESIZE(int,belongsToCloud, belongsToCloud);
    virtual void onExit();
        static RainDrop* RainDropWithimagename(CCString* adropname);
    
};
#endif /* defined(__Noah360__RainDrop__) */
