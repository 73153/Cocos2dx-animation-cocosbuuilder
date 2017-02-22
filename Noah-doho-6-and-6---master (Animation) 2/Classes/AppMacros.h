#ifndef __APPMACROS_H__
#define __APPMACROS_H__
#include "cocos2d.h"
/* 
    For demonstrating using one design resolution to match different resources,
    or one resource to match different design resolutions.
 [Situation 1] Using one design resolution to match different resources.
     Please look into Appdelegate::applicationDidFinishLaunching.
     We check current device frame size to decide which resource need to be selected.
     So if you want to test this situation which said in title '[Situation 1]',
     you should change ios simulator to different device(e.g. iphone, iphone-retina3.5, iphone-retina4.0, ipad, ipad-retina),
     or change the window size in "proj.XXX/main.cpp" by "CCEGLView::setFrameSize" if you are using win32 or linux plaform
     and modify "proj.mac/AppController.mm" by changing the window rectangle.

   [Situation 2] Using one resource to match different design resolutions.
     The coordinates in your codes is based on your current design resolution rather than resource size.
     Therefore, your design resolution could be very large and your resource size could be small.
     To test this, just define the marco 'TARGET_DESIGN_RESOLUTION_SIZE' to 'DESIGN_RESOLUTION_2048X1536'
     and open iphone simulator or create a window of 480x320 size.

  [Note] Normally, developer just need to define one design resolution(e.g. 960x640) with one or more resources.
 */
//all ios device resolutions....
#define DESIGN_RESOLUTION_480X320    0
#define DESIGN_RESOLUTION_800X480    1
#define DESIGN_RESOLUTION_960X640    2
#define DESIGN_RESOLUTION_1024X768   3
#define DESIGN_RESOLUTION_2048X1536  4
/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_2048X1536
typedef struct tagResource
{
    cocos2d::CCSize size;
    cocos2d::CCSize sizeDesign;
    char directory[100];
}
Resource;
//1. xSmall (240x320)
//2. Small  (320x480)
//3. Medium (800x480)
//4. Large  (1024x768)
//5. xLarge (2048x1536)
//resource directory for iphone
static Resource resources_iphone    ={ cocos2d::CCSizeMake(480,320),cocos2d::CCSizeMake(480,320),"resources-iphone" };
static Resource resources_iphonehd  ={ cocos2d::CCSizeMake(960,640),cocos2d::CCSizeMake(960,640),   "resources-ipad" };
static Resource resPhoneRetina40    ={ cocos2d::CCSizeMake(1136, 640), cocos2d::CCSizeMake(568, 320), "resources-ipad" };
static Resource resources_Medium    ={ cocos2d::CCSizeMake(800,480), cocos2d::CCSizeMake(800,480),"resources-medium" };
static Resource resources_ipad      ={ cocos2d::CCSizeMake(1024, 768), cocos2d::CCSizeMake(1024, 768), "resources-ipad" };
static Resource resources_ipadhd    ={  cocos2d::CCSizeMake(2048, 1536), cocos2d::CCSizeMake(1024, 768),"resources-ipad" };
//resource directory for android
#if (TARGET_DESIGN_RESOLUTION_SIZE   == DESIGN_RESOLUTION_480X320)
    static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480,320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_800X480)
    static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(800,480);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_960X640)
//    static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(960,640);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
    static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1024,768);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_2048X1536)
    static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(2048,1536);
#else
    #error unknown target design resolution!
#endif
// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 48)
#endif 
/* __APPMACROS_H__ */