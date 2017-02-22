//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene19Layer.h"
#include  "../../GameManager/common_function.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Scene19/flowersNodeLoader.h"
#include "../Footer/FooterLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene19Layer::Scene19Layer():mAnimationManager(NULL),rainbow(NULL),flower_layer(NULL)
{
    is_adding_flower=false;
    arr_flower=CCArray::create();
    arr_flower->retain();
}
Scene19Layer::~Scene19Layer()
{
  
  //CCLog("Scene 19 closed");
}
void Scene19Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    SoundManager::sharedSoundManager()->stopNarrator();
    CCLayer::onExit();
}
void Scene19Layer::onEnter()
{
    SoundManager::sharedSoundManager()->stopBackgroundSound();

    this->setTouchEnabled(true);
    rainbow->setOpacity(0);
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        CCNode *node_bg=this->getChildByTag(11);
        node_bg->setPosition(ccpAdd(node_bg->getPosition(),ccp(0, 28)));
        rainbow->setPosition(node_bg->getPosition());
        flower_layer->setContentSize(CCSizeMake(flower_layer->getContentSize().width, flower_layer->getContentSize().height+50));
        flower_layer->setPosition(ccpAdd(flower_layer->getPosition(), ccp(0, -85)));
    }
    SoundManager::sharedSoundManager()->startBackgroundSound();

    this->startNode();
    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene19Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    platform = CCApplication::sharedApplication()->getTargetPlatform();

    CCLOG("on loaded called");
}
SEL_CallFuncN Scene19Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
  CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onNarratorStart", Scene19Layer::onNarratorStart);
    return NULL;
}
SEL_MenuHandler Scene19Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene19Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene19Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rainbow", CCSprite *, this->rainbow);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flower_layer", CCLayerColor *, this->flower_layer);
    return false;
}
bool Scene19Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void Scene19Layer::startNode()
{
    platform = CCApplication::sharedApplication()->getTargetPlatform();
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
          naturesoud_id=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/countryMorning.caf", false);
    }
    else
    {
          naturesoud_id=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/countryMorning.ogg", false);
    }
    int randTime = (rand()%2000 + 12000)/1000.0f;
    this->schedule(schedule_selector(Scene19Layer::PlayCountrySounds),randTime);
    isEnabled = true;
}
void Scene19Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (GameManager::sharedGameManager()->isNodeAtPoint(flower_layer, location))
    {
        bool is_flower=false;
        CCObject *obj=NULL;
        CCARRAY_FOREACH(arr_flower,obj)
        {
            flowersNode *flower_node_c=(flowersNode*)obj;
            if (is_adding_flower==false&&flower_node_c->IsPointOnFlowers(ccpSub(location, flower_node_c->getPosition())))
            {
                is_flower=true;
                is_adding_flower=true;
            }
            else
            {

            }
        }
        if (is_flower==false)
        {
            flowersNode *flower_node = flowersNode::create();
                this->addChild(flower_node);
                flower_node->ShowFlowers();
                //CCPoint location_point = flower_layer->convertToNodeSpace(location);
                arr_flower->addObject(flower_node);
                flower_node->setPosition(location);
        }
    }
    else if (rainbow->getOpacity()==0&&GameManager::sharedGameManager()->isNodeAtPoint(rainbow, location))
    {
        rainbow->runAction(CCSequence::create(CCCallFunc::create(this, callfunc_selector(Scene19Layer::addRainbowStars)),CCFadeIn::create(0.8f),CCDelayTime::create(2.2f),CCFadeOut::create(0.8f),NULL));
    }
   }
void Scene19Layer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    is_adding_flower=false;
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
}
void Scene19Layer::addRainbowStars()
{
    CCParticleSystemQuad* rainbowStars = CCParticleSystemQuad::create("raibowStars.plist");
    this->addChild(rainbowStars,10, 123);
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    rainbowStars->setPosition(ccp(size.width ,-168*size.height/768));
    ccBezierConfig bezzier;
    bezzier.controlPoint_1 = ccp((950*size.width)/1024 ,(415*size.height)/768);
    bezzier.controlPoint_2 = ccp((600*size.width)/1024,(670*size.height)/768);
    bezzier.endPosition = ccp(size.width/2,size.height);
    rainbowStars->runAction(CCSequence::create(CCDelayTime::create(0.8f),CCBezierTo::create(1.8f, bezzier),CCRemoveSelf::create(),NULL));

}
void Scene19Layer::PlayCountrySounds(CCTime dt)
{
   this->unschedule(schedule_selector(Scene19Layer::PlayCountrySounds));
    
    platform = CCApplication::sharedApplication()->getTargetPlatform();
    if(SoundManager::sharedSoundManager()->isEffectPlaying(naturesoud_id))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(naturesoud_id);
    }
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
         naturesoud_id=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/countryMorning.caf", false);
    }
    else
    {
         naturesoud_id=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/countryMorning.ogg", false);
    }
   int randTime = (rand()%2000 + 12000)/1000.0f;
   this->schedule(schedule_selector(Scene19Layer::PlayCountrySounds),randTime);
}
#pragma mark -
#pragma mark Call Function Selector
#pragma mark -
void Scene19Layer::onNarratorStart(CCNode* sender)
{
    SoundManager::sharedSoundManager()->startNarrator();
}