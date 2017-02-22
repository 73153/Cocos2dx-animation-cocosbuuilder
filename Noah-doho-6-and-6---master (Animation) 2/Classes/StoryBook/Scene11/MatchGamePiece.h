//
//  MatchGamePiece.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__MatchGamePiece__
#define __Noah360__MatchGamePiece__

#include <iostream>
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#define AnimalTypeCerdo 0
#define AnimalTypeElefante 1
#define AnimalTypeGalina 2
#define AnimalTypeLeon 3
#define AnimalTypeMono 4
#define AnimalTypeOveja 5
#define AnimalTypePanda 6
#define AnimalTypeRana 7
#define AnimalTypeVaca 8
#define AnimalTypeGato 9
 USING_NS_CC;
USING_NS_CC_EXT;
class MatchGamePiece: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener, public CCTargetedTouchDelegate
{

public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MatchGamePiece, create);
        MatchGamePiece(const char *animalname_,int animaltype_);
        MatchGamePiece();
        virtual ~MatchGamePiece();
        virtual void onEnter();
        virtual void onExit();
        unsigned int got_paired;
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
  public:
    TargetPlatform platform;
    CC_SYNTHESIZE( CCString*, animalName, animalName);
    CC_SYNTHESIZE(int, animalType, animalType);
    CC_SYNTHESIZE(CCSprite*, image, image);
    CC_SYNTHESIZE(bool, pairWasFound, pairWasFound);
    CC_SYNTHESIZE(bool, isAnimalShowing, isAnimalShowing);
    void showAnimal(CCString *animalname_);
    void showBack();
    void GotPaired();
    bool isShowing();
    void EndAllSchedulers();
    CCString * getanimalName(int animalType);
    bool wasTouched(CCPoint  touchPoint);
};
#endif /* defined(__Noah360__MatchGamePiece__) */
