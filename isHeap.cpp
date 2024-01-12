#include <iostream>

using namespace std;

bool isHeap(int* arr, int n) {
    for (int i = 0; i < n/2; i++) {

        if ((i * 2 + 1 < n) && arr[(i * 2) + 1] > arr[i]) {
            return false;
        }

        if ((i * 2 + 2 < n) && arr[(i*2) + 2] > arr[i]) {
            return false;
        }

    }
    return true;
}

int main() {

    int arr[] = {50, 30, 40, 19, 20, 10, 5, 2};
    int n = 8;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bool result = isHeap(arr, n);
    if (result) {
        cout << "Heap" << endl;
    }
    else {
        cout << "Not Heap" << endl;
    }

    return 0;
}
