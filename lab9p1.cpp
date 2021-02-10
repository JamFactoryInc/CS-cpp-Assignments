//Team: Kieran Smith, Molly Vongsakhamphouy, and Mary Meineke

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <vector>
#include <ctime>

int numturns = 1;

using namespace std;
char board[3][3] = {{'O',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void displayBoard()
{

cout << "\n\n\n\n\n\nA   B   C\n\n" << board[0][0] << " # " << board[0][1] << " # " << board[0][2] << "  1\n#########\n" << board[1][0] << " # " << board[1][1] << " # " << board[1][2] << "  2\n#########\n" << board[2][0] << " # " << board[2][1] << " # " << board[2][2] << "  3\n";
        

}

bool checkForWinner()
{

    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
        return true;
    if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
        return true;
    if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        return true;
    if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        return true;
    if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        return true;
    if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
        return true;
    

    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
        return true;
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
        return true;
    if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
        return true;
    if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
        return true;
    if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        return true;
    if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        return true;

    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        return true;
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        return true;
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        return true;
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        return true;

    return false;
}

int getInput()
{
    
    int userInput = 0;
    string input = "A2";
    while(true)
        {
            cout << "Input your move (ex. A1):\n";
            cin >> input;
            
            userInput = ((int(toupper(input.at(0)))) - 65)*10 + int(toupper(input.at(1))) -49;
            if(board[userInput%10][userInput/10] != ' ')
                cout << "Please enter an empty space\n";
            else
                break;
        }
    board[userInput%10][userInput/10] = 'X';
    return userInput;
}

int main()
{
    int userInput = 0;
	char smart = ' ';
    cout << "Do you want to play an easy game or a hard game? Please type 'e' or 'h':";
    cin >> smart;
    //smart = 'e';
    if (smart == 'h')
    {


    beginning:
    int path = -1;
    for(int i = 1; i < 9; i++)
    {
        displayBoard();
        userInput = getInput();
        

        switch (i)
        {
            case 1:
            if(userInput == 11)
            {
                path = 2;
                board[0][2] = 'O';

            }
            else if (userInput == 10 || userInput == 20)
            {
                path = 1;
                board[2][0] = 'O';
            }
            else
            {
                path = 0;
                board[0][2] = 'O';
            }
            break;



            case 2:
            if(path == 2)
            {
                if(userInput != 10)
                {
                    board[0][1] = 'O';
                    
                    displayBoard();
                    cout << "You lose.";
                    return 0;
                }
                board[2][1] = 'O';
            }
            else if (path == 0)
            {
                if(userInput != 10 && board[2][1] != 'X')
                {
                    board[0][1] = 'O';
                    
                    displayBoard();
                    cout << "You lose.";
                    return 0;
                }
                if(board[2][1] == 'X')
                {

                    board[1][1] = 'O';

                }
                else if(board[2][2] == ' ')
                    board[2][2] = 'O';
                else
                    board[2][0] = 'O';
            }
            else if(path == 1)
            {
                
                if(userInput != 01)
                {
                    board[1][0] = 'O';
                    
                    displayBoard();
                    cout << "You lose.";
                    return 0;
                }
                board[2][2] = 'O';
                



            }
            break;

            case 3:
            if(path == 1)
            {
                if(userInput == 11)
                {
                    board[2][1] = 'O';
                    
                    displayBoard();
                    cout << "You lose.";
                    return 0;
                }
                if(userInput == 12)
                {
                    board[1][1] = 'O';
                    
                    displayBoard();
                    cout << "You lose.";
                    return 0;
                }



            }
            if(path == 0)
            {
                if(board[2][1] == ' ')
                {
                    if(userInput != 11)
                    {
                        board[1][1] = 'O';
                    
                        displayBoard();
                        cout << "You lose.";
                        return 0;
                    }
                    else if(board[2][2] == 'O')
                    {
                        board[1][2] = 'O';
                    
                        displayBoard();
                        cout << "You lose.";
                        return 0;
                    }
                    else
                    {
                        board[1][0] = 'O';
                    
                        displayBoard();
                        cout << "You lose.";
                        return 0;
                    }
                }
                else
                {
                    if(board[2][0] == ' ')
                        board[2][0] = 'O';
                    else
                        board[2][2] = 'O';

                    displayBoard();
                    cout << "You lose.";
                    return 0;

                }

            }

            if(path == 2)
                {   
                    
                    if(board[1][0] == ' ')
                        board[1][0] = 'O';
                    else board[1][2] = 'O';
                    displayBoard();
                    cout << "It's a draw. Play again? y/n";
                    char play = ' ';
                    cin >> play;
                    if(play == 'y')
                        goto beginning;
                    return 0;


                
                
                
                


            }
            
            
        }

        

    }

    }

    else
    {

        int userChoice= 0;

        for(int i = 0; i < 9; i++)
        {
            displayBoard();

            userChoice = getInput();

            numturns ++;
            if(numturns >= 8)
            {
                cout << "It's a draw. Play again? y/n";
                    char play = ' ';
                    cin >> play;
                    if(play == 'y')
                        goto beginning;
                    return 0;

            }
            
            if(checkForWinner())
            {
                displayBoard();
                cout << "You win!";
                return 0;
            }
            srand (time(NULL));
            int compChoiceR = rand()%3;
            int compChoiceC = rand()%3;
            while(board[compChoiceR][compChoiceC] != ' ')
            {
                compChoiceR = rand()%3;
                compChoiceC = rand()%3;
            }
            board[compChoiceR][compChoiceC] = 'O';
            if(checkForWinner())
            {
                displayBoard();
                cout << "You lose.";
                return 0;
            }
            numturns ++;
            if(numturns >= 8)
            {
                cout << "It's a draw. Play again? y/n";
                char play = ' ';
                cin >> play;
                if(play == 'y')
                    goto beginning;
                return 0;

            }
            

            
            

        }

    }
}

