#include "bicounter.hpp"
#include <iostream>

MyBiCounter::MyBiCounter() : MyCounter(){};

MyBiCounter::MyBiCounter(MyBiCounter &other) : MyCounter(other){};

MyBiCounter::MyBiCounter(unsigned maxCount) : MyCounter(maxCount){};

MyBiCounter::MyBiCounter(unsigned currentCount, unsigned maxCount)
    : MyCounter(currentCount, maxCount){};

void MyBiCounter::decrement() {
  if (counter == 0)
    counter = max;
  else
    counter--;
}

void MyBiCounter::print() { std::cout << counter << "/" << max << std::endl; }