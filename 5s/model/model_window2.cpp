#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

const static GLfloat blue[] = {0.2, 0.2, 0.8, 1.0}; /* 球の色 */
const static GLfloat yellow[] = {0.8, 0.8, 0.2, 1.0};
const static GLfloat red[] = {0.8, 0.2, 0.2, 1.0};

const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
// int base1 = 90, jo1 = -50, jo2 = -50, jo3 = 0;
int base1 = 0, jo1 = 0, jo2 = 0, jo3 = 0;
int joint = 0;
bool flag = 0;
int bay = 5;
#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */

double crower = 0.2;              //クローラー
double body[] = {0.8, 0.25};      //半径,高さ
double boom[] = {0.1, 1.15, 0.1}; //縦,高さ,横
double arm[] = {0.1, 0.6, 0.1};   //縦、高さ、横

float x = sin(base1) * sin(jo1) * boom[1];
float y = crower + body[1] + cos(jo2) * boom[1];
float z = cos(base1) * sin(jo1) * boom[1];

float xx = sin(base1) * sin(jo1) * 1;
float xy = cos(jo2) * 1;
float xz = cos(base1) * cos(jo1) * 1;

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
    for (j = -5 * bay; j < 5 * bay; ++j * bay)
    {
        for (i = -5 * bay; i < 5 * bay; ++i * bay)
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
    glTranslated(0, 0.15 * bay, 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glutSolidCube(0.3 * bay);
}

void joint3_display(int n)
{
    glPushMatrix();
    glRotated(90.0, 0.0, 0.0, 1.0);
    myCylinder(0.1 * bay, 0.1 * bay, 15);
    glPopMatrix();
    glRotated(n, 1.0, 0.0, 0.0);
}
/*上腕*/
void forearm_display()
{
    glTranslated(0.0, arm[1] * bay, 0);
    myBox(arm[0] * bay, arm[1] * bay, arm[2] * bay);
    glTranslated(0, arm[1] * bay, 0.0);
}

/*関節*/
void joint2_display(int n)
{
    glPushMatrix();
    glRotated(90.0, 0, 0.0, 1.0);
    myCylinder(0.1 * bay, 0.1 * bay, 5);
    glPopMatrix();
    glRotated(n, 1.0, 0.0, 0.0);
    // glRotated(n, 0.0, 1.0, 0.0);
}
/*前腕*/
void upper_display()
{
    glTranslated(0.0, boom[1] * bay, 0.0);
    myBox(boom[0] * bay, boom[1] * bay, boom[2] * bay); /* １番目の腕 */
    glTranslated(0, boom[1] * bay, 0.0);
}
void joint1_display(int n)
{
    glRotated(n, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotated(90.0, 0.0, 0.0, 1.0);
    myCylinder(0.1 * bay, 0.4 * bay, 15);
    glPopMatrix();
}

/* 土台　　　 */
void base(int n)
{
    glTranslated(0.0, crower * bay, 0.0);
    glRotated(n, 0.0, 1.0, 0.0);
    myCylinder(body[0] * bay, body[1] * bay, 16);
}

/*
 * 画面表示
 */
static void display(void)
{

    /* シーンの描画 */
    glPushMatrix();

    myGround(-0.2 * bay); /* 地面　　　 */
    base(base1);
    joint1_display(jo1);
    upper_display();
    joint2_display(jo2);
    forearm_display();
    joint3_display(jo3);
    hand_display();

    glPopMatrix();

    glPushMatrix();
    glTranslated(20, 0, 0.0);
    glutSolidCube(0.3 * bay);
    glPopMatrix();

    glFlush();
}
/*視点をもらう*/
static void since(void)
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();

    // gluLookAt(x, y, z, 5 + x, -5, 20 + z, xx, xy, xz);
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/
    glTranslated(0.0, 0, -70.0);
    display();
}

static void since1(void)
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
    float x = sin(base1) * sin(jo1) * boom[1];
    float y = crower + body[1] + cos(jo2) * boom[1];
    float z = cos(base1) * sin(jo1) * boom[1];

    float xx = sin(base1) * sin(jo1) * 1;
    float xy = cos(jo2) * 1;
    float xz = cos(base1) * cos(jo1) * 1;

    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();

    // gluLookAt(x, y, z, 5, -10, -10, 0, 1.0, 0);
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/
    glTranslated(0.0, 0.0, -70.0);
    display();
}

void mouse(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    isLine = (isLine == GL_TRUE ? GL_FALSE : GL_TRUE);
    glutPostRedisplay(); //再表示
}

static void resize1(int w, int h)
{
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);

    /* 透視変換行列の指定 */
    glMatrixMode(GL_PROJECTION);

    /* 透視変換行列の初期化 */
    glLoadIdentity();
    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(xx, 1.0, 0.0, 0.0);
    glRotated(xy, 0.0, 1.0, 0.0);
    glRotated(xz, 0.0, 0.0, 1.0);

    gluPerspective(42.5, 1.63, 1.0, 100);
    glPopMatrix();

    /* モデルビュー変換行列の指定 */
    glMatrixMode(GL_MODELVIEW);
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

static void swjug(unsigned char key, unsigned char down_char, unsigned char up_char, int &a, int anglemin, int anglemax)
{
    if (key == up_char)
    {
        if (a > anglemax)
            a = anglemax;
        a += 1;
    }
    if (key == down_char)
    {
        if (a < anglemin)
            a = anglemin;
        a -= 1;
    }
    glutPostRedisplay();
}

static void keyboard(unsigned char key, int x, int y)
{
    swjug(key, 'w', 's', base1, 0, 360); //旋回
    swjug(key, 'e', 'd', jo1, 0, 90);    //第一関節
    swjug(key, 'r', 'f', jo2, 0, 90);    //第一関節
    swjug(key, 't', 'g', jo3, 0, 90);    //第一関節

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
    //バラバラで動くのはスレッドの導入が必要そうwindow1とwindow2
    int window1, window2, window3;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window1 = glutCreateWindow(argv[0]);
    glutDisplayFunc(since1);
    glutReshapeFunc(resize);
    glutInitWindowSize(1280, 1024);
    glutKeyboardFunc(keyboard);
    init();

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window2 = glutCreateWindow(argv[1]);
    glutDisplayFunc(since1);
    glutReshapeFunc(resize);
    glutInitWindowSize(1080, 1024);
    glutKeyboardFunc(keyboard);
    init();

    /*glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window3 = glutCreateWindow("Window3");
    glutInitWindowSize(1080, 1024);
    glutDisplayFunc(since);
    glutReshapeFunc(resize);
    init();
    */
    // printf("%d", nice);
    glutMainLoop();
    return 0;
}