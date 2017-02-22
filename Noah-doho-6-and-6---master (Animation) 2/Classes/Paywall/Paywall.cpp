//
//   Paywall.cpp
//  Noah360
//  Created by Neil D on 03/10/13.

#include "Paywall.h"
#include "../SoundManager/SoundManager.h"
#include "../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
 Paywall:: Paywall()
{
    
}
 Paywall::~ Paywall()
{

}
void  Paywall::onExit()
{
    CCNode::onExit();
}
void  Paywall::onEnter()
{
    CCNode::onEnter();
}
bool  Paywall::init()
{
    if (CCNode::init())
    {
        int zOrder=0;
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
                {
                    bg_paywall=CCSprite::create("paywall_ipad.png");
                    this->addChild(bg_paywall,zOrder-1);
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                else
                {
                    bg_paywall=CCSprite::create("paywall_Bonus.png");
                    this->addChild(bg_paywall, zOrder-1);
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                break;
            }
            case 2:
            {
                if (screen_width==1136)
                {
                    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
                    {
                        bg_paywall=CCSprite::create("Paywall_iPhone 5.png");
                        CCLog("iphone 5");
                        this->addChild(bg_paywall, zOrder-1);
                        bg_paywall->setPosition(ccp(screen_width/2-31, screen_height/2));
                        bg_paywall->setScaleX(0.95);
                    }
                    else
                    {
                        bg_paywall=CCSprite::create("paywall_bonus5.png");
                        this->addChild(bg_paywall, zOrder-1);
                        bg_paywall->setPosition(ccp(screen_width/2-31, screen_height/2));
                        bg_paywall->setScaleX(0.95);
                    }
                }
                else
                {
                    if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
                    {
                        bg_paywall=CCSprite::create("paywall_ipad.png");
                        this->addChild(bg_paywall, zOrder-1);
                        bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                    }
                    else
                    {
                        bg_paywall=CCSprite::create("paywall_Bonus.png");
                        this->addChild(bg_paywall,zOrder-1);
                        bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                    }
                }
                break;
            }
            case 3:
            {
                if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
                {
                    bg_paywall=CCSprite::create("paywall_ipad.png");
                    this->addChild(bg_paywall, zOrder-1);
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                else
                {
                    bg_paywall=CCSprite::create("paywall_bonus5.png");
                    this->addChild(bg_paywall, zOrder-1);
                    GameManager::sharedGameManager()->get_header()->getupgrade()->setPosition(ccpAdd(GameManager::sharedGameManager()->get_header()->getupgrade()->getPosition(), ccp(0, -30)));
                    //upgrade
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                break;
            }
            case 4:
            {
                if (GameManager::sharedGameManager()->getcurrent_scene().getValue()==13)
                {
                    bg_paywall=CCSprite::create("paywall_ipad.png");
                    this->addChild(bg_paywall, zOrder-1);
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                else
                {
                    bg_paywall=CCSprite::create("paywall_Bonus_iPhone_4.jpg");
                    this->addChild(bg_paywall, zOrder-1);
                    bg_paywall->setPosition(ccp(screen_width/2, screen_height/2));
                }
                break;
            }
            default:
                break;
        }
        return true;
    }
    return false;
}
