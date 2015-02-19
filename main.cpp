#ifdef DEBUG
#include <QDebug>
#endif

#include <QApplication>
#include "Dialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

#if defined (Q_OS_UNIX)
    app.setWindowIcon(QIcon(":/Resources/PressureView.png"));
#endif
    Dialog *dialog = new Dialog();
    dialog->setWindowTitle(QString::fromUtf8("License File Generator"));
    dialog->show();

    return app.exec();
}

