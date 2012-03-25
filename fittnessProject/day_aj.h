#ifndef DAY_AJ_H
#define DAY_AJ_H

#include <QDate>
#include <QList>
#include "nom_aj.h"
#include "weight_aj.h"
#include "exercise_aj.h"

class day_aj
{
	public:
		day_aj();
		day_aj(QString strDate);

		void setDate(QString strDate);

		void addNom(nom_aj* newNom);
		void addWeight(weight_aj* newWeight);
		void addExercise(exercise_aj* newExer);

		QList<nom_aj *>* getNomListPtr(); // const; ?
		QList<weight_aj *>* getWeightListPtr(); //const;
		QList<exercise_aj *>* getExerListPtr(); //const;

		void printDetails();

	private:
		QDate date;
		QList<nom_aj*> noms;
		QList<weight_aj*> weights;
		QList<exercise_aj*> workouts;
};

#endif // DAY_AJ_H
