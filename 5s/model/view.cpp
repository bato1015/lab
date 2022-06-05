#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "model.cpp"
GLboolean isLine = GL_FALSE;

const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
int base1 = 90, jo1 = 0, jo2 = 0, jo3 = 0;
int joint = 0;
bool flag = 0;

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */

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