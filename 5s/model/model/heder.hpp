//oprnGL
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
#include <vector>

#include <opencv2/opencv.hpp>
#include"display.hpp"

#include <stdlib.h>

#if defined(WIN32)
#  include "glut.h"
#elif defined(__APPLE__) || defined(MACOSX)
#  include <GLUT/glut.h>
#else
#  define GL_GLEXT_PROTOTYPES
#  include <GL/glut.h>
#endif

/* 画像解像度 2835 pixel/meter ≒ 72dpi */
#define XRESOLUTION 2835
#define YRESOLUTION 2835

/*
** ウィンドウの内容を BMP 形式で保存
*/

static void myCylinder(double radius, double height, int sides);
static void myBox(double x, double y, double z);//red
double radee(int n);//パイ矢印
void hand_display();
void joint3_display(int n);
void forearm_display();
void joint2_display(int n);
void upper_display();
void joint1_display(int n);
void base(int n);
auto x_kaitenn(int re);
auto y_kaitenn(int re);
auto z_kaitenn(int re);

void kage(double tate,double yoko,double takasa,double x);
static void myBox1(double x, double y, double z);//blue
static void myBox2(double x, double y, double z);//
static void myGround(double height);
void track();
static void display();
static void since2(void);
static void resize1(int w, int h);
static void swjug(unsigned char key, unsigned char down_char, unsigned char up_char, int &a, int anglemin, int anglemax);
static void keyboard(unsigned char key, int x, int y);
static void init(void);

int saveimage1(void);

double radee(int n);

int bay = 50;        //等倍
int rubberband = 0; /* ラバーバンドの消去 */

double crower = 0.0105*bay;              //クローラー
double body[] = {0.06*bay, 0.025*bay};      //半径,高さ
double boom[] = {0.01*bay, 0.115*bay, 0.01*bay}; //縦,高さ,横
double arm[] = {0.01*bay, 0.06*bay, 0.01*bay};   //縦、高さ、横
//double siten = 0.015*bay;               //視点の位置を取り付け
double siten = 0.012*bay;  
double point_che = 0.25+0.1;            //注釈点
bool flag_num=0;

double tatetate[3000];
double yokoyoko[3000];
double pppoint_x[3000];
double pppoint_y[3000];
double ppkaitenn[3000];
int count=0;




//deg→rad
double radee(int n){
    return n*3.1415/180;
}

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

/*ハンド*/
void hand_display()
{
    glTranslated(0, 0.03/4 *bay , 0.03/4 *bay);
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
    //glNormal3d(0.0, 0.0, 0.0);
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
        glTranslated(5, 1.125, 0);//基準面

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

void kage(double tate,double yoko,double takasa,double x,double z){

//double w_x,double  w_y,double w_z
    //glBegin(GL_LINE_LOOP);
    glBegin(GL_POLYGON);
    glVertex3d(x-yoko/2,0,z-tate/2);
    glVertex3d(x-yoko/2,0,z+tate/2);
    //glVertex3d(w_x,w_y,w_z);
    glVertex3d(x+yoko/2,0,z+tate/2);
    glVertex3d(x+yoko/2,0,z-tate/2);
    //glVertex3d(w_x,w_y,w_z);
    glColor3f(1,0,0);
    glEnd();
    
}


//std::string str="123456789abcdefghijklmn";
//std::string strr="0123456";

void saveImage( const unsigned int imageWidth, const unsigned int imageHeight ,int j,int r)
{

std::ostringstream j_out;
 j_out << std::setfill('0') << std::setw(2) << j;
std::string str = j_out.str();

std::ostringstream r_out;
r_out << std::setfill('0') << std::setw(3) << r;
std::string strr = r_out.str();


  const unsigned int channelNum = 3; // RGBなら3, RGBAなら4
  void* dataBuffer = NULL;
  dataBuffer = ( GLubyte* )malloc( imageWidth * imageHeight * channelNum );

  // 読み取るOpneGLのバッファを指定 GL_FRONT:フロントバッファ　GL_BACK:バックバッファ
  glReadBuffer( GL_BACK );

  // OpenGLで画面に描画されている内容をバッファに格納
  glReadPixels(
    0,                 //読み取る領域の左下隅のx座標
	0,                 //読み取る領域の左下隅のy座標 //0 or getCurrentWidth() - 1
	imageWidth,             //読み取る領域の幅
	imageHeight,            //読み取る領域の高さ
	GL_BGR, //it means GL_BGR,           //取得したい色情報の形式
	GL_UNSIGNED_BYTE,  //読み取ったデータを保存する配列の型
	dataBuffer      //ビットマップのピクセルデータ（実際にはバイト配列）へのポインタ
	);

  GLubyte* p = static_cast<GLubyte*>( dataBuffer );
 
  std::string fname="../image2/outputImage";
  std::string choushi=".jpg";
  fname = fname+strr+str+choushi;

  IplImage* outImage = cvCreateImage( cvSize( imageWidth, imageHeight ), IPL_DEPTH_8U, 3 );
  

  for ( unsigned int j = 0; j < imageHeight; ++ j )
  {
    for ( unsigned int i = 0; i < imageWidth; ++i )
    {
      outImage->imageData[ ( imageHeight - j - 1 ) * outImage->widthStep + i * 3 + 0 ] = *p;
      outImage->imageData[ ( imageHeight - j - 1 ) * outImage->widthStep + i * 3 + 1 ] = *( p + 1 );
      outImage->imageData[ ( imageHeight - j - 1 ) * outImage->widthStep + i * 3 + 2 ] = *( p + 2 );
      p += 3;
    }
  }

  cvSaveImage(fname.c_str(), outImage );
    cv::Mat img, dst;

  img = cv::imread("./image/outputImage.jpg");
   //std::cout << img << std::endl;

}

int saveimage1(void)
{
  /* BMP/DIB ファイルのヘッダ定義 */
  struct biHeader {
    unsigned char bfType[2];
    unsigned char bfSize[4];
    unsigned char bfReserved1[2];
    unsigned char bfReserved2[2];
    unsigned char bfOffBits[4];
    unsigned char biSize[4];
    unsigned char biWidth[4];
    unsigned char biHeight[4];
    unsigned char biPlanes[2];
    unsigned char biBitCount[2];
    unsigned char biCompression[4];
    unsigned char biSizeImage[4];
    unsigned char biXPelsPerMeter[4];
    unsigned char biYPelsPerMeter[4];
    unsigned char biClrUsed[4];
    unsigned char biClrImportant[4];
  } header;
  
  GLint view[4];
  GLubyte *image;
  size_t size;

  /* 画面表示の完了を待つ */
  glFinish();

  /* 現在のビューポートのサイズを得る */
  glGetIntegerv(GL_VIEWPORT, view);
  
  /* ビューポートのサイズ分のメモリを確保する */
  size = view[2] * view[3] * 3;
  image = (GLubyte *)malloc(size);
  
  if (image) {
    static int count = 0;
    char filename[20];
    FILE *fp;
    
    snprintf(filename, sizeof(filename), "img%05d.bmp", count++);

    fp = fopen(filename, "wb");
    if (fp) {
      long temp;

      glReadPixels(view[0], view[1], view[2], view[3],
        GL_BGR, GL_UNSIGNED_BYTE, image);
      
/*
** BMP は Little Endian なので
** 使用マシンの Endian に依存しないように
** 1 byte ずつ設定する
*/

      header.bfType[0] = 'B';
      header.bfType[1] = 'M';

      temp = size + 54;
      header.bfSize[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.bfSize[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.bfSize[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.bfSize[3] = (unsigned char)(temp & 0xff);

      header.bfReserved1[0] = 0;
      header.bfReserved1[1] = 0;
      header.bfReserved2[0] = 0;
      header.bfReserved2[1] = 0;

      header.bfOffBits[0] = 54;
      header.bfOffBits[1] = 0;
      header.bfOffBits[2] = 0;
      header.bfOffBits[3] = 0;

      header.biSize[0] = 40;
      header.biSize[1] = 0;
      header.biSize[2] = 0;
      header.biSize[3] = 0;

      temp = view[2];
      header.biWidth[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biWidth[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biWidth[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biWidth[3] = (unsigned char)(temp & 0xff);

      temp = view[3];
      header.biHeight[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biHeight[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biHeight[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biHeight[3] = (unsigned char)(temp & 0xff);

      header.biPlanes[0] = 1;
      header.biPlanes[1] = 0;

      header.biBitCount[0] = 24;
      header.biBitCount[1] = 0;

      header.biCompression[0] = 0;
      header.biCompression[1] = 0;
      header.biCompression[2] = 0;
      header.biCompression[3] = 0;

      temp = size;
      header.biSizeImage[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biSizeImage[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biSizeImage[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biSizeImage[3] = (unsigned char)(temp & 0xff);

      temp = XRESOLUTION;
      header.biXPelsPerMeter[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biXPelsPerMeter[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biXPelsPerMeter[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biXPelsPerMeter[3] = (unsigned char)(temp & 0xff);

      temp = YRESOLUTION;
      header.biYPelsPerMeter[0] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biYPelsPerMeter[1] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biYPelsPerMeter[2] = (unsigned char)(temp & 0xff);
      temp >>= 8;
      header.biYPelsPerMeter[3] = (unsigned char)(temp & 0xff);

      header.biClrUsed[0] = 0;
      header.biClrUsed[1] = 0;
      header.biClrUsed[2] = 0;
      header.biClrUsed[3] = 0;

      header.biClrImportant[0] = 0;
      header.biClrImportant[1] = 0;
      header.biClrImportant[2] = 0;
      header.biClrImportant[3] = 0;

      fwrite(&header, sizeof(header), 1, fp);
      fwrite(image, size, 1, fp);
      
      fclose(fp);
      
      return 1;
    }
  }
  
  return 0;
}
