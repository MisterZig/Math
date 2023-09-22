#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <cmath> // sqrt

template <typename T>
struct Quaternion {
    T real;
    T i;
    T j;
    T k;
};

template <typename T>
Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
    return {lhs.real + rhs.real, lhs.i + rhs.i, lhs.j + rhs.j, lhs.k + rhs.k};
}

template <typename T>
Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
    return {lhs.real - rhs.real, lhs.i - rhs.i, lhs.j - rhs.j, lhs.k - rhs.k};
}

template <typename T>
Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
    return {
        lhs.real * rhs.real - lhs.i * rhs.i - lhs.j * rhs.j - lhs.k * rhs.k,
        lhs.real * rhs.i + lhs.i * rhs.real + lhs.j * rhs.k - lhs.k * rhs.j,
        lhs.real * rhs.j - lhs.i * rhs.k + lhs.j * rhs.real + lhs.k * rhs.i,
        lhs.real * rhs.k + lhs.i * rhs.j - lhs.j * rhs.i + lhs.k * rhs.real
    };
}

template <typename T>
Quaternion<T> operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
    return {
        (lhs.real * rhs.real + lhs.i * rhs.i + lhs.j * rhs.j + lhs.k * rhs.k) /
            (rhs.real * rhs.real + rhs.i * rhs.i + rhs.j * rhs.j + rhs.k * rhs.k),
        (lhs.i * rhs.real - lhs.real * rhs.i - lhs.j * rhs.k + lhs.k * rhs.j) /
            (rhs.real * rhs.real + rhs.i * rhs.i + rhs.j * rhs.j + rhs.k * rhs.k),
        (lhs.j * rhs.real + lhs.real * rhs.j - lhs.i * rhs.k - lhs.k * rhs.i) /
            (rhs.real * rhs.real + rhs.i * rhs.i + rhs.j * rhs.j + rhs.k * rhs.k),
        (lhs.k * rhs.real + lhs.real * rhs.k + lhs.i * rhs.j - lhs.j * rhs.i) /
            (rhs.real * rhs.real + rhs.i * rhs.i + rhs.j * rhs.j + rhs.k * rhs.k)
    };
}

template <typename T>
Quaternion<T> conjugate(const Quaternion<T>& alpha) {
    return {alpha.real, -alpha.i, -alpha.j, -alpha.k};
}

template <typename T>
T abs(const Quaternion<T>& alpha) {
    return sqrt(alpha.real * alpha.real + alpha.i * alpha.i + alpha.j * alpha.j + alpha.k * alpha.k);
}

template <typename T>
Quaternion<T> sqrt(const Quaternion<T>& alpha) {
    return {
        sqrt((alpha.real + abs_quaternion(alpha)) / 2),
        sqrt((-1 * alpha.real + abs_quaternion(alpha)) / 2),
        sqrt((-1 * alpha.real + abs_quaternion(alpha)) / 2),
        sqrt((-1 * alpha.real + abs_quaternion(alpha)) / 2)
    };
}

#endif // QUATERNION_HPP