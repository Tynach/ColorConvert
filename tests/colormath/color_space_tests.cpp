#include <colormath/transfer.h>
#include <colormath/color_space.h>
#include <colormath/convert.h>
#include <colormath/xyz_utils.h>
#include <cstdio>

using colorvec::vec3;
using colorvec::mat3;
using colormath::gamma_trc;
using colormath::rgb_space;
using colormath::convert;
using colormath::chromaticity;
using colormath::rgb_to_rgb;

int main(int argc, char *argv[])
{
	gamma_trc gamSrgb(2.4, 0.055, 12.92, 0.04045, 0.0031308);
	gamma_trc gam22(2.2, 0, 1, 0, 0);

	mat3 primaries709 = {chromaticity(0.64, 0.33),
	                     chromaticity(0.3, 0.6),
	                     chromaticity(0.15, 0.06)};
	mat3 primariesAdobe = {chromaticity(0.64, 0.33),
	                       chromaticity(0.21, 0.71),
	                       chromaticity(0.15, 0.06)};

	vec3 whiteD65S = chromaticity(0.3127, 0.329);

	rgb_space sRGB(primaries709, whiteD65S, &gamSrgb);
	rgb_space AdobeRGB(primariesAdobe, whiteD65S, &gam22);

	rgb_to_rgb sRGB_to_AdobeRGB(sRGB, AdobeRGB);

	vec3 color = sRGB_to_AdobeRGB((vec3){0, 127.5, 255}/255.0)*255.0;
	printf("%f, %f, %f\n", color.r, color.g, color.b);

	return 0;
}