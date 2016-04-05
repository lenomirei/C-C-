//
// 1.实现以下几个类的成员函数
// 2.实现一个虚函数的覆盖及调用
// 3.处理菱形继承问题。
//

// 植物
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
	string _name;		//名字
};

class Tree : public Botany
{
public:
	//...实现默认的成员函数
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
	int _hight;		// 高度
};

class Flower : public Botany
{
public:
	//...实现默认的成员函数
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
	int _colour;	// 颜色
};

// 白兰花，既是树又是花。
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
