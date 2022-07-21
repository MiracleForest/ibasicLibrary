/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:math.h
* @creation time:2022.5.22.11:54
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBMATH_MATH___
#define ___MIRACLEFOREST_I__LIBMATH_MATH___

#include "../../family/imacrofamily.h"
#include "../../type/basic/istring.hpp"
#include <vector>
#include <cmath>

SPACE(i) {
	SPACE(core) {
		SPACE(libmath) {
			SPACE(_function) {

				/****
				* @author Lovelylavender4
				* @since 2022.6.21.13:41
				* @brief 这个函数用来确保一个浮点数不是NaN或无穷大。
				*
				* @param f 浮点数
				* @retval 真或假
				*
				* @par 模板
				* @code
				* floatIsValid(aFloatNumber);
				* @endcode
				*
				* @details
				* 这个函数用来确保一个浮点数不是NaN或无穷大。
				* @enddetails
				****/
				IAPI inline bool floatIsValid(float f);


				template <typename T>
				inline T round(CRef<T> v) {
					return (T) (std::round((double) v));
				}


				template <typename T>
				inline T floor(CRef<T> v) {
					return (T) (std::floor((double) v));
				}


				template <typename T>
				inline T ceil(CRef<T> v) {
					return (T) (std::ceil((double) v));
				}


				template <typename T>
				inline T fract(CRef<T> v) {
					return v - floor<T>(v);
				}


				template <typename T>
				inline T cos(CRef<T> v) {
					return std::cos(v);
				}


				template <typename T>
				inline T acos(CRef<T> v) {
					return std::acos(v);
				}


				template <typename T>
				inline T sin(CRef<T> v) {
					return std::sin(v);
				}


				template <typename T>
				inline T asin(CRef<T> v) {
					return std::asin(v);
				}


				template <typename T>
				inline T tan(CRef<T> v) {
					return std::tan(v);
				}


				template <typename T>
				inline T atan(CRef<T> v) {
					return std::atan(v);
				}


				template <typename T>
				inline T mini(CRef<T> a, CRef<T> b) {
					return a < b ? a : b;
				}


				template <typename T>
				inline T maxi(CRef<T> a, CRef<T> b) {
					return a > b ? a : b;
				}


				template <typename T>
				inline T internalMini(CRef<T> a, CRef<T> b) {
					return a < b ? a : b;
				}


				template <typename T>
				inline T internalMaxi(CRef<T> a, CRef<T> b) {
					return a > b ? a : b;
				}


				template <typename T>
				inline T clamp(CRef<T> n) {
					return n >= T(0) && n <= T(1) ? n : T(n > T(0));
				}


				template <typename T>
				inline T clamp(CRef<T> n, CRef<T> b) {
					return n >= T(0) && n <= b ? n : T(n > T(0)) * b;
				}


				template <typename T>
				inline T clamp(CRef<T> n, CRef<T> a, CRef<T> b) {
					return n >= a && n <= b ? n : n < a ? a : b;
				}


				template <typename T>
				inline T abs(CRef<T> a) {
					return a < 0 ? a * (T) -1 : a;
				}


				template <typename T>
				inline T sign(CRef<T> a) {
					return a < 0 ? (T) -1 : (T) 1;
				}


				template <typename T>
				inline T step(CRef<T> a, CRef<T> b) {
					return b < a ? (T) 0 : (T) 1;
				}


				template <typename T>
				inline T mod(CRef<T> v, CRef<T> l) {
					return std::modf(v, l);
				}


				template <typename T>
				inline T invMix(CRef<T> i, CRef<T> s, CRef<T> r) {
					return (r - i) / (s - i);
				}


				template <typename T>
				inline T lerp(CRef<T> a, CRef<T> b, CRef<T> t) {
					return a * (1.0f - t) + b * t;
				}


				template <typename T>
				inline T eerp(CRef<T> a, CRef<T> b, CRef<T> t) {
					if ( a == (T) 0 ) return T(0);
					return pow(a * (b / a), t);
				}


				template <typename T>
				inline T mix(CRef<T> a, CRef<T> b, CRef<T> t) {
					return lerp(a, b, t);
				}


				template <typename T>
				T StringToNumber(CRef<std::string> text) {
					T value = (T) 0;
					std::stringstream ss(text);
					ss >> value;
					return value;
				}


				template <typename T>
				std::vector<T> StringToNumberVector(CRef<std::string> text, char delimiter) {
					std::vector<T> arr;
					std::string::size_type start = 0;
					std::string::size_type end = text.find(delimiter, start);
					while ( end != std::string::npos ) {
						std::string token = text.substr(start, end - start);
						arr.emplace_back(StringToNumber<T>(token));
						start = end + 1;
						end = text.find(delimiter, start);
					}
					arr.emplace_back(StringToNumber<T>(text.substr(start).c_str()));
					return arr;
				}




			}//SPACE(_function)
		}//SPACE(libmath)
	}//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I__LIBMATH_MATH___