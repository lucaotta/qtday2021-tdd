#include "protocol.h"

#include <QDebug>

Protocol::Protocol(QObject* parent)
    : QObject(parent)
{
}

void Protocol::send(QByteArray message)
{
    qDebug() << "Sending" << message;
}
