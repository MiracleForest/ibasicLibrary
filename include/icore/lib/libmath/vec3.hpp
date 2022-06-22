/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:Vec3.hpp
* @creation time:2022.5.20.13:14
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Happy 520 to everyone!
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_VEC3___
#define ___MIRACLEFOREST_I_VEC3___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "../../../cppstd/cmath"
#include "../../type/istring.hpp"

#include "vec2.hpp"


namespace i {
	namespace core {
		namespace libmath {

			template <typename T>
			class Vec3{
			public:
				Vec3() : x((T)0), y((T)0), z((T)0) {}

				template <typename U>
				Vec3<T>(Vec3<U> a) {
					x = (T)a.x;
					y = (T)a.y;
					z = (T)a.z;
				}

				Vec3(const T& xyz) : x(xyz), y(xyz), z(xyz) {}

				Vec3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
				
				Vec3(const Vec2<T>& xy, const T& z) : x(xy.x), y(xy.y), z(z) {}
				
				Vec3(const type::istring& vec, const char& c = ';', Vec3<T>* def = nullptr){
					if (def) { x = def->x; y = def->y; z = def->z; }
					std::vector<T> result = _function::StringToNumberVector<T>(vec.data(), c);
					const size_t s = result.size();
					if (s > 0) x = result[0];
					if (s > 1) y = result[1];
					if (s > 2) z = result[2];
				}

			public:
				

				T& operator [] (const size_t& i) { 
					return (&x)[i];
				}
				

				Vec3<T> offset(
					const T& vX,
					const T& vY,
					const T& vZ
				) const {
					return Vec3<T>(x + vX, y + vY, z + vZ);
				}
				
				
				void setXYZ(
					const T& vX,
					const T& vY,
					const T& vZ
				) {
					x = vX;
					y = vY;
					z = vZ;
				}
				
				
				Vec3<T> operator -() const {
					return Vec3<T>(-x, -y, -z);
				}
				
				
				Vec3<T> operator !() const {
					return Vec3<T>(!x, !y, !z);
				}
				
				
				Vec2<T> xy() const {
					return Vec2<T>(x, y);
				}
				

				Vec2<T> xz() const {
					return Vec2<T>(x, z);
				}


				Vec2<T> yz() const {
					return Vec2<T>(y, z);
				}


				Vec3 yzx() const {
					return Vec3<T>(y, z, x);
				}


				Vec3<T>& operator ++ () {
					++x;
					++y;
					++z;
					return *this;
				}


				Vec3<T>& operator -- () {
					--x;
					--y;
					--z;
					return *this;
				}


				Vec3<T> operator ++ (int) {
					Vec3<T> tmp = *this;
					++* this;
					return tmp;
				}


				Vec3<T> operator -- (int) {
					Vec3<T> tmp = *this;
					--* this;
					return tmp;
				}


				void operator += (const T& a) {
					x += a;
					y += a;
					z += a;
				}


				void operator += (const Vec3<T>& v) {
					x += v.x;
					y += v.y;
					z += v.z;
				}


				void operator -= (const T& a) {
					x -= a;
					y -= a;
					z -= a;
				}


				void operator -= (const Vec3<T>& v) {
					x -= v.x;
					y -= v.y;
					z -= v.z;
				}


				bool operator == (const T& a) {
					return (x == a) && (y == a) && (z == a);
				}


				bool operator == (const Vec3<T>& v) {
					return (x == v.x) && (y == v.y) && (z == v.z);
				}


				bool operator != (const T& a) {
					return (x != a) || (y != a) || (z != a);
				}


				bool operator != (const Vec3<T>& v) {
					return (x != v.x) || (y != v.y) || (z != v.z); 
				}


				void operator *= (const T& a) {
					x *= a;
					y *= a;
					z *= a;
				}


				void operator *= (const Vec3<T>& v) {
					x *= v.x;
					y *= v.y;
					z *= v.z;
				}


				void operator /= (const T& a) {
					x /= a;
					y /= a;
					z /= a;
				}


				void operator /= (const Vec3<T>& v) {
					x /= v.x;
					y /= v.y;
					z /= v.z;
				}


				T length() const {
					return (T)sqrt(lengthSquared());
				}


				T lengthSquared() const {
					return x * x + y * y + z * z;
				}


				T normalize() {
					T _length = length();
					if (_length < (T)1e-5) { return (T)0 };
					T _invLength = (T)1 / _length;
					x *= _invLength;
					y *= _invLength;
					z *= _invLength;
					return _length;
				}


				Vec3<T> GetNormalized() const {
					Vec3<T> n = Vec3<T>(x, y, z);
					n.normalize();
					return n;
				}


				T sum() const {
					return x + y + z;
				}



				T sumAbs() const {
					return _function::abs<T>(x) +
						_function::abs<T>(y) +
						_function::abs<T>(z);
				}


				bool emptyAND() const {
					return x == (T)0 && y == (T)0 && z == (T)0;
				}


				bool emptyOR() const {
					return x == (T)0 || y == (T)0 || z == (T)0;
				}


				type::istring istring(const char& c = ';') const {
					return (std::to_string(x) + c 
						+ std::to_string(y) + c 
						+ std::to_string(z));
				}


				T mini() const {
					return _function::internalMini<T>(x, _function::internalMini<T>(y, z));
				}


				T maxi() const {
					return _function::internalMaxi<T>(x, _function::internalMaxi<T>(y, z));
				}


			public:
				T x, y, z;
			};

			template <typename T>
			inline Vec3<T>& operator ++ (Vec3<T>& v) {
				++v;
				return v;
			} 
			

			template <typename T> 
			inline Vec3<T>& operator -- (Vec3<T>& v) {
				--v;
				return v;
			} 


			template <typename T>
			inline Vec3<T> operator ++ (Vec3<T>& v, int) {
				Vec3<T> a = v;
				++a;
				return a;
			} 


			template <typename T>
			inline Vec3<T> operator -- (Vec3<T>& v, int) {
				Vec3<T> a = v;
				--a;
				return a;
			} 


			template <typename T>
			inline Vec3<T> operator + (Vec3<T> v, T f) { 
				return Vec3<T>(v.x + f, v.y + f, v.z + f);
			}


			template <typename T>
			inline Vec3<T> operator + (Vec3<T> v, Vec3<T> f) {
				return Vec3<T>(v.x + f.x, v.y + f.y, v.z + f.z);
			}


			template <typename T>
			inline Vec3<T> operator + (T f, Vec3<T> v) {
				return Vec3<T>(f + v.x, f + v.y, f + v.z);
			}


			template <typename T>
			inline Vec3<T> operator - (Vec3<T> v, T f) {
				return Vec3<T>(v.x - f, v.y - f, v.z - f);
			}


			template <typename T>
			inline Vec3<T> operator - (Vec3<T> v, Vec3<T> f) {
				return Vec3<T>(v.x - f.x, v.y - f.y, v.z - f.z);
			}


			template <typename T>
			inline Vec3<T> operator - (T f, Vec3<T> v) {
				return Vec3<T>(f - v.x, f - v.y, f - v.z);
			}


			template <typename T>
			inline Vec3<T> operator * (Vec3<T> v, T f) {
				return Vec3<T>(v.x * f, v.y * f, v.z * f);
			}


			template <typename T>
			inline Vec3<T> operator * (Vec3<T> v, Vec3<T> f) {
				return Vec3<T>(v.x * f.x, v.y * f.y, v.z * f.z);
			}


			template <typename T>
			inline Vec3<T> operator * (T f, Vec3<T> v) {
				return Vec3<T>(f * v.x, f * v.y, f * v.z);
			}


			template <typename T>
			inline Vec3<T> operator / (Vec3<T> v, T f) {
				return Vec3<T>(v.x / f, v.y / f, v.z / f);
			}


			template <typename T>
			inline Vec3<T> operator / (T f, Vec3<T> v) {
				return Vec3<T>(f / v.x, f / v.y, f / v.z);
			}


			template <typename T>
			inline Vec3<T> operator / (Vec3<T> v, Vec3<T> f) {
				return Vec3<T>(v.x / f.x, v.y / f.y, v.z / f.z);
			}


			template <typename T>
			inline bool operator < (Vec3<T> v, Vec3<T> f) {
				return v.x < f.x&& v.y < f.y&& v.z < f.z;
			}


			template <typename T>
			inline bool operator < (Vec3<T> v, T f) {
				return v.x < f&& v.y < f&& v.z < f;
			}


			template <typename T>
			inline bool operator > (Vec3<T> v, Vec3<T> f) {
				return v.x > f.x && v.y > f.y && v.z > f.z;
			}


			template <typename T> 
			inline bool operator > (Vec3<T> v, T f) {
				return v.x > f && v.y > f && v.z > f; 
			}


			template <typename T>
			inline bool operator <= (Vec3<T> v, Vec3<T> f) {
				return v.x <= f.x && v.y <= f.y && v.z <= f.z;
			}


			template <typename T>
			inline bool operator <= (Vec3<T> v, T f) {
				return v.x <= f && v.y <= f && v.z <= f;
			}


			template <typename T>
			inline bool operator >= (Vec3<T> v, Vec3<T> f) {
				return v.x >= f.x && v.y >= f.y && v.z >= f.z;
			}


			template <typename T>
			inline bool operator >= (Vec3<T> v, T f) {
				return v.x >= f && v.y >= f && v.z >= f;
			}


			template <typename T>
			inline bool operator != (Vec3<T> v, Vec3<T> f) {
				return f.x != v.x || f.y != v.y || f.z != v.z;
			}


			template <typename T>
			inline bool operator == (Vec3<T> v, Vec3<T> f) {
				return f.x == v.x && f.y == v.y && f.z == v.z;
			}


			template <typename T>
			inline Vec3<T> mini(Vec3<T> a, Vec3<T> b) {
				return Vec3<T>(
					_function::mini<T>(a.x, b.x),
					_function::mini<T>(a.y, b.y),
					_function::mini<T>(a.z, b.z));
			}


			template <typename T>
			inline Vec3<T> maxi(Vec3<T> a, Vec3<T> b) {
				return Vec3<T>(
					_function::maxi<T>(a.x, b.x),
					_function::maxi<T>(a.y, b.y),
					_function::maxi<T>(a.z, b.z));
			}


			template <typename T>
			inline Vec3<T> floor(Vec3<T> a) {
				return Vec3<T>(
					_function::floor<T>(a.x),
					_function::floor<T>(a.y),
					_function::floor<T>(a.z));
			}


			template <typename T>
			inline Vec3<T> ceil(Vec3<T> a) { 
				return Vec3<T>(
					_function::ceil<T>(a.x),
					_function::ceil<T>(a.y),
					_function::ceil<T>(a.z));
			}


			template <typename T>
			inline Vec2<T> abs(Vec2<T> a) {
				return Vec2<T>(_function::abs<T>(a.x),
					_function::abs<T>(a.y));
			}


			template <typename T>
			inline Vec3<T> abs(Vec3<T> a) {
				return Vec3<T>(
					_function::abs<T>(a.x),
					_function::abs<T>(a.y),
					_function::abs<T>(a.z));
			}


			template <typename T>
			inline T dotS(Vec3<T> a, Vec3<T> b) {
				return a.x * b.x + a.y * b.y + a.z * b.z;
			}


			template <typename T>
			inline Vec3<T> cCross(Vec3<T> a, Vec3<T> b) {
				return Vec3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
			}


			template <typename T>
			inline Vec3<T> cReflect(Vec3<T> I, Vec3<T> N) {
				return I - (T)2 * dotS(N, I) * N;
			}
			

			using dVec3 = Vec3<double>;
			using fVec3 = Vec3<float>;
			using bVec3 = Vec3<bool>;
			using iVec3 = Vec3<int>;
			using i8Vec3 = Vec3<int8_t>;
			using i16Vec3 = Vec3<int16_t>;
			using iVec3 = Vec3<int32_t>;
			using i32Vec3 = Vec3<int32_t>;
			using i64Vec3 = Vec3<int64_t>;
			using u8Vec3 = Vec3<uint8_t>;
			using u16Vec3 = Vec3<uint16_t>;
			using uVec3 = Vec3<uint32_t>;
			using u32Vec3 = Vec3<uint32_t>;
			using u64Vec3 = Vec3<uint64_t>;


			inline bool valid(const fVec3& a) {
				return _function::floatIsValid(a.x) &&
					_function::floatIsValid(a.y) &&
					_function::floatIsValid(a.z);
			}

			
			inline bool operator == (const fVec3& v, const fVec3& f) {
				return IS_FLOAT_EQUAL(f.x, v.x) &&
					IS_FLOAT_EQUAL(f.y, v.y) &&
					IS_FLOAT_EQUAL(f.z, v.z);
			}


			inline bool operator != (const fVec3& v, const fVec3& f) {
				return IS_FLOAT_DIFFERENT(f.x, v.x) ||
					IS_FLOAT_DIFFERENT(f.y, v.y) ||
					IS_FLOAT_DIFFERENT(f.z, v.z);
			}


		}//namespace libmath
	}//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I_VEC3___