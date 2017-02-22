#ifndef _MatchGameNodeLoader_H_
#define _MatchGameNodeLoader_H_

#include "MatchGameNode.h"

/* Forward declaration. */
class CCBReader;
class MatchGameNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MatchGameNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MatchGameNode);
};
#endif
