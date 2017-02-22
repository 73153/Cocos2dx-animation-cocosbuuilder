//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__SplashLayer__
#define __Demo__SplashLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class SplashLayer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(SplashLayer, create);
        SplashLayer();
        virtual ~SplashLayer();
        virtual void onEnter();
        virtual void onExit();

    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
        void splash_faded(CCNode* sender);
    
        CCSprite *sprt;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
