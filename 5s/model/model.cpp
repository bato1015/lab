#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

const static GLfloat blue[] = {0.2, 0.2, 0.8, 1.0}; /* 球の色 */
const static GLfloat yellow[] = {0.8, 0.8, 0.2, 1.0};
const static GLfloat red[] = {0.8, 0.2, 0.2, 1.0};

static void myBox(double x, double y, double z)
{
    GLdouble vertex[][3] = {
        {-x, -y, -z},
        {x, -y, -z},
        {x, y, -z},
        {-x, y, -z},
        {-x, -y, z},
        {x, -y, z},
        {x, y, z},
        {-x, y, z}};

    const static int face[][4] = {
        {0, 1, 2, 3},
        {1, 5, 6, 2},
        {5, 4, 7, 6},
        {4, 0, 3, 7},
        {4, 5, 1, 0},
        {3, 2, 6, 7}};

    const static GLdouble normal[][3] = {
        {0.0, 0.0, -1.0},
        {1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0},
        {-1.0, 0.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, 1.0, 0.0}};

    int i, j;

    /* 材質を設定する */
    glMaterialfv(GL_FRONT, GL_DIFFUSE, red);

    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j)
    {
        glNormal3dv(normal[j]);
        for (i = 4; --i >= 0;)
        {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
}

/*
 * 円柱を描く
 */
//直径、高さ、滑らかさ
static void myCylinder(double radius, double height, int sides)
{
    double step = 6.28318530717958647692 / (double)sides;
    int i = 0;

    /* 材質を設定する */
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);

    /* 上面 */
    glNormal3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    while (i < sides)
    {
        double t = step * (double)i++;
        glVertex3d(radius * sin(t), height, radius * cos(t));
    }
    glEnd();

    /* 底面 */
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    while (--i >= 0)
    {
        double t = step * (double)i;
        glVertex3d(radius * sin(t), -height, radius * cos(t));
    }
    glEnd();

    /* 側面 */
    glBegin(GL_QUAD_STRIP);
    while (i <= sides)
    {
        double t = step * (double)i++;
        double x = sin(t);
        double z = cos(t);

        glNormal3d(x, 0.0, z);
        glVertex3f(radius * x, height, radius * z);
        glVertex3f(radius * x, -height, radius * z);
    }
    glEnd();
}

/*
 * 地面を描く
 */
static void myGround(double height)
{
    const static GLfloat ground[][4] = {
        {0.6, 0.6, 0.6, 1.0},
        {0.3, 0.3, 0.3, 1.0}};

    int i, j;

    glBegin(GL_QUADS);
    glNormal3d(0.0, 1.0, 0.0);
    for (j = -5; j < 5; ++j)
    {
        for (i = -5; i < 5; ++i)
        {
            glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
            glVertex3d((GLdouble)i, height, (GLdouble)j);
            glVertex3d((GLdouble)i, height, (GLdouble)(j + 1));
            glVertex3d((GLdouble)(i + 1), height, (GLdouble)(j + 1));
            glVertex3d((GLdouble)(i + 1), height, (GLdouble)j);
        }
    }
    glEnd();
}

/*ハンド*/
void hand_display()
{
    glTranslated(0.0, 0, -0.8);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glutSolidCube(0.9);
}

void joint3_display(int n)
{
    glTranslated(0.0, 0.0, -1.0);
    glRotated(n, 0.0, 1.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    myCylinder(0.4, 0.4, 15);
}
/*上腕*/
void forearm_display()
{
    glTranslated(0.0, 0.0, -1.0);
    myBox(0.3, 0.3, 1.0);
}

/*関節*/
void joint2_display(int n)
{
    glTranslated(0, 1.0, 0.0);
    glRotated(n, 1.0, 0.0, 0.0);
    glRotated(90.0, 0, 0.0, 1.0);
    myCylinder(0.4, 0.4, 5);
    // glRotated(n, 0.0, 1.0, 0.0);
}
/*前腕*/
void upper_display()
{
    glRotated(-90.0, 0.0, 0.0, 1.0);
    glRotated(0, 0.0, 1.0, 0.0);
    glTranslated(0.0, 1.0, 0.0);
    myBox(0.3, 1.0, 0.3); /* １番目の腕 */
}
void joint1_display(int n)
{
    glTranslated(0, 1.0, 0.0);
    glRotated(n, 1.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 0.0, 1.0);
    myCylinder(0.4, 0.4, 15);
}

/* 土台　　　 */
void base(int n)
{
    glTranslated(0.0, -1.5, 0.0);
    glRotated(n, 0.0, 1.0, 0.0);
    myCylinder(1.0, 0.8, 16);
}