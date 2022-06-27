#include "heder.hpp"

int base1 =0, jo1 = 60, jo2 = 140-jo1+40-90, jo3 = -90;
double sennsad=7;



static void display(){
    //double senssa=arm[1];

    double lijyou=siten/tan(radee(siten/(0.03*bay)*57));//バケットが見える最大長
    double kakudo=57/2-siten/(0.03*bay)*57;//バケッと角度

    double senssa=arm[1]-lijyou-0.2*sennsad;//センサ長

    glm::vec3 point_l1 = y_kaitenn(base1)*x_kaitenn(jo1)*x_kaitenn(jo2)*glm::vec3(0,senssa,point_che);
    glm::vec3 point_l2 =y_kaitenn(base1)*x_kaitenn(jo1)*glm::vec3(0,boom[1],0);
    glm::vec3 point_l3 =y_kaitenn(base1)*glm::vec3(0,crower+body[1]/2,0);
    glm::vec3 point_chu=point_l1+point_l2+point_l3;//センサ位置の順運動学


     /* シーンの描画 */
    glPushMatrix();
        //myGround(-0.02); /* 地面　　　 */
        glTranslated(point_chu.x, point_chu.y, point_chu.z);//底面
        glRotated(base1,0,1,0);  
        //glutSolidCube(0.5);
    glPopMatrix();
    char str[256];
    //track();
    //台車
    //base(base1);
    /*glPushMatrix();
        base(base1);
        joint1_display(jo1);
        upper_display();
        joint2_display(jo2);
        forearm_display();
        joint3_display(jo3);
        hand_display();
    glPopMatrix();*/
    double qw=0;
    double w1=tan(radee(86/2))*(point_chu.y)*2;
    double h1=tan(radee(57/2))*(point_chu.y)*2;
    //double se1=tan(radee(68+10))*(point_chu.y)-tan(radee(10))*(point_chu.y);

    //backetの影
    
    glPushMatrix();
        
    glPopMatrix();
    glPushMatrix(); 
    //glTranslated(g_arm.x+g_arm.y*tan(radee(68+40)),0,g_arm.z);//底面
    //glTranslated(point_chu.x,0,point_chu.z);//底面
    //glRotated(base1,0,1,0);
        if(point_chu.y<6){  
            //kage(h1,w1,7,0,0);
            tatetate[count]=h1;
            yokoyoko[count]=w1;
            pppoint_x[count]=point_chu.x;
            pppoint_y[count]=point_chu.z;
            ppkaitenn[count]=base1;
            
            count++;
        }
        //影の描画
        for(int i=0;i<count;i++){
            glPushMatrix();
                glTranslated(pppoint_x[i],0,pppoint_y[i]);//底面
                glRotated(ppkaitenn[i],0,1,0);
                kage(tatetate[i],yokoyoko[i],0,0,0);
                //glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
            glPopMatrix();
        }
        //90度のときの画面
        /*for(int i=0;i<count;i++){
            glPushMatrix();
                glTranslated(pppoint_x[i],0,pppoint_y[i]);//底面
                glRotated(ppkaitenn[i],0,1,0);
                kage(tatetate[i],yokoyoko[i],0,0,0);
            glPopMatrix();
        }*/
    glPopMatrix();
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    sprintf(str, "kakudo:%lf\nl_i:%lf\nw1:%lf\n\nb1:%d\nj1:%d\nj2:%d",kakudo,lijyou,point_chu.y, base1,jo1,jo2); /* 文字(char)配列strにaを数字(%d)に変換した文字列を格納 */
    glPushMatrix();
        glRasterPos2f(-5, 10); 
        for (int i = 0; i < strlen(str); i++) /* 文字列の長さ繰り返す */
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]); /* 1文字ずつ */
    glPopMatrix();
    glFlush();
}



static void since2(void) //手計算
{
    
    const static GLfloat lightpos1[] = {3.0, 4.0, 5.0, 1.0}; /* 光源の位置 */
    static GLfloat lightDiffuse[3]  = { 1.0,   1.0, 1.0  }; //拡散光
    static GLfloat lightAmbient[3]  = { 0.25, 0.25, 0.25 }; //環境光
    static GLfloat lightSpecular[3] = { 1.0,   1.0, 1.0  }; //鏡面光

    /* 画面クリア */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* モデルビュー変換行列の初期化 */
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, -30, 0, 1, 0, 0);//上面
//gluLookAt(30, 0, 0, -30,0, 0, 0, 1, 0);//横面
    //gluLookAt(0, 0, 30, 0,0, -30, 0, 1, 0);//横面
    /* 光源の位置を設定 */
    glLightfv(GL_LIGHT1, GL_POSITION, lightpos1);
    /* 視点の移動（シーンの方を奥に移す）*/


    //glTranslated(0, 0.0, -50);
                display();
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
    swjug(key, 'w', 's', base1, 1, 89); //旋回
    swjug(key, 'e', 'd', jo1, 0, 90);    //第一関節
    swjug(key, 'r', 'f', jo2, 0, 150);    //第一関節
    swjug(key, 't', 'g', jo3, -90, 0);    //第一関節
    glutPostRedisplay();

    if (key == '\033' || key == 'q')
    {
        saveImage(1280, 720);
        saveimage1();
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
    glEnable(GL_LIGHT1);      /* 1番目の光源点灯 */
}

int main(int argc, char *argv[])
{
    //バラバラで動くのはスレッドの導入が必要そうwindow1とwindow2
    //エスケープで保存
    int window1;
    GLint* w;
     glGetTexLevelParameteriv(GL_PROXY_TEXTURE_1D,0,GL_TEXTURE_HEIGHT,w);
     std::cout<<w<<std::endl;
    //glutInitWindowPosition(100, 100);
     glutInitWindowSize(1280, 720);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    window1 = glutCreateWindow(argv[0]);
    glutDisplayFunc(since2);
    glutReshapeFunc(resize1);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}