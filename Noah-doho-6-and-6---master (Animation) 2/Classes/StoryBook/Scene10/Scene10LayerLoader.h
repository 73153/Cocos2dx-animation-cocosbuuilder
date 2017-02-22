//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene10LayerLoader_h
#define Scene10LayerLoader_h
#include "../Scene10/Scene10Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene10LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene10LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene10Layer);
};
#endif