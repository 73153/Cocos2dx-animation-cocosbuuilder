#ifndef _ShipLoader_H_
#define _ShipLoader_H_

#include "Ship.h"

/* Forward declaration. */
class CCBReader;
class ShipLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ShipLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Ship);
};
#endif
