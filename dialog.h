#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

/**
 * @brief A classe Dialog é responsável por abrir o modal para redimensionar o escultor
 */

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    /**
     * @brief pegaDimXDialogo recupera a dimensão do eixo x do escultor
     * @return
     */
    QString pegaDimXDialogo();

    /**
     * @brief pegaDimYDialogo recupera a dimensão y do escultor
     * @return
     */
    QString pegaDimYDialogo();

    /**
     * @brief pegaDimZDialogo recupera a dimensão z do escultor
     * @return
     */
    QString pegaDimZDialogo();

private:
    /**
     * @brief ui interface do usuário do dialog
     */
    Ui::Dialog *ui;
};

#endif // DIALOG_H
