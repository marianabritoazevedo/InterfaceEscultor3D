#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString pegaDimXDialogo();
    QString pegaDimYDialogo();
    QString pegaDimZDialogo();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
