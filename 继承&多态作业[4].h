//
// 1.ʵ�����¼�����ĳ�Ա����
// 2.ʵ��һ���麯���ĸ��Ǽ�����
// 3.�������μ̳����⡣
//

// ֲ��
class Botany
{
public:
	Botany(string & name)
		:_name(name)
	{
		++_sCount;
	}
	virtual ~Botany()
	{
		delete[] _name;
		cout << "Botany::~Botany()" << endl;
	}
	virtual void Display()
	{

	}

protected:
	string _name;		//����
};

class Tree : public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����
	Tree(string &name,int hight)
		:Botany(name)
		,_hight(hight)
	{
	}
	virtual ~Tree()
	{
		cout << "Tree::Tree()" << endl;
	}
protected:
	int _hight;		// �߶�
};

class Flower : public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����
	Flower(string &name, int colour)
		:Botany(name)
		,_colour(colour)
	{

	}
	virtual ~Flower()
	{
		cout << "Flower::~Flower()" << endl;
	}
protected:
	int _colour;	// ��ɫ
};

// �����������������ǻ���
class MicheliaAlba : public Flower, public Tree
{
protected:
	// ...
	MicheliaAlba(string &name,int hight,int colour)
		:Botany(name)
		,Tree(hight)
		,Flower(colour)
	{

	}
	virtual ~MicheliaAlba()
	{
		cout << "MicheliaAlba::~MicheliaAlba()" << endl;
	}
};
