//
//  BranchNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__BranchNode__
#define __Noah360__BranchNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../GameManager/GameManager.h"
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
class BranchNode: public cocos2d::CCNode
{
public:
    BranchNode();
    virtual ~BranchNode();
    virtual void onEnter();
    bool  initBranchNode(branchType newType);
    static BranchNode* create(branchType newType);

public:
    CC_SYNTHESIZE(bool, shouldBeRemoved_1, shouldBeRemoved_1);
    CC_SYNTHESIZE_RETAIN(CCSprite*, image_,image_);
    CC_SYNTHESIZE(branchType,type_,type_);
    bool isPointOnImage(CCPoint point);
    void setToRemove();
    void Rumble(float dt);
    CCArray* thunderCloudFrames;

   
};
#endif /* defined(__Noah360__BranchNode__) */
