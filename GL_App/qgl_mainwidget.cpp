#include <QtGui>
#include "qgl_mainwidget.h"
#include "myqlwidget.h"

QGL_MainWidget::QGL_MainWidget(QWidget *parent) : QFrame(parent)

{
    /////gl widget////
    GlFrame = new MyGLWidget();
    GlFrame->setFixedHeight(400);

    ///resolution elements///
    Resolution = new QGroupBox("Resolution", this);
    x_label_resolution = new QLabel("x");
    x_spin_resolution = new QSpinBox();
    y_label_resolution = new QLabel("y");
    y_spin_resolution = new QSpinBox();
    z_label_resolution = new QLabel("z");
    z_spin_resolution = new QSpinBox();
    spacing_label = new QLabel("Space");
    spacing_spin = new QSpinBox();
    spacing_label->setBuddy(spacing_spin);
    inches = new QLabel("inches");

    x_spin_resolution->setRange(1,500);
    y_spin_resolution->setRange(1,500);
    z_spin_resolution->setRange(1,500);
    z_spin_resolution->setValue(80);
    x_spin_resolution->setValue(80);
    y_spin_resolution->setValue(80);
    spacing_spin->setValue(1);

   /////set signals and slots//////
    QObject::connect(x_spin_resolution, SIGNAL(valueChanged(int)), GlFrame, SLOT(setResolution_x(int)));
    QObject::connect(y_spin_resolution, SIGNAL(valueChanged(int)), GlFrame, SLOT(setResolution_y(int)));
    QObject::connect(z_spin_resolution, SIGNAL(valueChanged(int)), GlFrame, SLOT(setResolution_z(int)));
    QObject::connect(spacing_spin, SIGNAL(valueChanged(int)), GlFrame, SLOT(setResolution_spacing(int)));


    ///led elements///
    Led_color = new QGroupBox("Led Color", this);
    red = new QRadioButton("Red");
    green = new QRadioButton("Green");
    yellow = new QRadioButton("Yellow");
    white = new QRadioButton("White");

    QObject::connect(red, SIGNAL(toggled(bool)),
    GlFrame, SLOT(changeColorRed(bool)));
    QObject::connect(green, SIGNAL(toggled(bool)),
    GlFrame, SLOT(changeColorGreen(bool)));
    QObject::connect(yellow, SIGNAL(toggled(bool)),
    GlFrame, SLOT(changeColorYellow(bool)));
    QObject::connect(white, SIGNAL(toggled(bool)),
    GlFrame, SLOT(changeColorWhite(bool)));

    ///transformation elements///
    Transforms = new QGroupBox("Transformation", this);
    x_label_rotation = new QLabel("x");
    x_slider_rotation = new QSlider(Qt::Horizontal);
    x_spin_rotation = new QSpinBox();
    x_spin_rotation->setRange(-180, 180);
    x_slider_rotation->setRange(-180, 180);
    x_spin_rotation->setValue(0);

    y_label_rotation = new QLabel("y");
    y_slider_rotation = new QSlider(Qt::Horizontal);
    y_spin_rotation = new QSpinBox();
    y_spin_rotation->setRange(-180, 180);
    y_slider_rotation->setRange(-180, 180);
    y_spin_rotation->setValue(0);

    z_label_rotation = new QLabel("z");
    z_slider_rotation = new QSlider(Qt::Horizontal);
    z_spin_rotation = new QSpinBox();
    z_spin_rotation->setRange(-180, 180);
    z_slider_rotation->setRange(-180, 180);
    z_spin_rotation->setValue(0);

    zoom_label_rotation = new QLabel("Zoom");
    zoom_slider_rotation = new QSlider(Qt::Horizontal);
    zoom_spin_rotation = new QSpinBox();
    zoom_spin_rotation->setRange(0, 300);
    zoom_slider_rotation->setRange(0, 300);
    zoom_slider_rotation->setValue(50);
    zoom_spin_rotation->setValue(50);

    QObject::connect(zoom_spin_rotation, SIGNAL(valueChanged(int)), zoom_slider_rotation, SLOT(setValue(int)));
    QObject::connect(zoom_slider_rotation, SIGNAL(valueChanged(int)), zoom_spin_rotation, SLOT(setValue(int)));
    QObject::connect(zoom_spin_rotation, SIGNAL(valueChanged(int)), GlFrame, SLOT(setZoom(int)));
    QObject::connect(GlFrame, SIGNAL(zoomChanged(int)), zoom_slider_rotation, SLOT(setValue(int)));
    QObject::connect(z_spin_rotation, SIGNAL(valueChanged(int)), z_slider_rotation, SLOT(setValue(int)));
    QObject::connect(z_slider_rotation, SIGNAL(valueChanged(int)), z_spin_rotation, SLOT(setValue(int)));
    QObject::connect(z_spin_rotation, SIGNAL(valueChanged(int)), GlFrame, SLOT(setZRotation(int)));
    QObject::connect(y_spin_rotation, SIGNAL(valueChanged(int)),    y_slider_rotation, SLOT(setValue(int)));
    QObject::connect(y_slider_rotation, SIGNAL(valueChanged(int)),    y_spin_rotation, SLOT(setValue(int)));
    QObject::connect(y_spin_rotation, SIGNAL(valueChanged(int)), GlFrame, SLOT(setYRotation(int)));
    QObject::connect(x_spin_rotation, SIGNAL(valueChanged(int)), x_slider_rotation, SLOT(setValue(int)));
    QObject::connect(x_slider_rotation, SIGNAL(valueChanged(int)), x_spin_rotation, SLOT(setValue(int)));
    QObject::connect(x_spin_rotation, SIGNAL(valueChanged(int)), GlFrame, SLOT(setXRotation(int)));

    ///led sizes///

    size_label = new QLabel("Size Leds");
    size_slider = new QSlider(Qt::Horizontal);
    size_spin = new QSpinBox();
    size_spin->setRange(0, 10);
    size_slider->setRange(0, 10);
    size_slider->setValue(1);
    size_spin->setValue(1);

    QObject::connect(size_spin, SIGNAL(valueChanged(int)),   size_slider, SLOT(setValue(int)));
    QObject::connect(size_slider, SIGNAL(valueChanged(int)),  size_spin, SLOT(setValue(int)));
    QObject::connect(size_slider, SIGNAL(valueChanged(int)),  GlFrame, SLOT(changeSize(int)));

    ///actions///
    Actions = new QGroupBox("Actions", this);
    animateButton = new QPushButton("Animate");
    openButton = new QPushButton("Open File...");
    stopAnimationButton = new QPushButton("Pause");
    QObject::connect(openButton, SIGNAL(clicked(bool)), GlFrame, SLOT(openFile(bool)));
    QObject::connect(animateButton, SIGNAL(clicked(bool)), GlFrame, SLOT(animate(bool)));
    QObject::connect(stopAnimationButton, SIGNAL(clicked(bool)), GlFrame, SLOT(stopAnimation(bool)));


    ////////////Layouts////////////////

    QHBoxLayout *firstLine = new QHBoxLayout();
    firstLine->addWidget(x_label_resolution);
    firstLine->addWidget(x_spin_resolution);
    firstLine->addStretch();
    firstLine->addWidget(y_label_resolution);
    firstLine->addWidget(y_spin_resolution);
    firstLine->addStretch();
    firstLine->addWidget(z_label_resolution);
    firstLine->addWidget(z_spin_resolution);
    firstLine->addStretch();
    firstLine->addWidget(spacing_label);
    firstLine->addWidget(spacing_spin);
    firstLine->addWidget(inches);

    QVBoxLayout *resolution_layout = new QVBoxLayout();
    resolution_layout->addLayout(firstLine);
    Resolution->setLayout(resolution_layout);

    QGridLayout *led_color_layout = new QGridLayout();
    led_color_layout->addWidget(red, 1, 1);
    led_color_layout->addWidget(green, 1, 2);
    led_color_layout->addWidget(yellow, 1, 3);
    led_color_layout->addWidget(white, 1, 4);
    led_color_layout->addWidget(animateButton);
    led_color_layout->addWidget(openButton);
    Led_color->setLayout(led_color_layout);

    QGridLayout *Transforms_layout = new QGridLayout();
    Transforms_layout->addWidget(x_label_rotation, 1, 1);
    Transforms_layout->addWidget(x_slider_rotation, 1, 2);
    Transforms_layout->addWidget(x_spin_rotation, 1, 3);
    Transforms_layout->addWidget(y_label_rotation, 2, 1);
    Transforms_layout->addWidget(y_slider_rotation, 2, 2);
    Transforms_layout->addWidget(y_spin_rotation, 2, 3);
    Transforms_layout->addWidget(z_label_rotation, 3, 1);
    Transforms_layout->addWidget(z_slider_rotation, 3, 2);
    Transforms_layout->addWidget(z_spin_rotation, 3, 3);
    Transforms_layout->addWidget(zoom_label_rotation, 4, 1);
    Transforms_layout->addWidget(zoom_slider_rotation, 4, 2);
    Transforms_layout->addWidget(zoom_spin_rotation, 4, 3);
    Transforms_layout->addWidget(size_label, 5, 1);
    Transforms_layout->addWidget(size_slider, 5, 2);
    Transforms_layout->addWidget(size_spin, 5, 3);
    Transforms->setLayout(Transforms_layout);

    QHBoxLayout *Actions_layout = new QHBoxLayout();
    Actions_layout->addWidget(animateButton);
    Actions_layout->addWidget(stopAnimationButton);
    Actions_layout->addWidget(openButton);    
    Actions->setLayout(Actions_layout);

    QVBoxLayout *Main_layoutRight = new QVBoxLayout();
    QHBoxLayout *Main_layout = new QHBoxLayout();

    Main_layoutRight->addWidget(Transforms);
    Main_layoutRight->addWidget(Resolution);
    Main_layoutRight->addWidget(Led_color);
    Main_layoutRight->addWidget(Actions);

    Main_layout->addWidget(GlFrame);
    Main_layout->addStretch();
    Main_layout->addLayout(Main_layoutRight);

    setLayout(Main_layout);
    setWindowTitle("GL Application");

}
