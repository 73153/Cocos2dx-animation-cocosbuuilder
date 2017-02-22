#ifndef _DreamFloadWaterLoader_H_
#define _DreamFloadWaterLoader_H_

#include "DreamFloadWater.h"

/* Forward declaration. */
class CCBReader;
class DreamFloadWaterLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DreamFloadWaterLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(DreamFloadWater);
};
#endif
