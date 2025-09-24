#ifndef generic_sortHPP
#define generic_sortHPP

#include <iostream>
#include <random>
#include <vector>

namespace generic {
// Version générique des fonctions
template <typename T>
void populate_with_randoms(std::vector<T> &theVector, int theNumberOfValues,
                           T theMinValue, T theMaxValue) {
  std::random_device rd;
  std::minstd_rand generator(rd());
  std::uniform_int_distribution<> distribution(theMinValue, theMaxValue);
  for (int i = 0; i < theNumberOfValues; ++i) {
    T randomValue = distribution(generator);
    theVector.push_back(randomValue);
  }
}

template <typename T> void print_vector(const std::vector<T> &anArray) {
  for (const T &value : anArray) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

template <typename T> void generic_sort(std::vector<T> &theValues) {
  for (int i = 0; i < theValues.size(); i++) {
    for (int j = i + 1; j < theValues.size(); j++) {
      // Compare si les deux elements sont dans le bon ordre.
      if (theValues[i] > theValues[j]) {
        // Procede a la permutation des deux elements
        int Temp = theValues[i];
        theValues[i] = theValues[j];
        theValues[j] = Temp;
      }
    }
  }
}
} // namespace generic

#endif