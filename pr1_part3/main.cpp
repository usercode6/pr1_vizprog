#include <QApplication>
#include <QHash>
#include <QIcon>
#include <QPixmap>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickImageProvider>
#include <QQuickStyle>
#include <QStyle>
#include <QFont>
// Позволяет QML получать стандартные иконки QStyle.
class StandardIconProvider final : public QQuickImageProvider
{
public:
    StandardIconProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(
        const QString& id,
        QSize* size,
        const QSize& requestedSize
        ) override
    {
        static const QHash<QString, QStyle::StandardPixmap> icons{
            {"play",     QStyle::SP_MediaPlay},
            {"pause",    QStyle::SP_MediaPause},
            {"backward", QStyle::SP_MediaSeekBackward},
            {"stop",     QStyle::SP_MediaStop},
            {"forward",  QStyle::SP_MediaSeekForward}
        };

        const auto it = icons.constFind(id);

        if (it == icons.cend())
        {
            if (size)
                *size = QSize();

            return {};
        }

        const QSize iconSize =
            requestedSize.isValid()
                ? requestedSize
                : QSize(18, 18);

        QPixmap pixmap = QApplication::style()
                             ->standardIcon(it.value())
                             .pixmap(iconSize);

        if (size)
            *size = pixmap.size();

        return pixmap;
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Классическое оформление элементов Qt Quick.
    QQuickStyle::setStyle("Fusion");

    QQmlApplicationEngine engine;

    // Передаём в QML шрифт, используемый приложением Widgets.
    engine.rootContext()->setContextProperty(
        "widgetFont",
        QApplication::font()
        );

    engine.addImageProvider(
        "standard",
        new StandardIconProvider
        );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        {
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
        );

    engine.loadFromModule("VideoPlayerQml", "Main");

    return app.exec();
}