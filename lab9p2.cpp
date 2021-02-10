#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <ctype.h>


using namespace std;

string lowerCaseString (string & source)
{
	string str = "";
	for (int i = 0; i < source.length(); i++)
        str += tolower(source[i]);
	source = str;
	return str;


}


bool substitution (string & source, string cipherKey, string & destination)
{
	bool canCipher = false;
	string output = "";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < source.length(); i++)
		if(isalpha(source[i]))
		{
			output += cipherKey[alpha.find(source[i])];
			canCipher = true;
		}

		else
			output += source[i];
	destination = output;



	return canCipher;
}

int main(){

	string file_string;
	
	ifstream inFile;
	inFile.open("Temp.txt"); /*make necessary change for 
                                       file access path*/
	if (!inFile){
		cout << "Input file cannot be opened" << endl;
           return 0;
	}
	stringstream buffer;
	buffer << inFile.rdbuf();
	file_string = buffer.str();

    lowerCaseString(file_string);
	string str = "";

	substitution(file_string, "abcdefghijklmnopqrstuvwxyz", str);

	cout << str;



}
