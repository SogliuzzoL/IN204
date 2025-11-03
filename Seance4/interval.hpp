#pragma once

#include <cstddef>
#include <iterator>

class interval {
private:
  int minValue;
  int maxValue;

public:
  typedef int value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  interval(int theMinValue, int theMaxValue)
      : minValue(theMinValue), maxValue(theMaxValue) {}
  interval(const interval &anotherInterval)
      : minValue(anotherInterval.minValue), maxValue(anotherInterval.maxValue) {
  }
  interval &operator=(const interval &anotherInterval) {
    minValue = anotherInterval.minValue;
    maxValue = anotherInterval.maxValue;
    return *this;
  }
  size_type size() const { return (size_type)(maxValue - minValue); }
  int operator[](size_type anIndex) const {
    if (anIndex > size())
      throw std::out_of_range("Index out of range");
    return minValue + (int)anIndex;
  }
  bool operator==(const interval &anotherInterval) const {
    return anotherInterval.maxValue == maxValue &&
           anotherInterval.minValue == minValue;
  }
  bool operator!=(const interval &anotherInterval) const {
    return anotherInterval.maxValue != maxValue ||
           anotherInterval.minValue != minValue;
  }
};

class interval_iterator : public std::iterator<std::forward_iterator_tag, int> {
private:
  friend class interval;
  const interval *mInterval; // Référence à l'interval.
  int mCurrent;              // la valeur courante dont on fait référence.

  interval_iterator(const interval &anInterval, int aCurrentValue)
      : mInterval(&anInterval), mCurrent(aCurrentValue) {}

public:
  interval_iterator(const interval_iterator &anotherIterator)
      : mInterval(anotherIterator.mInterval),
        mCurrent(anotherIterator.mCurrent) {}

  interval_iterator &operator=(interval_iterator &anotherIterator) {
    mInterval = anotherIterator.mInterval;
    mCurrent = anotherIterator.mCurrent;
    return *this;
  }

  const reference operator*() const;
  const pointer operator->() const;
  interval_iterator &operator++();
  interval_iterator &operator++(int);
  bool operator==(const interval_iterator &) const;
  bool operator!=(const interval_iterator &) const;
};