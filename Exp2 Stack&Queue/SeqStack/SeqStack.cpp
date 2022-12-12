#include "SeqStack.h"

template <class DataType>
SeqStack<DataType>::SeqStack() {
    top = 0;
}

template <class DataType>
void SeqStack<DataType>::Push(DataType x) {
    if (top == StackSize) throw "上溢";
    data[top] = x;
    top++;
}

template <class DataType>
DataType SeqStack<DataType>::Pop() {
    if (top == 0) throw "下溢";
    top--;
    return data[top];
}

template <class DataType>
DataType SeqStack<DataType>::GetTop() {
    if (top == 0) throw "空栈";
    return data[top - 1];
}

template <class DataType>
bool SeqStack<DataType>::IsEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}