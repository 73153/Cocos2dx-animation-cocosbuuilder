//
//  FooterLayer.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#ifndef __Noah360__FooterLayer__
#define __Noah360__FooterLayer__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class FooterLayer: public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(FooterLayer, create);
        FooterLayer();
        virtual ~FooterLayer();
        virtual void onEnter();

        //CCB methods...
        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
        virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
        virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
        virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        CC_SYNTHESIZE(CCLabelTTF*, bold_rained, bold_rained);
        CC_SYNTHESIZE(CCLabelTTF *, lbl_narrator_text, lbl_narrator_text);
        CCLayerColor *bg_footer;
        void onNext_scene_clicked(CCObject* pSender);
        void onPrevious_scene_clicked(CCObject* pSender);
};
#endif /* defined(__Noah360__FooterLayer__) */
