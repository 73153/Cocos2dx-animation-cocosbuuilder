//
//  InstructionalNoahark.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__InstructionalNoahark__
#define __Noah360__InstructionalNoahark__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class InstructionalNoahark: public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{

public:
    //CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(InstructionalNoahark, create);
    InstructionalNoahark();
    virtual ~InstructionalNoahark();
    virtual void onEnter();
   // virtual bool init();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);

    CCMenu* menu;
    CCMenuItemSprite* arkBtn;
    CC_SYNTHESIZE(bool, blackArkIsSet, blackArkIsSet);
    CC_SYNTHESIZE_RETAIN(CCSprite*, flashyImage, flashyImage);
    CCSprite* waterImage;
    void pushBtn(CCObject *sender);
    void setIsEnabled(bool val);
    void MakeVisibleAgain();
    void SetBlackArk();
    void SetNormalArk();
    bool initWithSelector(CCObject *_object, SEL_CallFuncO _selector1);

    CC_SYNTHESIZE_RETAIN(CCObject *, parent, parent);
    SEL_CallFuncO   noah_btn_pressed;
    static InstructionalNoahark* create(CCObject *_object, SEL_CallFuncO _selector1);
 
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
};
#endif /* defined(__Noah360__InstructionalNoahark__) */
