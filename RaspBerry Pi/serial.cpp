#include "serial.h"

QSerialPort *serialPort = new QSerialPort();

Serial::Serial(QObject *parent) :
    QObject(parent)
{
    serialPort->setPortName("ttyACM0");
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->open(QIODevice::ReadWrite);

    connect(serialPort,SIGNAL(readyRead()),this,SLOT(readSerial()));
}

float Serial::temperature()
{
    return m_temperature;
}

float Serial::humidity()
{
    return m_humidity;
}

float Serial::CO2()
{
    return m_CO2;
}

int Serial::lightswitch1_state(){
    return m_lightswitch1_state;
}

int Serial::lightswitch2_state(){
    return m_lightswitch2_state;
}

int Serial::lightswitch3_state(){
    return m_lightswitch3_state;
}

int Serial::lightswitch4_state(){
    return m_lightswitch4_state;
}

int Serial::daylight(){
    return m_daylight;
}

void Serial::setTemperature(float temp){

    if ((temp < m_temperature) || (temp > m_temperature)) {
        m_temperature = temp;
        emit temperatureChanged();
    }
    else {
        return;
    }

}

void Serial::setHumidity(float humidity){

    if ((humidity < m_humidity) || (humidity > m_humidity)) {
        m_humidity = humidity;
        emit humidityChanged();
    }
    else {
        return;
    }

}

void Serial::setCO2(float co2){

    if ((co2 < m_CO2) || (co2 > m_CO2)) {
        m_CO2 = co2;
        emit CO2Changed();
    }
    else {
        return;
    }

}

void Serial::setLightswitch1State(int state){
    if(state != m_lightswitch1_state) {
        m_lightswitch1_state = state;
        emit lightswitch1StateChanged();
    }
    else {
        return;
    }
}

void Serial::setLightswitch2State(int state){
    if(state != m_lightswitch2_state) {
        m_lightswitch2_state = state;
        emit lightswitch2StateChanged();
    }
    else {
        return;
    }
}

void Serial::setLightswitch3State(int state){
    if(state != m_lightswitch3_state) {
        m_lightswitch3_state = state;
        emit lightswitch3StateChanged();
    }
    else {
        return;
    }
}

void Serial::setLightswitch4State(int state){
    if(state != m_lightswitch4_state) {
        m_lightswitch4_state = state;
        emit lightswitch4StateChanged();
    }
    else {
        return;
    }
}

void Serial::setDaylight(int light){
    if(light != m_daylight) {
        m_daylight = light;
        emit daylightChanged();
    }
    else {
        return;
    }
}

void Serial::readSerial(){

    QByteArray responseData = serialPort->readAll();
    while (serialPort->waitForReadyRead(10))
    responseData += serialPort->readAll();

    const QString response = QString::fromUtf8(responseData);
    qDebug() << response;
    QRegExp rx("[;]");
    QStringList list = response.split(rx, QString::SkipEmptyParts);



    QList <float> data;
    QList <int> lightSwitchData;
    for(int i = 0; i < list.size(); i++)
    {
        if(list.at(0) == "1") {
            lightSwitchData.append(list.at(i).toInt());
            if(lightSwitchData.at(1) == 1) {
                setLightswitch1State(lightSwitchData.at(2));
            }
            if(lightSwitchData.at(1) == 2) {
                setLightswitch2State(lightSwitchData.at(2));
            }
            if(lightSwitchData.at(1) == 3) {
                setLightswitch3State(lightSwitchData.at(2));
            }
            if(lightSwitchData.at(1) == 4) {
                setLightswitch4State(lightSwitchData.at(2));
            }
        }
        else if(list.at(0) == "2") {
            data.append(list.at(i).toFloat());
            setTemperature(data.at(1));
            setHumidity(data.at(2));
            setCO2(data.at(3));
            setDaylight(static_cast<int>(data.at(4)));
        }
    }
}

void Serial::writeSerial(const QByteArray &data) {
    serialPort->write(data);
}
