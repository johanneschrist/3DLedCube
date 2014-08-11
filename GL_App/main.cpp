#include <QApplication>
#include "myqlwidget.h"
#include "qgl_mainwidget.h"
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
QGL_MainWidget mainWin;
mainWin.setFixedSize(875, 425);
mainWin.show();
return app.exec();
}
