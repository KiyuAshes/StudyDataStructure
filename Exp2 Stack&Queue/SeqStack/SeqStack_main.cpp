#include <iostream>

#include "SeqStack.cpp"
using namespace std;
int main() {
    SeqStack<int> S;
    if (S.IsEmpty())
        cout << "栈为空" << endl;
    else
        cout << "栈非空" << endl;
    cout << "对15和10执行入栈操作" << endl;
    S.Push(15);
    S.Push(10);
    cout << "栈顶元素为:" << S.GetTop() << endl;
    cout << "执行一次出栈操作" << endl;
    S.Pop();
    cout << "栈顶元素为:" << S.GetTop() << endl;
    return 0;
}