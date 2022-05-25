/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:rect.hpp
* @creation time:2022.5.23.13:07
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBMATH_RECT___
#define ___MIRACLEFOREST_I__LIBMATH_RECT___

#include "../../family/imacrofamily.h"
#include "vec4.hpp"
#include "math.h"

namespace i {
	namespace core {
		namespace libmath {

			/// <summary>
			/// 
			/// </summary>
			/// <note>
			/// bottom left to top right
			/// </note>
			/// <typeparam name="T"></typeparam>
			template <typename T>
			class rect {
			public:
				T x, y, w, h;
				T left, right, top, bottom;
			public:
				rect() { setRect((T)0, (T)0, (T)0, (T)0); }
				rect(T vX, T vY, T vW, T vH) { setRect(vX, vY, vW, vH); }
				rect(Vec2<T> xy, Vec2<T> zw) { setRect(xy.x, xy.y, zw.x, zw.y); }
			public:

				/// <summary>
				/// 
				/// </summary>
				/// <param name="xy"></param>
				/// <param name="zw"></param>
				void setRect(Vec2<T> xy, Vec2<T> zw) { setRect(xy.x, xy.y, zw.x, zw.y); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vX"></param>
				/// <param name="vY"></param>
				/// <param name="vW"></param>
				/// <param name="vH"></param>
				void setRect(T vX, T vY, T vW, T vH) { x = vX; y = vY; w = vW; h = vH; left = vX; right = vX + vW; top = vY + vH; bottom = vY; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> rightBottom() const { return Vec2<T>(right, bottom); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> rightTop() const { return Vec2<T>(right, top); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> leftBottom() const { return Vec2<T>(left, bottom); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> leftTop() const { return Vec2<T>(left, top); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> center() const { return Vec2<T>((left + right) / (T)2, (top + bottom) / (T)2); }
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T>* vertices() { Vec2<T>* buf = new Vec2<T>[4]; buf[0] = leftBottom(); buf[1] = leftTop(); buf[2] = rightTop(); buf[3] = rightBottom(); return buf; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="scaleX"></param>
				/// <param name="scaleY"></param>
				/// <returns></returns>
				Vec2<T>* texCoords(T scaleX, T scaleY) { Vec2<T>* buf = new Vec2<T>[4]; buf[0] = Vec2<T>((T)0, (T)0); buf[1] = Vec2<T>((T)scaleX, (T)0); buf[2] = Vec2<T>(scaleX, scaleY); buf[3] = Vec2<T>((T)0, scaleY); return buf; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vw"></param>
				void setWidth(T vw) { w = vw; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vh"></param>
				void setHeight(T vh) { h = vh; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vleft"></param>
				void SnackLeft(T vleft) { x = vleft; w -= vleft;	left = x; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vright"></param>
				void SnackRight(T vright) { w -= vright; right = w + x; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vtop"></param>
				void SnackTop(T vtop) { h -= vtop; top = h + y; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vbottom"></param>
				void SnackBottom(T vbottom) { y = vbottom; h -= vbottom; bottom = y; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="pt"></param>
				/// <returns></returns>
				bool IsContainPoint(Vec2<T> pt) { if (pt.x > left)if (pt.x < right)if (pt.y > bottom)if (pt.y < top)return true; return false; }
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="v0"></param>
				/// <param name="v1"></param>
				/// <returns></returns>
				bool IsIntersectedByLine(Vec2<T> v0, Vec2<T> v1) {
					if ((v0.x <= left && v1.x <= left) ||
						(v0.y <= bottom && v1.y <= bottom) ||
						(v0.x >= right && v1.x >= right) ||
						(v0.y >= top && v1.y >= top))
						return false; // Completely outside.
					if (IS_FLOAT_EQUAL(v1.y, v0.y) && IS_FLOAT_EQUAL(v1.x, v0.x)) return true;
					if (IS_FLOAT_DIFFERENT(v1.x, v0.x)) // avoid div by zero
					{
						float _m = (v1.y - v0.y) / (v1.x - v0.x);
						float _y = _m * (left - v0.x) + v0.y;
						if (_y >= bottom && _y <= top) return true;
						_y = _m * (right - v0.x) + v0.y;
						if (_y >= bottom && _y <= top) return true;
						if (IS_FLOAT_DIFFERENT(_m, 0.0f)) // avoid div by zero
						{
							float _x = (bottom - v0.y) / _m + v0.x;
							if (_x >= left && _x <= right) return true;
							_x = (top - v0.y) / _m + v0.x;
							if (_x >= left && _x <= right) return true;
						}
					}
					return false;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <param name="vPos"></param>
				/// <param name="vRadius"></param>
				/// <returns></returns>
				bool IsIntersectedByCircle(Vec2<T> vPos, T vRadius) // only for axis aligned box
				{
					T d = maxi<T>(abs<T>(center() - vPos) - Size() / (T)2, (T)0).lengthSquared();
					return d < vRadius* vRadius;
				}
				
				/// <summary>
				/// 
				/// </summary>
				/// <returns></returns>
				Vec2<T> Size() { return Vec2<T>(w, h); }
			};

			typedef rect<int> irect;
			typedef rect<double> drect;
			typedef rect<float> frect;

			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a"></param>
			/// <returns></returns>
			template <typename T> inline rect<T> floor(const rect<T>& a) {
				return rect<T>(
					_function::floor<T>(a.x),
					_function::floor<T>(a.y),
					_function::floor<T>(a.w),
					_function::floor<T>(a.h));
			}
			
			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a"></param>
			/// <returns></returns>
			template <typename T> inline rect<T> ceil(const rect<T>& a) {
				return rect<T>(
					_function::ceil<T>(a.x),
					_function::ceil<T>(a.y),
					_function::ceil<T>(a.w),
					_function::ceil<T>(a.h));
			}

			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="v"></param>
			/// <param name="f"></param>
			/// <returns></returns>
			template <typename T> inline bool operator == (rect<T> v, rect<T> f) {
				return f.x == v.x &&
					f.y == v.y &&
					f.w == v.w &&
					f.h == v.h;
			}
			
			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="v"></param>
			/// <param name="f"></param>
			/// <returns></returns>
			template <typename T> inline bool operator != (rect<T> v, rect<T> f) {
				return f.x != v.x ||
					f.y != v.y ||
					f.w != v.w ||
					f.h != v.h;
			}

		}
	}
}

#endif //!___MIRACLEFOREST_I__LIBMATH_RECT___