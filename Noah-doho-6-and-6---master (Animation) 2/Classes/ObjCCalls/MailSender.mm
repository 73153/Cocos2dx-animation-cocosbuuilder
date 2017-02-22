//
//  MailSender.m
//  GetSocial
//
//  Created by Mikel Eizagirre on 24/03/13.
//
//

#import "MailSender.h"-
#import "../cocos2dx/platform/ios/EAGLView.h"


@implementation MailSender
-(void) sendMailUsingExternalApp:(const char *)score
{
    NSString *message = [NSString stringWithFormat:@"Check out this fantastic app about Noah! <a href=\"http://itunes.apple.com/us/app/noah-360-irresistible-interactive/id536774628?mt=8\">Noah 360 Irresistible Interactive</a>"];
    [self sendEmailTo:@""
               withCC:@""
              withBCC:@""
          withSubject:@"Great App!"
             withBody:message];
}
-(void)sendEmailTo:(NSString*)to withCC:(NSString*)cc withBCC:(NSString*)bcc withSubject:(NSString*)subject withBody:(NSString*)body
{
	NSString * url = [NSString stringWithFormat:@"mailto:?to=%@&cc=%@&bcc=%@&subject=%@&body=%@",
					  [to stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [cc stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [bcc stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [subject stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [body stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding]];
    
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}
- (void) sendMailUsingInAppMailer:(const char *)score _for:(emailType )type
{
   
    
    if ([MFMailComposeViewController canSendMail])
    {
        MFMailComposeViewController *mailer = [[MFMailComposeViewController alloc] init];
        mailer.mailComposeDelegate = self;
        NSString *emailBody;
       
        if (type==share_mail)
        {
           [mailer setSubject:@"Great App!"];
            emailBody = [NSString stringWithFormat:@"Check out this fantastic app about Noah! <a href=\"http://itunes.apple.com/us/app/noah-360-irresistible-interactive/id536774628?mt=8\">Noah 360 Irresistible Interactive</a>"];

        }
        else if (type==TalktoUs)
        {
            
            [mailer setToRecipients: [NSArray arrayWithObject: @"feedback@noah360.com"]];
             [mailer setSubject: @"FeedBack on Noah 360!"];
            emailBody=@" ";
         

        }
        else if (type==Feedback)
        {
            [mailer setToRecipients: [NSArray arrayWithObject: @"fallingscalesmedia@me.com"]];
            [mailer setSubject: @"FeedBack on Noah 360!"];
                        emailBody=@" ";

        }
        [mailer setMessageBody:emailBody isHTML:YES];
        AppController *app=(AppController*)[[UIApplication sharedApplication] delegate];
//        [app.viewController presentViewController:mailer animated:true completion:^{}];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Failure"
                                                        message:@"Your device doesn't support the composer sheet"
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
        [alert show];
        [alert release];
    }
}
- (void) sendMailUsingExternalApp:(const char *)score _for:(emailType )type
{


}
- (void)sendMailUsingInAppMailer:(const char *)score
{
   }
- (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error
{
    const char *message;
	switch (result)
	{
		case MFMailComposeResultCancelled:
			message = "Mail cancelled";
			break;
		case MFMailComposeResultSaved:
			message = "Mail saved";
			break;
		case MFMailComposeResultSent:
			message = "Mail send";
			break;
		case MFMailComposeResultFailed:
			message = "Mail failed";
			break;
		default:
            message = "Mail cancelled";
			break;
	}
    UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Mail"
                                                         message:[NSString stringWithCString:message encoding:NSASCIIStringEncoding] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [myalertView show];
    GameManager::sharedGameManager()->updateMessageLabel(message);
      AppController *app=(AppController*)[[UIApplication sharedApplication] delegate];
//	[app.viewController dismissViewControllerAnimated:true completion:^{}];
}
@end
