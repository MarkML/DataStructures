// Calculates the factorial of a number

#include <iostream>
using namespace std;

// Assume num will always be positive
int Factorial(int num) {
	// Base case
	if (num == 1) {
	    return 1;
	}
	int fact = Factorial(num - 1);
	return num * fact;
}

int main() {
	int num = 5;
	int res = Factorial(num);
	     
	cout << "The factorial of " << num << " is: " << res << endl;
}