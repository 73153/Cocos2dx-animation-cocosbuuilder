#ifndef _CitiesLoader_H_
#define _CitiesLoader_H_

#include "Cities.h"

/* Forward declaration. */
class CCBReader;
class CitiesLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CitiesLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Cities);
};
#endif
