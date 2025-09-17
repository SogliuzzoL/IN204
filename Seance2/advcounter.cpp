#include "advcounter.hpp"

void MyAdvCounter::increment() {
  counter++;
  if (counter > max)
    counter = max;
}