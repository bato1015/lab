#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <fstream>

std::string str[13]={"00","01","02","03","04","05","06","07","08","09","10","11","12"};
std::string strr="0123456";

unsigned int seconnd=0;

int main(){

  std::ofstream writing_file;
  std::string filename = "sample1.txt";
  writing_file.open(filename, std::ios::out);

  for(int m=0;m<151;m++){
  cv::Mat img,img1,img2,img5;
  std::string fname="../../image2/outputImage";
  std::string choushi=".jpg";
  std::string fname11,fname22;
  cv::Mat output_img1;

  	cv::Mat gray_img;
	cv::Mat bin_img;

  double r=0.0769231;

std::ostringstream r_out;
 r_out << std::setfill('0') << std::setw(3) << m;
std::string strr= r_out.str();
std::string str="00";

  fname11 = fname+strr+str+choushi;
  img = cv::imread(fname11.c_str());

//読み取った画像をグレースケールにする　　　　　

	cvtColor(img, gray_img, CV_BGR2GRAY);



//グレースケールにした画像を２値化する

	threshold(gray_img, bin_img, 100, 255, cv::THRESH_BINARY);



// 白色領域の面積(ピクセル数)を計算する

	double White = countNonZero(bin_img);	
    double all=1280*720;
    double black=all-White;

//計算結果を表示する		

	printf("second=%d\n",seconnd);
  printf("White=%f\n", White);
    printf("black=%f\n",all);
    printf("OK=%f\n",(1280*720-White)/(1280*720)*100);

//cv::imwrite("output.png", img);

 //writing_file <<m<<":"<<(1280*720-White)/(1280*720)*100<<std::endl;
writing_file <<(1280*720-White)/(1280*720)*100<<std::endl;
  //cv::waitKey(0);

    //std::cout << img << std::endl;
  }
    return 0;
}

