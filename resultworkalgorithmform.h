#pragma once
#ifndef RESULTWORKALGORITHMFORM_H
#define RESULTWORKALGORITHMFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QString>
#include <QIcon>
#include <QMessageBox>
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
    void setData(QVector<QVector<int>> g, QVector<int> path, int res);

private slots:
    void on_Close_clicked();

private:
    Ui::ResultWorkAlgorithmForm *ui;
    QVector<QVector<int>>g;
    QVector<int>prev;
};
/**************************************************************************************************/
#endif // RESULTWORKALGORITHMFORM_H
