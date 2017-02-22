//
//  BandSoundStarArrayNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__BandSoundStarArrayNode__
#define __Noah360__BandSoundStarArrayNode__

#include <iostream>
#include "../Scene18/BandSoundStarsNode.h"
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class BandSoundStarArrayNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BandSoundStarArrayNode, create);
    BandSoundStarArrayNode();
    virtual ~BandSoundStarArrayNode();
    virtual void onEnter();
    static BandSoundStarArrayNode* create(CCString *type, bool draggable);
    bool initBandSoundStarArrayNode(CCString *type, bool draggable);

    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCSize size;
    BandSoundStarsNode* moon;
    BandSoundStarsNode* starA;
    BandSoundStarsNode* starB;
    BandSoundStarsNode* starC;
    BandSoundStarsNode* starD;
    BandSoundStarsNode* starE;
    BandSoundStarsNode* starF;
    BandSoundStarsNode* starG;
    void testForTouchOnStar(CCPoint point);
    void MoveNode(BandSoundStarsNode* node,CCPoint point);
    void touchMoved(CCPoint point);
    void touchEnded();
    void RestartStars();

private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
  
};
#endif /* defined(__Noah360__BandSoundStarArrayNode__) */
