#include <cmath>
#include <iostream>
#include <ostream>
#include <stdlib.h>

template <typename T> class vector2D {
protected:
  T x;
  T y;

public:
  vector2D() : x(0), y(0) {}
  vector2D(T X, T Y) : x(X), y(Y) {}
  vector2D(const vector2D &anotherVector2D)
      : x(anotherVector2D.x), y(anotherVector2D.y) {}

  T getX() const { return x; }
  T getY() const { return y; }

  static vector2D fromPolar(double norme, double angle) {
    return vector2D(norme * cos(angle), norme * sin(angle));
  }

  virtual double norm() const { return sqrt(x * x + y * y); }
  double angle() const { return atan2(y, x); }
  std::pair<double, double> toPolar() const {
    return std::pair<double, double>(norm(), angle());
  }

  bool operator==(const vector2D &anotherVector2D) const {
    return (x == anotherVector2D.x) && (y == anotherVector2D.y);
  }

  bool operator!=(const vector2D &anotherVector2D) const {
    return !(*this == anotherVector2D);
  }

  vector2D operator+(const vector2D &anotherVector2D) const {
    return vector2D(x + anotherVector2D.x, y + anotherVector2D.y);
  }
  vector2D operator-(const vector2D &anotherVector2D) const {
    return vector2D(x - anotherVector2D.x, y - anotherVector2D.y);
  }

  bool operator+=(const vector2D &anotherVector2D) {
    x += anotherVector2D.x;
    y += anotherVector2D.y;
    return true;
  }

  bool operator-=(const vector2D &anotherVector2D) {
    x -= anotherVector2D.x;
    y -= anotherVector2D.y;
    return true;
  }

  vector2D operator*(const vector2D &anotherVector2D) const {
    return vector2D(x * anotherVector2D.x, y * anotherVector2D.y);
  }
};

std::ostream &operator<<(std::ostream &os, const vector2D<double> &vec) {
  os << "{" << vec.getX() << ", " << vec.getY() << "}";
  return os;
}

template <typename T> class vector3D : public vector2D<T> {
private:
  T z;

public:
  vector3D() : vector2D<T>(), z(0) {}
  vector3D(T X, T Y, T Z) : vector2D<T>(X, Y), z(Z) {}
  vector3D(const vector3D &anotherVector3D)
      : vector2D<T>(anotherVector3D.getX(), anotherVector3D.getY()),
        z(anotherVector3D.z) {}

  T getZ() const { return z; }

  double norm() const override {
    return sqrt(this->x * this->x + this->y * this->y + z * z);
  }
};

template <typename T> void print_norm(const vector3D<T> &vec) {
  std::cout << "Norm: " << vec.norm() << std::endl;
}

int main() {
  vector3D<double> v3D(1, 2, 1);
  print_norm(v3D);
}