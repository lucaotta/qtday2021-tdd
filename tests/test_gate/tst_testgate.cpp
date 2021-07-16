#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include <gate.h>
#include <protocol.h>

class TestGate : public QObject {
    Q_OBJECT

private slots:
    void test_case1();
};

void TestGate::test_case1()
{
    Protocol p;
    Gate g(&p);

    g.openGate();

    QCOMPARE(p.m_messages.size(), 1);
    QCOMPARE(p.m_messages.at(0), "openGate");
}

QTEST_MAIN(TestGate)

#include "tst_testgate.moc"
