TEMPLATE = subdirs

SUBDIRS += \
          Commom  \
          LoginServer  \
          GameServer

# locations

Commom.subdir = $$PWD/Common
LoginServer.subdir = $$PWD/LoginServer
GameServer.subdir = $$PWD/GameServer

LoginServer.depends = Commom
GameServer.depense = Common
