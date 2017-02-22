#ifndef _BandSoundStarsNodeLoader_H_
#define _BandSoundStarsNodeLoader_H_

#include "BandSoundStarsNode.h"

/* Forward declaration. */
class CCBReader;
class BandSoundStarsNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BandSoundStarsNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BandSoundStarsNode);
};
#endif
