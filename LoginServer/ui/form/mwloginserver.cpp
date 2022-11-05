#include "pch/pch.h"

#include "ui/form/mwloginserver.h"
#include "ui_mwloginserver.h"

MWLoginServer::MWLoginServer( QWidget* parent )
    : QMainWindow( parent )
  , ui( new Ui::MWLoginServerUI )
{
    ui->setupUi( this );
}

MWLoginServer::~MWLoginServer()
{
    delete ui;
}
