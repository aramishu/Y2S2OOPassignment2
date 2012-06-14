#include "filereader.h"

fileReader::fileReader()
{
	this->file = new QFile("testFile.xml");

	this->ptrDays = new QList<day_aj*>();
}

fileReader::fileReader(QList<day_aj*>* ptrDays)
{
	this->dayIndex = 0;
	this->file = new QFile("testFile.xml");
	this->ptrDays = ptrDays;
	this->numDays = 100;
}

fileReader::fileReader(QString fileName, QList<day_aj*>* ptrDays)
{
	this->dayIndex = 0;
	this->file = new QFile(fileName);
	this->ptrDays = ptrDays;
	this->numDays = 100;
}

fileReader::fileReader(QString fileName, QList<day_aj*>* ptrDays, unsigned int numDays)
{
	this->dayIndex = 0;
	this->file = new QFile(fileName);
	this->ptrDays = ptrDays;
	this->numDays = numDays;
}

void fileReader::parseFile()
{
	this->progress.setMessage("Loading data");
	this->progress.setMax(this->numDays + 1);
	this->progress.setValue(0);
	this->progress.show();

	if(this->file->isOpen())
	{
		QXmlStreamReader xml(this->file);

		while(!xml.atEnd())
		{
			QXmlStreamReader::TokenType token = xml.readNext();

			if(token == QXmlStreamReader::StartDocument)
			{
				qDebug() << "StartDocument";
				continue;
			}

			if(token == QXmlStreamReader::StartElement)
			{
				if(xml.name() == "data")
				{
					qDebug() << "parsing data";
					this->parseData(xml);
				}
			}
		}

		if (xml.hasError())
		{		qDebug() << "Error with xml file::" << xml.errorString();		}
	}
	else
	{	qDebug() << "cannot parse file, file not open";	}

	this->file->close();
	this->progress.setValue(this->numDays);
	this->progress.close();
}

bool fileReader::openFile()
{
	if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
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
/*
void fileReader::parseSettings(QXmlStreamReader &xml)
{
	QString distu, calu, massu;

	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "settings"))
	{
		xml.readNext();
		//if(xml.tokenType() == QXmlStreamReader::Characters)
		//{	continue;	}
		//if(xml.tokenType() != QXmlStreamReader::StartElement)
		//{	continue;	}

		if(xml.tokenType() == QXmlStreamReader::StartElement)
		{
			if(xml.name() == "distu")
			{
				distu = this->getNextVal(xml);
			}
			else if(xml.name() == "calu")
			{
				calu = this->getNextVal(xml);
			}
			else if(xml.name() == "massu")
			{
				massu =this->getNextVal(xml);
			}
		}
	}
	qDebug() << "disu" << distu;
	qDebug() << "calu" << calu;
	qDebug() << "massu" << massu;
}*/

void fileReader::parseData(QXmlStreamReader &xml)
{
	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "data"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "days")
		{
			this->parseDays(xml);
		}
		/*else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "userdata")
		{
			//this->parseUserdata(xml);
		}		
		else if(xml.name() == "settings")
		{
			this->parseSettings(xml);
		}*/
	}
}

void fileReader::parseDays(QXmlStreamReader &xml)
{
	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "days"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "day")
		{
			this->parseDay(xml);
			this->dayIndex++;
			this->progress.setValue(this->dayIndex);
			qDebug() << "index: " << dayIndex;
		}
	}
}

void fileReader::parseDay(QXmlStreamReader &xml)
{
	this->ptrDays->append(new day_aj());

	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "day"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "date")
		{
			this->ptrDays->value(this->dayIndex)->setDate(this->getNextVal(xml));
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "weight")
		{
			this->parseWeight(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "nom")
		{
			this->parseNomz(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "exer")
		{
			this->parseExer(xml);
		}
	}
}

void fileReader::parseWeight(QXmlStreamReader &xml)
{
	QString wtime, wmass;
	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "weight"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "time")
		{
			wtime = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "mass")
		{
			wmass = this->getNextVal(xml);
		}
	}
	this->ptrDays->value(this->dayIndex)->addWeight(new weight_aj(wmass, wtime));
	//qDebug() << "wtime" << wtime;
	//qDebug() << "wmass" << wmass;
}

void fileReader::parseNomz(QXmlStreamReader &xml)
{
	QString desc, ntime, ener;
	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "nom"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "desc")
		{
			desc = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "time")
		{
			ntime = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "ener")
		{
			ener = this->getNextVal(xml);
		}
	}
	this->ptrDays->value(this->dayIndex)->addNom(new nom_aj(desc, ntime, ener));
	//qDebug() << "desc" << desc;
	//qDebug() << "ntime" << ntime;
	//qDebug() << "ener" << ener;
}

void fileReader::parseExer(QXmlStreamReader &xml)
{
	QString completed, type, dist, ener, note;
	while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "exer"))
	{
		xml.readNext();
		if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "completed")
		{
			completed = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "type")
		{
			type = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "dist")
		{
			dist = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "ener")
		{
			ener = this->getNextVal(xml);
		}
		else if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "note")
		{
			note = this->getNextVal(xml);
		}
	}
	this->ptrDays->value(this->dayIndex)->addExercise(new exercise_aj(completed, type, dist, ener, note));
	//qDebug() << "completed" << completed;
	//qDebug() << "type" << type;
	//qDebug() << "dist" << dist;
	//qDebug() << "ener" << ener;
	//qDebug() << "note" << note;
}

QString fileReader::getNextVal(QXmlStreamReader &xml)
{
	xml.readNext();
	return xml.text().toString();
}

 /*void fileReader::cancel()
 {
	 qDebug() << "cancel";
 }
*/
