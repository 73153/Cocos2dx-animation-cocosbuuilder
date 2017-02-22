#include "ObjCCalls.h" 
#import "../cocos2dx/platform/ios/EAGLView.h" 
#import "TweetSender.h"
#import "Facebook.h"
#import "MailSender.h"
#import "Reachability.h"

void ObjCCalls::trySendATweet(const char *score)
{
    [TweetSender trySendATweet:score];
}

void ObjCCalls::trySendAnEMail(const char *score, bool usingInternalApp,emailType type)
{
    MailSender *mailSender = [MailSender alloc];
    if (usingInternalApp)
    {
        [mailSender sendMailUsingInAppMailer:score _for:type];
    }
    else
    {
        [mailSender sendMailUsingExternalApp:score _for:type];
    }
}
void ObjCCalls::tryPostOnFB(const char *score)
{
    [Facebook tryToPostOnFacebook:score];
}
bool ObjCCalls::tryIsInternetConnection()
{
    Reachability *networkReachability = [Reachability reachabilityForInternetConnection];
    NetworkStatus networkStatus = [networkReachability currentReachabilityStatus];
    return !(networkStatus == NotReachable);
}
bool ObjCCalls::gift_App()
{
    NSURL *appStoreURL = [NSURL URLWithString:@"itms-apps://itunes.apple.com/app/Noah-360/id536774628?mt=8"];
    [[UIApplication sharedApplication] openURL:appStoreURL];
    
    return true;
}