//
//  RainCloudNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "RainCloudNode.h"
#include "../../SoundManager/SoundManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
#define LightningOpacity 200
RainCloudNode::RainCloudNode():cloud1(NULL),cloud2(NULL),cloud3(NULL),cloud4(NULL),cloud1Working(false),cloud2Working(false),cloud3Working(false),cloud4Working(false),bigRainHasCome(false)
{
    waveSound = 0;
    rainDrops=CCArray::create();
    rainDrops->retain();
    //CCLog("Header Layer called");
}
RainCloudNode::~RainCloudNode()
{

}
void RainCloudNode::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleAllSelectors();
    this->stopAllActions();
    this->removeAllChildrenWithCleanup(true);
    CCNode::onExit();
}
void RainCloudNode::onEnter()
{
    CCNode::onEnter();
    winsize=CCDirector::sharedDirector()->getWinSize();
    platForm = CCApplication::sharedApplication()->getTargetPlatform();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    this->cloudsLoaded();
    waveSound = 0;
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void RainCloudNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("RainCloudNode::on loaded called");
}
SEL_CallFuncN RainCloudNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler RainCloudNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler RainCloudNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool RainCloudNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool RainCloudNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void RainCloudNode::ResetCloud4()
{
    cloud4->stopAllActions();
    cloud4L1->stopAllActions();
    cloud4L2->stopAllActions();
    cloud4L3->stopAllActions();
    cloud4Text->stopAllActions();
    cloud4->setPosition(CCPoint(791*(winsize.width/1024), (768-398)*winsize.height/768));
    //cloud4->setPosition(CCPoint(791, 768-392));
    cloud4->setOpacity(255);

	
    cloud4L1->setPosition(cloud4->getPosition());
    cloud4L1->setOpacity(0);

    cloud4L2->setPosition(cloud4->getPosition());
    cloud4L2->setOpacity(23);
    cloud4L3->setPosition(cloud4->getPosition());
    cloud4L3->setOpacity(0);
	cloud4Text->setPosition(ccp(cloud4->getPositionX()+4, cloud4->getPositionY()-27));
    cloud4Text->runAction(CCSpawn::create(CCScaleTo::create(0.3f, 0.90),CCFadeTo::create(0.4, 0),NULL));
	cloud4Working = false;
	bigRainHasCome = false;
	maxRainDrops = 400;
	float d = 2.0 + (((rand() % 20)*1.0)/10.0);
	float disX = 20.0 + ((rand() % 25)*1.0);
	float disY = 9.0 + ((rand() % 9)*1.0);
	ccBezierConfig bezierL;
	//bezier.startPosition = ccp(0,0);
	bezierL.controlPoint_1 = ccp(disX, 0);
	bezierL.controlPoint_2 = ccp(disX, disY);
	bezierL.endPosition = ccp(0,disY);
	ccBezierConfig bezier2L;
	//bezier2.startPosition = ccp(0,0);
	bezier2L.controlPoint_1 = ccp(-disX, 0);
	bezier2L.controlPoint_2 = ccp(-disX, -disY);
	bezier2L.endPosition = ccp(0,-disY);
   
    CCBezierBy *bezierForwardL=CCBezierBy::create(d, bezierL);
    CCBezierBy *bezierBackL=CCBezierBy::create(d, bezier2L);
    CCSequence *seq=CCSequence::create(bezierForwardL,bezierBackL,NULL);
    CCRepeatForever *rep=CCRepeatForever::create(seq);
    cloud4->runAction(rep);

	
	ccBezierConfig bezierM;
	//bezier.startPosition = ccp(0,0);
	bezierM.controlPoint_1 = ccp(disX, 0);
	bezierM.controlPoint_2 = ccp(disX, disY);
	bezierM.endPosition = ccp(0,disY);
	ccBezierConfig bezier2M;
	//bezier2.startPosition = ccp(0,0);
	bezier2M.controlPoint_1 = ccp(-disX, 0);
	bezier2M.controlPoint_2 = ccp(-disX, -disY);
	bezier2M.endPosition = ccp(0,-disY);
    
    CCBezierBy *bezierForwardM=CCBezierBy::create(d, bezierM);
    CCBezierBy *bezierBackM=CCBezierBy::create(d, bezier2M);
    CCSequence *seq2M=CCSequence::create(bezierForwardM,bezierBackM,NULL);
    CCRepeatForever *repM=CCRepeatForever::create(seq2M);
    cloud4L1->runAction(repM);

	
	ccBezierConfig bezierN;
	//bezier.startPosition = ccp(0,0);
	bezierN.controlPoint_1 = ccp(disX, 0);
	bezierN.controlPoint_2 = ccp(disX, disY);
	bezierN.endPosition = ccp(0,disY);
	ccBezierConfig bezier2N;
	//bezier2.startPosition = ccp(0,0);
	bezier2N.controlPoint_1 = ccp(-disX, 0);
	bezier2N.controlPoint_2 = ccp(-disX, -disY);
	bezier2N.endPosition = ccp(0,-disY);
    
    CCBezierBy *bezierForwardN=CCBezierBy::create(d, bezierN);
    CCBezierBy *bezierBackN=CCBezierBy::create(d, bezier2N);
    CCSequence *seq2N=CCSequence::create(bezierForwardN,bezierBackN,NULL);
    CCRepeatForever *repN=CCRepeatForever::create(seq2N);
    cloud4L2->runAction(repN);
    
		
	ccBezierConfig bezierO;
	//bezier.startPosition = ccp(0,0);
	bezierO.controlPoint_1 = ccp(disX, 0);
	bezierO.controlPoint_2 = ccp(disX, disY);
	bezierO.endPosition = ccp(0,disY);
	ccBezierConfig bezier2O;
	//bezier2.startPosition = ccp(0,0);
	bezier2O.controlPoint_1 = ccp(-disX, 0);
	bezier2O.controlPoint_2 = ccp(-disX, -disY);
	bezier2O.endPosition = ccp(0,-disY);
    
    CCBezierBy *bezierForwardO=CCBezierBy::create(d, bezierO);
    CCBezierBy *bezierBackO=CCBezierBy::create(d, bezier2O);
    CCSequence *seq2O=CCSequence::create(bezierForwardO,bezierBackO,NULL);
    CCRepeatForever *repO=CCRepeatForever::create(seq2O);
    cloud4L3->runAction(repO);
    
	
	
	
	ccBezierConfig bezierP;
	//bezier.startPosition = ccp(0,0);
	bezierP.controlPoint_1 = ccp(disX, 0);
	bezierP.controlPoint_2 = ccp(disX, disY);
	bezierP.endPosition = ccp(0,disY);
	ccBezierConfig bezierPA;
	//bezier2.startPosition = ccp(0,0);
	bezierPA.controlPoint_1 = ccp(-disX, 0);
	bezierPA.controlPoint_2 = ccp(-disX, -disY);
	bezierPA.endPosition = ccp(0,-disY);
    
    
    CCBezierBy *bezierForwardP=CCBezierBy::create(d, bezierP);
    CCBezierBy *bezierBackP=CCBezierBy::create(d, bezierPA);
    CCSequence *seq2P=CCSequence::create(bezierForwardP,bezierBackP,NULL);
    CCRepeatForever *repP=CCRepeatForever::create(seq2P);
    cloud4Text->runAction(repP);

	   
}
void RainCloudNode::cloudsLoaded()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene12.plist");
	sheet =CCSpriteBatchNode::create("Scene12.png",20);
    this->addChild(sheet,0,1);

    cloud1=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-1.png");
    cloud1->setPosition(ccp(156*(winsize.width/1024),(768-157)*winsize.height/768));
    sheet->cocos2d::CCNode::addChild(cloud1, 2);
    cloud1Text=CCSprite::createWithSpriteFrameName("Scene12/RAIN-1.png");
    cloud1Text->setPosition(ccp(cloud1->getPositionX()-2,cloud1->getPositionY()-12));
    cloud1Text->setScale(0.90);
    cloud1Text->setOpacity(0);
    sheet->addChild(cloud1Text, 6);
    
	float d = 2.0 + (((rand() % 20)*1.0)/10.0);
	
	float disX = 10.0 + ((rand() % 10)*1.0);
	float disY = 6.0 + ((rand() % 6)*1.0);
	
	ccBezierConfig bezier;
	//bezier.startPosition = ccp(0,0);
	bezier.controlPoint_1 = ccp(disX, 0);
	bezier.controlPoint_2 = ccp(disX, disY);
	bezier.endPosition = ccp(0,disY);
	ccBezierConfig bezier2;
	//bezier2.startPosition = ccp(0,0);
	bezier2.controlPoint_1 = ccp(-disX, 0);
	bezier2.controlPoint_2 = ccp(-disX, -disY);
	bezier2.endPosition = ccp(0,-disY);
    CCBezierBy *bezierForward=CCBezierBy::create(d, bezier);
    CCBezierBy *bezierBack=CCBezierBy::create(d, bezier2);
    CCSequence *seq2=CCSequence::create(bezierForward,bezierBack,NULL);
    CCRepeatForever *rep=CCRepeatForever::create(seq2);
	cloud1->runAction(rep);
    
	ccBezierConfig bezierA;
	//bezier.startPosition = ccp(0,0);
	bezierA.controlPoint_1 = ccp(disX, 0);
	bezierA.controlPoint_2 = ccp(disX, disY);
	bezierA.endPosition = ccp(0,disY);
	ccBezierConfig bezier2A;
	//bezier2.startPosition = ccp(0,0);
	bezier2A.controlPoint_1 = ccp(-disX, 0);
	bezier2A.controlPoint_2 = ccp(-disX, -disY);
	bezier2A.endPosition = ccp(0,-disY);
	CCBezierBy * bezierForwardA = CCBezierBy::create(d, bezierA);
	CCBezierBy * bezierBackA =  CCBezierBy::create(d, bezier2A);
	CCSequence *seq2A = CCSequence::create(bezierForwardA, bezierBackA,NULL);
	CCRepeatForever *repA = CCRepeatForever::create(seq2A);
	cloud1Text->runAction(repA);
	cloud1Working = false;
	
	
	cloud2= CCSprite::createWithSpriteFrameName("Scene12/CLOUD-2.png");
    cloud2->setPosition(ccp(309*(winsize.width/1024), (768-252)*winsize.height/768));
    sheet->addChild(cloud2, 2);
    
    
	cloud2L1= CCSprite::createWithSpriteFrameName("Scene12/CLOUD-2-LIGHTNING.png");
	cloud2L1->setPosition(cloud2->getPosition());
    cloud2L1->setOpacity(0);
    sheet->addChild(cloud2L1,3);
    
    
	cloud2L2=  CCSprite::createWithSpriteFrameName("Scene12/CLOUD-2-LIGHTNING-EXTREME.png");
	cloud2L2->setPosition(cloud2->getPosition());
	cloud2L2->setOpacity(23);
    sheet->addChild(cloud2L2,4);
    
    
	cloud2L3= CCSprite::createWithSpriteFrameName("Scene12/CLOUD-2-LIGHTNING-EXTREME.png");
    cloud2L3->setPosition(cloud2->getPosition());
	cloud2L3->setOpacity(0);
    sheet->addChild(cloud2L3,5);
	
	cloud2Text =CCSprite::createWithSpriteFrameName("Scene12/RAIN-2.png");
    cloud2Text->setPosition(ccp(cloud2->getPositionX()+4,cloud2->getPositionY()-22));
	cloud2Text->setOpacity(0);
    cloud2Text->setScale(0.90);
    sheet->addChild(cloud2Text,6);
	d = 2.0 + (((rand() % 20)*1.0)/10.0);
	
	disX = 15.0 + ((rand() % 15)*1.0);
	disY = 10.0 + ((rand() % 10)*1.0);
	
	ccBezierConfig bezierB;
	//bezier.startPosition = ccp(0,0);
	bezierB.controlPoint_1 = ccp(disX, 0);
	bezierB.controlPoint_2 = ccp(disX, disY);
	bezierB.endPosition = ccp(0,disY);
	ccBezierConfig bezier2B;
	//bezier2.startPosition = ccp(0,0);
	bezier2B.controlPoint_1 = ccp(-disX, 0);
	bezier2B.controlPoint_2 = ccp(-disX, -disY);
	bezier2B.endPosition = ccp(0,-disY);
	CCBezierBy *  bezierForwardB = CCBezierBy::create(d,bezierB);
	CCBezierBy * bezierBackB = CCBezierBy::create(d,bezier2B);
	CCSequence *  seq2B = CCSequence::create(bezierForwardB, bezierBackB,NULL);
	CCRepeatForever *repB = CCRepeatForever::create(seq2B);
    cloud2->runAction(repB);
    
	ccBezierConfig bezierD;
	//bezier.startPosition = ccp(0,0);
	bezierD.controlPoint_1 = ccp(disX, 0);
	bezierD.controlPoint_2 = ccp(disX, disY);
	bezierD.endPosition = ccp(0,disY);
	ccBezierConfig bezier2D;
	//bezier2.startPosition = ccp(0,0);
	bezier2D.controlPoint_1 = ccp(-disX, 0);
	bezier2D.controlPoint_2 = ccp(-disX, -disY);
	bezier2D.endPosition = ccp(0,-disY);
	CCBezierBy *   bezierForwardD =  CCBezierBy::create(d,bezierD);
	CCBezierBy *   bezierBackD = CCBezierBy::create(d,bezier2D);
	CCSequence *   seq2D =CCSequence::create(bezierForwardD, bezierBackD,NULL);
	CCRepeatForever *repD = CCRepeatForever::create(seq2D);
    cloud2L1->runAction(repD);
    
	ccBezierConfig bezierE;
	//bezier.startPosition = ccp(0,0);
	bezierE.controlPoint_1 = ccp(disX, 0);
	bezierE.controlPoint_2 = ccp(disX, disY);
	bezierE.endPosition = ccp(0,disY);
	ccBezierConfig bezier2E;
	//bezier2.startPosition = ccp(0,0);
	bezier2E.controlPoint_1 = ccp(-disX, 0);
	bezier2E.controlPoint_2 = ccp(-disX, -disY);
	bezier2E.endPosition = ccp(0,-disY);
	CCBezierBy *   bezierForwardE = CCBezierBy::create(d,bezierE);
	CCBezierBy *   bezierBackE =  CCBezierBy::create(d,bezier2E);
    CCSequence *seq2E = CCSequence::create(bezierForwardE, bezierBackE, NULL);
	CCRepeatForever *repE = CCRepeatForever::create(seq2E);
    cloud2L2->runAction(repE);
    
    
	ccBezierConfig bezierF;
	//bezier.startPosition = ccp(0,0);
	bezierF.controlPoint_1 = ccp(disX, 0);
	bezierF.controlPoint_2 = ccp(disX, disY);
	bezierF.endPosition = ccp(0,disY);
	ccBezierConfig bezier2F;
	//bezier2.startPosition = ccp(0,0);
	bezier2F.controlPoint_1 = ccp(-disX, 0);
	bezier2F.controlPoint_2 = ccp(-disX, -disY);
	bezier2F.endPosition = ccp(0,-disY);
	CCBezierBy * bezierForwardF = CCBezierBy::create(d,bezierF);
	CCBezierBy * bezierBackF = CCBezierBy::create(d,bezier2F);
    CCSequence * seq2F = CCSequence::create(bezierForwardF, bezierBackF,NULL);
    CCRepeatForever * repF = CCRepeatForever::create(seq2F);
	cloud2L3->runAction(repF);
	
	ccBezierConfig bezierC;
	//bezier.startPosition = ccp(0,0);
	bezierC.controlPoint_1 = ccp(disX, 0);
	bezierC.controlPoint_2 = ccp(disX, disY);
	bezierC.endPosition = ccp(0,disY);
	ccBezierConfig bezierCA;
	//bezier2.startPosition = ccp(0,0);
	bezierCA.controlPoint_1 = ccp(-disX, 0);
	bezierCA.controlPoint_2 = ccp(-disX, -disY);
	bezierCA.endPosition = ccp(0,-disY);
    CCBezierBy * bezierForwardC = CCBezierBy::create(d,bezierC);
	CCBezierBy * bezierBackC = CCBezierBy::create(d,bezierCA);
    CCSequence * seq2C = CCSequence::create(bezierForwardC, bezierBackC,NULL);
    CCRepeatForever * repC = CCRepeatForever::create(seq2C);
	cloud2Text->runAction(repC);
	
	cloud2Working =false;
    
	cloud3=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-3.png");
    
	cloud3->setPosition(ccp(517*(winsize.width/1024), (768-329)*(winsize.height/768)));
    sheet->cocos2d::CCNode::addChild(cloud3, 2);
	
	cloud3L1=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-3-LIGHTNING.png");
	cloud3L1->setPosition(cloud3->getPosition());
	cloud3L1->setOpacity(0);
    sheet->addChild(cloud3L1,3);
    
	
	cloud3L2=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-3-LIGHTNING-EXTREME.png");
	cloud3L2->setPosition(cloud3->getPosition());
	cloud3L2->setOpacity(23);
    sheet->addChild(cloud3L2,4);
    
	
	cloud3L3=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-3-LIGHTNING-EXTREME.png");
	cloud3L3->setPosition(cloud3->getPosition());
	cloud3L3->setOpacity(0);
	sheet->addChild(cloud3L3,5);
	
	cloud3Text=CCSprite::createWithSpriteFrameName("Scene12/RAIN-3.png");
	cloud3Text->setPosition(ccp(cloud3->getPositionX()+4,cloud3->getPositionY()));
	cloud3Text->setScale(0.90);
	cloud3Text->setOpacity(0);
    sheet->cocos2d::CCNode::addChild(cloud3Text,6);
    theFlood_ =TheFloodNode::create();
    this->addChild(theFlood_,40);
    d = 2.0 + (((rand() % 20)*1.0)/10.0);
	
	disX = 20.0 + ((rand() % 20)*1.0);
	disY = 10.0 + ((rand() % 10)*1.0);
	
	ccBezierConfig bezierG;
	//bezier.startPosition = ccp(0,0);
	bezierG.controlPoint_1 = ccp(disX, 0);
	bezierG.controlPoint_2 = ccp(disX, disY);
	bezierG.endPosition = ccp(0,disY);
	ccBezierConfig bezier2G;
	//bezier2.startPosition = ccp(0,0);
	bezier2G.controlPoint_1 = ccp(-disX, 0);
	bezier2G.controlPoint_2 = ccp(-disX, -disY);
	bezier2G.endPosition = ccp(0,-disY);
	CCBezierBy *bezierForwardG =CCBezierBy::create(d,bezierG);
	CCBezierBy * bezierBackG  =CCBezierBy::create(d,bezier2G);
	CCSequence *seq2G = CCSequence::create(bezierForwardG, bezierBackG,NULL);
	CCRepeatForever *repG =CCRepeatForever::create(seq2G);
	cloud3->runAction(repG);
	
	ccBezierConfig bezierH;
	//bezier.startPosition = ccp(0,0);
	bezierH.controlPoint_1 = ccp(disX, 0);
	bezierH.controlPoint_2 = ccp(disX, disY);
	bezierH.endPosition = ccp(0,disY);
	ccBezierConfig bezier2H;
	//bezier2.startPosition = ccp(0,0);
	bezier2H.controlPoint_1 = ccp(-disX, 0);
	bezier2H.controlPoint_2 = ccp(-disX, -disY);
	bezier2H.endPosition = ccp(0,-disY);
	CCBezierBy * bezierForwardH = CCBezierBy::create(d,bezierH);
    CCBezierBy * bezierBackH = CCBezierBy::create(d,bezier2H);
    CCSequence * seq2H = CCSequence::create(bezierForwardH, bezierBackH, NULL);
    CCRepeatForever * repH = CCRepeatForever::create(seq2H);
	cloud3L1->runAction(repH);
	
	ccBezierConfig bezierI;
	//bezier.startPosition = ccp(0,0);
	bezierI.controlPoint_1 = ccp(disX, 0);
	bezierI.controlPoint_2 = ccp(disX, disY);
	bezierI.endPosition = ccp(0,disY);
	ccBezierConfig bezier2I;
	//bezier2.startPosition = ccp(0,0);
	bezier2I.controlPoint_1 = ccp(-disX, 0);
	bezier2I.controlPoint_2 = ccp(-disX, -disY);
	bezier2I.endPosition = ccp(0,-disY);
    CCBezierBy * bezierForwardI = CCBezierBy::create(d,bezierI);
    CCBezierBy * bezierBackI = CCBezierBy::create(d,bezier2I);
    CCSequence * seq2I = CCSequence::create(bezierForwardI, bezierBackI,NULL);
    CCRepeatForever * repI = CCRepeatForever::create(seq2I);
	cloud3L2->runAction(repI);
	
	ccBezierConfig bezierJ;
	//bezier.startPosition = ccp(0,0);
	bezierJ.controlPoint_1 = ccp(disX, 0);
	bezierJ.controlPoint_2 = ccp(disX, disY);
	bezierJ.endPosition = ccp(0,disY);
	ccBezierConfig bezier2J;
	//bezier2.startPosition = ccp(0,0);
	bezier2J.controlPoint_1 = ccp(-disX, 0);
	bezier2J.controlPoint_2 = ccp(-disX, -disY);
	bezier2J.endPosition = ccp(0,-disY);
	CCBezierBy *bezierForwardJ = CCBezierBy::create(d,bezierJ);
	CCBezierBy *bezierBackJ =CCBezierBy::create(d,bezier2J);
	CCSequence *seq2J = CCSequence::create(bezierForwardJ, bezierBackJ,NULL);
	CCRepeatForever *repJ =CCRepeatForever::create(seq2J);
    cloud3L3->runAction(repJ);
    
	
	ccBezierConfig bezierK;
	//bezier.startPosition = ccp(0,0);
	bezierK.controlPoint_1 = ccp(disX, 0);
	bezierK.controlPoint_2 = ccp(disX, disY);
	bezierK.endPosition = ccp(0,disY);
	ccBezierConfig bezierKA;
	//bezier2.startPosition = ccp(0,0);
	bezierKA.controlPoint_1 = ccp(-disX, 0);
	bezierKA.controlPoint_2 = ccp(-disX, -disY);
	bezierKA.endPosition = ccp(0,-disY);
	CCBezierBy *bezierForwardK = CCBezierBy::create(d,bezierK);
	CCBezierBy *bezierBackK = CCBezierBy::create(d,bezierKA);
	CCSequence *seq2K = CCSequence::create(bezierForwardK, bezierBackK, NULL);
    CCRepeatForever *repK=CCRepeatForever::create(seq2K);
    cloud3Text->runAction(repK);
	cloud3Working = false;
	
	
	
	cloud4 =CCSprite::createWithSpriteFrameName("Scene12/CLOUD-4.png");
	sheet->addChild(cloud4,2);
    
	
	cloud4L1=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-4-LIGHTNING.png");
	sheet->addChild(cloud4L1,3);
	
	cloud4L2=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-4-LIGHTNING-EXTREME.png");
	sheet->addChild(cloud4L2,4);
	
	cloud4L3=CCSprite::createWithSpriteFrameName("Scene12/CLOUD-4-LIGHTNING-EXTREME.png");
    sheet->addChild(cloud4L3,5);
	
	cloud4Text =CCSprite::createWithSpriteFrameName("Scene12/RAIN-4.png");
    sheet->addChild(cloud4Text,6);
	cloud4Text->setOpacity(0);
   
    this->ResetCloud4();
    
    CCLog("complete loading four clouds");
    
}
void RainCloudNode::ResetRainDrops()
{
    CCObject *drop=NULL;
    CCARRAY_FOREACH(rainDrops, drop)
    {
        RainDrop *_drop=(RainDrop*)drop;
        sheet->removeChild(_drop,true);
    }
    rainDrops->removeAllObjects();
    
}
void RainCloudNode::HandleTouch(CCPoint point)
{
    if (!cloud1Working
        && (point.x > cloud1->getPositionX()-cloud1->getContentSize().width/2)
        && (point.x < cloud1->getPositionX()+cloud1->getContentSize().width/2)
        && (point.y > cloud1->getPositionY()-cloud1->getContentSize().height/2)
        && (point.y < cloud1->getPositionY()+cloud1->getContentSize().height/2))
    {

        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/Cloud 1_raindrop with reverb.mp3", false);
        //cloud1Working = YES;
        
        int numRainDropsFound = 0;
        for (int i=0; i < rainDrops->count(); i++)
        {
            RainDrop *aRainDrop = (RainDrop*)rainDrops->objectAtIndex(i);
            if (aRainDrop->getbelongsToCloud()== 1 && aRainDrop->getPositionY() < 0)
            {
                
                numRainDropsFound++;
                aRainDrop->setPosition(cloud1->getPosition());
                aRainDrop->setScaleY(1.0f);
                aRainDrop->setScaleX(1.0f);
                aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.0f, ccp(0,-winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.0, 0.369f, 1.54f)),NULL));
            }
        }
        if (numRainDropsFound < 1)
        {
            for (int i=0; i < 1; i++)
            {
                RainDrop *aRainDrop=RainDrop::RainDropWithimagename(CCString::create("Scene12/RAINDROP-2.png"));
                aRainDrop->setPosition(cloud1->getPosition());
                aRainDrop->setbelongsToCloud(1);
                sheet->addChild(aRainDrop,1);
                rainDrops->addObject(aRainDrop);
                aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.0, ccp(0, -winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.0, 0.369f,1.54f)),NULL));
            }
        }
        cloud1Text->stopActionByTag(1);
        CCSpawn *action = CCSpawn::create(CCEaseSineIn::create(CCFadeTo::create(0.3f, 255)),CCEaseSineIn::create(CCScaleTo::create(1.17f, 1.11)),NULL);
        action->setTag(1);
        cloud1Text->runAction(action);
        this->schedule(schedule_selector(RainCloudNode::wrapCloud1),0.48f);
    }
    else if (!cloud2Working
             && point.x > cloud2->getPositionX()-cloud2->getContentSize().width/2
             && point.x < cloud2->getPositionX()+cloud2->getContentSize().width/2
             &&point.y > cloud2->getPositionX()-cloud2->getContentSize().height/2
             && point.y < cloud2->getPositionY()+cloud2->getContentSize().height/2)
    {
        
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/Cloud 2_multiple drops no pitch drop with reverb.mp3", false);
        //cloud2Working = YES;
        cloud2L1->setOpacity(237);
        this->schedule(schedule_selector(RainCloudNode::wrapCloud2A),0.03f);
    }
    else if (!cloud3Working
             && point.x > cloud3->getPositionX()-cloud3->getContentSize().width/2
             && point.x < cloud3->getPositionX()+cloud3->getContentSize().width/2
             && point.y > cloud3->getPositionY()-cloud3->getContentSize().height/2
             && point.y < cloud3->getPositionY()+cloud3->getContentSize().height/2)
    {

        SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/Cloud 2_multiple drops no pitch drop with reverb.mp3", false);
        //cloud3Working = YES;
        
        cloud3L1->setOpacity(237);
        this->schedule(schedule_selector(RainCloudNode::wrapCloud3A), 0.03f);
    }   
    else if (point.x > cloud4->getPositionX()-cloud4->getContentSize().width/2 && point.x < cloud4->getPositionX()+cloud4->getContentSize().width/2 &&
             point.y > cloud4->getPositionY()-cloud4->getContentSize().height/2 && point.y < cloud4->getPositionY()+cloud4->getContentSize().height/2)
    {
   
        if (cloud4Working)
        {
            this->unscheduleAllSelectors();
            this->ResetCloud4();
            theFlood_->stopAllActions();
            this->schedule(schedule_selector(RainCloudNode::theUnFlood));
        }
        else
        {
           this->ResetRainDrops();
            cloud4Working = true;
            cloud4L1->setOpacity(237);
            this->schedule(schedule_selector(RainCloudNode::wrapCloud4A),0.03f);
        }
        
    }
}
void RainCloudNode::wrapCloud1(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud1));
    cloud1Text->stopActionByTag(1);
    CCFadeTo *act_fade=CCFadeTo::create(0.51f, 0);
    act_fade->setTag(1);
    cloud1Text->runAction(CCEaseSineIn::create(act_fade));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud2),0.71f);
}
void RainCloudNode::wrapCloud2(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud2));
    cloud1Text->setScale(0.90f);
    cloud1Working = false;
}
void RainCloudNode::wrapCloud2A(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud2A));
	cloud2Text->stopActionByTag(2);
    
	CCSpawn *action = CCSpawn::create(CCEaseSineIn::create(CCFadeTo::create(0.3f, 255)),CCEaseSineIn::create(CCScaleTo::create(1.17f, 1.11)),NULL);
    action->setTag(2);
    cloud2Text->runAction(action);
   
    cloud2L1->runAction(CCEaseSineIn::create(CCFadeTo::create(0.33f,0)));
	this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
    cloud2L2->setOpacity(LightningOpacity);
	cloud2L2->runAction(CCEaseSineIn::create(CCFadeTo::create(0.60f, 0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud2B),0.22f);
}
void RainCloudNode::wrapCloud2B(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud2B));
    int numRainDropsFound = 0;
	for (int i=0; i < rainDrops->count(); i++)
    {
		RainDrop *aRainDrop = (RainDrop*)rainDrops->objectAtIndex(i);
		
		if (aRainDrop->getbelongsToCloud()== 2 && aRainDrop->getPositionY() < 0 &&numRainDropsFound<3) {
			
			numRainDropsFound++;
			aRainDrop->stopAllActions();
			
			int diffX = (rand() % 60) - 30;
			int diffY = (rand() % 40) - 20;
			float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
			aRainDrop->setPosition(ccp(cloud2->getPositionX()+diffX, cloud2->getPositionY()+diffY));
            aRainDrop->setScaleX(1.0f);
            aRainDrop->setScaleY(1.0f);
            aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0, -winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5f+diffT, 0.369, 1.54f)),NULL));
		}
	}
	if (numRainDropsFound < 3)
    {
            for (int i=0; i < 3 - numRainDropsFound ; i++)
            {
                RainDrop *aRainDrop=RainDrop::RainDropWithimagename(CCString::create("Scene12/RAINDROP-2.png"));
                aRainDrop->setbelongsToCloud(2);
                sheet->addChild(aRainDrop,1);
                rainDrops->addObject(aRainDrop);
                int diffX = (rand() % 60) - 30;
                int diffY = (rand() % 40) - 20;
                float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
                aRainDrop->setPosition(ccp(cloud2->getPositionX()+diffX, cloud2->getPositionY()+diffY));
                aRainDrop->setScaleX(1.0f);
                aRainDrop->setScaleY(1.0f);
                
                aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0,-winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5+diffT, 0.369f, 1.54)),NULL));
                
            }
       
	}
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
	cloud2L3->setOpacity(LightningOpacity);
    cloud2L3->runAction(CCEaseSineIn::create(CCFadeTo::create(0.68f, 0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud21), 0.48);

}
void RainCloudNode::wrapCloud21(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud21));
	cloud2Text->stopActionByTag(2);
	CCFadeTo *action = CCFadeTo::create(0.51f, 0);
    action->setTag(2);
    cloud2Text->runAction(CCEaseSineIn::create(action));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud22),0.71f);
}
void RainCloudNode::wrapCloud22(float dt)
{
    
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud22));
	cloud2Text->setScale(0.90f);
	cloud2Working = false;
}
void RainCloudNode::wrapCloud3A(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud3A));
	cloud3Text->stopActionByTag(3);
    CCSpawn *action=CCSpawn::create(CCEaseSineIn::create(CCFadeTo::create(0.3f, 255)),CCEaseSineIn::create(CCScaleTo::create(1.17f, 1.11)),NULL);
	action->setTag(3);
	cloud3Text->runAction(action);
    cloud3L1->runAction(CCEaseSineIn::create(CCFadeTo::create(0.33, 0)));
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
    
	cloud3L2->setOpacity(LightningOpacity);
	cloud3L2->runAction(CCEaseSineIn::create(CCFadeTo::create(0.60f, 0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud3B),0.22f);
    
}
void RainCloudNode::wrapCloud3B (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud3B));
    int numRainDropsFound = 0;
	for (int i=0; i < rainDrops->count(); i++)
    {
		RainDrop *aRainDrop = (RainDrop*)rainDrops->objectAtIndex(i);
		if (aRainDrop->getbelongsToCloud()== 3 && aRainDrop->getPositionY() < 0 &&numRainDropsFound<9)
        {
			numRainDropsFound++;
			aRainDrop->stopAllActions();
			int diffX = (rand() % 170) - 85;
			int diffY = (rand() % 60) - 70;
			float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
			aRainDrop->setPosition(ccp(cloud3->getPositionX()+diffX, cloud3->getPositionY()+diffY));
            aRainDrop->setScaleX(1.0f);
            aRainDrop->setScaleY(1.0f);
            aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0, -winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5f+diffT, 0.369, 1.54f)),NULL));
		}
	}
	if (numRainDropsFound < 9)
    {
        for (int i=0; i < 9 - numRainDropsFound ; i++)
        {
                RainDrop *aRainDrop=RainDrop::RainDropWithimagename(CCString::create("Scene12/RAINDROP-2.png"));
                aRainDrop->setbelongsToCloud(3);
                sheet->addChild(aRainDrop,1);
                rainDrops->addObject(aRainDrop);
                
                
                int diffX = (rand() % 170) - 85;
                int diffY = (rand() % 60) - 70;
                float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
                aRainDrop->setPosition(ccp(cloud3->getPositionX()+diffX, cloud3->getPositionY()+diffY));
                aRainDrop->setScaleX(1.0f);
                aRainDrop->setScaleY(1.0f);
                
                aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0,-winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5+diffT, 0.369f, 1.54)),NULL));
                
            }
    }
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
	cloud3L3->setOpacity(LightningOpacity);
    cloud3L3->runAction(CCEaseSineIn::create(CCFadeTo::create(0.68f, 0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud31), 0.48);
}
void RainCloudNode::wrapCloud31 (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud31));
    cloud3Text->stopActionByTag(3);
	CCFadeTo *action = CCFadeTo::create(0.51, 0);
    action->setTag(3);
    cloud3Text->runAction(CCEaseSineIn::create(action));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud32),0.71f);
}
void RainCloudNode::wrapCloud32 (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud32));
    cloud3Text->setScale(0.90f);
	cloud3Working = false;
}
void RainCloudNode::wrapCloud4A (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud4A));
    cloud4Text->stopActionByTag(4);
    CCSpawn *action=CCSpawn::create(CCEaseSineIn::create(CCFadeTo::create(0.1f, 255)),CCEaseSineIn::create(CCScaleTo::create(5.0, 1.6f)),NULL);
	action->setTag(4);
	cloud4Text->runAction(action);
    cloud4L1->runAction(CCEaseSineIn::create(CCFadeTo::create(0.33, 0)));
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
    
	cloud4L2->setOpacity(LightningOpacity);
	cloud4L2->runAction(CCEaseSineIn::create(CCFadeTo::create(0.60f, 0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud4B),0.22f);
}
void RainCloudNode::wrapCloud4B (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud4B));
    this->schedule(schedule_selector(RainCloudNode::theLittleRain),0.01f);
    
    this->schedule(schedule_selector(RainCloudNode::thunder),0.00f);
	cloud4L3->setOpacity(LightningOpacity);
	cloud4L3->runAction(CCEaseSineIn::create(CCFadeTo::create(0.68,0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud4B2),0.1f);
    this->schedule(schedule_selector(RainCloudNode::wrapCloud41),0.48f);
}
void RainCloudNode::wrapCloud4B2 (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud4B2));
	if (!bigRainHasCome)
    {
		bigRainHasCome = true;
        if(platForm==kTargetIphone || platForm==kTargetIpad)
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/wind.caf",false);
        }
        else
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/wind.ogg",false);
        }
        this->schedule(schedule_selector(RainCloudNode::theBigRain),0.01f);
	}
    this->schedule(schedule_selector(RainCloudNode::theFlood),3.4f);

}
void RainCloudNode::thunder(float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::thunder));
	if (rand() % 4 == 0)
    {
        CCLog("ogg two");
        if(platForm==kTargetIphone || platForm==kTargetIpad)
        {
            if (rand() % 2 == 0)
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/thunder1.caf",false);
            }
            else
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/thunder2.caf",false);
            }
        }
        else
        {
            if (rand() % 2 == 0)
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/thunder1.ogg",false);
            }
            else
            {
                SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/thunder2.ogg",false);
            }
        }
	
	}
}
void RainCloudNode::theLittleRain (float dt)
{
    int numRainDropsFound = 0;
	for (int i=0; i < rainDrops->count(); i++)
    {
		RainDrop *aRainDrop = (RainDrop*)rainDrops->objectAtIndex(i);
		int numRainDropsFound = 0;
		if (aRainDrop->getbelongsToCloud()== 4 && aRainDrop->getPositionY() < 0 && i < 40 && rand() % 8 != 0)
        {
			numRainDropsFound++;
			aRainDrop->stopAllActions();
			int diffX = (rand() % 250) - 125;
			int diffY = (rand() % 80) - 100;
			float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
			aRainDrop->setPosition(ccp(cloud4->getPositionX()+diffX, cloud4->getPositionY()+diffY));
            aRainDrop->setScaleX(1.0f);
            aRainDrop->setScaleY(1.0f);
            aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0, -winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5f+diffT, 0.369, 1.54f)),NULL));
		}
	}
	if (numRainDropsFound < 20)
    {
        if (rainDrops->count() <= maxRainDrops)
        {
            for (int i=0; i < 20 - numRainDropsFound && rand() % 4 != 0; i++)
            {
             
                RainDrop *aRainDrop=RainDrop::RainDropWithimagename(CCString::create("Scene12/RAINDROP-2.png"));
                
                aRainDrop->setbelongsToCloud(4);
                sheet->addChild(aRainDrop,1);
                rainDrops->addObject(aRainDrop);
                
                
                int diffX = (rand() % 250) - 125;
                int diffY = (rand() % 80) - 100;
                float diffT = ((((rand() % 40) * 1.0) / 100.0) - 0.2);
                aRainDrop->setPosition(ccp(cloud4->getPositionX()+diffX, cloud4->getPositionY()+diffY));
                aRainDrop->setScaleX(1.0f);
                aRainDrop->setScaleY(1.0f);
                
                aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.4+diffT, ccp(0,-winsize.height))),CCEaseSineIn::create(CCScaleTo::create(1.5+diffT, 0.369f, 1.54)),NULL));
                
            }
        }
	}
}
void RainCloudNode::wrapCloud41 (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud41));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud42),0.71f);
}
void RainCloudNode::wrapCloud42 (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud42));
	cloud4L1->runAction(CCEaseSineIn::create(CCFadeTo::create(0.33f, 0)));
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
	cloud4L2->setOpacity(LightningOpacity);
	cloud4L2->runAction(CCEaseSineIn::create(CCFadeTo::create(0.60,0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud4C),0.22f);
}
void RainCloudNode::wrapCloud4C (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::wrapCloud4C));
    this->schedule(schedule_selector(RainCloudNode::thunder),0.0f);
	cloud4L3->setOpacity(LightningOpacity);
    cloud4L3->runAction(CCEaseSineIn::create(CCFadeTo::create(0.68f,0)));
    this->schedule(schedule_selector(RainCloudNode::wrapCloud41),.1+(((rand() % 38)*1.0)/100.0));
}
void RainCloudNode::theFlood (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::theFlood));
    waveSound = SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 12/WATER RISING.mp3",false);
    theFlood_->runAction(CCMoveTo::create(3.6, ccp(0.0f, 1320.0f*(winsize.height/768))));
}
void RainCloudNode::theUnFlood (float dt)
{
    this->unschedule(schedule_selector(RainCloudNode::theUnFlood));
    SoundManager::sharedSoundManager()->stopSoundEffect(waveSound);
   theFlood_->runAction(CCMoveTo::create(3.6,ccp(1600,0)));
}
void RainCloudNode::StartBigFlood()
{
    theFlood_->runAction(CCMoveTo::create(1.2f,ccp(0.05,1600*(winsize.height/768))));
}
void RainCloudNode::theBigRain (float dt)
{
    for (int i=0; i < rainDrops->count(); i++)
    {
		RainDrop *aRainDrop = (RainDrop*)rainDrops->objectAtIndex(i);
		if (aRainDrop->getPositionY()< 0)
        {
		
			aRainDrop->stopAllActions();
            aRainDrop->setPosition(ccp(rand() % (int)winsize.width, winsize.height+40));
            aRainDrop->setScaleX(1.0f);
            aRainDrop->setScaleY(1.0f);
			float diffT =rand()%40;//((((rand() % 120) * 1.0) / 120) - 0.6);
			aRainDrop->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.2+diffT, CCPoint(0, -880*(winsize.height)))),CCEaseSineIn::create(CCScaleTo::create(1.2+diffT, 0.369f, 1.54f)),NULL));
		}
	}
    if (rainDrops ->count() < maxRainDrops && rand() % 8 != 0)
    {
        for (int i=0;  i < maxRainDrops ; i++)
        {
            RainDrop *aRainDrop5=RainDrop::RainDropWithimagename(CCString::create("Scene12/RAINDROP-2.png"));
            CCSize s=CCDirector::sharedDirector()->getWinSize();
            int k=(int)s.width;
            aRainDrop5->setPosition(ccp(rand()%k,k+rand() % 200));
            aRainDrop5->setbelongsToCloud(-1);
            sheet->addChild(aRainDrop5, 6);
            rainDrops->addObject(aRainDrop5);
            float diffT = rand()%40;
            //((((rand() % 120) * 1.0) / 120) - 0.6);
            //((((rand() % 120) * 1.0) / 100.0) - 0.6);
            aRainDrop5->runAction(CCSpawn::create(CCEaseSineIn::create(CCMoveBy::create(1.2+diffT, ccp(0,-970*(winsize.height)))),CCEaseSineIn::create(CCScaleTo::create(1.2+diffT,0.369f,1.54f)),NULL));
        }
    }
}
void RainCloudNode::EndAllSchedulers()
{
    this->unscheduleAllSelectors();
}
bool RainCloudNode::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCPoint touchPoint =touch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    this->HandleTouch(touchPoint);
    return false;
}