#include "trafficlights.h"
/**************************************************************************************************/
int TrafficLights::global_index = 1;
bool TrafficLights::connect = false;
/**************************************************************************************************/
TrafficLights::TrafficLights(
                             QObject *parents,
                             QColor color_1,
                             QColor color_2,
                             QColor color_3,
                             QColor color_4
                             ):QObject(parents),
                             setting(new SettingForm()),
                             color_1(color_1),
                             color_2(color_2),
                             color_3(color_3),
                             color_4(color_4),
                             timer(new QTimer())
{
  this->index = this->global_index;
  ++this->global_index;
}
/**************************************************************************************************/
QColor TrafficLights::getColor_1() const
{
  return this->color_1;
}
/**************************************************************************************************/
QColor TrafficLights::getColor_2() const
{
  return this->color_2;
}
/**************************************************************************************************/
QColor TrafficLights::getColor_3() const
{
  return this->color_3;
}
/**************************************************************************************************/
QColor TrafficLights::getCurrColor() const
{
  return this->curr_color;
}
/**************************************************************************************************/
void TrafficLights::setColor_1(const QColor other)
{
  this->color_1 = other;
}
/**************************************************************************************************/
void TrafficLights::setColor_2(const QColor other)
{
  this->color_2 = other;
}
/**************************************************************************************************/
void TrafficLights::setColor_3(const QColor other)
{
  this->color_3 = other;
}
/**************************************************************************************************/
bool TrafficLights::getMode() const
{
  return this->isOn;
}
/**************************************************************************************************/
void TrafficLights::setMode(const bool other)
{
  this->isOn = other;
}
/**************************************************************************************************/
int TrafficLights::getInterval() const
{
  return this->interval;
}
/**************************************************************************************************/
int TrafficLights::getIndex() const
{
  return this->index;
}
/**************************************************************************************************/
void TrafficLights::setConnect(const bool other)
{
  this->connect = other;
}
/**************************************************************************************************/
void TrafficLights::Update()
{
  this->update();
}
/**************************************************************************************************/
TrafficLights::~TrafficLights()
{
  delete this->timer;
  delete this->transfer;
  --this->global_index;
  this->connect = false;
}
/**************************************************************************************************/
void TrafficLights::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
  Q_UNUSED(event);
  this->setting->setWindowTitle(tr("TrafficLightsApp Node"));
  this->setting->show();
}
/**************************************************************************************************/
void TrafficLights::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);
  this->doDrawing(painter, this->curr_color);
}
/**************************************************************************************************/
void TrafficLights::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  this->setPos(mapToScene(event->pos()));
}
/**************************************************************************************************/
void TrafficLights::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  Q_UNUSED(event);
  this->setCursor(QCursor(Qt::ClosedHandCursor));
}
/**************************************************************************************************/
void TrafficLights::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  Q_UNUSED(event);
  this->setCursor(QCursor(Qt::ArrowCursor));
}
/**************************************************************************************************/
QRectF TrafficLights::boundingRect() const
{
  return QRectF (-30,-30,60,60);
}
/**************************************************************************************************/
void TrafficLights::doDrawing(QPainter *painter, QColor other)
{
  painter->setPen(Qt::black);
  painter->setBrush(other);
  painter->drawEllipse(-10, -10, 20, 20);
  painter->drawText(-10, 20, QString::number(this->index));
}
/**************************************************************************************************/
