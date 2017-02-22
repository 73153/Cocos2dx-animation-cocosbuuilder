#ifndef _InstructionalNoaharkLoader_H_
#define _InstructionalNoaharkLoader_H_

#include "InstructionalNoahark.h"

/* Forward declaration. */
class CCBReader;
class InstructionalNoaharkLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InstructionalNoaharkLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(InstructionalNoahark);
};
#endif
