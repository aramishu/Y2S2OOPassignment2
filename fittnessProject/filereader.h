#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QtXml/QXmlStreamReader>

class fileReader
{
	public:
		fileReader();

	private:
		void parseSettings(QXmlStreamReader& xml);
		void parseData(QXmlStreamReader& xml);
		void parseDays(QXmlStreamReader& xml);
		void parseDay(QXmlStreamReader &xml);
		void parseWeight(QXmlStreamReader &xml);
		void parseNomz(QXmlStreamReader &xml);
		void parseExer(QXmlStreamReader &xml);
		QString getNextVal(QXmlStreamReader& xml);
};

#endif // FILEREADER_H
