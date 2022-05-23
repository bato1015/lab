#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

const static GLfloat blue[] = {0.2, 0.2, 0.8, 1.0}; /* 球の色 */
const static GLfloat yellow[] = {0.8, 0.8, 0.2, 1.0};
const static GLfloat red[] = {0.8, 0.2, 0.2, 1.0};

const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
int base1 = 90, jo1 = 0, jo2 = 0, jo3 = 0;
int joint = 0;
bool flag = 0;

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */

/*
 * 直方体を描く
 */
GLboolean isLine = GL_FALSE;

// cc prog4.c -L/usr/X11R6/lib -lglut -lGLU -lGL  -lXi -lXext -lX11 -lm^C
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
    for (j = -10; j < 10; ++j)
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

/*
 * 画面表示
 */
static void display(void)
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */

    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();

    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/
    glTranslated(0.0, 0.0, -20.0);

    /* シーンの描画 */
    myGround(-2.0); /* 地面　　　 */
    base(base1);
    joint1_display(jo1);
    upper_display();
    joint2_display(jo2);
    forearm_display();
    joint3_display(jo3);
    hand_display();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    isLine = (isLine == GL_TRUE ? GL_FALSE : GL_TRUE);
    glutPostRedisplay(); //再表示
}

static void resize(int w, int h)
{
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);

    /* 透視変換行列の指定 */
    glMatrixMode(GL_PROJECTION);

    /* 透視変換行列の初期化 */
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

    /* モデルビュー変換行列の指定 */
    glMatrixMode(GL_MODELVIEW);
}

static void swjug(int &a, int anglemax, int anglemin)
{
    if (a > anglemax)
        flag = 1;
    if (flag == 1)
    {
        a -= 10;
        if (a < anglemin)
            flag = 0;
    }
    else
        a += 10;

    glutPostRedisplay();
}

static void keyboard(unsigned char key, int x, int y)
{
    /*if (key == 'e')
    {
        joint = 20;
        glutPostRedisplay(); //再表示
    }*/
    if (key == 'w')
    {
        if (base1 > 360)
            base1 = 0;
        base1 += 10;
        glutPostRedisplay(); //再表示
        // ESC か q をタイプしたら終了
    }
    /*if (key == 'w')
        swjug(base1, 0, 360);*/
    if (key == 'e')
        swjug(jo1, 0, -90);
    if (key == 'r')
        swjug(jo2, 0, -90);
    if (key == 't')
        swjug(jo3, 0, -90);
    if (key == '\033' || key == 'q')
    {
        exit(0);
    }
}

static void init(void)
{
    /* 初期設定 */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutInitWindowSize(900, 900);
    glutKeyboardFunc(keyboard);
    init();
    // printf("%d", nice);
    glutMainLoop();
    return 0;
}