// prog06.cc: Sec 5.5 の終わりのプログラム
// 立方体を表示
// 面ごとに色が違う・ダブルバッファ・隠面消去・カリング

#include <GL/glut.h>
#include <stdlib.h> // exit() のため

// マシンの処理速度の差の調整用パラメタ
#define  adjust_r  5

GLdouble vertex[][3] = {
  { 0.0, 0.0, 1.0 },
  { 0.0, 1.0, 0.0 },
  { 1.0, 0.0, 0.0 },
  { 0.0, 0.0,-1.0 },
  {-1.0, 0.0, 0.0 },
  { 0.0,-1.0, 0.0 }
};

int edge[][2] = {
  { 0, 1 }, // [0] (A-B)
  { 1, 2 }, // [1] (B-C)
  { 2, 3 }, // [2] (C-D)
  { 3, 0 }, // [3] (D-A)
  { 4, 5 }, // [4] (E-F)
  { 5, 6 }, // [5] (F-G)
  { 6, 7 }, // [6] (G-H)
  { 7, 4 }, // [7] (H-E)
  { 0, 5 }, // [8] (A-F)
  { 1, 4 }, // [9] (B-E)
  { 2, 7 }, // [10] (C-H)
  { 3, 6 }  // [11] (D-G)
 };


/* 時計まわり */
int face[][3] = {
  { 0, 1, 2 },
  { 2, 1, 3 },
  { 3, 1, 4 },
  { 4, 1, 0 },
  { 5, 0, 2 },
  { 5, 4, 0 },
  { 5, 3, 4 },
  { 5, 2, 3 }
};

GLdouble color[][3] = {
  { 1.0, 0.0, 0.0 }, // 赤
  { 0.0, 1.0, 0.0 }, // 緑
  { 0.0, 0.0, 1.0 }, // 青
  { 1.0, 1.0, 0.0 }, // 黄
  { 1.0, 0.0, 1.0 }, // マゼンタ
  { 0.0, 1.0, 1.0 }  // シアン
};

/* 立方体の６つの表面法線ベクトル */
GLdouble normal[][3] = {
  { 0.0, 0.0, -1.0 },
  { 1.0, 0.0,  0.0 },
  {-1.0, 0.0,  0.0 },
  { 0.0, 0.0,  1.0 },
  { 0.0, 1.0,  0.0 },
  { 0.0,-1.0,  0.0 }
};

/* 光源の設定用 (四つ目の要素は 1.0 にする)*/
GLfloat light0pos[] = { 0.0, 3.0, 5.0, 1.0 };
/*GLfloat light1pos[] = { 5.0, 10.0, 0.0, 1.0 };
GLfloat red[] = { 1.0, 0.4, 0.3, 1.0 };
GLfloat blue[] = { 0.2, 0.4, 1.0, 1.0 };*/

// 描画
void display(void)
{
  int i;
  int j;
  static int r = 0;	// 回転角

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  // 視点位置と視線方向
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    /* 光源の位置設定 */
  glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
  //glLightfv(GL_LIGHT1, GL_POSITION, light1pos);

  // 図形の回転
  glRotated((double)r/adjust_r, 0.0, 1.0, 0.0);

    /* 図形の描画 */
  glBegin(GL_TRIANGLES);  /* 注意！GL_QUADS ではないです。*/
  for (j = 0; j < 8; j++){
    for (i = 0; i < 3; i++){
      glNormal3dv(vertex[face[j][i]]);
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();
       
  glutSwapBuffers();

  // 回転の制御
  if (glutLayerGet(GLUT_NORMAL_DAMAGED) == 0) {
    // glutPostRedisplay() による再描画
    if (r++ >= 360*adjust_r) {
      // 一周回ったらアニメーションを止める
      r = 0;
      glutIdleFunc(0);
    }
  }
}

void idle(void)
{
  glutPostRedisplay();
}

void resize(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  // ウィンドウ全体をビューポートにする
  glMatrixMode(GL_PROJECTION);          // マトリックスモードを投影変換にする
  glLoadIdentity();                     // 変換行列の初期化
  gluPerspective(30.0, (double)w/(double)h, 3.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case '\33': // \33 は ESC の ASCII コード
  case 'q':
  case 'Q':
    exit(0);
  default :
    break;
  }
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    // アニメーション開始
    if (state == GLUT_UP) glutIdleFunc(idle);
    break;
  case GLUT_MIDDLE_BUTTON:
    // コマ送り
    if (state == GLUT_UP) glutPostRedisplay();
    break;
  case GLUT_RIGHT_BUTTON:
    // アニメーション停止
    if (state == GLUT_UP) glutIdleFunc(NULL);
    break;
  default:
    break;
  }
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);	// 隠面消去
  
  glEnable(GL_CULL_FACE);	// カリング
  glFrontFace(GL_CW);		// 時計まわりを表に設定
  glCullFace(GL_BACK);		// カリングする面の指定
    glEnable(GL_LIGHTING);    /* ライティング処理のオン */
  glEnable(GL_LIGHT0);      /* ０番目の光源点灯 */
   /*glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
   glEnable(GL_LIGHT1);   
  glLightfv(GL_LIGHT1, GL_DIFFUSE, blue); :*/
  

}

int main(int argc, char** argv)
{
  // 初期化
  glutInit(&argc, argv);

  // ウィンドウの生成
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(200, 50);
  glutInitWindowSize(300, 300);
  glutCreateWindow(argv[0]);

  // OpenGL 初期化ルーチンの呼出し
  init();

  // 描画ルーチンの設定
  glutDisplayFunc(display);
  glutReshapeFunc(resize);

  // 入力処理ルーチンの設定
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  // 無限ループ
  glutMainLoop();
  return 0;
}
