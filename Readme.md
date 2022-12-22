# 一、环境工具准备
- VS2019
- Cmake
- zxing-cpp 源代码 [https://gitee.com/asalmc/zxing-cpp](https://gitee.com/asalmc/zxing-cpp)
- opencv4.2.0
# 二、zxing-cpp 编译
## 1. 源码目录下新建build文件夹存放构建目录
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671605784232-9e127030-99eb-472c-ace6-ca44c92c568e.png#averageHue=%23201e1c&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=279&id=uead410ed&margin=%5Bobject%20Object%5D&name=image.png&originHeight=279&originWidth=491&originalType=binary&ratio=1&rotation=0&showTitle=false&size=18838&status=done&style=none&taskId=u781508e1-25bd-405b-9d20-8ec5d08f8f8&title=&width=491)
## 2. 使用cmake编译源码
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671605936020-89f1a7a1-0b81-403b-9f6e-591cf1312f09.png#averageHue=%23f7d6d5&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=631&id=u79229bf2&margin=%5Bobject%20Object%5D&name=image.png&originHeight=631&originWidth=819&originalType=binary&ratio=1&rotation=0&showTitle=false&size=32015&status=done&style=none&taskId=u2a1c589e-e76d-4f3d-85c1-646659df742&title=&width=819)

1. 源码路径
2. 构建目录
3. 点击configure 选择 vs2019-》X64
4. 点击Generate 在build目录下生成VS工程

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671606067963-af385b2a-402e-4781-b9d1-3332fad8344b.png#averageHue=%23211f1d&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=474&id=u739e9ccd&margin=%5Bobject%20Object%5D&name=image.png&originHeight=474&originWidth=238&originalType=binary&ratio=1&rotation=0&showTitle=false&size=11376&status=done&style=none&taskId=u3387590b-4280-480d-8d7e-afa4e17185f&title=&width=238)

5. 用VS2019打开编译项目 生成lib库文件

`build\core\Debug\ZXingCore.lib`和 `build\core\Realse\ZXingCore.lib`
# 三、创建测试项目
## 1. VS2019创建控制台项目 `TestZXing`
## 2. 配置项目环境

1. 准备zxing-cpp 头文件和lib库
- 新建`include` 和 `lib`  
- zxing-cpp项目中找出头文件：`BarcodeFormat.h` `BitMatrix.h` `ByteMatrix.h` `CharacterSet.h` `MultiFormatWriter.h` `stb_image.h` `stb_image_write.h` `TextUtfEncoding.h` `ZXConfig.h` `ZXStrConvWorkaround.h`  
- zxing-cpp中拷贝出生成的lib库：`build\core\Debug\ZXingCore.lib`和 `build\core\Realse\ZXingCore.lib`

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671606998937-cf6b9c91-940e-4d45-8c46-85cfd9b0681b.png#averageHue=%231f1d1b&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=106&id=u3d1381d7&margin=%5Bobject%20Object%5D&name=image.png&originHeight=106&originWidth=176&originalType=binary&ratio=1&rotation=0&showTitle=false&size=1972&status=done&style=none&taskId=ubd851dbf-e1b3-4d8b-a6bb-10f539261bc&title=&width=176)

2. 准备opencv4.2.0 头文件、dll、lib

opencv4.2.0 开发环境这里不做记录，有兴趣网上查找
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671606977538-9a69e4b3-d2bb-4096-a087-35ab7d5f6371.png#averageHue=%23201e1b&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=123&id=ud4e4b45f&margin=%5Bobject%20Object%5D&name=image.png&originHeight=123&originWidth=182&originalType=binary&ratio=1&rotation=0&showTitle=false&size=2008&status=done&style=none&taskId=u2bc1c087-743e-42e0-9f61-4d556b12a33&title=&width=182)

3. 项目配置
- 头文件包含目录：右键-》属性-》C/C++-》常规-》附加包含目录

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671607230871-0a58e078-4a55-4943-8b7d-534ed8309358.png#averageHue=%23fbf1b7&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=140&id=u1d4f4b78&margin=%5Bobject%20Object%5D&name=image.png&originHeight=140&originWidth=235&originalType=binary&ratio=1&rotation=0&showTitle=false&size=3827&status=done&style=none&taskId=u0b2a0c87-fa5e-4afa-a9c3-56a9175a439&title=&width=235)

- lib库目录：右键-》属性-》链接器-》常规-》附加库目录

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671607361973-0967c506-8deb-4691-a23d-57f9eada6bcb.png#averageHue=%23fbf2b8&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=113&id=u34a51db0&margin=%5Bobject%20Object%5D&name=image.png&originHeight=113&originWidth=174&originalType=binary&ratio=1&rotation=0&showTitle=false&size=2727&status=done&style=none&taskId=u0017412b-0b51-40e3-89fb-78bd35934ca&title=&width=174)

- lib库：右键-》属性-》链接器-》输入-》附加依赖项

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671607440072-931a3b46-2129-4969-8c35-4ed01c36ce94.png#clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=133&id=uae311436&margin=%5Bobject%20Object%5D&name=image.png&originHeight=133&originWidth=165&originalType=binary&ratio=1&rotation=0&showTitle=false&size=3898&status=done&style=none&taskId=uc4006bbf-5acd-47be-8099-9bd697241a5&title=&width=165)
## 3. 编写测试代码
```cpp
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

```
# 四、最后展示效果
![QrCode.png](https://cdn.nlark.com/yuque/0/2022/png/29411390/1671608390735-3b9c8e2c-1bb9-4354-abfd-423842b841db.png#averageHue=%23969696&clientId=u23b55681-6263-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=500&id=u386ca6f8&margin=%5Bobject%20Object%5D&name=QrCode.png&originHeight=500&originWidth=500&originalType=binary&ratio=1&rotation=0&showTitle=false&size=24540&status=done&style=none&taskId=u30c8176b-cbcf-43e5-b496-050d4f8c37c&title=&width=500)
