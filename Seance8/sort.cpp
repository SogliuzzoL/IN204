#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class Base {
public:
  virtual bool isGreater(const Base &) const = 0;
  virtual void print() const = 0;
};

class Entier : public Base {
private:
  int m_value;

public:
  Entier() : m_value(0) {}
  Entier(int aValue) : m_value(aValue) {}
  operator int() { return m_value; }

  void print() const { std::cout << m_value; }
  bool isGreater(const Base &unEntier) const {
    return m_value > dynamic_cast<const Entier &>(unEntier).m_value;
  }
};

class Reel : public Base {
private:
  double m_value;

public:
  Reel() : m_value(0) {}
  Reel(double aValue) : m_value(aValue) {}
  operator double() { return m_value; }

  void print() const { std::cout << m_value; }
  bool isGreater(const Base &unReel) const {
    return m_value > dynamic_cast<const Reel &>(unReel).m_value;
  }
};

void print(std::vector<Base *> anArray) {
  std::cout << "[";
  for (const auto &elem : anArray) {
    elem->print();
    std::cout << ", ";
  }
  std::cout << "]";
}

std::vector<Base *> create_integer_array(size_t theNumberOfValues) {
  std::vector<Base *> result;
  result.resize(theNumberOfValues);
  for (int i = 0; i < theNumberOfValues; i++)
    result[i] = new Entier(i);
  return result;
}

std::vector<Base *> create_random_integer_array(size_t theNumberOfValues,
                                                int theMinValue,
                                                int theMaxValue) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(theMinValue, theMaxValue);
  std::vector<Base *> array(theNumberOfValues);
  for (size_t i = 0; i < theNumberOfValues; i++)
    array[i] = new Entier(distr(gen));
  return array;
}

std::vector<Base *> create_random_double_array(size_t theNumberOfValues,
                                               double theMinValue,
                                               double theMaxValue) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> distr(theMinValue, theMaxValue);
  std::vector<Base *> array(theNumberOfValues);
  for (size_t i = 0; i < theNumberOfValues; i++)
    array[i] = new Reel(distr(gen));
  return array;
}

void insertion_sort(std::vector<Base *> &anArray) {
  for (int i = 0; i < anArray.size(); i++) {
    for (int j = i + 1; j < anArray.size(); j++) {
      if (anArray[i]->isGreater(*anArray[j]))
        std::swap(anArray[i], anArray[j]);
    }
  }
}

void testTriReel() {
  std::vector<Base *> reels = create_random_double_array(10, -1, 1);
  print(reels);
  std::cout << std::endl;
  insertion_sort(reels);
  print(reels);
  std::cout << std::endl;
}

void testTriEntier() {
  std::vector<Base *> entiers = create_random_integer_array(10, -100, 100);
  print(entiers);
  std::cout << std::endl;
  insertion_sort(entiers);
  print(entiers);
  std::cout << std::endl;
}

int main() {
  testTriEntier();
  testTriReel();
}