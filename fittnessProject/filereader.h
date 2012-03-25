#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QtXml/QXmlStreamReader>
#include <QList>
#include <day_aj.h>

class fileReader
{
	public:
		fileReader();
		fileReader(QList<day_aj*>* ptrDays);
		fileReader(QString fileName, QList<day_aj*>* ptrDays);
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
		QList<day_aj *>* ptrDays;
};

#endif // FILEREADER_H
