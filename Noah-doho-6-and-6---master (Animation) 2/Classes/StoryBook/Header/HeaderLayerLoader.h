#ifndef _HeaderLayerLoader_H_
#define _HeaderLayerLoader_H_

#include "HeaderLayer.h"

/* Forward declaration. */
class CCBReader;
class HeaderLayerLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeaderLayerLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(HeaderLayer);
};
#endif
