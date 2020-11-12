#pragma once
#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H
/**************************************************************************************************/
#include <QGraphicsItem>
#include <QObject>
#include <QColor>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "settingform.h"
#include "Transfer.h"
#include <QString>
/**************************************************************************************************/
class TrafficLights  : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit TrafficLights(QObject*parents=nullptr,
                           QColor color_1 =Qt::red ,
                           QColor color_2 =Qt::yellow ,
                           QColor color_3 =Qt::green ,
                           QColor color_4 =Qt::black);
    QColor getColor_1(void) const;
    QColor getColor_2(void) const;
    QColor getColor_3(void) const;
    QColor getCurrColor(void) const;
    void setColor_1(const QColor);
    void setColor_2(const QColor);
    void setColor_3(const QColor);
    void setCurrColor(const QColor);
    bool getMode(void) const;
    void setMode(const bool);
    int getInterval(void) const;
    void setInterval(const int);
    int getIndex(void) const;
    void setConnect(const bool);
    void setTraffic(const int);
    int getTraffic(void) const;
    void setResAlgorithm(void);
    void Update(void);
    ~TrafficLights();
    public slots:
    void input(Transfer other);
private:
    SettingForm *setting;
    Transfer *transfer;
    QColor color_1;
    QColor color_2;
    QColor color_3;
    QColor color_4;
    QColor curr_color;
    QTimer* timer;
    bool isOn;
    int index;
    int interval;
    int traffic;
    static int global_index;
    static bool connect;
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*event) override;
    virtual void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget=nullptr) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent*event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*event) override;
    virtual QRectF boundingRect() const override;
    void doDrawing(QPainter *painter, QColor other);
    const QColor color_Algorithm = Qt::darkCyan;
 signals:
    void updateData(Transfer other);
};
/**************************************************************************************************/
#endif // TRAFFICLIGHTS_H
