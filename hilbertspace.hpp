#ifndef HILBERTSPACE_HPP
#define HILBERTSPACE_HPP

#include "vectorspace.hpp"

namespace vectorspace
{
    template <typename T>
    struct HilbertSpace : VectorSpace<T> {
        HilbertSpace(VectorSpace<T> space) {
            this->origin = space.origin;
            this->bases = space.bases;
        }
    };

    template <typename T>
    T inner_product(const HilbertSpace<T> &space, const std::vector<T> &lhs, const std::vector<T> &rhs)
    {
        T result = T(0);
        int bases_size = space.bases[0].size(); // Segfault :|
        for (int i = 0; i < space.bases.size(); i++)
        {
            Complex<int> temp = lhs[i] * rhs[i];
            for (int j = 0; j < bases_size; j++) {
                result = result + space.bases[i][j] * temp;
            }
        }
        return result;
    }
}

#endif // HILBERTSPACE_HPP