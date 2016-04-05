#include<string.h>
#include<assert.h>
#include<malloc.h>


typedef int DataType;
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode *_next;
	struct ComplexNode *_random;
}ComplexNode;




void CopyComplexList(ComplexNode *pHead)//使用已知的一些函数
{
	ComplexNode *cur=pHead;
	while(cur)
	{
		Insert(cur,cur->_data);
		cur=cur->_next->_next;//如果插入成功插入之后cur->_next肯定不为空，所以不会出现对cur的空指针的间接访问
	}
	while(cur)
	{
		cur->_next->_random=cur->_random->_next;
		cur=cur->_next->_next;
	}//然后再把复制好的节点取出来就可以了
}