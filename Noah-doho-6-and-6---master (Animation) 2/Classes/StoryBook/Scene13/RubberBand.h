//
//  RubberBand.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__RubberBand__
#define __Noah360__RubberBand__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class RubberBand: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RubberBand, create);
    RubberBand();
    virtual ~RubberBand();
    virtual void onEnter();
    virtual bool init();
        CCSprite *slingShotBand;
	int bandState;
    int posInHeight;
    int posInLenght;
    int prevPosInHeight;
    int prevPosInLenght;
    int direction;
    CCSize size;
    CCPoint HandleTouch(CCPoint point);
    void LetGoBand();
    unsigned int sound_rubber;
    unsigned int sound_rubber_1;
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    int next_speech;
};
#endif /* defined(__Noah360__RubberBand__) */
