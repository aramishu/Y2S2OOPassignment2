#include "loadinxmlporgress.h"
#include "ui_loadinxmlporgress.h"
#include <QDebug>

loadinxmlPorgress::loadinxmlPorgress(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::loadinxmlPorgress)
{
	ui->setupUi(this);
}

loadinxmlPorgress::~loadinxmlPorgress()
{
	delete ui;
}

void loadinxmlPorgress::setMessage(QString m)
{
	this->ui->message->setText(m);
}

void loadinxmlPorgress::setMax(int m)
{
	this->ui->progress->setRange(0, m);//setMaximum(m);
}

void loadinxmlPorgress::setValue(int v)
{
	this->ui->progress->setValue(v);
}
