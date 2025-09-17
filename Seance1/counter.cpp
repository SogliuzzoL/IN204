#include "counter.hpp"
#include <iostream>

MyCounter::MyCounter() : counter(0), max(0){};

MyCounter::MyCounter(unsigned maxCount) : counter(0), max(maxCount){};

MyCounter::MyCounter(unsigned currentCount, unsigned maxCount)
    : counter(0), max(maxCount) {
  set(currentCount);
}

MyCounter::MyCounter(const MyCounter &Counter)
    : counter(Counter.counter), max(Counter.max) {}

MyCounter::~MyCounter() {
  std::cout << "Destruction de MyCounter ayant pour valeur " << counter
            << " et pour valeur maximale " << max << std::endl;
}

unsigned MyCounter::getCounter() const { return counter; }

unsigned MyCounter::getMax() const { return max; }

void MyCounter::increment() {
  counter++;
  if (counter > max)
    counter = 0;
}

void MyCounter::reset() { counter = 0; }

void MyCounter::set(unsigned value) {
  counter = (value <= max) ? value : counter;
}

void MyCounter::setMax(unsigned value) {
  if (counter >= value)
    counter = 0;
  max = value;
}