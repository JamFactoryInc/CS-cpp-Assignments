// Lab5_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double deg = -45;
double rad;
double step = 15;
double sinx = 0;
double degreesToRadians(double x) {
	if (x >= 360){

		x = x - 360;

	}
	x = x * 0.0174533;
	return x;

}
double factorial(int x) {
	double sum = 1;
    	for (int i = x; i > 1; i--)
        	sum = sum * i;
    	return sum;

}
double mysine(double x) {
	double sum = 0;
	double prev = 1;
	double sign = 1;
	double k = 1; 
	

	while ( abs(sum-prev) > 0.00001) {

		
		prev = sum;

		sum += sign*(pow(x, k) / factorial(k));
		//cout << pow(x, k) / factorial(k) << "	" << k << endl;
		sign *= -1;
	
		
		k = k + 2;

		
		
	}
	
	return sum;

}

double mycosine(double x) {
	double sum = 0;
	double prev = 1;
	double sign = 1;
	double k = 0; 
	

	while ( abs(sum-prev) > 0.00001) {

		
		prev = sum;

		sum += sign*(pow(x, k) / factorial(k));
		//cout << pow(x, k) / factorial(k) << "	" << k << endl;
		sign *= -1;
	
		
		k = k + 2;

		
		
	}
	
	return sum;

}


int main()
{
	cout << "Degrees	Radians(x)	Sin(x)	Cosine(x)" << endl;
	
	for (deg; deg <= 540; deg = deg+15) {
		rad = degreesToRadians(deg);
		sinx = mysine(rad);
		cout << deg << "\t" << rad << "\t\t"<< sinx << "\t\t" << mycosine(rad) << endl;

	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
