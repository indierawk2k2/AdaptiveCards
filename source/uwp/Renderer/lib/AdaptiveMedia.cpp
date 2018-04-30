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

        m_wrap = sharedMedia->GetWrap();
        m_subtle = sharedMedia->GetIsSubtle();
        m_maxLines = sharedMedia->GetMaxLines();

        m_textSize = static_cast<ABI::AdaptiveNamespace::TextSize>(sharedMedia->GetTextSize());
        m_textWeight = static_cast<ABI::AdaptiveNamespace::TextWeight>(sharedMedia->GetTextWeight());
        m_foregroundColor = static_cast<ABI::AdaptiveNamespace::ForegroundColor>(sharedMedia->GetTextColor());
        m_horizontalAlignment = static_cast<ABI::AdaptiveNamespace::HAlignment>(sharedMedia->GetHorizontalAlignment());

        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetText(), m_text.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedMedia->GetLanguage(), m_language.GetAddressOf()));

        InitializeBaseElement(std::static_pointer_cast<BaseCardElement>(sharedMedia));
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Text(HSTRING* text)
    {
        return m_text.CopyTo(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Text(HSTRING text)
    {
        return m_text.Set(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Size(ABI::AdaptiveNamespace::TextSize* textSize)
    {
        *textSize = m_textSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Size(ABI::AdaptiveNamespace::TextSize textSize)
    {
        m_textSize = textSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Weight(ABI::AdaptiveNamespace::TextWeight* textWeight)
    {
        *textWeight = m_textWeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Weight(ABI::AdaptiveNamespace::TextWeight textWeight)
    {
        m_textWeight = textWeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Color(ABI::AdaptiveNamespace::ForegroundColor* foregroundColor)
    {
        *foregroundColor = m_foregroundColor;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Color(ABI::AdaptiveNamespace::ForegroundColor foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Wrap(boolean* wrap)
    {
        *wrap = m_wrap;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Wrap(boolean wrap)
    {
        m_wrap = wrap;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_IsSubtle(boolean* isSubtle)
    {
        *isSubtle = m_subtle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_IsSubtle(boolean isSubtle)
    {
        m_subtle = isSubtle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_MaxLines(UINT32* maxLines)
    {
        *maxLines = m_maxLines;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_MaxLines(UINT32 maxLines)
    {
        m_maxLines = maxLines;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_HorizontalAlignment(ABI::AdaptiveNamespace::HAlignment* alignment)
    {
        *alignment = m_horizontalAlignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_HorizontalAlignment(ABI::AdaptiveNamespace::HAlignment alignment)
    {
        m_horizontalAlignment = alignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_Language(HSTRING* language)
    {
        return m_language.CopyTo(language);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::put_Language(HSTRING language)
    {
        return m_language.Set(language);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveMedia::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::Media;
        return S_OK;
    }

    HRESULT AdaptiveMedia::GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseCardElement>& sharedMedia) try
    {
        std::shared_ptr<AdaptiveSharedNamespace::Media> media = std::make_shared<AdaptiveSharedNamespace::Media>();

        RETURN_IF_FAILED(SetSharedElementProperties(std::static_pointer_cast<AdaptiveSharedNamespace::BaseCardElement>(media)));

        media->SetWrap(m_wrap);
        media->SetIsSubtle(m_subtle);
        media->SetMaxLines(m_maxLines);
        media->SetTextSize(static_cast<AdaptiveSharedNamespace::TextSize>(m_textSize));
        media->SetTextWeight(static_cast<AdaptiveSharedNamespace::TextWeight>(m_textWeight));
        media->SetTextColor(static_cast<AdaptiveSharedNamespace::ForegroundColor>(m_foregroundColor));
        media->SetHorizontalAlignment(static_cast<AdaptiveSharedNamespace::HorizontalAlignment>(m_horizontalAlignment));

        std::string text;
        RETURN_IF_FAILED(HStringToUTF8(m_text.Get(), text));
        media->SetText(text);

        std::string language;
        RETURN_IF_FAILED(HStringToUTF8(m_language.Get(), language));
        media->SetLanguage(language);

        sharedMedia = media;
        return S_OK;
    } CATCH_RETURN;
AdaptiveNamespaceEnd
