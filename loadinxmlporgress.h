#ifndef LOADINXMLPORGRESS_H
#define LOADINXMLPORGRESS_H

#include <QDialog>

namespace Ui {
class loadinxmlPorgress;
}

class loadinxmlPorgress : public QDialog
{
		Q_OBJECT
		
	public:
		explicit loadinxmlPorgress(QWidget *parent = 0);
		~loadinxmlPorgress();
		void setMax(int m);
		void setMessage(QString m);
		void setValue(int v);

	private:
		Ui::loadinxmlPorgress *ui;
};

#endif // LOADINXMLPORGRESS_H
