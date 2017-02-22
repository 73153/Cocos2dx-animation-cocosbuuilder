//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene8Layer__
#define __Demo__Scene8Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene8/ArkBuildingPiece.h"
//#include "../HomeScreen/homeLayerLoader.h"
 
USING_NS_CC;
USING_NS_CC_EXT;
class Scene8Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene8Layer, create);
        Scene8Layer();
        virtual ~Scene8Layer();
        virtual void onEnter();
        virtual void onExit();

    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCSize screenSize;

	CCSprite * background;
    ArkBuildingPiece * deck1_a;
    ArkBuildingPiece * deck1_b;
    ArkBuildingPiece * deck1_c;
    ArkBuildingPiece * deck1_d;
    ArkBuildingPiece * deck1_e;
    ArkBuildingPiece * deck1_f;
    ArkBuildingPiece * deck1_g;
    ArkBuildingPiece * deck1_h;
    ArkBuildingPiece * deck2_a;
    ArkBuildingPiece * deck2_b;
    ArkBuildingPiece * deck2_c;
    ArkBuildingPiece * deck2_d;
    ArkBuildingPiece * deck2_e;
    ArkBuildingPiece * deck2_f;
    ArkBuildingPiece * deck2_g;
    ArkBuildingPiece * deck2_h;
    ArkBuildingPiece * house_b;
    ArkBuildingPiece * house_c;
    ArkBuildingPiece * house_d;
    ArkBuildingPiece * house_e;
    ArkBuildingPiece * house_f;
    ArkBuildingPiece * house_g;
    ArkBuildingPiece * house_h;
    ArkBuildingPiece * house_i;
    ArkBuildingPiece * main_a;
    ArkBuildingPiece * main_b;
    ArkBuildingPiece * main_c;
    ArkBuildingPiece * main_d;
    
    
   
    CCSprite * house_roof;
    CCSprite * houseDust;
    bool interactionsEnabled;
    bool waytingForNarrator;
    
    int currentLevel;
    int zOrderCounter;
    int lastPlayed;
    
    void PieceIsCorrect();
    void AddNodeToScene(CCNode* node);
    void LeavingScene();
    void PlayPieceCorrect();
    void PlayHouseSound();
    void GetInstructionalNoahStartingLine(float dt);
    void add_arkPiece();
    
    void main_ark_Piece();
    void deck_1_ark_Piece();
    void deck_2_ark_Piece();
    void house_ark_Piece();
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
