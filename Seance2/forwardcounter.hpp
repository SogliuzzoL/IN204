#pragma once
#include "basecounter.hpp"

class ForwardCounter : public BaseCounter {
public:
  ForwardCounter() : BaseCounter(){};
  ForwardCounter(const ForwardCounter &other) : BaseCounter(other){};
  explicit ForwardCounter(unsigned maxCount) : BaseCounter(maxCount){};
  ForwardCounter(unsigned currentCount, unsigned maxCount)
      : BaseCounter(currentCount, maxCount){};
  void increment();
};