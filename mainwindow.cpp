#include "mainwindow.h"
#include "ui_mainwindow.h"
/**************************************************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dijkstra(new DijkstraAlgorithmGraph)
    , fordfulkerson(new FordFulkersonAlgorithmGraph)
    , bfs(new BFSAlgorithmGraph)
    , resultworkalgorithmform(new ResultWorkAlgorithmForm(this))
    , aboutform(new AboutForm(this))
    , scene(new QGraphicsScene(this))
    , timer(new QLabel(this))
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
    this->ui->statusbar->addWidget(this->timer);
    this->startTimer(1000);
    this->timer->setText(QTime::currentTime().toString("hh:mm:ss"));
    /**************************************************************************************************/
    QObject::connect(this->dijkstra, &DijkstraAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    QObject::connect(this->fordfulkerson, &FordFulkersonAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    QObject::connect(this->bfs, &BFSAlgorithmGraph::GraphPath, this->resultworkalgorithmform, &ResultWorkAlgorithmForm::setData);
    /**************************************************************************************************/
    this->ui->graphicsView->setScene(this->scene);
    /**************************************************************************************************/
    QPixmap img;
    img.load(":/Data/Recourse/map.jpg");
    this->scene->setSceneRect(0,0,img.width(),img.height());
    this->ui->graphicsView->setBackgroundBrush(img.scaled(img.width(),img.height(),Qt::KeepAspectRatio));
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
    delete this->scene;
    delete this->timer;
}
/**************************************************************************************************/
void MainWindow::on_actionAbout_triggered()
{
    this->aboutform->show();
}
/**************************************************************************************************/
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
            this->dijkstra->Algorithm(g, prev , 0, 5, n);
            this->resultworkalgorithmform->show();
}
/**************************************************************************************************/
void MainWindow::on_actionEXIT_triggered()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)  QApplication::quit();
}
/**************************************************************************************************/
void MainWindow::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this);
}
/**************************************************************************************************/
void MainWindow::on_actionGitHub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/VladosYetti/CourseWork-TrafficLights-KNT-119"));
}
/**************************************************************************************************/
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
    this->fordfulkerson->Algorithm(g, prev , 0, 5, n);
    this->resultworkalgorithmform->show();
}
/**************************************************************************************************/
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
    this->bfs->Algorithm(g, prev , 0, 5, n);
    this->resultworkalgorithmform->show();
}
/**************************************************************************************************/
void MainWindow::on_actionClear_triggered()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {

    }
}
/**************************************************************************************************/
void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    this->timer->setText(QTime::currentTime().toString("hh:mm:ss"));
}
/**************************************************************************************************/
