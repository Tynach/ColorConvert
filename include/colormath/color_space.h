#pragma once

#include <colorvec/vec3.h>
#include <colorvec/mat3.h>
#include <colormath/transfer.h>
#include <colormath/xyz_utils.h>

namespace colormath {
	/**
	 * Abstract color space class; subclass to create different types of
	 * color spaces
	 */
	struct color_space {
		color_space() {}
		virtual ~color_space() {}
	};

	struct xyz_space: color_space {
		colorvec::mat3 to_lms;
		colorvec::vec3 white;

		xyz_space(const colorvec::mat3 &l, const colorvec::vec3 &w)
		: to_lms(l), white(w)
		{}
	};

	struct rgb_space: color_space {
		colorvec::mat3 primaries;
		colorvec::vec3 white;
		transfer *trc;

		rgb_space(colorvec::mat3 const &p, colorvec::vec3 const &w, transfer *const t)
		: primaries(p), white(bright(w)), trc(t)
		{}
	};
}