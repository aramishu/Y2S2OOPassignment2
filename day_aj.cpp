#include "day_aj.h"
#include <QDebug>

day_aj::day_aj()
{
	this->date = QDate(); // null date object

	//this->noms.QList(); //= QList();
	//this->weights = QList();
	//this->workouts = QList<exercise_aj*>();
}

day_aj::day_aj(QDate date)
{
	this->date = date;
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

void day_aj::removeExer(int i)
{
	delete this->workouts.value(i);
	this->workouts.removeAt(i);
}

void day_aj::removeNom(int i)
{
	delete this->noms.value(i);
	this->noms.removeAt(i);
}

void day_aj::removeWeight(int i)
{
	delete this->weights.value(i);
	this->weights.removeAt(i);
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

QDate day_aj::getDate()
{
	return this->date;
}

QString day_aj::getDateStr()
{
	return this->date.toString("yyyyMMdd");
}

QString day_aj::getDateString()
{
	return this->date.toString("ddd dd MM yy");
}

void day_aj::printDetails()
{
	qDebug() << this->date.toString("yyyyMMdd");
	qDebug() << "nom size" << this->noms.size();
	qDebug() << "weight size" << this->weights.size();
	qDebug() << "exer size" << this->workouts.size();
}
