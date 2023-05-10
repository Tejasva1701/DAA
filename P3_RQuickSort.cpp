// Bhoomika Singh
// program to implement randomized quick sort

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

int comparisons;

// places all smaller than pivot to left of pivot and all greater elements to right of pivot
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
      comparisons++;
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Generates Random Pivot
int randomPartition(int arr[], int low, int high) {
  int random = low + rand() % (high - low + 1);
  swap(arr[random], arr[high]);
  return partition(arr, low, high);
}

// quick sort algorithm
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = randomPartition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  srand(time(0)); // seed random value at current time

  int n = 100;    // no. of inputs
  
  // storing data in the file
  ofstream outputFile("RandomizedQuickSort.txt");
  outputFile << "N \t\t Total Comparisons";

  for (int i = 0; i < n; i++) {
    int size = rand() % 971 + 30;
    int *arr = new int[size];

    for (int j = 0; j < size; j++) {
      arr[j] = rand() % 1000;
    }

    cout << "\n------------------------------------\n";
    cout << "File " << i + 1 << ": \n";

    comparisons = 0;
    quickSort(arr, 0, size - 1);

    cout << "Size of the File: " << size << endl;
    cout << "Total Number of comparisons: " << comparisons << endl;

    outputFile << "\n" << size << "\t\t" << comparisons;

    delete[] arr; // delete data from the file to store next set of random no.(s)
  }

  outputFile.close(); // closing the file
  cout << endl;
  return 0;
}
