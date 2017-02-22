//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene6Layer__
#define __Demo__Scene6Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene6/ArkCompareNode.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Scene6Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene6Layer, create);
        Scene6Layer();
        virtual ~Scene6Layer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

        int is_narrator_playing;
    //Touch Delegate...
        virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
        virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

public:
    void tick(CCTime  dt);
    CCSize screenSize;
   

private:
        ArkCompareNode* arkCompareNode_;
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
        //ccb function callback
        void onNarratorStart(CCNode* sender);
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
