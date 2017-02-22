//
//  FooterLayer.cpp
//  Noah360
//  Created by Neil D on 03/10/13.
 
#include "FooterLayer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
FooterLayer::FooterLayer():lbl_narrator_text(NULL),bg_footer(NULL)
{
 
}
FooterLayer::~FooterLayer()
{
 
}
void FooterLayer::onEnter()
{
    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==19)
    {
        CCNode *node=this->getChildByTag(4);
        CCNode *node1=node->getChildByTag(3);
        CCNode *node2=node1->getChildByTag(2);
        if (node2)
        {
            node2->setVisible(false);
        }
    }
    //setting narrator text at the bottom of the screen....
    if (strcmp(GameManager::sharedGameManager()->get_narrator_text()->getCString(), "false")==0)
    {
        bg_footer->setOpacity(0);
    }
    else
    {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            this->lbl_narrator_text->setFontName("fonts/Portland LDO.ttf");
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if(GameManager::sharedGameManager()->getcurrent_scene().getValue()==10&&CCDirector::sharedDirector()->getWinSize().width!=1136&&((CCDirector::sharedDirector()->getWinSize().width!=960&&CCDirector::sharedDirector()->getWinSize().height!=640))&&screen_height>=768)
        {
            lbl_narrator_text->setContentSize(CCSizeMake(lbl_narrator_text->getContentSize().width, lbl_narrator_text->getContentSize().height+50));
            lbl_narrator_text->setVerticalAlignment(kCCVerticalTextAlignmentTop);
            lbl_narrator_text->setHorizontalAlignment(kCCTextAlignmentCenter);
            lbl_narrator_text->setPosition(ccpAdd(lbl_narrator_text->getPosition(), ccp(0,31)));
        }
        this->lbl_narrator_text->setFontName("Palatino");
       
        #endif
        float Kscale=0.0f;
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                Kscale=2.0;
                this->lbl_narrator_text->setFontSize(45);
                CCLOG("Device Resolution :1 ");
            }
            break;
            case 2:
            {
                CCLOG("Device Resolution :2");
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    Kscale=2.0;
                    this->lbl_narrator_text->setFontSize(25);
                }
                else
                {
                    Kscale=3.4;
                    this->lbl_narrator_text->setFontSize(25);
                }
            }
            break;
            case 3:
            {
                CCLOG("Device Resolution :3");
                if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==10)
                {
                    this->setPosition(CCPoint(0, 0));
                    this->lbl_narrator_text->setFontSize(18);
                }
                else
                {
                    Kscale=3.6;
                    this->lbl_narrator_text->setFontSize(18);
                }
            }
            break;
            case 4:
            {
                CCLOG("Device Resolution :4");
                Kscale=3.5;
                this->lbl_narrator_text->setFontSize(18);
            }
            break;
            default:
            break;
        }
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                Kscale=2.0;
                this->lbl_narrator_text->setFontSize(45);
            }
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                    Kscale=2.0;
                    this->lbl_narrator_text->setFontSize(25);
                }
                else
                {
                    Kscale=3.4;
                    this->lbl_narrator_text->setFontSize(25);
                }
            }
                break;
            case 3:
                if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==10)
                {
                    
                    this->setPosition(CCPoint(0, 0));
                    this->lbl_narrator_text->setFontSize(25);
                }
                else
                {
                    Kscale=3.6;
                    this->lbl_narrator_text->setFontSize(24);
                }
                break;
            case 4:
            {
                Kscale=3.5;
                this->lbl_narrator_text->setFontSize(23);
            }
                break;
            default:
                break;
        }
    #endif
       this->lbl_narrator_text->setString(GameManager::sharedGameManager()->get_narrator_text()->getCString());
        if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==12)
        {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            bold_rained=CCLabelTTF::create("rained.", "Published-iOS/fonts/Portland LDO Bold.ttf", lbl_narrator_text->getFontSize());
            this->lbl_narrator_text->setFontName("");
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
             bold_rained=CCLabelTTF::create("rained.", "Palatino-Bold", lbl_narrator_text->getFontSize());
    #endif
            bold_rained->setColor(ccBLACK);
            this->addChild(bold_rained);
            bold_rained->setPosition(ccp(2.88*(lbl_narrator_text->getContentSize().width/4)+(Kscale*(bold_rained->getContentSize().width/2)), lbl_narrator_text->getPositionY()-lbl_narrator_text->getContentSize().height/2));
            bg_footer->setOpacity(0);
        }
        else
        {
            bg_footer->setOpacity(255);
        }
    }
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void FooterLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN FooterLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler FooterLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onNext_scene_clicked", FooterLayer::onNext_scene_clicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPrevious_scene_clicked", FooterLayer::onPrevious_scene_clicked);
    return NULL;
}
SEL_CCControlHandler FooterLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool FooterLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lbl_narrator_text", CCLabelTTF *, this->lbl_narrator_text);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bg_footer", CCLayerColor *, this->bg_footer);
    return false;
}
bool FooterLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void FooterLayer::onPrevious_scene_clicked(CCObject* pSender)
{
    if (!GameManager::sharedGameManager()->get_header()->getmenu_toggle())
        return;
    
    if (GameManager::sharedGameManager()->get_header()->getis_paywall_opened())
        return;

    if (GameManager::sharedGameManager()->get_header()->getis_tips_showing())
        return;
    int next=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    next=next-1;
    #warning disable in app purchase
//    if (!GameManager::sharedGameManager()->is_next_scene_available(next))
//    {
//        GameManager::sharedGameManager()->get_header()->show_paywall();
//        return;
//    }

    GameManager::sharedGameManager()->remove_unused_data();
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/nextButtoPressed.mp3", false);
    GameManager::sharedGameManager()->gotoPreviousScene();
}
void  FooterLayer::onNext_scene_clicked(CCObject* pSender)
{
    
    if (!GameManager::sharedGameManager()->get_header()->getmenu_toggle())
        return;
    if (GameManager::sharedGameManager()->get_header()->getis_tips_showing())
        return;

    CCNode *node= GameManager::sharedGameManager()->getcurrent_layer();
    node->unscheduleAllSelectors();
    GameManager::sharedGameManager()->getcurrent_layer()->stopAllActions();

    int next=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    next=next+1;
    #warning disable in app purchase
    if (!GameManager::sharedGameManager()->is_next_scene_available(next))
    {
        GameManager::sharedGameManager()->get_header()->show_paywall();
        return;
    }
       if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==19)
      return;
    GameManager::sharedGameManager()->remove_unused_data();
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/nextButtoPressed.mp3", false);
    GameManager::sharedGameManager()->gotoNextScene();
}