#include <sstream>
#include <fstream>
#include "amneziaandroidservice.h"
using namespace AmneziaVPN;


void AmneziaAndroidService::sendToService(const QString &name)
{
    std::string configdata;
    readConfigData("/data/local/tmp/config.ovpn", configdata);
    m_openVpnProtocol.reset(new AmneziaVPN::OpenVPNProtocol(configdata));
    std::string message = m_openVpnProtocol.data()->returnStatus();
    emit messageFromService(QString::fromStdString(message));
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

void AmneziaAndroidService::readConfigData(std::string configPath, std::string& buffer)
{
    std::ifstream lConfigFile;

    lConfigFile.open(configPath);

    if (lConfigFile.is_open() == false) {
        return;
    }

    std::stringstream lFileStream;
    lFileStream << lConfigFile.rdbuf();
    buffer = lFileStream.str();
}
