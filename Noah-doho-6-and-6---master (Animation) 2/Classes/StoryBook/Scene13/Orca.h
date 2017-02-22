//
//  Orca.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__Orca__
#define __Noah360__Orca__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Orca: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Orca, create);
    Orca();
    virtual ~Orca();
    virtual void onEnter();
    virtual bool init();
    
    CCSize size;

    CC_SYNTHESIZE_RETAIN(CCSprite*, image, image);
    bool orcaShouldStop;
    void StopOrca();
    void StartOrca();
    void EndEverything();
    void TestForOrcaMov();
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
   
};
#endif /* defined(__Noah360__Orca__) */
