//
//  StarStoreNode.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "StarStoreNode.h"
#include "../HomeScreen/homeLayerLoader.h"
#include "../GameManager/GameManager.h"
#include "../SoundManager/SoundManager.h"
#include "../CCAlertView/CCAlertView.h"
USING_NS_CC;
USING_NS_CC_EXT;
StarStoreNode::StarStoreNode()
{
    CCLog("constructor called");
}
StarStoreNode::~StarStoreNode()
{
    CCLog("destracture called");
}
void StarStoreNode::onExit()
{
    CCNode::onExit();
}
void StarStoreNode::onEnter()
{
    CCNode::onEnter();
}
StarStoreNode* StarStoreNode::create(int index1,CCObject *obj,SEL_CallFuncO selector)
{
    StarStoreNode* ret = new StarStoreNode();
    if (ret)
    {
        if (ret->initStarStoreNode(index1,obj,selector))
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
bool StarStoreNode::initStarStoreNode(int index1,CCObject *obj,SEL_CallFuncO selector)
{
    
    if (StarStoreNode::init())
    {
        myIndex = index1;
        parent=obj;
        selected=selector;
        CCDictionary *dict=(CCDictionary*)GameManager::sharedGameManager()->getstarStoreElements()->objectAtIndex(index1);
        state=dict->valueForKey("status")->intValue();
        exclusiveGroupId =dict->valueForKey("exclusiveGroupId")->intValue();
        background=CCSprite::createWithSpriteFrameName("ROW-CEL_0001.png");
        star=CCSprite::createWithSpriteFrameName("STAR.png");
        locked=CCSprite::createWithSpriteFrameName("LOCK.png");
        image=CCSprite::createWithSpriteFrameName(dict->valueForKey("imageName")->getCString());
        sceneImage=CCSprite::createWithSpriteFrameName(dict->valueForKey("sceneName")->getCString());
        background->setPosition(ccp( 50*(screen_width/1024) + background->getContentSize().width/2, background->getContentSize().height/2-15));
        
        image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),64*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()));
        sceneImage->setPosition(ccp(750*(screen_width/1024), 12 *(screen_height/768)+ sceneImage->getContentSize().height/2 + dict->valueForKey("offsetImage")->intValue()));
        if(state <= elementStatusUnbought)
        {
            button=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"), CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"), this, menu_selector(StarStoreNode::buttonPressed));
            
        }
        else if (state <= elementStatusBoughtUnselected)
        {
            button=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"), CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"), this, menu_selector(StarStoreNode::buttonPressed));
        }
        else
        {
            button=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("ACTIVE-BUTTON.png"), CCSprite::createWithSpriteFrameName("ACTIVE-BUTTON.png"), this, menu_selector(StarStoreNode::buttonPressed));
            
        }
        button->setPosition(ccp(836*(screen_width/1024)+button->getContentSize().width/2, button->getContentSize().height/2.5));
        background->setPosition(ccp( 50*(screen_width/1024) + background->getContentSize().width/2, background->getContentSize().height/2-15));
        star->setPosition( ccp(936*(screen_width/1024) + star->getContentSize().width/2, background->getContentSize().height-1.12*star->getContentSize().height));
        
        image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),57*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()));
        sceneImage->setPosition(ccp(750*(screen_width/1024), 8 *(screen_height/768)+ sceneImage->getContentSize().height/2 + dict->valueForKey("offsetImage")->intValue()));
        
        menu=CCMenu::create(button,NULL);
        menu->setPosition(ccp(0,0));
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        title=CCLabelTTF::create(dict->valueForKey("title")->getCString(), "Published-iOS/fonts/HelveticaNeue-Bold.ttf", 20*CCDirector::sharedDirector()->getContentScaleFactor());
        price=CCLabelTTF::create(dict->valueForKey("price")->getCString(), "Published-iOS/fonts/MyriadPro-BoldSemiCn.ttf", 19*CCDirector::sharedDirector()->getContentScaleFactor());
        description=CCLabelTTF::create(dict->valueForKey("description")->getCString(), "Published-iOS/fonts/HelveticaNeue.ttf", 12*CCDirector::sharedDirector()->getContentScaleFactor());
        levelRequired=CCLabelTTF::create(dict->valueForKey("lockedPrice")->getCString(), "Published-iOS/fonts/MyriadPro-Black.ttf", 10*CCDirector::sharedDirector()->getContentScaleFactor());
        title->setHorizontalAlignment(kCCTextAlignmentLeft);
        description->setHorizontalAlignment(kCCTextAlignmentLeft);
        description->setDimensions(CCSizeMake(440*(screen_width/1024), 70*(screen_height/768)));
        
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        title=CCLabelTTF::create(dict->valueForKey("title")->getCString(), "Helvetica-Bold", 40);
        description=CCLabelTTF::create(dict->valueForKey("description")->getCString(), "Helvetica Neue.ttf", 19);
        
        price=CCLabelTTF::create(dict->valueForKey("price")->getCString(), "myriadproboldsemicn.ttf", 44);
        
        CCLOG("state %d ",state);
        levelRequired=CCLabelTTF::create(dict->valueForKey("lockedPrice")->getCString(), "myriadproblack.ttf", 16);
        description->setDimensions(CCSizeMake(440*(screen_width/1024), 50*(screen_height/768)));
#endif
        priceValue=dict->valueForKey("price")->intValue();
        title->setDimensions(CCSizeMake(480*(screen_width/1024), 60*(screen_height/768)));
        price->setDimensions(CCSizeMake(200*(screen_width/1024), 40*(screen_height/768)));
        price->setHorizontalAlignment(kCCTextAlignmentCenter);
        levelRequired->setDimensions(CCSizeMake(35*(screen_width/1024), 35*(screen_height/768)));
        
        title->setPosition(ccp(476 *(screen_width/1024) ,this->getContentSize().height+description->getContentSize().height+title->getContentSize().height/4));
        description->setPosition(ccp(460*(screen_width/1024),this->getContentSize().height+description->getContentSize().height/2));
        price->setPosition(ccp(star->getPositionX()+star->getContentSize().width/2-price->getContentSize().width/1.7, star->getPositionY()-price->getContentSize().height/4 +5));
        levelRequired->setPosition(ccp(198*(screen_width/1024), 87*(screen_height/768)));
        locked->setPosition(ccp(levelRequired->getPositionX(), levelRequired->getPositionY()+5));
        
        star->setPosition( ccp(250 *(screen_width/1024), background->getContentSize().height-40));
        //        price->setPosition(ccp(star->getPositionX()+star->getContentSize().width/2+price->getContentSize().width/4, star->getPositionY()-5));
        image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),57*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()+5));
        TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
        if (platform == kTargetIpad || platform ==kTargetIphone)
        {   button->setPosition(ccp(836*(screen_width/1024)+button->getContentSize().width/2, (button->getContentSize().height/2.5)+13));
            background->setPosition(ccp( 50*(screen_width/1024) + background->getContentSize().width/2, background->getContentSize().height/2-15));
            star->setPosition( ccp(936*(screen_width/1024) + star->getContentSize().width/2, background->getContentSize().height-1.12*star->getContentSize().height));
            locked->setPosition(ccp(180*(screen_width/1024) +  locked->getContentSize().width/2, background->getContentSize().height - locked->getContentSize().height/2));
            image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),57*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()));
            sceneImage->setPosition(ccp(750*(screen_width/1024), 8 *(screen_height/768)+ sceneImage->getContentSize().height/2 + dict->valueForKey("offsetImage")->intValue()));
            
            if( GameManager::sharedGameManager()->get_devise_resolution()==1)
            {
                price->setDimensions(CCSizeMake(0, 0));
                price->setAnchorPoint(ccp(1, 1));
                title->setDimensions(CCSizeMake(0, 0));
                title->setAnchorPoint(ccp(0, 0));
                description->setHorizontalAlignment(kCCTextAlignmentLeft);
                description->setDimensions(CCSizeMake(800, 100));
                description->setAnchorPoint(ccp(0, 0));
                
                price->setFontSize(80);
                price->setPosition(ccp((star->getPositionX()-star->getContentSize().width/4)-30, star->getPositionY()+50));
                title->setFontSize(80);
                description->setFontSize(35);
                title->setPosition(ccp(260 *(screen_width/1024) ,(this->getContentSize().height/2+120)));
                description->setPosition(ccp((250*(screen_width/1024))+15,this->getContentSize().height/2));
            }
            if(GameManager::sharedGameManager()->get_devise_resolution()==2)
            {
                //CCLOG("iphone device.");
                price->setDimensions(CCSizeMake(0, 0));
                price->setAnchorPoint(ccp(0, 0));
                title->setDimensions(CCSizeMake(0, 0));
                title->setAnchorPoint(ccp(0, 0));
                price->setFontSize(40);
                description->setHorizontalAlignment(kCCTextAlignmentLeft);
                description->setDimensions(CCSizeMake(400, 60));
                description->setAnchorPoint(ccp(0, 0));
                
                star->setPosition( ccp(850*(screen_width/1024) +  star->getContentSize().width/2, background->getContentSize().height- 3*star->getContentSize().height/4-15));
                price->setPosition(ccp((star->getPositionX()+star->getContentSize().width/2), star->getPositionY()-24));
                
                description->setPosition(ccp(((260*(screen_width/1024)))+10,(this->getContentSize().height/2)));
                
                image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),57*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()+5));
                title->setPosition(ccp(276 *(screen_width/1024) ,(this->getContentSize().height)+60));
            }
            if(GameManager::sharedGameManager()->get_devise_resolution()==3)
            {
                price->setPosition(ccp(star->getPositionX()+star->getContentSize().width/2-price->getContentSize().width/1.9, star->getPositionY()-price->getContentSize().height/4 +5));
                price->setFontSize(30);
                
            }
        }
        else if(platform==kTargetAndroid) {
            locked->setPosition(ccp(180*(screen_width/1024) +  locked->getContentSize().width/2, background->getContentSize().height - locked->getContentSize().height/2));
            CCLOG("Android Device");
            star->setPosition( ccp(550 *(screen_width/1024), background->getContentSize().height+40));
            price->setPosition(ccp(star->getPositionX()+star->getContentSize().width/2+price->getContentSize().width/4, star->getPositionY()-5));
            image->setPosition(ccp(86*(screen_width/1024) + 50*(screen_width/1024),57*(screen_height/768) + dict->valueForKey("offsetImage")->intValue()+5));
        }
        title->setColor(ccc3(0, 0, 0));
        description->setColor(ccc3(20, 20, 20));
        price->setColor( ccc3(0, 0, 0));
        levelRequired->setColor( ccc3(0, 0, 0));
        this->addChild(background,10);
        this->addChild(star,14);
        this->addChild(locked,26);
        this->addChild(menu,22);
        this->addChild(image,24);
        this->addChild(sceneImage,24);
        this->addChild(title,32);
        this->addChild(description,30);
        this->addChild(price ,30);
        this->addChild(levelRequired,30);
        int lockedPrice=dict->valueForKey("lockedPrice")->intValue();
        if(state==3)
        {
            locked->setOpacity(0);
            levelRequired->setOpacity(0);
        }
        else if(state==2)
        {
            locked->setOpacity(0);
            levelRequired->setOpacity(0);
        }
        if (!dict->valueForKey("locked")->boolValue()&&lockedPrice<=GameManager::sharedGameManager()->getlevel())
        {
            locked->setOpacity(0);
            levelRequired->setOpacity(0);
        }
        return true;
    }
    return false;
}
void StarStoreNode::TestForBuy()
{
    CCDictionary *dict=(CCDictionary*)GameManager::sharedGameManager()->getstarStoreElements()->objectAtIndex(myIndex);
    int isLocked =dict->valueForKey("locked")->intValue();
    bool canContinue = true;
    if (isLocked)
    {
        int lockedPrice =dict->valueForKey("lockedPrice")->intValue();
        if (lockedPrice >GameManager::sharedGameManager()->getlevel())
        {
            canContinue = true;
            SEL_CallFuncO _selector1;
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/playful_reveal_melodic_18.mp3", false);
            //            CCAlertView *alert=CCAlertView::create("Sorry!", "\n\n\nYou need a higher level, try to hit the Instructional Noah Ark more often to increase your level!", NULL, "Done", this,_selector1 , NULL);
            //            this->addChild(alert);
            /*            UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Sorry!" message:@"" delegate:nil cancelButtonTitle:@"Done" otherButtonTitles: nil];
             
             UIImage* lockImage = [UIImage imageNamed: @"LOCK.png"];
             UIImageView *lockImageView = [[UIImageView alloc] initWithFrame:CGRectMake(123, 46, 35, 42)];
             [lockImageView setImage:lockImage];
             [alert addSubview:lockImageView];
             [alert show];*/
            button->setSelectedImage(CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"));
            button->setNormalImage(CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"));
        }
    }
    if (canContinue)
    {
        if (priceValue > GameManager::sharedGameManager()->getpoints())
        {
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/playful_reveal_melodic_18.mp3", false);
            button->setSelectedImage(CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"));
            button->setNormalImage(CCSprite::createWithSpriteFrameName("BUY-BUTTON.png"));
        }
        else
        {
            showingAlertViewToShop = true;
            
            //showingAlertViewToShop = NO;
            GameManager::sharedGameManager()->setpoints(GameManager::sharedGameManager()->getpoints()-priceValue);
            //[Settings sharedInstance].points -= priceValue;
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/success_playful_19.mp3", false);
            
            CCDictionary *element=(CCDictionary*)GameManager::sharedGameManager()->getstarStoreElements()->objectAtIndex(myIndex);
            element->setObject(CCString::createWithFormat("%d",elementStatusBoughtUnselected), "status");
            GameManager::sharedGameManager()->getstarStoreElements()->replaceObjectAtIndex(myIndex, element);
            CCDictionary *root = CCDictionary::create();
            root->setObject(GameManager::sharedGameManager()->getstarStoreElements(), "array");
            std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
            std::string fullPath = writablePath_temp + "text.plist";
            if(root->writeToFile(fullPath.c_str()))
                CCLog("see the plist file at %s", fullPath.c_str());
            else
                CCLog("write plist file failed");
            
            state = elementStatusBoughtUnselected;
            button->setSelectedImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
            button->setNormalImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
            this->runAction(CCCallFuncO::create(parent, selected, this));
            
        }
    }
}
void StarStoreNode::buttonPressed(CCObject *obj)
{
    if (state <= elementStatusUnbought)
    {
        this->TestForBuy();
    }
    else if (state <= elementStatusBoughtUnselected)
    {
        GameManager::sharedGameManager()->SelectStarStoreElementAtIndex(myIndex);
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/levelup_07.mp3", false);
        state = elementStatusBoughtSelected;
        locked->setOpacity(0);
        levelRequired->setOpacity(0);
        button->setSelectedImage(CCSprite::createWithSpriteFrameName("ACTIVE-BUTTON.png"));
        button->setNormalImage(CCSprite::createWithSpriteFrameName("ACTIVE-BUTTON.png"));
        
        //[invocation invoke];
        
        this->runAction(CCCallFuncO::create(parent, selected, this));
    }
    else if (state <= elementStatusBoughtSelected)
    {
        state = elementStatusBoughtUnselected;
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/unslected_star_node.mp3", false);
        GameManager::sharedGameManager()->UnselectStarStoreElementAtIndex(myIndex);
        button->setSelectedImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
        button->setNormalImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
        
        this->runAction(CCCallFuncO::create(parent, selected, this));
    }
}
void StarStoreNode::Unselect()
{
    if (state != elementStatusUnbought)
    {
        state = elementStatusBoughtUnselected;
        SoundManager::sharedSoundManager()->playSoundEffect("Sound/unslected_star_node.mp3", false);
        GameManager::sharedGameManager()->UnselectStarStoreElementAtIndex(myIndex);
        button->setSelectedImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
        button->setNormalImage(CCSprite::createWithSpriteFrameName("SELECT-BUTTON.png"));
    }
}
