#pragma once
#include <colorvec/vec3.h>
#include <colorvec/mat3.h>
#include <colormath/transfer.h>
using colorvec::vec3;
using colorvec::mat3;
using colormath::transfer;

namespace colormath {
	/**
	 * Abstract color space class; subclass to create different types of
	 * color spaces
	 */
	class color_space {
	public:
		color_space() {}
		virtual ~color_space() {}
	};

	class xyz_space: color_space {
		mat3 *to_lms;
		vec3 *white;

	public:
	};

	class rgb_space: color_space {
		mat3 *primaries;
		vec3 *white;
		transfer *trc;

	public:
		rgb_space(mat3 *p, vec3 *w, transfer *t)
		: primaries(p), white(w), trc(t)
		{}
	};
}