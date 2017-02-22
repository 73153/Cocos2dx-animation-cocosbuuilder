#ifndef xxx_IAPWrapper_h
#define xxx_IAPWrapper_h

#import "IAPHelper_objc.h"
#import "IAPCallback.h"

class IAPWrapper
{
public:
    // Some users might have IAP disabled
    bool canMakePayments();
    
    void requestProducts(iOSBridge::Callbacks::IAPCallback* callback);
    
    void buyProductIdentifier(const std::string& productID);
    
};

#endif