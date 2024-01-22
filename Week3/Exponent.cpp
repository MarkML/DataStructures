// Calculates the exponent of a number

#include <iostream>
using namespace std;

// Assume base and exponent will always be positive
int Power(int base, int exponent) {
   // Base case
   if (exponent == 0) {
        return 1;
   }
   return base * Power(base, exponent - 1);
}

int main() {
   int base = 2;
   int exponent = 3;
   int res = Power(base, exponent);
         
   cout << base << " raised to the power of " << exponent << " is: " << res << endl;
}