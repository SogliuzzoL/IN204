#include <initializer_list>
#include <iostream>

#define PART2

#ifdef PART1
template <typename T> void print(std::initializer_list<T> list) {
  for (const auto &element : list) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::initializer_list<int> list_of_values = {1, 3, 4, 2};
  print(list_of_values);
}
#else
template <typename T> void print(T element) {
  std::cout << element << std::endl;
}

template <typename T, typename... Args> void print(T first, Args... args) {
  std::cout << first << " ";
  print(args...);
}

int main() { print(1, 2.5, "Hello", 'A'); }

#endif