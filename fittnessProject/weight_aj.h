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
		double getMass(char *unit) const;
		QString getTimeString() const;
		int getTimeInt() const;

	private:
		mass_aj mass;
		QTime time;
};

#endif // WEIGHT_AJ_H
