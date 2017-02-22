//
//  CliffsAndClouds.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__CliffsAndClouds__
#define __Noah360__CliffsAndClouds__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class CliffsAndClouds: public cocos2d::CCNode
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CliffsAndClouds, create);
    CliffsAndClouds();
    virtual ~CliffsAndClouds();
    virtual void onEnter();
    virtual bool init();
    CCSprite *cloud1;
    CC_SYNTHESIZE_RETAIN(CCSprite*, cloud2, cloud2);
    void HideClouds();
    void ShowClouds();
    void SetCloudsInvisible();
    void EndEverything();
    CCSize size;

private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__CliffsAndClouds__) */
