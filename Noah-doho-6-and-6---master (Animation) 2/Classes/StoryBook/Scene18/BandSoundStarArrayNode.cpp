//
//  BandSoundStarArrayNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "BandSoundStarArrayNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

BandSoundStarArrayNode::BandSoundStarArrayNode():mAnimationManager(NULL)
{

  
}
BandSoundStarArrayNode::~BandSoundStarArrayNode()
{

}
void BandSoundStarArrayNode::onEnter()
{
    
    moon =BandSoundStarsNode::create(CCString::create("MOON"),false);
    starA =BandSoundStarsNode::create(CCString::create("A"),true);
    starB=BandSoundStarsNode::create(CCString::create("B"),true);
    starC=BandSoundStarsNode::create(CCString::create("C"),true);
    starD=BandSoundStarsNode::create(CCString::create("D"),true);
    starE=BandSoundStarsNode::create(CCString::create("E"),true);
    starF=BandSoundStarsNode::create(CCString::create("F"),true);
    starG=BandSoundStarsNode::create(CCString::create("G"),true);
    size=CCDirector::sharedDirector()->getWinSize();
    
    moon->setPosition(ccp(200*(size.width/1024),(768 - 71)*(size.height/768)));
    starA->setPosition(ccp(325*(size.width/1024), (768 - 44)*(size.height/768)));
    starB->setPosition(ccp(386*(size.width/1024), (768 - 60)*(size.height/768)));
    starC->setPosition(ccp(488*(size.width/1024), (768 - 48)*(size.height/768)));
    starD->setPosition(ccp(596*(size.width/1024), (768- 61)*(size.height/768)));
    starE->setPosition(ccp(662*(size.width/1024), (768 - 81)*(size.height/768)));
    starF->setPosition(ccp(741*(size.width/1024), (768 - 75)*(size.height/768)));
    starG->setPosition(ccp(815*(size.width/1024), (768 - 59)*(size.height/768)));
    
    this->addChild(moon,10);
    
        this->addChild(starA, 20);
        this->addChild(starB ,20);
        this->addChild(starC ,20);
        this->addChild(starD ,20);
        this->addChild(starE ,20);
        this->addChild(starF ,20);
        this->addChild(starG ,20);
    CCNode::onEnter();
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void BandSoundStarArrayNode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN BandSoundStarArrayNode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler BandSoundStarArrayNode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
SEL_CCControlHandler BandSoundStarArrayNode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool BandSoundStarArrayNode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool BandSoundStarArrayNode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void BandSoundStarArrayNode::RestartStars()
{
    moon->setPosition(ccp(200*(size.width/1024),(768 - 71)*(size.height/768)));
    starA->setPosition( ccp(325*(size.width/1024),( 768 - 44)*(size.height/768)));
    starB->setPosition(ccp(386*(size.width/1024), (768 - 60)*(size.height/768)));
    starC->setPosition(ccp(488*(size.width/1024), (768 - 48)*(size.height/768)));
    starD->setPosition(ccp(596*(size.width/1024), (768- 61)*(size.height/768)));
    starE->setPosition(ccp(662*(size.width/1024), (768 - 81)*(size.height/768)));
    starF->setPosition(ccp(741*(size.width/1024), (768 - 75)*(size.height/768)));
    starG->setPosition(ccp(815*(size.width/1024), (768 - 59)*(size.height/768)));
}
void BandSoundStarArrayNode::testForTouchOnStar(CCPoint point)
{
    //point = ccpSub(point,ccp(0,this->getPositionY()));
    if (moon->TestForTouch(point)) return;
    if (starA->TestForTouch(point)) return;
    if (starB ->TestForTouch(point)) return;
    if (starC ->TestForTouch(point)) return;
    if (starD->TestForTouch(point)) return;
    if (starE->TestForTouch(point)) return;
    if (starF->TestForTouch(point)) return;
    if (starG->TestForTouch(point)) return;
}
void BandSoundStarArrayNode::MoveNode(BandSoundStarsNode* node,CCPoint point)
{
//    CCRect r1=CCRectMake(moon->getPositionX()-moon->getimageNormal()->getContentSize().width/2, moon->getPositionY(), moon->getimageNormal()->getContentSize().width, moon->getimageNormal()->getContentSize().height);
    
 //   CCRect r2=CCRectMake(moon->getPositionX()-moon->getimageNormal()->getContentSize().width/2, moon->getPositionY(), moon->getimageNormal()->getContentSize().width, moon->getimageNormal()->getContentSize().height);
//    ccpAdd(point,node.whereTouch).x -  node.imageNormal.contentSize.width/2, ccpAdd(point,node.whereTouch).y - node.imageNormal.contentSize.height/2, node.imageNormal.contentSize.width, node.imageNormal.contentSize.height)
//
//    CCRect intersection;
//    intersection = CCRectMake(std::max(CCRect::CCRectGetMinX(r1),CCRect::CCRectGetMinX(r2)), std::max(CCRect::CCRectGetMinY(r1),CCRect::CCRectGetMinY(r2)),0,0);
//    intersection.size.width = std::min(CCRect::CCRectGetMaxX(r1), CCRect::CCRectGetMaxX(r2)) - CCRect::CCRectGetMinX(intersection);
//    intersection.size.height = std::min(CCRect::CCRectGetMaxY(r1), CCRect::CCRectGetMaxY(r2)) - CCRect::CCRectGetMinY(intersection);
//    if (node.isDrag) {
//        
//        if(CGRectIntersectsRect(
//                                CGRectMake(moon.position.x - moon.imageNormal.contentSize.width/2, moon.position.y -  moon.imageNormal.contentSize.height/2,  moon.imageNormal.contentSize.width,  moon.imageNormal.contentSize.height),
//                                CGRectMake(ccpAdd(point,node.whereTouch).x -  node.imageNormal.contentSize.width/2, ccpAdd(point,node.whereTouch).y - node.imageNormal.contentSize.height/2, node.imageNormal.contentSize.width, node.imageNormal.contentSize.height)))
//        {
//            return;
//        }
//        node.position = ccpAdd(point,node.whereTouch);
//        if (node.position.y <= -300) {
//            node.position = ccp(node.position.x,-300);
//        }
//    }
}
void BandSoundStarArrayNode::touchMoved(CCPoint point)
{
        point = ccpSub(point,ccp(0,this->getPositionY()));
        this->MoveNode(starA, point);
        this->MoveNode(starB, point);
        this->MoveNode(starC, point);
        this->MoveNode(starD, point);
        this->MoveNode(starE, point);
    this->MoveNode(starF, point);
    this->MoveNode(starG, point);
}
void BandSoundStarArrayNode::touchEnded()
{
    
    starA->touchEnded();
    starB->touchEnded();
    starC->touchEnded();
    starD->touchEnded();
    starE->touchEnded();
    starF->touchEnded();
    starG->touchEnded();
}

