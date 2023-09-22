#ifndef HILBERTSPACE_HPP
#define HILBERTSPACE_HPP

#include "vectorspace.hpp"

namespace vector
{
    template <typename T>
    struct HilbertSpace : VectorSpace<T> {};

    template <typename T>
    T inner_product(const HilbertSpace<T> &space, const std::vector<T> &lhs, const std::vector<T> &rhs)
    {
        T result = 0;
        for (int i = 0; i < space.bases.size(); i++)
        {
            result += space.bases[i] * conjugate(lhs[i]) * rhs[i];
        }
        return result;
    }
}

#endif // HILBERTSPACE_HPP