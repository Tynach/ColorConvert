#pragma once

#include <colormath/convert.h>
#include <QPaintEvent>
#include <QWidget>
#include <QImage>
#include <QEvent>

class rgbGradient: public QWidget {
	QImage img;
	colormath::rgb_to_rgb convert;

	colorvec::vec3 left;
	colorvec::vec3 right;

public:
	rgbGradient(QWidget *parent, colormath::rgb_to_rgb convert, colorvec::vec3 left, colorvec::vec3 right);
	rgbGradient(colormath::rgb_to_rgb convert, colorvec::vec3 left, colorvec::vec3 right);

protected:
	void paintEvent(QPaintEvent *event);
	void changeEvent(QEvent *event);
};