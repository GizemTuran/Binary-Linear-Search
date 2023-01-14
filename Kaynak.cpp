#include <iostream>
using namespace std;
int counter = 0;
void bubbleSort(int arr[], int size) {
	counter = 0;	//Incrementing the counter by one

	for (int i = 0; i < size; i++) {				//Forming our "bubble" with index of n and n+1,
		for (int j = i+1; j < size; j++) {			//and moving them forward
			
			counter++;		//Incrementing the counter by one
			if (arr[i] > arr[j + 1]) {		//If the number is greater then the next number in the array, they need to swap places
				int temp = 0;
				//Swapping our numbers
				temp = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
	//Our loop and bubble sort algorithm ends. We print the number of comparisons.
	cout << "Bubble Sort # of Comparisons   : " << counter << endl;
	
}
void insertionSort(int size,int arr[]) {
	int i, j, key;
	counter = 0;	//Incrementing the counter by one

	for (j = 1; j < size; j++) {
		key = arr[j];	//We assign our key
		i = j ;			
		counter++;		//Incrementing the counter by one

		while (i > 0 && arr[i-1] > key){  //We check if we have moved forward and if our previous value from i th index is greater than our key. If they are both true, when we slide the value back
			arr[i] = arr[i-1];
			i = i - 1;
			counter++;		//Incrementing the counter by one
		}

			arr[i] = key; //insert in right place
	
	}
	cout << "Insertion Sort # of Comparisons: " << counter << endl;

}
int main() {
	
	int size;
	int* arr;
	int* arr2;
	int* arr3;
	
	cout << "Q2 - Number of Comparisons on Sorted (in Ascending Order) Arrays" << endl;
	cout << "SIZE: " ;
	cin >> size;
	cout << endl;

	arr = new int[size+1]; //To create a dynamic array

	for (int i = 0; i < size; i++) {

		arr[i] = i;
	}

	bubbleSort(arr,size);
	insertionSort(size, arr);
	
	cout << endl;
	cout << "Q2 - Number of Comparisons on Randomly Generated (Unsorted) Arrays" << endl;
	cout << "SIZE: ";
	cin >> size;
	cout << endl;

	arr2 = new int[size+1]; //To create a dynamic array
	arr3 = new int[size + 1];

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		int temp;
		temp = rand() % size;
		arr2[i] = temp;
		arr3[i] = temp;
		
	}
	bubbleSort(arr2, size);
	insertionSort(size, arr3);

	delete[]arr3;
	delete[]arr2;
	delete[]arr;
	return 0;
}