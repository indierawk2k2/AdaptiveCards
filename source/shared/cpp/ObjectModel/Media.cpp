#include "pch.h"
#include "Media.h"
#include "ParseUtil.h"

using namespace AdaptiveSharedNamespace;

Media::Media() :
    BaseCardElement(CardElementType::Media)
{
    PopulateKnownPropertiesSet();
}

Json::Value Media::SerializeToJsonValue()
{
    Json::Value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = GetTitle();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Src)] = GetSrc();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Image)] = GetImage();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width)] = GetWidth();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Height)] = GetHeight();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Description)] = GetDescription();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::ImageAccessibility)] = GetImageAccessibility();

    return root;
}

std::string Media::GetTitle() const
{
    return m_title;
}

void Media::SetTitle(const std::string value)
{
    m_title = value;
}

std::string Media::GetSrc() const
{
    return m_src;
}

void Media::SetSrc(const std::string value)
{
    m_src = value;
}

std::string Media::GetImage() const
{
    return m_image;
}

void Media::SetImage(const std::string value)
{
    m_image = value;
}

std::string Media::GetWidth() const
{
    return m_width;
}

void Media::SetWidth(const std::string value)
{
    m_width = value;
}

std::string Media::GetHeight() const
{
    return m_height;
}

void Media::SetHeight(const std::string value)
{
    m_height = value;
}

std::string Media::GetDescription() const
{
    return m_description;
}

void Media::SetDescription(const std::string value)
{
    m_description = value;
}

std::string Media::GetImageAccessibility() const
{
    return m_imageAccessibility;
}

void Media::SetImageAccessibility(const std::string value)
{
    m_imageAccessibility = value;
}

std::shared_ptr<BaseCardElement> MediaParser::Deserialize(
    std::shared_ptr<ElementParserRegistration>,
    std::shared_ptr<ActionParserRegistration>,
    const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::Media);

    std::shared_ptr<Media> media = BaseCardElement::Deserialize<Media>(json);

    media->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    media->SetSrc(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Src, true));
    media->SetImage(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Image, false));
    media->SetWidth(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Width, false));
    media->SetHeight(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Height, false));
    media->SetDescription(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Description, false));
    media->SetImageAccessibility(ParseUtil::GetString(json, AdaptiveCardSchemaKey::ImageAccessibility, false));

    return media;
}

std::shared_ptr<BaseCardElement> MediaParser::DeserializeFromString(
    std::shared_ptr<ElementParserRegistration> elementParserRegistration,
    std::shared_ptr<ActionParserRegistration> actionParserRegistration,
    const std::string& jsonString)
{
    return MediaParser::Deserialize(elementParserRegistration, actionParserRegistration, ParseUtil::GetJsonValueFromString(jsonString));


}

void Media::PopulateKnownPropertiesSet() 
{
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Src));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Image));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Height));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Description));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::ImageAccessibility));
}
