#ifndef EXERCISE_AJ_H
#define EXERCISE_AJ_H

#include <QString>
#include "distance_aj.h"
#include "energy_aj.h"

class exercise_aj
{
	public:
		exercise_aj();
		exercise_aj(bool completed, QString type, double dwDistance, double dwEnergy, QString note);
		exercise_aj(bool completed, QString type, QString strDistance, QString strEnergy, QString note);
		exercise_aj(QString completed, QString type, QString strDistance, QString strEnergy, QString note);

		bool getCompletion() const;
		void setCompletion(bool completion);
		QString getType() const;
		void setType(QString newValue);
		double getDistance() const;
		double getDistance(char *unit) const;
		void setDistance(double newValue);
		void setDistance(double newValue, char *unit);
		double getEnergy() const;
		double getEnergy(char *unit) const;
		void setEnergy(double newValue);
		void setEnergy(double newValue, char *unit);
		QString getNote() const;
		void setNote(QString newValue);

	private:
		bool completed;
		QString type;
		distance_aj distance;
		energy_aj energy;
		QString note;
};

#endif // EXERCISE_AJ_H
