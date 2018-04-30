#include "pch.h"
#include "AdaptiveMedia.h"
#include "Util.h"
#include "DateTimeParser.h"
#include <windows.foundation.collections.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespace;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

AdaptiveNamespaceStart
    HRESULT AdaptiveMedia::RuntimeClassInitialize() noexcept try
    {
        std::shared_ptr<AdaptiveSharedNamespace::Media> media = std::make_shared<AdaptiveSharedNamespace::Media>();
        return RuntimeClassInitialize(media);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::RuntimeClassInitialize(const std::shared_ptr<AdaptiveSharedNamespace::Media>& sharedMedia) try
    {
        if (sharedMedia == nullptr)
        {
            return E_INVALIDARG;
        }

        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetDescription(), m_description.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetHeight(), m_height.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetImage(), m_image.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetImageAccessibility(), m_imageAccessibility.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetSrc(), m_src.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetTitle(), m_title.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetWidth(), m_width.GetAddressOf()));

        InitializeBaseElement(std::static_pointer_cast<BaseCardElement>(sharedMedia));
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::Media;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Description(HSTRING* value)
    {
        return m_description.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Description(HSTRING value)
    {
        return m_description.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Height(HSTRING* value)
    {
        return m_height.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Height(HSTRING value)
    {
        return m_height.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Image(HSTRING* value)
    {
        return m_image.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Image(HSTRING value)
    {
        return m_image.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_ImageAccessibility(HSTRING* value)
    {
        return m_imageAccessibility.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_ImageAccessibility(HSTRING value)
    {
        return m_imageAccessibility.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Src(HSTRING* value)
    {
        return m_src.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Src(HSTRING value)
    {
        return m_src.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Title(HSTRING* value)
    {
        return m_title.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Title(HSTRING value)
    {
        return m_title.Set(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Width(HSTRING* value)
    {
        return m_width.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Width(HSTRING value)
    {
        return m_width.Set(value);
    }

    HRESULT AdaptiveMedia::GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseCardElement>& sharedMedia) try
    {
        std::shared_ptr<AdaptiveSharedNamespace::Media> media = std::make_shared<AdaptiveSharedNamespace::Media>();

        RETURN_IF_FAILED(SetSharedElementProperties(std::static_pointer_cast<AdaptiveSharedNamespace::BaseCardElement>(media)));

        std::string description;
        RETURN_IF_FAILED(HStringToUTF8(m_description.Get(), description));
        media->SetDescription(description);

        std::string height;
        RETURN_IF_FAILED(HStringToUTF8(m_height.Get(), height));
        media->SetHeight(height);

        std::string image;
        RETURN_IF_FAILED(HStringToUTF8(m_image.Get(), image));
        media->SetImage(image);

        std::string imageAccessibility;
        RETURN_IF_FAILED(HStringToUTF8(m_imageAccessibility.Get(), imageAccessibility));
        media->SetImageAccessibility(imageAccessibility);

        std::string src;
        RETURN_IF_FAILED(HStringToUTF8(m_src.Get(), src));
        media->SetSrc(src);

        std::string title;
        RETURN_IF_FAILED(HStringToUTF8(m_title.Get(), title));
        media->SetTitle(title);

        std::string width;
        RETURN_IF_FAILED(HStringToUTF8(m_width.Get(), width));
        media->SetWidth(width);

        sharedMedia = media;
        return S_OK;
    } CATCH_RETURN;
AdaptiveNamespaceEnd
