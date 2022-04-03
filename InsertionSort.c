#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int a[] = { 33,1,51,2,12,100,23,59,9 };

void printArray() {
	int loop = sizeof(a) / sizeof(int);
	for (int i = 0; i < loop; i++)
		printf("%4d", a[i]);
	printf("\n\n");
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort() {
	int min;
	int loop = sizeof(a) / sizeof(int);
	for (int i = 0; i < loop; i++) {
		min = i;
		for (int j = i + 1; j < loop; j++) {
			if (a[j] < a[min]) min = j;
		}
		if (min != i)
			swap(&a[min], &a[i]);
	}
}

void insertSort() {
	int valueToInsert, holePosition;
	int loop = sizeof(a) / sizeof(int);
	for (int i = 0; i < loop; i++) {
		valueToInsert = a[i];
		holePosition = i;
		while (holePosition > 0 && a[holePosition - 1] > valueToInsert) {
			a[holePosition] = a[holePosition - 1];
			holePosition = holePosition - 1;
		}
		a[holePosition] = valueToInsert;
	}	
}

void bubbleSort() {
	int loop = sizeof(a) / sizeof(int);
	for (int i=0;i<loop;i++)
		for (int j = 0; j < loop-i-1; j++) {
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
}

int main() {
for(;;){
	printf("\033[1;32m");
	printf("please choose wich sort you want : \n");
	printf("press 1 to bubble sort\n");
	printf("press 2 to insert sort\n");
	printf("press 3 to selection sort\n");
	printf("press 4 to merge sort\n");
	printf("press 5 to quick sort\n");
	printf("press 9 to exit\n");
    int option;
	scanf("%d",&option);
	getchar();
	switch (option);
    {
	case 1:
	bubbleSort() ;
	printArray();
	break;	
	case 2:
	insertSort();
	printArray();
	break;
	case 3: 
	 selectionSort();
	printArray();
	break;
	case 4:
	printArray(); 
	break; 
	case 5: 
	printArray();
	break;  
	case 9: return 0; //exit
	
	
	
	

	}	
}

return 0;
}
