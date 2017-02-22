//
//  GameManager.cpp
//  Noah360univarsal
//  Created by Neil D on 17/09/13.
#include "GameManager.h"
#include  "../GameManager/common_function.h"
#include "../SoundManager/SoundManager.h"
#include "../AppMacros.h"
// iOS Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "../ObjCCalls/ObjCCalls.h"

#endif
// Android Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "../JNICalls/InterfaceJNI.h"
#endif
#include "../HomeScreen/homeLayerLoader.h"
#include "../StoryBook/Scene1/Scene1LayerLoader.h"
#include "../StoryBook/Scene1/CloudContainerLoader.h"
#include "../StoryBook/Scene2/Scene2LayerLoader.h"
#include "../StoryBook/Scene2/WikedCityLoader.h"
#include "../StoryBook/Scene2/WickedFireLoader.h"
#include "../StoryBook/Scene3/Scene3LayerLoader.h"
#include "../StoryBook/Scene4/Scene4LayerLoader.h"
#include "../StoryBook/Scene5/Scene5LayerLoader.h"
#include "../StoryBook/Scene6/Scene6LayerLoader.h"
#include "../StoryBook/Scene6/ArkCompareNodeLoader.h"
#include "../StoryBook/Scene7/Scene7LayerLoader.h"
#include "../StoryBook/Scene7/DreamFloadCityLoader.h"
#include "../StoryBook/Scene7/DreamFloadWaterLoader.h"
#include "../StoryBook/Scene7/DreamFloadBackLoader.h"
#include "../StoryBook/Scene8/Scene8LayerLoader.h"
#include "../StoryBook/Scene9/Scene9LayerLoader.h"
#include "../StoryBook/Scene10/Scene10LayerLoader.h"
#include "../StoryBook/Scene10/BoardingTheArkNodeLoader.h"
#include "../StoryBook/Scene11/Scene11LayerLoader.h"
#include "../StoryBook/Scene11/MatchGameNodeLoader.h"
#include "../StoryBook/Scene12/Scene12LayerLoader.h"
#include "../StoryBook/Scene12/RainCloudNodeLoader.h"
#include "../StoryBook/Scene13/Scene13LayerLoader.h"
#include "../StoryBook/Scene14/Scene14LayerLoader.h"
#include "../StoryBook/Scene15/Scene15LayerLoader.h"
#include "../StoryBook/Scene16/Scene16LayerLoader.h"
#include "../StoryBook/Scene17/Scene17LayerLoader.h"
#include "../StoryBook/Scene18/Scene18LayerLoader.h"
#include "../StoryBook/Scene18/BandSoundStarArrayNodeLoader.h"
#include "../StoryBook/Scene19/Scene19LayerLoader.h"

using namespace std;
using namespace cocos2d;
CCScene* GameManager::get_scene_at(int nIndex)
{
    this->setcurrent_scene(nIndex);
    switch(nIndex)
    {
        case 1:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene1Layer.ccbi","Scene1Layer" ,Scene1LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 2:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene2Layer.ccbi","Scene2Layer" ,Scene2LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 3:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene3Layer.ccbi","Scene3Layer" ,Scene3LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 4:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene4Layer.ccbi","Scene4Layer" ,Scene4LayerLoader::loader(), CCScene::create(),true,true);
            }
        case 5:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene5Layer.ccbi","Scene5Layer" ,Scene5LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 6:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene6Layer.ccbi","Scene6Layer" ,Scene6LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 7:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene7Layer.ccbi","Scene7Layer" ,Scene7LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 8:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene8Layer.ccbi","Scene8Layer" ,Scene8LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 9:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene9Layer.ccbi","Scene9Layer" ,Scene9LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 10:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene10Layer.ccbi","Scene10Layer" ,Scene10LayerLoader::loader(), CCScene::create(),true,true);
            }
        case 11:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene11Layer.ccbi","Scene11Layer" ,Scene11LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 12:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene12Layer.ccbi","Scene12Layer" ,Scene12LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 13:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene13Layer.ccbi","Scene13Layer" ,Scene13LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 14:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
         return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene13Layer.ccbi","Scene13Layer" ,Scene13LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 15:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene15Layer.ccbi","Scene15Layer" ,Scene15LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 16:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene16Layer.ccbi","Scene16Layer" ,Scene16LayerLoader::loader(), CCScene::create(),true,true);
        }
        case 17:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            switch (this->get_devise_resolution())
            {
                case 1:
                     return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer.ccbi","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                    break;
                case 2:
                if (CCDirector::sharedDirector()->getWinSize().width==1136)
                {
                      return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer_iphone","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                }
                else
                {
                     return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer.ccbi","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                }
                    break;
                case 3:
                {
                    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                        return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer_iphone.ccbi","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                          return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer.ccbi","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                   #endif
                  
                }
                    break;
                case 4:
                    return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene17Layer_iphone.ccbi","Scene17Layer" ,Scene17LayerLoader::loader(), CCScene::create(),true,true);
                    break;
                default:
                    break;
            }
        }
        case 18:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            switch (this->get_devise_resolution())
            {
                case 1:
                    return  GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    break;
                case 2:
                    if (CCDirector::sharedDirector()->getWinSize().width==1136)
                    {
                       return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer_iphone5.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    }
                    else
                    {
                        CCLOG("iphone 4 size");
                       return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    }
                    break;
                    
                case 3:
                    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    #endif
                            break;


                  
                case 4:
                   return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene18Layer.ccbi","Scene18Layer" ,Scene18LayerLoader::loader(), CCScene::create(),true,true);
                    break;
                default:
                    break;
            }
        }
        case 19:
        {
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            return GameManager::sharedGameManager()->get_scene("StoryCCBFiles/Scene19Layer.ccbi","Scene19Layer" ,Scene19LayerLoader::loader(), CCScene::create(),true,true);
        }
        default:
        {
           CCLog("index:%d",nIndex);
           current_scene=nIndex;
           return GameManager::sharedGameManager()->get_scene("HomeLayer.ccbi","HomeLayer",HomeLayerLoader::loader(), CCScene::create(),false,false);
        }
    }
    return NULL;
}
//All static variables need to be defined in the .cpp file
//I've added this following line to fix the problem
GameManager* GameManager::m_mySingleton = NULL;
GameManager::GameManager():current_scene(0),wasInitialized(false),noahCounter(0),current_layer(NULL)
{
 
}
GameManager* GameManager::sharedGameManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new GameManager();
    }
    //Return the singleton object
    return m_mySingleton;
}
void GameManager::initialize()
{
    platForm = CCApplication::sharedApplication()->getTargetPlatform();
    if (!wasInitialized)
    {
        wasInitialized = true;
        this->mutedNarrator=CCUserDefault::sharedUserDefault()->getBoolForKey("mutedNarrator");
        this->mutedFX=CCUserDefault::sharedUserDefault()->getBoolForKey("mutedFX");
        this->social=CCUserDefault::sharedUserDefault()->getBoolForKey("social");
        this->points=CCUserDefault::sharedUserDefault()->getIntegerForKey("NOAHPOINTS");
        this->level=CCUserDefault::sharedUserDefault()->getIntegerForKey("NOAHLEVEL");
        this->arkHits=CCUserDefault::sharedUserDefault()->getIntegerForKey("NOAHARKHITS");
        this->is_upgraded();
        if (level == 0)
        {
            level = 1;
            arkHits = 2;
            CCUserDefault::sharedUserDefault()->setIntegerForKey("NOAHLEVEL", level);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("NOAHARKHITS",arkHits);
            CCUserDefault::sharedUserDefault()->flush();

        }
        gameLanguage =CCString::createWithFormat("%s",CCUserDefault::sharedUserDefault()->getStringForKey("GAMELANGUAGE", EnglishLang).c_str());
        this->read_data();
    }
}
void GameManager::read_data()
{
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "text.plist";
    if (CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    {
        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
        dict->retain();
       // starStoreElements=CCArray::create();
        CCLOG("%d",dict->allKeys()->count());
        starStoreElements=(CCArray*)dict->objectForKey("array");
        CCLOG("%d",starStoreElements->count());
    }
    else
    {
        starStoreElements=CCArray::createWithContentsOfFileThreadSafe("Published-iOS/aStarStoreItems.plist");
        CCDictionary *root = CCDictionary::create();
        root->setObject(starStoreElements, "array");
        if(root->writeToFile(fullPath.c_str()))
        {
           CCLog("see the plist file at %s", fullPath.c_str());
        }
        else
        {
           CCLog("write plist file failed");
       }
        CCLog("external file path = %s", fullPath.c_str());
    }
}
#pragma mark -
#pragma mark Scene manager
#pragma mark -
CCScene* GameManager::get_scene(const char *pCCBFilename,const char *pCCNodename,CCNodeLoader *pCCNodeLoader,CCObject *objowner,bool hasfooter,bool hasheader)
{
    CCNode *layer = NULL;
    map<string, CCNodeLoader*> loader_map;
    if (hasfooter)
        loader_map.insert(make_pair("FooterLayer", FooterLayerLoader::loader()));
    if (hasheader)
        loader_map.insert(make_pair("HeaderLayer", HeaderLayerLoader::loader()));
    loader_map.insert(make_pair(pCCNodename, pCCNodeLoader));
    if (this->getcurrent_scene().getValue()==6)
    {
        loader_map.insert(make_pair("ArkCompareNode", ArkCompareNodeLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==7)
    {
        loader_map.insert(make_pair("DreamFloadBack", DreamFloadBackLoader::loader()));
        loader_map.insert(make_pair("DreamFloadCity", DreamFloadCityLoader::loader()));
        loader_map.insert(make_pair("DreamFloadWater", DreamFloadWaterLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==10)
    {
        loader_map.insert(make_pair("BoardingTheArkNode", BoardingTheArkNodeLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==12)
    {
        loader_map.insert(make_pair("RainCloudNode", RainCloudNodeLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==11)
    {
        loader_map.insert(make_pair("MatchGameNode", MatchGameNodeLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==2)
    {
       loader_map.insert(make_pair("WikedCity", WikedCityLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==18)
    {
        loader_map.insert(make_pair("BandSoundStarArrayNode", BandSoundStarArrayNodeLoader::loader()));
       //  loader_map.insert(make_pair("BandSoundStarsNode", BandSoundStarsNodeLoader::loader()));
    }
    if (this->getcurrent_scene().getValue()==1)
    {
        loader_map.insert(make_pair("CloudContainer", CloudContainerLoader::loader()));
    }
    layer = loadCCBFile(pCCBFilename, loader_map);
    current_layer=(CCNode*)layer;
    /* Read a ccbi file. */
    CCScene * scene = CCScene::create();
    if(layer != NULL)
    {
        scene->addChild(layer);
        if (hasfooter)
        {
            _footer=(FooterLayer*)layer->getChildByTag(555);
            layer->reorderChild(_footer, 400);
        }
        if (hasheader)
        {
            _header=(HeaderLayer*)layer->getChildByTag(444);
            layer->reorderChild(_header, 400);
        }
    }

    return scene;
}
bool GameManager::gotoNextScene()
{
    int kscene=this->getcurrent_scene().getValue();
    CCScene *splash_scene=this->get_scene_at(++kscene);
    //push transition...
    if (kscene==11||kscene==18||kscene==19)
        CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.5f, splash_scene));
    else
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, splash_scene, false));
    return true;
}
bool GameManager::gotoPreviousScene()
{
    int kscene=this->getcurrent_scene().getValue();
    CCScene *splash_scene=this->get_scene_at(--kscene);
    
    if (kscene==10||kscene==18||kscene==17)
        CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::create(0.5f, splash_scene));
    else
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, splash_scene, true));
    
    
    return false;
}
bool GameManager::gotoScene(CCInteger index_scene)
{
    CCLog("Go to scene");
    int kscene=index_scene.getValue();
    SoundManager::sharedSoundManager()->loadSondEffect(kscene);
    CCLog("Sound Loaded");
    CCScene *splash_scene=this->get_scene_at(kscene);
    CCLog("Get Scene");
    CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(0.5f, splash_scene));

    return true;
}
#pragma mark -
#pragma mark Footer manager
#pragma mark -
//It will contain Changing Narrator text
//implement sound for narrator
static std::string narrator_list[] =
{
    "Long ago and far away, God rumbled in the sky.\n Those he made, disobeyed, were wicked and were sly.",
    "God's heart was filled with pain.",
    "All were wicked. All but one. A quiet man, a faithful son.\n His name was Noah, he stood alone. “It seemed the worst he'd ever known.”",
    "false",
    "Build me an ark, a big boat for the sea,\n and in it I'll save your whole family.",
    "“Why so big, Lord, for such a small crew?\n And where is the sea to sail the ark to?”",
    "“I must wash the world clean, with a storm from the sky.\n But you and the animals will be safe and dry.”",
    "false",
    "Noah warned them to change, “It's almost too late!” \nBut nobody listened and they suffered their fate.",
    "Two by two each pair came through,\n crocodile, camel and kangaroo.\n Porcupines, pelicans, possums and pigs,\n and bunches of bugs that looked like small twigs.",
    "false",
    "Then it rained, and rained, and rained, and ",
    "false",
    "Everyone's in, God shut the door with a THUD!\n And all the earth came under the flood.",
    "Days, weeks, months, a year,\n finally the journey's end was near.",
    "Noah sent birds out to find dry land,\n the one who returned put a branch in his hand.",
    "Landing the ark was AMAZING for Noah...\n Orangutans tried to hi-five the boa!",
    "false",
    "“I give you a gift and I want you to know,\n I'll keep my promise with this RAINBOW!!!”",
};
CCString* GameManager::get_narrator_text()
{
    int index=current_scene.getValue();
    CCString *str=NULL;
    if (
        (index==10&&CCDirector::sharedDirector()->getWinSize().width==1136)
        ||(index==10&&CCDirector::sharedDirector()->getWinSize().width==960&&CCDirector::sharedDirector()->getWinSize().height==640)||(index==10&&CCDirector::sharedDirector()->getWinSize().height<768))
    {
        str =CCString::createWithFormat("%s","Two by two each pair came through, crocodile, camel and kangaroo.\n Porcupines, pelicans, possums and pigs, and bunches of bugs that looked like small twigs.");
    }
    else
        str =CCString::createWithFormat("%s",(narrator_list[index-1]).c_str());
    return str;
}
bool GameManager::set_footer_text(int scene_no)
{
    if (this->get_narrator_text())
    {
        _footer->getlbl_narrator_text()->setString(this->get_narrator_text()->getCString());
        return true;
    }
    else
        return false;
    
}
#pragma mark -
#pragma mark social sharing
#pragma mark -
bool GameManager::tryIsInternetConnection()
{
    CCLog("HelloWorld: tryIsInternetConnection");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return InterfaceJNI::isInternetConnected();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return ObjCCalls::tryIsInternetConnection();
#endif
}
void GameManager::trySendAnEmail(emailType type)
{
    if (this->tryIsInternetConnection())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        InterfaceJNI::postMessageEMail();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        ObjCCalls::trySendAnEMail("FeedBack on Noah 360!",true,type);
#endif
    }
    else
    {
        this->updateMessageLabel("No internet connection to send an email");
    }
}
void GameManager::gift_an_app()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        ObjCCalls::gift_App();
    #endif
}
void  GameManager::trySendAnEmailInApp(emailType type)
{
    CCLog("HelloWorld: try to send an email");
    if (this->tryIsInternetConnection())
    {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                // Making...
        #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                ObjCCalls::trySendAnEMail("This is a Test Email",true,type);
        #endif
    }
    else
    {
        this->updateMessageLabel("No internet connection to send an email");
    }
}
void GameManager::trySendATweet()
{
    if(this->tryIsInternetConnection())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        InterfaceJNI::postMessageToTweet();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        ObjCCalls::trySendATweet("This is a Test Twitt.");
#endif
    }
    else
    {
        this->updateMessageLabel("No internet connection to send a Tweet");
    }
}
void  GameManager::tryPostOnFB()
{
    CCLog("HelloWorld: try to post on Facebook");
    if (this->tryIsInternetConnection())
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        InterfaceJNI::postMessageToFB();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        ObjCCalls::tryPostOnFB("This is a Test post on FB");
#endif
    }
    else
    {
        this->updateMessageLabel("No internet connection to post on Facebook");
    }
}
CCString* GameManager::updateMessageLabel(const char *status)
{
    return CCString::create(status);
}
#pragma mark -
#pragma mark utilities methods
#pragma mark -
bool GameManager::isNodeAtPoint(cocos2d::CCNode* node, cocos2d::CCPoint& touchLocation)
{
    CCPoint nodePoint = node->convertToNodeSpace(touchLocation);
    CCRect rect = CCRectMake(0, 0, node->getContentSize().width, node->getContentSize().height);
    return rect.containsPoint(nodePoint);
}
int GameManager::get_devise_resolution()
{
    return resolution_type;
}
void GameManager::set_devise_resolution(int resolution)
{
    resolution_type=resolution;
}
CCArray* GameManager::shuffle_array(CCArray *pArray, unsigned int nLen)
{
    int i;
    for( i = nLen - 1; i >= 0; i-- )
    {
        unsigned int j = rand() % (i+1);
        CCObject *tempobj = pArray->objectAtIndex(i);
        pArray->exchangeObject(tempobj, pArray->objectAtIndex(j));
    }
    return pArray;
}
bool GameManager::isTouchOnArea(CCPoint touch ,CCPoint center,float width,float height)
{
    if (CCRectMake(center.x-width/2, center.y-height/2, width, height).containsPoint(touch))
    {
        return true;
    }
    return false;
}
bool GameManager::isTouchOnAreaFromGimp(CCPoint touch ,CCPoint center,float width,float height)
{
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
	if(CCRectMake(center.x, screenSize.height - center.y - height, width, height).containsPoint(touch))
		return true;
	else
        return false;
   
}

void GameManager::remove_unused_data()
{
    SoundManager::sharedSoundManager()->stopAllEffect();
    SoundManager::sharedSoundManager()->unLoadSoundEffect(GameManager::sharedGameManager()->getcurrent_scene().getValue());
    SoundManager::sharedSoundManager()->stopNarrator();
    SoundManager::sharedSoundManager()->stopBackgroundSound();
    _header->unscheduleAllSelectors();
    _header->stopAllActions();
    CCLayer *layer=(CCLayer*)this->current_layer;
    layer->setTouchEnabled(false);
    this->current_layer->stopAllActions();
    this->current_layer->unscheduleAllSelectors();
    this->current_layer->removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    CCAnimationCache::purgeSharedAnimationCache();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCDirector::sharedDirector()->purgeCachedData();
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
}
#pragma mark -
#pragma mark StoreElement
#pragma mark -
void GameManager::saveMutedFX(bool mute)
{
    this->mutedFX = mute;
    CCUserDefault::sharedUserDefault()->setBoolForKey("mutedFX", mute);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::saveSocial(bool mute)
{
    this->social = mute;
    CCUserDefault::sharedUserDefault()->setBoolForKey("social", mute);
    CCUserDefault::sharedUserDefault()->flush();
}
bool GameManager::getSocial()
{
    return  CCUserDefault::sharedUserDefault()->getBoolForKey("social");
}
void GameManager::saveMutedNarrator(bool mute)
{
    this->mutedNarrator = mute;
    CCUserDefault::sharedUserDefault()->setBoolForKey("mutedNarrator", mute);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::AddPoints(int morePoints)
{
    points += morePoints;
    if (points >= 99999)
    {
        points = 99999;
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey("NOAHPOINTS",points);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::SetLanguage(CCString* newLanguage)
{
    gameLanguage = newLanguage;
    CCUserDefault::sharedUserDefault()->setStringForKey("GAMELANGUAGE", newLanguage->m_sString);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::AddArkTouch()
{
    arkHits--;
    if (arkHits<0)
        arkHits=0;
    
    if (arkHits == 0)
    {
        if (level < 10)
        {
            level ++;
            switch (level)
            {
                case 2:
                    arkHits = 2;
                    break;
                case 3:
                    arkHits = 15;
                    break;
                case 4:
                    arkHits = 30;
                    break;
                case 5:
                    arkHits = 50;
                    break;
                case 6:
                    arkHits = 75;
                    break;
                case 7:
                    arkHits = 100;
                    break;
                case 8:
                    arkHits = 130;
                    break;
                case 9:
                    arkHits = 160;
                    break;
                case 10:
                    arkHits = 200;
                    break;
                default:
                    arkHits = 1;
                    break;
            }
        }
    }
    _header->getlbl_ark_tap()->setString(CCString::createWithFormat("%d",this->arkHits)->getCString());
    _header->getlbl_current_level()->setString(CCString::createWithFormat("%d",this->level)->getCString());
    CCUserDefault::sharedUserDefault()->setIntegerForKey("NOAHLEVEL",level);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("NOAHARKHITS",arkHits);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::SelectStarStoreElementAtIndex(int index)
{
    CCDictionary *element=(CCDictionary*)starStoreElements->objectAtIndex(index);
    element->setObject(CCString::createWithFormat("%d",elementStatusBoughtSelected), "status");
    starStoreElements->replaceObjectAtIndex(index,element);
    CCDictionary *root = CCDictionary::create();
    root->setObject(starStoreElements, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "text.plist";

    if(root->writeToFile(fullPath.c_str()))
        CCLog("see the plist file at %s", fullPath.c_str());
    else
        CCLog("write plist file failed");
}
void GameManager::UnselectStarStoreElementAtIndex(int index)
{
    CCDictionary *element=(CCDictionary*)starStoreElements->objectAtIndex(index);
    element->setObject(CCString::createWithFormat("%d",elementStatusBoughtUnselected), "status");
    starStoreElements->replaceObjectAtIndex(index,element);
    CCDictionary *root = CCDictionary::create();
    root->setObject(starStoreElements, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "text.plist";
    if(root->writeToFile(fullPath.c_str()))
        CCLog("see the plist file at %s", fullPath.c_str());
    else
        CCLog("write plist file failed");

}
bool GameManager::GetAchievmentIsActive(int achievmentID)
{
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(this->starStoreElements,pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        CCString *str_Id=(CCString*)dict->objectForKey("id");
        CCString *str_status=(CCString*)dict->objectForKey("status");
        int groud_id=atoi(str_Id->getCString());
        int status_id=atoi(str_status->getCString());
        if (groud_id==achievmentID&&status_id==elementStatusBoughtSelected)
        {
            return true;
        }
    }
    return false;
}
CCString * GameManager::GetExclusiveName(int exclusiveGroupId)
{
    if (exclusiveGroupId == 0)
    {
        return CCString::create("");
    }
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(this->starStoreElements,pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        CCString *str_exclusiveGroupId=(CCString*)dict->objectForKey("exclusiveGroupId");
        CCString *str_status=(CCString*)dict->objectForKey("status");
        int groud_id=atoi(str_exclusiveGroupId->getCString());
        int status_id=atoi(str_status->getCString());
        if (groud_id==exclusiveGroupId&&status_id==elementStatusBoughtSelected)
        {
            CCString *str_filename=(CCString*)dict->objectForKey("fileName");
            return  str_filename;
        }
    }
    return CCString::create("");
}
CCString * GameManager::GetGroupAchievmentIsActiveFileName(int groupId)
{
    if (groupId == 0)
    {
        return  CCString::createWithFormat("");
    }
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(this->starStoreElements,pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        CCString *str_groupid=(CCString*)dict->objectForKey("groupId");
        CCString *str_status=(CCString*)dict->objectForKey("status");
        int groud_id=atoi(str_groupid->getCString());
        int status_id=atoi(str_status->getCString());
        if (groud_id==groupId&&status_id==elementStatusBoughtSelected)
        {
            CCString *str=(CCString*)dict->objectForKey("fileName");
            return str;
        }
    }
    return CCString::createWithFormat("");
}
int GameManager::GetGroupAchievmentIsActiveStars(int groupId)
{
    if (groupId == 0)
    {
        return 5;
    }
    CCObject *pobj=NULL;
    CCARRAY_FOREACH(this->starStoreElements,pobj)
    {
        CCDictionary *dict=(CCDictionary*)pobj;
        CCString *str_groupid=(CCString*)dict->objectForKey("groupId");
        CCString *str_status=(CCString*)dict->objectForKey("status");
        int groud_id=atoi(str_groupid->getCString());
        int status_id=atoi(str_status->getCString());
        if (groud_id==groupId&&status_id==elementStatusBoughtSelected)
        {
            CCString *str_id=(CCString*)dict->objectForKey("starsGiven");
            return  atoi(str_id->getCString());
        }
    }
    return 5;
}
int GameManager::GetGroupAchievmentIsActive(int groupId)
{
    if (groupId == 0)
    {
        return -1;
    }
    for (int i=0; i<starStoreElements->count(); i++)
    {
        CCDictionary *dict=(CCDictionary*)starStoreElements->objectAtIndex(i);
        int groud_id=atoi(dict->valueForKey("groupId")->getCString());
        int status_id=atoi(dict->valueForKey("status")->getCString());
        if (groud_id==groupId&&status_id==elementStatusBoughtSelected)
        {
            return dict->valueForKey("id")->intValue();
        }
    }
    return -1;
}
void GameManager::AddPoints(int morePoints,CCPoint pos,CCNode *node)
{
    CCParticleSystemQuad* starExplosion= CCParticleSystemQuad::create("starExplosion.plist");
    starExplosion->retain();
    starExplosion->setAutoRemoveOnFinish(true);
    starExplosion->setPosition(pos);
    if (morePoints == 0)
    {
        starExplosion->setTotalParticles(20);
    }
    else
    {
        this->AddPoints(morePoints);
        starExplosion->setTotalParticles(morePoints*20);
         _header->getlblpoints()->setString(CCString::createWithFormat("%d",this->points)->getCString());
    }
    node->addChild(starExplosion,100);
    if (SoundManager::sharedSoundManager()->isEffectPlaying(point_sound))
    {
        SoundManager::sharedSoundManager()->stopSoundEffect(point_sound);
    }
    point_sound=SoundManager::sharedSoundManager()->playSoundEffect("Sound/playful_sweep_20.mp3", false);
}
int GameManager::BuyStarStoreElementAtIndex(int index)
{
    return 0;
}
bool GameManager::is_upgraded()
{
    return CCUserDefault::sharedUserDefault()->getBoolForKey("full_access", false);
}
void GameManager::upgraded_app()
{
    CCUserDefault::sharedUserDefault()->setBoolForKey("full_access", true);
}
bool GameManager::is_next_scene_available(int destination_scene)
{
    if (GameManager::sharedGameManager()->is_upgraded())
    {
        return true;
    }
    //freemium version has access to scene 1,2,3,13,0
    switch (destination_scene)
    {
        case 0:
            is_previous_accessible=true;
            is_next_accessible=true;
            return true;
            break;
        case 1:
            is_previous_accessible=true;
            is_next_accessible=true;
            return true;
            break;
        case 2:
            is_previous_accessible=true;
            is_next_accessible=true;
            return true;
            break;
        case 3:
            is_previous_accessible=true;
            is_next_accessible=false;
            return true;
        case 13:
            is_previous_accessible=false;
            is_next_accessible=false;
            return true;
        default:
            is_previous_accessible=false;
            is_next_accessible=false;
            break;
    }
    return false;
}