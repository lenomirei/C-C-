//#include"Huffman.h"
//
//
//int main()
//{
//	
//	char a[10] = { 'q','g','b','a','h','d','a','c','z','a' };
//	HuffmanTree<char> h1(a, 10);
//	vector<string> code = h1.HuffmanCode(a, 10);
//	BitMap bt;
//	int index = 0;
//	for (int i = 0; i < code.size(); ++i)
//	{
//		for (int j = 0; j < code[i].size(); ++j)
//		{
//			bt.Set(code[i][j] - '0', index);
//			index++;
//		}
//	}
//	return 0;
//}


#include"FileCompress.h"


int main()
{
	TestFileCompress();
	return 0;
}