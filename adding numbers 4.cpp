#include <iostream>

// Function to find the maximum value among the given numbers
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
    const int SIZE = 5;
    double numbers[SIZE];

    // Ask the user to enter 5 numbers
    std::cout << "Enter 5 numbers:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    // Find the maximum value
    double max = findMax(numbers, SIZE);

    // Display the result
    std::cout << "The largest value entered is: " << max << std::endl;

    return 0;
}