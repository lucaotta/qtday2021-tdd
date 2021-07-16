#include "protocol.h"

Protocol::Protocol(QObject* parent)
    : QObject(parent)
{
}

// Fake implementation of send().
// We just store the messages for later retrieval and comparison
void Protocol::send(QByteArray message)
{
    m_messages.append(message);
}
