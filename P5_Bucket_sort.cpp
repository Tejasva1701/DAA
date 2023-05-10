// Bhoomika Singh
// program to implemet bucket sort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// bucket sort algorithm
void bucketSort(float arr[], int n)
{
    vector<float> buckets[n];

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    float arr[] = {0.12, 0.34, 0.63, 0.56, 0.15, 0.25, 0.92, 0.10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array - \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bucketSort(arr, n);

    cout << "\n\nSorted Array - \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
