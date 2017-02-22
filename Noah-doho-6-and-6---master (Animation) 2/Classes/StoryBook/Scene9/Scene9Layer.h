//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene9Layer__
#define __Demo__Scene9Layer__
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "cocos2d.h"
#include "cocos-ext.h"

//#include "../HomeScreen/homeLayerLoader.h"
 USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
class Scene9Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene9Layer, create);
        Scene9Layer();
        virtual ~Scene9Layer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    //Touch Delegate...
        virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
//        virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
         public:
        CCSprite * burns;
        CCSprite * dude;
        CCSprite * blackBeard;
        CCSprite * grandpa;
        CCSprite * gurlfriend;
        void WaitForSpeechToEnd(CCTime  dt);
        unsigned int speech_people;
        void onNarratorStart(CCNode* sender);
    
        void load_sounds();
        void playsound(CCString *str_path);
        std::vector<std::string> whimpyGuySpeeches;
        std::vector<std::string> whiteBeardSpeeches;
        std::vector<std::string> womenSpeeches;
        bool started_playing;

    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;
        unsigned int sound_people;

};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
