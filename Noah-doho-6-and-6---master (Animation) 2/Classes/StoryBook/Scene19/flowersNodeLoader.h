#ifndef _flowersNodeLoader_H_
#define _flowersNodeLoader_H_

#include "flowersNode.h"

/* Forward declaration. */
class CCBReader;
class flowersNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(flowersNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(flowersNode);
};
#endif
