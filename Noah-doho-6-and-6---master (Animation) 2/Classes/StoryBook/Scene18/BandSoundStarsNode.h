//
//  BandSoundStarsNode.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__BandSoundStarsNode__
#define __Noah360__BandSoundStarsNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class BandSoundStarsNode: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BandSoundStarsNode, create);
    BandSoundStarsNode();
    static BandSoundStarsNode* create(CCString *type, bool draggable);
    bool initSoundStarsNode(CCString *type, bool draggable);
    virtual ~BandSoundStarsNode();
    virtual void onEnter();

    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCSprite* imageOnSound;
    
    CC_SYNTHESIZE_RETAIN(CCString*,starType,starType);
    bool isPlaying;
    unsigned int sound;
    bool canBeDragged;
    CC_SYNTHESIZE(bool, isDrag, isDrag);
    CC_SYNTHESIZE(CCPoint, whereTouch, whereTouch);    
    CC_SYNTHESIZE_RETAIN(CCSprite*, imageNormal, imageNormal);
    bool TestForTouch(CCPoint point);
    void touchMoved(CCPoint point,CCSprite*moonImage);
    void touchEnded();
    void SetNotIsPlaying();
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__BandSoundStarsNode__) */
