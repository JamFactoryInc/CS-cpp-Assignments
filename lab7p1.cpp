#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <vector>

using namespace std;



bool arrayFind(int arr [], unsigned length, int searchVal)
{

    for(int i = 0; i < length; i++)
         if (searchVal==arr[i])
                return true;
    return false;

}

bool isSorted(int array[], unsigned length)
{
    int prev = -2147483648;
    if(length > 0)
        for(int i = 0; i < length; i++)
        {
            if(array[i] < prev)
                return false;
            prev = array[i];
        }
    else
        return false;
    return true;
    

}


int arrSetSize(int array[], unsigned length)
{
    int count = 0;
    int vals [length];
    for (int i = 0; i < length; i++)
        if(!arrayFind(vals, length, array[i]))
        {
            vals[i] = array[i];
            count ++;
        }

    return count;
        



}

int range(int array[], unsigned length)
{
    if(length == 0)
        return 0;
    int prevMin = 2147483647;
    int prevMax = -2147483648;
    for (int i = 0; i < length; i++)
    {
        if(array[i] < prevMin)
            prevMin = array[i];
        if(array[i] > prevMax)
            prevMax = array[i];
    }

    return prevMax - prevMin;

}

bool vectorFind(vector<int> vect, int searchVal)
{
    for(int i = 0; i < vect.size(); i++) 
    {
        if (searchVal==vect[i])
                return true;
    
    }
    return false;
}



void  reverse(vector<int> &vect)
{
    vector<int> temp;
    for(auto i=vect.rbegin(); i!=vect.rend(); ++i)
	    temp.push_back(*i);
        
    vect = temp;

    

}

vector<int> removeDups(vector<int> vect)
{
    vector<int> vals;
    for(auto i=vect.rbegin(); i!=vect.rend(); ++i) 
    {

        if(!vectorFind(vals,*i))
        {
            
            vals.push_back(*i);
            
        }
    }
    reverse(vals);
    return vals;

}

int countUpperChars(const string & mystring)
{
    int count;
    for (char const &c:mystring)
        if(isupper(c))
            count++;

    return count;
}

int numLines(const string & mystring)
{
    int count;
    for (char const &c:mystring)
        if(c == '\n')
            count++;

    return count+1;
}
int numWords(const string & mystring)
{
    int count;

    for (int i = 0; i < mystring.size()-1; i++)
        if((mystring[i] == ' ' || mystring[i] == '\n' || mystring[i] == '\t') && (mystring[i+1] !=  ' ' || mystring[i+1] != '\n' || mystring[i+1] != '\t'))
            count++;

    return count;
}

vector<int> characterCounts(const string & mystring)
{
    vector<int> out = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for (int i = 0; i < mystring.size(); i++)
        if(isalpha(mystring[i]))
            out[tolower(mystring[i]) - 97]++;
        
    return out;
}

bool convertToUpper(const string & mystring)
{

    if(mystring.size() == 0)
        return false;
    ofstream myfile;
    myfile.open ("Upper.txt");
    for (int i = 0; i < mystring.size(); i++)
        if(isalpha(mystring[i]) && mystring[i] > 95)
            myfile << char(mystring[i] - 32);
        else
            myfile << mystring[i];
        
    
    
    
    
    myfile.close();
    return true;

}

int main()
{
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
    convertToUpper(file_string);
}

