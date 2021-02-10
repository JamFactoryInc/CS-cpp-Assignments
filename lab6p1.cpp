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
float voltage;
int circNum = 1;
float current;
float currentPow;
ofstream writeOutput;
float rmax = 0;
float rmin = 2147483647;
int rtotal = 0;
float sum = 0;


void rMinMax(float myResist, float minResist, float maxResist)
{



}

void numResist(float myResist, float sumResist, float numResist)
{



}

float currentPower(float sumResist, float power, float currentFlow)
{


return 0;

}

void writeToFile(int &rtotal, float &sum, float &rmin, float &rmax)
{ 
    current = voltage/sum;
    currentPow = current * voltage;
    writeOutput << "cktNo: " <<  circNum++ << " voltage:" << voltage <<  " Num_resistors: " <<  rtotal    << " Ohm_sum: " <<  sum << " Rmin: " << rmin << " Rmax: " << rmax << " current: " << current <<" power: " << currentPow << "\n";
    rmax = 0;
    rmin = 2147483647;
    rtotal = 0;
    sum = 0; 

}



int main()
{
writeOutput.open ("output.txt");
ifstream input ("input.txt");
string str;



while(getline(input,str))
{
    istringstream is( str );
    float n;
    while( is >> n ) 
    {
        if(n >= 0)
        {
            rmax = max(rmax,float(n));
            rmin = min(rmin,float(n));
            rtotal++;
            sum += n;
        }
        else
        {
            cout << "Enter voltage for circut " << circNum << endl;
            cin >> voltage;
            writeToFile(rtotal, sum, rmin, rmax);
        }
    }
}
input.close();
writeOutput.close();  
}