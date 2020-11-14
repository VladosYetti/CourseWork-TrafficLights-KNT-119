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
    , work(new working(this))
    , helpform(new HelpForm(this))
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
    QObject::connect(this, &MainWindow::MaxSizeConnect, this->work, &working::setMaxSizeConnect);
    QObject::connect(this->work, &working::getConnect, [this](int a, int b)
    {
       this->arr[a - 1]->setConnect(true);
       QLineF line;
       line.setP1(this->arr[a - 1]->scenePos());
       line.setP2(this->arr[b - 1]->scenePos());
       this->scene->addLine(line);
    });
    /**************************************************************************************************/
    this->ui->graphicsView->setScene(this->scene);
    /**************************************************************************************************/
    QPixmap img;
    img.load(":/Data/Recourse/MapDay.jpg");
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
    for(auto&i:this->scene->items()) { delete  i; }
    delete this->work;
    delete this->helpform;
}
/**************************************************************************************************/
void MainWindow::on_actionAbout_triggered()
{
    this->aboutform->show();
}
/**************************************************************************************************/
void MainWindow::on_actionBest_Route_Planner_triggered()
{
  if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
  this->work->show();
            int n = 6;
                                 g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                                      {-1, 0, -1, 7, 5, -1  },
                                      { -1, -1, 0, -1, 3,-1 },
                                      {-1, -1, 3, 0, -1, 11 },
                                      {-1, -1, -1, -1, 0, 7 },
                                      {-1, -1, -1, -1, -1, 0} };

            prev = QVector<int>(n, -1);
            int s = 0, f = 5;
            InputData obj(g, prev , s, f, n);
            this->dijkstra->Algorithm(obj);
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
  if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
    this->work->show();
    int n = 6;
                         g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                              {-1, 0, -1, 7, 5, -1  },
                              { -1, -1, 0, -1, 3,-1 },
                              {-1, -1, 3, 0, -1, 11 },
                              {-1, -1, -1, -1, 0, 7 },
                              {-1, -1, -1, -1, -1, 0} };

    prev = QVector<int>(n, -1);
    int s = 0, f = 5;
    InputData obj(g, prev , s, f, n);
    this->fordfulkerson->Algorithm(obj);
    this->resultworkalgorithmform->show();
}
/**************************************************************************************************/
void MainWindow::on_actionConnection_heck_triggered()
{
  if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
  this->work->show();
    int n = 6;
                         g ={ {0, 3, 5, -1, -1, -1  },  // For Example
                              {-1, 0, -1, 7, 5, -1  },
                              { -1, -1, 0, -1, 3,-1 },
                              {-1, -1, 3, 0, -1, 11 },
                              {-1, -1, -1, -1, 0, 7 },
                              {-1, -1, -1, -1, -1, 0} };

    prev = QVector<int>(n, -1);
    int s = 0, f = 5;
    InputData obj(g, prev , s, f, n);
    this->bfs->Algorithm(obj);
    this->resultworkalgorithmform->show();
}
/**************************************************************************************************/
void MainWindow::on_actionClear_triggered()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        this->arr.clear();
        for(auto&i:this->scene->items()) { delete  i; }
    }
}
/**************************************************************************************************/
void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
  this->timer->setText(tr("Current Time: ") + QTime::currentTime().toString("hh:mm:ss"));
}
/**************************************************************************************************/
int MainWindow::randomBetween(int low, int high)
{
   return (qrand() % ((high + 1) - low) + low);
}
/**************************************************************************************************/
void MainWindow::on_actionAdd_triggered()
{
    TrafficLights* tmp = new TrafficLights(this);
    this->arr.push_back(tmp);
    tmp->setPos(randomBetween(40, 600), randomBetween(30,470));
    scene->addItem(tmp);
}
/**************************************************************************************************/
void MainWindow::on_actionconnect_triggered()
{
    if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
    this->work->show();
    emit this->MaxSizeConnect(this->arr.size());
}
/**************************************************************************************************/
void MainWindow::on_DayMode_clicked()
{
    QPixmap img;
    img.load(":/Data/Recourse/MapDay.jpg");
    this->scene->setSceneRect(0,0,img.width(),img.height());
    this->ui->graphicsView->setBackgroundBrush(img.scaled(img.width(),img.height(),Qt::KeepAspectRatio));
}
/**************************************************************************************************/
void MainWindow::on_NightMode_clicked()
{
  QPixmap img;
  img.load(":/Data/Recourse/MapNight.jpg");
  this->scene->setSceneRect(0,0,img.width(),img.height());
  this->ui->graphicsView->setBackgroundBrush(img.scaled(img.width(),img.height(),Qt::KeepAspectRatio));
}
/**************************************************************************************************/
void MainWindow::on_Start_clicked()
{
    if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
    for(auto i : this->arr)
    {
        i->setTraffic(randomBetween(1,50));
        i->setInterval(randomBetween(1000,1000000));
        i->setMode(true);
    }
}
/**************************************************************************************************/
void MainWindow::on_Stop_clicked()
{
  if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
  for(auto i : this->arr) i->setMode(false);
}
/**************************************************************************************************/
void MainWindow::on_actionHelp_triggered()
{
    this->helpform->show();
}
/**************************************************************************************************/
