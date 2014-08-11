#include "myqlwidget.h"
#include "math.h"
#include <QtOpenGL>
#include <QWidget>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //set some difaults for the application
    xRot = 64*16;
    yRot = 6;
    zRot = 31*16;
    x_resolution = 80;
    y_resolution = 80;
    z_resolution = 80;
    spacingvalue = 1;
    redcolor = 1.0;
    greencolor = 1.0;
    bluecolor = 1.0;
    ix=0;
    iy=0;
    iz=0;
    radiousball = 4;
    filename=" ";
    direction = true; //this variable sets the direction of the animation to start from...
    timer = new QTimer(this);
}

MyGLWidget::~MyGLWidget()
{
   //use default destructor
}

QSize MyGLWidget::minimumSizeHint() const //define the size of the widget
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle) //normalize angle as it comes from the mouse / widget
{
    while (angle < 0)
        angle += 360;
    while (angle > 360)
        angle -= 360;
}

void MyGLWidget::setXRotation(int angle) //set angle of rotation
{
    angle = angle * 16;
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    angle = angle * 16;
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    angle = angle * 16;
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setResolution_x(int x){ //set amount of leds per x, y and z
    x_resolution = x;
    updateGL();
    emit resolutionChanged_x(x);
}

void MyGLWidget::setResolution_y(int y){
    y_resolution = y;
    updateGL();
    emit resolutionChanged_y(y);
}

void MyGLWidget::setResolution_z(int z){
    z_resolution = z;
    updateGL();
    emit resolutionChanged_z(z);
}

void MyGLWidget::setResolution_spacing(int spacing){ //set the spacing
    double myspacing = spacing / 1.50;
    spacingvalue = myspacing;
    updateGL();
    emit resolutionChanged_spacing(spacing);
}

void MyGLWidget::changeColorRed(bool colorchoice) //define each of the colors to accept signals from the widget
{
    if (colorchoice==true){
        redcolor = 1.0;
        greencolor = 0.0;
        bluecolor = 0.0;
        updateGL();
    }
}

void MyGLWidget::changeColorGreen(bool colorchoice)
{
    if (colorchoice==true){
        redcolor = 0.0;
        greencolor = 1.0;
        bluecolor = 0.0;
        updateGL();
    }
}

void MyGLWidget::changeColorYellow(bool colorchoice)
{
    if (colorchoice==true){
        redcolor = 1.0;
        greencolor = 1.0;
        bluecolor = 0.0;
        updateGL();
    }
}

void MyGLWidget::changeColorWhite(bool colorchoice)
{
    if (colorchoice==true){
        redcolor = 1.0;
        greencolor = 1.0;
        bluecolor = 1.0;
        updateGL();
    }
}

void MyGLWidget::changeSize(int size){ //change led sizes...
    ledSize = size;
    updateGL();
}
void MyGLWidget::setZoom(int zoom){
    float myzoom = zoom / 100.00;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(myzoom, myzoom, myzoom);
    glOrtho(  (-(x_resolution+spacingvalue)/2), ( (x_resolution+spacingvalue)/2), (-(y_resolution+spacingvalue)/2), ((y_resolution+spacingvalue)/2), -10.0, z_resolution/2);
    glMatrixMode(GL_MODELVIEW);
    emit zoomChanged(zoom);
    updateGL();
}

void MyGLWidget::animate(bool yesno){ //animate the function

    connect(timer, SIGNAL(timeout()), this, SLOT(changeAmplitude()));
    timer->start(10);
}

void MyGLWidget::stopAnimation(bool){

    timer->stop(); //stop the timer...

}

void MyGLWidget::changeAmplitude(){ //change the amplitude/radious of the ball object
    if (direction) radiousball++;
    else radiousball--;
    if (radiousball == 50) direction = !direction;
    if (radiousball == 0) direction = !direction;

    if (filename != " "){
         animateZrot+=5; ///animation for the face...
    }
    updateGL();
}


void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    if (filename == " ") drawCube();
    if (filename != " ") drawFromFile();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(0.5, 0.5, 0.5);
    glOrtho(  (-(x_resolution+spacingvalue)/2), ( (x_resolution+spacingvalue)/2), (-(y_resolution+spacingvalue)/2), ((y_resolution+spacingvalue)/2), 0.0, 15.0*z_resolution*2);
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event) //define mouse interaction
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton) {
        setXRotation((xRot + 8 * dy)/16);
        setYRotation((yRot + 8 * dx)/16);
    } else if (event->buttons() & Qt::RightButton) {
        setZRotation((zRot + 8 * dx)/16);
    }
    lastPos = event->pos();
}

void MyGLWidget::openFile(bool){

        timer->stop(); //stop the timer from previous rendering

        QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."), QString(), tr(".xyz files (*.xyz);;All Files (*)"));
        filename = fn.toUtf8().constData(); //convert Qstring into std::string...
        animateZrot = 35;
        setXRotation(-102); //set the correct values to show the face nicely...
        setYRotation(10);
        setZRotation(35);
        setZoom(33);
}

void MyGLWidget::drawPoint(int x, int y, int z){ //draw a point given a coordinate

    glPointSize(ledSize);
    glBegin(GL_POINTS);
    glColor4f(redcolor, greencolor, bluecolor, 0.75 );
    glVertex3f(x, y, z);
    glEnd();


}

void MyGLWidget::drawCube() //draw a cube led with a sphere on it
{

    for (ix = -x_resolution/2; ix <= (x_resolution-1)/2 ; ix++){

          for ( iy = -y_resolution/2; iy <= (y_resolution-1)/2 ; iy++){

                for ( iz = -z_resolution/2; iz <= (z_resolution-1)/2 ; iz++){

                    if (radiousball  == round(sqrt (((ix*ix) + (iy*iy) + (iz*iz))))) //function to draw a sphere...
                    {
                        drawPoint(ix*spacingvalue, iy*spacingvalue, iz*spacingvalue);
                    }
                    else //this will draw off points
                    {
                        glPointSize(0.01f);
                        glBegin(GL_POINTS);
                        glColor4f(1, 1, 1, 0.03 );
                        glVertex3f(ix, iy, iz);
                        glEnd();
                    }
    }
        }
            }

}

void MyGLWidget::drawFromFile(){ //draw using a xyz input file


        string STRING;
        ifstream infile;
        infile.open (filename.c_str());
        getline(infile,STRING);
        int x,y,z;

        while(infile.peek() != -1){ // To get all the lines.

            int spacekey1 = 0;
            int spacekey2 = 0;
            string xc = "";
            string yc = "";
            string zc = "";

                getline(infile,STRING);

                for (int i = 0; i < STRING.length(); i++){

                    if (STRING[i] != ' '){

                    if (spacekey1 == 0){
                        xc = xc + STRING[i];

                    }

                    if (spacekey1 > spacekey2){
                        yc = yc + STRING[i];

                    }

                    if (spacekey1 < spacekey2){
                        zc = zc + STRING[i];

                    }
                    }

                    else {
                        if (spacekey1 == 0) spacekey1 = i;
                        else spacekey2 = i;}

                    }

                x = round(atoi(xc.c_str()));
                y = round(atoi(yc.c_str()));
                z = round(atoi(zc.c_str()));

                drawPoint(x*spacingvalue, y*spacingvalue, z*spacingvalue);

                if (timer->isActive()) setZRotation(animateZrot);
            }

        infile.close();
}



