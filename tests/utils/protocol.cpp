#include "protocol.h"

#include <QTimer>

Protocol::Protocol(IMockProtocol* mock, QObject* parent)
    : QObject(parent)
    , m_mock(mock)
{
}

// Fake implementation of send().
// We just store the messages for later retrieval and comparison
void Protocol::send(QByteArray message)
{
    m_mock->send(message);
}

MockProtocol::MockProtocol()
{
    m_p = new Protocol(this);
}

void MockProtocol::send(QByteArray message)
{
    m_messages.append(message);
}

Protocol* MockProtocol::p()
{
    return m_p;
}

DelayedProtocol::DelayedProtocol()
{
    m_p = new Protocol(this);
}

void DelayedProtocol::send(QByteArray message)
{
    QTimer::singleShot(500, this, [this, message]() {
        m_messages.append(message);
    });
}

Protocol* DelayedProtocol::p()
{
    return m_p;
}
