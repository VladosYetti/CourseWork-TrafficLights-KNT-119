#pragma once
#ifndef ABOUTFORM_H
#define ABOUTFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>
/**************************************************************************************************/
namespace Ui {
class AboutForm;
}
class AboutForm : public QDialog
{
    Q_OBJECT
public:
    explicit AboutForm(QWidget *parent = nullptr);
    ~AboutForm();
private slots:
    void on_close_clicked();
    void on_Duties_clicked();
    void on_About_clicked();
private:
    Ui::AboutForm *ui;
};
/**************************************************************************************************/
#endif // ABOUTFORM_H
