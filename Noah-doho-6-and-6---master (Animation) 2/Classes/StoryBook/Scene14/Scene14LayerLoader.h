//
//  HelloCocosBuilderLayerLoader.h
//  Demo
//
//  Created by Neil D on 20/05/13.
//
//
#ifndef Scene14LayerLoader_h
#define Scene14LayerLoader_h
#include "../Scene14/Scene14Layer.h"
/* Forward declaration. */
class CCBReader;
class Scene14LayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scene14LayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Scene14Layer);
};
#endif