#include <stdio.h>
#include "Ex03.05.h"

int main(void)
{
    int matrix[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    Transpose(matrix, 3);
    PrintMatrix(matrix, 3);
}

void Swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Transpose(int(*matrix)[], size_t sideLength)
{
    for (size_t row = 0; row < sideLength; ++row)
    {
        for (size_t column = 0; column < row; ++column)
        {
            {
                Swap((int *)matrix + row * sideLength + column, (int *)matrix + column * sideLength + row);
            }
        }
    }
}

void PrintMatrix(int(*matrix)[], size_t sideLength)
{
    for (size_t row = 0; row < sideLength; ++row)
    {
        for (size_t column = 0; column < sideLength; ++column)
        {
            printf_s("%i ", ((int *)matrix + row * sideLength)[column]);
        }
        printf_s("\n");
    }
}