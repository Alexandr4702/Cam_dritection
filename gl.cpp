#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include  <QString>

using namespace Eigen;

static Vector3f Vertices[5]=
{
    Vector3f ( 0, 0,-1),
    Vector3f (-1, 0.5, 1),
    Vector3f ( 1, 0.5, 1),
    Vector3f (-1,-0.5, 1),
    Vector3f ( 1,-0.5, 1)
};

static Vector3f Vertices1[5]=
{
    Vector3f ( 0, 0,-1),
    Vector3f (-1, 0.5, 1),
    Vector3f ( 1, 0.5, 1),
    Vector3f (-1,-0.5, 1),
    Vector3f ( 1,-0.5, 1)
};


Eigen::Vector3f rotate(const Eigen::Vector3f& axis,const Eigen::Vector3f& vector,float alpha)
{
    alpha*=static_cast<float>(M_PI)/360.0f;
    Quaternionf a(cosf(alpha),sinf(alpha)*axis.x(),sinf(alpha)*axis.y(),sinf(alpha)*axis.z());
    Quaternionf b(0,vector.x(),vector.y(),vector.z());
    a.normalize();
    b=a*b*a.conjugate();
    return b.vec();
}

static GLubyte indices[5][4]=
{
        {0,1,2},
        {0,3,4},
        {0,1,3},
        {0,2,4},
        {1,3,4,2},
};



void get_angle_coord(float x ,float y,float z,float* alpha,float* betta,float* gamma)
{

    float r=sqrtf(y*y+x*x+z*z);

    *alpha=acosf(x/r)*180.0f/static_cast<float>(M_PI);
    *betta=acosf(y/r)*180.0f/static_cast<float>(M_PI);
    *gamma=acosf(z/r)*180.0f/static_cast<float>(M_PI);

}


OpenglWidget::OpenglWidget(QWidget *parent) :
    QGLWidget(parent)
{
    setMouseTracking(true);
}

OpenglWidget::~OpenglWidget()
{
}


void OpenglWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    qglClearColor(Qt::black);
    setMouseTracking(true);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0, -1.0, 1.0, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);

}

void OpenglWidget::paintGL()
{

    static float i=0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float size_quad=0.5;
    float alpha,betta,gamma;
    get_angle_coord(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),10.0f-coord_mouse_z,&alpha,&betta,&gamma);

    glLoadIdentity();
    glTranslatef(0,0,-10);
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f( size_quad, size_quad,-size_quad);
        glVertex3f( size_quad,-size_quad,-size_quad);
        glVertex3f(-size_quad,-size_quad,-size_quad);
        glVertex3f(-size_quad, size_quad,-size_quad);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f( size_quad, size_quad, size_quad);
        glVertex3f( size_quad,-size_quad, size_quad);
        glVertex3f(-size_quad,-size_quad, size_quad);
        glVertex3f(-size_quad, size_quad, size_quad);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( size_quad, -size_quad, size_quad);
        glVertex3f( size_quad, -size_quad,-size_quad);
        glVertex3f(-size_quad, -size_quad,-size_quad);
        glVertex3f(-size_quad, -size_quad, size_quad);

        glColor3f(1.0, 0.0, 1.0);
        glVertex3f( size_quad, +size_quad, size_quad);
        glVertex3f( size_quad, +size_quad,-size_quad);
        glVertex3f(-size_quad, +size_quad,-size_quad);
        glVertex3f(-size_quad, +size_quad, size_quad);


        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-size_quad, +size_quad, size_quad);
        glVertex3f(-size_quad, +size_quad,-size_quad);
        glVertex3f(-size_quad, -size_quad,-size_quad);
        glVertex3f(-size_quad, -size_quad, size_quad);

        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(+size_quad, +size_quad, size_quad);
        glVertex3f(+size_quad, +size_quad,-size_quad);
        glVertex3f(+size_quad, -size_quad,-size_quad);
        glVertex3f(+size_quad, -size_quad, size_quad);
    glEnd();




    glLoadIdentity();
    glTranslatef(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),coord_mouse_z);
    //glRotatef(90,1,0,0);

    /*
    glRotatef(angle_a,0,1,0);
    glRotatef(angle_b,-1,0,0);
    glRotatef(angle_g,0,0,1);
    */

    /*
    glColor3f(1.0, 1.0, 1.0);
    renderText(1, 1 , 0, QString::fromUtf8("Вы набрали %1 очков:").arg(1), QFont() );

    Vector3f omega(angle_a,angle_b,angle_g);

    for(int i=0;i<5;i++)
    {
        //Vertices[i]=Vertices1[i];
        Vertices[i]=rotate(omega,Vertices[i],omega.norm());
    }



    glVertexPointer(3, GL_FLOAT, 0, Vertices);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3ub(255, 000, 000);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices[0]);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices[1]);
    glColor3ub(000, 000, 255);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices[2]);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices[3]);
    glColor3ub(000, 255,000);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices[4]);
*/


    static Vector3f x(2,2,0);
    Vector3f omega(angle_a,angle_b,angle_g);
    glColor3f(1.0, 1.0, 1.0);
    renderText(0, 0 , 0, QString::fromUtf8("%1 ").arg(1.0f), QFont() );


    x=rotate(Vector3f(angle_a,angle_b,angle_g),x,omega.norm());


    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f( 0.0,  0, 0);
        glVertex3f( x.x(),  x.y(), x.z());

    glEnd();



    //-----------------------------------------------------------------

    glLoadIdentity();
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f( 0.0,  0, -10);
        glVertex3f(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),coord_mouse_z);

        glVertex3f(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),coord_mouse_z);
        glVertex3f(2,0,0);

        glVertex3f(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),coord_mouse_z);
        glVertex3f(0,2,0);

        glVertex3f(2*(coord_mouse_x-0.5f),2*(coord_mouse_y+0.5f),coord_mouse_z);
        glVertex3f(0,0,2);

    glEnd();
    i+=1;
}


void OpenglWidget::mouseMoveEvent(QMouseEvent *event)
{
    coord_mouse_x= 2*(static_cast<GLfloat>(event->x()))/(static_cast<GLfloat>(this->geometry().width()));
    coord_mouse_y= -2*(static_cast<GLfloat>(event->y()))/(static_cast<GLfloat>(this->geometry().height()));
}
void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, GLint(width), GLint(height));
}



void OpenglWidget::wheelEvent(QWheelEvent *event)
{
    static int test=0;
    test+=event->delta();
    test=(test>5000)?5000:((test<-5000)?-5000:test);
    coord_mouse_z=test/500.0f-11.1f;
     fprintf(stderr,"%f  \r\n",static_cast<double>(coord_mouse_z));
}
