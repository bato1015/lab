#include <GL/glut.h>


GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 }, /* A */
  { 1.0, 0.0, 0.0 }, /* B */
  { 1.0, 1.0, 0.0 }, /* C */
  { 0.0, 1.0, 0.0 }, /* D */
  { 0.0, 0.0, 1.0 }, /* E */
  { 1.0, 0.0, 1.0 }, /* F */
  { 1.0, 1.0, 1.0 }, /* G */
  { 0.0, 1.0, 1.0 }  /* H */
};
int face[][4] = {
  { 0, 1, 2, 3 }, /* A-B-C-D を結ぶ面 */
  { 1, 5, 6, 2 }, /* B-F-G-C を結ぶ面 */
  { 5, 4, 7, 6 }, /* F-E-H-G を結ぶ面 */
  { 4, 0, 3, 7 }, /* E-A-D-H を結ぶ面 */
  { 4, 5, 1, 0 }, /* E-F-B-A を結ぶ面 */
  { 3, 2, 6, 7 }  /* D-C-G-H を結ぶ面 */
};

GLdouble normal[][3] = {
  { 0.0, 0.0,-1.0 },
  { 1.0, 0.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  {-1.0, 0.0, 0.0 },
  { 0.0,-1.0, 0.0 },
  { 0.0, 1.0, 0.0 }
};

void idle(void)
{
  glutPostRedisplay();
}

void display(void)
{
  int i;
  int j;
  static int r = 0; /* 回転角 */

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  /* 視点位置と視線方向 */
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* 図形の回転 */
  glRotated((double)r, 0.0, 1.0, 0.0);

  /* 図形の描画 */
  glBegin(GL_QUADS);
  for (j = 0; j < 6; ++j) {
    glNormal3dv(normal[j]);
    for (i = 0; i < 4; ++i) {
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();

  glutSwapBuffers();

  /* 一周回ったら回転角を 0 に戻す */
  if (++r >= 360) r = 0;
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);

  glLoadIdentity();
  gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}
void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);
  default:
    break;
  }
}


int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}