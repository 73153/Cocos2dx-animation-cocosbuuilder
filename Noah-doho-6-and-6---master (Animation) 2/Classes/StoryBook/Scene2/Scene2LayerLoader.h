//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene2LayerLoader_h
#define Scene2LayerLoader_h
#include "../Scene2/Scene2Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene2LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene2LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene2Layer);
};
#endif