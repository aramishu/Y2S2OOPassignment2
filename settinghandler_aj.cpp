#include "settinghandler_aj.h"

settingHandler_aj::settingHandler_aj()
{
    //QCoreApplication::setOrganizationName("aramishu");
    //QCoreApplication::setOrganizationDomain("aramishu.com");
    //QCoreApplication::setApplicationName("Fitness Project");

    this->settings = new QSettings("aramishu", "FitnessProject");
}

settingHandler_aj::~settingHandler_aj()
{
    delete this->settings;
}

bool settingHandler_aj::isFirstLaunch()
{
    return !(this->settings->contains("dob"));
}

void settingHandler_aj::setNumdays(unsigned int n)
{
    this->settings->setValue("numDays", n);
}

unsigned int settingHandler_aj::getNumdays()
{
    return this->settings->value("numDays").toUInt();
}

void settingHandler_aj::setDistu(char u)
{
    this->settings->setValue("distu", u);
}

char settingHandler_aj::getDistu()
{
    return this->settings->value("distu").value<char>();
}

void settingHandler_aj::setEneru(char u)
{
    this->settings->setValue("eneru", u);
}


char settingHandler_aj::getEneru()
{
    return this->settings->value("eneru").value<char>();
}

void settingHandler_aj::setMassu(char u)
{
    this->settings->setValue("massu", u);
}

char settingHandler_aj::getMassu()
{
    return this->settings->value("massu").value<char>();
}

void settingHandler_aj::setGender(char g)
{
    this->settings->setValue("gender", g);
}

char settingHandler_aj::getGender()
{
    return this->settings->value("gender").value<char>();
}

void settingHandler_aj::setDob(QDate dob)
{
    this->settings->setValue("dob", dob);
}

QDate settingHandler_aj::getDob()
{
    return this->settings->value("dob").toDate();
}

void settingHandler_aj::setHeight(double h)
{
    this->settings->setValue("height", h);
}

double settingHandler_aj::getHeight()
{
    return this->settings->value("height").toDouble();
}

void settingHandler_aj::saveSettings(char distu, char eneru, char massu, QDate dob, char gender, double height)
{
	this->setDistu(distu);
	this->setEneru(eneru);
	this->setMassu(massu);
	this->setDob(dob);
	this->setGender(gender);
	this->setHeight(height);

	//perminant storage of settings happens upon object destruction and at regular interval in the event loop.
	//alternatively sync() could be called but not nessecary.
}

void settingHandler_aj::saveSettings(user_aj* u)
{
	this->setDistu(u->getDistu());
	this->setEneru(u->getEneru());
	this->setMassu(u->getMassu());
	this->setDob(u->getDob());
	this->setGender(u->getGender());
	this->setHeight(u->getHeight());

    this->settings->sync();
}

void settingHandler_aj::deleteSettings()
{
    this->settings->clear();
}

user_aj* settingHandler_aj::getUserpt(void)
{
	return new user_aj(this->getMassu(), this->getEneru(), this->getDistu(), this->getHeight(), this->getGender(), this->getDob());
}
