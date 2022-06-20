#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <sstream>
#include <glm/glm.hpp>
#include<iostream>
#include <glm/gtc/matrix_transform.hpp>


const static GLfloat blue[] = {0.2, 0.2, 0.8, 1.0}; /* 球の色 */
const static GLfloat yellow[] = {0.8, 0.8, 0.2, 1.0};
const static GLfloat red[] = {0.8, 0.2, 0.2, 1.0};
double radee(int n);

/* 回転行列*/
auto x_kaitenn(int re){
    glm::mat3 e(1,0,0,0,cos(radee(re)),sin(radee(re)),0,-sin(radee(re)),cos(radee(re)));
    auto x=e;
    return x;
}

auto y_kaitenn(int re){
    glm::mat3 e(cos(radee(re)),0,-sin(radee(re)),0,1,0,sin(radee(re)),0,cos(radee(re)));
    auto x=e;
    return x;
}

auto z_kaitenn(int re){
    glm::mat3 e(cos(radee(re)),sin(radee(re)),0,-sin(radee(re)),cos(radee(re)),0,0,0,1);
    auto x=e;
    return x;
}

const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
// int base1 = 90, jo1 = -50, jo2 = -50, jo3 = 0;
int base1 =0, jo1 = 0, jo2 = 0, jo3 = 0;
int bay = 50;        //等倍
int rubberband = 0; /* ラバーバンドの消去 */

double crower = 0.0105*bay;              //クローラー
double body[] = {0.06*bay, 0.025*bay};      //半径,高さ
double boom[] = {0.01*bay, 0.115*bay, 0.01*bay}; //縦,高さ,横
double arm[] = {0.01*bay, 0.06*bay, 0.01*bay};   //縦、高さ、横
//double siten = 0.015*bay;               //視点の位置を取り付け
double siten = 0.015*bay;  
double point_che = 0.3;            //注釈点
bool flag_num=0;

double radee(int n){
    return n*3.1415/180;
}
static void DrawString(std::string str, int w, int h, int x0, int y0);
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
static void myBox1(double x, double y, double z)
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
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);

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
    for (j = -5*bay ; j < 5*bay ; ++j )
    {
        for (i = -5 *bay; i < 5*bay ; ++i )
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

void track(){
    glPushMatrix();
        double danpu[]={5,0.52,2.5};//長さ
        double ita[]={0.2,0.52};//幅
        glTranslated(-5, 1.125, 0);//基準面

        glPushMatrix();
            glTranslated(-danpu[0]/2-ita[0]/2, danpu[1]/2, 0);//横1
            myBox(ita[0]/2 ,  danpu[1]/2, danpu[2]/2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(danpu[0]/2+ita[0]/2, danpu[1]/2, 0);//横2
            myBox(ita[0]/2 ,  danpu[1]/2, danpu[2]/2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0, danpu[1]/2, -danpu[2]/2-ita[0]/2);//縦1
            myBox(danpu[0]/2 , danpu[1]/2, ita[0]/2);
        glPopMatrix();
    
        glPushMatrix();
            glTranslated(0, danpu[1]/2, danpu[2]/2+ita[0]/2);//縦2
            myBox(danpu[0]/2 , danpu[1]/2, ita[0]/2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0, danpu[1]/2-ita[0]/2, 0);//底面
            myBox1(danpu[0]/2 , -ita[0]/2, danpu[2]/2);
        glPopMatrix();

     glPopMatrix();
}
/*ハンド*/
void hand_display()
{
    glTranslated(0, 0.15 , 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glutSolidCube(0.03/2 *bay);
}

void joint3_display(int n)
{
    glPushMatrix();
        glRotated(90.0, 0.0, 0.0, 1.0);
        myCylinder(0.01/2*bay, 0.01/2*bay, 15);
    glPopMatrix();
    glRotated(n, 1.0, 0.0, 0.0);
}
/*上腕*/
void forearm_display()
{
    glTranslated(0.0, arm[1]/2 , 0);
    myBox(arm[0]/2 , arm[1]/2 , arm[2]/2 );
    glTranslated(0, arm[1]/ 2, 0.0);
}

/*関節*/
void joint2_display(int n)
{
    glPushMatrix();
        glRotated(90.0, 0, 0.0, 1.0);
        myCylinder(0.01/2*bay , 0.01/2*bay , 5);
    glPopMatrix();
    glRotated(n, 1.0, 0.0, 0.0);
    // glRotated(n, 0.0, 1.0, 0.0);
}
/*前腕*/
void upper_display()
{
    glTranslated(0.0, boom[1]/2 , 0.0);
    myBox(boom[0]/2 , boom[1]/2 , boom[2]/2 ); /* １番目の腕 */
    glTranslated(0, boom[1]/2 , 0.0);
}
void joint1_display(int n)
{
    glRotated(n, 1.0, 0.0, 0.0);
    glPushMatrix();
        glRotated(90.0, 0.0, 0.0, 1.0);
        myCylinder(0.01/2*bay , 0.01/2*bay, 15);
    glPopMatrix();
}

/* 土台　　　 */
void base(int n)
{
    glRotated(n, 0.0, 1.0, 0.0);
    glTranslated(0.0, crower+body[1]/2 , 0.0);
    myCylinder(body[0]/2 , body[1]/2 , 16);
    char str[256];
    char name_str1[]={"base1"};
   
}

/*
 * 画面表示
 */
static void display(void)
{

    /* シーンの描画 */
    glPushMatrix();
        myGround(-0.02); /* 地面　　　 */
    glPopMatrix();

    glPushMatrix();
        base(base1);
        joint1_display(jo1);
        upper_display();
        joint2_display(jo2);
        forearm_display();
        joint3_display(jo3);
        hand_display();
    glPopMatrix();

    glPushMatrix();
        //glTranslated((sin(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + sin(radee(base1)) * cos(radee(jo1)) * siten),(crower + body[1] + cos(radee(jo1)) * boom[1] /2- sin(radee(jo1)) * siten) ,(cos(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + cos(radee(base1)) * cos(radee(jo1)) * siten));
        float x = sin(radee(base1))*(sin(radee(jo1))* boom[1]  + sin(radee(jo2+jo1)) *arm[1]/2+ cos(radee(jo1+jo2)) * siten);
        float y = (crower + body[1] + cos(radee(jo1)) * boom[1]+cos(radee(jo1+jo2))*arm[1]/2- sin(radee(jo1+jo2)) * siten);
        float z = cos(radee(base1))*(sin(radee(jo1)) * boom[1] + sin(radee(jo1+jo2)) *arm[1]/2+cos(radee(jo1+jo2)) * siten);
        
        float point_x = sin(radee(base1))*(sin(radee(jo1))* boom[1]  + sin(radee(jo2+jo1)) *arm[1]/2+ cos(radee(jo1+jo2)) * (siten + point_che));
        float point_y =(crower + body[1] + cos(radee(jo1)) * boom[1]+cos(radee(jo1+jo2))*arm[1]/2- sin(radee(jo1+jo2)) * (siten + point_che));
        float point_z =cos(radee(base1))*(sin(radee(jo1)) * boom[1] + sin(radee(jo1+jo2)) *arm[1]/2+cos(radee(jo1+jo2)) * (siten + point_che));
        glPushMatrix();
            //glTranslated(x,y,z);
           //glutSolidCube(0.5);
        glPopMatrix();
           //glTranslated(point_x,point_y,point_z);
           glutSolidCube(3);
        glPushMatrix();

        glPopMatrix();
    glPopMatrix();

    //変換の統合
    glPushMatrix();
        /*glRotated(base1, 0.0, 1.0, 0.0);//global→base
        glTranslated(0.0, crower+body[1]/2 , 0.0);
        glRotated(jo1, 1.0, 0.0, 0.0);//base→joint1
        glTranslated(0.0, boom[1] , 0.0);//joint1→前腕
        glRotated(jo2, 1.0, 0.0, 0.0);//前腕→ジョイント２
        glTranslated(0.0, arm[1]/2 , 0);//ジョイント1→上腕
        glTranslated(0.0,0 , 1.5);//上腕→視点*/
        //global→base
        /*glm::vec3 g_b=y_kaitenn(base1)*glm::vec3(0,crower+body[1]/2,0);
        glm::vec3 g_zenwan=x_kaitenn(jo1)*(g_b)+glm::vec3(0,boom[1],0);
        glm::vec3 g_arm=x_kaitenn(jo2)*(g_zenwan)+glm::vec3(0,arm[1]/2,1.5);*/

        glm::vec3 l1=y_kaitenn(base1)*x_kaitenn(jo1)*x_kaitenn(jo2)*glm::vec3(0,arm[1]/2,1.5);
        glm::vec3 l2=y_kaitenn(base1)*x_kaitenn(jo1)*glm::vec3(0,boom[1],0);
        glm::vec3 l3=y_kaitenn(base1)*glm::vec3(0,crower+body[1]/2,0);
        glm::vec3 g_arm=l1+l2+l3;
        glTranslated(g_arm.x,g_arm.y, g_arm.z);
        glutSolidCube(0.3);
    glPopMatrix();
    
    track();

    char str[256];

    sprintf(str, "\n\nb1:%d\nj1:%d\nj2:%d", base1,jo1,jo2); /* 文字(char)配列strにaを数字(%d)に変換した文字列を格納 */
    glPushMatrix();
        glRasterPos2f(x, y); 
        for (int i = 0; i < strlen(str); i++) /* 文字列の長さ繰り返す */
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]); /* 1文字ずつ */
    glPopMatrix();
   /* std::stringstream ss;
    ss << base1;
    std::string str = ss.str(); // "3.14"
    DrawString(str,  3, 4, -20, 30);
  */

    glFlush();

}




static void since1(void)
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
    float x = (sin(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + sin(radee(base1)) * cos(radee(jo1)) * siten);
    float y = (crower + body[1] + cos(radee(jo1)) * boom[1] /2- sin(radee(jo1)) * siten);
    float z = (cos(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + cos(radee(base1)) * cos(radee(jo1)) * siten);

    float xx1 = sin(radee(base1)) * sin(radee(jo1)) * 1;
    float xy1 = cos(radee(jo1)) * 1;
    float xz1 = cos(radee(base1)) * sin(radee(jo1)) * 1;


    float point_x = (sin(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + sin(radee(base1)) * cos(radee(jo1)) * (siten + point_che));
    float point_y =(crower + body[1] + cos(radee(jo1)) * boom[1] /2- sin(radee(jo1)) * (siten + point_che));
    float point_z =(cos(radee(base1)) * sin(radee(jo1)) * boom[1] / 2 + cos(radee(base1)) * cos(radee(jo1)) * (siten + point_che));
    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();

    gluLookAt(x, y, z, point_x, point_y, point_z, xx1, xy1, xz1);
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/
    // glTranslated(0.0, 0.0, -70.0);
    display();
}

static void since3(void)
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
    float x = sin(radee(base1))*(sin(radee(jo1))* boom[1]  + sin(radee(jo2+jo1)) *arm[1]/2+ cos(radee(jo1+jo2)) * siten);
    float y = (crower + body[1] + cos(radee(jo1)) * boom[1]+cos(radee(jo1+jo2))*arm[1]/2- sin(radee(jo1+jo2)) * siten);
    float z = cos(radee(base1))*(sin(radee(jo1)) * boom[1] + sin(radee(jo1+jo2)) *arm[1]/2+cos(radee(jo1+jo2)) * siten);

    float xx1 = sin(radee(base1)) * sin(radee(jo1+jo2)) * 1;
    float xy1 = cos(radee(jo1+jo2)) * 1;
    float xz1 = cos(radee(base1)) * sin(radee(jo1+jo2)) * 1;


    float point_x = sin(radee(base1))*(sin(radee(jo1))* boom[1]  + sin(radee(jo2+jo1)) *arm[1]/2+ cos(radee(jo1+jo2)) * (siten + point_che));
    float point_y =(crower + body[1] + cos(radee(jo1)) * boom[1]+cos(radee(jo1+jo2))*arm[1]/2- sin(radee(jo1+jo2)) * (siten + point_che));
    float point_z =cos(radee(base1))*(sin(radee(jo1)) * boom[1] + sin(radee(jo1+jo2)) *arm[1]/2+cos(radee(jo1+jo2)) * (siten + point_che));
    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();

    gluLookAt(x, y, z, point_x, point_y, point_z, xx1, xy1, xz1);
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/
    // glTranslated(0.0, 0.0, -70.0);
    
    display();
}

static void since2(void) //手計算
{
    const static GLfloat lightpos[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */

    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();
    //gluLookAt(0, 0, 50, 0, 0, -50, 0, 1, 0);
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    /* 視点の移動（シーンの方を奥に移す）*/


    glTranslated(0, 0.0, -50);
    display();
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
    gluPerspective(30.0, (double)w / (double)h, 1.0, 1000000.0);

    /* モデルビュー変換行列の指定 */
    glMatrixMode(GL_MODELVIEW);
}

static void resize1(int w, int h)
{
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);

    /* 透視変換行列の指定 */
    glMatrixMode(GL_PROJECTION);

    /* 透視変換行列の初期化 */
    glLoadIdentity();
    gluPerspective(42.5, 1.63, 1, 1000);

    /* モデルビュー変換行列の指定 */
    glMatrixMode(GL_MODELVIEW);
}

static void swjug(unsigned char key, unsigned char down_char, unsigned char up_char, int &a, int anglemin, int anglemax)
{
    if (key == up_char)
    {
        if (a >=anglemax)
            a = anglemax;
        a += 1;
    }
    if (key == down_char)
    {
        if (a <=anglemin)
            a = anglemin;
        a -= 1;
    }
}

static void keyboard(unsigned char key, int x, int y)
{
    swjug(key, 'w', 's', base1, -180, 180); //旋回
    swjug(key, 'e', 'd', jo1, 0, 90);    //第一関節
    swjug(key, 'r', 'f', jo2, 0, 90);    //第一関節
    swjug(key, 't', 'g', jo3, 0, 90);    //第一関節
    glutPostRedisplay();

    if (key == '\033' || key == 'q')
    {
        exit(0);
    }
    if(key=='u')
        flag_num=1;
    if(key='j')
        flag_num=0;
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
    glutDisplayFunc(since3);
    glutReshapeFunc(resize1);
    glutInitWindowSize(1280, 1024);
    glutKeyboardFunc(keyboard);
    init();

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window2 = glutCreateWindow(argv[1]);
    glutDisplayFunc(since2);
    glutReshapeFunc(resize);
    glutInitWindowSize(1080, 1024);
    glutKeyboardFunc(keyboard);
    init();

    /*glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window3 = glutCreateWindow(argv[2]);
    glutInitWindowSize(1080, 1024);
    glutDisplayFunc(since3);
    glutReshapeFunc(resize1);
    init();*/

    // printf("%d", nice);
    glutMainLoop();
    return 0;
}