#include <stdio.h>
#include "Ex03.06.h"

#define SIDE_LENGTH 3

int main(void)
{
    int matrix[][SIDE_LENGTH] = { {1,-2,3}, {2,5,-6}, {-3,6,9} };
    Transpose(matrix, SIDE_LENGTH);
    PrintMatrix(matrix, SIDE_LENGTH);
    if (CheckSymmetric(matrix, SIDE_LENGTH))
    {
        printf_s("Matrix is symmetric\n");
    }
    else if (CheckSkewSymmetric(matrix, SIDE_LENGTH))
    {
        printf_s("Matrix is skew-symmetric\n");
    }
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

int CheckSymmetric(int(*matrix)[], size_t sideLength)
{
    int result = 1;
    for (size_t row = 0; result && row < sideLength; ++row)
    {
        for (size_t column = 0; result && column < row; ++column)
        {
            if (((int *)matrix + row * sideLength)[column] != ((int *)matrix + column * sideLength)[row])
            {
                result = 0;
            }
        }
    }

    return result;
}

int CheckSkewSymmetric(int(*matrix)[], size_t sideLength)
{
    int result = 1;
    for (size_t row = 0; result && row < sideLength; ++row)
    {
        for (size_t column = 0; result && column < row; ++column)
        {
            if (((int *)matrix + row * sideLength)[column] != -((int *)matrix + column * sideLength)[row])
            {
                result = 0;
            }
        }
    }

    return result;
}