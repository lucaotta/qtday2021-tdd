#pragma once

#include <QByteArray>
#include <QObject>

class Protocol : public QObject {
  Q_OBJECT
public:
  explicit Protocol(QObject *parent = nullptr);
  void send(QByteArray message);

signals:
  void percentageReceived(int percentage);
};
