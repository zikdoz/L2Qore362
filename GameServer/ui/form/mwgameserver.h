#ifndef MWGAMESERVER_H
#define MWGAMESERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MWGameServer; }
QT_END_NAMESPACE

class MWGameServer : public QMainWindow
{
    Q_OBJECT

public:
    MWGameServer(QWidget *parent = nullptr);
    ~MWGameServer();

private:
    Ui::MWGameServer *ui;
};
#endif // MWGAMESERVER_H
