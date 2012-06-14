#include "filewriter.h"

filewriter::filewriter()
{
	this->file = new QFile("writeTestFile.xml");
	this->stream = new QXmlStreamWriter(this->file);
	this->ptrDays = new QList<day_aj*>();
}

filewriter::filewriter(QList<day_aj*>* ptrDays)
{
	this->file = new QFile("writeTestFile.xml");
	this->stream = new QXmlStreamWriter(this->file);
	this->ptrDays = ptrDays;
}

filewriter::filewriter(QString fileName, QList<day_aj*>* ptrDays)
{
	this->file = new QFile(fileName);
	this->stream = new QXmlStreamWriter(this->file);
	this->ptrDays = ptrDays;
}

filewriter::~filewriter()
{
	delete this->stream;
}

bool filewriter::openFile()
{
	if (!file->open(QIODevice::WriteOnly))
	{
		qDebug() << "failed to open file";
		return false;
	}
	else
	{
		qDebug() << "file open";
		return true;
	}
}

void filewriter::saveFile()
{
	if (this->openFile())
	{
		this->stream->setAutoFormatting(true);
		this->stream->writeStartDocument();
		this->stream->writeStartElement("data");
		this->stream->writeStartElement("days");

		for(int i = 0; i < this->ptrDays->size(); i++)
		{
			this->saveDay(i);
		}

		stream->writeEndElement(); // /days
		stream->writeEndElement(); // /data
		stream->writeEndDocument();
		this->file->flush();
		this->file->close();
	}
}

void filewriter::saveDay(int dayIndex)
{
	this->stream->writeStartElement("day");
	this->stream->writeTextElement("date", this->ptrDays->value(dayIndex)->getDateStr());

	for(int i = 0; i < this->ptrDays->value(dayIndex)->getWeightListPtr()->size(); i++)
	{
		this->saveWeight(dayIndex, i);
	}

	for(int i = 0; i < this->ptrDays->value(dayIndex)->getNomListPtr()->size(); i++)
	{
		this->saveNom(dayIndex, i);
	}

	for(int i = 0; i < this->ptrDays->value(dayIndex)->getExerListPtr()->size(); i++)
	{
		this->saveExercise(dayIndex, i);
	}
	this->stream->writeEndElement(); // /day
}

void filewriter::saveWeight(int dayIndex, int weightIndex)
{
	this->stream->writeStartElement("weight");

	this->stream->writeTextElement("time", this->ptrDays->value(dayIndex)->getWeightListPtr()->value(weightIndex)->getTimeStr());
	this->stream->writeTextElement("mass", this->ptrDays->value(dayIndex)->getWeightListPtr()->value(weightIndex)->getMassStr());

	this->stream->writeEndElement(); // /weight
}

void filewriter::saveNom(int dayIndex, int nomIndex)
{
	this->stream->writeStartElement("nom");

	this->stream->writeTextElement("time", this->ptrDays->value(dayIndex)->getNomListPtr()->value(nomIndex)->getTimeStr());
	this->stream->writeTextElement("desc", this->ptrDays->value(dayIndex)->getNomListPtr()->value(nomIndex)->getDescription());
	this->stream->writeTextElement("ener", this->ptrDays->value(dayIndex)->getNomListPtr()->value(nomIndex)->getEnergyStr());

	this->stream->writeEndElement(); // /nom
}

void filewriter::saveExercise(int dayIndex, int exerIndex)
{
	this->stream->writeStartElement("exer");

	this->stream->writeTextElement("completed", QString::number(this->ptrDays->value(dayIndex)->getExerListPtr()->value(exerIndex)->getCompletion()));
	this->stream->writeTextElement("type", this->ptrDays->value(dayIndex)->getExerListPtr()->value(exerIndex)->getType());
	this->stream->writeTextElement("dist", QString::number(this->ptrDays->value(dayIndex)->getExerListPtr()->value(exerIndex)->getDistance()));
	this->stream->writeTextElement("ener", QString::number(this->ptrDays->value(dayIndex)->getExerListPtr()->value(exerIndex)->getEnergy()));
	this->stream->writeTextElement("note", this->ptrDays->value(dayIndex)->getExerListPtr()->value(exerIndex)->getNote());

	this->stream->writeEndElement(); // /exer
}
