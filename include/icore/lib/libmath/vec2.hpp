/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:vec2.hpp
* @creation time:2022.5.20.21:52
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Happy 520 to everyone!
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBMATH_VEC2___
#define ___MIRACLEFOREST_I__LIBMATH_VEC2___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "../../type/istring.hpp"
#include "../../../cppstd/thread"

#ifdef __WINDOWS__
#include <Windows.h>
#endif

namespace i {
	namespace core {
		namespace libmath {

			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			template <typename T>
			class Vec2 {
			public:
				T x, y;

				Vec2<T>() { x = (T)0; y = (T)0; }
				template <typename U> Vec2<T>(const Vec2<U>& a) { x = (T)a.x; y = (T)a.y; }
				Vec2<T>(const T& a) { x = a; y = a; }
				Vec2<T>(const T& a, const T& b) { x = a; y = b; }
				Vec2<T>(const ::std::string& Vec, const char& c = ';', Vec2<T>* def = nullptr) {
					if (def) {
						x = def->x;
						y = def->y;
					}
					::std::vector<T> result = _function::StringToNumberVector<T>(Vec, c);
					const size_t s = result.size();
					if (s > 0) x = result[0];
					if (s > 1) y = result[1];
				}

				/// <summary>
				/// 
				/// </summary>
				/// <param name="i"></param>
				/// <returns></returns>
				T& operator [] (const size_t& i) { return (&x)[i]; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="vX"></param>
				/// <param name="vY"></param>
				/// <returns></returns>
				Vec2<T> Offset(const T& vX, const T& vY) const {
					return Vec2<T>(x + vX, y + vY);
				}

				/// <summary>
				/// 
				/// </summary>
				/// <param name="vX"></param>
				/// <param name="vY"></param>
				void Set(const T& vX, const T& vY) { x = vX; y = vY; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> operator -() const { return Vec2<T>(-x, -y); }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> operator !() const { return Vec2<T>(!x, !y); }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T>& operator ++ () { ++x; ++y; return *this; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T>& operator -- () { --x; --y; return *this; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name=""></param>
				/// <returns></returns>
				Vec2<T> operator ++ (int) {
					Vec2<T> tmp = *this;
					++* this; return tmp;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <param name=""></param>
				/// <returns></returns>
				Vec2<T> operator -- (int) {
					Vec2<T> tmp = *this;
					--* this;
					return tmp;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator += (const T& a) { x += a; y += a; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator += (const Vec2<T>& v) { x += v.x; y += v.y; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator -= (const T& a) { x -= a; y -= a; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator -= (const Vec2<T>& v) { x -= v.x; y -= v.y; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				/// <returns></returns>
				bool operator == (const T& a) { return (x == a) && (y == a); }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				/// <returns></returns>
				bool operator == (const Vec2<T>& v) { return (x == v.x) && (y == v.y); }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				/// <returns></returns>
				bool operator != (const T& a) { return (x != a) || (y != a); }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				/// <returns></returns>
				bool operator != (const Vec2<T>& v) { return (x != v.x) || (y != v.y); }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator *= (const T& a) { x *= a; y *= a; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator *= (const Vec2<T>& v) { x *= v.x; y *= v.y; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator /= (const T& a) { x /= a; y /= a; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator /= (const Vec2<T>& v) { x /= v.x; y /= v.y; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T lengthSquared() const { return x * x + y * y; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T length() const { return (T)sqrt(lengthSquared()); }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T normalize() {
					T _length = length();
					if (_length < (T)1e-5) return (T)0.0;
					T _invLength = (T)1.0 / _length;
					x *= _invLength;
					y *= _invLength;
					return _length;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> GetNormalized() const {
					Vec2<T> n = Vec2<T>(x, y);
					n.normalize();
					return n;
				}

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T sum() const { return x + y; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T sumAbs() const { return abs<T>(x) + abs<T>(y); }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				bool emptyAND() const { return x == (T)0 && y == (T)0; }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				bool emptyOR() const { return x == (T)0 || y == (T)0; }

				/// <summary>
				/// 
				/// </summary>
				/// <param name="c"></param>
				/// <returns></returns>
				std::string string(const char& c = ';') const { return std::to_string(x) + c + std::to_string(y); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="U"></typeparam>
				/// <returns></returns>
				template <typename U>
				U ratioXY() const { if (y != (T)0) return (U)x / (U)y; return (U)0; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <typeparam name="U"></typeparam>
				/// <returns></returns>
				template <typename U>
				U ratioYX() const { if (x != (T)0) return (U)y / (U)x; return (U)0; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T mini() const { return _function::internalMini<T>(x, y); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T maxi() const { return _function::internalMaxi<T>(x, y); }
			};

			template <typename T> inline Vec2<T>& operator ++ (Vec2<T>& v) { ++v; return v; }
			template <typename T> inline Vec2<T>& operator -- (Vec2<T>& v) { --v; return v; }
			template <typename T> inline Vec2<T> operator ++ (Vec2<T>& v, int) { Vec2<T> a = v; ++a; return a; }
			template <typename T> inline Vec2<T> operator -- (Vec2<T>& v, int) { Vec2<T> a = v; --a; return a; }
			template <typename T> inline Vec2<T> operator + (Vec2<T> v, T f) { return Vec2<T>(v.x + f, v.y + f); }
			template <typename T> inline Vec2<T> operator + (T f, Vec2<T> v) { return Vec2<T>(v.x + f, v.y + f); }
			template <typename T> inline Vec2<T> operator + (Vec2<T> v, Vec2<T> f) { return Vec2<T>(v.x + f.x, v.y + f.y); }
			template <typename T> inline Vec2<T> operator - (Vec2<T> v, T f) { return Vec2<T>(v.x - f, v.y - f); }
			template <typename T> inline Vec2<T> operator - (T f, Vec2<T> v) { return Vec2<T>(f - v.x, f - v.y); }
			template <typename T> inline Vec2<T> operator - (Vec2<T> v, Vec2<T> f) { return Vec2<T>(v.x - f.x, v.y - f.y); }
			template <typename T> inline Vec2<T> operator * (Vec2<T> v, T f) { return Vec2<T>(v.x * f, v.y * f); }
			template <typename T> inline Vec2<T> operator * (T f, Vec2<T> v) { return Vec2<T>(v.x * f, v.y * f); }
			template <typename T> inline Vec2<T> operator * (Vec2<T> v, Vec2<T> f) { return Vec2<T>(v.x * f.x, v.y * f.y); }
			template <typename T> inline Vec2<T> operator / (Vec2<T> v, T f) { return Vec2<T>(v.x / f, v.y / f); }
			template <typename T> inline Vec2<T> operator / (T f, Vec2<T> v) { return Vec2<T>(f / v.x, f / v.y); }
			template <typename T> inline Vec2<T> operator / (Vec2<T> v, Vec2<T> f) { return Vec2<T>(v.x / f.x, v.y / f.y); }
			template <typename T> inline bool operator < (Vec2<T> v, Vec2<T> f) { return v.x < f.x&& v.y < f.y; }
			template <typename T> inline bool operator < (Vec2<T> v, T f) { return v.x < f&& v.y < f; }
			template <typename T> inline bool operator > (Vec2<T> v, Vec2<T> f) { return v.x > f.x && v.y > f.y; }
			template <typename T> inline bool operator > (Vec2<T> v, T f) { return v.x > f && v.y > f; }
			template <typename T> inline bool operator <= (Vec2<T> v, Vec2<T> f) { return v.x <= f.x && v.y <= f.y; }
			template <typename T> inline bool operator <= (Vec2<T> v, T f) { return v.x <= f && v.y <= f; }
			template <typename T> inline bool operator >= (Vec2<T> v, Vec2<T> f) { return v.x >= f.x && v.y >= f.y; }
			template <typename T> inline bool operator >= (Vec2<T> v, T f) { return v.x >= f && v.y >= f; }
			template <typename T> inline bool operator != (Vec2<T> v, Vec2<T> f) { return f.x != v.x || f.y != v.y; }
			template <typename T> inline bool operator == (Vec2<T> v, Vec2<T> f) { return f.x == v.x && f.y == v.y; }
			template <typename T> inline Vec2<T> floor(Vec2<T> a) { return Vec2<T>(_function::floor(a.x), _function::floor(a.y)); }
			template <typename T> inline Vec2<T> fract(Vec2<T> a) { return Vec2<T>(_function::fract(a.x), _function::fract(a.y)); }
			template <typename T> inline Vec2<T> ceil(Vec2<T> a) { return Vec2<T>(_function::ceil(a.x), _function::ceil(a.y)); }
			template <typename T> inline Vec2<T> mini(Vec2<T> a, Vec2<T> b) { return Vec2<T>(_function::mini(a.x, b.x), _function::mini(a.y, b.y)); }
			template <typename T> inline Vec2<T> maxi(Vec2<T> a, Vec2<T> b) { return Vec2<T>(_function::maxi(a.x, b.x), _function::maxi(a.y, b.y)); }
			template <typename T> inline T dot(Vec2<T> a, Vec2<T> b) { return a.x * b.x + a.y * b.y; }
			template <typename T> inline T det(Vec2<T> a, Vec2<T> b) { return a.x * b.y - a.y * b.x; }
			template <typename T> inline Vec2<T> cross(Vec2<T> a, Vec2<T> b) { return Vec2<T>(a.x * b.y - a.y * b.x, a.y * b.x - a.x * b.y); }
			template <typename T> inline Vec2<T> reflect(Vec2<T> I, Vec2<T> N) { return I - (T)2 * dotS(N, I) * N; }
			template <typename T> inline Vec2<T> sign(Vec2<T> a) { return Vec2<T>(a.x < (T)0 ? -(T)1 : (T)1, a.y < (T)0 ? (T)-1 : (T)1); }
			template <typename T> inline Vec2<T> sin(Vec2<T> a) { return Vec2<T>(_function::sin<T>(a.x), _function::sin<T>(a.y)); }
			template <typename T> inline Vec2<T> cos(Vec2<T> a) { return Vec2<T>(_function::cos<T>(a.x), _function::cos<T>(a.y)); }
			template <typename T> inline Vec2<T> tan(Vec2<T> a) { return Vec2<T>(_function::tan<T>(a.x), _function::tan<T>(a.y)); }
			template <typename T> inline Vec2<T> atan(Vec2<T> a) { return Vec2<T>(_function::atan<T>(a.x), _function::atan<T>(a.y)); }
			using dvec2 = Vec2<double>;
			using fvec2 = Vec2<float>;
			using bvec2 = Vec2<bool>;
			using i8vec2 = Vec2<int8_t>;
			using i16vec2 = Vec2<int16_t>;
			using ivec2 = Vec2<int32_t>;
			using i32vec2 = Vec2<int32_t>;
			using i64vec2 = Vec2<int64_t>;
			using u8vec2 = Vec2<uint8_t>;
			using u16vec2 = Vec2<uint16_t>;
			using uvec2 = Vec2<uint32_t>;
			using u32vec2 = Vec2<uint32_t>;
			using u64vec2 = Vec2<uint64_t>;

			inline fvec2 convert(const ivec2& v) { return fvec2((float)v.x, (float)v.y); }
			inline ivec2 convert(const fvec2& v) { return ivec2((int)v.x, (int)v.y); }

			inline bool valid(const fvec2& a) { return _function::floatIsValid(a.x) && _function::floatIsValid(a.y); }

			inline bool operator == (const fvec2& v, const fvec2& f) { return (IS_FLOAT_EQUAL(f.x, v.x) && IS_FLOAT_EQUAL(f.y, v.y)); }
			inline bool operator != (const fvec2& v, const fvec2& f) { return (IS_FLOAT_DIFFERENT(f.x, v.x) || IS_FLOAT_DIFFERENT(f.y, v.y)); }

			template <typename T>
			inline T prototypeRadAngleFromVec2(Vec2<T> vec) {
				T angle = 0.0f;
				if (vec.lengthSquared() > T(0) && vec.x != T(0)) {
					angle = _function::atan<T>(vec.y / vec.x);
				}
				return angle;
			}

			inline float radAngleFromVec2(const fvec2& vec) { return prototypeRadAngleFromVec2(vec); }
			inline double radAngleFromVec2(const dvec2& vec) { return prototypeRadAngleFromVec2(vec); }

		}
	}
}

#endif //!___MIRACLEFOREST_I__LIBMATH_VEC2___