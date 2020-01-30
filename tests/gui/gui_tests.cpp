#include <colormath/transfer.h>
#include <colormath/xyz_utils.h>
#include <colormath/color_space.h>
#include <colormath/convert.h>
#include <colorgui/rgb_gradient.h>
#include <QApplication>
#include <QFormLayout>

using colorvec::vec3;
using colorvec::mat3;
using colormath::gamma_trc;
using colormath::rgb_space;
using colormath::chromaticity;
using colormath::rgb_to_rgb;

int main(int argc, char *argv[])
{
	gamma_trc gam10(1.0, 0);
	gamma_trc gam22(2.2, 0, 1, 0, 0);
	gamma_trc gamSrgb(2.4, 0.055, 12.92, 0.04045, 0.0031308);
	gamma_trc gamLab(3.0, 0.16, 243.89/27.0, 0.08, 216.0/24389.0);

	mat3 primaries709 = {chromaticity(0.64, 0.33),
	                     chromaticity(0.3, 0.6),
	                     chromaticity(0.15, 0.06)};
	mat3 primariesNtsc = {chromaticity(0.67, 0.33),
	                      chromaticity(0.21, 0.71),
	                      chromaticity(0.14, 0.08)};

	vec3 whiteD65S = chromaticity(0.3127, 0.329);
	vec3 whiteC = chromaticity(0.31, 0.316);

	rgb_space sRGB(primaries709, whiteD65S, &gamSrgb);
	rgb_space Rec709_linear(primaries709, whiteD65S, &gam10);
	rgb_space sRGB_lab(primaries709, whiteD65S, &gamLab);
	rgb_space Ntsc(primariesNtsc, whiteC, &gam22);
	rgb_space Ntsc_linear(primariesNtsc, whiteC, &gam10);

	rgb_space *display = &sRGB;

	rgb_to_rgb from_Lin(Rec709_linear, *display);
	rgb_to_rgb from_sRGB(sRGB, *display);
	rgb_to_rgb from_sRGB_lab(sRGB_lab, *display);
	rgb_to_rgb from_Ntsc(Ntsc, *display);
	rgb_to_rgb from_NtscLin(Ntsc_linear, *display);

	rgb_to_rgb to_Lin(*display, Rec709_linear);
	rgb_to_rgb to_NtscLin(Ntsc, Ntsc_linear);

	vec3 left = {0.5, 0.8, 0.3};
	vec3 right = {0.3, 0.4, 0.8};

	QApplication app(argc, argv);
	QWidget window;
	QFormLayout lay(&window);

	rgbGradient gradLinear(from_Lin, to_Lin(left), to_Lin(right));
	rgbGradient gradSrgb(from_sRGB, left, right);
	rgbGradient gradLab(from_sRGB_lab, left, right);
	rgbGradient gradNtsc(from_Ntsc, left, right);
	rgbGradient gradNtscLin(from_NtscLin, to_NtscLin(left), to_NtscLin(right));

	lay.addRow("Linear", &gradLinear);
	lay.addRow("sRGB", &gradSrgb);
	lay.addRow("L*", &gradLab);
	lay.addRow("NTSC", &gradNtsc);
	lay.addRow("Linear NTSC", &gradNtscLin);

	window.show();
	return app.exec();
}