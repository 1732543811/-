#include "Heap.h"
#include <stdio.h>
#include <assert.h>
//向上调整法

void _CheackCapacity(Heap* hp){
	assert(hp);
	if (hp->_size == hp->_capacity){
		hp->_array = realloc(hp->_array, hp->_capacity * 2 * sizeof(HDataType));
		assert(hp->_array);
		hp->_capacity *= 2;
	}
}
void HeapInsert(Heap* hp, HDataType data){
	//1.先将元素放入堆中
	_CheackCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	//2.可能会破坏堆的性质，向上调整
	AdjustUp(hp->_size - 1, hp->_array, hp->_size);

}
//向上调整法
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
	//1.先将堆顶元素跟堆的最后一个节点互换，然后向上调整
	if (HeapEmpty(hp)){
		return;
	}
	HDataType* tmp = hp->_array[0];
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_array[hp->_size - 1] = tmp;
	hp->_size -= 1;
	AdjustUp(0, hp->_array, hp->_size);
}




//向下调整的方式
void AdjustDown(int root, int* array, int size){
	int parent = root;
	//child标记左右孩子中较小的孩子，默认左孩子较小
	int child = parent * 2 + 1;
	

	while (child<size)//左孩子存在
	{
		//找最后孩子中最小的孩子
		if ((child+1<size)&&(array[child] > array[child + 1]))
			child = child + 1;
		//将双亲与最小的孩子比较
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
	//1.开辟空间
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (NULL == hp->_array)
	      exit(1);
	//2.将数组中的元素拷贝到堆的空间中去
	for ( int i = 0;  i < size;  i++)
	{ 
		 hp->_array[i] = array[i];
	}
    hp->_capacity =size ;
	hp->_size = size;
	//3.进行调整，让其满足堆的性质
	//找倒数第一个非叶子节点
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