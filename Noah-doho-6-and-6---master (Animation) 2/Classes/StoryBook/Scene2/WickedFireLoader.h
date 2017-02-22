#ifndef _WickedFireLoader_H_
#define _WickedFireLoader_H_

#include "WickedFire.h"

/* Forward declaration. */
class CCBReader;
class WickedFireLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WickedFireLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WickedFire);
};
#endif
