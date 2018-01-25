//
// Created by manout on 17-7-6.
//

#include "all_include.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


#define KERNEL_SIZE     cv::Size(7, 7)
void show_blur(cv::Mat& src, const string& name)
{
    cv::Mat dst = src.clone();
    cv::blur(src, dst, KERNEL_SIZE);
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, dst);
    while(cv::waitKey(100) not_eq 27);
}

void show_gaussian(cv::Mat& src , const string& name)
{
    cv::Mat dst = src.clone();
    cv::GaussianBlur(src, dst, KERNEL_SIZE,0);
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, dst);
    while(cv::waitKey(100) not_eq 27);
}

void show_median(cv::Mat& src, const string& name)
{
    cv::Mat dst = src.clone();
    cv::medianBlur(src, dst, 7);
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, dst);
    while(cv::waitKey(100) not_eq 27);
}

void show_bilateral(cv::Mat& src, const string& name)
{
    cv::Mat dst = src.clone();
    cv::bilateralFilter(src, dst, 7, 14, 3);
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, dst);
    while(cv::waitKey(100) not_eq 27);
}


// 提取图像中笔记部分(也可以称为去掉水平线)
cv::Mat extract_content(cv::Mat img)
{
    assert(img.data);

    string window_name(R"-(result)-");
    cv::Mat gray;
    //将图像转化为灰度图
    if(img.channels() == 3)
    {
        cv::cvtColor(img, gray, CV_BGR2GRAY);
    }
    else
    {
        gray = img.clone();
    }
    cv::Mat bw;
    // 经过测试，当 blockSize　= 15 时效果最好，默认值结果过于纤细
    cv::adaptiveThreshold(~gray, bw, 255, CV_ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);
    cv::Mat vertical = bw.clone();
    //　以下是提取水平线的内容
   /*
    //对　gray　的　bitwise_not 采用自适应阀值化，块的大小为　15 * 15, 采用　CV_ADAPTIVE_THRESH_MEAN_C 表示在邻域内平均加权
    // 然后参考点的取值为　加权平均后　+ 2 (- (-2))
    cv::adaptiveThreshold(~gray, img, 255, CV_ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);
    cv::Mat horizontal = img.clone();
    cv::Mat vertical   = img.clone();

    int horizontal_size = horizontal.cols / 30;

    //　创建一个提取水平线的结构化元素
    cv::Mat horizontal_structure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(horizontal_size, 1));

    // 如果是在黑暗前景中提取明亮物体，那么应该先腐蚀在膨胀
    // 如果是在明亮前景中提取黑色物体，那么应该先膨胀在腐蚀
    cv::erode(horizontal, horizontal, horizontal_structure);
    cv::dilate(horizontal, horizontal, horizontal_structure);

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    cv::imshow(window_name, horizontal);
    while(cv::waitKey(100) not_eq 27);
*/
    int vertical_size = vertical.rows / 30;
    cv::Mat vertical_structure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, vertical_size));

    // 内核是竖直形状，细长的水平线会在腐蚀时被腐蚀掉
    /*
    cv::erode(vertical, vertical, vertical_structure);
    cv::dilate(vertical, vertical, vertical_structure);
    */
    // 先腐蚀在膨胀可以用开运算代替
    cv::morphologyEx(vertical, vertical,cv::MORPH_OPEN ,vertical_structure );

    //　接下来是平滑图像
    // 将 vertical　逐位取反
    cv::bitwise_not(vertical, vertical);
    cv::Mat edge;
    cv::adaptiveThreshold(vertical, edge, 255, CV_ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 3, -2);

    cv::Mat kernel = cv::Mat::ones(2, 2, CV_8UC1);
    cv::dilate(edge, edge, kernel);
    //cv::imshow(window_name, edge);
    //while(cv::waitKey(100) not_eq 27);
    cv::Mat smooth;
    vertical.copyTo(smooth);
    cv::blur(smooth, smooth, cv::Size(2, 2));
    smooth.copyTo(vertical, edge);
    //cv::imshow(window_name, vertical);
    //while(cv::waitKey(100) not_eq 27);
    return vertical;
}


cv::Mat find_circle(cv::Mat img)
{
    cv::Mat ret, ret_grey;
    std::vector<cv::Vec3f> circles;
    cv::cvtColor(img, ret_grey, CV_BGR2GRAY);
    cv::medianBlur(ret_grey, ret, 5);
    cv::HoughCircles(ret,  circles, cv::HOUGH_GRADIENT, ret_grey.rows/16, 100, 30, 1, 30);
    for(size_t i  = 0; i < circles.size(); ++i)
    {
        cv::Vec3i c = circles[i];
        cv::circle(img, cv::Point(c[0], c[1]), c[2], cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
        cv::circle(img, cv::Point(c[0], c[1]), 2, cv::Scalar(0, 255, 0), 3, cv::LINE_AA);
    }
    return ret;
}

//　生成直方图
void generateHist(const cv::Mat& src, cv::Mat& dst)
{
    std::vector<cv::Mat> bgr_planes;
    cv::split(src, bgr_planes);

    // 直方图大小
    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true, accumulate = false;

    cv::Mat b_plane, g_plane, r_plane;

    cv::calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_plane, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_plane, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_plane, 1, &histSize, &histRange, uniform, accumulate);

    int histWidth = 256 * 2, histHeight = 400;
    int binWidth = cvRound(static_cast<double>(histWidth) / histSize);

    cv::Mat histImage(histHeight, histWidth, CV_8UC3, cv::Scalar(0, 0, 0));

    cv::normalize(b_plane, b_plane, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(g_plane, g_plane, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(r_plane, r_plane, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    for (int i = 1; i < histSize; ++i)
    {
        cv::line(histImage, cv::Point(binWidth * (i - 1), histHeight - cvRound(b_plane.at<float>(i - 1))),
                            cv::Point(binWidth * i, histHeight - cvRound(b_plane.at<float>(i))),
                            cv::Scalar(255, 0, 0), 2, 8, 0);
        cv::line(histImage, cv::Point(binWidth * (i - 1), histHeight - cvRound(g_plane.at<float>(i - 1))),
                            cv::Point(binWidth * i, histHeight - cvRound(g_plane.at<float>(i))),
                            cv::Scalar(0, 255, 0), 2, 8, 0);
        cv::line(histImage, cv::Point(binWidth * (i - 1), histHeight - cvRound(r_plane.at<float>(i - 1))),
                            cv::Point(binWidth * i, histHeight - cvRound(r_plane.at<float>(i))),
                            cv::Scalar(0, 0, 255), 2, 8, 0);
    }
    dst = histImage;
}