#pragma once
#include <sys/types.h>

class BaseCounter {
protected:
  uint counter;
  uint max;
  void __increment();
  void __decrement();
  BaseCounter();
  explicit BaseCounter(uint maxCount);
  BaseCounter(uint currentCount, uint maxCount);
  BaseCounter(const BaseCounter &Counter);

public:
  uint getCounter() const;
  uint getMax() const;
  void reset();
  void set(uint value);
  void setMax(uint value);
  void print();
};