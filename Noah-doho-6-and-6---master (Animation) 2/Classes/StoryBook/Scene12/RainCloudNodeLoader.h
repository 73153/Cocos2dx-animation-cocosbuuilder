#ifndef _RainCloudNodeLoader_H_
#define _RainCloudNodeLoader_H_

#include "RainCloudNode.h"

/* Forward declaration. */
class CCBReader;
class RainCloudNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RainCloudNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RainCloudNode);
};
#endif
