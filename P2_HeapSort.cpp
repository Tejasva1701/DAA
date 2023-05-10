// Bhoomika Singh
// program to implement heap sort

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

int comparisons = 0;

// to heapify a subtree
void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
    comparisons++;
  }
 

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
    comparisons++;
  }
 

  if (largest != i) {
    swap(arr[i], arr[largest]);
    comparisons++;
    heapify(arr, n, largest);
  }
}

// heapsort algorithm
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    comparisons++;
    heapify(arr, i, 0);
  }
}

int main() {
  srand(time(0));   // seed random value at current time

  int n = 100;      // no. of inputs

  // storing data in the file
  ofstream outputFile("HeapSort.txt");
  outputFile << "N \t\t Total Comparisons";

  for (int i = 1; i <= n; i++) {
    int size = rand() % 971 + 30;
    int *arr = new int[size];

    for (int j = 0; j < size; j++) {
      arr[j] = rand() % 1000;
    }

    cout << "\n------------------------------------\n";
    cout << "File " << i  << ": \n";

    comparisons = 0;
    heapSort(arr, size);

    cout << "Size of the File: " << size << endl;
    cout << "Total Number of comparisons: " << comparisons << endl;

    outputFile << "\n" << size << "\t\t" <<comparisons;

    delete[] arr;  // delete data from the file to store next set of random no.(s)
  }

  outputFile.close(); // closing file
  cout << endl;
  return 0;
}
