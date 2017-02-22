//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene19Layer__
#define __Demo__Scene19Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene19/flowersNode.h"

 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene19Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{ 
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene19Layer, create);
        Scene19Layer();
        virtual ~Scene19Layer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
        virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
public:
    TargetPlatform platform;

        bool isfinished;
        CCSprite* rainbow;
    
        void onNarratorStart(CCNode* sender);
        void startNode();
        bool isEnabled;
        bool is_adding_flower;
        void addRainbowStars();
        void removeRainbowStars();
        void PlayCountrySounds(CCTime dt);
        unsigned int naturesoud_id;
        CCLayerColor *flower_layer;
        CCArray *arr_flower;
    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
