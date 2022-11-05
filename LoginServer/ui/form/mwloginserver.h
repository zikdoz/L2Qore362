#pragma once

namespace Ui
{
class MWLoginServerUI;
}

class MWLoginServer
    : public QMainWindow
{
    Q_OBJECT

public:
    MWLoginServer( QWidget* parent = nullptr );
    ~MWLoginServer();

private:
    Ui::MWLoginServerUI* ui;
};
