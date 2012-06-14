#ifndef SETTINGHANDLER_AJ_H
#define SETTINGHANDLER_AJ_H

#include <QSettings>
#include <QDate>
#include <QCoreApplication>
#include "user_aj.h"

class settingHandler_aj
{
	public:
		settingHandler_aj();
        ~settingHandler_aj();
		char getDistu(void);
		char getEneru(void);
		char getMassu(void);
		void setDistu(char);
		void setEneru(char);
		void setMassu(char);
		QDate getDob(void);
		void setDob(QDate dob);
		char getGender(void);
		void setGender(char g);
		double getHeight(void);
		void setHeight(double h);
		unsigned int getNumdays(void);
		void setNumdays(unsigned int);

		void saveSettings(char distu, char eneru, char massu, QDate dob, char gender, double height);
		void saveSettings(user_aj* u);

		bool isFirstLaunch(void);

		void deleteSettings(void);

		user_aj* getUserpt(void); // get user object based on values in settings.

	private:
        QSettings* settings;
};

#endif // SETTINGHANDLER_AJ_H
