#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QFile>
#include <QtXml/QXmlStreamWriter>
#include <QList>
#include <day_aj.h>
#include <QDebug>
#include <QProgressDialog>

class filewriter
{
	public:
		filewriter();
		filewriter(QList<day_aj*>* ptrDays);
		filewriter(QString fileName, QList<day_aj*>* ptrDays);
		~filewriter();

		bool openFile();
		void saveFile();

	private:
		QFile* file;
		QList<day_aj *>* ptrDays;
		QXmlStreamWriter* stream;

		void saveDay(int dayIndex);
		void saveWeight(int dayIndex, int weightIndex);
		void saveNom(int dayIndex, int nomIndex);
		void saveExercise(int dayIndex, int exerIndex);
};

#endif // FILEWRITER_H
