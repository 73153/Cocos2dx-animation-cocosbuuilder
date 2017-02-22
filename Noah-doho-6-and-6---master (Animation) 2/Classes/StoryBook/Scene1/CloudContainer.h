//
//  CloudContainer.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__CloudContainer__
#define __Noah360__CloudContainer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene1/RotatingCloud.h"
#define RotatingCloudStartScale 0.8f
#define RotatingCloudFinishScale 4.2f
#define MaxRotingClouds 5

 USING_NS_CC;
USING_NS_CC_EXT;
class CloudContainer: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CloudContainer, create);
    CloudContainer();
    virtual ~CloudContainer();
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    
    int startZorder;
    RotatingCloud* clouds1;
    RotatingCloud* clouds2;
    RotatingCloud* clouds3;
    RotatingCloud* clouds4;
    RotatingCloud* clouds5;
    void tick(CCTime dt);
    CC_SYNTHESIZE(bool ,TimeToZoomIn , TimeToZoomIn);
    CC_SYNTHESIZE(unsigned int  ,ambient , ambient);
    void EndZoomIn();
    void EndAll();
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__CloudContainer__) */
