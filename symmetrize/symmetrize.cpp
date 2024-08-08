#include "symmetrize.h"
#include <iostream>

std::string symmetrize(std::string img_path, char flag)
{
    // 读取图片
    cv::Mat img{cv::imread(img_path)};
    if (img.empty())
    {
        std::cout << "Image load failed!" << std::endl;
        exit(-1);
    }

    int height{img.rows}; // 图片高度
    int width{img.cols};  // 图片宽度
    int flip_code{1};     // 翻转方式，0 代表上下翻转，1 代表左右翻转

    cv::Rect source, dest;
    switch (flag)
    {
    case 'L': // 左半部分水平翻转覆盖右半部分
        source = cv::Rect(0, 0, width / 2, height);
        dest = cv::Rect(width / 2, 0, width / 2, height);
        flip_code = 1;
        break;
    case 'R': // 右半部分水平翻转覆盖左半部分
        source = cv::Rect(width / 2, 0, width / 2, height);
        dest = cv::Rect(0, 0, width / 2, height);
        flip_code = 1;
        break;
    case 'T': // 上半部分垂直翻转覆盖下半部分
        source = cv::Rect(0, 0, width, height / 2);
        dest = cv::Rect(0, height / 2, width, height / 2);
        flip_code = 0;
        break;
    case 'B': // 下半部分垂直翻转覆盖上半部分
        source = cv::Rect(0, height / 2, width, height / 2);
        dest = cv::Rect(0, 0, width, height / 2);
        flip_code = 0;
        break;
    default:
        break;
    }

    // 将原图片的半部分图片翻转
    cv::Mat half{img(source)};
    cv::Mat flip_half;
    cv::flip(half, flip_half, flip_code);

    flip_half.copyTo(img(dest)); // 翻转后的半部分图片覆盖原图片

    // 保存图片
    size_t index{img_path.find_last_of("/")};
    std::string img_dir{img_path.substr(0, index + 1)};
    std::string img_name{img_path.substr(index + 1)};
    std::string result_name{img_dir + "result_" + img_name};
    cv::imwrite(result_name, img);
    return result_name;
}