#ifndef _CliffsAndCloudsLoader_H_
#define _CliffsAndCloudsLoader_H_

#include "CliffsAndClouds.h"

/* Forward declaration. */
class CCBReader;
class CliffsAndCloudsLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CliffsAndCloudsLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CliffsAndClouds);
};
#endif
