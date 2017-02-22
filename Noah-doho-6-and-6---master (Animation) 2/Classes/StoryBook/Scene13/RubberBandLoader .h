#ifndef _RubberBandLoader_H_
#define _RubberBandLoader_H_

#include "RubberBand.h"

/* Forward declaration. */
class CCBReader;
class RubberBandLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RubberBandLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RubberBand);
};
#endif
