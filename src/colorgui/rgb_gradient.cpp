#include <colormath/convert.h>
#include <colorgui/rgb_gradient.h>
#include <cmath>
#include <QImage>
#include <QEvent>
#include <QWidget>
#include <QPainter>

using colorvec::vec3;
using colormath::rgb_to_rgb;

rgbGradient::rgbGradient(QWidget *parent, rgb_to_rgb convert, vec3 left, vec3 right)
: QWidget(parent), convert(convert), left(left), right(right)
{
	img = QImage(8192, 1, QImage::Format_RGBA8888);
	img.setDevicePixelRatio(devicePixelRatioF());
	setMinimumSize(256/devicePixelRatioF(), fontMetrics().height());
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

rgbGradient::rgbGradient(rgb_to_rgb convert, vec3 left, vec3 right)
: rgbGradient(nullptr, convert, left, right)
{}

void rgbGradient::paintEvent(QPaintEvent *event)
{
	size_t width = lround(this->width()*devicePixelRatioF());
	uint32_t *data;
	QPainter paint(this);

	data = (uint32_t *)img.bits();

	for (int i = 0; i < width; ++i) {
		floatp pos = (floatp)i/(width - 1);
		vec3 color = convert(left*(1.0 - pos) + right*pos)*255.0;
		uint8_t result[3] = {
			(uint8_t)lround(fmin(fmax(0, color.r), 255)),
			(uint8_t)lround(fmin(fmax(0, color.g), 255)),
			(uint8_t)lround(fmin(fmax(0, color.b), 255))
		};

		data[i] = result[0]       // Red
		        | result[1] << 8  // Green
		        | result[2] << 16 // Blue
		        | 0xFF000000;     // Alpha
	}

	paint.drawTiledPixmap(rect(), QPixmap::fromImage(img));
}

void rgbGradient::changeEvent(QEvent *event)
{
	if (event->type() == QEvent::FontChange) {
		setMinimumSize(256.0/devicePixelRatioF(), fontMetrics().height());
		img.setDevicePixelRatio(devicePixelRatioF());
	}
}