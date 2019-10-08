// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    capacity = cap;
    heap_size = 0;
    harr = new int[cap + 1]; //+1 because you keep the 0th index empty

}

// Return the index of parent of the node at index i
int MinHeap::parent(int i)
{
    return i/2;
}

// Return index of left child of node at index i
int MinHeap::left(int i)
{
    return i*2;
}

// Return index of right child of node at index i
int MinHeap::right(int i)
{
    return (i*2) + 1;
}

// Return the minimum value in the heap
int MinHeap::getMin()
{
    return harr[1];
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k)
{
    // Corner case: If heap is full
    if(heap_size == capacity){
        cout << "Heap is full. Cannot push the key." << endl;
        return;
    }
    // increment the heap size
    heap_size ++;
    // insert the new key at the end
    harr[heap_size] = k;

    // Fix the min heap property if it is violated
    cout<<endl<<"Index of "<<harr[heap_size]<<" : "<<heap_size<<endl;
    cout<<"Parent of "<<harr[heap_size]<<" : "<<harr[parent(heap_size)]<<" at index : "<<parent(heap_size)<<endl;
    // --- ENTER CODE HERE --- //
    ReverseHeapify(heap_size);
    cout<<endl;
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i) //repair upward
{
    if( i > heap_size){
        cout << "index cannot be greater than head size" << endl;
        return;
    }
    int p = parent(i);
    
    if(p != 0 && harr[p] > harr[i]){
        swap(&harr[p], &harr[i]);
        ReverseHeapify(p);
    }

}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    if(i > heap_size){
        cout << "given index cannot be greater than head size" << endl;
        return;
    }
    // left and right children
    int l = left(i);
    int r = right(i);

    // set given index as smallest
    int smallest = i;

    // compare it with its left and right children and set smallest
    
    if(l < heap_size && harr[smallest] > harr[l]){
        smallest = l;
    }
    if(r < heap_size && harr[smallest] > harr[r]){
        smallest = r;
    }

    // swap if not less than its one of the children
    if(smallest != i){
        swap(&harr[smallest], &harr[i]);
        MinHeapify(smallest);
    }
    
    cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
    cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
    cout<<"Heapifying "<<harr[i]<<" and its subtrees"<<endl;
    cout<<endl<<"Index of "<<harr[smallest]<<" : "<<smallest<<endl;
    // Heapify
    // ----- ENTER CODE HERE ----
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap()
{
    //CORNER CASE: HEAP EMPTY, HEAP SIZE 1
    if(heap_size == 0){
        cout << "Heap is EMPTY. Nothing to POP.";
        return;
    }
    if(heap_size == 1){
        heap_size --;
        return;
    }
    harr[1] = harr[heap_size];
    cout<<endl<<"Replaced root with the Last element"<<endl;
    heap_size --;
    MinHeapify(1);
    cout<<"Now the root is : "<< harr[1]<<endl;
    // Store the minimum value, and remove it from heap

    // Set the last element in the heap as roo

    // Decrease the heap size by 1

    // Move the root to its appropriate place

    // HEAPIFY
}

void MinHeap::printMinHeap()
{
    for(int i=1;i<=heap_size;i++){
        cout<<i<<":"<<harr[i]<<endl;
    }
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
