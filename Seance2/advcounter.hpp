#pragma once
#include "counter.hpp"
#include <sys/types.h>

class MyAdvCounter : public MyCounter {
public:
  using MyCounter::MyCounter;
  void increment();
};