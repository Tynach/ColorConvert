#pragma once
#include <colorvec/vec3.h>
#include <colorvec/mat3.h>
using colorvec::vec3;
using colorvec::mat3;

namespace colormath {
	class colorspace {
		vec3 white_ref;
		vec3 white_out;
	};
}