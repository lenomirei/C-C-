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




void CopyComplexList(ComplexNode *pHead)//ʹ����֪��һЩ����
{
	ComplexNode *cur=pHead;
	while(cur)
	{
		Insert(cur,cur->_data);
		cur=cur->_next->_next;//�������ɹ�����֮��cur->_next�϶���Ϊ�գ����Բ�����ֶ�cur�Ŀ�ָ��ļ�ӷ���
	}
	while(cur)
	{
		cur->_next->_random=cur->_random->_next;
		cur=cur->_next->_next;
	}//Ȼ���ٰѸ��ƺõĽڵ�ȡ�����Ϳ�����
}