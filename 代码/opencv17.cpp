//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//typedef struct _imgPair {
//	Mat* src;
//	Mat* dst;
//	void* Param;
//	string winName;
//}ImgPair;
//
//typedef struct _gaussianParam {
//	int kernelSize;
//	int sigma;
//}GaussianParam;//gaussianParam高斯参数
//
//typedef struct _bilateralParam {
//	int kernelSize;
//	int sigmaColor;
//	int sigmaSpace;
//}BilateralParam;//双边参数
//
//void on_gaussiankernelBar(int ksize, void* userdata)
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//	GaussianParam* gPair = (GaussianParam*)(pImgPair->Param);
//	gPair->kernelSize = ksize;
//
//	GaussianBlur(*(pImgPair->src), *(pImgPair->dst), Size(gPair->kernelSize / 2 * 2 + 1, gPair->kernelSize / 2 * 2 + 1), gPair->sigma, gPair->sigma);
//	imshow(pImgPair->winName, *(pImgPair->dst));
//}
//
//
//void on_gaussianSigmaBar(int sigma, void* userdata)//高斯滤波器
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//	GaussianParam* gPair = (GaussianParam*)(pImgPair->Param);
//	gPair->sigma = double(sigma);
//
//	GaussianBlur(*(pImgPair->src), *(pImgPair->dst), Size(gPair->kernelSize / 2 * 2 + 1, gPair->kernelSize / 2 * 2 + 1), gPair->sigma, gPair->sigma);
//	imshow(pImgPair->winName, *(pImgPair->dst));
//}
//
//
//
//
//void on_medianSigmaBar(int ksize, void* userdata)//中值滤波器
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//
//	medianBlur(*(pImgPair->src), *(pImgPair->dst), ksize / 2 * 2 + 1);
//	imshow(pImgPair->winName, *(pImgPair->dst));
//
//}
//
//
//void on_bilateralDBar(int ksize, void* userdata)//双边滤波器
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//	BilateralParam* param = (BilateralParam*)(pImgPair->Param);
//	bilateralFilter(*(pImgPair->src), *(pImgPair->dst), ksize / 2 * 2 + 1, param->sigmaColor, param->sigmaSpace);
//	param->kernelSize = ksize;
//	imshow(pImgPair->winName, *(pImgPair->dst));
//
//}
//
//
//
//void on_bilateralSigmaSpaceBar(int sigmaSpace, void* userdata)
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//	BilateralParam* param = (BilateralParam*)(pImgPair->Param);
//	bilateralFilter(*(pImgPair->src), *(pImgPair->dst), param->kernelSize / 2 * 2 + 1, param->sigmaColor, sigmaSpace);
//	param->sigmaSpace = sigmaSpace;
//	imshow(pImgPair->winName, *(pImgPair->dst));
//}
//
//void on_bilateralSigmaColorBar(int sigmaColor, void* userdata)
//{
//	ImgPair* pImgPair = (ImgPair*)userdata;
//	BilateralParam* param = (BilateralParam*)(pImgPair->Param);
//	bilateralFilter(*(pImgPair->src), *(pImgPair->dst), param->kernelSize / 2 * 2 + 1, sigmaColor, param->sigmaSpace);
//	param->sigmaColor = sigmaColor;
//	imshow(pImgPair->winName, *(pImgPair->dst));
//}
//
//
//int main()
//{
//	Mat src = imread("C:\\Users\\zxy\\Pictures\\opencv\\11.jpg");
//
//	namedWindow("src");
//	imshow("src", src);
//
//
//	/*-------GaussianBlur-----------*/
//	Mat GaussianBlurImg;
//	namedWindow("GaussianBlurImg");
//	GaussianParam gaussianParam = { 5, 1.0 };
//	GaussianBlur(src, GaussianBlurImg, Size(5, 5), 1, 1);
//	GaussianParam gparam = { 5, 1.0 };
//	ImgPair  gaussianPair = { &src, &GaussianBlurImg, &gparam,  "GaussianBlurImg" };
//
//	imshow("GaussianBlurImg", GaussianBlurImg);
//	createTrackbar("kernelsize", "GaussianBlurImg", &(gparam.kernelSize), 30, on_gaussiankernelBar, &gaussianPair);
//	createTrackbar("sigma", "GaussianBlurImg", &(gparam.kernelSize), 10, on_gaussianSigmaBar, &gaussianPair);
//
//	/*-------medianBlur-----------*/
//	Mat MedianBlurImg;
//	int kernelSize = 5;
//	ImgPair  medianPair = { &src, &MedianBlurImg, nullptr,  "MedianBlurImg" };
//	medianBlur(src, MedianBlurImg, 5);
//	imshow("MedianBlurImg", MedianBlurImg);
//	createTrackbar("kernelsize", "MedianBlurImg", &(kernelSize), 30, on_medianSigmaBar, &medianPair);
//
//
//	/*---Bilateral-----------------*/
//	Mat BilateralFilterImg;
//	bilateralFilter(src, BilateralFilterImg, 5, 2, 2);
//	BilateralParam bparam = { 5,1,1 };
//	ImgPair  bilateralPair = { &src, &BilateralFilterImg, &bparam,  "BilateralFilterImg" };
//	imshow("BilateralFilterImg", BilateralFilterImg);
//	createTrackbar("kernelsize", "BilateralFilterImg", &(bparam.kernelSize), 30, on_bilateralDBar, &bilateralPair);
//	createTrackbar("sigmaspace", "BilateralFilterImg", &(bparam.sigmaSpace), 30, on_bilateralSigmaSpaceBar, &bilateralPair);
//	createTrackbar("sigmacolor", "BilateralFilterImg", &(bparam.sigmaColor), 30, on_bilateralSigmaColorBar, &bilateralPair);
//	waitKey(0);
//}



//
// Created by yyy on 12/6/17.
//
#include <iostream>
using namespace std;
#include<fstream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv/cv.h>
#include<vector>
void drawLine(cv::Mat& mat, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        mat.at<int>(y1, i) = 1;
    }

}
void fillBottomFlatTriangle(cv::Mat& mat, cv::Point& v1, cv::Point& v2, cv::Point& v3) {
    float invslope1 = float(v2.x - v1.x) / float(v2.y - v1.y);
    float invslope2 = float(v3.x - v1.x) / float(v3.y - v1.y);

    float curx1 = v1.x;
    float curx2 = v1.x;

    for (int scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
    {
        drawLine(mat, (int)curx1, scanlineY, (int)curx2, scanlineY);
        curx1 += invslope1;
        curx2 += invslope2;
    }
}

void fillTopFlatTriangle(cv::Mat& mat, cv::Point& v1, cv::Point& v2, cv::Point& v3) {

    float invslope1 = float(v3.x - v1.x) / float(v3.y - v1.y);
    float invslope2 = float(v3.x - v2.x) / float(v3.y - v2.y);

    float curx1 = v3.x;
    float curx2 = v3.x;

    for (int scanlineY = v3.y; scanlineY > v1.y; scanlineY--)
    {
        drawLine(mat, (int)curx1, scanlineY, (int)curx2, scanlineY);
        curx1 -= invslope1;
        curx2 -= invslope2;
    }
}

void drawTriangle(cv::Mat& mat, std::vector<cv::Point>& triPts)
{
    /* at first sort the three vertices by y-coordinate ascending so v1 is the topmost vertice */
    std::sort(triPts.begin(), triPts.end(), [](cv::Point& p1, cv::Point& p2) {return (p1.y == p2.y) ? p1.x < p2.x : p1.y < p2.y; });
    cv::Point& v1 = triPts[0];
    cv::Point& v2 = triPts[1];
    cv::Point& v3 = triPts[2];

    /* here we know that v1.y <= v2.y <= v3.y */
    /* check for trivial case of bottom-flat triangle */
    if (v2.y == v3.y)
    {
        fillBottomFlatTriangle(mat, v1, v2, v3);
    }
    /* check for trivial case of top-flat triangle */
    else if (v1.y == v2.y)
    {
        fillTopFlatTriangle(mat, v1, v2, v3);
    }
    else
    {
        /* general case - split the triangle in a topflat and bottom-flat one */
        cv::Point v4(
            (int)(v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x)), v2.y);
        fillBottomFlatTriangle(mat, v1, v2, v4);
        fillTopFlatTriangle(mat, v2, v4, v3);
    }
}

int main()
{

    cv::Mat mm(30, 20, CV_32SC1, cv::Scalar(0));
    cv::Mat mmm(30, 20, CV_32SC1, cv::Scalar(0));
    std::vector<cv::Point> triPts2(3);
    triPts2[0] = (cv::Point(12, 2));
    triPts2[1] = (cv::Point(2, 9));
    triPts2[2] = (cv::Point(17, 29));
    drawTriangle(mm, triPts2);
    cv::fillConvexPoly(mmm, triPts2, cv::Scalar(1));   //opencv 光栅化
    std::cout << "\n";   std::cout << "\n";   std::cout << "\n";
    for (int i = 0; i < mm.rows; i++) {
        for (int j = 0; j < mm.cols; j++) {
            std::cout << mm.at<int>(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";   std::cout << "\n";
    std::cout << "\n";   std::cout << "\n";   std::cout << "\n";
    for (int i = 0; i < mmm.rows; i++) {
        for (int j = 0; j < mmm.cols; j++) {
            std::cout << mmm.at<int>(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";   std::cout << "\n";
    return 0;
}
