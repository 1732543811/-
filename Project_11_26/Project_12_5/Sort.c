#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;

}
void HeapAdjust(int* array, int size, int parent)
{
	int child = (parent << 1) + 1;
	while (child < size)
	{
		//找出左右孩子中的最大孩子
		if (child + 1 && array[child] < array[child + 1])
			child = child + 1;
		//判断双亲跟孩子哪个大
		if (array[parent] < array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
			return;

	}
}
void PrintArray(int* array, int size)
{
	for (int  i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int Pation1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin<end)
	{ 
		//从前往后找比基准值小的元素
		while (begin<end&&array[begin]<=key)
		{
			begin++;
		}
		//找比基准值大的元素
		while (begin<end&&array[end]>=key)
		{
			end--;
		}
		//交换begin跟end的值
		if (begin<end)
			Swap(&array[begin], &array[end]);

		//如果begin每到end的位置，交换begin跟最后一个数的位置
		
	}
	//出了循环，end跟begin走到一起了，
	//让right-1走到begin的位置，
	//至此，key左边的就是小于key的，右边的都大于key
	Swap(&array[begin], &array[right - 1]);
	return begin;
}
void QuietSort(int* array,int left, int right)
{
	if (right-left > 1)
	{
		//先划分区间
		int div = Pation1(array, left, right);
		QuietSort(array, left, div);
		QuietSort(array, div + 1, right);
	}
}

//1.插入排序
void InsertSort(int* array, int size)
{
	for (int  i = 1; i < size; i++)
	{
		//从第二元素开始往排好之后的元素插入
		int key = array[i];
		int end = i - 1;
		while (end>=0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--; 
			//让end向前走一直比,可能会出现end不存在,
			//所以在条件里规定一下
		}
		//让key走到end+1的位置
		array[end + 1] = key;
	}

}

//2.希尔排序
void ShellSort(int* array, int size)
{
	int gap = size;
	while (gap){
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
			//i++是因为不同的组交替排列,不要误写成i=i+gap
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			//此时的end为负值,要插到刚刚比较的前一个
			array[end + gap] = key;
		}
		gap--;

	}
}


//3.选择排序
void SelectSort(int* array, int size)
{
	//选择的趟数
	for (int i = 0; i < size - 1; i++)
	{
		//选择的方式
		int maxPos = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		if (maxPos != size - 1 - i)
			//判断maxPos是不是最后一个,如果是就不用交换
			Swap(&array[maxPos], &array[size - 1 - i]);
	}
}

//4.选择排序优化
void SelectSortOP(int* array, int size){
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] < array[min])
				min = index;

			if (array[index]>array[max])
				max = index;
			index++;
		}
		if (min != 0)
			Swap(&array[min], &array[begin]);
		if (max!=end)
			Swap(&array[max], &array[end]);
		begin++;
		end--;
	}
}

//5.堆排序
void HeapSort(int* array, int size)
{
	//1.建堆
	int root = (size - 2) >> 1;
	for (; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	//2.堆排序
	int end = size - 1;
	while (end)
	{
		//删除法排序
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

//6.冒泡排序
void BubbleSort(int* array, int size)
{
  
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{

			if (array[j - 1]>array[j])
				Swap(&array[j - 1], &array[j]);
		}
	}
}

