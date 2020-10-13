#pragma once
#ifndef RESULTWORKALGORITHMFORM_H
#define RESULTWORKALGORITHMFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QIcon>
#include <dijkstraalgorithmgraph.h>
#include <fordfulkersonalgorithmgraph.h>
#include <bfsalgorithmgraph.h>
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
    void setData(QVector<QVector<int>>&g, QVector<int>&path);

private:
    Ui::ResultWorkAlgorithmForm *ui;
    DijkstraAlgorithmGraph* dijkstra;
    FordFulkersonAlgorithmGraph* fordfulkerson;
    BFSAlgorithmGraph* bfs;
    QVector<QVector<int>>g;
    QVector<int>prev;
};
/**************************************************************************************************/
#endif // RESULTWORKALGORITHMFORM_H
