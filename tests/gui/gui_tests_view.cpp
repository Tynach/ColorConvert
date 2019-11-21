#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImage>

class LinearGradient: public QGraphicsView {
	QImage img;
	QPixmap back;
	QGraphicsScene scene;
	QGraphicsPixmapItem *backItem;

public:
	LinearGradient(): QGraphicsView(), scene()
	{
		setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		setFrameStyle(QFrame::NoFrame | QFrame::Plain);
		setMinimumSize(256, 0);

		setScene(&scene);
		backItem = scene.addPixmap(back);

		show();
	}

	void resizeEvent(QResizeEvent *event)
	{
		size_t totalPixels = width()*height();
		int gap = 0xFFFFFF/(totalPixels - 1);
		uint32_t *data;

		img = QImage(size(), QImage::Format_RGBA8888);
		data = (uint32_t *)img.bits();

		for (int i = 0; i < totalPixels; ++i) {
			data[i] = i*gap | 0xFF000000;
		}

		back = QPixmap::fromImage(img);
		backItem->setPixmap(back);
	}
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	LinearGradient grad;

	return app.exec();
}