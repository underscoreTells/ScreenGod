#include <QApplication>
#include <QWidget>
#include <QWindow>
#include <QScreen>

class OverlayWindow : public QWidget {
public:
    OverlayWindow() {
        // Remove window decorations
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);

        // Set transparent background
        setAttribute(Qt::WA_TranslucentBackground);

        // Disable focus
        setAttribute(Qt::WA_ShowWithoutActivating);

        // Set full screen over the primary screen
        setGeometry(QApplication::primaryScreen()->geometry());
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    OverlayWindow window;
    window.showFullScreen();

    return app.exec();
}
