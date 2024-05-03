#include <iostream>

void fibonacci(int n) {
    int first = 0, second = 1, next;
    
    std::cout << "Fibonacci Sequence up to " << n << ":\n";
    std::cout << first << " " << second << " ";
    
    for(int i = 2; i < n; ++i) {
        next = first + second;
        std::cout << next << " ";
        first = second;
        second = next;
    }
}

int main() {
    int num;
    std::cout << "Enter the number of terms for Fibonacci sequence: ";
    std::cin >> num;
    
    fibonacci(num);
    
    return 0;
}
