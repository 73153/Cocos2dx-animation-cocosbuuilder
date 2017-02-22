#ifndef _ArkCompareNodeLoader_H_
#define _ArkCompareNodeLoader_H_

#include "ArkCompareNode.h"

/* Forward declaration. */
class CCBReader;
class ArkCompareNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ArkCompareNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ArkCompareNode);
};
#endif
