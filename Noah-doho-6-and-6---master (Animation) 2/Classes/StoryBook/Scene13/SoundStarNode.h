//
//  SoundStarNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__SoundStarNode__
#define __Noah360__SoundStarNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class SoundStarNode: public cocos2d::CCNode
{

public:

    SoundStarNode();
    virtual ~SoundStarNode();
    virtual void onEnter();
    static SoundStarNode* create(CCString *type,bool draggable);
    bool initSoundStarNode(CCString *type,bool draggable);
    
  

    CCSprite* imageOnSound;
    CCString* starType;
    bool isPlaying;


    bool canBeDragged;
    CC_SYNTHESIZE_RETAIN(CCSprite*, imageNormal, imageNormal);
    CC_SYNTHESIZE(bool, isDrag, isDrag);
    CC_SYNTHESIZE(CCPoint, whereTouch, whereTouch);

    unsigned int star_sound;


    bool TestForTouch(CCPoint point);
    void touchMoved(CCPoint point,CCSprite* moonImage);
    void touchEnded();
    void SetNotIsPlaying();
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Noah360__SoundStarNode__) */
