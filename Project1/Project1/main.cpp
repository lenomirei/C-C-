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
//	//�ٱ����ļ������б���ȷ��---����Huffmantree---���ɱ�����
//	//���ļ�ѹ�������ݱ��룬��ȡ�ļ�ͬʱѹ������
//	Compress cp;
//	cp.Encode("test.txt");
//	cp.Decode("Result.txt");
//	//Decode()(3);
//	//���ļ���ѹ����ȡ�ֽ���������HuffmanTree���л�ԭ����
//	system("pause");
//	return 0;
//}
