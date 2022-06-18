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
#include "../../../cppstd/cmath"

namespace i {
    namespace core {
        namespace libmath {
            namespace _function{
				
				/// <summary>
				/// This function is used to ensure that a floating point number is not a NaN or infinity.
				/// </summary>
				/// <param name="x"></param>
				/// <returns></returns>
				IAPI inline bool floatIsValid(float x);

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T round(const T& v) {
					return (T)(std::round((double)v));
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T floor(const T& v) {
					return (T)(std::floor((double)v));
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T ceil(const T& v) {
					return (T)(std::ceil((double)v));
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T fract(const T& v) {
					return v - floor<T>(v);
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T cos(const T& v) {
					return std::cos(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T>
				inline T acos(const T& v) {
					return std::acos(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T sin(const T& v) {
					return std::sin(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T asin(const T& v) {
					return std::asin(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T tan(const T& v) {
					return std::tan(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <returns></returns>
				template <typename T> 
				inline T atan(const T& v) {
					return std::atan(v);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T mini(const T& a, const T& b) {
					return a < b ? a : b;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T maxi(const T& a, const T& b) {
					return a > b ? a : b;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T internalMini(const T& a, const T& b) {
					return a < b ? a : b;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T internalMaxi(const T& a, const T& b) {
					return a > b ? a : b;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="n"></param>
				/// <returns></returns>
				template <typename T> 
				inline T clamp(const T& n) {
					return n >= T(0) && n <= T(1) ? n : T(n > T(0));
				} 
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="n"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T clamp(const T& n, const T& b) {
					return n >= T(0) && n <= b ? n : T(n > T(0)) * b;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="n"></param>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T clamp(const T& n, const T& a, const T& b) {
					return n >= a && n <= b ? n : n < a ? a : b;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <returns></returns>
				template <typename T> 
				inline T abs(const T& a) {
					return a < 0 ? a * (T)-1 : a;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <returns></returns>
				template <typename T> 
				inline T sign(const T& a) {
					return a < 0 ? (T)-1 : (T)1;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <returns></returns>
				template <typename T> 
				inline T step(const T& a, const T& b) {
					return b < a ? (T)0 : (T)1;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="v"></param>
				/// <param name="l"></param>
				/// <returns></returns>
				template <typename T> 
				inline T mod(const T& v, const T& l) {
					return std::modf(v, l);
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="i"></param>
				/// <param name="s"></param>
				/// <param name="r"></param>
				/// <returns></returns>
				template <typename T> 
				inline T invMix(const T& i, const T& s, const T& r) {
					return (r - i) / (s - i);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <param name="t"></param>
				/// <returns></returns>
				template <typename T> 
				inline T lerp(const T& a, const T& b, const T& t) {
					return a * (1.0f - t) + b * t;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <param name="t"></param>
				/// <returns></returns>
				template <typename T> 
				inline T eerp(const T& a, const T& b, const T& t) {
					if (a == (T)0) return T(0);
					return pow(a * (b / a), t);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="a"></param>
				/// <param name="b"></param>
				/// <param name="t"></param>
				/// <returns></returns>
				template <typename T> 
				inline T mix(const T& a, const T& b, const T& t) {
					return lerp(a, b, t);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="text"></param>
				/// <returns></returns>
				template <typename T>
				T StringToNumber(const std::string& text){
					T value = (T)0;
					std::stringstream ss(text);
					ss >> value;
					return value;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <param name="text"></param>
				/// <param name="delimiter"></param>
				/// <returns></returns>
				template <typename T> 
				std::vector<T> StringToNumberVector(const std::string& text, char delimiter){
					std::vector<T> arr;
					std::string::size_type start = 0;
					std::string::size_type end = text.find(delimiter, start);
					while (end != std::string::npos){
						std::string token = text.substr(start, end - start);
						arr.emplace_back(StringToNumber<T>(token));
						start = end + 1;
						end = text.find(delimiter, start);
					}
					arr.emplace_back(StringToNumber<T>(text.substr(start).c_str()));
					return arr;
				}




            }//namespace _function
        }//namespace libmath
    }//namespace core
}//namespace i 


#endif //!___MIRACLEFOREST_I__LIBMATH_MATH___