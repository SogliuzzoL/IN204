#include "backwardcounter.hpp"
#include "bicounter.hpp"
#include "bidicounter.hpp"
#include "counter.hpp"
#include "forwardcounter.hpp"
#include <iostream>

void useObjectA() {
  MyCounter Counter1(2);
  MyCounter Counter2(4);
  for (unsigned i = 0; i <= 5; i++) {
    std::cout << "Valeur des compteurs (" << Counter1.counter << ", "
              << Counter2.counter << ")" << std::endl;
    Counter1.increment();
    Counter2.increment();
  }
}

void myfunctionA() {
  MyCounter counter;
  std::cout << counter.getCounter() << std::endl;
  std::cout << counter.getMax() << std::endl;
}

void myfunctionB() {
  MyCounter *counter = new MyCounter();
  std::cout << counter->getCounter() << std::endl;
  std::cout << counter->getMax() << std::endl;
  delete counter;
}

void testMyBiCounter() {
  MyBiCounter counterA(4);
  counterA.print();
  for (int i = 0; i < 6; i++) {
    counterA.increment();
    counterA.print();
  }
  for (int i = 0; i < 6; i++) {
    counterA.decrement();
    counterA.print();
  }
}

void testFamilyOfCounters() {
  ForwardCounter incCounter(0, 4);
  BackwardCounter decCounter(0, 3);
  BiDiCounter biDiCounter(0, 5);
  for (int i = 0; i < 6; i++) {
    incCounter.increment();
    incCounter.print();
    decCounter.decrement();
    decCounter.print();
    biDiCounter.increment();
    biDiCounter.print();
  }
  for (int i = 0; i < 6; i++) {
    biDiCounter.decrement();
    biDiCounter.print();
  }
}

int main() {
  testFamilyOfCounters();
  return 0;
}