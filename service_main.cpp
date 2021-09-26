#include "amneziaandroidservice.h"

#include <QDebug>
#include <QAndroidService>

int main(int argc, char *argv[])
{
    qWarning() << "AmneziaAndroidService starting from separate .so";
    QAndroidService app(argc, argv);

    QRemoteObjectHost srcNode(QUrl(QStringLiteral("local:replica")));
    AmneziaAndroidService amneziaAndroidService;
    srcNode.enableRemoting(&amneziaAndroidService);

    return app.exec();
}
