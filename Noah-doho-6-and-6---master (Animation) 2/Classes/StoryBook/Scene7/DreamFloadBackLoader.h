#ifndef _DreamFloadBackLoader_H_
#define _DreamFloadBackLoader_H_

#include "DreamFloadBack.h"

/* Forward declaration. */
class CCBReader;
class DreamFloadBackLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DreamFloadBackLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(DreamFloadBack);
};
#endif
