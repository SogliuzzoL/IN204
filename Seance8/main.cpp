#include "Counter.hpp"

void testForwardCounter() {
  ForwardCounter fc(5);

  std::cout << "Testing ForwardCounter:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << fc << "\n";
    fc.next();
  }

  std::cout << "Testing ForwardCounter with step 3:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << fc << "\n";
    fc.next(3);
  }
}

void testBackwardCounter() {
  BackwardCounter bc(5);

  std::cout << "Testing BackwardCounter:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << bc << "\n";
    bc.next();
  }

  std::cout << "Testing BackwardCounter with step 3:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << bc << "\n";
    bc.next(3);
  }
}

void testBiDiCounter() {
  BiDiCounter bdc(5);

  std::cout << "Testing BiDiCounter:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << bdc << "\n";
    bdc.next();
  }

  std::cout << "Testing BiDiCounter with step 3:\n";

  for (int i = 0; i < 10; i++) {
    std::cout << bdc << "\n";
    bdc.next(3);
  }
}

int main() {
  testForwardCounter();
  testBackwardCounter();
  testBiDiCounter();
  return 0;
}