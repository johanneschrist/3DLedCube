#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public: //define the main variables to be used on the GL widget

    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
    int x_resolution;
    int y_resolution;
    int z_resolution;
    double spacingvalue;
    GLdouble redcolor;
    GLdouble greencolor;
    GLdouble bluecolor;
    double ledSize;
    int ix,iy,iz; //counters for coordinates;
    int xCoordinate, yCoordinate, zCoordinate;
    int radiousball, animateZrot; //variables for animation
    std::string filename;
    bool direction;
    QTimer *timer;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setZoom(int zoom);
    void setResolution_x(int x);
    void setResolution_y(int y);
    void setResolution_z(int z);
    void setResolution_spacing(int spacing);
    void changeColorRed(bool colorchoice);
    void changeColorGreen(bool colorchoice);
    void changeColorYellow(bool colorchoice);
    void changeColorWhite(bool colorchoice);
    void changeSize(int size);
    void animate(bool yesno);
    void changeAmplitude();
    void openFile(bool);
    void stopAnimation(bool);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void zoomChanged(int zoom);
    void resolutionChanged_x(int x);
    void resolutionChanged_y(int y);
    void resolutionChanged_z(int z);
    void resolutionChanged_spacing(int spacing);


private:
    void drawPoint(int x, int y, int z);
    void drawCube();
    void drawFromFile();
    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
};

#endif // MYGLWIDGET_H
