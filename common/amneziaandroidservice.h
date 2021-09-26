#include "rep_amneziaandroidservice_source.h"
#include <amnezia_ovpn.h>
#include <QThread>

class AmneziaAndroidService : public AmneziaAndroidServiceSource
{
public slots:
    void sendToService(const QString &name) override;

    bool isConnected() override;
    bool isDisconnected() override;
    int start() override;
    void stop() override;



};
