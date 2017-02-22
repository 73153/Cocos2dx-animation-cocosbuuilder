#ifndef _SquatingNoahLoader_H_
#define _SquatingNoahLoader_H_

#include "SquatingNoah.h"

/* Forward declaration. */
class CCBReader;
class SquatingNoahLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SquatingNoahLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SquatingNoah);
};
#endif
