//PrintMessage.h
#ifndef __PRINTMESSAGE_H__
#define __PRINTMESSAGE_H__

#include <stddef.h>
#import "../GameManager/GameManager.h"
class ObjCCalls
{
public:
    static void trySendATweet(const char *score);
    static void trySendAnEMail(const char *score, bool usingInternalApp,emailType type);
    static void tryPostOnFB(const char *score);
    static bool tryIsInternetConnection();
    static bool gift_App();
};

#endif//__PRINTMESSAGE_H__