//
//  TipsLayer.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#ifndef __Noah360__TipsLayer__
#define __Noah360__TipsLayer__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class TipsLayer: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TipsLayer, create);
    TipsLayer();
    virtual ~TipsLayer();
    virtual void onEnter();
    virtual bool init();
    virtual void onExit();
    
    CC_SYNTHESIZE_RETAIN(CCSprite*, tipsholder, tipsholder);
    CC_SYNTHESIZE_RETAIN(CCSprite*, tips_pointer_2, tips_pointer_2);
    CC_SYNTHESIZE_RETAIN(CCSprite*, tips_pointer_1, tips_pointer_1);
    
    
    int current_tips;
    void show_tips(int tips_id);
    void show_tip_1();
    void show_tip_2();
    void show_tip_3();
    void show_tip_4();
    void start_tips();
    void completed_tips();
};
#endif /* defined(__Noah360__TipsLayer__) */
