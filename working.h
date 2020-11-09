#ifndef WORKING_H
#define WORKING_H

#include <QDialog>

namespace Ui {
  class working;
}

class working : public QDialog
{
  Q_OBJECT

public:
  explicit working(QWidget *parent = nullptr);
  ~working();

private:
  Ui::working *ui;
};

#endif // WORKING_H
