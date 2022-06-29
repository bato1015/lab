#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>

std::string str="123456789abcdefghijklmn";
std::string strr="0123456";



int main(){
     cv::Mat img,img1,img2,img5;
  std::string fname="../outputImage";
  std::string choushi=".jpg";
  std::string fname11,fname22;
  cv::Mat output_img1;

  	cv::Mat gray_img;
	cv::Mat bin_img;

  double r=0.0769231;
  fname11 = fname+strr[0]+str[0]+choushi;
  img = cv::imread(fname11.c_str());
  img5 = cv::imread(fname11.c_str());
  for(int i=1;i<13;i++){
  fname22 = fname+strr[0]+str[i]+choushi;
  img2=cv::imread(fname22.c_str());
    //add(img,img2,output_img1);
    addWeighted(img, 0.0769231*(i+3), img2, 0.0769231, 10, img);
    cv::imshow("title",img);
  }


//読み取った画像をグレースケールにする　　　　　

	cvtColor(img, gray_img, CV_BGR2GRAY);



//グレースケールにした画像を２値化する

	threshold(gray_img, bin_img, 100, 255, cv::THRESH_BINARY);



// 白色領域の面積(ピクセル数)を計算する

	double White = countNonZero(bin_img);	
    double all=1280*720;
    double black=all-White;

//計算結果を表示する		

	printf("White=%f\n", White);
    printf("black=%f\n",all);
    printf("OK=%f\n",(1280*720-White)/(1280*720));

cv::imwrite("../output.png", img);


  cv::waitKey(0);

    //std::cout << img << std::endl;
    return 0;
}

