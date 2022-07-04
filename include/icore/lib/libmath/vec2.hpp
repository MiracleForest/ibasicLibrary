/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：vec2.hpp
* @创建时间：2022.5.20.21:52
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 祝大家520快乐！
* Vec2
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I__LIBMATH_VEC2___
#define ___MIRACLEFOREST_I__LIBMATH_VEC2___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "../../type/istring.hpp"
#include "../../../mcppstd/thread"

#ifdef __WINDOWS__
#include <Windows.h>
#endif//__WINDOWS__

SPACE(i) {
	SPACE(core) {
		SPACE(libmath) {

			

			template <typename T>
			class Vec2 {
			public:

				Vec2<T>() {
					x = (T)0;
					y = (T)0;
				}

				template <typename U>
				Vec2<T>(CRef<Vec2<U>> a) {
					x = (T)a.x;
					y = (T)a.y;
				}

				Vec2<T>(CRef<T> a) {
					x = a;
					y = a; 
				}

				Vec2<T>(CRef<T> a, CRef<T> b) {
					x = a;
					y = b;
				}

				Vec2<T>(CRef<type::istring> Vec, CRef<char> c = ';', Ptr<Vec2<T>> def = nullptr) {
					if (def) {
						x = def->x;
						y = def->y;
					}
					::std::vector<T> result = _function::StringToNumberVector<T>(Vec.data(), c);
					const size_t s = result.size();
					if (s > 0) x = result[0];
					if (s > 1) y = result[1];
				}
				

				T& operator [] (CRef<size_t> i) {
					return (&x)[i];
				}
				

				Vec2<T> offset(CRef<T> vX, CRef<T> vY) const {
					return Vec2<T>(x + vX, y + vY);
				}


				void set(CRef<T> vX, CRef<T> vY) {
					x = vX;
					y = vY;
				}


				Vec2<T> operator -() const {
					return Vec2<T>(-x, -y);
				}


				Vec2<T> operator !() const {
					return Vec2<T>(!x, !y);
				}

				

				Ref<Vec2<T>> operator ++ () {
					++x; ++y; return *this;
				}

				

				Ref<Vec2<T>> operator -- () {
					--x; --y; return *this;
				}

				

				Vec2<T> operator ++ (int) {
					Vec2<T> tmp = *this;
					++* this; return tmp;
				}

				

				Vec2<T> operator -- (int) {
					Vec2<T> tmp = *this;
					--* this;
					return tmp;
				}

				

				void operator += (CRef<T> a) {
					x += a; y += a; 
				}


				void operator += (CRef<Vec2<T>> v) {
					x += v.x;
					y += v.y;
				}


				void operator -= (CRef<T> a) {
					x -= a;
					y -= a;
				}
				

				void operator -= (CRef<Vec2<T>> v) {
					x -= v.x;
					y -= v.y; 
				}


				bool operator == (CRef<T> a) {
					return (x == a) && (y == a);
				}
				

				bool operator == (CRef<Vec2<T>> v) {
					return (x == v.x) && (y == v.y);
				}


				bool operator != (CRef<T> a) {
					return (x != a) || (y != a);
				}


				bool operator != (CRef<Vec2<T>> v) {
					return (x != v.x) || (y != v.y); 
				}


				void operator *= (CRef<T> a) {
					x *= a;
					y *= a; 
				}


				void operator *= (CRef<Vec2<T>> v) {
					x *= v.x;
					y *= v.y; 
				}


				void operator /= (CRef<T> a) { 
					x /= a;
					y /= a;
				}


				void operator /= (CRef<Vec2<T>> v) { 
					x /= v.x; 
					y /= v.y; 
				}
				

				T lengthSquared() const {
					return x * x + y * y;
				}
				

				T length() const {
					return (T)sqrt(lengthSquared());
				}
				

				T normalize() {
					T _length = length();
					if (_length < (T)1e-5) { return (T)0.0; }
					T _invLength = (T)1.0 / _length;
					x *= _invLength;
					y *= _invLength;
					return _length;
				}


				Vec2<T> getNormalized() const {
					Vec2<T> n = Vec2<T>(x, y);
					n.normalize();
					return n;
				}


				T sum() const {
					return x + y;
				}
				

				T sumAbs() const {
					return _function::abs<T>(x) + _function::abs<T>(y); 
				}
				

				bool emptyAND() const {
					return x == (T)0 && y == (T)0;
				}
				

				bool emptyOR() const {
					return x == (T)0 || y == (T)0;
				}


				type::istring string(CRef<char> c = ';') const {
					return (std::to_string(x) + c + std::to_string(y));
				}
				

				template <typename U>
				U ratioXY() const {
					if (y != (T)0) return (U)x / (U)y;
					return (U)0;
				}
				

				template <typename U>
				U ratioYX() const {
					if (x != (T)0) return (U)y / (U)x;
					return (U)0;
				}
				

				T mini() const {
					return _function::internalMini<T>(x, y);
				}
				

				T maxi() const {
					return _function::internalMaxi<T>(x, y);
				}

			public:
				T x, y;
			};

			template <typename T>
			inline Ref<Vec2<T>> operator ++ (Ref<Vec2<T>> v) {
				++v;
				return v;
			}


			template <typename T>
			inline Ref<Vec2<T>> operator -- (Ref<Vec2<T>> v) {
				--v;
				return v;
			}


			template <typename T>
			inline Vec2<T> operator ++ (Ref<Vec2<T>> v, int) {
				Vec2<T> a = v;
					++a;
					return a;
			}


			template <typename T>
			inline Vec2<T> operator -- (Ref<Vec2<T>> v, int) {
				Vec2<T> a = v;
				--a;
				return a;
			}


			template <typename T>
			inline Vec2<T> operator + (Vec2<T> v, T f) {
				return Vec2<T>(v.x + f, v.y + f);
			}


			template <typename T>
			inline Vec2<T> operator + (T f, Vec2<T> v) {
				return Vec2<T>(v.x + f, v.y + f); 
			}


			template <typename T>
			inline Vec2<T> operator + (Vec2<T> v, Vec2<T> f) {
				return Vec2<T>(v.x + f.x, v.y + f.y);
			}


			template <typename T>
			inline Vec2<T> operator - (Vec2<T> v, T f) {
				return Vec2<T>(v.x - f, v.y - f);
			}


			template <typename T>
			inline Vec2<T> operator - (T f, Vec2<T> v) {
				return Vec2<T>(f - v.x, f - v.y);
			}


			template <typename T>
			inline Vec2<T> operator - (Vec2<T> v, Vec2<T> f) {
				return Vec2<T>(v.x - f.x, v.y - f.y); 
			}


			template <typename T> 
			inline Vec2<T> operator * (Vec2<T> v, T f) {
				return Vec2<T>(v.x * f, v.y * f);
			}


			template <typename T>
			inline Vec2<T> operator * (T f, Vec2<T> v) {
				return Vec2<T>(v.x * f, v.y * f);
			}


			template <typename T>
			inline Vec2<T> operator * (Vec2<T> v, Vec2<T> f) {
				return Vec2<T>(v.x * f.x, v.y * f.y); 
			}


			template <typename T>
			inline Vec2<T> operator / (Vec2<T> v, T f) {
				return Vec2<T>(v.x / f, v.y / f); 
			}


			template <typename T>
			inline Vec2<T> operator / (T f, Vec2<T> v) {
				return Vec2<T>(f / v.x, f / v.y);
			}


			template <typename T>
			inline Vec2<T> operator / (Vec2<T> v, Vec2<T> f) {
				return Vec2<T>(v.x / f.x, v.y / f.y);
			}


			template <typename T>
			inline bool operator < (Vec2<T> v, Vec2<T> f) {
				return v.x < f.x&& v.y < f.y; 
			}


			template <typename T>
			inline bool operator < (Vec2<T> v, T f) {
				return v.x < f&& v.y < f;
			}


			template <typename T>
			inline bool operator > (Vec2<T> v, Vec2<T> f) { 
				return v.x > f.x && v.y > f.y;
			}


			template <typename T>
			inline bool operator > (Vec2<T> v, T f) {
				return v.x > f && v.y > f; 
			}


			template <typename T>
			inline bool operator <= (Vec2<T> v, Vec2<T> f) {
				return v.x <= f.x && v.y <= f.y; 
			}


			template <typename T>
			inline bool operator <= (Vec2<T> v, T f) {
				return v.x <= f && v.y <= f; 
			}


			template <typename T>
			inline bool operator >= (Vec2<T> v, Vec2<T> f) {
				return v.x >= f.x && v.y >= f.y; 
			}


			template <typename T>
			inline bool operator >= (Vec2<T> v, T f) {
				return v.x >= f && v.y >= f;
			}


			template <typename T>
			inline bool operator != (Vec2<T> v, Vec2<T> f) { 
				return f.x != v.x || f.y != v.y;
			}


			template <typename T>
			inline bool operator == (Vec2<T> v, Vec2<T> f) {
				return f.x == v.x && f.y == v.y;
			}


			template <typename T>
			inline Vec2<T> floor(Vec2<T> a) {
				return Vec2<T>(
					_function::floor(a.x),
					_function::floor(a.y));
			}


			template <typename T>
			inline Vec2<T> fract(Vec2<T> a) {
				return Vec2<T>(_function::fract(a.x),
					_function::fract(a.y));
			}


			template <typename T>
			inline Vec2<T> ceil(Vec2<T> a) { 
				return Vec2<T>(_function::ceil(a.x),
					_function::ceil(a.y)); 
			}


			template <typename T>
			inline Vec2<T> mini(Vec2<T> a, Vec2<T> b) {
				return Vec2<T>(_function::mini(a.x, b.x),
					_function::mini(a.y, b.y));
			}


			template <typename T>
			inline Vec2<T> maxi(Vec2<T> a, Vec2<T> b) {
				return Vec2<T>(_function::maxi(a.x, b.x),
					_function::maxi(a.y, b.y));
			}


			template <typename T>
			inline T dot(Vec2<T> a, Vec2<T> b) { 
				return a.x * b.x + a.y * b.y;
			}


			template <typename T>
			inline T det(Vec2<T> a, Vec2<T> b) { 
				return a.x * b.y - a.y * b.x; 
			}


			template <typename T>
			inline Vec2<T> cross(Vec2<T> a, Vec2<T> b) { 
				return Vec2<T>(
					a.x * b.y - a.y * b.x,
					a.y * b.x - a.x * b.y);
			}


			template <typename T>
			inline Vec2<T> reflect(Vec2<T> I, Vec2<T> N) {
				return I - (T)2 * dotS(N, I) * N; 
			}


			template <typename T>
			inline Vec2<T> sign(Vec2<T> a) {
				return Vec2<T>(a.x < (T)0 ? -(T)1 : (T)1,
					a.y < (T)0 ? (T)-1 : (T)1);
			}


			template <typename T>
			inline Vec2<T> sin(Vec2<T> a) {
				return Vec2<T>(_function::sin<T>(a.x),
					_function::sin<T>(a.y));
			}


			template <typename T>
			inline Vec2<T> cos(Vec2<T> a) {
				return Vec2<T>(_function::cos<T>(a.x),
					_function::cos<T>(a.y)); 
			}
			
			
			template <typename T>
			inline Vec2<T> tan(Vec2<T> a) {
				return Vec2<T>(
					_function::tan<T>(a.x),
					_function::tan<T>(a.y));
			}
			

			template <typename T>
			inline Vec2<T> atan(Vec2<T> a) {
				return Vec2<T>(
					_function::atan<T>(a.x),
					_function::atan<T>(a.y)
					);
			}
			
			
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


			inline fvec2 convert(CRef<ivec2> v) {
				return fvec2(
					(float)v.x,
					(float)v.y
				);
			}


			inline ivec2 convert(CRef<fvec2> v) {
				return ivec2(
					(int)v.x,
					(int)v.y);
			}


			inline bool valid(CRef<fvec2> a) {
				return _function::floatIsValid(a.x) &&
					_function::floatIsValid(a.y);
			}


			inline bool operator == (CRef<fvec2> v, CRef<fvec2> f) {
				return (IS_FLOAT_EQUAL(f.x, v.x) &&
					IS_FLOAT_EQUAL(f.y, v.y));
			}

			inline bool operator != (CRef<fvec2> v, CRef<fvec2> f) {
				return (
					IS_FLOAT_DIFFERENT(f.x, v.x) ||
					IS_FLOAT_DIFFERENT(f.y, v.y)
					);
			}

			template <typename T>
			inline T prototypeRadAngleFromVec2(Vec2<T> vec) {
				T angle = 0.0f;
				if (vec.lengthSquared() > T(0) && vec.x != T(0)) {
					angle = _function::atan<T>(vec.y / vec.x);
				}
				return angle;
			}

			inline float radAngleFromVec2(CRef<fvec2> vec) {
				return prototypeRadAngleFromVec2(vec);
			}

			inline double radAngleFromVec2(CRef<dvec2> vec) {
				return prototypeRadAngleFromVec2(vec);
			}

		}//SPACE(libmath)
	}//SPACE(core) 
}//SPACE(i)

#endif //!___MIRACLEFOREST_I__LIBMATH_VEC2___