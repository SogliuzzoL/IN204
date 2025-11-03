#include <algorithm>
#include <iostream>
#include <vector> // std::vector

// template <class T> int upper(std::vector<T> aVector, const T &theValue) {
//   for (int i = 0; i < aVector.size(); i++) {
//     if (aVector[i] > theValue)
//       return i;
//   }
//   return -1;
// }

template <class inputIterator, class T>
inputIterator upper(inputIterator first, inputIterator end, const T &theValue) {
  std::sort(first, end);
  for (; first != end; first++) {
    if (*first > theValue)
      return first;
  }
  return end;
}

int testUpper() {
  int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
  std::vector<int> v(myints, myints + 8);
  std::vector<int>::iterator up = upper(v.begin(), v.end(), 20);
  std::cout << "first value greater than 20 at position " << (up - v.begin())
            << '\n';
  return 0;
}

int main() { return testUpper(); }