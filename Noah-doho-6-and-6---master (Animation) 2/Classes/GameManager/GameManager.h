//
//  GameManager.h
//  Noah360univarsal
//
//  Created by Neil D on 17/09/13.

#ifndef __Noah360univarsal__GameManager__
#define __Noah360univarsal__GameManager__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../StoryBook/Footer/FooterLayerLoader.h"
#include "../StoryBook/Header/HeaderLayerLoader.h"
#include "../StoryBook/Footer/FooterLayer.h"
#include "../StoryBook/Header/HeaderLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define EnglishLang "english"
#define SpanishLang "spanish"
#define SavedAppVersionCode "SavedAppVersion"
#define AppVersionCode "0.0.32"
#define elementStatusUnbought 1
#define elementStatusBoughtUnselected 2
#define elementStatusBoughtSelected 3
#define InkyAchievmentID 12
#define GuitarStarsAchievmentID 25
#define ForceFieldAchievmentID 11
#define GroupIDArks 1
#define GroupIDLoadingAnimals 2
#define GroupIDFishes 3
#define ExclusiveGroupIDArks 1
#define ExclusiveGroupIDStarSounds 2
#define screen_height  CCDirector::sharedDirector()->getWinSize().height
#define screen_width   CCDirector::sharedDirector()->getWinSize().width

typedef enum
{
    green,
    red,
    cloud
} branchType;
typedef enum
{
    TalktoUs,
    Feedback,
    share_mail
}emailType;
class GameManager
{
    private:
        //Constructor
        GameManager();
        //Instance of the singleton
        static GameManager* m_mySingleton;
    public:
        void initialize();
        //Get instance of singleton
        static GameManager* sharedGameManager();
        CC_SYNTHESIZE(FooterLayer*, _footer, _footer);
        CC_SYNTHESIZE(HeaderLayer*, _header, _header);
        CC_SYNTHESIZE(TargetPlatform , platForm, platForm);
        CC_SYNTHESIZE(CCInteger, current_scene,current_scene);
        bool set_footer_text(int scene_no);
        CC_SYNTHESIZE(CCNode*, current_layer, current_layer);
    
        CCScene* get_scene(const char *pCCBFilename,const char *pCCNodename,CCNodeLoader *pCCNodeLoader,CCObject *objowner,bool hasfooter,bool hasheader);
        CCScene* get_scene_at(int nIndex);  
        bool gotoNextScene();
        bool gotoPreviousScene();
        bool gotoScene(CCInteger index_scene);


        CCString *get_narrator_text();

        bool tryIsInternetConnection();
        void trySendAnEmail(emailType type);
        void trySendAnEmailInApp(emailType type);
        void trySendATweet();
        void tryPostOnFB();
        void gift_an_app();
    
    //memory management...
        void remove_unused_data();
    
        CCString* updateMessageLabel(const char *status);
        bool isNodeAtPoint(cocos2d::CCNode* node, cocos2d::CCPoint& touchLocation);
        bool isTouchOnArea(CCPoint touch ,CCPoint center,float width,float height);
        bool isTouchOnAreaFromGimp(CCPoint touch ,CCPoint center,float width,float height);
        int get_devise_resolution();
        void set_devise_resolution(int resolution);
        int resolution_type;
        CC_SYNTHESIZE(float, resolutionscale,resolutionscale);
        CCArray* shuffle_array(CCArray *pArray, unsigned int nLen);
    
        void read_data();
        bool initWithDictionary(CCDictionary *dictionary, const char *dirname);
    
        unsigned int point_sound;
        void AddPoints(int morePoints,CCPoint pos,CCNode *node);
        void AddPoints(int morePoints);
        void AddArkTouch();
        void SetLanguage(CCString* newLanguage);
        int BuyStarStoreElementAtIndex(int index);
        void SelectStarStoreElementAtIndex(int index);
        void UnselectStarStoreElementAtIndex(int index);
        bool GetAchievmentIsActive(int achievmentID);
        int GetGroupAchievmentIsActive(int groupId);
        CCString * GetGroupAchievmentIsActiveFileName(int groupId);
        int GetGroupAchievmentIsActiveStars(int groupId);
        CCString * GetExclusiveName(int exclusiveGroupId);
        void saveMutedFX(bool mute);
        void saveMutedNarrator(bool mute);
        void saveSocial(bool mute);
        bool getSocial();

    
    //paywall status
        bool is_upgraded();
        void upgraded_app();
        bool is_next_scene_available(int destination_scene);
        CC_SYNTHESIZE(bool, is_next_accessible,is_next_accessible);
        CC_SYNTHESIZE(bool, is_previous_accessible,is_previous_accessible);
    
    
    ///score stuff...
        CC_SYNTHESIZE(bool, wasInitialized, wasInitialized);
        CC_SYNTHESIZE_RETAIN(CCArray*, starStoreElements, starStoreElements);
        CC_SYNTHESIZE(int, noahCounter, noahCounter);
   
        CC_SYNTHESIZE(int, points, points);
        CC_SYNTHESIZE(int, level, level);
        CC_SYNTHESIZE(int, arkHits, arkHits);
        CC_SYNTHESIZE(CCString*, gameLanguage, gameLanguage);
        CC_SYNTHESIZE(bool, mutedFX, mutedFX);
        CC_SYNTHESIZE(bool, social, social);
        CC_SYNTHESIZE(bool, mutedNarrator, mutedNarrator);
    
    
    
    //in app purchase...
    //    void productsDownloaded(const std::vector& products);
   
};
#endif /* defined(__Noah360univarsal__GameManager__) */
