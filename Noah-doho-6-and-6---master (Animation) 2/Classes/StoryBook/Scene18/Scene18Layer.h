//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__Scene18Layer__
#define __Demo__Scene18Layer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene18/BandSoundStarArrayNode.h"

USING_NS_CC;
USING_NS_CC_EXT;
class Scene18Layer:public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Scene18Layer, create);
        Scene18Layer();
        virtual ~Scene18Layer();
        virtual void onEnter();
        virtual void onExit();
    //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    void animalband_play();

   	CCSprite * bulbs;
	CCSprite * tikiFire1;
	CCSprite * tikiFire2;
	CCSprite * gramofone;
	CCSprite * bear;
	CCSprite * racoon;
	CCSprite * snake;
	CCSprite * rabbit;
	CCSprite * hippo;
    
    unsigned int  bearSound;
    unsigned int  snakeSound1;
    unsigned int  snakeSound2;
    unsigned int  snakeSound3;
    unsigned int  snakeSound4;
    unsigned int  snakeSound5;
    unsigned int  snakeSound6;
    unsigned int  snakeSound7;
    unsigned int  snakeSound8;
    unsigned int  racoonSound;
    unsigned int  rabbitSound1;
    unsigned int  rabbitSound2;
    unsigned int  hippoSound;
    
    CCParticleSystemQuad* smoke1;
    CCParticleSystemQuad* smoke2;
    
    BandSoundStarArrayNode* starNode;
    
    CCLayerColor *snake1;
    CCLayerColor *snake2;
    CCLayerColor *snake3;
    CCLayerColor *snake4;
    CCLayerColor *snake5;
    CCLayerColor *snake6;
    CCLayerColor *snake7;
    CCLayerColor *snake8;
    CCLayerColor *rabbit1;
    CCLayerColor *rabbit2;

    bool interactionsEnabled;
    bool waytingForNarrator;
    bool isPlaying;
    bool narratorsPlaying;
    bool isEnabled;
    void tick(float  dt);
    CCPoint initialPostionTiki1;
    CCPoint initialPostionTiki2;
    CCPoint extinguishedPostionTiki1;
    CCPoint extinguishedPostionTiki2;
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
