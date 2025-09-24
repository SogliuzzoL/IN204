#include "simple_sort.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>

namespace monomorphic {

void populate_with_randoms(std::vector<int> &theVector, int theNumberOfValues,
                           int theMinValue, int theMaxValue) {

  std::random_device rd;
  // Générateur de nombres alératoire qui est utilisé
  // comme racine d'une séquence de nombres aléatoires.
  std::minstd_rand generator(rd());
  // Générateur générant des nombres aléatoires initialisées
  // par une valeur tirée au hasard par le générateur rd.
  std::uniform_int_distribution<> distribution(theMinValue, theMaxValue);
  // Crée une distribution qui prend une valeur générée par un
  // générateur aléatoire et retournant une valeur uniformément
  // distribuée entre theMinValue et theMaxValue.

  for (int i = 0; i < theNumberOfValues; ++i) {
    int randomValue = distribution(generator);
    // Une valeur générée entre theMinValue et theMaxValue de
    // manière équiprobable.
    theVector.push_back(randomValue);
  }
}

void print_vector(const std::vector<int> &anArray) {
  for (const int &value : anArray) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

void simple_sort(std::vector<int> &theValues) {
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

} // namespace monomorphic