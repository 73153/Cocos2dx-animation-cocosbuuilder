#include "Scene18Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
Scene18Layer::Scene18Layer():mAnimationManager(NULL),bulbs(NULL),tikiFire1(NULL),tikiFire2(NULL),gramofone(NULL),bear(NULL),racoon(NULL),snake(NULL),rabbit(NULL),hippo(NULL),starNode(NULL),snake1(NULL),snake2(NULL),snake3(NULL),snake4(NULL),snake5(NULL),snake6(NULL),snake7(NULL),snake8(NULL),rabbit1(NULL),rabbit2(NULL)
{
     //CCLog("Scene 18 opened");
}
Scene18Layer::~Scene18Layer()
{
    //CCLog("Scene 18 closed");
}
void Scene18Layer::onExit()
{
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    CCLayer::onExit();
}
void Scene18Layer::onEnter()
{
    this->setTouchEnabled(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene16.plist");
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    smoke1=CCParticleSystemQuad::create("smoke.plist");
    smoke2=CCParticleSystemQuad::create("smoke.plist");
    smoke1->setLife(1.2f);
    smoke1->setLifeVar(0.6f);
    smoke2->setLife(1.2f);
    smoke2->setLifeVar(0.6f);
    this->addChild(smoke1, 30);
    this->addChild(smoke2, 340);
    smoke1->setPosition(tikiFire1->getPosition());
    smoke2->setPosition(tikiFire2->getPosition());
    isPlaying = true;
    this->animalband_play();
    if (CCDirector::sharedDirector()->getWinSize().width==1136)
    {
        CCNode *node=this->getChildByTag(11);
        node->setScaleY(0.833);
        node->setPosition(ccpAdd(node->getPosition(), ccp(0,-10)));
        bear->setScale(0.85);
        racoon->setScale(0.85);
        snake->setScale(0.85);
        rabbit->setScale(0.85);
        hippo->setScale(0.85);
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCNode *node=this->getChildByTag(11);
    node->setScaleY(0.833);
    node->setPosition(ccpAdd(node->getPosition(), ccp(0,-10)));
    bear->setScale(0.85);
    racoon->setScale(0.85);
    snake->setScale(0.85);
    rabbit->setScale(0.85);
    hippo->setScale(0.85);

#endif
    this->schedule(schedule_selector(Scene18Layer::tick),63);
    SoundManager::sharedSoundManager()->startBackgroundSound();
    CCLayer::onEnter();
}
void Scene18Layer::animalband_play()
{
    //animmating all the animals with one time line
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
         mAnimationManager->runAnimationsForSequenceNamed("bulb");
    }
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene18Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene18Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler Scene18Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene18Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene18Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bulbs", CCSprite *, this->bulbs);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "tikiFire1", CCSprite *, this->tikiFire1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "tikiFire2", CCSprite *, this->tikiFire2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gramofone", CCSprite *, this->gramofone);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "racoon", CCSprite *, this->racoon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bear", CCSprite *, this->bear);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake", CCSprite *, this->snake);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rabbit", CCSprite *, this->rabbit);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "hippo", CCSprite *, this->hippo);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "starNode", BandSoundStarArrayNode *, this->starNode);

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake1", CCLayerColor *, this->snake1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake2", CCLayerColor *, this->snake2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake3", CCLayerColor *, this->snake3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake4", CCLayerColor *, this->snake4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake5", CCLayerColor *, this->snake5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake6", CCLayerColor *, this->snake6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake7", CCLayerColor *, this->snake7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "snake8", CCLayerColor *, this->snake8);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rabbit1", CCLayerColor *, this->rabbit1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rabbit2", CCLayerColor *, this->rabbit2);
    return false;
}
bool Scene18Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void Scene18Layer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *ptouch=(CCTouch*)pTouches->anyObject();
    CCPoint plocation=ptouch->getLocationInView();
    plocation=CCDirector::sharedDirector()->convertToGL(plocation);
    if (GameManager::sharedGameManager()->isNodeAtPoint(snake1, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound1))
        {
             SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound1);
           snakeSound1 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound1.mp3", false);  
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound1);
            snakeSound1 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound1.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake2, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound2))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound2);
            snakeSound2 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound2.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound2);
            snakeSound2 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound2.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake3, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound3))
        {
             SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound3);
            snakeSound3 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound3.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound3);
            snakeSound3 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound3.mp3", false);
        }
   }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake4, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound4))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound4);
            snakeSound4 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound4.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound4);
            snakeSound4 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound4.mp3", false);
        }
     }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake5, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound5))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound5);
            snakeSound5 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound5.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound5);
            snakeSound5 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound5.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake6, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound6))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound6);
            snakeSound6 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound6.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound6);
            snakeSound6 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound6.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake7, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound7))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound7);
            snakeSound7 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound7.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound7);
            snakeSound7 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound7.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(snake8, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(snakeSound8))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound8);
            snakeSound8 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound8.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(snakeSound8);
            snakeSound8 =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/snakeTouchedSound8.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(bear, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(bearSound))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(bearSound);
            bearSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/bearTouchedSound.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(bearSound);
            bearSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/bearTouchedSound.mp3", false);
        }
      
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(racoon, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(racoonSound))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(racoonSound);
            racoonSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/racoonTouchedSound.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(racoonSound);
            racoonSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/racoonTouchedSound.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(hippo, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(hippoSound))
        {
             SoundManager::sharedSoundManager()->stopSoundEffect(hippoSound);
            hippoSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/hippoTouchedSound.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(hippoSound);
            hippoSound =SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/hippoTouchedSound.mp3", false);
        }
        
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(tikiFire1, plocation))
    {
        smoke2->setLife( 0.3f);
        smoke2->setLifeVar(0.2f);
//        tikiFire1->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 0.3f),CCMoveTo::create(0.3f, ccpAdd(tikiFire1->getPosition(), ccp(0,-20))),NULL));
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(tikiFire2, plocation))
    {
        smoke2->setLife( 0.3f);
        smoke2->setLifeVar(0.2f);
//        tikiFire2->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 0.3f),CCMoveTo::create(0.3f, ccpAdd(tikiFire2->getPosition(), ccp(0,-20))),NULL));

      //  tikiFire2->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 0.3f),CCMoveTo::create(0.3f, extinguishedPostionTiki2),NULL));
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(gramofone, plocation))
    {
        isPlaying = true;
        this->schedule(schedule_selector(Scene18Layer::tick),63);
       SoundManager::sharedSoundManager()->startBackgroundSound();
       mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
       if (mAnimationManager)
       {
           mAnimationManager->runAnimationsForSequenceNamed("bulb");
       }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(rabbit1, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(rabbitSound1))
        {
             SoundManager::sharedSoundManager()->stopSoundEffect(rabbitSound1);
            rabbitSound1 =  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/rabbitTouchedSound1.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(rabbitSound1);
           rabbitSound1 =  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/rabbitTouchedSound1.mp3", false);
        }
    }
    else if (GameManager::sharedGameManager()->isNodeAtPoint(rabbit2, plocation))
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(rabbitSound2))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(rabbitSound2);
           rabbitSound2 =  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/rabbitTouchedSound2.mp3", false);
        }
        else
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(rabbitSound2);
            rabbitSound2 =  SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 17/rabbitTouchedSound2.mp3", false);
        }
    }
    else
    {
        starNode->testForTouchOnStar(plocation);
    }
}
void Scene18Layer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    if (tikiFire1->getScale() != 1.0f)
    {
        smoke1->setLife(1.2f);
        smoke1->setLifeVar(0.6f);
        tikiFire1->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 1.0f),CCMoveTo::create(0.3f, initialPostionTiki1),NULL));
    }
    if (tikiFire2->getScale() != 1.0f)
    {
        smoke2->setLife(1.2f);
        smoke2->setLifeVar(0.6f);
        tikiFire2->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 1.0f),CCMoveTo::create(0.3f, initialPostionTiki2),NULL));
    }
    starNode->touchEnded();
}
void Scene18Layer::tick(float  dt)
{
        isPlaying=false;
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager)
        {
            mAnimationManager->runAnimationsForSequenceNamed("Default Timeline");
        }
        this->unschedule(schedule_selector(Scene18Layer::tick));
}