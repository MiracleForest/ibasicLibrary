/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：vec4.hpp
* @创建时间：2022.5.22.12:17
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* Vec4
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I__LIBMATH_VEC4___
#define ___MIRACLEFOREST_I__LIBMATH_VEC4___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "vec3.hpp"


SPACE(i) {
	SPACE(core) {
		SPACE(libmath) {

			template <typename T>
			class Vec4{
			public:

				Vec4() : x((T)0), y((T)0), z((T)0), w((T)0) {}
				
				template <typename U>
				Vec4<T>(Vec4<U> a) {
					x = (T)a.x;
					y = (T)a.y;
					z = (T)a.z;
					w = (T)a.w; 
				}
				
				Vec4(Vec2<T> xy, Vec2<T> zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
				
				Vec4(Vec3<T> xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
				
				Vec4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
				
				Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
				
				Vec4(type::istring vec, char c = ';', Ptr<Vec4<T>> def = nullptr){
					if (def){
						x = def->x;
						y = def->y;
						z = def->z;
						w = def->w;
					}
					::std::vector<T> result = _function::StringToNumberVector<T>(vec.data(), c);
					const size_t s = result.size();
					if (s > 0) x = result[0];
					if (s > 1) y = result[1];
					if (s > 2) z = result[2];
					if (s > 3) w = result[3];
				}
				
				Vec4(type::istring vec, char c = ';', int n = 4, Ptr<Vec4<T>> def = nullptr){
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
					::std::vector<T> result = _function::StringToNumberVector<T>(vec.data(), c);
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
				

				T& operator [] (CRef<size_t> i) {
					return (&x)[i];
				}
				

				Vec4<T> offset(CRef<T> vX, CRef<T> vY, CRef<T> vZ, CRef<T> vW) const {
					return Vec4<T>(x + vX, y + vY, z + vZ, w + vW); 
				}
				

				void set(CRef<T> vX, CRef<T> vY, CRef<T> vZ, CRef<T> vW) {
					x = vX; y = vY; z = vZ; w = vW;
				}
				

				Vec4<T> operator -() const {
					return Vec4<T>(-x, -y, -z, -w);
				}
				

				Vec4<T> operator !() const {
					return Vec4<T>(!x, !y, !z, !w);
				}
				

				Vec2<T> xy() const {
					return Vec2<T>(x, y);
				}
				

				Vec3<T> xyz() const {
					return Vec3<T>(x, y, z);
				}
				
				
				Vec2<T> zw() const {
					return Vec2<T>(z, w);
				}

				
				Ref<Vec4<T>> operator ++ () {
					++x;
					++y;
					++z;
					++w;
					return *this;
				} 
				
				
				Ref<Vec4<T>> operator -- () {
					--x;
					--y;
					--z;
					--w;
					return *this;
				} 
				
				
				Vec4<T> operator ++ (int) {
					Vec4<T> tmp = *this;
					++* this;
					return tmp;
				} 
				
				
				Vec4<T> operator -- (int) {
					Vec4<T> tmp = *this;
					--* this;
					return tmp;
				}
				
			
				void operator += (CRef<T> a) {
					x += a;
					y += a;
					z += a;
					w += a;
				}
				
				
				void operator += (Ref<Vec4<T>> v) {
					x += v.x;
					y += v.y;
					z += v.z;
					w += v.w;
				}
				
				 
				void operator -= (CRef<T> a) {
					x -= a;
					y -= a;
					z -= a;
					w -= a;
				}
				
				 
				void operator -= (Ref<Vec4<T>> v) {
					x -= v.x;
					y -= v.y;
					z -= v.z;
					w -= v.w;
				}
				
				 
				bool operator == (CRef<T> a) {
					return (x == a) && (y == a) && (z == a) && (w == a);
				}
				
				 
				bool operator == (Ref<Vec4<T>> v) {
					return (x == v.x) &&
						(y == v.y) &&
						(z == v.z) &&
						(w == v.w);
				}
				
				 
				bool operator != (CRef<T> a) {
					return (x != a) || (y != a) || (z != a) || (w != a);
				}
				
				 
				bool operator != (Ref<Vec4<T>> v) {
					return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
				}
				
				 
				void operator *= (CRef<T> a) {
					x *= a;
					y *= a;
					z *= a;
					w *= a;
				}
				
				 
				void operator *= (Ref<Vec4<T>> v) {
					x *= v.x;
					y *= v.y;
					z *= v.z;
					w *= v.w;
				}
				
				 
				void operator /= (CRef<T> a) {
					x /= a;
					y /= a;
					z /= a;
					w /= a;
				}
				
				 
				void operator /= (Ref<Vec4<T>> v) {
					x /= v.x;
					y /= v.y;
					z /= v.z;
					w /= v.w;
				}
				

				Vec2<T> sizeLBRT() const {
					return Vec2<T>(z - x, w - y);
				}
				
				 
				Vec2<T> pos() const {
					return xy();
				}
				
				 
				Vec2<T> size() const {
					return zw();
				}
				
				 
				T length() const {
					return (T)sqrt(lengthSquared());
				}
				
				 
				T lengthSquared() const {
					return x * x + y * y + z * z + w * w;
				}
				
				 
				T normalize() {
					T _length = length();
					if (_length < (T)1e-5) { return (T)0; }
					T _invLength = (T)1 / _length;
					x *= _invLength;
					y *= _invLength;
					z *= _invLength;
					w *= _invLength;
					return _length;
				}
				
				 
				Vec4<T> getNormalized() const {
					Vec4<T> n = Vec4<T>(x, y, z, w);
					n.normalize();
					return n;
				}
				
				 
				bool emptyAND() const {
					return x == (T)0 &&
						y == (T)0 &&
						z == (T)0 &&
						w == (T)0;
				}
				
				 
				bool emptyOR() const {
					return x == (T)0 ||
						y == (T)0 ||
						z == (T)0 ||
						w == (T)0;
				}
				
				 
				T sum() const {
					return x + y + z + w;
				}
				
				 
				T sumAbs() const {
					return _function::abs<T>(x) +
						_function::abs<T>(y) +
						_function::abs<T>(z) +
						_function::abs<T>(w);
				}
				
				 
				type::istring string(char c = ';') const {
					return (std::to_string(x) + c +
						std::to_string(y) + c +
						std::to_string(z) + c +
						std::to_string(w));
				}
				
				 
				T mini() const {
					return _function::internalMini<T>(
						x, _function::internalMini<T>(
							y, _function::internalMini<T>(
								z, w)
							)
						);
				}
				
				 
				T maxi() const {
					return _function::internalMaxi<T>(
						x, _function::internalMaxi<T>(
							y, _function::internalMaxi<T>(
								z, w)
							)
						);
				}


			public:
				T x, y, z, w;
			};


			template <typename T>
			inline Ref<Vec4<T>> operator ++ (Ref<Vec4<T>> v) {
				++v;
				return v;
			} 


			template <typename T>
			inline Ref<Vec4<T>> operator -- (Ref<Vec4<T>> v) {
				--v;
				return v;
			} 


			template <typename T>
			inline Vec4<T> operator ++ (Ref<Vec4<T>> v, int){ 
				Vec4<T> a = v;
				++a;
				return a;
			} 


			template <typename T>
			inline Vec4<T> operator -- (Ref<Vec4<T>> v, int) {
				Vec4<T> a = v;
				--a;
				return a;
			} 


			template <typename T>
			inline Vec4<T> operator + (Vec4<T> v, T f) {
				return Vec4<T>(v.x + f,
					v.y + f,
					v.z + f,
					v.w + f);
			}


			template <typename T>
			inline Vec4<T> operator + (Vec4<T> v, Vec4<T> f) {
				return Vec4<T>(v.x + f.x,
					v.y + f.y,
					v.z + f.z,
					v.w + f.w);
			}


			template <typename T>
			inline Vec4<T> operator - (Vec4<T> v, T f) {
				return Vec4<T>(v.x - f,
					v.y - f,
					v.z - f,
					v.w - f);
			}


			template <typename T>
			inline Vec4<T> operator - (T f, Vec4<T> v) {
				return Vec4<T>(f - v.x,
					f - v.y,
					f - v.z,
					f - v.w); 
			}


			template <typename T>
			inline Vec4<T> operator - (Vec4<T> v, Vec4<T> f) {
				return Vec4<T>(v.x - f.x,
					v.y - f.y,
					v.z - f.z,
					v.w - f.w);
			}


			template <typename T>
			inline Vec4<T> operator * (Vec4<T> v, T f) {
				return Vec4<T>(v.x * f,
					v.y * f,
					v.z * f,
					v.w * f);
			}


			template <typename T>
			inline Vec4<T> operator * (Vec4<T> v, Vec4<T> f) {
				return Vec4<T>(v.x *f.x,
					v.y * f.y,
					v.z * f.z,
					v.w * f.w
					);
			}


			template <typename T>
			inline Vec4<T> operator / (Vec4<T> v, T f) {
				return Vec4<T>(v.x /
					f, v.y /
					f, v.z /
					f, v.w /
					f);
			}


			template <typename T>
			inline Vec4<T> operator / (Vec4<T> v, Vec4<T> f) {
				return Vec4<T>(v.x /
					f.x, v.y /
					f.y, v.z /
					f.z, v.w /
					f.w);
			}


			template <typename T>
			inline bool operator < (Vec4<T> v, Vec4<T> f) {
				return v.x < f.x&&
					v.y < f.y&&
					v.z < f.z&&
					v.w < f.w; 
			}


			template <typename T>
			inline bool operator < (Vec4<T> v, T f) {
				return v.x < f&&
					v.y < f&&
					v.z < f&&
					v.w < f;
			}


			template <typename T>
			inline bool operator > (Vec4<T> v, Vec4<T> f) {
				return v.x > f.x &&
					v.y > f.y &&
					v.z > f.z &&
					v.w > f.w;
			}


			template <typename T>
			inline bool operator > (Vec4<T> v, T f) {
				return v.x > f &&
					v.y > f &&
					v.z > f &&
					v.w > f;
			}


			template <typename T>
			inline bool operator <= (Vec4<T> v, Vec4<T> f) {
				return v.x <= f.x &&
					v.y <= f.y &&
					v.z <= f.z &&
					v.w <= f.w;
			}


			template <typename T>
			inline bool operator <= (Vec4<T> v, T f) {
				return v.x <= f &&
					v.y <= f &&
					v.z <= f &&
					v.w <= f; 
			}


			template <typename T>
			inline bool operator >= (Vec4<T> v, Vec4<T> f) {
				return v.x >= f.x &&
					v.y >= f.y &&
					v.z >= f.z &&
					v.w >= f.w; 
			}


			template <typename T>
			inline bool operator >= (Vec4<T> v, T f) { 
				return v.x >= f &&
					v.y >= f && 
					v.z >= f &&
					v.w >= f; 
			}


			template <typename T>
			inline bool operator == (Vec4<T> v, Vec4<T> f) {
				return f.x == v.x &&
					f.y == v.y &&
					f.z == v.z &&
					f.w == v.w;
			}


			template <typename T>
			inline bool operator != (Vec4<T> v, Vec4<T> f) {
				return f.x != v.x ||
					f.y != v.y ||
					f.z != v.z ||
					f.w != v.w;
			}


			template <typename T>
			inline Vec4<T> mini(Vec4<T> a, Vec4<T> b) {
				return Vec4<T>(
					_function::mini<T>(a.x, b.x),
					_function::mini<T>(a.y, b.y),
					_function::mini<T>(a.z, b.z),
					_function::mini<T>(a.w, b.w)
					);
			}


			template <typename T>
			inline Vec4<T> maxi(Vec4<T> a, Vec4<T> b) {
				return Vec4<T>(
					_function::maxi<T>(a.x, b.x),
					_function::maxi<T>(a.y, b.y),
					_function::maxi<T>(a.z, b.z),
					_function::maxi<T>(a.w, b.w)
					);
			}


			template <typename T>
			inline Vec4<T> floor(Vec4<T> a) {
				return Vec4<T>(
					_function::floor<T>(a.x),
					_function::floor<T>(a.y),
					_function::floor<T>(a.z),
					_function::floor<T>(a.w)
					);
			}


			template <typename T>
			inline Vec4<T> ceil(Vec4<T> a) {
				return Vec4<T>(
					_function::ceil<T>(a.x),
					_function::ceil<T>(a.y),
					_function::ceil<T>(a.z),
					_function::ceil<T>(a.w)
					);
			}


			template <typename T>
			inline Vec4<T> abs(Vec4<T> a) {
				return Vec4<T>(
					_function::abs<T>(a.x),
					_function::abs<T>(a.y),
					_function::abs<T>(a.z),
					_function::abs<T>(a.w));
			}


			template <typename T>
			inline Vec4<T> sign(Vec4<T> a) {
				return Vec4<T>(
					a.x < (T)0 ? (T)-1 : (T)1,
					a.y < (T)0 ? (T)-1 : (T)1,
					a.z < (T)0 ? (T)-1 : (T)1,
					a.w < (T)0 ? (T)-1 : (T)1);
			}


			template <typename T>
			inline Vec4<T> sin(Vec4<T> a) {
				return Vec4<T>(
					_function::sin<T>(a.x),
					_function::sin<T>(a.y),
					_function::sin<T>(a.z),
					_function::sin<T>(a.w)
					);
			}


			template <typename T>
			inline Vec4<T> cos(Vec4<T> a) {
				return Vec4<T>(
					_function::cos<T>(a.x),
					_function::cos<T>(a.y),
					_function::cos<T>(a.z),
					_function::cos<T>(a.w)
					); 
			}


			template <typename T>
			inline Vec4<T> tan(Vec4<T> a) {
				return Vec4<T>(
					_function::tan<T>(a.x),
					_function::tan<T>(a.y),
					_function::tan<T>(a.z),
					_function::tan<T>(a.w)
					);
			}
			
			
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

			

			inline bool valid(CRef<fVec4> a) {
				return _function::floatIsValid(a.x) &&
					_function::floatIsValid(a.y) &&
					_function::floatIsValid(a.z) &&
					_function::floatIsValid(a.w);
			}
			
			
			inline bool operator == (CRef<fVec4> v, CRef<fVec4> f) {
				return IS_FLOAT_EQUAL(f.x, v.x) &&
					IS_FLOAT_EQUAL(f.y, v.y) &&
					IS_FLOAT_EQUAL(f.z, v.z) &&
					IS_FLOAT_EQUAL(f.w, v.w);
			}
			
			
			inline bool operator != (CRef<fVec4> v, CRef<fVec4> f) {
				return IS_FLOAT_DIFFERENT(f.x, v.x) ||
					IS_FLOAT_DIFFERENT(f.y, v.y) ||
					IS_FLOAT_DIFFERENT(f.z, v.z) ||
					IS_FLOAT_DIFFERENT(f.w, v.w);
			}

		}//SPACE(libmath)
	}//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I__LIBMATH_VEC4___