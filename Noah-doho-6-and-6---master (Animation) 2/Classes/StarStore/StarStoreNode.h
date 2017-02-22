//
//  HelloCocosBuilderLayer.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//

#ifndef __Demo__StarStoreNode__
#define __Demo__StarStoreNode__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
class StarStoreNode: public cocos2d::CCNode
{
    public:
    StarStoreNode();
    virtual ~StarStoreNode();
    virtual void onEnter();
    virtual void onExit();
    CCSprite* background;
    CCSprite* image;
    CCSprite* sceneImage;
    CCSprite* star;
    CCSprite* locked;
    
    CCLabelTTF* title;
    CCLabelTTF* description;
    CCLabelTTF* price;
    CCLabelTTF* levelRequired;
    
    CCMenu* menu;
    CCMenuItemSprite* button;
    int state;
    int myIndex;
    int groupId;
    int exclusiveGroupId;
    int priceValue;
    bool showingAlertViewToShop;
    CC_SYNTHESIZE_RETAIN(CCObject *, parent, parent);
    SEL_CallFuncO   selected;
    bool initStarStoreNode(int index1,CCObject *obj,SEL_CallFuncO selector);
    static StarStoreNode* create(int index1,CCObject *obj,SEL_CallFuncO selector);
    void buttonPressed(CCObject *obj);
    void Unselect();
    void TestForBuy();
};
#endif /* defined(__Demo__HelloCocosBuilderLayer__) */
