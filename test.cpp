#include <iostream>
#include "Cnumbers.hpp"
#include "quaternion.hpp"
using namespace std;

#include "vectorspace.hpp"
#include "hilbertspace.hpp"

int main() {

    // Complex numbers
    cout << "Hello World!";
    cout << endl << "This is a test of the Cnumbers class." << endl;
    cout << "(3 + 4i) / (4 - 2i) = "; // should be 0.2 + 1.1i
    Complex<double> calc = (Complex<double>({3, 4}) / Complex<double>({4, -2}));
    cout << calc.real << " + " << calc.imaginary << "i" << endl;
    cout << "=> |(3 +4i) / (4 - 2i)| = "; // should be 1.11803
    cout << abs(calc) << endl;
    //cout << calc.real << " + " << calc.imaginary << "i" << endl;

    // Quaternions
    cout << endl << "This is a test of the Quaternion class." << endl;
    cout << "i*j*k = "; // should be -1
    Quaternion<double> calc2 = Quaternion<double>({0, 1, 0, 0}) * Quaternion<double>({0, 0, 1, 0}) * Quaternion<double>({0, 0, 0, 1});
    cout << calc2.real << " + " << calc2.i << "i + " << calc2.j << "j + " << calc2.k << "k" << endl;

    // Vectors
    cout << endl << "This is a test of vectorspcaces." << endl;
    cout << "defining a vector space V with the 3 bases: ((1, 1 + i, 0), (0, 1, 1 + i), (0, 0, i))" << endl;
    vectorspace::VectorSpace<Complex<int>> V = vectorspace::VectorSpace<Complex<int>>({{Complex<int>({0, 0}), Complex<int>({0, 0}), Complex<int>({0, 0})}, {{Complex<int>({1, 0}), Complex<int>({1, 1}), Complex<int>({0, 0})}, {Complex<int>({0, 0}), Complex<int>({1, 0}), Complex<int>({1, 1})}, {Complex<int>({0, 0}), Complex<int>({0, 0}), Complex<int>({0, 1})}}});
    cout << "defining a vector u = (1, 1 + i, 0) in V" << endl;
    vectorspace::vector<Complex<int>> u = vectorspace::vector<Complex<int>>({&V, {Complex<int>({1, 0}), Complex<int>({1, 1}), Complex<int>({0, 0})}});
    cout << "defining a vector v = (0, 1, 1 + i) in V" << endl;
    vectorspace::vector<Complex<int>> v = vectorspace::vector<Complex<int>>({&V, {Complex<int>({0, 0}), Complex<int>({1, 0}), Complex<int>({1, 1})}});
    cout << "u+v = "; // should be ((1 + 0i), (2 + 1i), (1 + 1i))
    vectorspace::vector<Complex<int>> calc3 = u + v;
    cout << "((" << calc3.elements[0].real << " + " << calc3.elements[0].imaginary << "i) + (" << calc3.elements[1].real << " + " << calc3.elements[1].imaginary << "i) + (" << calc3.elements[2].real << " + " << calc3.elements[2].imaginary << "i))" << endl << endl;

    cout << "inner_product(u, v) = ";
    Complex<int> calc4 = vectorspace::inner_product(vectorspace::HilbertSpace<Complex<int>>(), u.elements, v.elements);
    return 0;
}