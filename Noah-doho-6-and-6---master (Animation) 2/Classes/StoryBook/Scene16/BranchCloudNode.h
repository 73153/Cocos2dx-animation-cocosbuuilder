//
//  BranchCloudNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__BranchCloudNode__
#define __Noah360__BranchCloudNode__
#include <iostream>
#include "../Scene16/BranchNode.h"
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
class BranchCloudNode: public BranchNode
{
public:
    BranchCloudNode();
    virtual ~BranchCloudNode();
    virtual void onEnter();
    bool initBranchCloud(branchType newType);
    static BranchCloudNode* create(branchType newType);
    CCArray* thunderCloudFrames;
    void Rumble(float dt);

};
#endif /* defined(__Noah360__BranchCloudNode__) */
