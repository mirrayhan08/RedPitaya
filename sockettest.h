//
// Created by Mir Mehedi Hasan on 4/15/2021.
//

#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug7gt;

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = 0);

    void Connect();

    signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif //REDPITAYA_SOCKETTEST_H
