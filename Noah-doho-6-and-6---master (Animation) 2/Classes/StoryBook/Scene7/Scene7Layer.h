//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene7Layer__
#define __Demo__Scene7Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../StoryBook/Scene7/DreamFloadWater.h"
#include "../../StoryBook/Scene7/DreamFloadCity.h"
#include "../../StoryBook/Scene7/DreamFloadBack.h"

//#include "../HomeScreen/homeLayerLoader.h"
 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene7Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene7Layer, create);
        Scene7Layer();
        virtual ~Scene7Layer();
        virtual void onEnter();
        virtual void onExit();
         virtual bool init();
        //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        //ccb function callback
        void onNarratorStart(CCNode* sender);
        bool toggle;

        CCSize screenSize;
        CCSprite * whiteOverlay;
        //Touch Delegate...
        virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
        DreamFloadWater *dreamFloadWater_;
        DreamFloadCity *dreamFloadcity_;
        DreamFloadBack* background;

        bool interactionsEnabled;
        bool waytingForNarrator;
        bool isAnimationRunning;
        private:
            cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
