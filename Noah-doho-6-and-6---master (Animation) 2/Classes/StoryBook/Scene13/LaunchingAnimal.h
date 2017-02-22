//
//  LaunchingAnimal.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__LaunchingAnimal__
#define __Noah360__LaunchingAnimal__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
USING_NS_CC_EXT;
#define WINHEIGHT  CCDirector::sharedDirector()->getWinSize().height
#define WINWIDTH   CCDirector::sharedDirector()->getWinSize().width

#define AnimalInitialScale 1.0f/0.75f
#define AnimalMidScale 0.4f/0.75f
#define AnimalMissScale 0.2f/0.75f
#define AnimalMinScale 0.1f/0.75f
#define NormalAnimalY 200*(WINHEIGHT/768)
#define HighAnimalY 140*(WINHEIGHT/768)
#define MidAnimalY 95*(WINHEIGHT/768)
#define LowAminalY 50*(WINHEIGHT/768)

#define MiddleAnimalX 512*(WINWIDTH/1024)
#define HalfRightAnimalX 672*(WINWIDTH/1024)
#define HalfLeftAnimalX 352*(WINWIDTH/1024)
#define FullRightAnimalX 832*(WINWIDTH/1024)
#define FullLeftAnimalX 192*(WINWIDTH/1024)
class LaunchingAnimal: public cocos2d::CCNode
{

public:
    LaunchingAnimal();
    virtual ~LaunchingAnimal();
    virtual void onEnter();
    bool initAnimal(CCString *animalName, int index1);
    CC_SYNTHESIZE_RETAIN(CCSprite*,  image,  image);
    CC_SYNTHESIZE_RETAIN(CCString*, name, name);
    CC_SYNTHESIZE(int, index, index);
    int        state;
    
    unsigned int sound_fall;
    unsigned int sound_fall_animal;
    float LaunchAnimal();
    void ResetAnimal();
    static LaunchingAnimal* create(CCString *animalName, int index1);
};
#endif /* defined(__Noah360__LaunchingAnimal__) */
