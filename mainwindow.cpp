#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
/**************************************************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dijkstra(new DijkstraAlgorithmGraph)
    , fordfulkerson(new FordFulkersonAlgorithmGraph)
    , bfs(new BFSAlgorithmGraph)
    , resultworkalgorithmform(new ResultWorkAlgorithmForm(this))
    , aboutform(new AboutForm(this))
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
    /**************************************************************************************************/
    QObject::connect(this->dijkstra, &DijkstraAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    QObject::connect(this->fordfulkerson, &FordFulkersonAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    QObject::connect(this->bfs, &BFSAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    /**************************************************************************************************/











}
/**************************************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
    delete this->dijkstra;
    delete this->fordfulkerson;
    delete this->bfs;
    delete this->resultworkalgorithmform;
    delete this->aboutform;
}
/**************************************************************************************************/

void MainWindow::on_actionAbout_triggered()
{
    this->aboutform->show();
}

void MainWindow::on_actionBest_Route_Planner_triggered()
{
            int n = 6;
                                 g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                                      {-1, 0, -1, 7, 5, -1  },
                                      { -1, -1, 0, -1, 3,-1 },
                                      {-1, -1, 3, 0, -1, 11 },
                                      {-1, -1, -1, -1, 0, 7 },
                                      {-1, -1, -1, -1, -1, 0} };

            prev = QVector<int>(n, -1);
            qDebug() << this->dijkstra->Algorithm(g, prev , 0, 5, n);
            this->resultworkalgorithmform->show();
}

void MainWindow::on_actionEXIT_triggered()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)  QApplication::quit();
}

void MainWindow::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionGitHub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/VladosYetti/CourseWork-TrafficLights-KNT-119"));
}

void MainWindow::on_actionTraffic_ongestion_triggered()
{
    int n = 6;
                         g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                              {-1, 0, -1, 7, 5, -1  },
                              { -1, -1, 0, -1, 3,-1 },
                              {-1, -1, 3, 0, -1, 11 },
                              {-1, -1, -1, -1, 0, 7 },
                              {-1, -1, -1, -1, -1, 0} };

    prev = QVector<int>(n, -1);
    qDebug() << this->fordfulkerson->Algorithm(g, prev , 0, 5, n);
    this->resultworkalgorithmform->show();
}

void MainWindow::on_actionConnection_heck_triggered()
{
    int n = 6;
                         g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                              {-1, 0, -1, 7, 5, -1  },
                              { -1, -1, 0, -1, 3,-1 },
                              {-1, -1, 3, 0, -1, 11 },
                              {-1, -1, -1, -1, 0, 7 },
                              {-1, -1, -1, -1, -1, 0} };

    prev = QVector<int>(n, -1);
    qDebug() << this->bfs->Algorithm(g, prev , 0, 5, n);
    this->resultworkalgorithmform->show();
}
