//
//  BoardingTheArkNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "BoardingTheArkNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
BoardingTheArkNode::BoardingTheArkNode():mAnimationManager(NULL),mentis(NULL),RatleSnake(NULL),Goat(NULL),Sheep(NULL),Ducks(NULL),Tiger(NULL),Croc(NULL),Zebra(NULL),Elephant(NULL),layer_possum(NULL),layer_camel(NULL),pig(NULL),pelican(NULL),porcupine(NULL),cangaru(NULL),other(NULL),allother(NULL),elephantWater1(NULL),elephantWater2(NULL)
{
    next_speech=1;
    is_comparing=false;
    isPlaying=false;
    is_elephantanimating=true;
    
}
BoardingTheArkNode::~BoardingTheArkNode()
{
    
}
void BoardingTheArkNode::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void BoardingTheArkNode::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    elephantWater2->setOpacity(0);
    elephantWater1->setOpacity(0);
    screenSize=CCDirector::sharedDirector()->getWinSize();
    isPlaying=false;
    CCNode::onEnter();
}
void BoardingTheArkNode::tick(CCTime dt)
{
    ////CCLog("Tick Method");
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void BoardingTheArkNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN BoardingTheArkNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler BoardingTheArkNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler BoardingTheArkNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool BoardingTheArkNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "layer_camel", CCLayer *, this->layer_camel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pig", CCSprite *, this->pig);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pelican", CCSprite *, this->pelican);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "porcupine", CCSprite *, this->porcupine);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cangaru", CCSprite *, this->cangaru);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "layer_possum", CCLayer *, this->layer_possum)
    
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mentis", CCLayer *, this->mentis)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "RatleSnake", CCLayer *, this->RatleSnake)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Goat", CCLayer *, this->Goat)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Sheep", CCLayer *, this->Sheep)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Ducks", CCLayer *, this->Ducks)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Tiger", CCLayer *, this->Tiger)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Croc", CCLayer *, this->Croc)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Zebra", CCLayer *, this->Zebra)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Elephant", CCLayer *, this->Elephant)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "elephantWater1", CCSprite *, this->elephantWater1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "elephantWater2", CCSprite *, this->elephantWater2);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "other",  CCLayerColor *, this->other)
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "allother",CCLayerColor*, this->allother)
    return false;
}
bool BoardingTheArkNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void BoardingTheArkNode::CamelTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.2f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("CamelTouched");
    }
}
void BoardingTheArkNode::StopIsPlaying(CCTime dt)
{
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying));
    isPlaying = false;
}
void BoardingTheArkNode::CrocTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 0.6f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("CrocTouched");
    }
}
void BoardingTheArkNode::CangaruTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.0f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("cangarutouched");
    }
}
void BoardingTheArkNode::PelicanTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.2f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("pelicantouched");
    }
}
void BoardingTheArkNode::PigTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 2.2f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("pigtouched");
    }
}
void BoardingTheArkNode::PorcupineTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.6f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("PorcupineTouched");
    }
}
void BoardingTheArkNode::PossumTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.8f);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("possumtouched");
    }
}
void BoardingTheArkNode::ElephantTouched()
{
    isPlaying = true;
    this->schedule(schedule_selector(BoardingTheArkNode::StopIsPlaying), 1.8f);
    if (is_elephantanimating==true)
    {
        is_elephantanimating=false;
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager)
        {
            mAnimationManager->runAnimationsForSequenceNamed("ElephantTouched");
        }
        
          CCSequence *seq1;
        elephantWater1->setPosition(ccp(510*(screenSize.width/1024) + elephantWater1->getContentSize().width/2,screenSize.height - 370*(screenSize.height/768) + elephantWater1->getContentSize().height/2));
        elephantWater2->setPosition(ccp(510*(screenSize.width/1024) + elephantWater2->getContentSize().width/2,screenSize.height - 465*(screenSize.height/768) + elephantWater2->getContentSize().height/2));
        elephantWater2->setRotation(0);
        elephantWater2->setOpacity(0);
        elephantWater1->setOpacity(0);
        ccBezierConfig bezzier;
        bezzier.controlPoint_1 = ccp(elephantWater2->getPositionX() + 250*(screenSize.width/1024),elephantWater2->getPositionY() +130*(screenSize.height/768));
        bezzier.controlPoint_2 = ccp(elephantWater2->getPositionX() + 500*(screenSize.width/1024),elephantWater2->getPositionY() +100*(screenSize.height/768));
        bezzier.endPosition = ccp(elephantWater2->getPositionX() + 750*(screenSize.width/1024), elephantWater2->getPositionY() - 50*(screenSize.height/768));
        //elephantWater1->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCDelayTime::create(0.6f),CCFadeOut::create(0.1f),NULL));
        seq1=CCSequence::create(CCDelayTime::create(0.1f),CCFadeIn::create(0.1f),CCSpawn::create(CCBezierTo::create(1.5f, bezzier),CCRotateBy::create(2.5f, 80.0f),CCFadeOut::create(1.5f),NULL),CCCallFunc::create(this, callfunc_selector(BoardingTheArkNode::iselephantCompleted)),NULL);


        TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {
            if( GameManager::sharedGameManager()->get_devise_resolution()==1)
            {
                elephantWater1->setPosition(ccp(510*(screenSize.width/1024) + elephantWater1->getContentSize().width/2,screenSize.height - 370*(screenSize.height/768) + elephantWater1->getContentSize().height/2));
                elephantWater2->setPosition(ccp(510*(screenSize.width/1024) + elephantWater2->getContentSize().width/2,screenSize.height - 465*(screenSize.height/768) + elephantWater2->getContentSize().height/2));
                elephantWater2->setRotation(0);
                elephantWater2->setOpacity(0);
                elephantWater1->setOpacity(0);
                ccBezierConfig bezzier;
                bezzier.controlPoint_1 = ccp(elephantWater2->getPositionX() + 250*(screenSize.width/1024),elephantWater2->getPositionY() +130*(screenSize.height/768));
                bezzier.controlPoint_2 = ccp(elephantWater2->getPositionX() + 500*(screenSize.width/1024),elephantWater2->getPositionY() +100*(screenSize.height/768));
                bezzier.endPosition = ccp(elephantWater2->getPositionX() + 750*(screenSize.width/1024), elephantWater2->getPositionY() - 50*(screenSize.height/768));
                //elephantWater1->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCDelayTime::create(0.6f),CCFadeOut::create(0.1f),NULL));
                seq1=CCSequence::create(CCDelayTime::create(0.1f),CCFadeIn::create(0.1f),CCSpawn::create(CCBezierTo::create(1.5f, bezzier),CCRotateBy::create(1.5f, 80.0f),CCFadeOut::create(1.5f),NULL),CCCallFunc::create(this, callfunc_selector(BoardingTheArkNode::iselephantCompleted)),NULL);
            }
            if(GameManager::sharedGameManager()->get_devise_resolution()==2)
            {
                elephantWater1->setPosition(ccp(510*(screenSize.width/1024) + elephantWater1->getContentSize().width/2,screenSize.height - 370*(screenSize.height/768) + elephantWater1->getContentSize().height/2));
                elephantWater2->setPosition(ccp(510*(screenSize.width/1024) + elephantWater2->getContentSize().width/2,screenSize.height - 465*(screenSize.height/768) + elephantWater2->getContentSize().height/2));
                elephantWater2->setRotation(0);
                elephantWater2->setOpacity(0);
                elephantWater1->setOpacity(0);
                ccBezierConfig bezzier;
                bezzier.controlPoint_1 = ccp(elephantWater2->getPositionX() + 250*(screenSize.width/1024),elephantWater2->getPositionY() +130*(screenSize.height/768));
                bezzier.controlPoint_2 = ccp(elephantWater2->getPositionX() + 500*(screenSize.width/1024),elephantWater2->getPositionY() +100*(screenSize.height/768));
                bezzier.endPosition = ccp(elephantWater2->getPositionX() + 750*(screenSize.width/1024), elephantWater2->getPositionY() - 50*(screenSize.height/768));
                //elephantWater1->runAction(CCSequence::create(CCFadeIn::create(0.1f),CCDelayTime::create(0.6f),CCFadeOut::create(0.1f),NULL));
                seq1=CCSequence::create(CCDelayTime::create(0.1f),CCFadeIn::create(0.1f),CCSpawn::create(CCBezierTo::create(2.5f, bezzier),CCRotateBy::create(1.5f, 80.0f),CCFadeOut::create(1.5f),NULL),CCCallFunc::create(this, callfunc_selector(BoardingTheArkNode::iselephantCompleted)),NULL);

            }
        }
         elephantWater2->runAction(seq1);
    }
}
void BoardingTheArkNode::iselephantCompleted()
{
    is_elephantanimating=true;
}
void BoardingTheArkNode::EndAllSchedulers()
{
    this->unscheduleAllSelectors();
}
bool BoardingTheArkNode::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCPoint point =touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    if (isPlaying)return false;
    
    if (GameManager::sharedGameManager()->isNodeAtPoint(cangaru, point))
    {
        this->CangaruTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(layer_camel, point))
    {
        this->CamelTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(pelican, point))
    {
        this->PelicanTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(porcupine, point))
    {
        this->PorcupineTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(pig, point))
    {
        this->PigTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(layer_possum, point))
    {
        this->PossumTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(mentis, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/Mantis.mp3", false);
        CCLOG("Mentis touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Elephant, point))
    {
        this->ElephantTouched();
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Zebra, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/ZebraWhinny.mp3", false);
        CCLOG("zebra touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Croc, point))
    {
        this->CrocTouched();
        CCLOG("croc touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Tiger, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/Tiger.mp3", false);
        CCLOG("tiger touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Ducks, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/DucksMix.mp3", false);
        CCLOG("duck touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Sheep, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/SheepBaah.mp3", false);
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(Goat, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/Goat.mp3", false);
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(RatleSnake, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/BackRattleSnake.mp3", false);
        CCLOG("rental snake touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(other, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/OtterChuckle.mp3", false);
        CCLOG("other chuckle touched");
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(allother, point))
    {
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 10/AllTheOthers.mp3", false);
    }
    return true;
}
