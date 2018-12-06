#include "Heap.h"
#include <stdio.h>
#include <assert.h>
//���ϵ�����

void _CheackCapacity(Heap* hp){
	assert(hp);
	if (hp->_size == hp->_capacity){
		hp->_array = realloc(hp->_array, hp->_capacity * 2 * sizeof(HDataType));
		assert(hp->_array);
		hp->_capacity *= 2;
	}
}
void HeapInsert(Heap* hp, HDataType data){
	//1.�Ƚ�Ԫ�ط������
	_CheackCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	//2.���ܻ��ƻ��ѵ����ʣ����ϵ���
	AdjustUp(hp->_size - 1, hp->_array, hp->_size);

}
//���ϵ�����
void AdjustUp(int child, HDataType* array, int size){
	int parent = (child - 1) >> 1;
	while (child){
		if (array[child] < array[parent]){
			HDataType* tmp = array[child];
			array[child] = array[parent];
			array[parent] = tmp;

			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}

void HeapErase(Heap* hp){
	//1.�Ƚ��Ѷ�Ԫ�ظ��ѵ����һ���ڵ㻥����Ȼ�����ϵ���
	if (HeapEmpty(hp)){
		return;
	}
	HDataType* tmp = hp->_array[0];
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_array[hp->_size - 1] = tmp;
	hp->_size -= 1;
	AdjustUp(0, hp->_array, hp->_size);
}




//���µ����ķ�ʽ
void AdjustDown(int root, int* array, int size){
	int parent = root;
	//child������Һ����н�С�ĺ��ӣ�Ĭ�����ӽ�С
	int child = parent * 2 + 1;
	

	while (child<size)//���Ӵ���
	{
		//�����������С�ĺ���
		if ((child+1<size)&&(array[child] > array[child + 1]))
			child = child + 1;
		//��˫������С�ĺ��ӱȽ�
		if (array[parent] > array[child])
		{
			HDataType* tmp = array[parent];
			array[parent] = array[child];
			array[child] = tmp;

			parent = child;
			child = parent * 2 + 1;

		}
		else
			return;
	}
}




void HeapInit(Heap* hp, int* array ,int size){
	assert(hp);
	//1.���ٿռ�
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (NULL == hp->_array)
	      exit(1);
	//2.�������е�Ԫ�ؿ������ѵĿռ���ȥ
	for ( int i = 0;  i < size;  i++)
	{ 
		 hp->_array[i] = array[i];
	}
    hp->_capacity =size ;
	hp->_size = size;
	//3.���е�������������ѵ�����
	//�ҵ�����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for  ( ;root>=0; --root)
	{
		AdjustDown(root, hp->_array, size);

	}
}
HDataType HeapTop(Heap* hp){
	return hp->_array[0];
}
int HeapSize(Heap* hp){
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp){ 
	assert(hp);
	return 0 == hp->_size;

}
void HeapDestory(Heap* hp){
	assert(hp);
	
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

 int main(){
	TestHeap();
	system("pause");
	return 0;
}
void TestHeap(){
	int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Heap hp;
	HeapInit(&hp,array,sizeof(array)/sizeof(array[0]));
	
	HeapDestory(&hp);
}