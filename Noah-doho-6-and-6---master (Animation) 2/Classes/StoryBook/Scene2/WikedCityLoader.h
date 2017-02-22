#ifndef _WikedCityLoader_H_
#define _WikedCityLoader_H_

#include "WikedCity.h"

/* Forward declaration. */
class CCBReader;
class WikedCityLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WikedCityLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WikedCity);
};
#endif
