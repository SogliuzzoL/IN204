#include "basecounter.hpp"
#include <iostream>

void BaseCounter::__increment() {
  counter++;
  if (counter > max)
    counter = 0;
}

void BaseCounter::__decrement() {
  if (counter == 0)
    counter = max;
  else
    counter--;
}

BaseCounter::BaseCounter() : counter(0), max(0) {}

BaseCounter::BaseCounter(uint maxCount) : counter(0), max(maxCount) {}

BaseCounter::BaseCounter(uint currentCount, uint maxCount)
    : counter(0), max(maxCount) {
  set(currentCount);
}

BaseCounter::BaseCounter(const BaseCounter &Counter)
    : counter(Counter.counter), max(Counter.max) {}

uint BaseCounter::getCounter() const { return counter; }

uint BaseCounter::getMax() const { return max; }

void BaseCounter::reset() { counter = 0; }

void BaseCounter::set(uint value) {
  counter = (value <= max) ? value : counter;
}

void BaseCounter::setMax(uint value) {
  if (counter >= value)
    counter = 0;
  max = value;
}

void BaseCounter::print() { std::cout << counter << "/" << max << std::endl; }