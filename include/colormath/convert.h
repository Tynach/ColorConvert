#pragma once
#include <colormath/color_space.h>

namespace colormath {
	/**
	 * Abstract color space conversion class; subclass to create ways to
	 * convert between two specific types of color spaces
	 */
	class convert {
	public:
		convert() {}
		virtual ~convert() {}
	};
}