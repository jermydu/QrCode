

#include "BarcodeFormat.h"
#include "MultiFormatWriter.h"
#include "BitMatrix.h"
#include "ByteMatrix.h"
#include "TextUtfEncoding.h"
#include "ZXStrConvWorkaround.h"

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
using namespace ZXing;

#include<opencv2/opencv.hpp>  
using namespace cv;


static inline std::string GetExtension(const std::string& path)
{
	auto fileNameStart = path.find_last_of("/\\");
	auto fileName = fileNameStart == std::string::npos ? path : path.substr(fileNameStart + 1);
	auto extStart = fileName.find_last_of('.');
	auto ext = extStart == std::string::npos ? "" : fileName.substr(extStart + 1);
	std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return std::tolower(c); });
	return ext;
}

static inline void AddLogoToQRCodeImage(const std::string pngPath, const std::string logoPath)
{
	Mat srcQRCode = imread(pngPath);
	Mat srcLogo = imread(logoPath);
	Mat imageRoi = srcQRCode(Rect(srcQRCode.cols / 2 - srcLogo.cols / 2, srcQRCode.rows / 2 - srcLogo.rows / 2, srcLogo.cols, srcLogo.rows));
	Mat mask = imread(logoPath, 0);
	srcLogo.copyTo(imageRoi, mask);

	imwrite(pngPath, srcQRCode);
}

int main(int argc, char* argv[])
{
	int width = 500, height = 500;
	int margin = 10;    //空白
	int eccLevel = 8;	//纠错级别
	std::string format = "QR_CODE";
	std::string text = " {\"data\" : \"www.baidu.com\",\"type\" : \"1\"} ";
	std::string filePath = "./QrCode.png";
	std::string logoPath = "./logo.png";
	try {
		auto barcodeFormat = BarcodeFormatFromString(format);
		if (barcodeFormat == BarcodeFormat::FORMAT_COUNT)
			throw std::invalid_argument("Unsupported format: " + format);

		MultiFormatWriter writer(barcodeFormat);
		if (margin >= 0)
			writer.setMargin(margin);
		if (eccLevel >= 0)
			writer.setEccLevel(eccLevel);

		auto bitmap = writer.encode(TextUtfEncoding::FromUtf8(text), width, height).toByteMatrix();

		auto ext = GetExtension(filePath);
		int success = 0;
		if (ext == "" || ext == "png") {
			success = stbi_write_png(filePath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		}
		else if (ext == "jpg" || ext == "jpeg") {
			success = stbi_write_jpg(filePath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		}

		if (!success) {
			std::cerr << "Failed to write image: " << filePath << std::endl;
			return -1;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}

	AddLogoToQRCodeImage(filePath, logoPath);
	return 0;
}
