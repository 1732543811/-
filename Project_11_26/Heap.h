#pragma once

typedef int HDataType;

typedef struct Heap
{
	HDataType* _array;
	int _capacity;
	int _size;
}Heap;

void HeapInit(Heap* hp, int* array, int size);
void HeapInsert(Heap* hp, HDataType data);
void HeapErase(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapDestory(Heap* hp);
void TestHeap();
void AdjustUp(int child, HDataType* array, int size);
