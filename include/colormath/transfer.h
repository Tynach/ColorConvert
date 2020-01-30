#pragma once

#include <cmath>
#include <colorvec/conf.h>

namespace colormath {
	struct transfer {
		transfer() {}
		virtual ~transfer() {};

		/// Convert a value from being non-linear, to being linear.
		virtual floatp to_linear(floatp value) = 0;

		/// Convert a value from being linear, to being non-linear.
		virtual floatp from_linear(floatp value) = 0;
	};

	struct gamma_trc: transfer {
		floatp power;
		floatp offset;
		floatp slope;
		floatp linear_cutoff;
		floatp gamma_cutoff;

		gamma_trc():
			power(1.0),
			offset(0.0),
			slope(1.0),
			linear_cutoff(0.0),
			gamma_cutoff(0.0)
		{}

		gamma_trc(floatp p, floatp o, floatp s, floatp l, floatp g):
			power(p),
			offset(o),
			slope(s),
			linear_cutoff(l),
			gamma_cutoff(g)
		{}

		gamma_trc(floatp p, floatp o): gamma_trc(
			p,
			o,
			pow(p*o/(p - 1.0), 1.0 - p)*pow(1.0 + o, p)/p,
			o/(p - 1.0),
			o/(p - 1.0)*p/(pow(p*o/(p - 1.0), 1.0 - p)*pow(1.0 + o, p))
		) {}

		~gamma_trc() {}

		floatp to_linear(floatp value);
		floatp from_linear(floatp value);
	};
}