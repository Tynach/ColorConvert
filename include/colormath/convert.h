#pragma once

#include <colormath/color_space.h>
#include <colorvec/mat3.h>

namespace colormath {
	/**
	 * Abstract color space conversion class; subclass to create ways to
	 * convert between two specific types of color spaces
	 */
	struct convert {
		convert() {}
		virtual colorvec::vec3 operator()(colorvec::vec3 color) = 0;
		virtual ~convert() {}
	};

	struct rgb_to_rgb: convert {
		rgb_space a;
		rgb_space b;
		colorvec::mat3 conv_mat;

		rgb_to_rgb(rgb_space a, rgb_space b)
		: a(a), b(b)
		{
			colorvec::vec3 fr_scale = a.primaries.inverse()*a.white;
			colorvec::mat3 from = a.primaries*(colorvec::mat3){fr_scale.x, 0, 0,
			                                                   0, fr_scale.y, 0,
			                                                   0, 0, fr_scale.z};
			colorvec::vec3 to_scale = b.primaries.inverse()*b.white;
			colorvec::mat3 to = b.primaries*(colorvec::mat3){to_scale.x, 0, 0,
			                                                 0, to_scale.y, 0,
			                                                 0, 0, to_scale.z};

			conv_mat = to.inverse()*from;
		}

		colorvec::vec3 operator()(colorvec::vec3 color)
		{
			color.r = a.trc->to_linear(color.r);
			color.g = a.trc->to_linear(color.g);
			color.b = a.trc->to_linear(color.b);

			color = conv_mat*color;

			color.r = b.trc->from_linear(color.r);
			color.g = b.trc->from_linear(color.g);
			color.b = b.trc->from_linear(color.b);

			return color;
		}
	};
}