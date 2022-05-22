#include "../../../include/icore/lib/libmath/math.h"


namespace i {
	namespace core {
		namespace libmath {
			namespace _function {

				inline bool floatIsValid(float x) {
					const union {
						float f;
						int32_t i;
					} v = { x };
					return (v.i & 0x7f800000) != 0x7f800000;
				}

			}
		}
	}
}