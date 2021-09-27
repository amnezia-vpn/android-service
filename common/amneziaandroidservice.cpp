#include "amneziaandroidservice.h"
using namespace AmneziaVPN;


void AmneziaAndroidService::sendToService(const QString &name) {
//    emit messageFromService("Hello " + name);
    AmneziaVPN::OpenVPNProtocol m_openVpnProtocol;
    std::string message = m_openVpnProtocol.returnStatus();
    emit messageFromService("Hello " + QString::fromStdString(message));
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

}

void AmneziaAndroidService::stop()
{

}
