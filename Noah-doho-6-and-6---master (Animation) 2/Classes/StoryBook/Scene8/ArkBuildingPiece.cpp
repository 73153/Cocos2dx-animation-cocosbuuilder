//
//  ArkBuildingPiece.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "ArkBuildingPiece.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

ArkBuildingPiece::ArkBuildingPiece():arkPieceName(NULL),arkPieceLetter(NULL),isCorrect(false),isEnabled(false)
{

  
}
ArkBuildingPiece* ArkBuildingPiece::create(CCString *name,CCString *letter,CCPoint spos,CCPoint bcpos, CCPoint fcpos,CCObject *obj,SEL_CallFuncO selector)
{
    ArkBuildingPiece* ret = new ArkBuildingPiece();
    if (ret)
    {
        if (ret->initArkBuildingPiece(name,letter,spos,bcpos,fcpos,obj,selector))
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
bool ArkBuildingPiece::initArkBuildingPiece(CCString *name,CCString *letter,CCPoint spos,CCPoint bcpos, CCPoint fcpos,CCObject *obj,SEL_CallFuncO selector)
{
    if (CCNode::init())
    {
        arkPieceName = CCString::create(name->getCString());
        arkPieceLetter= CCString::create(letter->getCString());
        arkPieceName->retain();
        arkPieceLetter->retain();

        callback_selector=selector;
        parent=obj;

        scalefactor=CCDirector::sharedDirector()->getContentScaleFactor();
        startPosition =spos;
       
        image = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_block_%s.png",arkPieceName->getCString(),arkPieceLetter->getCString())->getCString());
        wire = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_wire_%s.png",arkPieceName->getCString(),arkPieceLetter->getCString())->getCString());
       
        size=CCSizeMake(1024/CCDirector::sharedDirector()->getContentScaleFactor(), 768/CCDirector::sharedDirector()->getContentScaleFactor());
       
        bcpos = CCPointMake(bcpos.x/scalefactor, bcpos.y/scalefactor);
        blockCorrectPosition=ccp(bcpos.x + image->getContentSize().width/2,768*(screen_height/768) - bcpos.y - image->getContentSize().height/2);
       
        fcpos = CCPointMake(fcpos.x/scalefactor, fcpos.y/scalefactor);
        finishedCorrectPosition = fcpos;
        image->setPosition(startPosition);
        image->setOpacity(0);
        wire->setOpacity(0);

        this->addChild(image);
        this->addChild(wire);
        this->schedule(schedule_selector(ArkBuildingPiece::tick));
       
        return true;
    }
    return false;
}
ArkBuildingPiece::~ArkBuildingPiece()
{

}
void ArkBuildingPiece::onExit()
{
    this->isEnabled=false;
    CCNode::onExit();
}
void ArkBuildingPiece::onEnter()
{
    CCNode::onEnter();
}
void ArkBuildingPiece::SetWirePosition(CCPoint pos ,CCSize screenSize)
{
    float scalefactor=CCDirector::sharedDirector()->getContentScaleFactor();
    pos=CCPointMake(pos.x/scalefactor,pos.y/scalefactor);
    wire->setPosition(ccp(pos.x + wire->getContentSize().width/2,screenSize.height - pos.y - wire->getContentSize().height/2));
}
void ArkBuildingPiece::stopSwallingTouchs()
{
    isCorrect = false;
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleAllSelectors();
}
bool ArkBuildingPiece::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	if (isCorrect)
        return false;
    
	CCPoint touchPoint = touch->getLocationInView();
	touchPoint =CCDirector::sharedDirector()->convertToGL(touchPoint);
    if (GameManager::sharedGameManager()->isNodeAtPoint(image, touchPoint))
    {
        isDrag=true;
		whereTouch=ccpSub(image->getPosition(), touchPoint);
		return true;
	}
	return false;
}
void ArkBuildingPiece::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    /* do your stuff here */
    if (isCorrect)
        return;
	CCPoint touchPoint = touch->getLocationInView();
 	touchPoint =CCDirector::sharedDirector()->convertToGL(touchPoint);
    image->setPosition(ccpAdd(touchPoint, whereTouch));
}
void ArkBuildingPiece::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
        isDrag = false;
    /* do your stuff here */
}
void ArkBuildingPiece::tick(float dt)
{
    if (isCorrect)
        return;
    if (ccpDistance(image->getPosition(), wire->getPosition()) <= 40||ccpDistance(image->getPosition(), blockCorrectPosition)<= 40)
    {
        isCorrect = true;
        //CCLog("image position:(%f,%f)",image->getPositionX(),image->getPositionY());
        //CCLog("wire position:(%f,%f)",wire->getPositionX(),wire->getPositionY());
        //CCLog("correct position:(%f,%f)",blockCorrectPosition.x,blockCorrectPosition.y);
        image->setPosition(blockCorrectPosition);
        if (SoundManager::sharedSoundManager()->isEffectPlaying(piece_to_place))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(piece_to_place);
         piece_to_place=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/pieceToPlace.mp3", false);
        }
        else
        {
            piece_to_place=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/pieceToPlace.mp3", false);
        }

        //CCLog("%s__%s",arkPieceName->getCString(),arkPieceLetter->getCString());
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_finished_%s.png",arkPieceName->getCString(),arkPieceLetter->getCString())->getCString())) {
              image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_finished_%s.png",arkPieceName->getCString(),arkPieceLetter->getCString())->getCString()));
        }
      
        image->setPosition(ccp(finishedCorrectPosition.x + image->getContentSize().width/2,768*(size.height/768) - finishedCorrectPosition.y - image->getContentSize().height/2));
        wire->runAction(CCFadeOut::create(0.2f));
      //  this->ShowPainted();
        CCLOG("%s %s",arkPieceName->getCString(),arkPieceLetter->getCString());
        //callback parent class...
        this->runAction(CCCallFuncO::create(parent, callback_selector, this));
    }
}
void ArkBuildingPiece::EnablePiece()
{
    isEnabled = true;
    image->runAction(CCFadeIn::create(0.4f));
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
void ArkBuildingPiece::ShowPainted()
{
    
   
   
}