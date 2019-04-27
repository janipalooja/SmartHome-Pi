#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QSerialPort>

class Serial : public QObject
{

    Q_OBJECT
    Q_PROPERTY(float temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(float humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(float CO2 READ CO2 WRITE setCO2 NOTIFY CO2Changed)
    Q_PROPERTY(int lightswitch1_state READ lightswitch1_state WRITE setLightswitch1State NOTIFY lightswitch1StateChanged)
    Q_PROPERTY(int lightswitch2_state READ lightswitch2_state WRITE setLightswitch2State NOTIFY lightswitch2StateChanged)
    Q_PROPERTY(int lightswitch3_state READ lightswitch3_state WRITE setLightswitch3State NOTIFY lightswitch3StateChanged)
    Q_PROPERTY(int lightswitch4_state READ lightswitch4_state WRITE setLightswitch4State NOTIFY lightswitch4StateChanged)
    Q_PROPERTY(int daylight READ daylight WRITE setDaylight NOTIFY daylightChanged)

public:
    explicit Serial(QObject *parent = nullptr);
    float temperature();
    float humidity();
    float CO2();
    int lightswitch1_state();
    int lightswitch2_state();
    int lightswitch3_state();
    int lightswitch4_state();
    int daylight();

public slots:
    void setTemperature(float);
    void setHumidity(float);
    void setCO2(float);
    void setLightswitch1State(int);
    void setLightswitch2State(int);
    void setLightswitch3State(int);
    void setLightswitch4State(int);
    void setDaylight(int);
    void readSerial();
    void writeSerial(const QByteArray &data);

private:
    float m_temperature;
    float m_humidity;
    float m_CO2;
    int m_lightswitch1_state = 0;
    int m_lightswitch2_state = 0;
    int m_lightswitch3_state = 0;
    int m_lightswitch4_state = 0;
    int m_daylight;

signals:
    void temperatureChanged();
    void humidityChanged();
    void CO2Changed();
    void lightswitch1StateChanged();
    void lightswitch2StateChanged();
    void lightswitch3StateChanged();
    void lightswitch4StateChanged();
    void daylightChanged();
};

#endif // SERIAL_H
