#pragma once
#ifndef ROOT_H
#define ROOT_H
/**************************************************************************************************/
#include <QObject>
#include <QString>
#include <QVector>
#include <QQueue>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QTextStream>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QGraphicsItem>
/**************************************************************************************************/
class Root : public QObject
{
  Q_OBJECT
public:
  explicit Root(QObject *parent = nullptr);
};
/**************************************************************************************************/
#endif // ROOT_H
