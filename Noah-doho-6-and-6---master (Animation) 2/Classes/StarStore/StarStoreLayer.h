//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__StarStoreLayer__
#define __Demo__StarStoreLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class StarStoreLayer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(StarStoreLayer, create);

        CCLayerColor *headerbg;
        StarStoreLayer();
        virtual ~StarStoreLayer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    void OncrossClicked(CCNode* sender);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    void tick(float dt);
    void elementwasselecter(CCObject *pobj);
    CCSize screenSize;
    
    CCMenu* menu;
    CCMenuItem* closeBtn;
    CCMenuItemSprite* starStoreBtn;
    CCSprite* blackLayer;
    CCSprite* ribbonImage;
    CCSprite* totalStarsBack;
    CCSprite* levelsBack;
    CCSprite* arkHitsBack;
    CCSprite* scrollKnob;
    CCSprite* scrollStripe;
    CCMenuItemImage *crossbtn;
    
    CCPoint whereTouch;
	CCPoint prevTouch;
    float ySpeed;
    float timeForLastTouch;
    float knobMaxPosition;
    float knobMinPosition;
    float maxHeight;
    int reverseSpeed;
    
    bool shouldScroll;
    bool isTouchOnKnob;
    CCNode* containerNode;
    CCArray* elements;

};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
