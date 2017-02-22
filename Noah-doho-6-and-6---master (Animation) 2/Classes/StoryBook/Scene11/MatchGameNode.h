//
//  MatchGameNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__MatchGameNode__
#define __Noah360__MatchGameNode__

#include <iostream>
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCValue.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class MatchGamePiece;
class MatchGameNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener,public CCTargetedTouchDelegate{

public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MatchGameNode, create);
        MatchGameNode();
        virtual ~MatchGameNode();
        virtual void onEnter();
            virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

public:
    TargetPlatform platform;
   	CCSize screenSize;
    CC_SYNTHESIZE_RETAIN(CCArray*, piecesArray, piecesArray);
    int numberOfShownAnimals;
    CCSprite *restartButton;
    int firstShownAnimalType;
    int secondShownAnimalType;
    int totalPairedPieces;
    void insertPiecePosition(MatchGamePiece*piece,CCArray *piecesPosition);
    void CheckDoubleAnimals(CCTime dt);
    void fillPieceArray();
    void EndAllSchedulers();
    void RestartGame();
    bool isplaying;
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    
    
    unsigned int bell_Transition_sound;
    unsigned int card_flip_sound;
     unsigned int wrong_match_deny_sound;
    unsigned int    jingle_sound;

   
};
#endif /* defined(__Noah360__MatchGameNode__) */
