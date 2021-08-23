#ifndef EX03_04
#define EX03_04

///@file Ex03.04.h

typedef struct uint96_t
{
    uint64_t upperBits;
    uint32_t lowerBits;
} uint96_t;

/**
 * @brief Given a positive number n, will return the nth number in the fibonacci sequence, using lazy evaluation
*/
uint96_t CalculateFibonacciLazy(size_t fibIndex);

/**
* Adds two uint96_t types together
*/
uint96_t Add(uint96_t x, uint96_t y);

/**
* Subtracts y from x. x must be greater than y
*/
uint96_t Subtract(uint96_t x, uint96_t y);

/**
* Multiplies a uint96_t by a normal int
*/
uint96_t MultiplyByInt(uint96_t x, int y);

/**
* Returns which number passed is bigger.
* 0 = first number bigger. 1 = second number bigger. -1 = numbers are equal
*/
short GreaterUInt128(uint96_t x, uint96_t y);

/**
* Calculates the highest decimal place of a number.
* For example, 100 would return 3
*/
int HighestDecimalPlace(uint96_t bigNum);

/**
 * @brief Returns 10 to the power of exponent
*/
uint96_t GetDecimal(int exponent);

/**
* Performs integer division on uint96_t. Only use if result will be less than 10
*/
int Int128Div(uint96_t x, uint96_t y);

/**
* Prints out uint96_t type numbers
*/
void PrintUInt128(uint96_t bigNum);

#endif