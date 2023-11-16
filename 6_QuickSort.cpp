#include<bits/stdc++.h>

using namespace std;

int partition(int * arr, int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int * arr, int p, int r){
    if (p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int randomPartition(int *arr, int p, int r) {
    int x = arr[r];
    int i = p + rand() % (r - p + 1);  // Ensure the index is within bounds
    swap(arr[i], arr[r]);

    i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void randomizedQuickSort(int * arr, int p, int r){
    if (p < r){
        int q = randomPartition(arr, p, r);
        randomizedQuickSort(arr, p, q - 1);
        randomizedQuickSort(arr, q + 1, r);
    }
}

int main(){

    int A[] = {23, 34, 54, 123, 34, 56, 67676, 112};
    int n = sizeof(A) / sizeof(A[0]);

    // Clone the array for deterministic quicksort
    int B[n];
    copy(A, A + n, B);

    cout << "Original Array: ";
    for(int i : A){
        cout << i << " ";
    }
    cout << '\n';

    // Deterministic quicksort
    quickSort(A, 0, n - 1);

    cout << "Sorted Array (Deterministic): ";
    for(int i : A){
        cout << i << " ";
    }
    cout << '\n';

    // Randomized quicksort
    randomizedQuickSort(B, 0, n - 1);

    cout << "Sorted Array (Randomized): ";
    for(int i : B){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}
