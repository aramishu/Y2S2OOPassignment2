#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QtXml/QXmlStreamReader>
#include <QList>
#include <day_aj.h>
#include <QDebug>
#include <QProgressBar>
#include <QObject>
#include "loadinxmlporgress.h"

class fileReader: public QObject
{
		Q_OBJECT
	public:
		fileReader();
		fileReader(QList<day_aj*>* ptrDays);
		fileReader(QString fileName, QList<day_aj*>* ptrDays);
		fileReader(QString fileName, QList<day_aj*>* ptrDays, unsigned int numDays);
		bool openFile();
		void parseFile();

	private:

		void parseSettings(QXmlStreamReader &xml);
		void parseData(QXmlStreamReader &xml);
		void parseDays(QXmlStreamReader &xml);
		void parseDay(QXmlStreamReader &xml);
		void parseWeight(QXmlStreamReader &xml);
		void parseNomz(QXmlStreamReader &xml);
		void parseExer(QXmlStreamReader &xml);
		QString getNextVal(QXmlStreamReader &xml);

		QFile* file;
		int dayIndex;
		unsigned int numDays;
		QList<day_aj *>* ptrDays;

		loadinxmlPorgress progress;
};

#endif // FILEREADER_H
