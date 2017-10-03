#pragma once

#include "AdaptiveCards.Uwp.h"
#include "Enums.h"

namespace AdaptiveCards { namespace Uwp
{
    class AdaptiveShowCardActionRenderer :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        ABI::AdaptiveCards::Uwp::IAdaptiveActionRenderer>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Uwp_AdaptiveShowCardActionRenderer, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP Render(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveActionElement* actionElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result);
    };

    ActivatableClass(AdaptiveShowCardActionRenderer);
}}
