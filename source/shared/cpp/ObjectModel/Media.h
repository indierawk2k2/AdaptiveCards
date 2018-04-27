#pragma once

#include "pch.h"
#include "BaseCardElement.h"
#include "Enums.h"
#include "ElementParserRegistration.h"

AdaptiveSharedNamespaceStart
class Media : public BaseCardElement
{
public:
    Media();

    virtual Json::Value SerializeToJsonValue() override;

    std::string GetTitle() const;
    void SetTitle(const std::string value);

    std::string GetSrc() const;
    void SetSrc(const std::string value);

    std::string GetImage() const;
    void SetImage(const std::string value);

    std::string GetWidth() const;
    void SetWidth(const std::string value);

    std::string GetHeight() const;
    void SetHeight(const std::string value);

    std::string GetDescription() const;
    void SetDescription(const std::string value);

    std::string GetImageAccessibility() const;
    void SetImageAccessibility(const std::string value);

private:
    std::string m_title;
    std::string m_src;
    std::string m_image;
    std::string m_width;
    std::string m_height;
    std::string m_description;
    std::string m_imageAccessibility;

    void PopulateKnownPropertiesSet();
};

class MediaParser : public BaseCardElementParser
{
public:
    std::shared_ptr<BaseCardElement> Deserialize(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration,
        const Json::Value& root);

    std::shared_ptr<BaseCardElement> DeserializeFromString(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration,
        const std::string& jsonString);
};
AdaptiveSharedNamespaceEnd
