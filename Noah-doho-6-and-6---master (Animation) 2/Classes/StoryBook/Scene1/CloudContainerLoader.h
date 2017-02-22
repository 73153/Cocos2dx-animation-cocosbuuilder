#ifndef _CloudContainerLoader_H_
#define _CloudContainerLoader_H_

#include "CloudContainer.h"

/* Forward declaration. */
class CCBReader;
class CloudContainerLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CloudContainerLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CloudContainer);
};
#endif
