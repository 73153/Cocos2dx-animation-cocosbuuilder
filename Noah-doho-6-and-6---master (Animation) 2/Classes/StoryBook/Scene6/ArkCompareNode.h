//
//  ArkCompareNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__ArkCompareNode__
#define __Noah360__ArkCompareNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class ArkCompareNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ArkCompareNode, create);
    ArkCompareNode();
    virtual ~ArkCompareNode();
    virtual void onEnter();
    virtual  void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    //ccb function callback
public:
    void tick(CCTime  dt);
    CCLabelTTF *lblmeasure;
    CCSprite *sprt_ark;
    void compare_next_object();
    void swith_on_instractunal_noah();
    CC_SYNTHESIZE(bool, is_comparing, is_comparing);
    unsigned int is_noah_instracting;
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    int next_speech;
};
#endif /* defined(__Noah360__ArkCompareNode__) */
