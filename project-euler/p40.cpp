#include <iostream>
typedef unsigned int uint;

uint pow(uint n, uint p) {
  uint r = 1;
  for (uint i = 0; i < p; i++, r *= n);
  return r;
}

int main() {
  // The result
  uint res = 1;

  // Variables to control the nth digit searching
  uint nthDigitLimit = 10;
  uint totalDigits = 0;
  uint baseIncrementCount = 1;
  bool foundDigit = false;


  // Variables to control de digit count per number
  uint numDigitsPerNumber = 1;
  uint nextMaxNDigitNumber = 9;

  const uint LIMIT = 1000000;
  for (uint n = 1; n <= LIMIT; n++) {
    // Sum the digit count to the digit totals for this n
    totalDigits += numDigitsPerNumber;

    // Once we find that totalDigits is bigger than the limit for the
    // next searched digit, we search the digit inside the number n
    // p.e: totalDigits = 11, nthDigitLimit for n = 10
    //      then n = 10 contains the 10th digit, it is located at the
    //      totalDigits - nthDigitLimit = 1 position of n (counting from 0)
    //      this is: 10
    //               ^
    if (totalDigits >= nthDigitLimit) {
      uint pos = totalDigits - nthDigitLimit;
      uint digit = (n / pow(10, pos)) % 10;
      foundDigit = true;
      res *= digit;
    }

    // Increment the digit count per number if we reach the next limit (p.e: 9, 99, 999, etc)
    if (n == nextMaxNDigitNumber) {
      numDigitsPerNumber++;
      nextMaxNDigitNumber = pow(10, numDigitsPerNumber) - 1;
    }

    // Found a digit, so the next digit we'll be at 10^(baseIncrementCount + 1)
    if (foundDigit) {
      baseIncrementCount++;
      nthDigitLimit = pow(10, baseIncrementCount);
      foundDigit = false;
    }
  }
  std::cout << std::endl << res << std::endl;
}
