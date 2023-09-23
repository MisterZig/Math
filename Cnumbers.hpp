// Headerfile for Complex number types and operators in C++

#ifndef COMPLEX_NUMBERS_HPP
#define COMPLEX_NUMBERS_HPP

#include <cmath> // sqrt

template <typename T>
struct Complex {
    T real;
    T imaginary;
};

template <typename T>
Complex<T> operator+(const Complex<T>& lhs, const Complex<T>& rhs) {
    return {lhs.real + rhs.real, lhs.imaginary + rhs.imaginary};
}

template <typename T>
Complex<T> operator-(const Complex<T>& lhs, const Complex<T>& rhs) {
    return {lhs.real - rhs.real, lhs.imaginary - rhs.imaginary};
}

template <typename T>
Complex<T> operator-(const Complex<T>& rhs) {
    return {-rhs.real, -rhs.imaginary};
}

template <typename T>
Complex<T> operator*(const Complex<T>& lhs, const Complex<T>& rhs) {
    return {lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
            lhs.real * rhs.imaginary + lhs.imaginary * rhs.real};
}

template <typename T>
Complex<T> operator/(const Complex<T>& lhs, const Complex<T>& rhs) {
    return {(lhs.real * rhs.real + lhs.imaginary * rhs.imaginary) /
                (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary),
            (lhs.imaginary * rhs.real - lhs.real * rhs.imaginary) /
                (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary)};
}

template <typename T>
Complex<T> onjugate(const Complex<T>& alpha) {
    return {alpha.real, -alpha.imaginary};
}

template <typename T>
T abs(const Complex<T>& alpha) {
    return sqrt(alpha.real * alpha.real + alpha.imaginary * alpha.imaginary);
}

template <typename T>
Complex<T> sqrt(const Complex<T>& alpha) {
    return {sqrt((alpha.real + abs_complex(alpha)) / 2),
            sqrt((-1 * alpha.real + abs_complex(alpha)) / 2)};
}

// Mixed operators
template <typename T>
Complex<T> operator+(const Complex<T>& lhs, const T& rhs) {
    return {lhs.real + rhs, lhs.imaginary};
}

template <typename T>
Complex<T> operator+(const T& lhs, const Complex<T>& rhs) {
    return {rhs.real + lhs, rhs.imaginary};
}

template <typename T>
Complex<T> operator-(const Complex<T>& lhs, const T& rhs) {
    return {lhs.real - rhs, lhs.imaginary};
}

template <typename T>
Complex<T> operator-(const T& lhs, const Complex<T>& rhs) {
    return {rhs.real - lhs, -rhs.imaginary};
}

template <typename T>
Complex<T> operator*(const Complex<T>& lhs, const T& rhs) {
    return {lhs.real * rhs, lhs.imaginary * rhs};
}

template <typename T>
Complex<T> operator*(const T& lhs, const Complex<T>& rhs) {
    return {rhs.real * lhs, rhs.imaginary * lhs};
}

template <typename T>
Complex<T> operator/(const Complex<T>& lhs, const T& rhs) {
    return {lhs.real / rhs, lhs.imaginary / rhs};
}

template <typename T>
Complex<T> operator/(const T& lhs, const Complex<T>& rhs) {
    return {lhs * rhs.real / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary),
            -lhs * rhs.imaginary / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary)};
}

#endif // COMPLEX_NUMBERS_HPP