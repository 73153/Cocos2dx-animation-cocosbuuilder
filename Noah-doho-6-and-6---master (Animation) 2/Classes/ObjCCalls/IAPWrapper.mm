#import "IAPWrapper.h"

bool IAPWrapper::canMakePayments()
{
    return [[IAPHelper_objc sharedHelper] canMakePayments];
}

void IAPWrapper::requestProducts(iOSBridge::Callbacks::IAPCallback* callback)
{
    [[IAPHelper_objc sharedHelper] requestProductsWithCallback: callback];
}

void IAPWrapper::buyProductIdentifier(const std::string& productID)
{
    NSString *nsID = [NSString stringWithCString:productID.c_str()
                                        encoding:[NSString defaultCStringEncoding]];
    
    [[IAPHelper_objc sharedHelper] buyProductIdentifier:nsID];
}
