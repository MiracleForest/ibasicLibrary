#include "../../../include/icore/lib/libmath/math.h"


SPACE(i) {
	SPACE(core) {
		SPACE(libmath) {
			SPACE(_function) {

				inline bool floatIsValid(float x) {
					const union {
						float f;
						int32_t i;
					} v = { x };
					return (v.i & 0x7f800000) != 0x7f800000;
				}

			}//SPACE(_function)
		}//SPACE(libmath)
	}//SPACE(core)
}//SPACE(i)