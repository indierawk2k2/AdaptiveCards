// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adaptivecards.djinni

#import "ACDjinniAdaptiveCard+Private.h"
#import "ACDjinniAdaptiveCard.h"
#import "ACDjinniBaseCardElement+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface ACDjinniAdaptiveCard ()

- (id)initWithCpp:(const std::shared_ptr<::AdaptiveCards::DjinniAdaptiveCard>&)cppRef;

@end

@implementation ACDjinniAdaptiveCard {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::AdaptiveCards::DjinniAdaptiveCard>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::AdaptiveCards::DjinniAdaptiveCard>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nonnull NSArray<ACDjinniBaseCardElement *> *)getItems {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getItems();
        return ::djinni::List<::djinni_generated::DjinniBaseCardElement>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto DjinniAdaptiveCard::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto DjinniAdaptiveCard::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<ACDjinniAdaptiveCard>(cpp);
}

}  // namespace djinni_generated

@end