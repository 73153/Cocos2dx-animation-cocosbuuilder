//
//  ArkCompareNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "ArkCompareNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
ArkCompareNode::ArkCompareNode():mAnimationManager(NULL),lblmeasure(NULL),sprt_ark(NULL),is_comparing(false)
{
    //CCLog("Header Layer called");
    next_speech=1;
    is_comparing=false;
}
ArkCompareNode::~ArkCompareNode()
{
     // CC_SAFE_RELEASE(mAnimationManager);
     //CCLog("Header Layer removed");
}
void ArkCompareNode::onExit()
{
    this->stopAllActions();
    this->unscheduleAllSelectors();
    this->removeAllChildrenWithCleanup(true);
}
void ArkCompareNode::onEnter()
{
    CCNode::onEnter();
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        sprt_ark->setScale(0.9);
    }
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            this->lblmeasure->setFontSize(45);
            break;
        case 2:
            this->lblmeasure->setFontSize(25);
            break;
        case 3:
            this->lblmeasure->setFontSize(24);
            break;
        case 4:
            this->lblmeasure->setFontSize(23);
            break;
            
        default:
            break;
    }

}
void ArkCompareNode::tick(CCTime dt)
{
    if (!SoundManager::sharedSoundManager()->isInstractunalNoahplaying())
    {
        if (next_speech!=1)
        {
            int k=next_speech;
            if (k==2)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_buses_remove");
                
            }
            else if (k==3)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_field_remove");
                
            }
            else if (k==4)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_elephant_remove");
            }
            is_comparing=false;
            this->unschedule(schedule_selector(ArkCompareNode::tick));
        }
    }
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void ArkCompareNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN ArkCompareNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler ArkCompareNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler ArkCompareNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool ArkCompareNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprt_ark", CCSprite *, this->sprt_ark);
     CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lblmeasure", CCLabelTTF *, this->lblmeasure);
    return false;
}
bool ArkCompareNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void ArkCompareNode::compare_next_object()
{
    if (SoundManager::sharedSoundManager()->isInstractunalNoahplaying()&&is_comparing==true)
    return;
    
    is_comparing=true;
    mAnimationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (mAnimationManager)
    {
        next_speech++;
       
        if (next_speech > 4)
            next_speech =2;
        this->swith_on_instractunal_noah();
        SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
        if (next_speech!=1)
        {
             this->schedule(schedule_selector(ArkCompareNode::tick),1);
            int k=next_speech;
            if (k==2)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_buses");
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 6/Bus_School_Horn.mp3", false);
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-2.mp3"));
             
            }
            else if (k==3)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_field");
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 6/fieldWhistle.mp3", false);
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-4.mp3"));

            }
            else if (k==4)
            {
                mAnimationManager->runAnimationsForSequenceNamed("compare_anim_elephant");
               SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 6/ELEPHANT.mp3", false);
                SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 6/instructionalNoahScene6-3.mp3"));
            }
           
        }
        else
        {
            
        }
    }
}
void ArkCompareNode::swith_on_instractunal_noah()
{
    int angle = 0;//arc4random()%4;
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setRotation(angle*90);
    int offsetValue;
    switch (angle)
    {
        case 0:
            offsetValue = rand()%600-300;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,0));
            break;
        case 2:
            offsetValue = rand()%600-300;
             GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,screen_height+5));
            break;
        case 1:
            offsetValue = rand()%400-200;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(0-5,screen_height/2+offsetValue));

            break;
        case 3:
            offsetValue = rand()%400-200;
            GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width+5,screen_height/2+offsetValue));

            break;
            
        default:
            break;
    }
    GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->MakeNoahAppearWithoutBackground();
}