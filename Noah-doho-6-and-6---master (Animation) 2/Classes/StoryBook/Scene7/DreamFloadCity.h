//
//  DreamFloadCity.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__DreamFloadCity__
#define __Noah360__DreamFloadCity__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class DreamFloadCity: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(DreamFloadCity, create);
    DreamFloadCity();
    virtual ~DreamFloadCity();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    //ccb function callback
public:
    void start_animation();
    void stop_animation();

    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Noah360__DreamFloadCity__) */
