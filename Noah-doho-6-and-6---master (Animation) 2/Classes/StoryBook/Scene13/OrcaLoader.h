#ifndef _OrcaLoader_H_
#define _OrcaLoader_H_

#include "Orca.h"

/* Forward declaration. */
class CCBReader;
class OrcaLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OrcaLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Orca);
};
#endif
