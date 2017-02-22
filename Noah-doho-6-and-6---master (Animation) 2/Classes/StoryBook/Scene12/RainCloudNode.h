//
//  RainCloudNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__RainCloudNode__
#define __Noah360__RainCloudNode__

#include <iostream>
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Scene12/RainDrop.h"
#include "../Scene12/TheFloodNode.h"
 USING_NS_CC;
USING_NS_CC_EXT;

class RainCloudNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener,public CCTargetedTouchDelegate
{

public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RainCloudNode, create);
        RainCloudNode();
        virtual ~RainCloudNode();
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
    TargetPlatform platForm;
    CCSize winsize;
    CCSpriteBatchNode *sheet;
	CCSprite *cloud1;
	CCSprite *cloud1Text;
	CCSprite *cloud2;
	CCSprite *cloud2Text;
	CCSprite *cloud2L1;
	CCSprite *cloud2L2;
	CCSprite *cloud2L3;
	CCSprite *cloud3;
	CCSprite *cloud3Text;
	CCSprite *cloud3L1;
	CCSprite *cloud3L2;
	CCSprite *cloud3L3;
	CCSprite *cloud4;
	CCSprite *cloud4Text;
	CCSprite *cloud4L1;
	CCSprite *cloud4L2;
	CCSprite *cloud4L3;
	
	TheFloodNode *theFlood_;
	
	CCArray *rainDrops;
	
	bool cloud1Working;
	bool cloud2Working;
	bool cloud3Working;
	bool cloud4Working;
	
	bool bigRainHasCome;
	
	int maxRainDrops;
    
    void cloudsLoaded();
    void ResetCloud4();
    void ResetRainDrops();
    void wrapCloud1(float dt);
    void wrapCloud2(float dt);
    void wrapCloud2A(float dt);
    void wrapCloud2B(float dt);
    void wrapCloud21(float dt);
    void wrapCloud22(float dt);
    void wrapCloud3A(float dt);
    void wrapCloud3B (float dt);
    void wrapCloud31 (float dt);
    void wrapCloud32 (float dt);
    void wrapCloud4A (float dt);
    void wrapCloud4B (float dt);
    void wrapCloud4B2 (float dt);
    void wrapCloud41 (float dt);
    void wrapCloud42 (float dt);
    void wrapCloud4C (float dt);
    void  theBigRain (float dt);
    void theFlood (float dt);
    void theUnFlood (float dt);
    void theLittleRain (float dt);
        
    void thunder(float dt);
    void HandleTouch(CCPoint point);
    void StartBigFlood();
    void EndAllSchedulers();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    CC_SYNTHESIZE(unsigned int, waveSound, waveSound);
};
#endif /* defined(__Noah360__RainCloudNode__) */
