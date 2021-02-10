#include<iostream>
#include <iomanip>
#include<math.h>

int main ()
{

    int iterations;

    std::cin >> iterations;
    int iterationsCopy = iterations;
    int step = 1;

    
    std::cout << std::fixed << std::setprecision(5) << "x\t\tlog10(x)\tlog2(x)\t\tln(x)\n";
    loop:
    for (int i = 0; i < 10; i ++)
    {

        if(iterationsCopy != iterations && iterationsCopy >= 0 && i * step != 0)
            std::cout << i*step << "\t\t" << log10(i*step)  << "\t\t" << log2(i*step) << "\t\t" << log(i*step) << "\n"; 
        iterations --;
    }
    if(iterations > 0)
    {
        step *= 10;
        goto loop;

    }



    

    



}