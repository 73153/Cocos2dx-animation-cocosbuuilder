#ifndef _SoundStarNodeLoader_H_
#define _SoundStarNodeLoader_H_

#include "SoundStarNode.h"

/* Forward declaration. */
class CCBReader;
class SoundStarNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SoundStarNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SoundStarNode);
};
#endif
