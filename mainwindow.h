#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**************************************************************************************************/
#include <QMainWindow>
#include <QMessageBox>
#include <dijkstraalgorithmgraph.h>
#include <fordfulkersonalgorithmgraph.h>
#include <bfsalgorithmgraph.h>
#include "resultworkalgorithmform.h"
#include "aboutform.h"
#include <QDesktopServices>
#include <QUrl>
#include <QGraphicsScene>
#include "TransferGraph.h"
#include <QLabel>
#include <QTime>
#include "trafficlights.h"
#include "working.h"
/**************************************************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**************************************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionAbout_triggered();
    void on_actionBest_Route_Planner_triggered();
    void on_actionEXIT_triggered();
    void on_actionQt_triggered();
    void on_actionGitHub_triggered();
    void on_actionTraffic_ongestion_triggered();
    void on_actionConnection_heck_triggered();
    void on_actionClear_triggered();
    void on_actionAdd_triggered();
    void on_actionconnect_triggered();
    void on_DayMode_clicked();
    void on_NightMode_clicked();
private:
    Ui::MainWindow *ui;
    DijkstraAlgorithmGraph* dijkstra;
    FordFulkersonAlgorithmGraph* fordfulkerson;
    BFSAlgorithmGraph* bfs;
    ResultWorkAlgorithmForm* resultworkalgorithmform;
    AboutForm* aboutform;
    QVector<QVector<int>>g;
    QVector<int>prev;
    QVector<TrafficLights*>arr;
    QGraphicsScene*scene;
    QLabel* timer;
    working* work;
protected:
    virtual void timerEvent(QTimerEvent* event) override;
    static int randomBetween(int low, int high);
};
/**************************************************************************************************/
#endif // MAINWINDOW_H
