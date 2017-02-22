//
//  TweetSender.m
//  GetSocial
//
//  Created by Mikel Eizagirre on 24/03/13.
//
//

#import "Facebook.h"
#import "../cocos2dx/platform/ios/EAGLView.h"
#import "../GameManager/GameManager.h"
@implementation Facebook
/**
 * Try to send a tweet using iOS 5 automatically
 */
+(void) tryToPostOnFacebook:(const char *)score
{
    NSLog(@"Try to post on facebook");
    SLComposeViewController  *mySocialComposer;
    UIViewController *myViewController;
    myViewController = [UIViewController alloc];
    EAGLView *view = [EAGLView sharedEGLView];
    [view addSubview:(myViewController.view)];
    mySocialComposer = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeFacebook];
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
                message = "Post Canceled";
                break;
            case SLComposeViewControllerResultDone:
                message = "Posted on Facebook";
                
            default:
                break;
        }
        UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Facebook"
                                                             message:[NSString stringWithCString:message encoding:NSASCIIStringEncoding] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [myalertView show];
        
        GameManager::sharedGameManager()->updateMessageLabel(message);
        // Dismiss the controller
        [myViewController dismissViewControllerAnimated:true completion:^{}];
    };
}
@end
