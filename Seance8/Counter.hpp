#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>
#include <string>

class BaseCounter {
protected:
  unsigned counter;
  unsigned max;

public:
  unsigned getCounter() const { return counter; }
  unsigned getMax() const { return max; }
  void reset() { counter = 0; }
  void set(unsigned value) { counter = value; }
  void setMax(unsigned value) {
    max = value;
    if (value > counter)
      counter = counter % max;
  }

  virtual void next() {
    if (counter < max)
      counter += 1;
    else
      counter = 0;
  }

  virtual void next(unsigned step) { counter = (counter + step) % (max + 1); }

  virtual std::string getClassName() { return "BaseCounter"; }

protected:
  BaseCounter() : counter(0), max(0) {}
  BaseCounter(unsigned theCounter, unsigned theMax)
      : counter(theCounter), max(theMax) {}
  explicit BaseCounter(unsigned theMax) : max(theMax), counter(0) {}
  BaseCounter(const BaseCounter &anotherCounter)
      : counter(anotherCounter.counter), max(anotherCounter.max) {}
  ~BaseCounter() {}

  friend std::ostream &operator<<(std::ostream &, BaseCounter &aCounter) {
    return std::cout << aCounter.getClassName() << ": " << aCounter.counter
                     << " / Max: " << aCounter.max;
  }
};

class ForwardCounter : public virtual BaseCounter {
public:
  void increment() {
    if (counter < max)
      counter = counter + 1;
    else
      counter = 0;
  }

  ForwardCounter() : BaseCounter() {}
  ForwardCounter(const ForwardCounter &aCounter) : BaseCounter(aCounter) {}
  explicit ForwardCounter(unsigned theMaxValue)
      : ForwardCounter(0, theMaxValue) {}
  ForwardCounter(unsigned theCounter, unsigned theMaxValue)
      : BaseCounter(theCounter, theMaxValue) {}

  virtual void next() { increment(); }
  virtual void next(unsigned step) {
    for (unsigned i = 0; i < step; ++i)
      increment();
  }

  virtual std::string getClassName() { return "ForwardCounter"; }
};

class BackwardCounter : public virtual BaseCounter {
public:
  void decrement() {
    if (counter > 0)
      counter = counter - 1;
    else
      counter = max;
  }
  BackwardCounter() : BaseCounter() {}
  BackwardCounter(const ForwardCounter &aCounter) : BaseCounter(aCounter) {}
  explicit BackwardCounter(unsigned theMaxValue)
      : BackwardCounter(0, theMaxValue) {}
  BackwardCounter(unsigned theCounter, unsigned theMaxValue)
      : BaseCounter(theCounter, theMaxValue) {}

  virtual void next() { decrement(); }
  virtual void next(unsigned step) {
    for (unsigned i = 0; i < step; ++i)
      decrement();
  }

  virtual std::string getClassName() { return "BackwardCounter"; }
};

class BiDiCounter : public ForwardCounter, public BackwardCounter {
public:
  BiDiCounter() : ForwardCounter(), BackwardCounter() {}
  BiDiCounter(const BiDiCounter &aCounter)
      : ForwardCounter(aCounter),
        BackwardCounter((const BackwardCounter &)aCounter),
        BaseCounter(aCounter) {}
  BiDiCounter(unsigned theMaxValue) : BiDiCounter(0, theMaxValue) {}
  BiDiCounter(unsigned theCounter, unsigned theMaxValue)
      : ForwardCounter(theCounter, theMaxValue),
        BackwardCounter(theCounter, theMaxValue),
        BaseCounter(theCounter, theMaxValue) {}

  virtual void next() { ForwardCounter::next(); }
  virtual void next(unsigned step) { ForwardCounter::next(step); }

  virtual std::string getClassName() { return "BiDiCounter"; }
};
#endif // COUNTER_HPP