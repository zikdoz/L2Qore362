#include "pch/pch.h"

#include "mwgameserver.h"
#include "ui_mwgameserver.h"

MWGameServer::MWGameServer( QWidget* parent )
    : QMainWindow( parent )
  , ui( new Ui::MWGameServer )
{
    ui->setupUi( this );
}

MWGameServer::~MWGameServer()
{
    delete ui;
}
