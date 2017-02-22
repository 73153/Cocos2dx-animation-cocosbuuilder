#ifndef _FooterLayerLoader_H_
#define _FooterLayerLoader_H_

#include "FooterLayer.h"

/* Forward declaration. */
class CCBReader;
class FooterLayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FooterLayerLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(FooterLayer);
};
#endif
