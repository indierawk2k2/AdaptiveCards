// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adaptivecards.djinni

#pragma once

#include <memory>
#include <string>

namespace AdaptiveCards {

class DjinniBaseCardElement;
enum class DjinniTextColor;

class DjinniTextBlock {
public:
    virtual ~DjinniTextBlock() {}

    static std::shared_ptr<DjinniTextBlock> Create();

    static std::shared_ptr<DjinniTextBlock> Deserialize(const std::string & jsonString);

    virtual void SetText(const std::string & text) = 0;

    virtual std::string GetText() = 0;

    virtual void SetWrap(bool wrap) = 0;

    virtual bool GetWrap() = 0;

    virtual void SetTextColor(DjinniTextColor textColor) = 0;

    virtual DjinniTextColor GetTextColor() = 0;

    virtual std::shared_ptr<DjinniBaseCardElement> AsBaseCardElement() = 0;
};

}  // namespace AdaptiveCards