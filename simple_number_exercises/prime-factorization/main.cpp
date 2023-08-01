#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

auto printVector(const std::vector<int>& my_vector)
{
    for (int i : my_vector)
        std::cout << i << ' ';
}

auto findPrimes(int n)
{
    std::vector<int> primeList{};
    while (n % 2 == 0) {
        primeList.emplace_back(2);
        n /= 2;
    }

    // Check for other prime factors starting from 3
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            primeList.emplace_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2, add it as a prime factor
    if (n > 2) {
        primeList.emplace_back(n);
    }

    printVector(primeList);
}

int main()
{
    std::cout << "Enter the number: ";
    int input;

    while (!(std::cin >> input) || input < 0)
    {
        std::cout << "Bad input, try again" << std::endl;
        std::cin.clear();                                                   // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
    }

    findPrimes(input);
    return 0;
}
