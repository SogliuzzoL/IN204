#ifndef simple_sortHPP
#define simple_sortHPP

#include <vector>

namespace monomorphic {
void populate_with_randoms(std::vector<int> &theVector, int theNumberOfValues,
                           int theMinValue, int theMaxValue);

void print_vector(const std::vector<int> &anArray);

void simple_sort(std::vector<int> &theValues);
} // namespace monomorphic

#endif