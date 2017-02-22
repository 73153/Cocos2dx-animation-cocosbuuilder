//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Demo_StarStoreNodeLoader_h
#define Demo_StarStoreNodeLoader_h
/* Forward declaration. */
#import "../StarStore/StarStoreNode.h"
class CCBReader;
class StarStoreNodeLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StarStoreNodeLoader, loader);
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(StarStoreNode);
};
#endif