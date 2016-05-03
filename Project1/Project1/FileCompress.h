#include"HuffmanTree.h"

extern vector<HuffmanTreeNode*> _leafVec;	//Ҷ�ӽڵ㱣��


class FileCompress
{
public:
	FileCompress()
	{}
	bool Compress(const char * filename)
	{
		static int chCountBuff[256] = { 0 };
		memset(chCountBuff, 0, 256);

		//����ͳ��
		InitCountArr(filename, chCountBuff);

		//EOF��ȡ
		HuffmanTreeNode* pEOF = _ht.SetHuffmanTree(chCountBuff);
		_EOF = _ht.GetCode(pEOF);

		//������Ч����
		for (int i = 0; i < _leafVec.size(); ++i)
		{
			_code[_leafVec[i]->_data] = _ht.GetCode(_leafVec[i]);
		}

		//�����ļ�����
		string configName = filename;
		configName += "config";
		ofstream ofsConfig(configName, ios::out);
		for (int i = 0; i < _leafVec.size(); ++i)
		{
			ofsConfig << _leafVec[i]->_data << ',';
			ofsConfig << chCountBuff[_leafVec[i]->_data] << endl;
		}
		ofsConfig.close();

		//ѹ���ļ���ʼ
		string outFile = filename;
		outFile += ".Compress";

		char codeBuff = 0;
		ofstream ofs(outFile.c_str(), ios::out);

		ifstream ifs(filename, ios::in);
		char c = ifs.get();
		
		int bytes = 8;
		while (ifs.good()) {
//			cout << c;
			///����ѹ��
			for (int i = 0; i < _code[c].size(); ++i)
			{
				--bytes;
				if (_code[c][i] == '1')
					codeBuff |= (1<<bytes);

				if (bytes == 0)
				{
					//д��codeBuff
					ofs.put(codeBuff);
					codeBuff = 0;
					bytes = 8;
				}
			}
			c = ifs.get();
		}
		//д��EOF
		for (int i = 0; i < _EOF.size(); ++i)
		{
			--bytes;
			if (_EOF[i] == '1')
				codeBuff |= (1 << bytes);

			if (bytes == 0)
			{
				//д��codeBuff
				ofs.put(codeBuff);
				codeBuff = 0;
				bytes = 8;
			}
		}
		ofs.put(codeBuff);

//		Print();
		_ht.Show();
		_ht.clear();
		_leafVec.clear();
		ifs.close();
		ofs.close();
		return true;
	}

	static bool UnCompress(const char *filename)
	{
		static int chCountBuff[256] = { 0 };
		memset(chCountBuff, 0, 256);

		//��ȡ�ļ����ؽ�HuffmanTree
		string fileConfig = filename;
		fileConfig += "config";
		ifstream ifsConfig(fileConfig, ios::in);
		char chIn = ifsConfig.get();
		while (ifsConfig.good())
		{
			char c = ifsConfig.get();
			ifsConfig >> chCountBuff[chIn];
//			cout << chIn << "  "<< chCountBuff[chIn] << endl;
			c = ifsConfig.get();
			chIn = ifsConfig.get();
		}
		ifsConfig.close();
		//EOF��ȡ
		HuffmanTreeNode* pEOF = _ht.SetHuffmanTree(chCountBuff);
		for (int i = 0; i < _leafVec.size(); ++i)
		{
			_code[_leafVec[i]->_data] = _ht.GetCode(_leafVec[i]);
		}

		Print();
		_ht.Show();
		//����
		string UnCompressFile = filename;
		UnCompressFile += ".Compress";

		ifstream ifs(UnCompressFile.c_str(), ios::in);

		string finallyFile = filename;
		finallyFile += "final";
		ofstream ofs(finallyFile, ios::out);
		
		char codeBuff = 0;
		//��ȡһ���ַ�
		codeBuff = ifs.get();
		int bytes = 8;

		HuffmanTreeNode* cur = _ht.getRoot();

		while (1) 
		{
			--bytes;

			//�����Ҷ�ӽ��
			if (cur->_left == cur->_right&& cur->_left == NULL)
			{
				if (cur == pEOF)
				{
					break;
				}
				ofs.put(cur->_data);
				cout << cur->_data;
				cur = _ht.getRoot();
			}

			if ((codeBuff&(1 << bytes)) == 0)
			{
				//����
				cur = cur->_left;
			}
			else
			{
				//��
				cur = cur->_right;
			}

			if (bytes == 0)
			{
				codeBuff = 0;
				codeBuff = ifs.get();
				bytes = 8;
			}
		}

		_leafVec.clear();
		_ht.clear();
		_code.clear();

		ifs.close();
		ofs.close();
		return true;
	}

protected:

	//�ļ����ַ�����ͳ��
	static bool InitCountArr(const char* filename, int *chCount)
	{
		//��¼����
		ifstream ifs(filename, ios::in);
		char c = ifs.get();
		while (ifs.good()) {
			chCount[c]++;
			c = ifs.get();
		}
		ifs.close();
		return true;
	}


	static void Print()
	{
		for (int i = 0; i < _leafVec.size(); ++i)
		{
			cout << "[" << _leafVec[i]->_data << "]" << _code[_leafVec[i]->_data].c_str() << endl;
		}
		cout << "[EOF]" << _EOF.c_str() << endl;
	}
private:
	static HuffmanTree _ht;
	static hash_map<char, string> _code;
	static string _EOF;
};
HuffmanTree FileCompress::_ht = HuffmanTree();
hash_map<char, string> FileCompress::_code = hash_map<char,string>();
string FileCompress::_EOF = string();

//struct CodeMap
//{
//protected:
//	CodeMap(){}
//protected:
//	//��ֵ�ԣ�key-value;
//	//static hash_map<char, string> _code;
//	static hash_map<char, BitMap> _code;
//	static BitMap _EOF;
//
//	//����֮����
//	static HuffmanTree _ht;
//
//	//static void InitCodeMap(const char *arr, int n)
//	static void InitCodeMap(const char*filename)
//	{
//		//����HuffmanTree���б���
//		//HuffmanTreeNode * eof = _ht.SetHuffmanTree(arr, n);
//		HuffmanTreeNode * eof = _ht.SetHuffmanTree(filename);
//
//		int arrI[1] = { 1 };
//		int arrII[1] = { 0 };
//		for (int i = 0; i < _ht._leafVec.size(); ++i)
//		{
//			HuffmanTreeNode* cur = _ht._leafVec[i];
//
//			stack<int> stBit;
//			while (cur != _ht._root)
//			{
//				if (cur == cur->_parent->_left)
//				{
//					//_code[_ht._leafVec[i]->_data].append(1, '0');
//					_code[_ht._leafVec[i]->_data].append(arrII, 1);
//					//	stBit.push(1);
//				}
//				else if (cur == cur->_parent->_right)
//				{
//					//_code[_ht._leafVec[i]->_data].append(1, '1');
//					_code[_ht._leafVec[i]->_data].append(arrI, 1);
//					//		stBit.push(0);
//				}
//				cur = cur->_parent;
//			}
//			//while (!stBit.empty())
//			//{
//			//	_code[_ht._leafVec[i]->_data].append(stBit.top());
//			//	stBit.pop();
//			//}
//		}
//
//		//���뷭ת����
//		_EOF = _code[eof->_data];
//		cout << "_EOF->";
//		_EOF.PrintByte();
//	}
//
//	virtual void ShowCode()
//	{
//		hash_map<char, BitMap>::iterator it = _code.begin();
//		hash_map<char, BitMap>::iterator itEnd = _code.end();
//
//		cout << "Start::" << endl;
//		while (it != itEnd)
//		{
//			cout << "[" << ((*it).first) << "]";
//			(*it).second.PrintByte();
//			++it;
//		}
//		cout << "Finish::" << endl;
//	}
//};
////hash_map<char, string> CodeMap::_code = hash_map<char, string>();
//hash_map<char, BitMap> CodeMap::_code = hash_map<char, BitMap>();
//BitMap CodeMap::_EOF = BitMap();
//HuffmanTree CodeMap::_ht = HuffmanTree();
//
////
//BitMap retMap;
//
//
//
//class Compress :protected CodeMap
//{
//public:
//	bool Encode(const char * filename)
//	{
//		//�������ݽ���huffmanTree,������ݶ�Ӧλ������Ϣ
//		InitCodeMap(filename);
//		ShowCode();
//		//���������ļ�
//		string confile = filename;
//		confile += ".Config";
//
//		ofstream conOfs(confile.c_str());
//		for (int i = 0; i < _ht._leafVec.size(); ++i)
//		{
//			//����ļ���Ϣ��
//			conOfs.put(_ht._leafVec[i]->_data);
//		}
//		conOfs.close();
//		//����ļ�
//
//		string Ofname = "Result.txt";
//		ofstream ofs(Ofname.c_str());
//
//		ifstream ifs(filename, ios::in);
//		char c = ifs.get();
//
//		//����ͳ��ƴ��
//		while (ifs.good())
//		{
//			retMap.Merge(_code[c]);
//			//���ơ������ұ�����
//			if (retMap._setv.size() > 100)
//			{
//				for (int i = 0; i < 100; ++i)
//				{
//					ofs.put(retMap._setv[i]);
//				}
//				for (int i = 100; i < retMap._setv.size(); ++i)
//				{
//					retMap._setv[i - 100] = retMap._setv[i];
//				}
//				retMap._setv.resize(retMap._size -= 100 * TYPE_SIZE);
//			}
//			c = ifs.get();
//		}
//
//		//����EOF
//		retMap.Merge(_EOF);
//
//		for (int i = 0; i < retMap._setv.size(); ++i)
//		{
//			ofs.put(retMap._setv[i]);
//			//	cout << retMap._setv[i];
//		}
//
//		cout << "��������";
//		retMap.PrintByte();
//		cout << retMap.size() << endl;
//		ofs.close();
//		ifs.close();
//		return true;
//	}
//
//	bool Decode()
//	{
//		cout << "Decoding" << endl;
//		HuffmanTreeNode* cur = _ht._root;
//		//for (int i = retMap._size; i >= 1; --i)
//		for (int i = 1; i <= retMap._size; ++i)
//		{
//			if (retMap.test(i))
//			{
//				if (cur->_right != NULL)
//					cur = cur->_right;
//				else
//				{
//					--i;
//					cout << cur->_data;
//					cur = _ht._root;
//				}
//			}
//			else
//			{
//				if (cur->_left != NULL)
//					cur = cur->_left;
//				else
//				{
//					--i;
//					cout << cur->_data;
//					cur = _ht._root;
//				}
//			}
//		}
//		if (cur->_left == cur->_right&&cur->_left == NULL)
//			cout << cur->_data << endl;
//	}
//
//
//
//
//	bool Decode(const char* filename)
//	{
//
//		string Ofname = "ret.txt";
//		ofstream ofs(Ofname.c_str());
//		cout << "Decoding" << endl;
//		HuffmanTreeNode* cur = _ht._root;
//		ifstream ifs(filename);
//
//		int i = 1;
//		while (1)
//		{
//			BitMap code;
//			while (cur->_left != NULL&&cur->_right != NULL)
//			{
//				if (retMap.test(i))
//				{
//					cur = cur->_right;
//					code.append(1);
//				}
//				else
//				{
//					cur = cur->_left;
//					code.append(0);
//				}
//				++i;
//			}
//			//����ֵ����root����
//			cout << cur->_data;
//			ofs.put(cur->_data);
//
//
//			cur = _ht._root;
//			code.revers();
//			if (code == _EOF)
//				return true;
//		}
//	}
//};