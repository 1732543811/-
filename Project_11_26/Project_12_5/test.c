#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>




int main(){
	int array[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	//SelectSortOP(array, sizeof(array) / sizeof(array[0]));
	QuietSort(array, 0, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	
	system("pause");
	return 0;
}
