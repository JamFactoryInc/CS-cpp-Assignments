#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

bool cont = true;


using namespace std;

int randNum(){
    srand(time(NULL));
    int Num = (rand() % 3) + 1;
    return Num;
}

string compChoice(){
    int num;
    string choice;
    num = randNum();

    if(num == 1){
        choice = "Rock";
    }
    else if(num == 2){
        choice = "Paper";
    }
    else if(num == 3){
        choice = "Scissors";
    }
    return choice;
}

string userChoice(){
    string choice;
    cout << "Choices:" << endl;
    cout << "Rock" << endl;
    cout << "Paper" << endl;
    cout << "Scissors" << endl;
    cout << endl;
    cout << "Please pick what choice you'd like" << endl;
    cin >> choice;
    //choice = "Rock";
    return choice;
}



void winner(string computer, string user){
            if(computer == "Rock" && user == "Rock"){
                cout << "You tied!" << endl;
                return;
            }
            else if(computer == "Rock" && user == "Paper"){
                cout << "You won!" << endl;
                cont = false;
            }
            else if(computer == "Rock" && user == "Scissors"){
                cout << "You lost!" << endl;
                cont = false;
            }


            if(computer == "Paper" && user == "Paper"){
                cout << "You tied" << endl;
                return;
                
            }
            else if(computer == "Paper" && user == "Scissors"){
                cout << "You won!" << endl;
                cont = false;
            }
            else if(computer == "Paper" && user == "Rock"){
                cout << "You lost!" << endl;
                cont = false;
            }


            if(computer == "Scissors" && user == "Scissors"){
                cout << "You tied!" << endl;
                return;
            }
            else if(computer == "Scissors" && user == "Rock"){
                cout << "You won!" << endl;
                cont = false;
            }
            else if(computer == "Scissors" && user == "Paper"){
                cout << "You lost!" << endl;
                cont = false;
            }


}

void runGame(){
    string computer;
    string user;
    computer = compChoice();
    user = userChoice();
    cout << "Computer's choice is: " << computer << endl;
    cout << "Your choice is: " << user << endl;
    winner(computer, user);

}


int main()
{
    while(cont){
        runGame();
    }

    return 0;
}
