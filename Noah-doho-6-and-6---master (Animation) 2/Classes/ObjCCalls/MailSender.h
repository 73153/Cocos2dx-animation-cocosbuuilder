//
//  MailSender.h
//  GetSocial
//
//  Created by Mikel Eizagirre on 24/03/13.
//
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "AppController.h"
#import "../../Classes/GameManager/GameManager.h"
@interface MailSender : UIViewController <MFMailComposeViewControllerDelegate>
{
    UIViewController *currentModalViewController;
}
- (void) sendMailUsingInAppMailer:(const char *)score _for:(emailType )type;
- (void) sendMailUsingExternalApp:(const char *)score _for:(emailType )type;

@end
