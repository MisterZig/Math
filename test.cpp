#include <iostream>
#include "Cnumbers.hpp"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "This is a test of the Cnumbers class." << endl;
    cout << "(3 + 4i) / (4 - 2i) = ";
    Complex<double> calc = (Complex<double>({3, 4}) / Complex<double>({4, -2}));
    cout << abs_complex(calc) << endl;
    //cout << calc.real << " + " << calc.imaginary << "i" << endl;
    return 0;
}