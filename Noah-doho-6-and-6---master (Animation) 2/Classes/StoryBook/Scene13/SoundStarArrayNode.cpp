//
//  SoundStarArrayNode.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "SoundStarArrayNode.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
SoundStarArrayNode::SoundStarArrayNode():mAnimationManager(NULL)
{

  
}
SoundStarArrayNode::~SoundStarArrayNode()
{

}

bool SoundStarArrayNode::init()
{
    if (CCNode::init())
    {
        smallStars = CCSprite::createWithSpriteFrameName("LITTLE STARS_TEMPLATE.png");
        
        moon = SoundStarNode::create(CCString::create("MOON"), false);
        starA = SoundStarNode::create(CCString::create("A"), true);
        starB = SoundStarNode::create(CCString::create("B"), true);
        starC = SoundStarNode::create(CCString::create("C"), true);
        starD = SoundStarNode::create(CCString::create("D"), true);
        starE= SoundStarNode::create(CCString::create("E"), true);
        starF = SoundStarNode::create(CCString::create("F"), true);
        starG = SoundStarNode::create(CCString::create("G"), true);
        
        size=CCDirector::sharedDirector()->getWinSize();
        smallStars->setPosition(ccp(512,0));
        
        moon->setPosition(ccp(120*(size.width/1024),0));
        starA->setPosition(ccp(220*(size.width/1024) + 42*(size.width/1024), smallStars->getContentSize().height/2 - 126*(size.height/768)));
        starB->setPosition( ccp(220*(size.width/1024) + 121*(size.width/1024), smallStars->getContentSize().height/2 - 159*(size.height/768)));
        starC->setPosition(ccp(220*(size.width/1024) + 240*(size.width/1024), smallStars->getContentSize().height/2 - 117*(size.height/768)));
        starD->setPosition(ccp(220*(size.width/1024) + 323*(size.width/1024), smallStars->getContentSize().height/2 - 117*(size.height/768)));
        starE->setPosition(ccp(220*(size.width/1024) + 400*(size.width/1024), smallStars->getContentSize().height/2 - 72*(size.height/768)));
        starF->setPosition(ccp(220*(size.width/1024) + 539*(size.width/1024), smallStars->getContentSize().height/2 - 86*(size.height/768)));
        starG->setPosition(ccp(220*(size.width/1024) + 640*(size.width/1024), smallStars->getContentSize().height/2 - 86*(size.height/768)));
        
      this->addChild(smallStars,10);
                this->addChild(moon,10);
                this->addChild(starA,20);
                this->addChild(starB,20);
                this->addChild(starC,20);
                this->addChild(starD,20);
                this->addChild(starE,20);
                this->addChild(starF,20);
                this->addChild(starG,20);

        return true;
    }
    return false;
}

void SoundStarArrayNode::onEnter()
{

    CCNode::onEnter();
}
void SoundStarArrayNode::RestartStars()
{
    moon->setPosition(ccp(120*(size.width/1024),0));
    starA->setPosition(ccp(220*(size.width/1024) + 42*(size.width/1024), smallStars->getContentSize().height/2 - 126*(size.height/768)));
    starB->setPosition(ccp(220*(size.width/1024) + 121*(size.width/1024), smallStars->getContentSize().height/2 - 159*(size.height/768)));
    starC->setPosition(ccp(220*(size.width/1024)+ 240*(size.width/1024), smallStars->getContentSize().height/2 - 117*(size.height/768)));
    starD->setPosition(ccp(220*(size.width/1024) + 323*(size.width/1024), smallStars->getContentSize().height/2 - 117*(size.height/768)));
    starE->setPosition(ccp(220*(size.width/1024) + 400*(size.width/1024), smallStars->getContentSize().height/2 - 72*(size.height/768)));
    starF->setPosition(ccp(220*(size.width/1024) + 539*(size.width/1024), smallStars->getContentSize().height/2 - 86*(size.height/768)));
    starG->setPosition(ccp(220*(size.width/1024) + 640*(size.width/1024), smallStars->getContentSize().height/2 - 86*(size.height/768)));
}
void SoundStarArrayNode::testForTouchOnStar(CCPoint point)
{
    //point = ccpSub(point,ccp(0,this->getPositionY()));
    if (moon->TestForTouch(point)) return;
    if (starA->TestForTouch(point)) return;
    if (starB->TestForTouch(point)) return;
    if (starC->TestForTouch(point)) return;
    if (starD->TestForTouch(point)) return;
    if (starE->TestForTouch(point)) return;
    if (starF->TestForTouch(point)) return;
    if (starG->TestForTouch(point)) return;
}
void SoundStarArrayNode::MoveNode(SoundStarNode* node,CCPoint point)
{
    if (node->getisDrag())
    {
       //CRect r=CCRectMake(moon->getPositionX() - moon->getimageNormal()->getContentSize().width/2, moon->getPositionY() -  moon->getimageNormal()->getContentSize().height/2,  moon->getimageNormal()->getContentSize().width,  moon->getimageNormal()->getContentSize().height);
        if (node->boundingBox().intersectsRect(moon->boundingBox()))
        {
            return;
        }
        //        if(r.intersectsRect(CCRectMake(ccpAdd(point,node->getwhereTouch()).x -  node->getimageNormal()->getContentSize().width/2, ccpAdd(point,node->getwhereTouch()).y - node->getimageNormal()->getContentSize().height/2, node->getimageNormal()->getContentSize().width, node->getimageNormal()->getContentSize().height)))
        //        {
        //            return;
        //          }
        //node->setPosition(ccpAdd(point, node->getwhereTouch()));
        point=this->convertToNodeSpace(point);
        node->setPosition(point);
        if (node->getPositionY() <= -300*(size.height/768)) {
            node->setPosition(ccp(node->getPositionX(),-300*(size.height/768)));
        }
    }
}
void SoundStarArrayNode::touchMoved(CCPoint point)
{
        //point = ccpSub(point,ccp(0,this->getPositionY()));
        this->MoveNode(starA,point);
        this->MoveNode(starB,point);
        this->MoveNode(starC,point);
        this->MoveNode(starD,point);
        this->MoveNode(starE,point);
        this->MoveNode(starF,point);
        this->MoveNode(starG,point);
    
}
void SoundStarArrayNode::touchEnded()
{
      starA->touchEnded();
        starB->touchEnded();
        starC->touchEnded();
        starD->touchEnded();
        starE->touchEnded();
        starF->touchEnded();
        starG->touchEnded();
    
}