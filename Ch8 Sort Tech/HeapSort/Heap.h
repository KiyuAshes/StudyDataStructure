/*
 * @Author: Askr_Yggdrasills
 * @Date: 2022-01-10 19:39:40
 * @LastEditTime: 2022-01-10 22:39:39
 * @LastEditors: Askr_Yggdrasills
 * @Description:
 * Copyright © 2021 Askr_Yggdrasills, All Rights Reserved.
 */

enum HeapType { MaxHeap, MinHeap };

class Heap {
   public:
    //建堆
    Heap(int *arr, int arr_size, HeapType);
    void max_heapify(int index);
    void min_heapify(int index);

   private:
    int *heap;
    int heap_size, max_size;
    HeapType type;
};