#include <iostream>
#include <chrono>

using namespace std;

template <typename T>
void swap(T* first, T* second) {

	T temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

template <typename T>
void selection_sort(T arr[], int arr_size) {
	int small_index;
	for (int i = 0; i < arr_size - 1; i++) {
		small_index = i;
		for (int j = i + 1; j < arr_size; j++) {
			if (arr[small_index] > arr[j]) {
				small_index = j;
			}
		}
		swap(&arr[small_index], &arr[i]);
	}
}

template <typename T>
void insertion_sort(T arr[], int arr_size) {
	for (int i = 1; i < arr_size; i++) {
		T temp = arr[i];
		int j = i - 1;
		while (j > -1 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;

		}
		arr[j + 1] = temp;
	}
}

template <typename T>
int partition(T arr[], int start, int end) {

	swap(&arr[start], &arr[(start + end) / 2]);
	T pivot = arr[start];
	int small_index = start;
	int index = start + 1;

	for (index; index <= end; index++) {
		if (arr[index] < pivot) {
			small_index++;
			swap(&arr[small_index], &arr[index]);
		}
	}
	swap(&arr[start], &arr[small_index]);

	return small_index;
}

template <typename T>
void quick_sort(T arr[], int start, int end) {
	if (start < end) {

		int pivot_location = partition(arr, start, end);
		quick_sort(arr, start, pivot_location - 1);
		quick_sort(arr, pivot_location + 1, end);
	}
}

template <typename T>
void merge(T arr[], int start, int mid, int end) {
	T temp_arr[100]; // temporary array for storing merged sub arrays. size is passed staticly here for compiler compatibility. 
					// end - start + 1 can also be passed depending on some compilers for better performance
	int temp_pointer = 0;
	int pointer1 = start;
	int pointer2 = mid + 1;
	
	while (pointer1 <= mid && pointer2 <= end) {
		if (arr[pointer1] < arr[pointer2]) {
			temp_arr[temp_pointer++] = arr[pointer1++];
		}
		else {
			temp_arr[temp_pointer++] = arr[pointer2++];
		}
	}

	while (pointer1 <= mid) {
		temp_arr[temp_pointer++] = arr[pointer1++];
	}

	while (pointer2 <= end) {
		temp_arr[temp_pointer++] = arr[pointer2++];
	}

	temp_pointer = 0;
	for (int i = start; i <= end; i++) {
		arr[i] = temp_arr[temp_pointer++];
	}
}

template <typename T>
void merge_sort(T arr[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

template <typename T>
void heapify(T arr[], int size, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != root) {
		swap(&arr[largest], &arr[root]);
		heapify(arr, size, largest);
	}
}

template <typename T>
void heapSort(T arr[], int size) {

	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);

		heapify(arr, i, 0);
	}
}

int main() {
	int arr[] = {3, 5, 2, 6, 4, 1, 9, 3, 5, 2, 6, 4, 1};
	int count = 0;
	for (int e : arr)
		count++;

	cout << "Before Heap Sort: ";
	for (auto element : arr) {
		cout << element << " ";
	}
	cout << "\n";
	

	auto start = chrono::high_resolution_clock::now();
	// selection_sort(arr, count);
	// insertion_sort(arr, count);
	// quick_sort(arr, 0, count - 1);
	// merge_sort(arr, 0, count - 1);
	heapSort(arr, count);
	auto stop = chrono::high_resolution_clock::now();

	cout << "After Heap Sort: ";
	for (auto element : arr) {
		cout << element << " ";
	}
	cout << "\n";

	auto duration = (chrono::duration_cast<chrono::milliseconds>(stop - start).count());

	std::cout << "Total Elapsed Time: " << duration << " miliseconds" << "\n";
	return 0;
}
