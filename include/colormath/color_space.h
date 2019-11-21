#pragma once
#include <colorvec/vec3.h>
#include <colorvec/mat3.h>
using colorvec::vec3;
using colorvec::mat3;

namespace colormath {
	class color_space {
	public:
		color_space() {}
		virtual ~color_space() {}

		virtual vec3 from_connection_space(vec3 c);
		virtual vec3 to_connection_space(vec3 c);
	};

	class rgb_space {
		mat3 primaries;
		vec3 white_point;
	};
}