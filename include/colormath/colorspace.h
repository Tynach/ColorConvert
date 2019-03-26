#pragma once
#include <vecmath/vec3.h>
#include <vecmath/mat3.h>
using vecmath::vec3;
using vecmath::mat3;

namespace colormath {
	class colorspace {
		vec3 white_ref;
		vec3 white_out;
	};
}