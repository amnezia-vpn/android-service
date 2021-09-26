#include "amneziaandroidservice.h"
#include <amnezia_ovpn.h>


void AmneziaAndroidService::sendToService(const QString &name) {
    AmneziaVPN::OpenVPNProtocol protocol1;

    emit messageFromService("Hello " + name);
    qDebug() << "Something";
};


bool AmneziaAndroidService::isConnected()
{
    return false;
}

bool AmneziaAndroidService::isDisconnected()
{
   return false;
}

int AmneziaAndroidService::start()
{
   return 1;
}

void AmneziaAndroidService::stop()
{

}
