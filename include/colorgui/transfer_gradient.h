#pragma once

#include <colormath/transfer.h>
#include <QWidget>
#include <QImage>
#include <QEvent>
using colormath::transfer;

class transferGradient: public QWidget {
	QImage img;
	transfer *from;
	transfer *to;

public:
	transferGradient(QWidget *parent, transfer *from, transfer *to);
	transferGradient(transfer *from, transfer *to);

protected:
	void paintEvent(QPaintEvent *event);
	void changeEvent(QEvent *event);
};