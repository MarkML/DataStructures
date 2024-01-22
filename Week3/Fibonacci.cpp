// Calculates the Fibonacci sequence up to a given number n

#include <iostream>
using namespace std;

// Assume num will always be positive
int Fibonacci(int num) {
	// Base case
	if (num <= 1) {
	    return num;
	}
	return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main() {
	int num = 6;
	int res = Fibonacci(num);
	     
	cout << "The " << num << "th number in the Fibonacci sequence is: " << res << endl;
}