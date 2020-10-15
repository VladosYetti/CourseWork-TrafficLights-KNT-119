#pragma once
#ifndef RESULTWORKALGORITHMFORM_H
#define RESULTWORKALGORITHMFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QString>
#include <QIcon>
#include <QMessageBox>
#include <TransferGraph.h>
/**************************************************************************************************/
namespace Ui {
class ResultWorkAlgorithmForm;
}

class ResultWorkAlgorithmForm : public QDialog
{
    Q_OBJECT
public:
    explicit ResultWorkAlgorithmForm(QWidget *parent = nullptr);
    ~ResultWorkAlgorithmForm();
public slots:
    void setData(TransferGraph obj);

private slots:
    void on_Close_clicked();

private:
    Ui::ResultWorkAlgorithmForm *ui;
    QVector<QVector<int>>g;
    QVector<int>prev;
};
/**************************************************************************************************/
#endif // RESULTWORKALGORITHMFORM_H
