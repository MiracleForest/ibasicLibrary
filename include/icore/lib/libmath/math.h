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
				
				/****
				* @author Lovelylavender4
				* @since 2022.6.21.13:41
				* @brief This function is used to ensure that a floating point number is not a NaN or infinity.
				*
				* @param x -
				* @retval Õæ»ò¼Ù
				*
				* @par Example
				* @code
				* ´úÂëÊ¾Àý
				* @endcode
				*
				* @details
				* ÏêÏ¸ÃèÊö
				* @enddetails
				****/
				IAPI inline bool floatIsValid(float x);

				

				template <typename T> 
				inline T round(const T& v) {
					return (T)(std::round((double)v));
				}
				
				 
				template <typename T> 
				inline T floor(const T& v) {
					return (T)(std::floor((double)v));
				}
				
				 
				template <typename T> 
				inline T ceil(const T& v) {
					return (T)(std::ceil((double)v));
				}
				
				 
				template <typename T> 
				inline T fract(const T& v) {
					return v - floor<T>(v);
				}
				
				 
				template <typename T> 
				inline T cos(const T& v) {
					return std::cos(v);
				}

				 
				template <typename T>
				inline T acos(const T& v) {
					return std::acos(v);
				}

				 
				template <typename T> 
				inline T sin(const T& v) {
					return std::sin(v);
				}

				 
				template <typename T> 
				inline T asin(const T& v) {
					return std::asin(v);
				}

				 
				template <typename T> 
				inline T tan(const T& v) {
					return std::tan(v);
				}

				 
				template <typename T> 
				inline T atan(const T& v) {
					return std::atan(v);
				}

				 
				template <typename T> 
				inline T mini(const T& a, const T& b) {
					return a < b ? a : b;
				}

				 
				template <typename T> 
				inline T maxi(const T& a, const T& b) {
					return a > b ? a : b;
				}

				 
				template <typename T> 
				inline T internalMini(const T& a, const T& b) {
					return a < b ? a : b;
				}
				
				 
				template <typename T> 
				inline T internalMaxi(const T& a, const T& b) {
					return a > b ? a : b;
				}

				 
				template <typename T> 
				inline T clamp(const T& n) {
					return n >= T(0) && n <= T(1) ? n : T(n > T(0));
				} 
				
				 
				template <typename T> 
				inline T clamp(const T& n, const T& b) {
					return n >= T(0) && n <= b ? n : T(n > T(0)) * b;
				}
				
				 
				template <typename T> 
				inline T clamp(const T& n, const T& a, const T& b) {
					return n >= a && n <= b ? n : n < a ? a : b;
				}

				 
				template <typename T> 
				inline T abs(const T& a) {
					return a < 0 ? a * (T)-1 : a;
				}
				
				 
				template <typename T> 
				inline T sign(const T& a) {
					return a < 0 ? (T)-1 : (T)1;
				}
				
				 
				template <typename T> 
				inline T step(const T& a, const T& b) {
					return b < a ? (T)0 : (T)1;
				}
				
				 
				template <typename T> 
				inline T mod(const T& v, const T& l) {
					return std::modf(v, l);
				}
				
				 
				template <typename T> 
				inline T invMix(const T& i, const T& s, const T& r) {
					return (r - i) / (s - i);
				}

				 
				template <typename T> 
				inline T lerp(const T& a, const T& b, const T& t) {
					return a * (1.0f - t) + b * t;
				}
				
				 
				template <typename T> 
				inline T eerp(const T& a, const T& b, const T& t) {
					if (a == (T)0) return T(0);
					return pow(a * (b / a), t);
				}

				 
				template <typename T> 
				inline T mix(const T& a, const T& b, const T& t) {
					return lerp(a, b, t);
				}

				 
				template <typename T>
				T StringToNumber(const std::string& text){
					T value = (T)0;
					std::stringstream ss(text);
					ss >> value;
					return value;
				}

				 
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