//
//  TweetSender.m
//  GetSocial
//
//  Created by Mikel Eizagirre on 24/03/13.
//
//

#import "TweetSender.h"
#import "../cocos2dx/platform/ios/EAGLView.h"
#import "../GameManager/GameManager.h"

@implementation TweetSender
/**
 * Try to send a tweet using iOS 5 automatically
 */
+(void) trySendATweet:(const char *)score
{
    SLComposeViewController  *mySocialComposer;
    UIViewController *myViewController;
    myViewController = [UIViewController alloc];
    EAGLView *view = [EAGLView sharedEGLView];
    [view addSubview:(myViewController.view)];
    mySocialComposer = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
    NSString *customMessage = [NSString stringWithFormat:@"Noah 360 - An Irresistible Interactive Children's Bible Story"];
    [mySocialComposer setInitialText:customMessage];
    [mySocialComposer addURL:[NSURL URLWithString:@"http://itunes.apple.com/us/app/noah-360-irresistible-interactive/id536774628?mt=8"]];
    [myViewController presentViewController:mySocialComposer animated:YES completion:nil];
    mySocialComposer.completionHandler = ^(SLComposeViewControllerResult result)
    {
        const char *message = "";
        switch (result)
        {
            case SLComposeViewControllerResultCancelled:
                message = "Tweet Cancelled";
                break;
            case SLComposeViewControllerResultDone:
                message = "Tweet Sent";
                
            default:
                break;
        
        }

        UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Twitter"
                                                             message:[NSString stringWithCString:message encoding:NSASCIIStringEncoding] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [myalertView show];
        GameManager::sharedGameManager()->updateMessageLabel(message);
        // Dismiss the controller
        [myViewController dismissViewControllerAnimated:true completion:^{}];
    };
}
@end
