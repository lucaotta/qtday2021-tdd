#include "gate.h"

#include <protocol.h>

Gate::Gate(Protocol* protocol, QObject* parent)
    : QObject(parent)
    , m_protocol(protocol)
{
    connect(protocol, &Protocol::percentageReceived, this, &Gate::percentageChanged);
}

void Gate::openGate() { m_protocol->send("openGate"); }

bool Gate::isGateOpen() { return false; }

void Gate::openToPercentage(int percentage)
{
    m_protocol->send("percentage: " + QByteArray::number(percentage));
}
