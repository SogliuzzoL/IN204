#pragma once
#include "counter.hpp"

class MyBiCounter : public MyCounter {
public:
  //   using MyCounter::MyCounter;
  MyBiCounter();
  MyBiCounter(MyBiCounter &other);
  explicit MyBiCounter(unsigned maxCount);
  MyBiCounter(unsigned currentCount, unsigned maxCount);
  void decrement();
  void print();
};