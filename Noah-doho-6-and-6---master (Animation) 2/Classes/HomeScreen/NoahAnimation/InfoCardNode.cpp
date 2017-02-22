//
//  InfoCardNode.cpp
//  Noah360
//
//  Created by Neil D on 24/09/13.
//
//

#include "InfoCardNode.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
InfoCardNode::InfoCardNode():pages(NULL)
{
   
   
}
InfoCardNode::~InfoCardNode()
{

}
InfoCardNode* InfoCardNode::create(CCArray *sprites, CCString* bg_image)
{
    InfoCardNode* ret = new InfoCardNode();
    if (ret)
    {
        if (ret->initInfoCardNode(sprites,bg_image))
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
bool InfoCardNode::initInfoCardNode(CCArray *sprites, CCString* bg_image)
{
    if (InfoCardNode::init())
    {
        if (sprites)
        {
            if (sprites->count() > 0)
            {
                groundingNode =CCNode::create();
                groundingNode->setPosition(ccp(0,0));
                this->addChild(groundingNode,0);
                pages=CCArray::createWithArray(sprites);
                pages->retain();
                CCString *str=(CCString*)sprites->objectAtIndex(0);
                image=CCSprite::create(str->getCString());
                background=CCSprite::create(bg_image->getCString());
                prevGlow=CCSprite::createWithSpriteFrameName("Scene8/nextPrevGlow.png");
                nextGlow=CCSprite::createWithSpriteFrameName("Scene8/nextPrevGlow.png");

                next=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Scene8/nextPrevBtn.png"), CCSprite::createWithSpriteFrameName("Scene8/nextPrevBtn.png"), this, menu_selector(InfoCardNode::nextPressed));

                prev=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("Scene8/nextPrevBtn.png"), CCSprite::createWithSpriteFrameName("Scene8/nextPrevBtn.png"), this, menu_selector(InfoCardNode::prevPressed));
                
                
                menuNext =CCMenu::createWithItem(next);
                menuPrev=CCMenu::createWithItem(prev);
                
                prev->setEnabled(false);
                next->setEnabled(false);
                
                image->setPosition(ccp(0,0));

                background->setPosition(ccp(0,0));
                menuNext->setPosition(ccp(0,0));
                menuPrev->setPosition(ccp(0,0));
//                if (screen_height<768)
//                {
                    next->setPosition(ccp(120*(screen_width/1024),-background->getContentSize().height/2+prevGlow->getContentSize().height/2+10));
                    prev->setPosition(ccp(-122*(screen_width/1024),-background->getContentSize().height/2+prevGlow->getContentSize().height/2+10));
//                }
//                else
//                {
//                    next->setPosition(ccp(120*(screen_width/1024),-220*(screen_height/768)));
//                    prev->setPosition(ccp(-122*(screen_width/1024),-220*(screen_height/768)));
//                }

                nextGlow->setPosition(next->getPosition());
                prevGlow->setPosition(prev->getPosition());
                groundingNode->addChild(prevGlow,5);
                groundingNode->addChild(nextGlow,5);
                groundingNode->addChild(menuNext,4);
                groundingNode->addChild(menuPrev,4);
                groundingNode->addChild(image,2);
                groundingNode->addChild(background,0);
                next->setScaleX(-1);
                image->setOpacity(0);
                background->setOpacity(0);
                menuNext->setOpacity(0);
                menuPrev->setOpacity(0);
                prevGlow->setOpacity(0);
                nextGlow->setOpacity(0);
                currentPage = 0;
                maxPage = sprites->count()- 1;
               
            }
        }
        return true;
    }
    return false;
}
void InfoCardNode::appearAnimation()
{
    currentPage = 0;
    image->setOpacity(255);
    background->setOpacity(255);
    menuNext->setOpacity(255);
    groundingNode->setPosition(ccp(-40,0));
    next->setEnabled(true);
    groundingNode->runAction(CCSpawn::create(CCEaseElasticOut::create(CCMoveBy::create(0.2f, ccp(40, 0))),NULL));
    CCString *str=(CCString *)pages->objectAtIndex(0);
    CCLOG("%s",str->getCString());
    image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
}
void InfoCardNode::changePageAnimation()
{
    groundingNode->setPosition(ccp(-40,0));
    groundingNode->runAction(CCSpawn::create(CCEaseElasticOut::create(CCMoveBy::create(0.2f, ccp(40,0))),NULL));
}
void InfoCardNode::nextPressed()
{
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/textSwitch.mp3", false);
    nextGlow->runAction(CCSequence::create(CCFadeIn::create(0.2f),CCFadeOut::create(0.2f),NULL));
    if (currentPage < maxPage) {
        currentPage ++;
        CCString *str=(CCString*)pages->objectAtIndex(currentPage);
        image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
        
        prev->setEnabled(true);
        menuPrev->setOpacity(255);
        
        if (currentPage == maxPage) {
            menuNext->setOpacity(0);
            next->setEnabled(false);
        }
    }
    this->changePageAnimation();
}
void InfoCardNode::prevPressed()
{
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/textSwitch.mp3", false);
    prevGlow->runAction(CCSequence::create(CCFadeIn::create(0.2f),CCFadeOut::create(0.2f),NULL));
    if (currentPage > 0) {
        currentPage --;
        CCString *str=(CCString*)pages->objectAtIndex(currentPage);
        image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
        
        menuNext->setOpacity(255);
        next->setEnabled(true);
        
        if (currentPage == 0) {
            prev->setEnabled(false);
            menuPrev->setOpacity(0);
        }
    }
    this->changePageAnimation();
}
void InfoCardNode::Appear()
{
    this->appearAnimation();
}
void InfoCardNode::Disapear()
{
    prev->setEnabled(false);
    next->setEnabled(false);
    image->setOpacity(0);
    background->setOpacity(0);
    menuNext->setOpacity(0);
    menuPrev->setOpacity(0);
    prevGlow->setOpacity(0);
    nextGlow->setOpacity(0);
    groundingNode->setPosition(0,0);
}
bool InfoCardNode::TestForTouch(CCPoint touchPoint)
{
    if (currentPage == maxPage)
    {
        return GameManager::sharedGameManager()->isTouchOnArea(touchPoint,this->getPosition(), image->getContentSize().width/2,image->getContentSize().height/2);
    }
    return false;
}