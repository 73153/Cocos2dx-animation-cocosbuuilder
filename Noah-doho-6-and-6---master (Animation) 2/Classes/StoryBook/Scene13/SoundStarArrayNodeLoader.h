#ifndef _SoundStarArrayNodeLoader_H_
#define _SoundStarArrayNodeLoader_H_

#include "SoundStarArrayNode.h"

/* Forward declaration. */
class CCBReader;
class SoundStarArrayNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SoundStarArrayNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SoundStarArrayNode);
};
#endif
