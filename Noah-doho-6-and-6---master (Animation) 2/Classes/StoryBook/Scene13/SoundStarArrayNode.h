//
//  SoundStarArrayNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__SoundStarArrayNode__
#define __Noah360__SoundStarArrayNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SoundStarNode.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class SoundStarArrayNode: public cocos2d::CCNode
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(SoundStarArrayNode, create);
    SoundStarArrayNode();
    virtual ~SoundStarArrayNode();
    virtual void onEnter();
    virtual bool init();
    CCSize size;
    SoundStarNode* moon;
    SoundStarNode* starA;
    SoundStarNode* starB;
    SoundStarNode* starC;
    SoundStarNode* starD;
    SoundStarNode* starE;
    SoundStarNode* starF;
    SoundStarNode* starG;
    
    CCSprite* smallStars;

    void testForTouchOnStar(CCPoint point);
    void touchMoved(CCPoint point);
    void touchEnded();
    void RestartStars();
    void MoveNode(SoundStarNode* node,CCPoint point);

private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__SoundStarArrayNode__) */
