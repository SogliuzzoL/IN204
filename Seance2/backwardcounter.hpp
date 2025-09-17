#pragma
#include "basecounter.hpp"

class BackwardCounter : public BaseCounter {
public:
  BackwardCounter() : BaseCounter(){};
  BackwardCounter(const BackwardCounter &other) : BaseCounter(other){};
  explicit BackwardCounter(unsigned maxCount) : BaseCounter(maxCount){};
  BackwardCounter(unsigned currentCount, unsigned maxCount)
      : BaseCounter(currentCount, maxCount){};
  void decrement();
};