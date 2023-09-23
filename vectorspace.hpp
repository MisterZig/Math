#ifndef VECTORSPACE_HPP
#define VECTORSPACE_HPP

#include <vector>

namespace vectorspace {
    template <typename T>
    struct VectorSpace {
        std::vector<T> origin;
        std::vector<std::vector<T>> bases;
    };

    template <typename T>
    struct vector {
        VectorSpace<T> * vector_space;
        std::vector<T> elements;
    };
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    std::vector<T> result;
    for (int i = 0; i < lhs.size(); i++) {
        result.push_back(lhs[i] + rhs[i]);
    }
    return result;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    std::vector<T> result;
    for (int i = 0; i < lhs.size(); i++) {
        result.push_back(lhs[i] - rhs[i]);
    }
    return result;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& rhs) {
    std::vector<T> result;
    for (int i = 0; i < rhs.size(); i++) {
        result.push_back(-rhs[i]);
    }
    return result;
}

template <typename T>
std::vector<T> operator*(const T lhs, const std::vector<T>& rhs) {
    std::vector<T> result;
    for (int i = 0; i < rhs.size(); i++) {
        result.push_back(lhs * rhs[i]);
    }
    return result;
}

template <typename T>
std::vector<T> operator*(const std::vector<T>& lhs, const T rhs) {
    return rhs*lhs;
}

template <typename T>
vectorspace::vector<T> operator+(const vectorspace::vector<T>& lhs, const vectorspace::vector<T>& rhs) {
    if (lhs.vector_space != rhs.vector_space) {
        throw "Error: vector spaces do not match.";
    }
    return {lhs.vector_space, lhs.elements + rhs.elements};
}

template <typename T>
vectorspace::vector<T> operator-(const vectorspace::vector<T>& lhs, const vectorspace::vector<T>& rhs) {
    return rhs + (-lhs);
}

template <typename T>
vectorspace::vector<T> operator-(const vectorspace::vector<T>& rhs) {
    return {rhs.vector_space, -rhs.elements};
}

#endif // VECTORSPACE_HPP