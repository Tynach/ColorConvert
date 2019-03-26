#pragma once
#include <vecmath/vec3.h>
#include <vecmath/mat3.h>
using vecmath::vec3;
using vecmath::mat3;

namespace colormath {
	const mat3 BRADFORD = mat3(
		0.8951L, -0.7502L, 0.0389L,
		0.2664L, 1.7135L, -0.0685L,
		-0.1614L, 0.0367L, 1.0296L
	);

	const vec3 white(const floatp& x, const floatp& y)
	{
		return vec3(x, y, 1.0L - x - y);
	}

	const vec3 bright(const vec3& white)
	{
		return vec3(white.x/white.y, 1, white.z/white.y);
	}
}