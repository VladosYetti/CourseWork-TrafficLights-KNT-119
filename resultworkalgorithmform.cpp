#include "resultworkalgorithmform.h"
#include "ui_resultworkalgorithmform.h"
/**************************************************************************************************/
ResultWorkAlgorithmForm::ResultWorkAlgorithmForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWorkAlgorithmForm)
   , dijkstra(new DijkstraAlgorithmGraph())
   , fordfulkerson(new FordFulkersonAlgorithmGraph())
   , bfs(new BFSAlgorithmGraph())

{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(""));
    QObject::connect(dijkstra, SIGNAL(GraphPath(QVector<QVector<int>>&, QVector<int>&)), this, SLOT(setData(QVector<QVector<int>>&, QVector<int>&)));
    QObject::connect(fordfulkerson, SIGNAL(GraphPath(QVector<QVector<int>>&, QVector<int>&)), this, SLOT(setData(QVector<QVector<int>>&, QVector<int>&)));
    QObject::connect(bfs, SIGNAL(GraphPath(QVector<QVector<int>>&, QVector<int>&)), this, SLOT(setData(QVector<QVector<int>>&, QVector<int>&)));
}
/**************************************************************************************************/
ResultWorkAlgorithmForm::~ResultWorkAlgorithmForm()
{
    delete ui;
    delete this->dijkstra;
    delete this->fordfulkerson;
    delete this->bfs;
}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::setData(QVector<QVector<int> > &g, QVector<int> &path)
{
    this->g = g;
    this->prev = path;
}
/**************************************************************************************************/
