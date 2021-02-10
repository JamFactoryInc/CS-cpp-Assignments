#include<iostream>
#include <iomanip>
#include<math.h>
#include <cstdlib> 
#include <ctime>

int main ()
{
    srand(time(0));
    rollAgain:
    int roll1 = rand() % 6 + 1;
    int roll2 = rand() % 6 + 1;
    int total = roll1 + roll2;
    
    std::cout << "Die 1: " << roll1 << "\tDie 2: " << roll2 << "\tTotal: " << total << "\n";

    if(total == 7 || total == 9 || total == 11)
        std::cout << "You win";
    else if(total == 2 || total == 3 || total == 5)
        std::cout << "You Lose";
    else
    {
        std::cout << "Rolling again...\n";
        goto rollAgain;
    }
    
    



    

    



}