#include <iostream>
#include "Cnumbers.hpp"
#include "quaternion.hpp"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "This is a test of the Cnumbers class." << endl;
    cout << "(3 + 4i) / (4 - 2i) = "; // should be 0.2 + 1.1i
    Complex<double> calc = (Complex<double>({3, 4}) / Complex<double>({4, -2}));
    cout << calc.real << " + " << calc.imaginary << "i" << endl;
    cout << "=> |(3 +4i) / (4 - 2i)| = "; // should be 1.11803
    cout << abs(calc) << endl;
    //cout << calc.real << " + " << calc.imaginary << "i" << endl;

    cout << "This is a test of the Quaternion class." << endl;
    cout << "i*j*k = "; // should be -1
    Quaternion<double> calc2 = Quaternion<double>({0, 1, 0, 0}) * Quaternion<double>({0, 0, 1, 0}) * Quaternion<double>({0, 0, 0, 1});
    cout << calc2.real << " + " << calc2.i << "i + " << calc2.j << "j + " << calc2.k << "k" << endl;
    return 0;
}