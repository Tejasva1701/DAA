// Bhoomika Singh
// program to implement insertion sort

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

int comparisons;

// insertion sort algorithm
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
}

int main() {

    srand(time(0));  // seed random value at current time

    int n = 100;     // no. of inputs

	// storing data in the file
    ofstream outputFile("InsertionSort.txt");
    outputFile << "N \t\t TotalComparisons";

    for(int i = 1; i <= n; i++) {
        int size = rand()%971 + 30;
        int *arr = new int[size];

        for(int j = 0; j < size; j++) {
            arr[j] = rand()%1000;
        }

        cout << "\n------------------------------------\n";
        cout << "File " << i << ": \n";

        comparisons = 0;
        insertionSort(arr, size);

        cout << "Size of the File: " << size << endl;
        cout << "Total Number of comparisons: " << comparisons << endl;


        outputFile << "\n" << size << "\t\t" << comparisons;

        delete[] arr; // delete data from the file to store next set of random no.(s)
    }

    outputFile.close();   // closing file
    cout << endl;
    return 0;
}
