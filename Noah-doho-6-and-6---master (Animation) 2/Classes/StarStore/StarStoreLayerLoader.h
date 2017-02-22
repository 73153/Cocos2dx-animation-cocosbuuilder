//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Demo_StarStoreLayerLoader_h
#define Demo_StarStoreLayerLoader_h
#include "../StarStore/StarStoreLayer.h"
/* Forward declaration. */
class CCBReader;
class StarStoreLayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StarStoreLayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(StarStoreLayer);
};
#endif