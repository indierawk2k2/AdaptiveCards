#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "Media.h"
#include "AdaptiveCardElement.h"

AdaptiveNamespaceStart
    class DECLSPEC_UUID("0c87566c-a58c-4332-8b3b-79c9714074f6") AdaptiveMedia :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveNamespace::IAdaptiveMedia,
            ABI::AdaptiveNamespace::IAdaptiveCardElement,
            Microsoft::WRL::CloakedIid<ITypePeek>,
            Microsoft::WRL::CloakedIid<AdaptiveNamespace::AdaptiveCardElementBase>>
    {
        AdaptiveRuntime(AdaptiveMedia)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveSharedNamespace::Media>& sharedMedia);

        // IAdaptiveMedia
        IFACEMETHODIMP get_Description(_Out_ HSTRING *text);
        IFACEMETHODIMP put_Description(_In_ HSTRING text);

        IFACEMETHODIMP get_Height(_Out_ HSTRING *text);
        IFACEMETHODIMP put_Height(_In_ HSTRING text);

        IFACEMETHODIMP get_Image(_Out_ ABI::Windows::Foundation::IUriRuntimeClass** url);
        IFACEMETHODIMP put_Image(_In_ ABI::Windows::Foundation::IUriRuntimeClass* url);

        IFACEMETHODIMP get_ImageAccessibility(_Out_ HSTRING *text);
        IFACEMETHODIMP put_ImageAccessibility(_In_ HSTRING text);

        IFACEMETHODIMP get_Src(_Out_ ABI::Windows::Foundation::IUriRuntimeClass** url);
        IFACEMETHODIMP put_Src(_In_ ABI::Windows::Foundation::IUriRuntimeClass* url);

        IFACEMETHODIMP get_Title(_Out_ HSTRING *text);
        IFACEMETHODIMP put_Title(_In_ HSTRING text);

        IFACEMETHODIMP get_Width(_Out_ HSTRING *text);
        IFACEMETHODIMP put_Width(_In_ HSTRING text);

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveNamespace::ElementType* elementType);

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveNamespace::Spacing* spacing) { return AdaptiveCardElementBase::get_Spacing(spacing); }
        IFACEMETHODIMP put_Spacing(_In_ ABI::AdaptiveNamespace::Spacing spacing) { return AdaptiveCardElementBase::put_Spacing(spacing); }

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator) { return AdaptiveCardElementBase::get_Separator(separator); }
        IFACEMETHODIMP put_Separator(_In_ boolean separator) { return AdaptiveCardElementBase::put_Separator(separator); }

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id) { return AdaptiveCardElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveCardElementBase::put_Id(id); }

        IFACEMETHODIMP get_ElementTypeString(_Out_ HSTRING* value) { return AdaptiveCardElementBase::get_ElementTypeString(value); }

        IFACEMETHODIMP get_AdditionalProperties(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::get_AdditionalProperties(result); }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value) { return AdaptiveCardElementBase::put_AdditionalProperties(value); }

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::ToJson(result); }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseCardElement>& sharedModel) override;

        // ITypePeek method
        void *PeekAt(REFIID riid) override
        {
            return PeekHelper(riid, this);
        }

    private:
        Microsoft::WRL::Wrappers::HString m_description;
        Microsoft::WRL::Wrappers::HString m_height;
        Microsoft::WRL::Wrappers::HString m_imageAccessibility;
        Microsoft::WRL::Wrappers::HString m_title;
        Microsoft::WRL::Wrappers::HString m_width;

        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> m_src;
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> m_image;
};

    ActivatableClass(AdaptiveMedia);
AdaptiveNamespaceEnd