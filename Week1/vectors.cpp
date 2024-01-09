#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Example 1: Declaring a vector with no values
    vector<int> emptyVector;

    // Example 2: Creating and initializing vectors with integers
    vector<int> vectorA = {2, 4, 6};
    vector<int> vectorB = {1, 3, 5};

    // Example 3: Vector addition with integers
    vector<int> sumVector(vectorA.size());
    for (int i = 0; i < vectorA.size(); ++i) {
        sumVector[i] = vectorA[i] + vectorB[i];
    }

    // Example 4: Vector subtraction with integers
    vector<int> diffVector(vectorA.size());
    for (int i = 0; i < vectorA.size(); ++i) {
        diffVector[i] = vectorA[i] - vectorB[i];
    }

    // Example 5: Scalar multiplication of a vector with integers
    int scalar = 3;
    vector<int> scaledVector(vectorA.size());
    for (int i = 0; i < vectorA.size(); ++i) {
        scaledVector[i] = vectorA[i] * scalar;
    }

    // Example 6: Creating and initializing vectors with strings
    vector<string> stringVectorA = {"Hello", "World"};
    vector<string> stringVectorB = {"C++", "Programming"};

    // Example 7: Vector concatenation with strings
    vector<string> concatVector(stringVectorA.size());
    for (int i = 0; i < stringVectorA.size(); ++i) {
        concatVector[i] = stringVectorA[i] + " " + stringVectorB[i];
    }

    // Example 8: Creating and initializing vectors with doubles
    vector<double> doubleVectorA = {1.5, 2.5, 3.5};
    vector<double> doubleVectorB = {0.5, 1.0, 1.5};

    // Example 9: Vector multiplication with doubles
    vector<double> productVector(doubleVectorA.size());
    for (int i = 0; i < doubleVectorA.size(); ++i) {
        productVector[i] = doubleVectorA[i] * doubleVectorB[i];
    }

    // Displaying results for empty vector
    cout << "Empty Vector: ";
    for (int i = 0; i < emptyVector.size(); ++i) {
        cout << emptyVector[i] << " ";
    }
    cout << endl;

    // Displaying results for integer vectors
    cout << "Integer Vector A: ";
    for (int i = 0; i < vectorA.size(); ++i) {
        cout << vectorA[i] << " ";
    }
    cout << endl;

    cout << "Integer Vector B: ";
    for (int i = 0; i < vectorB.size(); ++i) {
        cout << vectorB[i] << " ";
    }
    cout << endl;

    cout << "Integer Vector A + Integer Vector B: ";
    for (int i = 0; i < sumVector.size(); ++i) {
        cout << sumVector[i] << " ";
    }
    cout << endl;

    cout << "Integer Vector A - Integer Vector B: ";
    for (int i = 0; i < diffVector.size(); ++i) {
        cout << diffVector[i] << " ";
    }
    cout << endl;

    cout << "Scalar * Integer Vector A: ";
    for (int i = 0; i < scaledVector.size(); ++i) {
        cout << scaledVector[i] << " ";
    }
    cout << endl;

    // Displaying results for string vectors
    cout << "String Vector A: ";
    for (int i = 0; i < stringVectorA.size(); ++i) {
        cout << stringVectorA[i] << " ";
    }
    cout << endl;

    cout << "String Vector B: ";
    for (int i = 0; i < stringVectorB.size(); ++i) {
        cout << stringVectorB[i] << " ";
    }
    cout << endl;

    cout << "Concatenated String Vector: ";
    for (int i = 0; i < concatVector.size(); ++i) {
        cout << concatVector[i] << " ";
    }
    cout << endl;

    // Displaying results for double vectors
    cout << "Double Vector A: ";
    for (int i = 0; i < doubleVectorA.size(); ++i) {
        cout << doubleVectorA[i] << " ";
    }
    cout << endl;

    cout << "Double Vector B: ";
    for (int i = 0; i < doubleVectorB.size(); ++i) {
        cout << doubleVectorB[i] << " ";
    }
    cout << endl;

    cout << "Double Vector A * Double Vector B: ";
    for (int i = 0; i < productVector.size(); ++i) {
        cout << productVector[i] << " ";
    }
    cout << endl;

    return 0;
}

