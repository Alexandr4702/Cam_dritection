#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GL_w=new OpenglWidget(ui->centralWidget);
    GL_w->setGeometry(QRect(0, 0, this->geometry().width(), this->geometry().height()));

    tim=new QTimer;
    connect(tim,SIGNAL(timeout()),GL_w,SLOT(update()));
    tim->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
    GL_w->setGeometry(QRect(0, 0, event->size().width(), event->size().height()));
}


void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key())
    {


    case Qt::Key_Space:
        GL_w->angle_a=0.0f;GL_w->angle_b=0.0f;GL_w->angle_g=0.0f;
                break;
    case Qt::Key_Q:
        GL_w->angle_g=1;
        break;
    case Qt::Key_E:
        GL_w->angle_g=-1;
        break;
    case Qt::Key_A:
        GL_w->angle_b=1;
        break;
    case Qt::Key_D:
        GL_w->angle_b=-1;
        break;
    case Qt::Key_W:
        GL_w->angle_a=1;
        break;
    case Qt::Key_S:
        GL_w->angle_a=-1;
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        GL_w->angle_g=0;
        break;
    case Qt::Key_E:
        GL_w->angle_g=0;
        break;
    case Qt::Key_A:
        GL_w->angle_b=0;
        break;
    case Qt::Key_D:
        GL_w->angle_b=0;
        break;
    case Qt::Key_W:
        GL_w->angle_a=0;
        break;
    case Qt::Key_S:
        GL_w->angle_a=0;
        break;
    }
}

