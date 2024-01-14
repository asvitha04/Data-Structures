#include <iostream>
#include <vector>
using namespace std;

void down_heapify(vector<int>& heap, int parent, int size, bool isMaxHeap) {
    int largest = parent;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    if (isMaxHeap) {
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
    } else {
        if (leftChild < size && heap[leftChild] < heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[largest]) {
            largest = rightChild;
        }
    }

    if (parent != largest) {
        swap(heap[parent], heap[largest]);
        down_heapify(heap, largest, size, isMaxHeap);
    }
}

void up_heapify(vector<int>& heap, int child, bool isMaxHeap) {
    int parent = (child - 1) / 2;
    if (parent >= 0) {
        if (isMaxHeap && heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);
            up_heapify(heap, parent, isMaxHeap);
        } else if (!isMaxHeap && heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
            up_heapify(heap, parent, isMaxHeap);
        }
    }
}

void insert_heap(vector<int>& heap, int& size, int key, bool isMaxHeap) {
    heap.push_back(key);
    size++;  
    up_heapify(heap, size - 1, isMaxHeap); 
}


void deleteRoot(vector<int>& heap, int& size, bool isMaxHeap) {
    if (size == 0) {
        cout << "Heap is empty.Cannot delete." << endl;
        return;
    }

    swap(heap[0], heap[size - 1]);
    heap.pop_back();
    size--;
    down_heapify(heap, 0, size, isMaxHeap);
}

int findTop(const vector<int>& heap) {
    if (!heap.empty()) {
        return heap[0];
    } else {
        cout << "Heap is empty." << endl;
        return -1;
    }
}

int extractTop(vector<int>& heap, int& size, bool isMaxHeap) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return -1;
    }

    int topElement = heap[0];  
    deleteRoot(heap, size, isMaxHeap);
    
    return topElement;  
}


void heapSort(vector<int>& arr, bool isMaxHeap) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
    down_heapify(arr, i, n, isMaxHeap);
}
for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    down_heapify(arr, 0, i, isMaxHeap);
}
}

int main() {
    vector<int> minHeap;
    vector<int> maxHeap;
    int minHeapSize = 0;
    int maxHeapSize = 0;
    while (true) {
        cout << "------------------------------BINARY HEAP------------------------------" << endl;
        cout << "Enter an operation to perform:" << endl;
        cout << "1) Insert element in Minheap" << endl;
        cout << "2) Find Min" << endl;
        cout << "3) Delete element in Minheap" << endl;
        cout << "4) Extract Min" << endl;
        cout << "5) Insert element in Maxheap" << endl;
        cout << "6) Find Max" << endl;
        cout << "7) Delete element in Maxheap" << endl;
        cout << "8) Extract Max" << endl;
        cout << "9) Heap Sort (Ascending)" << endl;
        cout << "10) Heap Sort (Descending)" << endl;
        cout << "11) Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to be inserted in Minheap: ";
                cin >> value;
                insert_heap(minHeap, minHeapSize, value, false);
                break;
            }
            case 2: {
                int min = findTop(minHeap);
                if (min != -1) {
                    cout << "Min element: " << min << endl;
                }
                break;
            }
            case 3: {
                deleteRoot(minHeap, minHeapSize, false);
                break;
            }
            case 4: {
                int extractedMin = extractTop(minHeap, minHeapSize, false);
                if (extractedMin != -1) {
                    cout << "Extracted Min element: " << extractedMin << endl;
                }
                break;
            }
            case 5: {
                int value;
                cout << "Enter value to be inserted in Maxheap: ";
                cin >> value;
                insert_heap(maxHeap, maxHeapSize, value, true);
                break;
            }
            case 6: {
                int max = findTop(maxHeap);
                if (max != -1) {
                    cout << "Max element: " << max << endl;
                }
                break;
            }
            case 7: {
                deleteRoot(maxHeap, maxHeapSize, true);
                break;
            }
            case 8: {
                int extractedMax = extractTop(maxHeap, maxHeapSize, true);
                if (extractedMax != -1) {
                    cout << "Extracted Max element: " << extractedMax << endl;
                }
                break;
            }
            case 9: {
                heapSort(minHeap, false);
                cout << "Sorted array (Ascending): ";
                for (int i = minHeap.size()-1; i >= 0; i--) {
                    cout << minHeap[i] << " ";
                }
                cout << endl;
                break;
            }
            case 10: {
                heapSort(maxHeap, true);
                cout << "Sorted array (Descending): ";
                for (int i = maxHeap.size()-1; i >= 0; i--) {
                    cout << maxHeap[i] << " ";
                }
                cout << endl;
                break;
            }
            case 11: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}
