#include <colorgui/transfer_gradient.h>

transferGradient::transferGradient(QWidget *parent, transfer *from, transfer *to)
: QWidget(parent), from(from), to(to)
{
	img = QImage(8192, 1, QImage::Format_RGBA8888);
	img.setDevicePixelRatio(devicePixelRatioF());
	setMinimumSize(256/devicePixelRatioF(), fontMetrics().height());
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

transferGradient::transferGradient(transfer *from, transfer *to)
: transferGradient(nullptr, from, to)
{}

void transferGradient::paintEvent(QPaintEvent *event)
{
	size_t width = lround(this->width()*devicePixelRatioF());
	uint32_t *data;
	QPainter paint(this);

	data = (uint32_t *)img.bits();

	for (int i = 0; i < width; ++i) {
		floatp value = from->to_linear((floatp)i/(width - 1));
		value = to->from_linear(value);
		uint8_t result = lround(value*255.0);
		data[i] = result << 16
		        | result << 8
		        | result
		        | 0xFF000000; // Alpha channel
	}

	paint.drawTiledPixmap(rect(), QPixmap::fromImage(img));
}

void transferGradient::changeEvent(QEvent *event)
{
	if (event->type() == QEvent::FontChange) {
		setMinimumSize(256.0/devicePixelRatioF(), fontMetrics().height());
		img.setDevicePixelRatio(devicePixelRatioF());
	}
}