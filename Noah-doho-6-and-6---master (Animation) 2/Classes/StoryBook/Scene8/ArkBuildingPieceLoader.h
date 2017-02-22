#ifndef _ArkBuildingPieceLoader_H_
#define _ArkBuildingPieceLoader_H_

#include "ArkBuildingPiece.h"

/* Forward declaration. */
class CCBReader;
class ArkBuildingPieceLoader : public cocos2d::extension::CCNodeLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ArkBuildingPieceLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ArkBuildingPiece);
};
#endif
