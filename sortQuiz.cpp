//fady zarka && sameeh sweed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define file1Path "sortedArray.txt"
#define file2Path "sort1.txt"
#define file3Path "sort2.txt"
int a[1000];

FILE* ptr1;
FILE* ptr2;
FILE* ptr3;


void createArray1(int a[]){
	for(int i=1;i<=1000;i++){
		a[i-1]=i;
	}

}
void  createUnsortArray(int arr[]){
	
	for(int i=1;i<=1000;i++){
		int x=rand()%10000;
		arr[i-1]=x;
	}
	
}
void readFirstfile(){
 ptr1=fopen(file1Path, "w");

    if (ptr1 == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return ;
    }
else{
     createArray1(a);
	fwrite(a,sizeof(int),sizeof(a),ptr1);

}

fclose(ptr1);

}


void readSecondfile(){
 ptr2=fopen(file2Path, "w");

    if (ptr2 == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return ;
    }
	else{
     createUnsortArray(a);
     fwrite(a,sizeof(int),sizeof(a),ptr2);
	}
fclose(ptr2);

}
void readThirdfile(){
 ptr3=fopen(file3Path, "w");

    if (ptr3 == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return ;
    }
	else{
     createUnsortArray(a);
     fwrite(a,sizeof(int),sizeof(a),ptr3);
	}

fclose(ptr3);
	
}



void printArray() {
	int loop = sizeof(a) / sizeof(int);
	for (int i = 0; i < loop; i++)
		printf("%8d", a[i]);
	printf("\n\n");

}

void swap(int* x, int* y) {

	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = a[high]; // pivot
    int i = low; 

    for (int j = low; j <= high - 1; j++)
    {
     
        if (a[j] < pivot)
        {
            swap(&a[i], &arr[j]);
            i++; 
        }
    }
    swap(&a[i], &a[high]);
    return (i);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pivot = partition(arr, low, high);
       

        // Separately sort elements before
        // partition and after partition
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
    else {
        //stop condition
    }
}
void merge(int array[], int const left, int const mid, int const right)
{
    //define arrays size
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray =  new int[subArrayOne];
    auto* rightArray =  new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    //define pointers
    auto indexOfSubArrayOne = 0; // Initial index of first sub-array
    auto   indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)// if the array size is 1 or less
        return; // Returns recursively (stop condition)
     
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);//left
    mergeSort(array, mid + 1, end);//right
    merge(array, begin, mid, end);//begin = left, mid=mid, end=right
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
time_t seconds,seconds_end;

auto a_size = sizeof(a) / sizeof(a[0]);
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
	switch(option)
    {
	case 1:
	readSecondfile();
	seconds = time(NULL);//time before loop
	bubbleSort();
    seconds_end = time(NULL);//time after loop
    
	printArray();
    printf("\nsec = %ld\n", seconds_end - seconds);
    
   //timeFunc();

	break;	
	case 2:
	readThirdfile();
    seconds = time(NULL);//time before loop
	insertSort();
    seconds_end = time(NULL);//time after loop
   
	printArray();
    printf("\nsec = %ld\n", seconds_end - seconds);
	break;
	case 3: 
	readSecondfile();
    seconds = time(NULL);//time before loop
	selectionSort();
    seconds_end = time(NULL);//time after loop

	printArray();
    printf("\nsec = %ld\n", seconds_end - seconds);
	break;
	case 4:
	readSecondfile();
	seconds = time(NULL);//time before loop
	mergeSort(a, 0, a_size - 1);
    seconds_end = time(NULL);//time after loop
   
    printArray();
    printf("\nsec = %ld\n", seconds_end - seconds);
   break; 
	case 5: 
	readSecondfile();
    seconds = time(NULL);//time before loop
	quickSort(a, 0, a_size - 1);
    seconds_end = time(NULL);//time after loop
   
	
	printArray();
    printf("\nsec = %ld\n", seconds_end - seconds);
	break;  
	case 9: return 0; //exit
	
	
	
	

	}	
}

return 0;
}