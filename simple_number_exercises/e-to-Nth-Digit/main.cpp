#include <iostream>
#include <string>
#include <iomanip>
#include <string_view>
#include <limits> 

using std::string_literals::operator""s;
using std::string_view_literals::operator""sv;

int main()
{
    double e=2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274;

    std::cout << "Enter the precision n: "sv;

    int precision{};

    while (!(std::cin >> precision) || (precision > 30))
    {
        std::cout << "cin.fail() = "sv << std::cin.fail() << std::endl;
        if(precision > 30){
            std::cout << "Precision must be smaller than 30 and greater than *"sv << std::endl;
        }
        if(std::cin.fail()){
            std::cout << "Bad input try again"sv << std::endl;
        }
        std::cin.clear();   // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        std::cout << "Enter the precision n: "sv;
    }

    std::cout << std::setprecision(precision + 1) << e << std::endl;

    return 0;
}
