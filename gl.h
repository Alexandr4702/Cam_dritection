#ifndef GL_H
#define GL_H


#include <QGLWidget>
#include <QtOpenGL>

class OpenglWidget : public QGLWidget
{
public:
    GLfloat coord_mouse_x=0,coord_mouse_y=0,coord_mouse_z=-1.1f;
    GLfloat angle_a=0,angle_b=0,angle_g=0;


    OpenglWidget(QWidget *parent = nullptr);
    ~OpenglWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};


#endif // GL_H
