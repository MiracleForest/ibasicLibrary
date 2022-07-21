/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：color.hpp
* @创建时间：****.**.**.**:**
* @创建者：***
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_COLOR___
#define ___MIRACLEFOREST_I_COLOR___

#include "../family/imacrofamily.h"
#include "filepos.hpp"
#include "istring.hpp"

#include <cmath>
#include <vector>
#include <glm/glm.hpp>


SPACE(i) {
    SPACE(core) {
        SPACE(type) {

            struct RGB {
                ushort r;
                ushort g;
                ushort b;

                static inline RGB makeRGB(ushort r, ushort g, ushort b) {
                    RGB rgb { r, b, g };
                    return rgb;
                }

                static inline RGB makeDefault() {
                    RGB rgb;
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;
                    return rgb;
                }
            };

            struct RGBA {
                RGBA(CRef<RGB>) = delete;
                RGBA() = default;
                RGB rgb;
                ushort a;

                static inline RGBA makeRGBA(ushort r, ushort g, ushort b, ushort a = 255) {
                    RGBA rgba;
                    rgba.rgb = { r, b, g };
                    rgba.a = a;
                    return rgba;
                }

                static inline RGBA makeDefault() {
                    RGBA rgba;
                    rgba.rgb = RGB::makeDefault();
                    rgba.a = 255;
                    return rgba;
                }
            };

            class color {
            public:
                enum Colors : ulong {
                    black = 0x000000,//0,0,0
                    white = 0xFFFFFF,//255,255,255
                    blue = 0x0000FF,//0,0,255
                    green = 0x00FF00,//0,0,255
                    red = 0xFF0000,//255,0,0
                    yellow = 0xFFFF00//255,255,0
                };

                enum class ImageType {
                    JPEG,
                    PNG,
                    TIFF,
                    DDS,
                    TGA,
                    BMP
                };

                enum class ConsoleTargetType {
                    text,
                    background
                };

            public:

                color() :_rgb(RGB::makeDefault()) {}

                color(RGB rgb) :_rgb(rgb) {}

                color(RGBA rgba) :_rgb(rgba.rgb) {}

                color(ushort r, ushort g, ushort b) :_rgb({ r, g, b }) {}

                color(ulong hex)
                    :_rgb(RGB::makeRGB(((hex >> 16) & 0xFF), ((hex >> 8) & 0xFF), (hex & 0xFF)))
                {}

                color(Colors Color)
                    : _rgb(RGB::makeRGB(((Color >> 16) & 0xFF), ((Color >> 8) & 0xFF), (Color & 0xFF)))
                {}

                ~color() {}

            public:

                ulong toHex()const {
                    return
                        ((_rgb.r & 0xff) << 16) +
                        ((_rgb.g & 0xff) << 8)
                        + (_rgb.b & 0xff);
                }

            public:

                RGB data()const {
                    return _rgb;
                }

                void setData(RGB rgb) {
                    _rgb = rgb;
                }

                void reset() {
                    _rgb = RGB::makeDefault();
                }

                RGBA getRGBA()const {
                    return RGBA::makeRGBA(_rgb.r, _rgb.g, _rgb.b);
                }

                RGB getRGB()const {
                    return _rgb;
                }

                void setRGB(RGB rgb) {
                    _rgb = rgb;
                }

                ushort getR()const {
                    return _rgb.r;
                }

                void setR(ushort r) {
                    _rgb.r = r;
                }

                ushort getG()const {
                    return _rgb.g;
                }

                void setG(ushort g) {
                    _rgb.g = g;
                }

                ushort getB()const {
                    return _rgb.b;
                }

                void setB(ushort b) {
                    _rgb.b = b;
                }

                public C_STATIC:

                static ulong toHex(RGBA rgba) {
                    return ((rgba.rgb.r & 0xff) << 24) +
                        ((rgba.rgb.g & 0xff) << 16) +
                        ((rgba.rgb.b & 0xff) << 8)
                        + (rgba.a & 0xff);
                }

                static ulong toHex(ushort _r, ushort _g, ushort _b, ushort _a) {
                    return ((_r & 0xff) << 24) +
                        ((_g & 0xff) << 16) +
                        ((_b & 0xff) << 8)
                        + (_a & 0xff);
                }

                static ulong toHex(ushort _r, ushort _g, ushort _b) {
                    return ((_r & 0xff) << 16) +
                        ((_g & 0xff) << 8) +
                        (_b & 0xff);
                }

                static ulong toHex(RGB rgb) {
                    return ((rgb.r & 0xff) << 16) +
                        ((rgb.g & 0xff) << 8) +
                        (rgb.b & 0xff);
                }

                static type::istring getConsoleColorIString(RGB _rgb) {
                    return istring("\033[38;2;" +
                                   std::to_string(_rgb.r) +
                                   ";" +
                                   std::to_string(_rgb.g) +
                                   ";" +
                                   std::to_string(_rgb.b) +
                                   "m");
                }

                static type::istring getConsoleColorIString(RGBA _rgb) {
                    return istring("\033[38;2;" +
                                   std::to_string(_rgb.rgb.r) +
                                   ";" +
                                   std::to_string(_rgb.rgb.g) +
                                   ";" +
                                   std::to_string(_rgb.rgb.b) +
                                   "m");
                }

                static type::istring getConsoleColorIString(CRef<color> _color) {
                    auto c = _color.getRGB();
                    return istring("\033[38;2;" +
                                   std::to_string(c.r) +
                                   ";" +
                                   std::to_string(c.g) +
                                   ";" +
                                   std::to_string(c.b) +
                                   "m");
                }

                public C_OPERATOR:

                public C_CLASS :

                    class Gradient {

                };

            protected:
            private:
                RGB _rgb;
            };


        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_COLOR___
