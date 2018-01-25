//
// Created by manout on 17-7-1.
//
#include "all_include.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#define use_filter2D
#define w   400

using std::cin;
using std::cout;
using std::endl;

//显示一个图像
int show_img(const string& file_path)
{
    cv::Mat img = cv::imread(file_path);
    if (img.empty())
        return -1;
    cv::namedWindow(file_path, CV_WINDOW_AUTOSIZE);
    cv::imshow(file_path, img);
    while(cv::waitKey(1000) not_eq 27);
    return 0;
}

//将图像转换为灰度图显示
int grey_img(const string& file_path)
{
    cv::Mat origin_img = cv::imread(file_path, cv::IMREAD_COLOR);
    if (origin_img.empty())
        return -1;
    cv::Mat grey_img;
    string grey_img_title = "grey_img";
    cv::namedWindow(file_path, cv::WINDOW_AUTOSIZE);
    cv::imshow(file_path, origin_img);
    cv::cvtColor(origin_img, grey_img, cv::COLOR_BGR2GRAY);

    cv::namedWindow(grey_img_title, CV_WINDOW_AUTOSIZE);
    cv::imshow(grey_img_title, grey_img);
    while(cv::waitKey(1000) not_eq 27);
    return 0;
}

int scan_img(const string& img_file)
{
    cv::Mat img = cv::imread(img_file);
    assert(not img_file.empty());
    assert(img.depth() == CV_8U);
    int channel = img.channels();
    // divide = 10　的时候图像变化不明显，加大到100才有明显的变化，可能是原图像的清晰度就不高吧
    int divide = 100;
    uchar table[256];
    for(int i = 0; i < 256; ++i)
    {
        table[i] = static_cast<uchar> (divide * (i / divide));
    }
    switch (channel)
    {
        case 1:
            for (cv::MatIterator_<uchar> it = img.begin<uchar>(); it not_eq img.end<uchar>(); ++it)
            {
                *it = table[*it];
            }
            break;

        case 3:
            for (cv::MatIterator_<cv::Vec3b> it = img.begin<cv::Vec3b>(); it not_eq img.end<cv::Vec3b>(); ++it)
            {
                (*it)[0] = table[(*it)[0]] ;
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];
            }
            break;
    }
    cv::namedWindow(img_file, cv::WINDOW_AUTOSIZE);
    cv::imshow(img_file, img);
    while(cv::waitKey(1000) not_eq 27);
    return 0;
}

//使用LUT函数转换一个矩阵
cv::Mat scan_img_LUT(const string& file_path)
{
    cv::Mat imgfile = cv::imread(file_path);
    cv::Mat ret;
    assert(not imgfile.empty());
    uchar table[256];
    int divide = 100;
    for (int i = 0; i < 256; ++i)
    {
        table[i] = static_cast<uchar>( divide * (i / divide) );
    }

    //一行，256列的行矩阵
    cv::Mat lookuptable(1, 256, CV_8U);
    uchar* p = lookuptable.ptr();
    for (int i = 0; i < 256; ++i, ++p)
    {
        *p = table[i];
    }

    cv::LUT(imgfile, lookuptable, ret);
    return ret;
}


//图片的对比增强算法，就是要对每个像素点使用以下公式
//
//      I(i, j) = 5 * I(i, j) - [I(i - 1, j) + I(i + 1, j) +  I(i, j - 1) + I(i, j + 1)]
//
cv::Mat sharpen(const cv::Mat& origin_img)
{
    assert(origin_img.depth() == CV_8U);    //只接受unchar图像

    const int channels= origin_img.channels();
    cv::Mat ret(origin_img.size(), origin_img.type());
#ifndef use_filter2D
    for (int i = 1; i < origin_img.rows - 1; ++i)
    {
        //cv::Mat::ptr(int i) 返回指向第i行的指针
        const uchar* previous  = origin_img.ptr(i - 1);
        const uchar* current   = origin_img.ptr(i);
        const uchar* next      = origin_img.ptr(i + 1);

        uchar * output         = ret.ptr(i);
        for (int j = channels; j < channels * (origin_img.cols - 1); ++j, ++output)
        {
            //channels 为一个像素的通道数，当前通道加上channels即为下一个像素该通道
            *output = static_cast<uchar> (5 * current[j] - current[j -channels] - current[j + channels]
                                            - previous[j] - next[j]);
        }
    }
#endif
#ifdef use_filter2D
    cv::Mat kernel;
    kernel = (cv::Mat_<uchar>(3, 3) << 0, -1, 0,
                                       -1, 5, -1,
                                        0, -1 , 0);

    //奇怪，使用filter2D结果与之前并不相同，是核函数的原因吗？
    cv::filter2D(origin_img, ret, origin_img.depth(), kernel);
#endif
    cv::Scalar sa(255, 255, 255);
    ret.row(0).setTo(sa);
    ret.row(ret.rows- 1).setTo(sa);
    ret.col(0).setTo(sa);
    ret.col(ret.cols - 1).setTo(sa);
    return ret;
}

//使用 cv::addWeighted()alpah融合两个图像，指定ROI区域只需获取原图像的一个矩形区域即可
void alpha_fusion(cv::Mat& img_1, cv::Mat& img_2)
{
    //因为Mat不显式复制时并不复制数据体，所以只需获取图像的一个子矩形区域便可得到原图像的ROI
    cv::Mat src_roi (img_2, cv::Rect(100, 100, img_1.rows, img_1.cols));
    cv::Mat ret;
    double alpha = 0.5;
    double beta  = 0.5;
    cv::addWeighted(img_1, alpha, src_roi, beta, 0, src_roi);
}


//调整图像的亮度和对比度
//常用的像素点运算为如下公式
/*
 *      G(x) = a * F(x) + b
 */
//其中 a 常被称为增益参数， b 常被成为偏置参数，同样可以表示成以下形式
/*
 *      G(i, j) = a * F(i, j) + b
 *      (i, j) 表示第 i 行，第 i 列
 */

//　alpha　　表示增益参数，简单对比度控制。
//  beta  　表示偏置参数，简单亮度控制
void change_contrast_bright(cv::Mat& img, double alpha, int beta)
{
    for (int i = 0; i < img.rows; ++i)
    {
        for (int j = 0; j < img.cols; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                img.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(alpha * img.at<cv::Vec3b>(i, j)[k] + beta);
            }
        }
    }
}


void MyEllipse(cv::Mat img, double angle)
{
    int thickness = 2;
    int lineType = 8;
    cv::ellipse(img, cv::Point(w / 2, w /2),cv::Size(w / 4, w / 16),
                angle, 0 ,360, cv::Scalar(255, 0, 0),
                thickness, lineType);

}

void MyFilledCircle(cv::Mat img, cv::Point center)
{
    //在图像的中心画一个半径为　w / 32，红色圆
    cv::circle(img, center, w /32, cv::Scalar(0, 0, 255), cv::FILLED);
}

//多边形
void MyPolygon( cv::Mat img )
{
    int lineType = cv::LINE_8;
    cv::Point rook_points[1][20];
    rook_points[0][0] = cv::Point(w / 4, 7 * w / 8);
    rook_points[0][1] = cv::Point(3 * w / 4, 7 * w / 8);
    rook_points[0][2] = cv::Point(3 * w / 4, 13 * w / 16);
    rook_points[0][3] = cv::Point(11 * w / 16, 13 * w / 16);
    rook_points[0][4] = cv::Point(19 * w / 32, 3 * w / 8);
    rook_points[0][5] = cv::Point(3 * w / 4, 3 * w / 8);
    rook_points[0][6] = cv::Point(3 * w / 4, w / 8);
    rook_points[0][7] = cv::Point(26 * w / 40, w / 8);
    rook_points[0][8] = cv::Point(26 * w / 40, w / 4);
    rook_points[0][9] = cv::Point(22 * w / 40, w / 4);
    rook_points[0][10] = cv::Point(22 * w / 40, w / 8);
    rook_points[0][11] = cv::Point(18 * w / 40, w / 8);
    rook_points[0][12] = cv::Point(18 * w / 40, w / 4);
    rook_points[0][13] = cv::Point(14 * w / 40, w / 4);
    rook_points[0][14] = cv::Point(14 * w / 40, w / 8);
    rook_points[0][15] = cv::Point(w / 4, w / 8);
    rook_points[0][16] = cv::Point(w / 4, 3 * w / 8);
    rook_points[0][17] = cv::Point(13 * w / 32, 3 * w / 8);
    rook_points[0][18] = cv::Point(5 * w / 16, 13 * w / 16);
    rook_points[0][19] = cv::Point(w / 4, 13 * w / 16);

    const cv::Point *ppt[1] = {rook_points[0]};
    int npt[] = {20};
    cv::fillPoly(img, ppt, npt, 1, cv::Scalar(255, 255, 255), lineType);
}

void MyLine(cv::Mat img, cv::Point start, cv::Point end)
{
    int thickness = 2;
    int lineType = cv::LINE_8;
    cv::line(img, start, end, cv::Scalar(0, 0 ,0 ),
             thickness, lineType);
}

void show_atom()
{
    string atom_window("Drawing 1: Atom");
    cv::Mat atom_img = cv::Mat::zeros(w, w, CV_8UC3);
    MyEllipse(atom_img, 90);
    MyEllipse(atom_img, 0);
    MyEllipse(atom_img, 45);
    MyEllipse(atom_img, -45);

    MyFilledCircle(atom_img, cv::Point(w / 2, w / 2));

    cv::namedWindow(atom_window, cv::WINDOW_AUTOSIZE);
    cv::imshow(atom_window, atom_img);
}


void show_rook()
{
    string rook_window("Drawing 2: Rook");
    cv::Mat rook_img = cv::Mat::zeros(w, w, CV_8UC3);
    MyPolygon(rook_img);
    cv::rectangle(rook_img, cv::Point(0, 7 * w / 8), cv::Point(w, w),
                  cv::Scalar(0, 255, 255), cv::FILLED, cv::LINE_8);
    MyLine(rook_img, cv::Point(0, 15 * w / 16), cv::Point(w, 15 * w / 16));
    MyLine(rook_img, cv::Point(w / 4, 7 * w /8), cv::Point(w / 4, w));
    MyLine(rook_img, cv::Point(w / 2, 7 * w / 8), cv::Point(w / 2, w));
    MyLine(rook_img, cv::Point(3 * w /4, 7 * w / 8), cv::Point(3 * w / 4, w));

    cv::namedWindow(rook_window, cv::WINDOW_AUTOSIZE);
    cv::imshow(rook_window, rook_img);
}