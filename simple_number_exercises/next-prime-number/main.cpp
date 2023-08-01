#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using std::string_literals::operator""s;
using std::string_view_literals::operator""sv;

auto findNextPrime()
{
    char input;
    int n = 2;
    std::cout << "Next prime number: "sv << n;
    do
    {
        std::cout << "Continue? (y/n): "sv;

        while (!(std::cin >> input) || (input != 'y' && input != 'Y' && input != 'n' && input != 'N'))
        {
            std::cout << "Bad input, try again"sv << std::endl;
            std::cin.clear();                                                   // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        }

        if (input == 'y' || input == 'Y')
        {
            n++;
            while (true)
            {
                bool isPrime = true;
                for (int i = 2; i <= sqrt(n); ++i)
                {
                    if (n % i == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }

                if (isPrime)
                {
                    std::cout << "Next Prime number: "sv << n << std::endl;
                    break;
                }

                n++;
            }
        }
        else {
            return;
        }

    } while (input == 'y' || input == 'Y');

    return;
}

int main()
{
    findNextPrime();
    return 0;
}
