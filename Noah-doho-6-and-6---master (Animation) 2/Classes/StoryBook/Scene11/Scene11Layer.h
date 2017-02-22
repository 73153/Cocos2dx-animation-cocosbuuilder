//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene11Layer__
#define __Demo__Scene11Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene11/MatchGameNode.h"
//#include "../HomeScreen/homeLayerLoader.h"
 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene11Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene11Layer, create);
        Scene11Layer();
        virtual ~Scene11Layer();
        virtual void onEnter();
    virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        MatchGameNode *matchgamenode_;
        void onNarratorStart(CCNode* sender);
       // void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
