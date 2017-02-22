#ifndef _BoardingTheArkNodeLoader_H_
#define _BoardingTheArkNodeLoader_H_

#include "BoardingTheArkNode.h"

/* Forward declaration. */
class CCBReader;
class BoardingTheArkNodeLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BoardingTheArkNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BoardingTheArkNode);
};
#endif
