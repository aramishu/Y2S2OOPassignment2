#include "firstuseform.h"
#include "ui_firstuseform.h"

firstUseForm::firstUseForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::firstUseForm)
{
	ui->setupUi(this);
}

firstUseForm::~firstUseForm()
{
	delete ui;
}

double firstUseForm::getHeight()
{
	return ui->doubleSpinBox->value();
}

QDate firstUseForm::getDob()
{
	return ui->dateEdit->date();
}

char firstUseForm::getDistu()
{

	if("km" == this->ui->comboBox_3->currentText())
	{	return KILOMETERS;	}
	else if("miles" == this->ui->comboBox_3->currentText())
	{	return MILES;	}
	else // if("m" == this->ui->comboBox_3->currentText())
	{	return METERS;	}
}

char firstUseForm::getEneru()
{
	if("j" == this->ui->comboBox_2->currentText())
	{	return JOULE;	}
	else if("kj" == this->ui->comboBox_2->currentText())
	{	return KILOJOULE;	}
	//else if("kCal" == this->ui->comboBox_2->currentText())
	return CALORIE;
}

char firstUseForm::getMassu()
{
	if("lb" == this->ui->comboBox_2->currentText())
	{	return POUND;	}
	else if("stone" == this->ui->comboBox_2->currentText())
	{	return STONE;	}
	else //if("kg" == this->ui->comboBox_2->currentText())
	{	return KILO;	}
}

char firstUseForm::getGender()
{
	if("m" == this->ui->comboBox->currentText())
	{	return 'm';	}
	else
	{	return 'f';	}
}
