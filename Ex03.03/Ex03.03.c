#include <stdio.h>
#include "Ex03.03.h"

int main(void)
{
    size_t fibIndex;
    printf_s("Enter a number: ");
    scanf_s("%i", &fibIndex);
    printf_s("The %ith fibonacci number is: %i", fibIndex, CalculateFibonacci(fibIndex));
}

int CalculateFibonacci(size_t fibIndex)
{
    if (fibIndex == 1 || fibIndex == 2) 
        return 1;
    else
    {
        return CalculateFibonacci(fibIndex - 1) + CalculateFibonacci(fibIndex - 2);
    }
}