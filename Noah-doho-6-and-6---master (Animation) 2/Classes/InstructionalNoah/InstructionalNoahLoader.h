#ifndef _InstructionalNoahLoader_H_
#define _InstructionalNoahLoader_H_

#include "InstructionalNoah.h"

/* Forward declaration. */
class CCBReader;
class InstructionalNoahLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InstructionalNoahLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(InstructionalNoah);
};
#endif
