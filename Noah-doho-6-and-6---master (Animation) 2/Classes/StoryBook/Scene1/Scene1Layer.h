//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene1Layer__
#define __Demo__Scene1Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene1/CloudContainer.h"
#include "../Scene2/WikedCity.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class Scene1Layer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene1Layer, create);
        Scene1Layer();
        virtual ~Scene1Layer();
        virtual void onEnter();
        virtual void onExit();
        virtual void onExitTransitionDidStart();
        //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        //assign variables
        void init_settings();

        CCSize screenSize;

        CCSprite * background;
    
        CloudContainer* cloudContainer;
        WikedCity *wikedCity;
    void addWickedCity();
    //start narrator
    void onNarratorStart(CCNode* sender);
    void StartWikedCity(float  dt);
    void EndRotatingClouds(float dt);
    void EnableInteractions();
    private:
            cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__Scene1Layer__) */
