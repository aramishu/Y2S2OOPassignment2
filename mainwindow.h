#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>
//#include <QPointer>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QMessageBox>
#include <QDebug>
#include "day_aj.h"
#include "exercise_aj.h"
#include "nom_aj.h"
#include "weight_aj.h"
#include "user_aj.h"
#include "settinghandler_aj.h"
#include "filewriter.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void setDaylistPtr(QList<day_aj *>* ptrDays);
	void setUserPtr(user_aj* u);
	void setSettingPtr(settingHandler_aj* s);
	void initialise();
	/*void drawDays();
	void drawWeights(int day, QFormLayout* gbLayout);
	void drawNomz(int day, QFormLayout* gbLayout);
	void drawExers(int day, QFormLayout* gbLayout);

protected:
	virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;*/

private slots:
	void on_calendarWidget_selectionChanged();
	void on_type_editingFinished();
	void on_completed_stateChanged(int state);
	void on_distance_editingFinished();
	void on_exerEner_editingFinished();
	void on_description_textChanged();
	void on_nomTime_editingFinished();
	void on_nomener_editingFinished();
	void on_note_textChanged();
	void on_weighttime_editingFinished();
	void on_weight_editingFinished();
	void on_addexer_clicked();
	void on_addNom_clicked();
	void on_addweight_clicked();
	void on_exerlist_currentRowChanged(int currentRow);
	void on_nomlist_currentRowChanged(int currentRow);
	void on_weightlist_currentRowChanged(int currentRow);

	void on_actionSave_activated();

	void on_actionView_totals_activated();

	void on_subExer_clicked();

	void on_subNom_clicked();

	void on_subWeight_clicked();

private:
	Ui::MainWindow *ui;
	//QFormLayout* layout;
	QList<day_aj *>* ptrDays;
	user_aj* ptrUser;
	settingHandler_aj* ptrSettings;

	int selectedDayIndex; // -1 if day not in list
	int selectedNomIndex;
	int selectedExerIndex;
	int selectedWeightIndex;

	int getDayIndex(QDate day);
	void populateDay();
	void clearLists();
	void clearBoxes();
	void populateExerBoxes();
	void populateNomBoxes();
	void populateWeightBoxes();
	void clearExerBoxes();
	void clearNomBoxes();
	void clearWeightBoxes();
	void enableExerBoxes();
	void enableNomBoxes();
	void enableWeightBoxes();
	bool validDay();
	void addDayIfNeeded();
	double energyUsedForDay(); //return total energry burn for day in chosen units
	double energyConsumedForDay(); //return total energry gained for day in chosen units
	void populateUnitLables();
	energy_aj calculateRMR(char gender, double w, double h, int a); //resting metabolic rate
	energy_aj getRMRforSelectedDay();
	double getLatestWeightToSelectedDay();
};

#endif // MAINWINDOW_H
