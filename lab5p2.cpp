#include<iostream>
#include <iomanip>
#include<cmath>
#include <cstdlib> 
#include <ctime>
#include <stdlib.h>


double future = 0;
double interestRate = 0;
double numYears = 0;

void getUserValues()
{

    std::cout << "Enter the future value: \n";
    std::cin >> future;
    std::cout << "Enter the annual interest rate: \n";
    std::cin >> interestRate;
    std::cout << "Enter the number of years you will leave the money in the account: \n";
    std::cin >> numYears;

}

double presentValue()
{

    return future/(pow(1+interestRate,numYears));

}

void display()
{

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "If you deposit $" << presentValue() << " today into an account\nwith an annual interest rate of " << interestRate << "% for " << numYears << " years,\nyou will have $" << future << "\n";

}

int main()
{


getUserValues();
display();


}
