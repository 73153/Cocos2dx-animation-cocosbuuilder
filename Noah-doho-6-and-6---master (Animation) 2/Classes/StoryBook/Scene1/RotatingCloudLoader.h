#ifndef _RotatingCloudLoader_H_
#define _RotatingCloudLoader_H_
#include "RotatingCloud.h"
/* Forward declaration. */
class CCBReader;
class RotatingCloudLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RotatingCloudLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RotatingCloud);
};
#endif
