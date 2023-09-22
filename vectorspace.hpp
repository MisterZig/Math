#ifndef VECTORSPACE_HPP
#define VECTORSPACE_HPP

#include <vector>

namespace vector {
    template <typename T>
    struct VectorSpace {
        std::vector<T> origin;
        std::vector<std::vector<T>> bases;
    };

    template <typename T>
    struct vector {
        VectorSpace vector_space;
        std::vector<T> elements;
    };
}

#endif // VECTORSPACE_HPP