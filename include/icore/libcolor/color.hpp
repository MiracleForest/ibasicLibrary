/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:color.hpp
* @creation time:2022.4.26.13:37
* @created by:Lovelylavender4
* @project:iBasicLibrary-libcolor
* -----------------------------------------------------------------------------
* This file contains information about color types and operations, etc.
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_COLOR___
#define ___MIRACLEFOREST_I_COLOR___

#include "../family/imacrofamily.h"

#include <iostream>
#include <string>

namespace i::core {
	namespace icolor {

		/// <summary>
		/// 
		/// </summary>
		struct RGB {
			RGB() :r(0), g(0), b(0) {}
			RGB(ushort _r, ushort _g, ushort _b) :r(_r), g(_g), b(_b) {}
			ushort r;
			ushort g;
			ushort b;
		};

		/// <summary>
		/// 
		/// </summary>
		class icolor {
		public:
			icolor() :rgb(0, 0, 0) {}
			icolor(RGB _rgb) :rgb(_rgb.r, _rgb.g, _rgb.b) {}
			icolor(ushort _r, ushort _g, ushort _b) :rgb(_r, _g, _b) {}
			~icolor() {}
		public:
			/// <summary>
			/// 
			/// </summary>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns></returns>
			ulong gethex()const {
				return rgb.r << 16 | rgb.g << 8 | rgb.b;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns></returns>
			RGB getRGB()const {
				return rgb;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <param name="_rgb"></param>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			void setRGB(RGB _rgb) {
				rgb = _rgb;
			}
		public:
			/// <summary>
			/// 
			/// </summary>
			/// <param name="_r"></param>
			/// <param name="_g"></param>
			/// <param name="_b"></param>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns></returns>
			static ushort tohex(ushort _r, ushort _g, ushort _b) {
				return _r << 16 | _g << 8 | _b;
			}
		private:
			RGB rgb;
		};//class color


	}//namespace icolor
}//namespace i::core
#endif//!___MIRACLEFOREST_I_COLOR___