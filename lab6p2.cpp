#include<iostream>
#include <iomanip>
#include<cmath>
#include <cstdlib> 
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int generateNum()
{

    srand(time(0));
    return rand()% 3 + 1;

}

string numToRPS(int num)
{

    switch (num)
    {
        case 1:
        return "rock";
        break;

        case 2:
        return "paper"; 
        break;

        case 3:
        return "scissors";
        break;
    }
    return "err";

}

int getUserInput()
{

    int num = 0;
    while (num < 1 || num > 3)
    {

    cout << "Please enter a number 1-3;\nRock = 1\nPaper = 2\nScissors = 3\n";
    cin >> num;

    }

    return num;


}

string determineWinner(int userIn, int computerNum)
{

    if(userIn == computerNum )
        return "Draw\n";
    else if(userIn == 1 && computerNum == 3)
        return "Rock smashes scissors.\nYou win!\n";
    else if(userIn == 3 && computerNum == 1)
        return "Rock smashes scissors.\nYou lose\n";
    else if(userIn == 2 && computerNum == 3)
        return "Scissors cut paper.\nYou lose\n";
    else if(userIn == 3 && computerNum == 2)
        return "Scissors cut paper.\nYou win!\n";
    else if(userIn == 2 && computerNum == 1)
        return "Paper Covers Rock.\nYou win!\n";
    else if(userIn == 1 && computerNum == 2)
        return "Paper Covers Rock.\nYou lose\n";
    else
        return "err\n";
    

}

void display()
{
    int userIn = getUserInput();
    int computerNum = generateNum();
    cout << "You chose: " << numToRPS(userIn) << "\nComputer chose: " << numToRPS(computerNum) << "\n" << determineWinner(userIn,computerNum);


}



int main()
{
    bool cont = true;
    string yn;
    while(cont)
    {
        

        display();
        
        cout << "Play again?\nY/N\n";
        cin >> yn;
        if(yn == "N")
            cont = false;


    }


return 0;
}

