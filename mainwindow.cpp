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
    , status(false)
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
       Road* line = new Road(this);
       line->setLeft(arr[a - 1]);
       line->setRight(arr[b - 1]);

       if(line->getLeft()->getMode() and line->getRight()->getMode())
       {
           this->g[a - 1][b - 1] = (this->arr[a - 1]->getInterval() / 1000) + (this->arr[b - 1]->getInterval() / 1000);
           this->g[b - 1][a - 1] = (this->arr[a - 1]->getInterval() / 1000) + (this->arr[b - 1]->getInterval() / 1000);
       }
       else
       {
           this->g[a - 1][b - 1] = -1;
           this->g[b - 1][a - 1] = -1;
       }
       this->g2[a - 1][b - 1] = this->arr[a - 1]->getTraffic() + this->arr[b - 1]->getTraffic();
       this->g2[b - 1][a - 1] = this->arr[a - 1]->getTraffic() + this->arr[b - 1]->getTraffic();
       this->arr_road.push_back(line);
       this->scene->addLine(line->getLine());
    });
    QObject::connect(this, &MainWindow::MaxSizeAlgorithm, this->work, &working::setMaxSizeAlgorithm);
    /**************************************************************************************************/
    QObject::connect(this->work, &working::getAlgorithm, [this](int a, int b, QString str)
    {
        if(!this->status) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("ERROR")); return; }
        int start = a - 1;
        int finish = b - 1;
        this->prev = QVector<int>(arr.size(), -1);
        int n = this->arr.size();
        /**************************************************************************************************/
        if(str == "BFS")
        {
            InputData obj(this->g, this->prev , start, finish, n);
            this->bfs->Algorithm(obj);
            this->resultworkalgorithmform->show();
        }
        else if(str == "DIJKSTRA")
        {
           InputData obj(this->g, this->prev , start, finish, n);
           this->dijkstra->Algorithm(obj);
           this->resultworkalgorithmform->show();
        }
        else if(str == "FORD-FULKERSON")
        {
            InputData obj(this->g2, this->prev , start, finish, n);
            this->fordfulkerson->Algorithm(obj);
            this->resultworkalgorithmform->show();
        }
        /**************************************************************************************************/
    });
    QObject::connect(this, &MainWindow::changeMatrix,this, &MainWindow::change);
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
    for(auto&i:this->arr_road) {delete i;}
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
  emit MaxSizeAlgorithm(this->arr.size(), "DIJKSTRA");
  this->work->show();
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
   emit MaxSizeAlgorithm(this->arr.size(), "FORD-FULKERSON");
   this->work->show();
}
/**************************************************************************************************/
void MainWindow::on_actionConnection_heck_triggered()
{
  if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
  emit MaxSizeAlgorithm(this->arr.size(), "BFS");
  this->work->show();
}
/**************************************************************************************************/
void MainWindow::on_actionClear_triggered()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        this->arr.clear();
        for(auto&i:this->scene->items()) { delete  i; }
        for(auto&i:this->arr_road) {delete i;}
        this->status = false;
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
    QObject::connect(tmp, &TrafficLights::change, this, &MainWindow::changeMatrix);
    scene->addItem(tmp);
}
/**************************************************************************************************/
void MainWindow::on_actionconnect_triggered()
{
    if(this->arr.size() == 0) { QMessageBox::information(this, tr("TrafficLightsApp"), tr("Empty")); return; }
    this->work->show();
    emit this->MaxSizeConnect(this->arr.size());
    if(!status)
    {
        this->g = QVector<QVector<int>>(this->arr.size(), QVector<int>(this->arr.size(), 0));
        this->g2 = QVector<QVector<int>>(this->arr.size(), QVector<int>(this->arr.size(), 0));
        this->status = true;
    }
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
    emit changeMatrix();
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
void MainWindow::change()
{
  for(int i = 0; i < this->arr.size(); ++i)
  {
     for(int j = 0; j < this->arr.size(); ++j)
     {
         if(this->g[i][j] != 0)
         {
             if(this->arr[i]->getMode() and arr[j]->getMode())
             {
                 this->g[i][j] = (this->arr[i]->getInterval() / 1000) + (this->arr[j]->getInterval() / 1000);
                 this->g[j][i] = (this->arr[i]->getInterval() / 1000) + (this->arr[j]->getInterval() / 1000);
             }
             else
             {
                 this->g[i][j] = -1;
                 this->g[j][i] = -1;
             }
         }
         if(this->g2[i][j] != 0)
         {
             this->g2[i][j] = (this->arr[i]->getTraffic() + this->arr[j]->getTraffic());
             this->g2[j][i] = (this->arr[i]->getTraffic() + this->arr[j]->getTraffic());
         }
     }
  }
}
/**************************************************************************************************/
