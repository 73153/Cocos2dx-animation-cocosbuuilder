//
//  RubberBand.cpp
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//
#include "RubberBand.h"
#include "../../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width
#define NormalAnimalY 200*(WINHEIGHT/768)
#define HighAnimalY 140*(WINHEIGHT/768)
#define MidAnimalY 95*(WINHEIGHT/768)
#define LowAminalY 50*(WINHEIGHT/768)
#define normalY 1*(WINHEIGHT/768)
#define highY 2*(WINHEIGHT/768)
#define midY 3*(WINHEIGHT/768)
#define lowY 4*(WINHEIGHT/768)
#define normalX 1*(WINWIDTH/1024)

#define midX 2*(WINWIDTH/1024)

#define highX 3*(WINWIDTH/1024)

#define MiddleAnimalX 512*(WINWIDTH/1024)

#define HalfRightAnimalX 672*(WINWIDTH/1024)

#define HalfLeftAnimalX 352*(WINWIDTH/1024)

#define FullRightAnimalX 832*(WINWIDTH/1024)
#define FullLeftAnimalX 192*(WINWIDTH/1024)

RubberBand::RubberBand():mAnimationManager(NULL),posInHeight(0),posInLenght(0)
{

  
}
RubberBand::~RubberBand()
{

}
bool RubberBand::init()
{
    if (CCNode::init())
    {
        size=CCDirector::sharedDirector()->getWinSize();
        slingShotBand = CCSprite::createWithSpriteFrameName("rubberBand_11.png");
        slingShotBand->setPosition(ccp((512*(size.width/1024)), (120*(size.height/768))));
        slingShotBand->setScale(1/0.75f);
        this->addChild(slingShotBand,20);
       return true;
    }
    return false;
}
void RubberBand::onEnter()
{
    CCNode::onEnter();
}
void RubberBand::LetGoBand()
{
    float animTime = 5*0.05f;
    CCAnimation* animation = CCAnimation::create();
    for( int i=posInHeight;i>=2;i--)
    {
        char szName[100] = {0};
        sprintf(szName, "rubberBand_%d%d.png",i, posInHeight);
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(szName))
        {
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(szName));
            animTime+=0.05f;
        }
    }
    if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_rubber))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(sound_rubber);
    }
    sound_rubber=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/rubberBoing.mp3", false);
     animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("rubberBand_01.png"));
      animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("rubberBand_02.png"));
      animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("rubberBand_01.png"));
      animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("rubberBand_02.png"));
      animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("rubberBand_11.png"));
    
    animation->setDelayPerUnit(animTime/ 7);
    animation->setRestoreOriginalFrame(false);
    CCAnimate* action = CCAnimate::create(animation);
    action->setDuration(animTime);
    slingShotBand->runAction(CCSequence::create(action,NULL));

    
//    cocos2d::CCAnimation *pAnimation=CCAnimation::createWithSpriteFrames(frames);
//    pAnimation->setRestoreOriginalFrame(false);
//    CCAnimate *anim=CCAnimate::create(pAnimation);
//    anim->setDuration(animTime);
//    slingShotBand->runAction(anim);
}
CCPoint RubberBand::HandleTouch(CCPoint point)
{
    posInHeight = normalY;
    posInLenght = normalX;
    direction = 1;
    float x = (512*(size.width/1024));
    float y = (200*(size.height/768));
    if (point.y < 260*(size.height/768) && point.y >= 160*(size.height/768))
    {
        posInHeight = normalY;
        y = NormalAnimalY;
        //[theAnimal setPosition:CGPointMake(theAnimal.position.x, 240)];
    }
    else if (point.y < 160*(size.height/768) && point.y >= 120*(size.height/768))
    {
        posInHeight = highY;
        y = HighAnimalY;
        //[theAnimal setPosition:CGPointMake(theAnimal.position.x, 190)];
    }
    else if (point.y < 120*(size.height/768) && point.y >= 70*(size.height/768))
    {
        posInHeight = midY;
        y = MidAnimalY;
        //[theAnimal setPosition:CGPointMake(theAnimal.position.x, 140)];
    }
    else if (point.y < 70*(size.height/768))
    {
        posInHeight = lowY;
        y = LowAminalY;
        //[theAnimal setPosition:CGPointMake(theAnimal.position.x, 80)];
    }
    if (point.x <= (512*(size.width/1024) + 50*(size.width/1024)) && point.x >= (512*(size.width/1024) - 50*(size.width/1024)))
    {
        posInLenght = normalX;
        x = MiddleAnimalX;
    }
    else if (point.x < (512*(size.width/1024) + 250*(size.width/1024)) && point.x > (512*(size.width/1024) - 250*(size.width/1024)))
    {
        if (point.x > (512*(size.width/1024)))
        {
            direction = -1;
            x = HalfRightAnimalX;
        }
        else
        {
            x = HalfLeftAnimalX;
            if (posInHeight > 1)
            {
                posInLenght = midX;
            }
        }
    }
    else if (point.x >= (512*(size.width/1024) + 250*(size.width/1024)) || point.x <= (512 - 250)*(size.width/1024)) {
        if (point.x > (512)*(size.width/1024)) {
            direction = -1;
            x = FullRightAnimalX;
        }
        else
            x = FullLeftAnimalX;
            if (posInHeight > 1)
            {
                posInLenght = highX;
            }
    }
    if (prevPosInHeight != posInHeight)
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_rubber_1))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(sound_rubber_1);
        }
       sound_rubber_1=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/RubberRubb.mp3", false);
        prevPosInHeight = posInHeight;
    }
    else if (prevPosInLenght != posInLenght)
    {
        if (SoundManager::sharedSoundManager()->isEffectPlaying(sound_rubber_1))
        {
            SoundManager::sharedSoundManager()->stopSoundEffect(sound_rubber_1);
        }
        sound_rubber_1=SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 13/RubberRubb.mp3", false);
        prevPosInLenght = posInLenght;
    }
    slingShotBand->setScaleX(direction*1/0.75f);
    CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("rubberBand_%d%d.png",posInHeight,posInLenght)->getCString());
    if (frame)
    {
        slingShotBand->setDisplayFrame(frame);
    }
    return ccp(x,y);
}


