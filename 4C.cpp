#include<iostream>
#include <iomanip>
#include<cmath>
#include <cstdlib> 
#include <ctime>
#include <stdlib.h>

const double DEGREES_TO_RADS_COEFF = 0.0174533;
double degreesToRad (double degrees)
{

    return degrees * DEGREES_TO_RADS_COEFF;

}

double factorial(double input)
{
    double sum = 1;
    for (int i = input; i > 1; i--)
        sum *= i;
    return sum;

}

double taylorSeriesSin(float input)
{

    double sum = 0;
    int sign = 1;
    double prev = 1;
    for(float i = 1; abs(sum - prev) > 0.00001; i+= 2)
    {

        prev = sum;

        sum += sign * (pow(input,i)/factorial(i));
        sign *= -1; 



    }
    if (abs(sum) < .001)
        return 0;
    return sum;

}

double taylorSeriesCos(float input)
{

    double sum = 0;
    int sign = 1;
    double prev = 1;
    for(float i = 0; abs(sum - prev) > 0.00001; i+= 2)
    {

        prev = sum;

        sum += sign * (pow(input,i)/factorial(i));
        sign *= -1; 



    }
    
    if (abs(sum) < .001)
        return 0;
    return sum;

}

int main ()
{
    

std::cout << std::setprecision(4) << std::fixed;;

double radians;

std::cout << "Degrees\t" << "Radians(x)\t" << "Sin(x)\t\t" << "Cos(x)\n";

    for (int i = -45; i <= 540; i+= 15)
    {
        radians = degreesToRad(i);
        std::cout << i << "\t\t" << radians << "\t\t" << taylorSeriesSin(radians) << "\t\t" << taylorSeriesCos(radians) << "\n";

    }





    
    



    





}

