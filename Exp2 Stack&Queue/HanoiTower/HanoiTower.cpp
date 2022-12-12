#include <iostream>
int count = 0;

void Hanoi(int n, char X, char Y, char Z) {
    if (n == 1) {
        std::cout << count++ << " " << X << "->" << Z << std::endl;
    } else {
        Hanoi(n - 1, X, Z, Y);
        std::cout << count++ << " " << X << "->" << Z << std::endl;
        Hanoi(n - 1, Y, X, Z);
    }
}
int main() {
    int n;
    std::cin >> n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}