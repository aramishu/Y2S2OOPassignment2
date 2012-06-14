#ifndef USER_AJ_H
#define USER_AJ_H

#include <QDate>
#include <QString>
#include "header_aj.h"

class user_aj
{
	public:
		user_aj();
		user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob);
		user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob, unsigned int numDays);
		user_aj(char massu, char eneru, char distu, double height, char gender, QDate dob, unsigned int numDays, QString filename);
		void setMassu(char u);
		void setEneru(char u);
		void setDistu(char u);
		void setHeight(double h);
		void setGender(char g);
		void setDob(QDate dob);
		void setNumDays(unsigned int n);
		void setFileName(QString f);
		char getMassu() const;
		char getEneru() const;
		char getDistu() const;
		QString getMassuStr() const;
		QString getEneruStr() const;
		QString getDistuStr() const;
		double getHeight() const;
		char getGender() const;
		QDate getDob() const;
		unsigned int getNumDays() const;
		QString getFileName() const;
		int getAge() const;

	private:
		char massu;
		char eneru;
		char distu;

		double height;
		char gender;
		QDate dob;

		unsigned int numDays;
		QString filename; // file storing data as xml
};

#endif // USER_AJ_H
