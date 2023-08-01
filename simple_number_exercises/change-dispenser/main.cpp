#include <iostream>
#include <vector>
#include <limits>
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

void calculateChange(float& cost,float& paid)
{
    float change {paid - cost};
    if (change < 0){
        std::cout << "Cost cannot be greater than paid"sv <<std::endl;
        return;
    }

    int dollars {static_cast<int>(change)};
    int cents {static_cast<int>((change-dollars)*100)};

    int quarters {cents/25};
    cents %= 25;
    int dimes {cents/10};
    cents %= 10;
    int nickels {cents/5};
    cents %= 5;
    int pennies {cents/1};

    std::cout << "Dollars: "sv << dollars  <<"\n"
              << "Quartes: "sv << quarters << "\n"
              << "Dimes: "sv << dimes      << "\n"
              << "Nickels: "sv << nickels  << "\n"
              << "Pennies: "sv << pennies  << "\n";
              

    
    
}

int main() {
    float cost {};
    float paid {};
    std::cout << "Enter the cost: "sv;
    getInput(cost);
    std::cout << "Enter paid amount: "sv;
    getInput(paid);

    calculateChange(cost,paid);

    return 0;
}
