#ifndef CounterHPP
#define CounterHPP

struct MyCounter {
  unsigned counter;
  unsigned max;

public:
  MyCounter();

  explicit MyCounter(unsigned maxCount);

  explicit MyCounter(unsigned currentCount, unsigned maxCount);

  MyCounter(const MyCounter &Counter);

  ~MyCounter();

  unsigned getCounter() const;
  unsigned getMax() const;

  void increment();

  void reset();

  void set(unsigned value);

  void setMax(unsigned value);
};

#endif