#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QStatusBar>
//#include <QTranslator>
#include <QDebug>
//#include <QSplashScreen>
#include "distance_aj.h"
#include "energy_aj.h"
#include "mass_aj.h"
#include "filereader.h"
#include "filewriter.h"
#include "weight_aj.h"

#include "settinghandler_aj.h"
#include "firstuseform.h"
#include "user_aj.h"

/*
using namespace std;

int energyTest()
{
	energy_aj en1(15.0f), en2(20.0f);

	qDebug() << "en1:" << en1.getEnergy();
	qDebug() << "en2:" << en2.getEnergy();

	energy_aj en3 = en1 + en2;
	qDebug() << "en3:" << en3.getEnergy();

	if (en1 == en2)	qDebug() << "en1 == en2  true";	else qDebug() << "en1 == en2  false";
	if (en1 != en2)	qDebug() << "en1 != en2  true";	else qDebug() << "en1 != en2  false";

	char testUnit = 'c';

	en1.setEnergy(10.0f, &testUnit);
	en2.setEnergy(35.0f, &testUnit);
	qDebug() << "en1:" << en1.getEnergy(&testUnit) << "cal";
	qDebug() << "en2:" << en2.getEnergy(&testUnit) << "cal";
	qDebug() << "en1:" << en1.getEnergy();
	qDebug() << "en2:" << en2.getEnergy();

	return 0;
}

int massTest()
{
	mass_aj en1(15.0f), en2(20.0f);

	qDebug() << "en1:" << en1.getMass();
	qDebug() << "en2:" << en2.getMass();

	mass_aj en3 = en1 + en2;
	qDebug() << "en3:" << en3.getMass();

	if (en1 == en2)	qDebug() << "en1 == en2  true";	else qDebug() << "en1 == en2  false";
	if (en1 != en2)	qDebug() << "en1 != en2  true";	else qDebug() << "en1 != en2  false";

	char testUnit = 'b';

	en1.setMass(10.0f, &testUnit);
	en2.setMass(35.0f, &testUnit);
	qDebug() << "en1:" << en1.getMass(&testUnit) << "lb";
	qDebug() << "en2:" << en2.getMass(&testUnit) << "lb";
	qDebug() << "en1:" << en1.getMass();
	qDebug() << "en2:" << en2.getMass();

	return 0;
}

int distanceTest()
{
	distance_aj dist1(100.0f), dist2(20.0f);
	distance_aj dist3 = dist1 / dist2;
	char unit = METERS;
	qDebug() << dist1.getDistance(&unit);
	qDebug() << dist3.getDistance();
	dist1 -= dist2;
	qDebug() << dist1.getDistance();
	return 0;
}

int weightTest()
{
	weight_aj w1;

	weight_aj w2(12.0f, (QString)"153011000");

	char testUnit = 'b';

	qDebug() << "w1: mass:" << w1.getMass();
	qDebug() << "w2: mass:" << w2.getMass(&testUnit);
	qDebug() << "w1: time:" << w1.getTimeString();
	qDebug() << "w2: time:" << w2.getTimeString();
	qDebug() << "w2: time: int:" << w2.getTimeInt();
	return 0;
}

int fileReaderTest(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPixmap pixmap("logo.png");
	QSplashScreen splash(pixmap);
	splash.show();
	app.processEvents();

	 //splash.showMessage("Established connections");
	//fileReader testfile;
	QList<day_aj *> dayList;
	fileReader testfile(&dayList);

	if(testfile.openFile())
		testfile.parseFile();

	qDebug() << dayList.size();
	qDebug() << dayList.value(0)->getExerListPtr()->size();
	qDebug() << dayList.value(0)->getNomListPtr()->size();
	qDebug() << dayList.value(0)->getWeightListPtr()->size();

	for(int i = 0; i < dayList.size(); i++)
	{
		qDebug() << "day" << i;
		for(int j = 0; j < dayList.value(i)->getExerListPtr()->size(); j++)
		{
			qDebug() << "exer " << j;
			qDebug() << "completion: " << dayList.value(i)->getExerListPtr()->value(j)->getCompletion();
			qDebug() << "type: " << dayList.value(i)->getExerListPtr()->value(j)->getType();
			qDebug() << "dist : " << dayList.value(i)->getExerListPtr()->value(j)->getDistance();
			qDebug() << "energy: " << dayList.value(i)->getExerListPtr()->value(j)->getEnergy();
			qDebug() << "note: " << dayList.value(i)->getExerListPtr()->value(j)->getNote();
		}
		for(int j = 0; j < dayList.value(i)->getNomListPtr()->size(); j++)
		{
			qDebug() << "nom " << j;
			qDebug() << "desc: " << dayList.value(i)->getNomListPtr()->value(j)->getDescription();
			qDebug() << "ener: " << dayList.value(i)->getNomListPtr()->value(j)->getEnergy();
			qDebug() << "ener: " << dayList.value(i)->getNomListPtr()->value(j)->getTimeString();
		}
		for(int j = 0; j < dayList.value(i)->getWeightListPtr()->size(); j++)
		{
			qDebug() << "weight " << j;
			qDebug() << "time: " << dayList.value(i)->getWeightListPtr()->value(j)->getTimeString();
			qDebug() << "mass: " << dayList.value(i)->getWeightListPtr()->value(j)->getMass();
		}
	}

	QMainWindow window;
	 window.show();
	 splash.finish(&window);
	 return app.exec();
	return 0;
}

int settingTest()
{
	settingHandler_aj settings;

	settings.deleteSettings();

	//if(settings.isFirstLaunch())
		//qDebug() << "no settings found";
	//else
	//	qDebug() << "settings found!";
	//settings.saveSettings(METERS, 'c', 'k', QDate(), METERS, 1.56f);

	//settings.setNumdays(0);

	//qDebug() << settings.getDistu();

	return 0;
}
*/
void readFile(QString filename, QList<day_aj *>* dayList, unsigned int numdays)
{
	fileReader file(filename, dayList, numdays);
	if(file.openFile())
	{	file.parseFile();	}
}

int main(int argc, char *argv[])
{
	/*QApplication a(argc, argv);
	MainWindow w;
	QStatusBar * statusbar;
	w.setStatusBar(statusbar);
	//w.statusBar()->showMessage(QObject::tr("Ready"), 2000);
	w.show();

	return a.exec();

	//return distanceTest();
	//return energyTest();
	//return massTest();
	//return weightTest();
	//return fileReaderTest(argc, argv); // include splash screen code
	//return settingTest();

*/
	//-------------------------
	QApplication a(argc, argv);

	settingHandler_aj settings;
	user_aj* user;
    QList<day_aj *> dayList; // holds the days //TODO: WRAP IN CLASS
	if(settings.isFirstLaunch())
	{
		//launch setup form
		firstUseForm setupForm;
		setupForm.exec();

		if(setupForm.result())
		{
			user = new user_aj(setupForm.getMassu(), setupForm.getEneru(), setupForm.getDistu(), setupForm.getHeight(), setupForm.getGender(), setupForm.getDob());
			settings.saveSettings(user);
		}
		else
		{	return 0;	} // close clicked at setup form
	}
	else // not first launch
	{
		user = settings.getUserpt();
		readFile(user->getFileName(), &dayList, user->getNumDays()); //read in data and add to dayList
	}

	//test---
	//readFile("testFile.xml", &dayList, 2); //read in data
	//filewriter wfile(&dayList);
	//wfile.saveFile();
	//test^^^


	MainWindow w;
	w.setDaylistPtr(&dayList);
	w.setUserPtr(user);
	w.setSettingPtr(&settings);
	//w.drawDays();
	w.initialise();
	w.show();

	return a.exec();
}

