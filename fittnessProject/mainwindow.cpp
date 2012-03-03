#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cout << "hello world?" << endl;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
