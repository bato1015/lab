#include<iostream>
#include <opencv2/opencv.hpp>
#include<fstream>

int main(){
    cv::Mat img1 = cv::imread("../0.png");
    cv::Mat img2 = cv::imread("../all20.0.png");
    cv::Mat img3 = cv::imread("../shindokaku1.png");
    std::ofstream ifs("../output.txt",std::ios_base::out | std::ios_base::binary);
    std::ofstream ifs1("../shindokaku.txt",std::ios_base::out | std::ios_base::binary);
    cv::Mat img_OR;

    double far=5.0;
    double near=0.01;

    double far_t,near_t;

    cv::bitwise_and(img1, img2,img_OR);
    cv::imshow("save2", img_OR);
    //cv::imshow("save2", img1);
    cv::waitKey(0);
    cv::imwrite("../output.png", img_OR);

    far_t=1/far;
    near_t=1/near;

    for (int v = 0; v < img2.size().height; v++) {
        for (int u = 0; u < img2.size().width; u++) {
             cv::Vec3b &p = img1.at<cv::Vec3b>(v,u);
            ifs<<(int)p[2];
            if(v<img2.size().height-2)
                ifs<<"\n";
        }
        ifs<<std::endl;
    }
    for (int v = 0; v < img2.size().height; v++) {
        for (int u = 0; u < img2.size().width; u++) {
             cv::Vec3b &p = img3.at<cv::Vec3b>(v,u);
             if((int)p[2]==0)
                ifs1<<0;
            else{
            //ifs1<<(4.99)*(255-(int)p[2])/255+0.01<<",";  先生相談前
            //ifs1<<1/((far_t-near_t)*(int)p[2]/255+near_t)<<",";
            //ifs1<<(p[2]-near_t)*255*1/(far_t-near_t)<<",";//先生相談後
            ifs1<<4.9-((256-(int)p[2])*(5-0.01)/256);
            //ifs1<<(int)p[2];

            }
        if(u <(img2.size().width-1))
                ifs1<<" ";
        }
        
        ifs1<<std::endl;
    }
    ifs.close();
    ifs1.close();

    return 0;
}