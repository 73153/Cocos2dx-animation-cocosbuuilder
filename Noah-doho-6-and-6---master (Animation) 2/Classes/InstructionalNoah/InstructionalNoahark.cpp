//
//  InstructionalNoahark.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "InstructionalNoahark.h"
#include "../SoundManager/SoundManager.h"
#include "../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
InstructionalNoahark::InstructionalNoahark()
{
    
}
InstructionalNoahark::~InstructionalNoahark()
{

}
InstructionalNoahark* InstructionalNoahark::create(CCObject *_object, SEL_CallFuncO _selector1)
{
    InstructionalNoahark* ret = new InstructionalNoahark();
    if (ret)
    {
        if (ret->initWithSelector(_object,_selector1))
        {
            ret->autorelease();
        }
        else
        {
            delete ret;
            ret = NULL;
        }
    }
    
    return ret;
}
void InstructionalNoahark::onEnter()
{
    CCNode::onEnter();
}
bool InstructionalNoahark::initWithSelector(CCObject *_object, SEL_CallFuncO _selector1)
{
    if (InstructionalNoahark::init())
    {
        noah_btn_pressed=_selector1;
        parent=_object;
        flashyImage =CCSprite::create("arkGlow.png");
        flashyImage->setOpacity(0);
        CCString *buttonName=GameManager::sharedGameManager()->GetExclusiveName(ExclusiveGroupIDArks);
      
        if (buttonName->length() != 0) {
            
            arkBtn=CCMenuItemSprite::create(CCSprite::create(buttonName->getCString()), CCSprite::create(buttonName->getCString()), this,  menu_selector(InstructionalNoahark::pushBtn));
        }
        else{
             arkBtn=CCMenuItemSprite::create(CCSprite::create("ARK_NORMAL.png"), CCSprite::create("ARK_NORMAL.png"), this,  menu_selector(InstructionalNoahark::pushBtn));
        }
        arkBtn->setAnchorPoint(ccp(0, 0));
        menu =CCMenu::create(arkBtn,NULL);
        this->addChild(flashyImage,30);
        this->addChild(menu,20);
        flashyImage->setAnchorPoint(ccp(0, 0));
        flashyImage->setPosition(ccp(0,0));
        menu->setPosition(ccp(0,0));
        return true;
    }
    return false;
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void InstructionalNoahark::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN InstructionalNoahark::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
      return NULL;
}
SEL_MenuHandler InstructionalNoahark::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler InstructionalNoahark::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool InstructionalNoahark::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool InstructionalNoahark::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void InstructionalNoahark::SetBlackArk()
{
    blackArkIsSet = true;
    arkBtn->setSelectedImage(CCSprite::create("ARK_BLACK.png"));
    arkBtn->setNormalImage(CCSprite::create("ARK_BLACK.png"));

}
void InstructionalNoahark::SetNormalArk()
{
    blackArkIsSet = false;
    CCString * buttonName = GameManager::sharedGameManager()->GetExclusiveName(ExclusiveGroupIDArks);
    if (buttonName->length() != 0)
    {
        CCLOG("%s",buttonName->getCString());
        arkBtn->setSelectedImage(CCSprite::create(buttonName->getCString()));
        arkBtn->setNormalImage(CCSprite::create(buttonName->getCString()));
    }
    else
    {
        arkBtn->setSelectedImage(CCSprite::create("ARK_NORMAL.png"));
        arkBtn->setNormalImage(CCSprite::create("ARK_NORMAL.png"));
    }
}
void InstructionalNoahark::pushBtn(CCObject *sender)
{
    menu->runAction(CCFadeOut::create(0.2f));
    flashyImage->runAction(CCSequence::create(CCFadeIn::create(0.16f),CCDelayTime::create(0.21f),CCFadeOut::create(0.3f),NULL));
    CCCallFuncO *first  = CCCallFuncO::create(parent, noah_btn_pressed, parent);
    this->runAction(CCSequence::create(first, NULL));
 }
void InstructionalNoahark::setIsEnabled(bool val)
{
    arkBtn->setEnabled(val);
}
void InstructionalNoahark::MakeVisibleAgain()
{
    menu->setOpacity(255);
}
