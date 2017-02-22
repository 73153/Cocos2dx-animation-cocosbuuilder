#include "AppDelegate.h"
#include "AppMacros.h"
#include <vector>
#include "../SplashVideo/AudioManager.h"
#include "../SplashVideo/Config.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
#include "../SoundManager/SoundManager.h"
#include "../SplashScreen/SplashLayer.h"
#include "../SplashScreen/SplashLayerLoader.h"
#include "../HomeScreen/HomeLayer.h"
#include "../HomeScreen/homeLayerLoader.h"
#include "../SplashVideo/WrapperClass.h"
USING_NS_CC;
using namespace CocosDenshion;
AppDelegate::AppDelegate()
{

}
AppDelegate::~AppDelegate()
{
    
}
bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    pDirector = CCDirector::sharedDirector();
    pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);
    pDirector->setProjection(kCCDirectorProjection2D);
    CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888);
    GameManager::sharedGameManager()->initialize();
    CCUserDefault::sharedUserDefault()->setBoolForKey("Tips",false);
    CCUserDefault::sharedUserDefault()->flush();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        Config::getConfig()->screenWidth = CCEGLView::sharedOpenGLView()->getFrameSize().width;
        Config::getConfig()->screenHeight = CCEGLView::sharedOpenGLView()->getFrameSize().height;
    #endif
    //pDirector->setDisplayStats(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    this->set_assets_path();
    pDirector->setAnimationInterval(1 / 60);
    //CCScene *home_scene=GameManager::sharedGameManager()->get_scene("SplashLayer.ccbi", "SplashLayer", SplashLayerLoader::loader(), CCScene::create(),false,false);
    CCScene *home_scene=GameManager::sharedGameManager()->get_scene("HomeLayer 2.ccbi", "HomeLayer", HomeLayerLoader::loader(), CCScene::create(),false,false);
   //CCScene *home_scene=GameManager::sharedGameManager()->get_scene_at(13);
    CCDirector::sharedDirector()->runWithScene(home_scene);
    return true;
}
//#warning change path for assets based on device resolution..
void AppDelegate::set_assets_path()
{
    //Set the design resolution
    //IMPORTANT LINE!!!
    CCSize frameSize = CCDirector::sharedDirector()->getWinSize();
    // Set the design resolution
    float scale_factor;
    vector<std::string> searchPaths;
    vector<std::string> resDirOrders;
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        searchPaths.push_back("Published-iOS");
        if(frameSize.height >=resources_ipadhd.size.height)
        {
            CCLog("retina ipad");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            
            GameManager::sharedGameManager()->set_devise_resolution(1);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.width >= resources_ipad.size.width)
        {
            CCLog("normal ipad");
            //searchPath.push_back(resources_ipad.directory);
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            GameManager::sharedGameManager()->set_devise_resolution(2);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        //if the frame's height is larger than the height of small resource size, select medium resource.
        else if (frameSize.width >= resources_iphonehd.size.width)
        {
            CCLog("retina ipod");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            if (frameSize.width>=1136)
            {
                 scale_factor=MIN(resources_iphonehd.size.height/frameSize.height, resources_iphonehd.size.width/frameSize.width);
            }
            else
            {
                scale_factor=MIN(resources_iphonehd.size.height/frameSize.height, resources_iphonehd.size.width/frameSize.width);
            }
            GameManager::sharedGameManager()->set_devise_resolution(3);
            pDirector->setContentScaleFactor(scale_factor);
        }
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
        {
            CCLog("normal ipod");
            //searchPaths.push_back("resources-ipad");
            //resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad"); 
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");

            scale_factor=MIN(resources_iphone.size.height/frameSize.height, resources_iphone.size.width/frameSize.width);
            GameManager::sharedGameManager()->set_devise_resolution(4);
            pDirector->setContentScaleFactor(scale_factor);
        }
        pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
    }
    else if (platform == kTargetAndroid )
    {
        searchPaths.push_back("Published-iOS");
        CCSize designSize = CCSizeMake(1024, 768);
        if(frameSize.height >= resources_ipad.size.height)
        {
            CCLog("retina ipad");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            GameManager::sharedGameManager()->set_devise_resolution(1);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        }
        else if (frameSize.height >= resources_ipad.size.height)
        {
            CCLog("normal ipad");
            //searchPath.push_back(resources_ipad.directory);
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            GameManager::sharedGameManager()->set_devise_resolution(2);
            scale_factor=MIN(resources_ipad.size.height/designSize.height, resources_ipad.size.width/designSize.width);
            pDirector->setContentScaleFactor(scale_factor);
              pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        }
        //if the frame's height is larger than the height of small resource size, select medium resource.
        else if(frameSize.height >= resources_iphonehd.size.height)
        {
            CCLog("retina ipod");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            if (frameSize.width>=1136)
            {
                scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            }
            else
            {
                scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            }
            
            GameManager::sharedGameManager()->set_devise_resolution(3);
            pDirector->setContentScaleFactor(scale_factor);
            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        }
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
        {
            CCLog("normal ipod");
            searchPaths.push_back("resources-ipad");
            resDirOrders.push_back("resources-ipad");
            searchPaths.push_back("Scene7/resources-ipad");
            resDirOrders.push_back("Scene7/resources-ipad");
            searchPaths.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("Scene15/resources-ipad");
            resDirOrders.push_back("noah_squashing/resources-ipad");
            searchPaths.push_back("noah_squashing/resources-ipad");
            //scale_factor=MIN(resources_ipadhd.size.height/frameSize.height, resources_ipadhd.size.width/frameSize.width);
            //scale_factor=MIN(resources_Medium.size.height/frameSize.height,resources_Medium.size.height/frameSize.width);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            GameManager::sharedGameManager()->set_devise_resolution(3);
            pDirector->setContentScaleFactor(scale_factor);
            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        }
    }
//    CCLog("GameManager::sharedGameManager()->")
    /*else if (platform == kTargetAndroid || platform == kTargetWindows)
    {
        searchPaths.push_back("Published-Android");
        if (frameSize.width > 720)
        {
            searchPaths.push_back("resources-large");
            resDirOrders.push_back("resources-large");
            scale_factor=MIN(resources_ipadhd.size.height/frameSize.height, resources_ipadhd.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (resources_Medium.size.width > 568)
        {
            searchPaths.push_back("resources-medium");
            resDirOrders.push_back("resources-medium");
            scale_factor=MIN(resources_Medium.size.height/frameSize.height, resources_Medium.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else
        {
            //resourceSize = CCSizeMake(568, 320);
            searchPaths.push_back("resources-small");
            resDirOrders.push_back("resources-small");
            scale_factor=MIN(resources_iphone.size.height/frameSize.height, resources_iphone.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
    }*/
    CCFileUtils::sharedFileUtils()->setSearchResolutionsOrder(resDirOrders);
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
}
//This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
//    CCDirector::sharedDirector()->stopAnimation();
//    CCDirector::sharedDirector()->pause();
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
//    CCDirector::sharedDirector()->stopAnimation();
//    CCDirector::sharedDirector()->resume();
//    CCDirector::sharedDirector()->startAnimation();
    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
