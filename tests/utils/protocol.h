#pragma once

#include <QObject>
#include <QVector>

class Protocol;

class IMockProtocol : public QObject {
public:
    virtual void send(QByteArray message) = 0;
    virtual Protocol* p() = 0;
};

class Protocol : public QObject {
    Q_OBJECT
public:
    explicit Protocol(IMockProtocol* m, QObject* parent = nullptr);
    void send(QByteArray message);

signals:
    void percentageReceived(int percentage);

private:
    IMockProtocol* m_mock;
};

class MockProtocol : public IMockProtocol {
public:
    MockProtocol();
    void send(QByteArray message) override;
    Protocol* p() override;

    QVector<QByteArray> m_messages;

private:
    Protocol* m_p;
};

class DelayedProtocol : public IMockProtocol {
public:
    DelayedProtocol();

    void send(QByteArray message) override;
    Protocol* p() override;

    QVector<QByteArray> m_messages;

private:
    Protocol* m_p;
};
