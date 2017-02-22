//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene3LayerLoader_h
#define Scene3LayerLoader_h
#include "../Scene3/Scene3Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene3LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene3LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene3Layer);
};
#endif