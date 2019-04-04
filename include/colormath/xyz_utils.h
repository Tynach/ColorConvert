#pragma once
#include <vecmath/vec3.h>
#include <vecmath/mat3.h>
using vecmath::vec3;
using vecmath::mat3;

namespace colormath {
	const mat3 BRADFORD = {
		0.8951, -0.7502, 0.0389,
		0.2664, 1.7135, -0.0685,
		-0.1614, 0.0367, 1.0296
	};

	const vec3 chromaticity(const floatp& x, const floatp& y)
	{
		return {x, y, 1.0 - x - y};
	}

	const vec3 bright(const vec3& white)
	{
		return {white.x/white.y, 1, white.z/white.y};
	}
}