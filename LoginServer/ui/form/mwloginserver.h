#ifndef MWLOGINSERVER_H
#define MWLOGINSERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MWLoginServer; }
QT_END_NAMESPACE

class MWLoginServer : public QMainWindow
{
    Q_OBJECT

public:
    MWLoginServer(QWidget *parent = nullptr);
    ~MWLoginServer();

private:
    Ui::MWLoginServer *ui;
};
#endif // MWLOGINSERVER_H
