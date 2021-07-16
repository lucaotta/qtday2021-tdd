#pragma once

#include <QObject>

class Protocol;

class Gate : public QObject {
    Q_OBJECT
public:
    explicit Gate(Protocol* protocol, QObject* parent = nullptr);
    void openGate();
    bool isGateOpen();
    void openToPercentage(int percentage);

signals:
    void percentageChanged(int percentage);

private:
    Protocol* m_protocol { nullptr };
};
