#ifndef WEIGHT_AJ_H
#define WEIGHT_AJ_H

#include "mass_aj.h"
#include <QTime>
#include <QString>

class weight_aj
{
	public:
		weight_aj();
		~weight_aj();
		weight_aj(double massValue, QString strTime);
		weight_aj(QString massValue, QString strTime);
		double getMass() const;
		double getMass(char unit) const;
		QString getMassStr() const;
		QTime getTime() const;
		QString getTimeString() const;
		int getTimeInt() const;
		void setTime(QTime t);
		void setMass(double m, char u);
		QString getTimeStr() const; //  used for saving, servertime style

	private:
		mass_aj mass;
		QTime time;
};

#endif // WEIGHT_AJ_H
