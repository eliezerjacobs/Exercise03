#include <stdio.h>
#include <stdint.h>
#include "Ex03.04.h"

int main(void)
{
    size_t fibIndex;
    printf_s("Enter a number: ");
    scanf_s("%zi", &fibIndex);
    printf_s("The %zith fibonacci number is: ", fibIndex);
    PrintUInt128(CalculateFibonacciLazy(fibIndex));
}

uint96_t CalculateFibonacciLazy(size_t fibIndex)
{
    uint96_t firstNumber = { 0,1 };
    uint96_t secondNumber = { 0,0 };
    uint96_t temp = { 0,0 };

    for (size_t i = 1; i < fibIndex; ++i)
    {
        temp = Add(firstNumber, secondNumber);
        secondNumber = firstNumber;
        firstNumber = temp;
    }
    return firstNumber;
}

uint96_t Add(uint96_t x, uint96_t y)
{
    uint96_t result;

    result.lowerBits = x.lowerBits + y.lowerBits;
    result.upperBits = x.upperBits + y.upperBits;
    if (UINT32_MAX - x.lowerBits < y.lowerBits)     //check for overflow
    {
        ++result.upperBits;
    }

    return result;
}

uint96_t Subtract(uint96_t x, uint96_t y)
{
    uint96_t result;

    result.lowerBits = x.lowerBits - y.lowerBits;
    result.upperBits = x.upperBits - y.upperBits;
    if (x.lowerBits < y.lowerBits)                  //check for overflow
    {
        --result.upperBits;
    }

    return result;
}

uint96_t MultiplyByInt(uint96_t x, int y)
{
    uint64_t temp = (uint64_t)x.lowerBits * y;
    x.lowerBits = (uint32_t)temp;
    x.upperBits *= y;
    x.upperBits += temp >> 32;
    return x;
}

short GreaterUInt128(uint96_t x, uint96_t y)
{
    short result = 0;
    if (x.upperBits > y.upperBits)
    {
        ++result;
    }
    else if (x.upperBits == y.upperBits)
    {
        if (x.lowerBits > y.lowerBits)
        {
            ++result;
        }
    }
    return result;
}

int HighestDecimalPlace(uint96_t bigNum)
{
    int count = 0;
    uint96_t nextDec = { 0,1 };

    while (!GreaterUInt128(nextDec, bigNum))      // find highest power of 10 that is bigger than bigNum
    {
        nextDec = MultiplyByInt(nextDec, 10);
        ++count;
    }

    return count;
}

uint96_t GetDecimal(int exponent)
{
    uint96_t decimal = { 0,1 };
    while (exponent)
    {
        decimal = MultiplyByInt(decimal, 10);
        --exponent;
    }
    return decimal;
}

int Int128Div(uint96_t x, uint96_t y)
{
    int count = 0;
    while (!GreaterUInt128(y, x))      // while y is less than or equal to x
    {
        x = Subtract(x, y);
        ++count;
    }

    return count;
}

void PrintUInt128(uint96_t bigNum)
{
    int decimalPlace = HighestDecimalPlace(bigNum);
    while (decimalPlace)
    {
        uint96_t decimal = GetDecimal(decimalPlace - 1);           // set number to mod by to get correct digit in nth position
        int digit = Int128Div(bigNum, decimal);
        printf_s("%i", digit);
        bigNum = Subtract(bigNum, MultiplyByInt(decimal, digit));
        decimal = GetDecimal(--decimalPlace);
    }
}