//
//  MatchGameNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "MatchGameNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
#include "../Scene11/MatchGamePiece.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d_extensions;
using namespace cocos2d;

#define piecesStartOffsetX 172
#define piecesStartOffsetY 100
#define piecesOffsetX 170
#define piecesOffsetY 180
MatchGameNode::MatchGameNode()
{
    this->piecesArray=CCArray::create();
    this->piecesArray->retain();
    numberOfShownAnimals=0;
    //CCLog("Header Layer called");
}
MatchGameNode::~MatchGameNode()
{
    
}
void MatchGameNode::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void MatchGameNode::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    totalPairedPieces=0;
    isplaying=true;
    screenSize=CCDirector::sharedDirector()->getWinSize();
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene11.plist");
    restartButton = CCSprite::createWithSpriteFrameName("Scene11/replayButton.png");
    restartButton->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    restartButton->setVisible(false);
    this->addChild(restartButton,100);
    this->fillPieceArray();
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void MatchGameNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
     platform = CCApplication::sharedApplication()->getTargetPlatform();

}
SEL_CallFuncN MatchGameNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler MatchGameNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler MatchGameNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool MatchGameNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool MatchGameNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void MatchGameNode::insertPiecePosition(MatchGamePiece*piece,CCArray *piecesPosition)
{
    CCValue<CCPoint> *v3 = static_cast<CCValue<CCPoint> *>(piecesPosition->lastObject());
    //CCLog("%d",piecesPosition->count());
    piece->getimage()->setPosition(v3->getValue());
#warning iphone 5 patch
    if (screenSize.width==1136)
    {
        piece->getimage()->setScale(0.85);
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    piece->getimage()->setScale(0.85);
#endif
    
    piecesPosition->removeLastObject();
    this->addChild(piece,10);
    this->piecesArray->addObject(piece);
}
void MatchGameNode::fillPieceArray()
{
    CCArray *piecesPosition=CCArray::create();
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            CCPoint p=CCPointMake((piecesStartOffsetX*screenSize.width)/1024 + (j*piecesOffsetX*screenSize.width)/1024, (piecesStartOffsetY*screenSize.height)/768 + i*(piecesOffsetY*screenSize.height)/768 );
            CCValue<CCPoint> *value = CCValue<CCPoint>::valueWithValue(p);
            piecesPosition->addObject(value);
        }
    }
    piecesPosition=GameManager::sharedGameManager()->shuffle_array(piecesPosition, piecesPosition->count());
    this->insertPiecePosition(new MatchGamePiece("cerdito", AnimalTypeCerdo), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("elefante", AnimalTypeElefante),piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("gallina", AnimalTypeGalina), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("gato", AnimalTypeGato), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("leon", AnimalTypeLeon), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("mono", AnimalTypeMono), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("oveja", AnimalTypeOveja), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("panda", AnimalTypePanda), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("rana", AnimalTypeRana), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("vaca", AnimalTypeVaca), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("cerdito", AnimalTypeCerdo), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("elefante",AnimalTypeElefante), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("gallina", AnimalTypeGalina), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("gato", AnimalTypeGato), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("leon", AnimalTypeLeon), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("mono", AnimalTypeMono), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("oveja", AnimalTypeOveja), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("panda", AnimalTypePanda), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("rana", AnimalTypeRana), piecesPosition);
    this->insertPiecePosition(new MatchGamePiece("vaca", AnimalTypeVaca), piecesPosition);
    CCLOG("%d",piecesArray->count());
    
}
void MatchGameNode::CheckDoubleAnimals(CCTime dt)
{
    if (firstShownAnimalType == secondShownAnimalType)
    {
        //Correct Pair
        int point = 1;
        CCObject *pobj=NULL;
        CCARRAY_FOREACH(this->piecesArray, pobj)
        {
            MatchGamePiece* piece=(MatchGamePiece*)pobj;
            if (piece->getanimalType() == firstShownAnimalType)
            {
                piece->GotPaired();
                totalPairedPieces++;
                GameManager::sharedGameManager()->AddPoints(point, piece->getimage()->getPosition(), this);
                point--;
            }
        }
        
        
        
        if (SoundManager::sharedSoundManager()->isEffectPlaying(bell_Transition_sound))
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {

                SoundManager::sharedSoundManager()->stopSoundEffect(bell_Transition_sound);
                bell_Transition_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/Bell Transition.caf", false);
            }
            else
            {
                SoundManager::sharedSoundManager()->stopSoundEffect(bell_Transition_sound);
                bell_Transition_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/Bell Transition.ogg", false);
            }
            
        }
        else
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                bell_Transition_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/Bell Transition.caf", false);
            }
            else
            {
                bell_Transition_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/Bell Transition.ogg", false);
            }
        }
    }
    else
    {
        CCObject *pobj=NULL;
        CCARRAY_FOREACH(this->piecesArray, pobj)
        {
            MatchGamePiece* piece=(MatchGamePiece*)pobj;
            if (piece->getanimalType() == firstShownAnimalType)
            {
                piece->showBack();
            }
            if (piece->getanimalType()== secondShownAnimalType)
            {
                piece->showBack();
            }
        }
        
        if (SoundManager::sharedSoundManager()->isEffectPlaying(wrong_match_deny_sound))
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                SoundManager::sharedSoundManager()->stopSoundEffect(wrong_match_deny_sound);
                wrong_match_deny_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/wrong match deny.caf", false);
            }
            else
            {
                
                SoundManager::sharedSoundManager()->stopSoundEffect(wrong_match_deny_sound);
                wrong_match_deny_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/wrong match deny.ogg", false);
            }
        }
        else
        {
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                wrong_match_deny_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/wrong match deny.caf", false);
            }
            else
            {
                wrong_match_deny_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/wrong match deny.ogg", false);
            }
        }
    }
    numberOfShownAnimals = 0;
    if (totalPairedPieces == 20)
    {
        
        SoundManager::sharedSoundManager()->stopBackgroundSound();
        SoundManager::sharedSoundManager()->startBackgroundSound();
        //Won game
        GameManager::sharedGameManager()->AddPoints(5,ccp(screenSize.width/2, screenSize.height/2), this);
        restartButton->setVisible(true);
        isplaying=false;
        
        int angle = 0;
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setRotation(angle*90);
        int offsetValue = rand()%600-300;
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,0));
        SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
        SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 9/noahArkBuildFinished.mp3"));
        GameManager::sharedGameManager()->get_header()->SwitchOnInstructionalNoahWithoutBackGround();
    
        if (SoundManager::sharedSoundManager()->isEffectPlaying(jingle_sound))
        {
              SoundManager::sharedSoundManager()->stopSoundEffect(jingle_sound);
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
              
                jingle_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/jingle.mp3", false);
            }
            else
            {
                jingle_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/jingle.ogg", false);
            }
        }
        else
        {
              SoundManager::sharedSoundManager()->stopSoundEffect(jingle_sound);
            
            if (platform == kTargetIpad || platform ==kTargetIphone)
            {
                jingle_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/jingle.mp3", false);
            }
            else
            {
                jingle_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/jingle.ogg", false);
            }
        }
    }

    this->unschedule(schedule_selector(MatchGameNode::CheckDoubleAnimals));
}
void MatchGameNode::RestartGame()
{
    restartButton->setVisible(false);
    isplaying=true;
    CCArray *piecesPosition=CCArray::create();
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            CCPoint pnt=CCPointMake((piecesStartOffsetX*screenSize.width)/1024 + (j*piecesOffsetX*screenSize.width)/1024, (piecesStartOffsetY*screenSize.height)/768 + i*(piecesOffsetY*screenSize.height)/768 );
            //CCPoint pnt=CCPointMake(piecesStartOffsetX + j*piecesOffsetX, piecesStartOffsetY + i*piecesOffsetY);
            CCValue<CCPoint> *value = CCValue<CCPoint>::valueWithValue(pnt);
            piecesPosition->addObject(value);
        }
    }
    piecesPosition=GameManager::sharedGameManager()->shuffle_array(piecesPosition, piecesPosition->count());
    totalPairedPieces = 0;
    numberOfShownAnimals = 0;
    CCObject *pObj=NULL;
    CCARRAY_FOREACH(this->piecesArray, pObj)
    {
        MatchGamePiece* piece = (MatchGamePiece*)pObj;
        CCValue<CCPoint> *v3 = static_cast<CCValue<CCPoint> *>(piecesPosition->lastObject());
        piece->getimage()->setOpacity(255);
        piece->getimage()->setVisible(true);
        piece->getimage()->setPosition(v3->getValue());
        piecesPosition->removeLastObject();
        piece->showBack();
    }
}
void MatchGameNode::EndAllSchedulers()
{
    this->unscheduleAllSelectors();
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(this->piecesArray, pObj)
    {
        MatchGamePiece* piece = (MatchGamePiece*)pObj;
        piece->unscheduleAllSelectors();
    }
}
bool MatchGameNode::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCPoint touchPoint =touch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    if (isplaying==true)
    {
        if (numberOfShownAnimals == 1)
        {
            CCObject *pobj=NULL;
            CCARRAY_FOREACH(this->piecesArray, pobj)
            {
                MatchGamePiece* piece=(MatchGamePiece*)pobj;
                if (GameManager::sharedGameManager()->isNodeAtPoint(piece->getimage(), touchPoint))
                {
                    if (piece->wasTouched(touchPoint))
                    {
                        piece->showAnimal(piece->getanimalName());
                        
                        if (SoundManager::sharedSoundManager()->isEffectPlaying(card_flip_sound))
                        {
                            if (platform == kTargetIpad || platform ==kTargetIphone)
                            {
                                SoundManager::sharedSoundManager()->stopSoundEffect(card_flip_sound);
                                card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.caf", false);
                            }
                            else
                            {
                                SoundManager::sharedSoundManager()->stopSoundEffect(card_flip_sound);
                                card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.ogg", false);
                            }
                        }
                        else
                        {
                            if (platform == kTargetIpad || platform ==kTargetIphone)
                            {
                                card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.caf", false);
                            }
                            else
                            {
                                card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.ogg", false);
                            }
                        }
                        
                        secondShownAnimalType = piece->getanimalType();
                        numberOfShownAnimals = 2;
                        this->schedule(schedule_selector(MatchGameNode::CheckDoubleAnimals), 0.8f);
                    }
                    return true;
                }
            }
        }
        if (numberOfShownAnimals == 0)
        {
            CCObject *pobj=NULL;
            CCARRAY_FOREACH(this->piecesArray, pobj)
            {
                MatchGamePiece* piece=(MatchGamePiece*)pobj;
                if (GameManager::sharedGameManager()->isNodeAtPoint(piece->getimage(), touchPoint))
                {
                    piece->showAnimal(piece->getanimalName());
                    if (SoundManager::sharedSoundManager()->isEffectPlaying(card_flip_sound))
                    {
                        if (platform == kTargetIpad || platform ==kTargetIphone)
                        {
                            SoundManager::sharedSoundManager()->stopSoundEffect(card_flip_sound);
                            card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.caf", false);
                        }
                        else
                        {
                            SoundManager::sharedSoundManager()->stopSoundEffect(card_flip_sound);
                            card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.ogg", false);
                        }
                    }
                    else
                    {
                        if (platform == kTargetIpad || platform ==kTargetIphone)
                        {
                              card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.caf", false);
                        }
                        else
                        {
                            card_flip_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 11/card flip.ogg", false);
                        }
                    }
                    firstShownAnimalType =  piece->getanimalType();
                    numberOfShownAnimals = 1;
                    return true;;
                }
            }
        }
    }
    else
    {
        if (GameManager::sharedGameManager()->isNodeAtPoint(restartButton, touchPoint))
        {
            this->RestartGame();
        }
    }
    return false;
}
