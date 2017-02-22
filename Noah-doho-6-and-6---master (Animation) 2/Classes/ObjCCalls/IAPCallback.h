//
//  TweetSender.h
//  GetSocial
//
//  Created by Mikel Eizagirre on 24/03/13.
//
//


#ifndef xxx_IAPCallback_h
#define xxx_IAPCallback_h

#include "cocos2d.h"

using namespace cocos2d;

namespace iOSBridge
{
	namespace Callbacks
	{
		struct IAPItem
		{
			std::string identification;
			std::string name;
			std::string localizedTitle;
			std::string localizedDescription;
			float price;
		};
        
		class IAPCallback
		{
		public:
			//virtual void productsDownloaded(const std::vector& products) = 0;
		};
	}
}

#endif