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
		//�ҳ����Һ����е������
		if (child + 1 && array[child] < array[child + 1])
			child = child + 1;
		//�ж�˫�׸������ĸ���
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
		//��ǰ�����ұȻ�׼ֵС��Ԫ��
		while (begin<end&&array[begin]<=key)
		{
			begin++;
		}
		//�ұȻ�׼ֵ���Ԫ��
		while (begin<end&&array[end]>=key)
		{
			end--;
		}
		//����begin��end��ֵ
		if (begin<end)
			Swap(&array[begin], &array[end]);

		//���beginÿ��end��λ�ã�����begin�����һ������λ��
		
	}
	//����ѭ����end��begin�ߵ�һ���ˣ�
	//��right-1�ߵ�begin��λ�ã�
	//���ˣ�key��ߵľ���С��key�ģ��ұߵĶ�����key
	Swap(&array[begin], &array[right - 1]);
	return begin;
}
void QuietSort(int* array,int left, int right)
{
	if (right-left > 1)
	{
		//�Ȼ�������
		int div = Pation1(array, left, right);
		QuietSort(array, left, div);
		QuietSort(array, div + 1, right);
	}
}

//1.��������
void InsertSort(int* array, int size)
{
	for (int  i = 1; i < size; i++)
	{
		//�ӵڶ�Ԫ�ؿ�ʼ���ź�֮���Ԫ�ز���
		int key = array[i];
		int end = i - 1;
		while (end>=0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--; 
			//��end��ǰ��һֱ��,���ܻ����end������,
			//������������涨һ��
		}
		//��key�ߵ�end+1��λ��
		array[end + 1] = key;
	}

}

//2.ϣ������
void ShellSort(int* array, int size)
{
	int gap = size;
	while (gap){
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
			//i++����Ϊ��ͬ���齻������,��Ҫ��д��i=i+gap
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			//��ʱ��endΪ��ֵ,Ҫ�嵽�ոձȽϵ�ǰһ��
			array[end + gap] = key;
		}
		gap--;

	}
}


//3.ѡ������
void SelectSort(int* array, int size)
{
	//ѡ�������
	for (int i = 0; i < size - 1; i++)
	{
		//ѡ��ķ�ʽ
		int maxPos = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		if (maxPos != size - 1 - i)
			//�ж�maxPos�ǲ������һ��,����ǾͲ��ý���
			Swap(&array[maxPos], &array[size - 1 - i]);
	}
}

//4.ѡ�������Ż�
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

//5.������
void HeapSort(int* array, int size)
{
	//1.����
	int root = (size - 2) >> 1;
	for (; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	//2.������
	int end = size - 1;
	while (end)
	{
		//ɾ��������
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

//6.ð������
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

