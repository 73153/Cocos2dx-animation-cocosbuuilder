//
//  flowersNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__flowersNode__
#define __Noah360__flowersNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
class flowersNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(flowersNode, create);
    flowersNode();
    virtual ~flowersNode();
    virtual void onEnter();
    virtual bool init();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    unsigned int flower_chime;
    CC_SYNTHESIZE(CCSprite*, flower1, flower1);
    CC_SYNTHESIZE(CCSprite*, flower2, flower2);
    CC_SYNTHESIZE(CCSprite*, flower3, flower3);
    CC_SYNTHESIZE(CCSprite*, flower4, flower4);
    void ShowFlowers();
    bool IsPointOnFlowers(CCPoint point);
public:
    void tick(CCTime  dt);
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__flowersNode__) */
