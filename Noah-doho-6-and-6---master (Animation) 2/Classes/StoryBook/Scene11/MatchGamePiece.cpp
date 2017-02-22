//
//  MatchGamePiece.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "MatchGamePiece.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
USING_NS_CC_EXT;

MatchGamePiece::MatchGamePiece():animalName(NULL),animalType(0)
{

}
MatchGamePiece::MatchGamePiece(const char *animalname_,int animaltype_)
{
   animalName=CCString::createWithFormat("%s",animalname_);
   animalType=animaltype_;
    isAnimalShowing=false;
   image =CCSprite::createWithSpriteFrameName("Scene11/ark-front_saturated.png");
   this->addChild(image);
}
MatchGamePiece::~MatchGamePiece()
{
 

}
void MatchGamePiece::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
    
}
void MatchGamePiece::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
   CCNode::onEnter();
    platform = CCApplication::sharedApplication()->getTargetPlatform();

}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void MatchGamePiece::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN MatchGamePiece::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler MatchGamePiece::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler MatchGamePiece::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool MatchGamePiece::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool MatchGamePiece::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void MatchGamePiece::GotPaired()
{

    pairWasFound = true;
    image->setOpacity(0);
    image->setVisible(false);
    if (SoundManager::sharedSoundManager()->isEffectPlaying(got_paired))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(got_paired);
    }

    if (strcmp(this->getanimalName(this->getanimalType())->getCString(), "gato")==0)
    {
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {
            
          got_paired =  SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("Sound/Scene 11/%s.caf",this->getanimalName(this->getanimalType())->getCString())->getCString(), false);

        }
        else
        {
            got_paired=SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 11/%s.ogg",this->getanimalName(this->getanimalType())->getCString())->getCString(), false);
        }
        
    }
    else
    {
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {
           got_paired = SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("Sound/Scene 11/%s.caf",this->getanimalName(this->getanimalType())->getCString())->getCString(), false);
        }
        else
        {
            got_paired=SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 11/%s.ogg",this->getanimalName(this->getanimalType())->getCString())->getCString(), false);
        }
        
    }
}
void MatchGamePiece::showAnimal(CCString *animalname_)
{
    image->setOpacity(255.0f);

    CCString *str=CCString::createWithFormat("Scene11/%s.png",this->getanimalName(this->getanimalType())->getCString());
    image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
    isAnimalShowing = true;
}
CCString * MatchGamePiece::getanimalName(int animalType)
{
    CCString *animalname_=NULL;
    switch (this->animalType)
    {
        case AnimalTypeCerdo:
            animalname_=CCString::create("cerdito");
            break;
        case AnimalTypeElefante:
            animalname_=CCString::create("elefante");
            break;
        case AnimalTypeGalina:
            animalname_=CCString::create("gallina");
            break;
        case AnimalTypeGato:
            animalname_=CCString::create("gato");
            break;
        case AnimalTypeLeon:
            animalname_=CCString::create("leon");
            break;
        case AnimalTypeMono:
            animalname_=CCString::create("mono");
            break;
        case AnimalTypeOveja:
            animalname_=CCString::create("oveja");
            break;
        case AnimalTypePanda:
            animalname_=CCString::create("panda");
            break;
            
        case AnimalTypeRana:
            animalname_=CCString::create("rana");
            break;
        case AnimalTypeVaca:
            animalname_=CCString::create("vaca");
            break;
        default:
            animalname_=CCString::create("front_saturated");
            break;
    }
    return animalname_;
}
void MatchGamePiece::showBack()
{
    image->setOpacity(255.0f);
    image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scene11/ark-front_saturated.png"));
    isAnimalShowing = false;

}
bool MatchGamePiece::isShowing()
{
    return isAnimalShowing;
}
void MatchGamePiece::EndAllSchedulers()
{
    this->unscheduleAllSelectors();
}
bool MatchGamePiece::wasTouched(CCPoint  touchPoint)
{
    if (isAnimalShowing)
        return false;
    return GameManager::sharedGameManager()->isNodeAtPoint(image, touchPoint);
}