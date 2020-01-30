#pragma once

#include <colorvec/vec3.h>
#include <colorvec/mat3.h>

namespace colormath {
	colorvec::mat3 const BRADFORD = {
		0.8951, -0.7502, 0.0389,
		0.2664, 1.7135, -0.0685,
		-0.1614, 0.0367, 1.0296
	};

	inline colorvec::vec3 const chromaticity(floatp const &x, const floatp &y)
	{
		return {x, y, 1.0 - x - y};
	}

	inline colorvec::vec3 const bright(colorvec::vec3 const &white)
	{
		return {white.x/white.y, 1, white.z/white.y};
	}
}