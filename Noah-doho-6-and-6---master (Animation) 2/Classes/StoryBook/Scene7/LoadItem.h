//
//  LoadItem.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__LoadItem__
#define __Noah360__LoadItem__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class LoadItem: public cocos2d::CCNode
{
public:
    bool initLoadItem(CCString *name);
    static LoadItem* create(CCString *name);
    LoadItem();
    virtual ~LoadItem();
    virtual void onEnter();
    virtual void onExit();
    CCSprite* image;
};
#endif /* defined(__Noah360__LoadItem__) */
