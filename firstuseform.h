#ifndef FIRSTUSEFORM_H
#define FIRSTUSEFORM_H

#include <QDialog>
#include <QDate>
#include "header_aj.h"

namespace Ui {
class firstUseForm;
}

class firstUseForm : public QDialog
{
		Q_OBJECT

	public:
		explicit firstUseForm(QWidget *parent = 0);
		~firstUseForm();

		double getHeight(void);
		QDate getDob(void);
		char getMassu(void);
		char getDistu(void);
		char getEneru(void);
		char getGender(void);

	private:
		Ui::firstUseForm *ui;
};

#endif // FIRSTUSEFORM_H
