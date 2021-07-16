#pragma once

#include <QObject>
#include <QVector>

class Protocol : public QObject {
  Q_OBJECT
public:
  explicit Protocol(QObject *parent = nullptr);
  void send(QByteArray message);

  QVector<QByteArray> m_messages;

signals:
  void percentageReceived(int percentage);
};
