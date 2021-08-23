#ifndef EX03_05
#define EX03_05

///@file Ex03.05.h

/**
* Method to swap two values
* @param first Pointer to first value
* @param second Pointer to second value
*/
void Swap(int *first, int *second);

/**
* Transposes a sideLength x sideLength matrix
* @param matrix The matrix to transpose
* @param sideLength The length of one side of the matrix
*/
void Transpose(int (*matrix)[], size_t sideLength);

/**
* Prints out a matrix onto the console. Spaces between values, newlines for each row
* @param matrix The matrix to print out
* @param sideLength The length of one side of the matrix
*/
void PrintMatrix(int(*matrix)[], size_t sideLength);
#endif