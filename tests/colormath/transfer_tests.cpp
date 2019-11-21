#include <cstdio>
#include <colormath/transfer.h>
using colormath::gamma_trc;

int main()
{
	gamma_trc srgb = gamma_trc(2.4, 0.055, 12.92, 0.04045, 0.0031308);
	gamma_trc srgb_high = gamma_trc(2.4, 0.055);

	if (srgb.power != srgb_high.power) {
		return 1;
	}

	printf("sRGB 50%% luminosity: %ld\n", lround(srgb.from_linear(0.5)*255.0));
	printf("sRGB High 50%% luminosity: %ld\n", lround(srgb_high.from_linear(0.5)*255.0));

	printf("sRGB 1/255 linear: %ld\n", lround(srgb.from_linear(1.0/255.0)*255.0));
	printf("sRGB High 1/255 linear: %ld\n", lround(srgb_high.from_linear(1.0/255.0)*255.0));

	return 0;
}