//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene7LayerLoader_h
#define Scene7LayerLoader_h
#include "../Scene7/Scene7Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene7LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene7LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene7Layer);
};
#endif