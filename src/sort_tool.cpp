// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2021/02/26 Hsien-Chia Chen]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for(int j=1; j<data.size(); j++) {
        int key = data.at(j);
        int i = j-1;
        while(i >= 0 && data.at(i) > key) {
            data.at(i+1) = data.at(i);
            i--;
        }
        data.at(i+1) = key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if(high>low) {
        int pivot = Partition(data, low, high);
        QuickSortSubVector(data, low, pivot-1);
        QuickSortSubVector(data, pivot+1, high);
    }
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int pivot = data.at((low+high)/2);
    data.at((low+high)/2) = data.at(high);
    data.at(high) = pivot;
    
    int i=low-1;
    for(int j=low; j<high; j++){
        if(data.at(j) <= pivot){
            i++;
            int temp = data.at(i);
            data.at(i) = data.at(j);
            data.at(j) = temp;
        }
    }
    data.at(high) = data.at(i+1);
    data.at(i+1) = pivot;
    
    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if(low<high) {
        int middle1 = (high+low)/2;
        int middle2 = middle1 + 1;
        MergeSortSubVector(data, low, middle1);
        MergeSortSubVector(data, middle2, high);
        Merge(data, low, middle1, middle2, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> sub1(data.begin()+low, data.begin()+middle2);
    vector<int> sub2(data.begin()+middle2, data.begin()+high+1);
    sub1.push_back(1000001);
    sub2.push_back(1000001);
    
    int i=0;
    int j=0;
    for(int k=low; k<=high; k++) {
        if(sub1.at(i) <= sub2.at(j)) {
            data.at(k) = sub1.at(i);
            i++;
        } else {
            data.at(k) = sub2.at(j);
            j++;
        }
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
	int tmp = 0;
    for (int i = data.size() - 1; i >= 1; i--) {
		tmp = data[i];
		data[i] = data[0];
		data[0] = tmp;
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int lc = root*2+1;
    int rc = root*2+2;
    int largest = root;
    if(lc < heapSize && data.at(lc) > data.at(largest)) {
        largest = lc;
    }
    if(rc < heapSize && data.at(rc) > data.at(largest)) {
        largest = rc;
    }
    if(largest != root) {
        int temp = data.at(root);
        data.at(root) = data.at(largest);
        data.at(largest) = temp;
        MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for(int i=(data.size()-1)/2; i>=0; i--) {
        MaxHeapify(data, i);
    }
}
