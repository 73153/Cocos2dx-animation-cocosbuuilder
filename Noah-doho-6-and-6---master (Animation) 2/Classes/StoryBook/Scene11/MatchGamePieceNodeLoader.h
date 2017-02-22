#ifndef _MatchGamePieceLoader_H_
#define _MatchGamePieceLoader_H_

#include "MatchGamePiece.h"

/* Forward declaration. */
class CCBReader;
class MatchGamePieceLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MatchGamePieceLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MatchGamePiece);
};
#endif
