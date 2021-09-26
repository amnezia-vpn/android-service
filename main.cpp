#include "rep_amneziaandroidservice_replica.h"

#include <QAndroidIntent>
#include <QtAndroid>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

void startService()
{
    QAndroidIntent serviceIntent(QtAndroid::androidActivity().object(),
                                        "org/amnezia/amneziavpn/AmneziaAndroidService");
    QAndroidJniObject result = QtAndroid::androidActivity().callObjectMethod(
        "startService",
        "(Landroid/content/Intent;)Landroid/content/ComponentName;",
        serviceIntent.handle().object());
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

   startService();

    QRemoteObjectNode repNode;
    repNode.connectToNode(QUrl(QStringLiteral("local:replica")));
    QSharedPointer<AmneziaAndroidServiceReplica> rep(repNode.acquire<AmneziaAndroidServiceReplica>());
    engine.rootContext()->setContextProperty("amneziaService", rep.data());
    bool res = rep->waitForSource();
    Q_ASSERT(res);
//    rep->sendToService("Qt");

    QObject::connect(rep.data(), &AmneziaAndroidServiceReplica::messageFromService, [](const QString &message){
        qDebug() << "Service sent: " << message;
    });
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
