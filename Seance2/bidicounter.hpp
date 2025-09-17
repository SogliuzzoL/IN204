#pragma once
#include "basecounter.hpp"

class BiDiCounter : public BaseCounter {
public:
  BiDiCounter() : BaseCounter(){};
  BiDiCounter(const BiDiCounter &other) : BaseCounter(other){};
  explicit BiDiCounter(unsigned maxCount) : BaseCounter(maxCount){};
  BiDiCounter(unsigned currentCount, unsigned maxCount)
      : BaseCounter(currentCount, maxCount){};
  void decrement();
  void increment();
};