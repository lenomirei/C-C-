#include"FileCompress.h"
#include"HuffmanTree.h"

int main()
{
	FileCompress fc;
	fc.Compress("Test.txt");
	fc.UnCompress("Test.txt");
}

//int main()
//{
//	//①遍历文件，进行编码确定---建立Huffmantree---生成编码表格
//	//②文件压缩：根据编码，读取文件同时压缩处理
//	Compress cp;
//	cp.Encode("test.txt");
//	cp.Decode("Result.txt");
//	//Decode()(3);
//	//③文件解压：读取字节流，遍历HuffmanTree进行还原处理
//	system("pause");
//	return 0;
//}
