//  StarStoreLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "StarStoreLayer.h"
#include "../GameManager/GameManager.h"
#include "../SoundManager/SoundManager.h"
#include "../StarStore/StarStoreNode.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
USING_NS_CC_EXT;
StarStoreLayer::StarStoreLayer():headerbg(NULL),crossbtn(NULL),menu(NULL)
{
    CCLog("constructor called");
}
StarStoreLayer::~StarStoreLayer()
{
    CCLog("destracture called");
}
void StarStoreLayer::onExit()
{
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void StarStoreLayer::onEnter()
{
    this->setTouchEnabled(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    screenSize =CCDirector::sharedDirector()->getWinSize();
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("startStoreImagePack_android.plist", "startStoreImagePack.pvr.ccz");
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("startStoreImagePack.plist", "startStoreImagePack.pvr.gz");
#endif
    blackLayer =CCSprite::createWithSpriteFrameName("blackLayer.png");
    arkHitsBack =CCSprite::createWithSpriteFrameName("ARK-HITS-GRAPHIC.png");
    totalStarsBack =CCSprite::createWithSpriteFrameName("POINTS-GRAPHIC_5.png");
    levelsBack =CCSprite::createWithSpriteFrameName("LEVELS-GRAPHIC.png");
    ribbonImage =CCSprite::createWithSpriteFrameName("STAR-STORE-BANNER.png");
    scrollKnob =CCSprite::createWithSpriteFrameName("LEFT-ARROW-SLIDER-GRAPHIC.png");
    scrollStripe =CCSprite::createWithSpriteFrameName("scrollBar.png");
    
    blackLayer->setPosition(ccp( screenSize.width/2, screenSize.height - blackLayer->getContentSize().height/2));
    arkHitsBack->setPosition(ccp(29 *(screen_width/1024)+ arkHitsBack->getContentSize().width/2,screenSize.height - 53*(screen_height/768) -  arkHitsBack->getContentSize().height/2));
    totalStarsBack->setPosition(ccp(29*(screen_width/1024) + totalStarsBack->getContentSize().width/2,screenSize.height - 15*(screen_height/768) - totalStarsBack->getContentSize().height/2));
    levelsBack->setPosition(ccp(29*(screen_width/1024) + levelsBack->getContentSize().width/2,screenSize.height - 81*(screen_height/768) - levelsBack->getContentSize().height/2));
//    ribbonImage->setPosition(ccp(266*(screen_width/1024) + ribbonImage->getContentSize().width/2,screenSize.height - 37*(screen_height/768) - ribbonImage->getContentSize().height/2));
    ribbonImage->setPosition(ccp(screen_width/2,screenSize.height - 37*(screen_height/768) - ribbonImage->getContentSize().height/2));
    knobMaxPosition = blackLayer->getPositionY() - blackLayer->getContentSize().height/2 -scrollKnob->getContentSize().height/2;
    knobMinPosition = scrollKnob->getContentSize().height/2;
    scrollKnob->setPosition(ccp(4*(screen_width/1024) + scrollKnob->getContentSize().width/2,knobMaxPosition));
    scrollStripe->setPosition(ccp(scrollKnob->getPositionX()+ 7,scrollStripe->getContentSize().height/2 + 4*(screen_height/768)));

    SoundManager::sharedSoundManager()->stopBackgroundSound();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/Scene 10/noah_scene_10_ver3.mp3", true);
    
    this->addChild(blackLayer,-1);
    this->reorderChild(headerbg, 2);
    this->reorderChild(menu, 3);
    this ->addChild(ribbonImage, 12);
    this ->addChild(scrollStripe , 1);
    this ->addChild(scrollKnob, 16);
 
    //this->addChild(menu ,12);
    containerNode = CCNode::create();
    containerNode->setPosition(CCPointZero);
    this->addChild(containerNode,0);
    elements=CCArray::create();
    elements->retain();
    for (int index = 0; index<GameManager::sharedGameManager()->getstarStoreElements()->count() ; index++)
    {
        StarStoreNode* newStarNode =StarStoreNode::create(index, this,callfuncO_selector(StarStoreLayer::elementwasselecter));
        if (screen_width==1024||screen_width==960)
        {
          newStarNode->setPosition(ccp(0, blackLayer->getPositionY()-blackLayer->getContentSize().height-64*(screen_height/768)-((index*172)*((screen_height/768)))));
        }
        else
        {
            newStarNode->setPosition(ccp(0, blackLayer->getPositionY()-blackLayer->getContentSize().height-64*(screen_height/768)-((index*167)*((screen_height/768)))));
        }
        elements->addObject(newStarNode);
        containerNode->addChild(newStarNode,0);
    }
    if (screen_width==1024||screen_width==960)
    {
        maxHeight=(GameManager::sharedGameManager()->getstarStoreElements()->count()+1)*(172*(screen_height/768))+32*(screen_height/768)-768*(screen_height/768);
        
    }
    else
    {
        maxHeight=(GameManager::sharedGameManager()->getstarStoreElements()->count()+1)*(168*(screen_height/768))+32*(screen_height/768)-768*(screen_height/768);

    }
    this->schedule(schedule_selector(StarStoreLayer::tick));
     CCLayer::onEnter();
}
void StarStoreLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    ySpeed = 0;
    reverseSpeed = 0;
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->getLocationInView();
    point=CCDirector::sharedDirector()->convertToGL(point);
    shouldScroll = false;
    prevTouch = point;
    if (GameManager::sharedGameManager()->isNodeAtPoint(scrollKnob, point))
    {
        isTouchOnKnob = true;
        containerNode->stopAllActions();
        whereTouch=ccpSub(scrollKnob->getPosition(), point);
    }
    else
    {
               containerNode->stopAllActions();
            whereTouch=ccpSub(containerNode->getPosition(), point);
    }
    timeForLastTouch = 0;
}
void StarStoreLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->getLocationInView();
    point=CCDirector::sharedDirector()->convertToGL(point);
    if (timeForLastTouch <=1/30.0)
    {
        timeForLastTouch = 1/30.0f;
    }
    if (isTouchOnKnob)
    {
        if (point.y + whereTouch.y > knobMaxPosition)
        {
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMaxPosition));
        }
        else if(point.y + whereTouch.y < knobMinPosition)
        {
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMinPosition));
        }
        else
        {
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),point.y + whereTouch.y));
        }
        float newYValue = (knobMaxPosition - scrollKnob->getPositionY())*maxHeight/(knobMaxPosition-knobMinPosition);
        containerNode->setPosition(ccp(containerNode->getPositionX(),newYValue));
    }
    else
    {
        ySpeed = (point.y - prevTouch.y )/timeForLastTouch;
        prevTouch = point;
        containerNode->setPosition(ccp(containerNode->getPositionX(),point.y + whereTouch.y));
        float newYValue = knobMaxPosition - (containerNode->getPositionY())*(knobMaxPosition-knobMinPosition)/maxHeight;
        if (newYValue > knobMaxPosition) {
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMaxPosition));
        }
        else if(newYValue < knobMinPosition){
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMinPosition));
        }
        else{
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),newYValue));
        }
    }
    timeForLastTouch = 0;
}
void StarStoreLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location=CCDirector::sharedDirector()->convertToGL(location);
    if (isTouchOnKnob)
    {
        isTouchOnKnob = false;
        return;
    }
    if (containerNode->getPositionY()< 0) {
        ySpeed = 0;
        containerNode->runAction(CCEaseElasticOut::create(CCMoveTo::create(0.6f, ccp(0, 0)), 2));
    }
    else{
        if (maxHeight <= 0) {
            ySpeed = 0;
            containerNode->runAction(CCEaseElasticOut::create(CCMoveTo::create(0.6f, ccp(0, 0)), 2));
           
        }
        else if (containerNode->getPositionY()> maxHeight) {
            ySpeed = 0;
            containerNode->runAction(CCEaseElasticOut::create(CCMoveTo::create(0.6f, ccp(0, maxHeight)), maxHeight));
        }
        else{
            if (ySpeed!= 0) {
                shouldScroll = true;
            }
        }
    }
}
void StarStoreLayer::tick(float dt)
{
    timeForLastTouch += dt;
    if (shouldScroll)
    {
        if (ySpeed>0) {
            ySpeed -= dt*(700 + 400*reverseSpeed);
            if (ySpeed < 0) {
                ySpeed = 0;
            }
        }
        else if (ySpeed<0) {
            ySpeed += dt*(700 + 400*reverseSpeed);
            if (ySpeed > 0) {
                ySpeed = 0;
            }
        }
        if (ySpeed != 0) {
            if (! reverseSpeed) {
                if (containerNode->getPositionY()  + dt*ySpeed < dt*ySpeed*2) {
                    ySpeed = 0;
                    containerNode->runAction(CCEaseElasticOut::create(CCMoveTo::create(0.6f, ccp(0, 0)), 2.0f));
                }
                else if (containerNode->getPositionY() + dt*ySpeed > maxHeight + dt*ySpeed*2) {
                    ySpeed = 0;
                    containerNode->runAction(CCEaseElasticOut::create(CCMoveTo::create(0.6f, ccp(0, maxHeight)), 2.0f));
                }
                else{
                    containerNode->setPosition(ccp(containerNode->getPositionX(),containerNode->getPositionY() + dt*ySpeed));
                }
            }
            else {
                ySpeed *=-1;
            }
        }
        
        float newYValue = knobMaxPosition - (containerNode->getPositionY())*(knobMaxPosition-knobMinPosition)/maxHeight;
        if (newYValue > knobMaxPosition) {
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMaxPosition));
        }
        else if(newYValue < knobMinPosition){
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),knobMinPosition));
        }
        else{
            scrollKnob->setPosition(ccp(scrollKnob->getPositionX(),newYValue));
        }
    }
}
void StarStoreLayer::elementwasselecter(CCObject *pobj)
{
    CCLOG("star store element was selected");
    /*    if (((StarStoreNode*)sender).state == elementStatusBoughtSelected )
    {
        if (((StarStoreNode*)sender).exclusiveGroupId == 0)
        {
            return;
        }
        for (StarStoreNode* starNode in elements)
        {
            if (((StarStoreNode*)sender).exclusiveGroupId == starNode.exclusiveGroupId && ((StarStoreNode*)sender).myIndex != starNode.myIndex)
            {
                [starNode Unselect];
            }
        }
    }
    [totalStarsLabel setString:[NSString stringWithFormat:@"%d",[Settings sharedInstance].points]];
    [totalStarsLabel runAction:[CCSequence actions:[CCScaleTo actionWithDuration:0.2f scale:1.2f],[CCScaleTo actionWithDuration:0.2f scale:1.0f],nil]];*/
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void StarStoreLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN StarStoreLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler StarStoreLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCMenuItemSelector");
     CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "OncrossClicked", StarStoreLayer::OncrossClicked);
    return NULL;
}
SEL_CCControlHandler StarStoreLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool StarStoreLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "headerbg", CCLayerColor *, this->headerbg);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "crossbtn", CCMenuItemImage *, this->crossbtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menu", CCMenu *, this->menu);
    return false;
}
bool StarStoreLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
#pragma mark -
#pragma mark Callfunctionselector
#pragma mark -
void StarStoreLayer::OncrossClicked(CCNode* sender)
{
    CCScene *splash_scene=GameManager::sharedGameManager()->get_scene_at(GameManager::sharedGameManager()->getcurrent_scene().getValue());
    CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(0.5f, splash_scene));
}