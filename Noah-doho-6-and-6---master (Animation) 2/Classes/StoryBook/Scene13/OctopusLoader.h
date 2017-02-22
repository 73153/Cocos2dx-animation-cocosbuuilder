#ifndef _OctopusLoader_H_
#define _OctopusLoader_H_

#include "Octopus.h"

/* Forward declaration. */
class CCBReader;
class OctopusLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OctopusLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Octopus);
};
#endif
