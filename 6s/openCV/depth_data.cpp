#include<iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img1 = cv::imread("../0.png", -1);
    cv::Mat img2 = cv::imread("../imag55555.png", -1);
    cv::Mat img_OR;
    //cv::bitwise_or(img1, img2,img_OR);
    //cv::imshow("save2", img_OR);
    //print(img1.size);
    //print(img2.size);
    cv::Size(img1.rows, img1.cols);
    std::cout<<img1.rows<<" "<<img1.cols;
    std::cout<<img2.rows<<" "<<img2.cols;
    cv::cvtColor(img1, img1, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img2, img2, cv::COLOR_BGR2GRAY);
    cv::bitwise_or(img1, img2,img_OR);
    cv::imshow("save2", img_OR);
    cv::imshow("save2", img1);
    cv::waitKey(0);
    cv::imwrite("output.png", img_OR);
    return 0;
}