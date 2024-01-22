// Calculates the sum of the first n natural numbers

#include <iostream>
using namespace std;

// Assume num will always be positive
int SumNaturalNumbers(int num) {
	// Base case
	if (num == 1) {
	    return 1;
	}
	int sum = SumNaturalNumbers(num - 1);
	return num + sum;
}

int main() {
	int num = 3;
	int res = SumNaturalNumbers(num);
	     
	cout << "The sum of the first " << num << " natural numbers is: " << res << endl;
}