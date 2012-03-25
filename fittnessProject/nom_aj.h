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
		QString getTimeString() const;
		int getTimeInt() const;
		double getEnergy() const;
		double getEnergy(char *unit) const;
		void setEnergy(double newValue);
		void setEnergy(double newValue, char *unit);

	private:
		QString description;
		QTime time;
		energy_aj energy;
};

#endif // NOM_AJ_H
