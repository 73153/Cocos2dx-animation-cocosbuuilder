#ifndef _NoahAndDoveLoader_H_
#define _NoahAndDoveLoader_H_

#include "NoahAndDove.h"

/* Forward declaration. */
class CCBReader;
class NoahAndDoveLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NoahAndDoveLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(NoahAndDove);
};
#endif
