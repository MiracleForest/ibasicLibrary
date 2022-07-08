// Copyright(C) MiracleForest Studio. All Rights Reserved
// Notes: all of the color value must be clamped to [0.0, 1.0], such as (0.2, 0.5, 0.8, 1.0)

#pragma once
#ifndef MIRACLEFOREST_IBASICLIBRARY_INCLUDE_ICORE_TYPE_COLOR_HPP_
#define MIRACLEFOREST_IBASICLIBRARY_INCLUDE_ICORE_TYPE_COLOR_HPP_

// temporary define to compatible IDE formatter settings
#define _IBASICLIBRARY_BEGIN namespace i {
#define _ICORE_BEGIN         namespace core {
#define _TYPE_BEGIN          namespace type {

#define _IBASICLIBRARY_END }
#define _ICORE_END         }
#define _TYPE_END          }
// those macros can romave after submit by SPACE(x)

#include <cmath>
#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "../family/imacrofamily.h"
#include "filepos.hpp"
#include "istring.hpp"

_IBASICLIBRARY_BEGIN
_ICORE_BEGIN
_TYPE_BEGIN

enum class Colors {
    // unknown
};

class Color {
public:
    enum class ImageType { // unfinished
        JPEG, PNG, TIFF, DDS, TGA, BMP
    };

    enum class ConsoleTargetType {
        // unknown
    };

    // structure function
    // ------------------
    Color() : _rgba({ 0.0f, 0.0f, 0.0f, 0.0f }) {}
    Color(glm::dvec4 Value) : _rgba(Value) {}
    Color(CRef<glm::dvec4> Value) : _rgba(Value) {}

    // functions to convert color data
    // -------------------------
    static Color convertColorValueFromHex(uint HexValue);
    uint         convertColorValueToHex(CRef<glm::dvec3> Value);
    static Color convertColorValueFromHexIString(CRef<istring> iString);
    istring      convertColorValueToIString(CRef<glm::dvec4> Value);
    static Color convertColorValueFromRgba(CRef<glm::dvec4> Value);
    glm::dvec4   convertColorValueToRgba(CRef<glm::dvec3> Value);
    static Color convertColorValueFromRgb();
    glm::dvec3   convertColorValueToRgb();

    // functions to convert image type
    // -------------------------------
    istring convertImageTypeToIString(ImageType Type);

    std::vector<std::vector<Color>> getAllFragColor(CRef<istring> Filename, ImageType Type);
    Color   getColorFromFragCoord(CRef<FilePos> FragCoord, ImageType Type);


    // functions to convert console target type
    // ----------------------------------------
    istring convertConsoleTargetTypeToIString(ConsoleTargetType Type);

    // setter functions
    // set color value
    // ---------------
    void setRed(double Value);
    void setGreen(double Value);
    void setBlue(double Value);
    void setAlpha(double Value);

    // set console target color
    // ------------------------
    void setConsoleTargetColor(ConsoleTargetType, CRef<FilePos> Coord, Color Value);

    void       reset();
    glm::dvec4 getColor();
    Color      getGrayscale(CRef<glm::dvec4> Value);
    glm::dvec4 data();
    glm::dvec4 mix(CRef<glm::dvec4> Color1, CRef<glm::dvec4> Color2, double Level);
    std::vector<FilePos> findOutAllSameColor(CRef<istring> Filename, CRef<Color> Target);

    // Gradient class
    // --------------
    class Gradient {
    public:
    protected:
    private:
        // TODO
    };

    // overload operators
    // ------------------
    Color operator+(CRef<Color> Value) {
        Color Result;
        Result._rgba += Value._rgba;

        return Result;
    }

    Color operator-(CRef<Color> Value) {
        Color Result;
        Result._rgba -= Value._rgba;

        return Result;
    }

    Color operator*(CRef<Color> Value) {
        Color Result;
        Result._rgba *= Value._rgba;

        return Result;
    }

    Color operator/(CRef<Color> Value) {
        Color Result;
        Result._rgba /= Value._rgba;

        return Result;
    }

    CRef<Color> operator+=(CRef<Color> Value) {
        _rgba += Value._rgba;
        return *this;
    }

    CRef<Color> operator-=(CRef<Color> Value) {
        _rgba -= Value._rgba;
        return *this;
    }

    CRef<Color> operator*=(CRef<Color> Value) {
        _rgba *= Value._rgba;
        return *this;
    }

    CRef<Color> operator/=(CRef<Color> Value) {
        _rgba /= Value._rgba;
        return *this;
    }

    bool operator<(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) < convertColorValueToHex(Value._rgba);
    }

    bool operator>(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) > convertColorValueToHex(Value._rgba);
    }

    bool operator<=(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) <= convertColorValueToHex(Value._rgba);
    }

    bool operator>=(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) >= convertColorValueToHex(Value._rgba);
    }

    bool operator==(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) == convertColorValueToHex(Value._rgba);
    }

    bool operator!=(CRef<Color> Value) {
        return convertColorValueToHex(this->_rgba) != convertColorValueToHex(Value._rgba);
    }

private:
    glm::dvec4 _rgba;
    static glm::dvec4 _static_rgba;
};

inline Color Color::convertColorValueFromHex(uint HexValue) {
    glm::dvec3 Result(0.0);
    Result.r = (HexValue >> 16) & 0xff / 255;
    Result.r = (HexValue >>  8) & 0xff / 255;
    Result.r = (HexValue)       & 0xff / 255;

    Color Object;
    Object._static_rgba = glm::dvec4(Result, 1.0);

    return Object;
}

inline inline uint Color::convertColorValueToHex(CRef<glm::dvec3> Value) {
    return (((static_cast<uint>(std::round(Value.r * 255.0)))) << 16) |
           (((static_cast<uint>(std::round(Value.g * 255.0)))) <<  8) |
           (((static_cast<uint>(std::round(Value.b * 255.0)))));
}

inline Color Color::convertColorValueFromHexIString(CRef<istring> iString) {
    uint HexValue = std::stoi(iString.data());
    Color Result = convertColorValueFromHex(HexValue);

    return Result;
}

inline istring Color::convertColorValueToIString(CRef<glm::dvec4> Value) {
    uint Result = convertColorValueToHex(Value);
    return istring(std::to_string(Result));
}

inline Color Color::convertColorValueFromRgba(CRef<glm::dvec4> Value) {
    Color Object;
    Object._rgba = Value;

    return Object;
}

inline glm::dvec4 Color::convertColorValueToRgba(CRef<glm::dvec3> Value) {
    return glm::dvec4();
}

inline Color Color::convertColorValueFromRgb() {
    return Color();
}

inline glm::dvec3 Color::convertColorValueToRgb() {
    return glm::dvec3();
}

istring Color::convertImageTypeToIString(ImageType Type) {
    switch (Type) {
    case ImageType::JPEG:
        return istring(".jpg");
    case ImageType::PNG:
        return istring(".png");
    case ImageType::TIFF:
        return istring(".tif");
    case ImageType::BMP:
        return istring(".bmp");
    case ImageType::DDS:
        return istring(".dds");
    case ImageType::TGA:
        return istring(".tga");
    }
}

inline std::vector<std::vector<Color>> Color::getAllFragColor(CRef<istring> Filename, ImageType Type) {
    return std::vector<std::vector<Color>>();
}

inline Color Color::getColorFromFragCoord(CRef<FilePos> FragCoord, ImageType Type) {
    return Color();
}

inline istring Color::convertConsoleTargetTypeToIString(ConsoleTargetType Type) {
    return istring();
}

inline void Color::setRed(double Value) {
    _rgba.r = Value;
}

inline void Color::setGreen(double Value) {
    _rgba.g = Value;
}

inline void Color::setBlue(double Value) {
    _rgba.b = Value;
}

inline void Color::setAlpha(double Value) {
    _rgba.a = Value;
}

inline void Color::setConsoleTargetColor(ConsoleTargetType, CRef<FilePos> Coord, Color Value) {}

inline void Color::reset() {
    _rgba = glm::dvec4(0.0);
}

inline glm::dvec4 Color::getColor() {
    return data();
}

inline Color Color::getGrayscale(CRef<glm::dvec4> Value) {
    return Color();
}

inline glm::dvec4 Color::data() {
    return _rgba;
}

inline glm::dvec4 i::core::type::Color::mix(CRef<glm::dvec4> Color1, CRef<glm::dvec4> Color2, double Level) {
    glm::dvec4 Result;
    Result = Color1 * (1.0 - Level) + Color2 * Level;
    return Result;
}

inline std::vector<FilePos> Color::findOutAllSameColor(CRef<istring> Filename, CRef<Color> Target) {
    return std::vector<FilePos>();
}

_IBASICLIBRARY_END
_ICORE_END
_TYPE_END

#endif // !MIRACLEFOREST_IBASICLIBRARY_INCLUDE_ICORE_TYPE_COLOR_HPP_
