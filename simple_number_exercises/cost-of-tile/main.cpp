#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using std::string_literals::operator""s;
using std::string_view_literals::operator""sv;

template <typename T>   
void getInput(T &input) 
{
    while (!(std::cin >> input) || input < 0)
    {
        std::cout << "Bad input, try again" << std::endl;
        std::cin.clear();                                                   // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
    }
    return;
}

double calculateCost(double w, double l, double cost_m2)
{
    return w * l * cost_m2;
}

int main()
{
    double width{};
    double length{};
    double cost_per_m2{};
    std::cout << "Enter tile cost per meter square: "sv;
    getInput(cost_per_m2);
    std::cout << "Enter the width: "sv;
    getInput(width);
    std::cout << "Enter the length: "sv;
    getInput(length);
    std::cout << "Total cost: "sv << calculateCost(width, length, cost_per_m2) << "$"sv ;
    return 0;
}
