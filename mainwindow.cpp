#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
/**************************************************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dijkstra(new DijkstraAlgorithmGraph)
    , fordfulkerson(new FordFulkersonAlgorithmGraph)
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");

    int n = 6;
    QVector<QVector<int>>g ={ {0, 3, 5, -1, -1, -1  },
                              {-1, 0, -1, 7, 5, -1  },
                              { -1, -1, 0, -1, 3,-1 },
                              {-1, -1, 3, 0, -1, 11 },
                              {-1, -1, -1, -1, 0, 7 },
                              {-1, -1, -1, -1, -1, 0} };

    QVector<int>prev(n, -1);
    qDebug() << this->fordfulkerson->Algorithm(g, prev , 0, 5, n);

}
/**************************************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
    delete this->dijkstra;
    delete this->fordfulkerson;
}
/**************************************************************************************************/
