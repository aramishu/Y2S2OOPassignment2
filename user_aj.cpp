#include "user_aj.h"

user_aj::user_aj()
{
	this->massu = 'k';
	this->eneru = 'j';
	this->distu = 'k';
	this->height = 1.6f;
}

user_aj::user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob)
{
	this->massu = massu;
	this->eneru = eneru;
	this->distu = distu;
	this->height = height;
	this->gender = gender;
	this->dob = dob;
	this->numDays = 0;
	this->filename = "datafile.xml";
}

user_aj::user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob, unsigned int numDays)
{
	this->massu = massu;
	this->eneru = eneru;
	this->distu = distu;
	this->height = height;
	this->gender = gender;
	this->dob = dob;
	this->numDays = numDays;
	this->filename = "datafile.xml";
}

user_aj::user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob, unsigned int numDays, QString filename)
{
	this->massu = massu;
	this->eneru = eneru;
	this->distu = distu;
	this->height = height;
	this->gender = gender;
	this->dob = dob;
	this->numDays = numDays;
	this->filename = filename;
}

void user_aj::setMassu(char u)
{
	this->massu = u;
}

void user_aj::setEneru(char u)
{
	this->eneru = u;
}

void user_aj::setDistu(char u)
{
	this->distu = u;
}

void user_aj::setHeight(double h)
{
	this->height = h;
}

void user_aj::setGender(char g)
{
	this->gender = g;
}

void user_aj::setDob(QDate dob)
{
	this->dob = dob;
}

void user_aj::setNumDays(unsigned int n)
{
	this->numDays = n;
}

char user_aj::getMassu() const
{
	return this->massu;
}

char user_aj::getEneru() const
{
	return this->eneru;
}

char user_aj::getDistu() const
{
	return this->distu;
}

QString user_aj::getMassuStr() const
{
	if(this->massu == STONE)
	{	return "st";	}
	else if(this->massu == POUND)
	{	return "lbs";	}
	return "kg";
}

QString user_aj::getEneruStr() const
{
	if(this->eneru == KILOJOULE)
	{	return "kj";	}
	else if(this->eneru == CALORIE)
	{	return "kCal";	}
	return "j";
}

QString user_aj::getDistuStr() const
{
	if(this->distu == KILOMETERS)
	{	return "km";	}
	else if(this->distu == MILES)
	{	return "Miles";	}
	return "m";
}

double user_aj::getHeight() const
{
	return this->height;
}

char user_aj::getGender() const
{
	return this->gender;
}

QDate user_aj::getDob() const
{
	return this->dob;
}

unsigned int user_aj::getNumDays() const
{
	return this->numDays;
}

QString user_aj::getFileName() const
{
	return this->filename;
}

int user_aj::getAge() const
{
	QDate now = QDate::currentDate();
	int age = now.year() - this->dob.year() - 1;

	if(now.month() >= this->dob.month() && now.day() >= this->dob.day())
	{	age++;	}
	return age;
}
