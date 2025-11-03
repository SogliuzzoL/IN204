#include "simple_sort.hpp"
#include <iostream>
#include <list>

int main() {
  std::list<int> v = {1, 7, 3, 4, 9, 2, 5};
  simple_sort(v.begin(), v.end());
  for (const auto &e : v)
    std::cout << e << " ";
  std::cout << std::endl;
  //   std::cout << v;
  return 0;
}