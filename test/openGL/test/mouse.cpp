/* prog04.c */
/* マウスで線を描く */
/* ESC キーで終了 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXPOINTS 100

GLint windowH;                /* 現在のウィンドウの高さ */
GLdouble point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;             /* 記憶した座標の数 */
int rubberband = 0;           /* ラバーバンドの消去 */

void display(void)
{
    /* 変更なし */
}

void resize(int w, int h)
{
    /* 変更なし */
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        fprintf(stderr, "(%d, %d) ", x, y);
        /* ボタンを操作した位置を記録する */
        point[pointnum][0] = (GLdouble)x / 300.0;
        point[pointnum][1] = (GLdouble)(windowH - y) / 300.0;

        if (state == GLUT_UP)
        {
            printf("--> (%d, %d)\n", x, y);
            /* ボタンを押した位置から離した位置まで線を引く */
            glColor3d(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2dv(point[pointnum - 1]); /* 一つ前は押した位置 */
            glVertex2dv(point[pointnum]);     /* 現在の位置は離した位置 */
            glEnd();
            glFlush();
            rubberband = 0;
        }
        if (pointnum < MAXPOINTS)
            pointnum++;
        break;
    case GLUT_MIDDLE_BUTTON:
        break;
    case GLUT_RIGHT_BUTTON:
        break;
    default:
        break;
    }
}

void motion(int x, int y)
{
    static GLdouble savepoint[2]; /* 以前のラバーバンドの端点 */

    /* 論理演算機能 ON */
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_INVERT);

    glBegin(GL_LINES);
    if (rubberband)
    {
        /* 以前のラバーバンドを消す */
        glVertex2dv(point[pointnum - 1]);
        glVertex2dv(savepoint);
    }
    /* ラバーバンドを描き始める */
    glVertex2dv(point[pointnum - 1]);
    glVertex2d((GLdouble)x / 300.0, (GLdouble)(windowH - y) / 300.0);
    glEnd();

    glFlush();

    /* 論理演算機能 OFF */
    glLogicOp(GL_COPY);
    glDisable(GL_LOGIC_OP);

    /* 今描いたラバーバンドの端点を保存 */
    savepoint[0] = (GLdouble)x / 300.0;
    savepoint[1] = (GLdouble)(windowH - y) / 300.0;
    rubberband = 1;
}

void init(void)
{
    /* 変更なし */
}

int main(int argc, char *argv[])
{
    /* 初期化 */
    glutInit(&argc, argv);

    /* ウィンドウの生成 */
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(200, 50);
    glutInitWindowSize(900, 900);
    glutCreateWindow(argv[0]);

    /* OpenGL 初期化ルーチンの呼出し */
    init();

    /* 描画ルーチンの設定 */
    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    /* 入力処理ルーチンの設定 */
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    /* 無限ループ */
    glutMainLoop();
    return 0;
}