#ifndef _BandSoundStarArrayNodeLoader_H_
#define _BandSoundStarArrayNodeLoader_H_

#include "BandSoundStarArrayNode.h"

/* Forward declaration. */
class CCBReader;
class BandSoundStarArrayNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BandSoundStarArrayNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BandSoundStarArrayNode);
};
#endif
