//  HelloCocosBuilderLayer.cpp
//  Demo
//  Created by Neil D on 20/05/13.
#include "Scene8Layer.h"
#include "../../GameManager/GameManager.h"
#include "../../SoundManager/SoundManager.h"
#include "../Footer/FooterLayerLoader.h"
#include "CCValue.h"
using namespace cocos2d_extensions;
using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;
Scene8Layer::Scene8Layer()
{
     zOrderCounter=0;
}
Scene8Layer::~Scene8Layer()
{
     //CCLog("Scene 8 closed");
}
void Scene8Layer::onExit()
{
    this->LeavingScene();
//    this->unscheduleAllSelectors();
//    this->stopAllActions();
//    this->removeAllChildrenWithCleanup(true);
    SoundManager::sharedSoundManager()->stopNarrator();
    CCLayer::onExit();
}
void Scene8Layer::onEnter()
{
    this->setTouchEnabled(true);
    waytingForNarrator = true;
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Scene9Blocks_android.plist");
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene9Blocks_android.plist", "Scene9Blocks.pvr.ccz");
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Scene9Blocks.plist");
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Scene9Blocks.plist", "Scene9Blocks.pvr.gz");
#endif

    
    currentLevel = 1;
    this->add_arkPiece();
    SoundManager::sharedSoundManager()->startBackgroundSound();
    SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
    SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 9/noahArkBuildFinished.mp3"));
    this->schedule(schedule_selector(Scene8Layer::GetInstructionalNoahStartingLine),0.2);
    CCLayer::onEnter();
}
void Scene8Layer::add_arkPiece()
{
    //screenSize=CCSizeMake(1024, 768);
    screenSize=CCSizeMake(1024/CCDirector::sharedDirector()->getContentScaleFactor(), 768/CCDirector::sharedDirector()->getContentScaleFactor());
    //CCDirector::sharedDirector()->getWinSize();
    //CCSizeMake(1024, 768);
    //CCDirector::sharedDirector()->getWinSize();
    //CCSizeMake(1024, 768);
    background =CCSprite::create("whiteBackground.png");
    background->setScaleY(2);
    background->setPosition(ccp(screen_width/2, screen_height+background->getContentSize().height/2-40));
    house_roof = CCSprite::createWithSpriteFrameName("house_finished_a-(rooftop).png");
    houseDust  = CCSprite::createWithSpriteFrameName("arkModelDust1.png");
    houseDust->setPosition(ccp(screenSize.width/2,screenSize.height /2));
    house_roof->setPosition(ccp( screenSize.width/2, screenSize.height + house_roof->getContentSize().height));
    this->deck_1_ark_Piece();
    this->deck_2_ark_Piece();
    this->house_ark_Piece();
    this->main_ark_Piece();

    this->AddNodeToScene(background);
    this->AddNodeToScene(main_d);
    this->AddNodeToScene(main_c);
    this->AddNodeToScene(main_b);
    this->AddNodeToScene(deck1_h);
    this->AddNodeToScene(deck1_g);
    this->AddNodeToScene(deck1_f);
    this->AddNodeToScene(deck1_e);
    this->AddNodeToScene(deck1_d);
    this->AddNodeToScene(deck1_c);
    this->AddNodeToScene(deck1_b);
    this->AddNodeToScene(deck2_h);
    this->AddNodeToScene(deck2_g);
    this->AddNodeToScene(deck2_f);
    this->AddNodeToScene(deck2_e);
    this->AddNodeToScene(main_a);
    this->AddNodeToScene(deck1_a);
    this->AddNodeToScene(deck2_d);
    this->AddNodeToScene(deck2_c);
    this->AddNodeToScene(deck2_b);
    this->AddNodeToScene(deck2_a);
    this->AddNodeToScene(house_i);
    this->AddNodeToScene(house_h);
    this->AddNodeToScene(house_g);
    this->AddNodeToScene(house_f);
    this->AddNodeToScene(house_e);
    this->AddNodeToScene(house_d);
    this->AddNodeToScene(house_c);
    this->AddNodeToScene(house_b);
  
    
    this->AddNodeToScene(house_roof);
    this->addChild(houseDust, 5000);
    

    //    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/gamePiano.mp3",false);
    interactionsEnabled = true;
   
    
    //getting that nice FadeIn effect;
    main_a->getwire()->runAction(CCFadeIn::create(0.4f));
    main_b->getwire()->runAction(CCFadeIn::create(0.4f));
    main_c->getwire()->runAction(CCFadeIn::create(0.4f));
    main_d->getwire()->runAction(CCFadeIn::create(0.4f));
    main_a->EnablePiece();
    main_b->EnablePiece();
    main_c->EnablePiece();
    main_d->EnablePiece();
}
void Scene8Layer::main_ark_Piece()
{
    CCArray *positionArray=CCArray::create();
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)* 240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)*160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)*580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)*660)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)*580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)*160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)*240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 , (screen_height/768)*660)));

    int randomPosIndex = rand()%positionArray->count();
    
    CCValue<CCPoint> * v3   = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    CCPoint sPos =v3->getValue();
    main_a= ArkBuildingPiece::create(CCString::create("main_frame"),CCString::create("a"),sPos,ccp(171 ,327),ccp(171 ,327), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);

    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    main_b= ArkBuildingPiece::create(CCString::create("main_frame"),CCString::create("b"),sPos,ccp(256 , 482),ccp(256 , 482), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    randomPosIndex = rand()%positionArray->count();
     v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    main_c= ArkBuildingPiece::create(CCString::create("main_frame"),CCString::create("c"),sPos,ccp(490 ,442),ccp(490 , 442), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    main_d= ArkBuildingPiece::create(CCString::create("main_frame"),CCString::create("d"),sPos,ccp(677 , 278),ccp(677 , 278), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeAllObjects();
    


    main_a->SetWirePosition(ccp(171 ,327), screenSize);
    main_b->SetWirePosition(ccp(256 ,482), screenSize);
    main_c->SetWirePosition(ccp(490, 442), screenSize);
    main_d->SetWirePosition(ccp(677 ,278),screenSize);
//    main_a->SetWirePosition(ccp((screen_width/1024)*171 , (screen_height/768)*327), screenSize);
//    main_b->SetWirePosition(ccp((screen_width/1024)*256 , (screen_height/768)*482), screenSize);
//    main_c->SetWirePosition(ccp((screen_width/1024)*490, (screen_height/768)*442), screenSize);
//    main_d->SetWirePosition(ccp((screen_width/1024)*677 ,(screen_height/768)* 278),screenSize);

}
void Scene8Layer::deck_1_ark_Piece()
{

    CCArray *positionArray=CCArray::create();
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 , (screen_height/768)*240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)* 160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)* 580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)* 660)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)* 240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)* 660)));
    
    int randomPosIndex = rand()%positionArray->count();
    
    CCValue<CCPoint> * v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    CCPoint sPos =v3->getValue();
    
    
    deck1_a= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("a"),sPos,ccp(265 , 438),ccp(266 ,439), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_b= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("b"),sPos,ccp(383 , 421),ccp(384 , 421), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_c= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("c"),sPos,ccp(519 , 407),ccp(519 ,406), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_d= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("d"),sPos,ccp(637 , 389),ccp(637 , 390), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_e= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("e"),sPos,ccp(226 , 387),ccp(226 ,387), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_f= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("f"),sPos,ccp(282 , 363),ccp(282 , 363), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_g= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("g"),sPos,ccp(386 , 351),ccp(386 , 351), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    
    
    randomPosIndex = rand()%positionArray->count();
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck1_h= ArkBuildingPiece::create(CCString::create("deck1"),CCString::create("h"),sPos,ccp(519 , 351),ccp(519 ,351), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);

    deck1_a->SetWirePosition(ccp(261 , 439), screenSize);
    deck1_b->SetWirePosition(ccp(393 ,421), screenSize);
    deck1_c->SetWirePosition(ccp(517 ,404), screenSize);
    deck1_d->SetWirePosition(ccp(639 ,387), screenSize);
    deck1_e->SetWirePosition(ccp(221 ,382), screenSize);
    deck1_f->SetWirePosition(ccp(284 ,361), screenSize);
    deck1_g->SetWirePosition(ccp(384 ,350), screenSize);
    deck1_h->SetWirePosition(ccp(519 ,348), screenSize);


}
void Scene8Layer::deck_2_ark_Piece()
{
    //Bottom Pieces
    CCArray *positionArray=CCArray::create();
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)* 240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)* 160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)* 580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)* 660)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 , (screen_height/768)*240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)* 660)));
    
    int randomPosIndex = rand()%positionArray->count();
    
    CCValue<CCPoint> * v3    = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    CCPoint sPos =v3->getValue();
    
    deck2_a= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("a"),sPos,ccp(232 , 370),ccp(232 ,370), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_b= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("b"),sPos,ccp(377 , 359),ccp(377 , 359), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_c= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("c"),sPos,ccp(465 , 342),ccp(465 , 342), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_d= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("d"),sPos,ccp(629 , 323),ccp(629 , 323), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_e= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("e"),sPos,ccp(194 , 313),ccp(194 , 313), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_f= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("f"),sPos,ccp(276 , 306),ccp(276 , 306), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_g= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("g"),sPos,ccp(353 , 296),ccp(353 , 296), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    deck2_h= ArkBuildingPiece::create(CCString::create("deck2"),CCString::create("h"),sPos,ccp(500 , 283),ccp(500 , 283), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
   
    deck2_a->SetWirePosition(ccp(235 , 370), screenSize);
    deck2_b->SetWirePosition(ccp(382 , 360), screenSize);
    deck2_c->SetWirePosition(ccp(463 , 341), screenSize);
    deck2_d->SetWirePosition(ccp(628 , 323), screenSize);
    deck2_e->SetWirePosition(ccp(197 , 312), screenSize);
    deck2_f->SetWirePosition(ccp(278 , 304), screenSize);
    deck2_g->SetWirePosition(ccp(354 , 293), screenSize);
    deck2_h->SetWirePosition(ccp(516 , 282), screenSize);
}
void Scene8Layer::house_ark_Piece()
{
    //Bottom Pieces
    CCArray *positionArray=CCArray::create();
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 ,(screen_height/768)* 240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 , (screen_height/768)*160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*120 , (screen_height/768)*580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*260 ,(screen_height/768)* 660)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 580)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*740 ,(screen_height/768)* 160)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)* 240)));
    positionArray->addObject(CCValue<CCPoint>::valueWithValue(ccp((screen_width/1024)*884 ,(screen_height/768)* 660)));
 
    int randomPosIndex = rand()%positionArray->count();
    CCValue<CCPoint> * v3 = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    CCPoint sPos =v3->getValue();
    house_b= ArkBuildingPiece::create(CCString::create("house"),CCString::create("b"),sPos,ccp(409 , 334),ccp(409 ,334), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    v3 = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_c= ArkBuildingPiece::create(CCString::create("house"),CCString::create("c"),sPos,ccp(480 , 320),ccp(480 , 320), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    v3=static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos=v3->getValue();
    house_d= ArkBuildingPiece::create(CCString::create("house"),CCString::create("d"),sPos,ccp(618 , 316),ccp(618 , 316), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_e= ArkBuildingPiece::create(CCString::create("house"),CCString::create("e"),sPos,ccp(351 , 310),ccp(351 , 310), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_f= ArkBuildingPiece::create(CCString::create("house"),CCString::create("f"),sPos,ccp(603 , 288),ccp(603 , 288), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3= static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_g= ArkBuildingPiece::create(CCString::create("house"),CCString::create("g"),sPos,ccp(329 , 296),ccp(329 , 296), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_h= ArkBuildingPiece::create(CCString::create("house"),CCString::create("h"),sPos,ccp(384 , 286),ccp(384 , 286), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    randomPosIndex = rand()%positionArray->count();
    
    v3  = static_cast<CCValue<CCPoint> *>(positionArray->objectAtIndex(randomPosIndex));
    sPos =v3->getValue();
    house_i= ArkBuildingPiece::create(CCString::create("house"),CCString::create("i"),sPos,ccp(512 , 281),ccp(512 , 281), this,callfuncO_selector(Scene8Layer::PieceIsCorrect));
    positionArray->removeObjectAtIndex(randomPosIndex);
    
    house_b->SetWirePosition(ccp(409 , 334), screenSize);
    house_c->SetWirePosition(ccp(480 , 320), screenSize);
    house_d->SetWirePosition(ccp(618 , 316) ,screenSize);
    house_e->SetWirePosition(ccp(351 , 310), screenSize);
    house_f->SetWirePosition(ccp(603 , 288), screenSize);
    house_g->SetWirePosition(ccp(329 , 296), screenSize);
    house_h->SetWirePosition(ccp(353 , 293) ,screenSize);
    house_i->SetWirePosition(ccp(516 , 282), screenSize);
}
#pragma mark -
#pragma mark ccb functions
#pragma mark -
void Scene8Layer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
}
SEL_CallFuncN Scene8Layer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler Scene8Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCMenuItemSelector");
    return NULL;
}
SEL_CCControlHandler Scene8Layer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    //CCLog("onResolveCCBCCControlSelector");
    return NULL;
}
bool Scene8Layer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}
bool Scene8Layer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    //CCLog("onAssignCCBCustomProperty");
    bool bRet = false;
    return bRet;
}
void Scene8Layer::AddNodeToScene(CCNode* node)
{
    this->addChild(node,zOrderCounter);
    zOrderCounter+=1;
}
void Scene8Layer::GetInstructionalNoahStartingLine(float dt)
{
        this->unschedule(schedule_selector(Scene8Layer::GetInstructionalNoahStartingLine));
    
        int angle = 0;//arc4random()%4;
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setVisible(true);
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setRotation(angle*90);
        int offsetValue;
        switch (angle)
        {
            case 0:
                offsetValue = rand()%600-300;
                GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,0));
                break;
            case 2:
                offsetValue = rand()%600-300;
                GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width/2 + offsetValue,screen_height+5));
                break;
            case 1:
                offsetValue = rand()%400-200;
                GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(0-5,screen_height/2+offsetValue));
                
                break;
            case 3:
                offsetValue = rand()%400-200;
                GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->setPosition(ccp(screen_width+5,screen_height/2+offsetValue));
                
                break;
                
            default:
                break;
        }
        GameManager::sharedGameManager()->get_header()->getinstructionalNoah()->MakeNoahAppearWithoutBackground();
}
void Scene8Layer::LeavingScene()
{
    if (currentLevel>=1)
    {
        main_a->stopSwallingTouchs();
        main_b->stopSwallingTouchs();
        main_c->stopSwallingTouchs();
        main_d->stopSwallingTouchs();
    }
    if (currentLevel>=2)
    {
        deck1_a->stopSwallingTouchs();
        deck1_b->stopSwallingTouchs();
        deck1_c->stopSwallingTouchs();
        deck1_d->stopSwallingTouchs();
        deck1_e->stopSwallingTouchs();
        deck1_f->stopSwallingTouchs();
        deck1_g->stopSwallingTouchs();
        deck1_h->stopSwallingTouchs();
 
    }
    if (currentLevel>=3)
    {
        deck2_a->stopSwallingTouchs();
        deck2_b->stopSwallingTouchs();
        deck2_c->stopSwallingTouchs();
        deck2_d->stopSwallingTouchs();
        deck2_e->stopSwallingTouchs();
        deck2_f->stopSwallingTouchs();
        deck2_g->stopSwallingTouchs();
        deck2_h->stopSwallingTouchs();
  
    }
    if (currentLevel>=4)
    {
        house_b->stopSwallingTouchs();
        house_c->stopSwallingTouchs();
        house_d->stopSwallingTouchs();
        house_e->stopSwallingTouchs();
        house_f->stopSwallingTouchs();
        house_g->stopSwallingTouchs();
        house_h->stopSwallingTouchs();
        house_i->stopSwallingTouchs();
    }
}
void Scene8Layer::PlayHouseSound()
{
    SoundManager::sharedSoundManager()->getarr_instractunalNoah()->removeAllObjects();
    SoundManager::sharedSoundManager()->getarr_instractunalNoah()->addObject(CCString::create("Sound/Scene 9/noahArkBuildFinished.mp3"));
    GameManager::sharedGameManager()->get_header()->SwitchOnInstructionalNoahWithoutBackGround();
}
void Scene8Layer::PlayPieceCorrect()
{
    int rand_ = rand()%23-14;
    while (rand_ == lastPlayed)
    {
        rand_ =rand()%23-14;
    }
    lastPlayed = rand_;
    if (rand_ >= 1)
    {
        SoundManager::sharedSoundManager()->playSoundEffect(CCString::createWithFormat("Sound/Scene 9/arkPieceDone%d.mp3",rand_)->getCString(), false);
    }
}
void Scene8Layer::PieceIsCorrect()
{
    if (currentLevel == 4)
    {
        if (house_b->getisCorrect() && house_c->getisCorrect() && house_d->getisCorrect() && house_e->getisCorrect() && house_f->getisCorrect() && house_g->getisCorrect() && house_h->getisCorrect() && house_i->getisCorrect())
        {
            currentLevel = 5;
                       float fallingTime = 0.20f;
            float waitingTime = 0.6f;
           house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCDelayTime::create(fallingTime),CCRotateTo::create(0.05f, 14.0f),CCEaseElasticOut::create(CCRotateTo::create(0.2f, 0.0f), 0.05f),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            if (screen_height<=640)
            {
               house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCEaseBounceOut::create(CCMoveTo::create(fallingTime+0.2f,ccp(screenSize.width/2+16,house_roof->getContentSize().height+ screen_height/2+16 ))),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
            }
            else
            {
                house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCEaseBounceOut::create(CCMoveTo::create(fallingTime+0.2f,ccp(screenSize.width/2+16,house_roof->getContentSize().height+ screen_height/2+37 ))),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
            }
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            if (screen_height==640&&screen_width==960)
            {
                house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCEaseBounceOut::create(CCMoveTo::create(fallingTime+0.2f,ccp(screenSize.width/2+16,house_roof->getContentSize().height+ screen_height/2 ))),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
                
            }
            else if (screen_width==1136)
            {
                house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCEaseBounceOut::create(CCMoveTo::create(fallingTime+0.2f,ccp(screenSize.width/2+10,screen_height-140))),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
            }
            else
            {
                house_roof->runAction(CCSequence::create(CCDelayTime::create(waitingTime),CCEaseBounceOut::create(CCMoveTo::create(fallingTime+0.2f,ccp(screenSize.width/2+16,screen_height/2 + 76*(screen_height/768) ))),CCCallFunc::create(this, callfunc_selector(Scene8Layer::PlayHouseSound)),NULL));
            }
    #endif
            CCAnimation* animation = CCAnimation::create();
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust1.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust2.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust3.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust4.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust5.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust6.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust7.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust8.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust9.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust10.png"));
            animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("arkModelDust11.png"));
            animation->setRestoreOriginalFrame(true);
            animation->setDelayPerUnit(0.40f/11);
            CCAnimate* action = CCAnimate::create(animation);
            action->setDuration(1);
            CCSequence *seq=CCSequence::create(CCDelayTime::create(fallingTime+waitingTime),action,NULL);
            houseDust->runAction(seq);
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/HOUSE Impact.mp3", false);
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/magic_flourish_04.mp3", false);
        }
        else
            this->PlayPieceCorrect();
    }
    if (currentLevel == 3)
    {
        if (deck2_a->getisCorrect() && deck2_b->getisCorrect() && deck2_c->getisCorrect() && deck2_d->getisCorrect() && deck2_e->getisCorrect() && deck2_f->getisCorrect() && deck2_g->getisCorrect() && deck2_h->getisCorrect())
        {
            currentLevel = 4;
            
            house_b->getwire()->runAction(CCFadeIn::create(0.4f));
            house_c->getwire()->runAction(CCFadeIn::create(0.4f));
            house_d->getwire()->runAction(CCFadeIn::create(0.4f));
            house_e->getwire()->runAction(CCFadeIn::create(0.4f));
            house_f->getwire()->runAction(CCFadeIn::create(0.4f));
            house_g->getwire()->runAction(CCFadeIn::create(0.4f));
            house_h->getwire()->runAction(CCFadeIn::create(0.4f));
            house_i->getwire()->runAction(CCFadeIn::create(0.4f));
            
            house_b->EnablePiece();
            house_c->EnablePiece();
            house_d->EnablePiece();
            house_e->EnablePiece();
            house_f->EnablePiece();
            house_g->EnablePiece();
            house_h->EnablePiece();
            house_i->EnablePiece();
            
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/noahArkDeck2Done.mp3",false);
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/magic_flourish_05.mp3",false);
        }
        else
        {
            this->PlayPieceCorrect();
        }
        
    }
    if (currentLevel == 2)
    {
        if (deck1_a->getisCorrect() && deck1_b->getisCorrect() && deck1_c->getisCorrect() && deck1_d->getisCorrect() && deck1_e->getisCorrect() && deck1_f->getisCorrect() && deck1_g->getisCorrect() && deck1_h->getisCorrect())
        {
            currentLevel = 3;
            
            //getting that nice FadeIn effect;
            deck2_a->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_b->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_c->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_d->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_e->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_f->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_g->getwire()->runAction(CCFadeIn::create(0.4f));
            deck2_h->getwire()->runAction(CCFadeIn::create(0.4f));
            
            deck2_a->EnablePiece();
            deck2_b->EnablePiece();
            deck2_c->EnablePiece();
            deck2_d->EnablePiece();
            deck2_e->EnablePiece();
            deck2_f->EnablePiece();
            deck2_g->EnablePiece();
            deck2_h->EnablePiece();
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/noahArkDeck1Done.mp3",false);
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/magic_flourish_04.mp3",false);
        }
        else
            this->PlayPieceCorrect();
        
    }
    if (currentLevel == 1)
    {
        if (main_a->getisCorrect() && main_b->getisCorrect() && main_c->getisCorrect() && main_d->getisCorrect())
        {
            
            currentLevel = 2;
            
            //getting that nice FadeIn effect;
            deck1_a->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_b->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_c->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_d->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_e->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_f->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_g->getwire()->runAction(CCFadeIn::create(0.4f));
            deck1_h->getwire()->runAction(CCFadeIn::create(0.4f));
            
            deck1_a->EnablePiece();
            deck1_b->EnablePiece();
            deck1_c->EnablePiece();
            deck1_d->EnablePiece();
            deck1_e->EnablePiece();
            deck1_f->EnablePiece();
            deck1_g->EnablePiece();
            deck1_h->EnablePiece();
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/noahArkDeck1Done.mp3",false);
            SoundManager::sharedSoundManager()->playSoundEffect("Sound/Scene 9/magic_flourish_05.mp3",false);
           
        }
        else
            this->PlayPieceCorrect();
    }
}