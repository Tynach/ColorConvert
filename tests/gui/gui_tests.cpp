#include <colorgui/transfer_gradient.h>
#include <colormath/transfer.h>
#include <QApplication>
#include <QVBoxLayout>
using colormath::gamma_trc;

int main(int argc, char *argv[])
{
	gamma_trc gamLinear(1.0, 0);
	gamma_trc gamSrgb(2.4, 0.055, 12.92, 0.04045, 0.0031308);
	gamma_trc gamLab(3.0, 0.16, 243.89/27.0, 0.08, 216.0/24389.0);

	QApplication app(argc, argv);
	QWidget window;
	QVBoxLayout lay(&window);

	transferGradient gradLinear(&gamLinear, &gamSrgb);
	transferGradient gradSrgb(&gamSrgb, &gamSrgb);
	transferGradient gradLab(&gamLab, &gamSrgb);

	lay.addWidget(&gradLinear);
	lay.addWidget(&gradSrgb);
	lay.addWidget(&gradLab);

	window.show();
	return app.exec();
}