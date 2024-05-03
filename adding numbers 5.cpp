#include <iostream>

double findMax(double numbers[], int size) {
    double max = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int main() {
    double numbers[5];

    std::cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    double max = findMax(numbers, 5);
    std::cout << "The largest value entered is: " << max << std::endl;

    return 0;
}