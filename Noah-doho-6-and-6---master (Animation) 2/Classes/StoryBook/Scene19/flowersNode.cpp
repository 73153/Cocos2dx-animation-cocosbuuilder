//
//  flowersNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "flowersNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define distanceFlower 10
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width

flowersNode::flowersNode():mAnimationManager(NULL),flower1(NULL),flower2(NULL),flower3(NULL),flower4(NULL)
{
    
}

bool flowersNode::init()
{
    if (CCNode::init())
    {
        int i=0;
        i=rand()%6+1;
        std::vector<std::string> image;
        image.push_back("Scene19/flower1.png");
        image.push_back("Scene19/flower2.png");
        image.push_back("Scene19/flower3.png");
        image.push_back("Scene19/flower4.png");
        image.push_back("Scene19/flower5.png");
        image.push_back("Scene19/flower6.png");
        random_shuffle( image.begin(), image.end() );
        
        CCString  *str=CCString::create(image[0].c_str());
        //CCLog("%s",str->getCString());
        flower1=CCSprite::createWithSpriteFrameName(str->getCString());
        
        random_shuffle( image.begin(), image.end() );
        str=CCString::create(image[0].c_str());
        //CCLog("%s",str->getCString());
        flower2=CCSprite::createWithSpriteFrameName(str->getCString());
        
        random_shuffle( image.begin(), image.end() );
        str=CCString::create(image[0].c_str());
        //CCLog("%s",str->getCString());
        flower3 =CCSprite::createWithSpriteFrameName(str->getCString());
        
        random_shuffle( image.begin(), image.end() );
        str=CCString::create(image[0].c_str());
        //CCLog("%s",str->getCString());
        flower4 =CCSprite::createWithSpriteFrameName(str->getCString());
        
        this->addChild(flower1);
        this->addChild(flower2);
        this->addChild(flower3);
        this->addChild(flower4);
        
        flower1->setScale(0.1f);
        flower2->setScale(0.1f);
        flower3->setScale(0.1f);
        flower4->setScale(0.1f);
        
        flower1->setOpacity(0);
        flower2->setOpacity(0);
        flower3->setOpacity(0);
        flower4->setOpacity(0);
        flower1->setPosition(ccp(distanceFlower*(WINHEIGHT/768),distanceFlower*(WINWIDTH/1024)));
        flower2->setPosition(ccp(-distanceFlower*(WINHEIGHT/768),distanceFlower*(WINWIDTH/1024)));
        flower3->setPosition(ccp(distanceFlower*(WINHEIGHT/768),-distanceFlower*(WINWIDTH/1024)));
        flower4->setPosition(ccp(-distanceFlower*(WINHEIGHT/768),-distanceFlower*(WINWIDTH/1024)));
        return true;
    }
    return false;
}
flowersNode::~flowersNode()
{

}
void flowersNode::onEnter()
{
    CCNode::onEnter();
}
void flowersNode::tick(CCTime dt)
{
    ////CCLog("Tick Method");
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void flowersNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}

SEL_CallFuncN flowersNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler flowersNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler flowersNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool flowersNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flower1", CCSprite *, this->flower1);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flower2", CCSprite *, this->flower2);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flower3", CCSprite *, this->flower3);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flower4", CCSprite *, this->flower4);
    return false;
}
bool flowersNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}

void flowersNode::ShowFlowers()
{
    if (SoundManager::sharedSoundManager()->isEffectPlaying(flower_chime))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(flower_chime);
    }
    TargetPlatform platForm =GameManager::sharedGameManager()->getplatForm();
    if(platForm == kTargetIpad || platForm==kTargetIphone)
    {
           flower_chime=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/flowerChime.caf", false);
    }
    else
    {
           flower_chime=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/flowerChime.ogg", false);
    }
 
 flower1->runAction(CCSpawn::create(CCScaleTo::create(0.4f, 1.0f),CCFadeIn::create(0.2f),NULL));
 flower2->runAction(CCSpawn::create(CCScaleTo::create(0.4f, 1.0f),CCFadeIn::create(0.2f),NULL));
 flower3->runAction(CCSpawn::create(CCScaleTo::create(0.4f, 1.0f),CCFadeIn::create(0.2f),NULL));
 flower4->runAction(CCSpawn::create(CCScaleTo::create(0.4f, 1.0f),CCFadeIn::create(0.2f),NULL));

}
bool flowersNode::IsPointOnFlowers(CCPoint point)
{
    if (flower1->boundingBox().containsPoint(point))
    {
         return true;
    }
    if (flower2->boundingBox().containsPoint(point))
    {
       return true;
    }
    if (flower3->boundingBox().containsPoint(point))
    {
       return true;
    }
    if (flower4->boundingBox().containsPoint(point))
    {
      return true;
    }
    return false;
}

