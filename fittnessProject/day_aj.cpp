#include "day_aj.h"
#include <QDebug>
day_aj::day_aj()
{
	this->date = QDate(); // null date object

	//this->noms.QList(); //= QList();
	//this->weights = QList();
	this->workouts = QList<exercise_aj*>();
}

day_aj::day_aj(QString strDate)
{
	this->date = QDate::fromString(strDate, "yyyyMMdd");

	//this->noms = QList();
	//this->weights = QList();
	//this->workouts = QList();
}

void day_aj::setDate(QString strDate)
{
	this->date = QDate::fromString(strDate, "yyyyMMdd");
}

void day_aj::addNom(nom_aj* newNom)
{
	this->noms << newNom;
}

void day_aj::addWeight(weight_aj* newWeight)
{
	this->weights << newWeight;
}

void day_aj::addExercise(exercise_aj* newExer)
{
	this->workouts.append(newExer);
}

QList<nom_aj*>* day_aj::getNomListPtr()
{
	return &this->noms;
}

QList<weight_aj*>* day_aj::getWeightListPtr()
{
	return &this->weights;
}

QList<exercise_aj*>* day_aj::getExerListPtr()
{
	return &this->workouts;
}

void day_aj::printDetails()
{
	qDebug() << this->date.toString("yyyyMMdd");
	qDebug() << "nom size" << this->noms.size();
	qDebug() << "weight size" << this->weights.size();
	qDebug() << "exer size" << this->workouts.size();
}
