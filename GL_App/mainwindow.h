#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>

class QFrame;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    //void closeEvent(QCloseEvent *event);

    //signal-slots not defined yet, but should go here...

private:

    QFrame *mainWidget;

};

#endif // MAINWINDOW_H
