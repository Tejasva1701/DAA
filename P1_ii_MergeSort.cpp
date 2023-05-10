// Bhoomika Singh
// program to implement merge sort

#include <iostream>
#include <fstream>
#include <sys/time.h>	
#include <cstdlib>
using namespace std;

int comparisons;

void merge(int arr[], int left, int mid, int right) {
 
  // l_arr <- arr[left:mid] and R_arr subarray <- arr[mid+1:right]
  	int n1 = mid - left + 1;
  	int n2 = right - mid;

	int l_arr[n1], R_arr[n2];

    for (int i = 0; i < n1; i++)
    	l_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
      	R_arr[j] = arr[mid + 1 + j];


  	int i = 0, j = 0, k = left;

	// merge arrays again
  	while (i < n1 && j < n2) {
      	if (l_arr[i] <= R_arr[j]) {
          	arr[k] = l_arr[i];
          	i++;
      	} 
		else {
          	arr[k] = R_arr[j];
          	j++;
      	}
      	comparisons++;
      	k++;
  	}

 	// checking for remaining elements in L_arr, if any
  	while (i < n1) {
      	arr[k] = l_arr[i];
      	i++;
      	k++;
  	}
  	// checking for remaining elements in R_arr, if any
  	while (j < n2) {
      	arr[k] = R_arr[j];
      	j++;
      	k++;
  	}
}

// merge sort algorithm
void mergeSort(int arr[], int left, int right) {
  	if (left < right) {
    // Finding mid of array
    	int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted subarrays
    merge(arr, left, mid, right);
  	}
}

int main()
{ 
  	srand(time(0));  // seed random value at current time

  	int n = 100;     // no. of inputs

  	ofstream outputFile("MergeSort.txt");
  	outputFile << "N \t\t Total Comparisons";

  	for(int i = 0; i <= n; i++)
  	{
    	int size = rand()%971 + 30;
    	int *arr = new int[size];

    for(int j = 1; j < size; j++)
    {
      	arr[j] = rand()%1000;
    }
      	cout << "\n------------------------------------\n";
      	cout << "File " << i << ": \n";

      	comparisons = 0;
      	mergeSort(arr, 0, size - 1);

      	cout << "Size of the File: " << size << endl;
      	cout << "Total Number of comparisons: " << comparisons << endl;
      	
      	outputFile << "\n" << size << "\t\t" << comparisons;
      	                 
      	delete[] arr;  // delete data from the file to store next set of random no.(s)
    }

    outputFile.close();  // closing file
    cout << endl;
    
	return 0;
}
