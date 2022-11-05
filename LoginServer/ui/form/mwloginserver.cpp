#include "pch/pch.h"

#include "mwloginserver.h"
#include "ui_mwloginserver.h"

MWLoginServer::MWLoginServer( QWidget* parent )
    : QMainWindow( parent )
  , ui( new Ui::MWLoginServer )
{
    ui->setupUi( this );
}

MWLoginServer::~MWLoginServer()
{
    delete ui;
}
