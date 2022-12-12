/*
 * @Author: Askr_Yggdrasills
 * @Date: 2022-01-10 19:33:21
 * @LastEditTime: 2022-12-11 01:58:31
 * @LastEditors: Askr_Yggdrasills
 * @Description:
 * Copyright © 2021 Askr_Yggdrasills, All Rights Reserved.
 */
#include "Heap.h"

#include <cstring>
#include <iostream>

// using std::cin;
// using std::cout;
// using std::endl;

//交换两个数，用内联实现类似宏替换的效果
inline void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

//建堆
Heap::Heap(int *arr, int arr_size, HeapType heap_type)
    : heap_size(arr_size), max_size(2 * heap_size), type(heap_type) {
    heap = new int[max_size];
    memcpy(heap, arr, sizeof(int) * heap_size);

    switch (type) {
        case MaxHeap:
            for (int i = heap_size / 2; i >= 1; i--) {
                max_heapify(i);
            }
            break;
        case MinHeap:
            for (int i = heap_size / 2; i >= 1; i--) {
                min_heapify(i);
            }
            break;
    }
}

//使以index为根的子树堆变成最大堆
void Heap::min_heapify(int index) {
    int l = index << 1;
    int r = l + 1;
    int least = index;
    if (l <= heap_size && heap[l] < heap[least]) least = l;
    if (r <= heap_size && heap[r] < heap[least]) least = r;
    if (least != index) {
        swap(&heap[index], &heap[least]);
        min_heapify(least);
    }
}

//使以index为根的子树堆变成最小堆
void Heap::max_heapify(int index) {
    int l = index << 1;
    int r = l + 1;
    int largest = index;
    if (l <= heap_size && heap[l] > heap[largest]) largest = l;
    if (r <= heap_size && heap[r] > heap[largest]) largest = r;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        max_heapify(largest);
    }
}

// int main() {
//     int lenght = 0, size = 0, heap[1000] = {0};
//     cin >> lenght;
//     size = lenght;
//     for (int i = 1; i <= lenght; i++) cin >> heap[i];
//     //建堆

//     //排序
//     for (int i = lenght; i >= 2; i--) {
//         for (int i = 1; i <= lenght; i++) cout << heap[i] << " ";
//         cout << endl;
//         swap(&heap[1], &heap[size]);
//         size--;
//         max_heapify(heap, 1, size);
//     }
//     for (int i = 1; i <= lenght; i++) cout << heap[i] << " ";
//     return 0;
// }