#include <iostream>
#include <vector>
#include <limits>

auto printVector(const std::vector<int>& my_vector) {
    for (int i : my_vector)
        std::cout << i << ' ';
}

auto generateFibonacci(int& fibonacci_N) {
    std::vector<int> fibonacci_seq;
/*Conditions for if the number is 1 or 2*/
    if (fibonacci_N > 0) {
        fibonacci_seq.emplace_back(0);
        --fibonacci_N;

        if (fibonacci_N > 0) {
            fibonacci_seq.emplace_back(1);
            --fibonacci_N;
        }
    }

    while (fibonacci_N != 0) {
        int next_fNumber = fibonacci_seq.at(fibonacci_seq.size() - 1) + fibonacci_seq.at(fibonacci_seq.size() - 2);
        fibonacci_seq.emplace_back(next_fNumber);
        --fibonacci_N;
    }

    printVector(fibonacci_seq);
}

int main() {
    std::cout << "Enter the size of the fibonacci sequence you want to generate: ";
    int fibonacci_Number;

    while (!(std::cin >> fibonacci_Number) || fibonacci_Number < 0) {
        std::cout << "Bad input, try again" << std::endl;
        std::cin.clear();   // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
    }

    generateFibonacci(fibonacci_Number);
    return 0;
}
