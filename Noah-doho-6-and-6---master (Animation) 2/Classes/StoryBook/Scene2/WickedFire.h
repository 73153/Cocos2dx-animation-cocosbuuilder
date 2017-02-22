//
//  CloudContainer.h
//  Noah360
//
//  Created by Neil D on 24/09/13.
//
//

#ifndef __Noah360__WickedFire__
#define __Noah360__WickedFire__
#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
class WickedFire: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
   public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WickedFire, create);
    WickedFire(void);
    ~WickedFire(void);
    virtual void onEnter();
    virtual void onExit();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    CCAnimation *animation;
    CC_SYNTHESIZE_RETAIN(CCSprite *, fire, fire);

    CC_SYNTHESIZE_RETAIN(CCParticleSystemQuad *, smoke, smoke);
    CC_SYNTHESIZE_RETAIN(CCParticleSystemQuad *, firefx, firefx);
//    
    
    

    
    
    CC_SYNTHESIZE( bool, isExtinguished, isExtinguished);
    int fireSoundStatus;
    void tick(CCTime dt);
    void InitFire();
    void RestartFire();
    void ExtingFire();
    void StopSounds();
};
#endif /* defined(__Noah360__WickedFire__) */
