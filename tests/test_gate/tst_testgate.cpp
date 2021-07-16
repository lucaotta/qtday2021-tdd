#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include <gate.h>
#include <protocol.h>

class TestGate : public QObject {
    Q_OBJECT

private slots:
    void test_normal();
    void test_delayed();
};

void TestGate::test_normal()
{
    MockProtocol m;
    Gate g(m.p());

    g.openGate();

    QCOMPARE(m.m_messages.size(), 1);
    QCOMPARE(m.m_messages.at(0), "openGate");
}

void TestGate::test_delayed()
{
    DelayedProtocol m;
    Gate g(m.p());

    g.openGate();

    QCOMPARE(m.m_messages.size(), 0);
}

QTEST_MAIN(TestGate)

#include "tst_testgate.moc"
