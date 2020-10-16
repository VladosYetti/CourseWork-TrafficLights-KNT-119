#include "trafficlights.h"





TrafficLights::TrafficLights(QColor color_1,
                             QColor color_2,
                             QColor color_3,
                             QColor color_4,
                             QObject *parents):QObject(parents),
                             setting(new SettingForm()),
                             color_1(color_1),
                             color_2(color_2),
                             color_3(color_3),
                             color_4(color_4),
                             timer(new QTimer())
{

}

void TrafficLights::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    this->setting->show();
}
