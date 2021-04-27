#include "dialog.h"
#include "ui_dialog.h"
#include <string>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::pegaDimXDialogo()
{
    return ui->lineEditDimX->text();
}

QString Dialog::pegaDimYDialogo()
{
    return ui->lineEditDimY->text();
}

QString Dialog::pegaDimZDialogo()
{
    return ui->lineEditDimZ->text();
}


