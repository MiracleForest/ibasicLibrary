/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:Vec4.hpp
* @creation time:2022.5.22.12:17
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBMATH_VEC4___
#define ___MIRACLEFOREST_I__LIBMATH_VEC4___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "vec3.hpp"


namespace i {
	namespace core {
		namespace libmath {

			template <typename T>
			class Vec4{
			public:
				T x, y, z, w;
			public:
				Vec4() : x((T)0), y((T)0), z((T)0), w((T)0) {}
				
				template <typename U>
				Vec4<T>(Vec4<U> a) { x = (T)a.x; y = (T)a.y; z = (T)a.z; w = (T)a.w; }
				
				Vec4(Vec2<T> xy, Vec2<T> zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
				
				Vec4(Vec3<T> xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
				
				Vec4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
				
				Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
				
				Vec4(::std::string vec, char c = ';', Vec4<T>* def = nullptr){
					if (def){
						x = def->x;
						y = def->y;
						z = def->z;
						w = def->w;
					}
					::std::vector<T> result = StringToNumberVector<T>(vec, c);
					const size_t s = result.size();
					if (s > 0) x = result[0];
					if (s > 1) y = result[1];
					if (s > 2) z = result[2];
					if (s > 3) w = result[3];
				}
				
				Vec4(::std::string vec, char c = ';', int n = 4, Vec4<T>* def = nullptr){
					if (def){
						x = def->x;
						y = def->y;
						z = def->z;
						w = def->w;
					}
					else{
						x = (T)0;
						y = (T)0;
						z = (T)0;
						w = (T)0;
					}
					::std::vector<T> result = _function::StringToNumberVector<T>(vec, c);
					const size_t s = result.size();
					if ((int)s != n){
						if (s == 1){
							x = result[0];
							y = result[0];
							z = result[0];
							w = result[0];
						}
						if (s == 2){
							x = result[0];
							y = result[0];
							z = result[1];
							w = result[1];
						}
					}
					else{
						if (s > 0) x = result[0];
						if (s > 1) y = result[1];
						if (s > 2) z = result[2];
						if (s > 3) w = result[3];
					}
				}

				/// <summary>
				/// 
				/// </summary>
				/// <param name="vec"></param>
				/// <param name="c"></param>
				/// <param name="n"></param>
				/// <param name="def"></param>
				T& operator [] (const size_t& i) { return (&x)[i]; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vX"></param>
				/// <param name="vY"></param>
				/// <param name="vZ"></param>
				/// <param name="vW"></param>
				/// <returns></returns>
				Vec4<T> Offset(const T& vX, const T& vY, const T& vZ, const T& vW) const { return Vec4<T>(x + vX, y + vY, z + vZ, w + vW); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vX"></param>
				/// <param name="vY"></param>
				/// <param name="vZ"></param>
				/// <param name="vW"></param>
				void Set(const T& vX, const T& vY, const T& vZ, const T& vW) { x = vX; y = vY; z = vZ; w = vW; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec4<T> operator -() const { return Vec4<T>(-x, -y, -z, -w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec4<T> operator !() const { return Vec4<T>(!x, !y, !z, !w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> xy() const { return Vec2<T>(x, y); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec3<T> xyz() const { return Vec3<T>(x, y, z); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> zw() const { return Vec2<T>(z, w); }

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec4<T>& operator ++ () { ++x; ++y; ++z; ++w; return *this; } 
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec4<T>& operator -- () { --x; --y; --z; --w; return *this; } 
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name=""></param>
				/// <returns></returns>
				Vec4<T> operator ++ (int) { Vec4<T> tmp = *this; ++* this; return tmp; } 
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name=""></param>
				/// <returns></returns>
				Vec4<T> operator -- (int) { Vec4<T> tmp = *this; --* this; return tmp; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator += (const T& a) { x += a; y += a; z += a; w += a; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator += (const Vec4<T>& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator -= (const T& a) { x -= a; y -= a; z -= a; w -= a; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator -= (const Vec4<T>& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				/// <returns></returns>
				bool operator == (const T& a) { return (x == a) && (y == a) && (z == a) && (w == a); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				/// <returns></returns>
				bool operator == (const Vec4<T>& v) { return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				/// <returns></returns>
				bool operator != (const T& a) { return (x != a) || (y != a) || (z != a) || (w != a); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				/// <returns></returns>
				bool operator != (const Vec4<T>& v) { return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator *= (const T& a) { x *= a; y *= a; z *= a; w *= a; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator *= (const Vec4<T>& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="a"></param>
				void operator /= (const T& a) { x /= a; y /= a; z /= a; w /= a; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v"></param>
				void operator /= (const Vec4<T>& v) { x /= v.x; y /= v.y; z /= v.z; w /= v.w; }
				

				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> SizeLBRT() const { return Vec2<T>(z - x, w - y); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> pos() const { return xy(); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> size() const { return zw(); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T length() const { return (T)sqrt(lengthSquared()); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T lengthSquared() const { return x * x + y * y + z * z + w * w; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T normalize() { T _length = length(); if (_length < (T)1e-5)return (T)0; T _invLength = (T)1 / _length; x *= _invLength; y *= _invLength; z *= _invLength; w *= _invLength; return _length; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec4<T> GetNormalized() const { Vec4<T> n = Vec4<T>(x, y, z, w); n.normalize(); return n; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				bool emptyAND() const { return x == (T)0 && y == (T)0 && z == (T)0 && w == (T)0; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				bool emptyOR() const { return x == (T)0 || y == (T)0 || z == (T)0 || w == (T)0; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T sum() const { return x + y + z + w; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T sumAbs() const { return abs<T>(x) + _function::abs<T>(y) + _function::abs<T>(z) + _function::abs<T>(w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="c"></param>
				/// <returns></returns>
				std::string string(char c = ';') const { return std::to_string(x) + c + std::to_string(y) + c + std::to_string(z) + c + std::to_string(w); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T mini() const { return _function::internalMini<T>(x, _function::internalMini<T>(y, _function::internalMini<T>(z, w))); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				T maxi() const { return _function::internalMaxi<T>(x, _function::internalMaxi<T>(y, _function::internalMaxi<T>(z, w))); }
			};

			template <typename T> inline Vec4<T>& operator ++ (Vec4<T>& v) { ++v; return v; } 
			template <typename T> inline Vec4<T>& operator -- (Vec4<T>& v) { --v; return v; } 
			template <typename T> inline Vec4<T> operator ++ (Vec4<T>& v, int) { Vec4<T> a = v; ++a; return a; } 
			template <typename T> inline Vec4<T> operator -- (Vec4<T>& v, int) { Vec4<T> a = v; --a; return a; } 
			template <typename T> inline Vec4<T> operator + (Vec4<T> v, T f) { return Vec4<T>(v.x + f, v.y + f, v.z + f, v.w + f); }
			template <typename T> inline Vec4<T> operator + (Vec4<T> v, Vec4<T> f) { return Vec4<T>(v.x + f.x, v.y + f.y, v.z + f.z, v.w + f.w); }
			template <typename T> inline Vec4<T> operator - (Vec4<T> v, T f) { return Vec4<T>(v.x - f, v.y - f, v.z - f, v.w - f); }
			template <typename T> inline Vec4<T> operator - (T f, Vec4<T> v) { return Vec4<T>(f - v.x, f - v.y, f - v.z, f - v.w); }
			template <typename T> inline Vec4<T> operator - (Vec4<T> v, Vec4<T> f) { return Vec4<T>(v.x - f.x, v.y - f.y, v.z - f.z, v.w - f.w); }
			template <typename T> inline Vec4<T> operator * (Vec4<T> v, T f) { return Vec4<T>(v.x * f, v.y * f, v.z * f, v.w * f); }
			template <typename T> inline Vec4<T> operator * (Vec4<T> v, Vec4<T> f) { return Vec4<T>(v.x * f.x, v.y * f.y, v.z * f.z, v.w * f.w); }
			template <typename T> inline Vec4<T> operator / (Vec4<T> v, T f) { return Vec4<T>(v.x / f, v.y / f, v.z / f, v.w / f); }
			template <typename T> inline Vec4<T> operator / (Vec4<T> v, Vec4<T> f) { return Vec4<T>(v.x / f.x, v.y / f.y, v.z / f.z, v.w / f.w); }
			template <typename T> inline bool operator < (Vec4<T> v, Vec4<T> f) { return v.x < f.x&& v.y < f.y&& v.z < f.z&& v.w < f.w; }
			template <typename T> inline bool operator < (Vec4<T> v, T f) { return v.x < f&& v.y < f&& v.z < f&& v.w < f; }
			template <typename T> inline bool operator > (Vec4<T> v, Vec4<T> f) { return v.x > f.x && v.y > f.y && v.z > f.z && v.w > f.w; }
			template <typename T> inline bool operator > (Vec4<T> v, T f) { return v.x > f && v.y > f && v.z > f && v.w > f; }
			template <typename T> inline bool operator <= (Vec4<T> v, Vec4<T> f) { return v.x <= f.x && v.y <= f.y && v.z <= f.z && v.w <= f.w; }
			template <typename T> inline bool operator <= (Vec4<T> v, T f) { return v.x <= f && v.y <= f && v.z <= f && v.w <= f; }
			template <typename T> inline bool operator >= (Vec4<T> v, Vec4<T> f) { return v.x >= f.x && v.y >= f.y && v.z >= f.z && v.w >= f.w; }
			template <typename T> inline bool operator >= (Vec4<T> v, T f) { return v.x >= f && v.y >= f && v.z >= f && v.w >= f; }
			template <typename T> inline bool operator == (Vec4<T> v, Vec4<T> f) { return f.x == v.x && f.y == v.y && f.z == v.z && f.w == v.w; }
			template <typename T> inline bool operator != (Vec4<T> v, Vec4<T> f) { return f.x != v.x || f.y != v.y || f.z != v.z || f.w != v.w; }
			template <typename T> inline Vec4<T> mini(Vec4<T> a, Vec4<T> b) { return Vec4<T>(_function::mini<T>(a.x, b.x), _function::mini<T>(a.y, b.y), _function::mini<T>(a.z, b.z), _function::mini<T>(a.w, b.w)); }
			template <typename T> inline Vec4<T> maxi(Vec4<T> a, Vec4<T> b) { return Vec4<T>(_function::maxi<T>(a.x, b.x), _function::maxi<T>(a.y, b.y), _function::maxi<T>(a.z, b.z), _function::maxi<T>(a.w, b.w)); }
			template <typename T> inline Vec4<T> floor(Vec4<T> a) { return Vec4<T>(_function::floor<T>(a.x), _function::floor<T>(a.y), _function::floor<T>(a.z), _function::floor<T>(a.w)); }
			template <typename T> inline Vec4<T> ceil(Vec4<T> a) { return Vec4<T>(_function::ceil<T>(a.x), _function::ceil<T>(a.y), _function::ceil<T>(a.z), _function::ceil<T>(a.w)); }
			template <typename T> inline Vec4<T> abs(Vec4<T> a) { return Vec4<T>(_function::abs<T>(a.x), _function::abs<T>(a.y), _function::abs<T>(a.z), _function::abs<T>(a.w)); }
			template <typename T> inline Vec4<T> sign(Vec4<T> a) { return Vec4<T>(a.x < (T)0 ? (T)-1 : (T)1, a.y < (T)0 ? (T)-1 : 1, a.z < (T)0 ? (T)-1 : (T)1, a.w < (T)0 ? (T)-1 : (T)1); }
			template <typename T> inline Vec4<T> sin(Vec4<T> a) { return Vec4<T>(_function::sin<T>(a.x), _function::sin<T>(a.y), _function::sin<T>(a.z), _function::sin<T>(a.w)); }
			template <typename T> inline Vec4<T> cos(Vec4<T> a) { return Vec4<T>(_function::cos<T>(a.x), _function::cos<T>(a.y), _function::cos<T>(a.z), _function::cos<T>(a.w)); }
			template <typename T> inline Vec4<T> tan(Vec4<T> a) { return Vec4<T>(_function::tan<T>(a.x), _function::tan<T>(a.y), _function::tan<T>(a.z), _function::tan<T>(a.w)); }
			
			
			using dVec4 = Vec4<double>;
			using fVec4 = Vec4<float>;
			using bVec4 = Vec4<bool>;
			using iVec4 = Vec4<int>;
			using i8Vec4 = Vec4<int8_t>;
			using i16Vec4 = Vec4<int16_t>;
			using iVec4 = Vec4<int32_t>;
			using i32Vec4 = Vec4<int32_t>;
			using i64Vec4 = Vec4<int64_t>;
			using u8Vec4 = Vec4<uint8_t>;
			using u16Vec4 = Vec4<uint16_t>;
			using uVec4 = Vec4<uint32_t>;
			using u32Vec4 = Vec4<uint32_t>;
			using u64Vec4 = Vec4<uint64_t>;

			/// <summary>
			/// 
			/// </summary>
			/// <param name="a"></param>
			/// <returns></returns>
			inline bool valid(const fVec4& a) {
				return _function::floatIsValid(a.x) &&
					_function::floatIsValid(a.y) &&
					_function::floatIsValid(a.z) &&
					_function::floatIsValid(a.w);
			}
			
			/// <summary>
			/// 
			/// </summary>
			/// <param name="v"></param>
			/// <param name="f"></param>
			/// <returns></returns>
			inline bool operator == (const fVec4& v, const fVec4& f) { return IS_FLOAT_EQUAL(f.x, v.x) && IS_FLOAT_EQUAL(f.y, v.y) && IS_FLOAT_EQUAL(f.z, v.z) && IS_FLOAT_EQUAL(f.w, v.w); }
			
			/// <summary>
			/// 
			/// </summary>
			/// <param name="v"></param>
			/// <param name="f"></param>
			/// <returns></returns>
			inline bool operator != (const fVec4& v, const fVec4& f) { return IS_FLOAT_DIFFERENT(f.x, v.x) || IS_FLOAT_DIFFERENT(f.y, v.y) || IS_FLOAT_DIFFERENT(f.z, v.z) || IS_FLOAT_DIFFERENT(f.w, v.w); }
		}
	}
}

#endif //!___MIRACLEFOREST_I__LIBMATH_VEC4___