#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->selectedDayIndex = -1;
	this->selectedNomIndex = -1;
	this->selectedExerIndex = -1;
	this->selectedWeightIndex = -1;
	this->ptrDays = 0;
	this->ptrUser = 0;
	this->ptrSettings = 0;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setDaylistPtr(QList<day_aj *>* ptrDays)
{
	this->ptrDays = ptrDays;

}

void MainWindow::setUserPtr(user_aj* u)
{
	this->ptrUser = u;

	this->populateUnitLables();
}

void MainWindow::setSettingPtr(settingHandler_aj* s)
{
	this->ptrSettings = s;
}

void MainWindow::initialise()
{
	if(this->ptrDays == 0 || this->ptrUser == 0)
	{	return;	}
	this->selectedDayIndex = this->ptrDays->size() - 1;
	this->populateDay();

	if(this->validDay())
	{
		this->ui->calendarWidget->setSelectedDate(this->ptrDays->value(this->selectedDayIndex)->getDate());
	}

	/* TODO: HIGHLIGHT DAYS WITH DATA
	for(int i = 0; i < this->ptrDays->size(); i++)
	{
		QDate day = this->ptrDays->value(i)->getDate();
		this-ui->calendarWidget->paintCell(&painter, rect, day); // PROTECTED FUNCTION, EXTEND AND REIMPLEMENT -> http://appearstupid.blogspot.com/2008/06/highlight-todays-date-in.html
	}*/
}

bool MainWindow::validDay()
{
	if(this->selectedDayIndex > -1)
	{	return true; }
	return false;
}

int MainWindow::getDayIndex(QDate day)
{
	for(int i = 0; i < this->ptrDays->size(); i++)
	{
		if(this->ptrDays->value(i)->getDate() == day)
		{    return i;   }
	}
	return -1;
}


void MainWindow::on_calendarWidget_selectionChanged()
{
	QDate selected = this->ui->calendarWidget->selectedDate();

	this->selectedDayIndex = this->getDayIndex(selected);

	this->populateDay();
}

void MainWindow::populateDay()
{
	this->clearLists();

	if(this->validDay())
	{
		QList<exercise_aj*>* exerList = this->ptrDays->value(this->selectedDayIndex)->getExerListPtr();
		for(int i = 0; i < exerList->size(); i++)
		{// add exercises to list
			this->ui->exerlist->addItem(exerList->value(i)->getType());
		}

		if(this->selectedExerIndex == -1) // dont change selection if one already selected
		{	this->selectedExerIndex = exerList->size() - 1;	}

		this->populateExerBoxes();

		QList<nom_aj*>* nomList =  this->ptrDays->value(this->selectedDayIndex)->getNomListPtr();
		for(int i = 0; i < nomList->size(); i++)
		{// add food to list
			this->ui->nomlist->addItem(nomList->value(i)->getTimeString());
		}

		if(this->selectedNomIndex == -1) // dont change selection if one already selected
		{	this->selectedNomIndex = nomList->size() - 1;	}

		this->populateNomBoxes();

		QList<weight_aj*>* weightList = this->ptrDays->value(this->selectedDayIndex)->getWeightListPtr();
		for(int i = 0; i < weightList->size(); i++)
		{// add food to list
			this->ui->weightlist->addItem(weightList->value(i)->getTimeString());
		}

		if(this->selectedWeightIndex == -1) // dont change selection if one already selected
		{	this->selectedWeightIndex = weightList->size() - 1;	}
		this->populateWeightBoxes();
	}
	else
	{ this->clearBoxes();   }
}

void MainWindow::clearLists()
{
	this->ui->exerlist->clear();
	this->ui->nomlist->clear();
	this->ui->weightlist->clear();
}

void MainWindow::clearBoxes()
{
	this->clearExerBoxes();
	this->clearNomBoxes();
	this->clearWeightBoxes();
}

void MainWindow::populateExerBoxes()
{
	if(this->selectedExerIndex > -1)
	{
		exercise_aj* exer = this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex);

		Qt::CheckState state = (exer->getCompletion()) ? Qt::Checked : Qt::Unchecked;
		this->ui->completed->setCheckState(state);

		this->ui->type->setText(exer->getType());

		this->ui->distance->setValue(exer->getDistance(this->ptrUser->getDistu()));

		this->ui->exerEner->setValue(exer->getEnergy(this->ptrUser->getEneru()));

		this->ui->description->setText(exer->getNote());

		this->enableExerBoxes();

		this->ui->exerlist->setCurrentRow(this->selectedExerIndex);
	}
	else
	{   this->clearExerBoxes(); }
}

void MainWindow::populateNomBoxes()
{
	if(this->selectedNomIndex > -1)
	{
		nom_aj* nom = this->ptrDays->value(this->selectedDayIndex)->getNomListPtr()->value(this->selectedNomIndex);

		this->ui->nomener->setValue(nom->getEnergy(this->ptrUser->getEneru()));
		this->ui->nomTime->setTime(nom->getTime());
		this->ui->note->setText(nom->getDescription());

		this->enableNomBoxes();

		this->ui->nomlist->setCurrentRow(this->selectedNomIndex);
	}
	else
	{	this->clearNomBoxes();	}
}

void MainWindow::populateWeightBoxes()
{
	if(this->selectedWeightIndex > -1)
	{
		weight_aj* weight = this->ptrDays->value(this->selectedDayIndex)->getWeightListPtr()->value(this->selectedWeightIndex);

		this->ui->weighttime->setTime(weight->getTime());
		this->ui->weight->setValue(weight->getMass(this->ptrUser->getMassu()));

		this->enableWeightBoxes();

		this->ui->weightlist->setCurrentRow(this->selectedWeightIndex);
	}
	else
	{	this->clearWeightBoxes();	}
}

void MainWindow::clearExerBoxes()
{
	this->ui->completed->setCheckState(Qt::Unchecked);
	this->ui->distance->clear(); //setValue(0.0f);
	this->ui->exerEner->clear(); //setValue(0.0f);
	this->ui->description->clear();
	this->ui->type->clear();

	this->ui->completed->setEnabled(false);
	this->ui->distance->setEnabled(false);
	this->ui->exerEner->setEnabled(false);
	this->ui->description->setEnabled(false);
	this->ui->type->setEnabled(false);
}

void MainWindow::clearNomBoxes()
{
	this->ui->nomener->clear(); //setValue(0.0f);
	this->ui->nomTime->setTime(QTime(0,0,0));
	this->ui->note->clear();

	this->ui->nomener->setEnabled(false);
	this->ui->nomTime->setEnabled(false);
	this->ui->note->setEnabled(false);
}

void MainWindow::clearWeightBoxes()
{
	this->ui->weighttime->setTime(QTime(0,0,0));
	this->ui->weight->clear(); //setValue(0.0f);

	this->ui->weighttime->setEnabled(false);
	this->ui->weight->setEnabled(false);
}

void MainWindow::enableExerBoxes()
{
	this->ui->completed->setEnabled(true);
	this->ui->distance->setEnabled(true);
	this->ui->exerEner->setEnabled(true);
	this->ui->description->setEnabled(true);
	this->ui->type->setEnabled(true);
}

void MainWindow::enableNomBoxes()
{
	this->ui->nomener->setEnabled(true);
	this->ui->nomTime->setEnabled(true);
	this->ui->note->setEnabled(true);
}

void MainWindow::enableWeightBoxes()
{
	this->ui->weighttime->setEnabled(true);
	this->ui->weight->setEnabled(true);
}

void MainWindow::on_type_editingFinished()
{
	if(this->selectedExerIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex)->setType(this->ui->type->text());
		this->populateDay();
	}
}

void MainWindow::on_completed_stateChanged(int state)
{
	if(this->selectedExerIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex)->setCompletion((state == Qt::Checked) ? true : false);
	}
}

void MainWindow::on_distance_editingFinished()
{
	if(this->selectedExerIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex)->setDistance(this->ui->distance->value(), this->ptrUser->getDistu());
	}
}

void MainWindow::on_exerEner_editingFinished()
{
	if(this->selectedExerIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex)->setEnergy(this->ui->exerEner->value(), this->ptrUser->getEneru());
	}
}

void MainWindow::on_description_textChanged()
{
	if(this->selectedExerIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->value(this->selectedExerIndex)->setNote(this->ui->description->toPlainText());
	}
}


void MainWindow::on_nomTime_editingFinished()
{
	if(this->selectedNomIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getNomListPtr()->value(this->selectedNomIndex)->setTime(this->ui->nomTime->time());
		this->populateDay();
	}
}

void MainWindow::on_nomener_editingFinished()
{
	if(this->selectedNomIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getNomListPtr()->value(this->selectedNomIndex)->setEnergy(this->ui->nomener->value(), this->ptrUser->getEneru());
	}
}

void MainWindow::on_note_textChanged()
{
	if(this->selectedNomIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getNomListPtr()->value(this->selectedNomIndex)->setDecription(this->ui->note->toPlainText());
	}
}

void MainWindow::on_weighttime_editingFinished()
{
	if(this->selectedWeightIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getWeightListPtr()->value(this->selectedWeightIndex)->setTime(this->ui->weighttime->time());
		this->populateDay();
	}
}

void MainWindow::on_weight_editingFinished()
{
	if(this->selectedWeightIndex > -1 && this->validDay())
	{
		this->ptrDays->value(this->selectedDayIndex)->getWeightListPtr()->value(this->selectedWeightIndex)->setMass(this->ui->weight->value(), this->ptrUser->getMassu());
	}
}

void MainWindow::on_addexer_clicked()
{
	this->addDayIfNeeded();

	this->ptrDays->value(this->selectedDayIndex)->addExercise(new exercise_aj("workout " + QString::number(this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->size() + 1)));
	this->selectedExerIndex = this->ptrDays->value(this->selectedDayIndex)->getExerListPtr()->size() - 1;
	this->populateDay();
}

void MainWindow::on_addNom_clicked()
{
	this->addDayIfNeeded();

	this->ptrDays->value(this->selectedDayIndex)->addNom(new nom_aj());
	this->selectedNomIndex = this->ptrDays->value(this->selectedDayIndex)->getNomListPtr()->size() - 1;
	this->populateDay();
}

void MainWindow::on_addweight_clicked()
{
	this->addDayIfNeeded();

	this->ptrDays->value(this->selectedDayIndex)->addWeight(new weight_aj());
	this->selectedWeightIndex = this->ptrDays->value(this->selectedDayIndex)->getWeightListPtr()->size() - 1;
	this->populateDay();
}

void MainWindow::on_subExer_clicked()
{
	if(this->selectedExerIndex > -1)
	{
		this->ptrDays->value(this->selectedDayIndex)->removeExer(this->selectedExerIndex);
		this->selectedExerIndex = -1; // revert to default selection logic
		this->populateDay();
	}
}


void MainWindow::on_subNom_clicked()
{
	if(this->selectedNomIndex > -1)
	{
		this->ptrDays->value(this->selectedDayIndex)->removeNom(this->selectedNomIndex);
		this->selectedNomIndex = -1; // revert to default selection logic
		this->populateDay();
	}
}

void MainWindow::on_subWeight_clicked()
{
	if(this->selectedWeightIndex > -1)
	{
		this->ptrDays->value(this->selectedDayIndex)->removeWeight(this->selectedWeightIndex);
		this->selectedWeightIndex = -1; // revert to default selection logic
		this->populateDay();
	}
}


void MainWindow::addDayIfNeeded()
{
	if(!this->validDay())
	{
		this->ptrDays->append(new day_aj(this->ui->calendarWidget->selectedDate()));
		this->selectedDayIndex = this->getDayIndex(this->ui->calendarWidget->selectedDate());
	}
}

void MainWindow::on_exerlist_currentRowChanged(int currentRow)
{
	if(currentRow > -1) // -1 is value for no current row selected which gets triggered byt the clear() function when repopulating.
	{
		this->selectedExerIndex = currentRow;
		this->populateExerBoxes();
	}
}

void MainWindow::on_nomlist_currentRowChanged(int currentRow)
{
	if(currentRow > -1) // -1 is value for no current row selected which gets triggered byt the clear() function when repopulating.
	{
		this->selectedNomIndex = currentRow;
		this->populateNomBoxes();
	}
}

void MainWindow::on_weightlist_currentRowChanged(int currentRow)
{
	if(currentRow > -1) // -1 is value for no current row selected which gets triggered byt the clear() function when repopulating.
	{
		this->selectedWeightIndex = currentRow;
		this->populateWeightBoxes();
	}
}

void MainWindow::on_actionSave_activated()
{
	filewriter wfile(this->ptrUser->getFileName(), this->ptrDays);
	wfile.saveFile();

	//if(this->ptrSettings != 0)
	//{
	this->ptrSettings->setNumdays(this->ptrDays->size());
	//}
}

void MainWindow::on_actionView_totals_activated()
{
	QString msgText;
	if(this->validDay())
	{
		msgText = "Total energy used: " +
				QString::number(this->energyUsedForDay()) + this->ptrUser->getEneruStr() +
				"<br>Total energy consumed: " + QString::number(this->energyConsumedForDay()) + this->ptrUser->getEneruStr() +
				"<br>RMR: " + QString::number(this->getRMRforSelectedDay().getEnergy(this->ptrUser->getEneru())) + this->ptrUser->getEneruStr();
	}
	else
	{
		msgText = "There is no data for this day. Try adding data by clicking the + buttons.";
	}
	QMessageBox::information(this, "Day " + this->ui->calendarWidget->selectedDate().toString("ddd dd MM yy"), msgText, QMessageBox::Close);

}

double MainWindow::energyConsumedForDay()
{
	QList<nom_aj*>* nomList = this->ptrDays->value(this->selectedDayIndex)->getNomListPtr();
	double total = 0;

	for(int i = 0; i < nomList->size(); i++)
	{
		total += nomList->value(i)->getEnergy(this->ptrUser->getEneru());
	}
	return total;
}

double MainWindow::energyUsedForDay()
{
	QList<exercise_aj*>* exerList = this->ptrDays->value(this->selectedDayIndex)->getExerListPtr();
	double total = 0;

	for(int i = 0; i < exerList->size(); i++)
	{
		total += exerList->value(i)->getEnergy(this->ptrUser->getEneru());
	}
	return total;
}
 void MainWindow::populateUnitLables()
 {
	 this->ui->exerdistu->setText(this->ptrUser->getDistuStr());
	 this->ui->exereneru->setText(this->ptrUser->getEneruStr());
	 this->ui->nomeneru->setText(this->ptrUser->getEneruStr());
	 this->ui->massu->setText(this->ptrUser->getMassuStr());
 }

 energy_aj MainWindow::getRMRforSelectedDay()
 {
	 double w = this->getLatestWeightToSelectedDay();

	 qDebug() << "latest weight: " << w;

	 if(w == 0) // no weight data
	 {
		 w = 70; //default to 70kg
	 }

	 return this->calculateRMR(this->ptrUser->getGender(), w, this->ptrUser->getHeight(), this->ptrUser->getAge());
 }

 energy_aj MainWindow::calculateRMR(char gender, double w, double h, int a)
 {
	 //http://www.caloriesperhour.com/tutorial_BMR.php
	 //For men: (10 x w) + (6.25 x h) - (5 x a) + 5
	 //For women: (10 x w) + (6.25 x h) - (5 x a) - 161
	 //w = weight in kg
	 //h = height in cm
	 //a = age
	 // gives result in kCal
	 qDebug() << "gender " << gender;
	 qDebug() << "w " << w;
	 qDebug() << "h " << h;
	 qDebug() << "a" << a;
	 double mfFactor;
	 if(MALE == gender)
	 {	mfFactor = MALE_FACTOR; }
	 else
	 {	mfFactor = FEMALE_FACTOR;	}

	 qDebug() << mfFactor;
	 qDebug() << ((10.0f*w) + (6.25*(h*100)) - (5*(double)a) + (mfFactor));

	 return energy_aj(((10.0f*w) + (6.25*(h*100)) - (5*(double)a) + (mfFactor)), CALORIE);
 }


 double MainWindow::getLatestWeightToSelectedDay()
 {
	int dayIndex = this->selectedDayIndex;
	double tmpWeight = 0;
	int tmpTime = 0;

	while(dayIndex >= 0)
	{
		day_aj* day = this->ptrDays->value(dayIndex);
		if(this->validDay())
		{
			for(int i = 0; i < day->getWeightListPtr()->size(); i++)
			{
				if(tmpTime < day->getWeightListPtr()->value(i)->getTimeInt())
				{
					tmpTime = day->getWeightListPtr()->value(i)->getTimeInt();
					tmpWeight = day->getWeightListPtr()->value(i)->getMass();
				}
			}
			if(tmpWeight != 0) break;
		}
		else
		{	// go to newest day if day not valid. TODO: GO TO CLOSEST DAY IN THE PAST THAT HAS DATA.
			dayIndex = this->ptrDays->size();
		}
		dayIndex--;
	}

	return tmpWeight;
 }

/* Original gui generation code
void MainWindow::drawDays()
{
	this->layout = new QFormLayout;
	for(int i = 0; i < this->ptrDays->size(); i++)
	{
		QGroupBox* dayBox = new QGroupBox(this->ptrDays->value(i)->getDate().toString("ddd dd MMM yy"));

		QFormLayout* gbLayout = new QFormLayout;

		//gbLayout->addRow("hello", new QLineEdit("stuff"));
		this->drawExers(i, gbLayout);

		dayBox->setLayout(gbLayout);
		this->layout->addWidget(dayBox);
	}
	this->ui->Days->setLayout(this->layout);
}

void MainWindow::drawExers(int day, QFormLayout *gbLayout)
{
	QGroupBox* exerBox = new QGroupBox("Workouts");
	QFormLayout* exerBoxLayout = new QFormLayout;

	for(int i = 0; i < this->ptrDays->value(day)->getExerListPtr()->size(); i++)
	{
		QHBoxLayout* exerLayout = new QHBoxLayout;

		QCheckBox* completed =  new QCheckBox("Completed");
		completed->setCheckState((this->ptrDays->value(day)->getExerListPtr()->value(i)->getCompletion()) ? Qt::Checked : Qt::Unchecked);
		exerLayout->addWidget(completed);

		QLineEdit* type = new QLineEdit(this->ptrDays->value(day)->getExerListPtr()->value(i)->getType());
		QLabel* label = new QLabel("Type:");
		label->setBuddy(type);
		exerLayout->addWidget(label);
		exerLayout->addWidget(type);

		QDoubleSpinBox* distance = new QDoubleSpinBox();
		distance->setRange(0.0f, 999999.99f);
		char distu = this->ptrUser->getDistu();
		distance->setValue(this->ptrDays->value(day)->getExerListPtr()->value(i)->getDistance(&distu));
		exerLayout->addWidget(distance);

		exerBoxLayout->addRow(exerLayout);

		exerLayout = new QHBoxLayout;

		QDoubleSpinBox* energy = new QDoubleSpinBox();
		energy->setRange(0.0f, 999999.99f);
		char enneru = this->ptrUser->getEneru();
		energy->setValue(this->ptrDays->value(day)->getExerListPtr()->value(i)->getEnergy(&enneru));
		exerLayout->addWidget(energy);

		QTextEdit* note = new QTextEdit(this->ptrDays->value(day)->getExerListPtr()->value(i)->getNote());
		note->setMaximumHeight(30);
		exerLayout->addWidget(note);

		exerBoxLayout->addRow(exerLayout);
	}
	exerBox->setLayout(exerBoxLayout);
	gbLayout->addRow(exerBox);
}
*/
