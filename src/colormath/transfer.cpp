#include <colormath/transfer.h>
#include <colorvec/conf.h>
#include <cmath>

namespace colormath {
	floatp gamma_trc::to_linear(floatp value)
	{
		if (value < -linear_cutoff) {
			return -pow((value - offset)/(-1.0 - offset), power);
		} else if (value < linear_cutoff) {
			return value/slope;
		} else {
			return pow((value + offset)/(1.0 + offset), power);
		}
	}

	floatp gamma_trc::from_linear(floatp value)
	{
		if (value < -gamma_cutoff) {
			return (-1.0 - offset)*pow(-value, 1.0/power) + offset;
		} else if (value < gamma_cutoff) {
			return value*slope;
		} else {
			return (1.0 + offset)*pow(value, 1.0/power) - offset;
		}
	}
}