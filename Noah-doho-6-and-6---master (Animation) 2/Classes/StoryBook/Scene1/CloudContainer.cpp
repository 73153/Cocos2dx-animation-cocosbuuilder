//
//  CloudContainer.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "CloudContainer.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
CloudContainer::CloudContainer():mAnimationManager(NULL)
{

  
}
CloudContainer::~CloudContainer()
{
    
}
void CloudContainer::onExit()
{
    SoundManager::sharedSoundManager()->stopSoundEffect(ambient);
}
void CloudContainer::onEnter()
{
    // Set to autorelease
    TimeToZoomIn = false;
    startZorder = 1;
    //0.8f
    float startScale1 = RotatingCloudStartScale + 0 * ((RotatingCloudFinishScale-RotatingCloudStartScale)/MaxRotingClouds);
    //1.48
    float startScale2 = RotatingCloudStartScale + 1 * ((RotatingCloudFinishScale-RotatingCloudStartScale)/MaxRotingClouds);
    //2.16
    float startScale3 = RotatingCloudStartScale + 2 * ((RotatingCloudFinishScale-RotatingCloudStartScale)/MaxRotingClouds);
    //2.84
    float startScale4 = RotatingCloudStartScale + 3 * ((RotatingCloudFinishScale-RotatingCloudStartScale)/MaxRotingClouds);
    //3.52
    float startScale5 = RotatingCloudStartScale + 4 * ((RotatingCloudFinishScale-RotatingCloudStartScale)/MaxRotingClouds);
    clouds1=new RotatingCloud(startScale1, 0, 0);
    clouds2=new RotatingCloud(startScale2, 20, 120);
    clouds3=new RotatingCloud(startScale3, 40, 240);
    clouds4=new RotatingCloud(startScale4, 60, 360);
    clouds5=new RotatingCloud(startScale5, 80, 480);
    
    this->addChild(clouds1,1);
    this->addChild(clouds2,2);
    this->addChild(clouds3,3);
    this->addChild(clouds4,4);
    this->addChild(clouds5,5);
    this->schedule(schedule_selector(CloudContainer::tick));
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void CloudContainer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ////CCLog("on loaded called");
}
SEL_CallFuncN CloudContainer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler CloudContainer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler CloudContainer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    ////CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool CloudContainer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool CloudContainer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    ////CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void CloudContainer::tick(CCTime dt)
{
    bool shouldReorderAll = false;
    for (int i = 0; i<this->getChildrenCount(); i++)
    {
        RotatingCloud* oldCloud = (RotatingCloud*)this->getChildren()->objectAtIndex(i);
        if (oldCloud->gethasFinishedRotating())
        {
            if (!TimeToZoomIn)
            {
                shouldReorderAll =true;
                this->reorderChild(oldCloud,0);
                oldCloud->ResetScaleAndPosition();
            }
            else
            {
                oldCloud->unscheduleAllSelectors();
                oldCloud->stopAllActions();
                oldCloud->EndAll();
                this->removeChild(oldCloud,true);
            }
            break;
        }
    }
    if (shouldReorderAll)
    {
        this->reorderChild(clouds1, clouds1->getZOrder()+1);
        this->reorderChild(clouds2, clouds2->getZOrder()+1);
        this->reorderChild(clouds3, clouds3->getZOrder()+1);
        this->reorderChild(clouds4, clouds4->getZOrder()+1);
        this->reorderChild(clouds5, clouds5->getZOrder()+1);
    }
}
void CloudContainer::EndZoomIn()
{
    TimeToZoomIn = true;
}
void CloudContainer::EndAll()
{
    this->unscheduleAllSelectors();
}
