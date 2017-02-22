//
//  LaunchingAnimal.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "LaunchingAnimal.h"
#include "../../SoundManager/SoundManager.h"
#include "../../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
LaunchingAnimal::LaunchingAnimal()
{
  
}
LaunchingAnimal::~LaunchingAnimal()
{

}
LaunchingAnimal* LaunchingAnimal::create(CCString *animalName, int index1)
{
    LaunchingAnimal* ret = new LaunchingAnimal();
    if (ret)
    {
        if (ret->initAnimal(animalName,index1))
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
bool LaunchingAnimal::initAnimal(CCString *animalName, int index1)
{
    if (LaunchingAnimal::init())
    {
        name =CCString::create(animalName->getCString());
        name->retain();
        state = 0;
        image = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("1%s.png",name->getCString())->getCString());
        image->retain();
        image->setScale(AnimalInitialScale);
        image->setPosition(ccp(MiddleAnimalX, NormalAnimalY));
        index = index1;
        this->addChild(image);
        return true;
    }
    return false;
}
void LaunchingAnimal::onEnter()
{
    CCNode::onEnter();
}
float LaunchingAnimal::LaunchAnimal()
{
    ccBezierConfig bezzier;
    float flyTime = 2.0f;
    float trajectoryScale;
    float fullPointx;
    if (image->getPositionY() == NormalAnimalY)
        return 0;
    if (image->getPositionY() == HighAnimalY) {
        trajectoryScale = 0.6f;
    }
    if (image->getPositionY() == MidAnimalY) {
        trajectoryScale = 0.8f;
    }
    if (image->getPositionY()== LowAminalY) {
        trajectoryScale = 1.0f;
    }
    if (image->getPositionX()== MiddleAnimalX) {
        fullPointx = 0;
    }
    if (image->getPositionX() == HalfRightAnimalX) {
        fullPointx = HalfLeftAnimalX -  MiddleAnimalX;
    }
    if (image->getPositionX()== FullRightAnimalX) {
        fullPointx = FullLeftAnimalX -  MiddleAnimalX;
    }
    if (image->getPositionX()== HalfLeftAnimalX) {
        fullPointx = HalfRightAnimalX -  MiddleAnimalX;
    }
    if (image->getPositionX()== FullLeftAnimalX) {
        fullPointx = FullRightAnimalX -  MiddleAnimalX;
    }
    
    //bezzier.controlPoint_1 = ccp(theAnimal.position.x, theAnimal.position.y);
    bezzier.controlPoint_1 = ccp(MiddleAnimalX + fullPointx*trajectoryScale*1/6,514*(screen_height/768)*trajectoryScale*5/4);
    bezzier.controlPoint_2 = ccp(MiddleAnimalX + fullPointx*trajectoryScale*1/3,514*(screen_height/768)*trajectoryScale*5/3);
    bezzier.endPosition = ccp(MiddleAnimalX + fullPointx*trajectoryScale , 512*(screen_height/768) * trajectoryScale);

    if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_fall))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(sound_fall);
    }
    if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_fall_animal))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(sound_fall_animal);
    }
    TargetPlatform platForm = CCApplication::sharedApplication()->getTargetPlatform();
    if(platForm==kTargetIphone || platForm==kTargetIpad)
        
    {
        sound_fall=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/animalFalling.mp3", false);
        sound_fall_animal=SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 13/LTB_%s.mp3",name->getCString())->getCString(), false);
    }
    else
    {
        sound_fall=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/animalFalling.m4a", false);
        sound_fall_animal=SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 13/LTB_%s.m4a",name->getCString())->getCString(), false);
    }
    
   CCActionInterval *nb=CCBezierTo::create(flyTime*trajectoryScale,bezzier);
   image->runAction(CCSpawn::create(CCEaseOut::create(nb, 2.0),CCEaseOut::create(CCScaleTo::create(flyTime*trajectoryScale, AnimalMinScale/(trajectoryScale*trajectoryScale*trajectoryScale)), 2.0),NULL));
   image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("2%s.png",name->getCString())->getCString()));
   image->runAction(CCRepeatForever::create(CCRotateBy::create(2.4f, 360)));
    return flyTime*trajectoryScale;
}
void LaunchingAnimal::ResetAnimal()
{
    image->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("1%s.png",name->getCString())->getCString()));
    image->setPosition(CCPointMake(MiddleAnimalX, NormalAnimalY));
    image->setScale(AnimalInitialScale);
    image->setRotation(0.0f);
    image->stopAllActions();
}