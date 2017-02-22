#ifndef _DreamFloadCityLoader_H_
#define _DreamFloadCityLoader_H_

#include "DreamFloadCity.h"

/* Forward declaration. */
class CCBReader;
class DreamFloadCityLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DreamFloadCityLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(DreamFloadCity);
};
#endif
