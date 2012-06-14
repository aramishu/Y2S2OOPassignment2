#ifndef NOM_AJ_H
#define NOM_AJ_H

#include <QString>
#include <QTime>
#include "energy_aj.h"

class nom_aj
{
	public:
		nom_aj();
		nom_aj(QString description, QString strTime, double dwEnergy);
		nom_aj(QString description, QString strTime, QString strEnergy);
		QString getDescription() const;
		void setDecription(QString newString);
		QTime getTime() const;
		QString getTimeString() const;
		QString getTimeStr() const;
		int getTimeInt() const;
		double getEnergy() const;
		double getEnergy(char unit) const;
		QString getEnergyStr() const;
		void setEnergy(double newValue);
		void setEnergy(double newValue, char unit);
		void setTime(QTime t);

	private:
		QString description;
		QTime time;
		energy_aj energy;
};

#endif // NOM_AJ_H
