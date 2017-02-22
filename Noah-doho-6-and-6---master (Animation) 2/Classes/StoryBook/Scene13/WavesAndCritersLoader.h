#ifndef _WavesAndCritersLoader_H_
#define _WavesAndCritersLoader_H_

#include "WavesAndCriters.h"

/* Forward declaration. */
class CCBReader;
class WavesAndCritersLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WavesAndCritersLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WavesAndCriters);
};
#endif
