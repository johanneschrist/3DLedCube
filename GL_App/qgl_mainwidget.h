#ifndef QGL_MAINWIDGET_H
#define QGL_MAINWIDGET_H

#include <QFrame> //set what classes to be used

class QLabel;
class QCheckbox;
class QGroupBox;
class QSpinBox;
class QSlider;
class QRadioButton;
class QLineEdit;
class QFrame;
class QGLWidget;
class MyGLWidget;
class QPushButton;


class QGL_MainWidget : public QFrame
{
    Q_OBJECT

public:
    QGL_MainWidget(QWidget *parent = 0);

private: //define the type and names of the widgets
    MyGLWidget *GlFrame;
    QGroupBox *Resolution;
    QLabel *x_label_resolution;
    QSpinBox *x_spin_resolution;
    QLabel *y_label_resolution;
    QSpinBox *y_spin_resolution;
    QLabel *z_label_resolution;
    QSpinBox *z_spin_resolution;
    QLabel *spacing_label;
    QSpinBox *spacing_spin;
    QLabel *inches;
    QGroupBox *Led_color;
    QRadioButton *red;
    QRadioButton *green;
    QRadioButton *yellow;
    QRadioButton *white;
    QGroupBox *Transforms;
    QLabel *x_label_rotation;
    QSlider *x_slider_rotation;
    QSpinBox *x_spin_rotation;
    QLabel *y_label_rotation;
    QSlider *y_slider_rotation;
    QSpinBox *y_spin_rotation;
    QLabel *z_label_rotation;
    QSlider *z_slider_rotation;
    QSpinBox *z_spin_rotation;
    QLabel *zoom_label_rotation;
    QSlider *zoom_slider_rotation;
    QSpinBox *zoom_spin_rotation;
    QLabel *size_label;
    QSlider *size_slider;
    QSpinBox *size_spin;
    QGroupBox *Actions;
    QPushButton *animateButton;
    QPushButton *openButton;
    QPushButton *stopAnimationButton;

};

#endif // QGL_MAINWIDGET_H
