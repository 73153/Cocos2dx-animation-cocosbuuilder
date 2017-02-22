//
//  InfoCardNode.h
//  Noah360
//
//  Created by Neil D on 24/09/13.
//
//

#ifndef __Noah360__InfoCardNode__
#define __Noah360__InfoCardNode__
#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
class InfoCardNode: public cocos2d::CCNode
{
    InfoCardNode(void);
    virtual ~InfoCardNode(void);
   
    CCSprite* background;
    CC_SYNTHESIZE(CCSprite*, image, image);
    CC_SYNTHESIZE(CCSprite* ,prevGlow,prevGlow);
    CC_SYNTHESIZE(CCSprite* ,nextGlow,nextGlow);
    CCMenu* menuNext;
    CCMenu* menuPrev;
    CCMenuItem* next;
    CCMenuItem* prev;
    
    CCNode* groundingNode;
    
    int currentPage;
    int maxPage;
    void appearAnimation();
    void nextPressed();
    void prevPressed();
    void changePageAnimation();
    CCArray * pages;
    void Appear();
    bool  TestForTouch(CCPoint touchPoint);
    void Disapear();
    bool initInfoCardNode(CCArray *sprites, CCString* bg_image);
    static InfoCardNode* create(CCArray *sprites,CCString *bg_image);
};
#endif /* defined(__Noah360__SquatingNoah__) */
