#include "generic_sort.hpp"
#include "simple_sort.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "Monomorphic version:" << std::endl;
  std::vector<int> MyVector;
  monomorphic::populate_with_randoms(MyVector, 10, 1, 10);
  monomorphic::print_vector(MyVector);
  monomorphic::simple_sort(MyVector);
  monomorphic::print_vector(MyVector);

  std::cout << "Generic version:" << std::endl;
  std::vector<float> AnotherVector;
  generic::populate_with_randoms(AnotherVector, 15, -10.0f, 10.0f);
  generic::print_vector(AnotherVector);
  generic::generic_sort(AnotherVector);
  generic::print_vector(AnotherVector);

  std::cout << "Generic version with chars:" << std::endl;
  std::vector<char> CharVector;
  generic::populate_with_randoms(CharVector, 25, (char)0x20, (char)0x7E);
  generic::print_vector(CharVector);
  generic::generic_sort(CharVector);
  generic::print_vector(CharVector);

  return 0;
}