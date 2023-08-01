#include <iostream>
#include <string>
#include <iomanip>
#include <string_view>
#include <limits> 

constexpr float PI{3.14159265358979323846264338327950288419716939937};
using std::string_literals::operator""s;
using std::string_view_literals::operator""sv;

int main()
{
    std::cout << "Enter the precision n: "sv;
    int precision{};

    while (!(std::cin >> precision) || (precision > 30))
    {
        std::cout << "cin.fail() = "sv << std::cin.fail() << std::endl;
        if(precision > 30){
            std::cout << "Precision must be smaller than 30"sv << std::endl;
        }
        if(std::cin.fail()){
            std::cout << "Bad input try again"sv << std::endl;
        }
        std::cin.clear();   // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        std::cout << "Enter the precision n: "sv;
    }

    std::cout << std::setprecision(precision) << PI << std::endl;

    return 0;
}
