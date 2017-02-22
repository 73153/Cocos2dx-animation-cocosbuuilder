//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene1LayerLoader_h
#define Scene1LayerLoader_h
#include "../Scene1/Scene1Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene1LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene1LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene1Layer);
};
#endif


