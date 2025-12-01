#include <chrono>
#include <iostream>
#include <utility>

template <typename T> constexpr T factorial(T n) {
  return n == 0 ? 1 : (n * factorial(n - 1));
}

template <typename T>
std::pair<std::chrono::high_resolution_clock::duration, T>
estimate_factorial_time(T n) {
  auto start = std::chrono::high_resolution_clock::now();
  T result = factorial(n);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = end - start;
  return std::make_pair(duration, result);
}

template <class numericalT>
constexpr numericalT power_by_int(numericalT x, int y) {
  numericalT result = (numericalT)1.0;
  while (y-- > 0)
    result *= x;
  return result;
}

template <typename F, typename... Args>
auto estimate_function_time(F function, Args... args) {
  auto start = std::chrono::high_resolution_clock::now();
  auto result = function(args...);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = end - start;
  return std::make_pair(duration, result);
}

template <typename F, typename... Args>
long mean_function_time(int number_of_runs, F function, Args... args) {
  long total_time = 0;
  for (int i = 0; i < number_of_runs; ++i) {
    auto start = std::chrono::high_resolution_clock::now();
    function(args...);
    auto end = std::chrono::high_resolution_clock::now();
    total_time +=
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count();
  }
  return total_time / number_of_runs;
}

int main() {
  auto result_factorial = estimate_factorial_time((long double)1754);
  std::cout << "Factorial: " << result_factorial.second << ", Time taken: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   result_factorial.first)
                   .count()
            << " ns" << std::endl;

  auto result_power =
      estimate_function_time(power_by_int<long double>, 1.0002, 10000000);
  std::cout << "Power: " << result_power.second << ", Time taken: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   result_power.first)
                   .count()
            << " ns" << std::endl;

  int runs = 10;
  long mean_time =
      mean_function_time(runs, power_by_int<long double>, 1.0002, 10000000);
  std::cout << "Mean time over " << runs << " runs: " << mean_time << " ns"
            << std::endl;

  auto fn = estimate_function_time(factorial<long double>, 100);
  std::cout << "Computing fact(100)=" << fn.second << " in " << fn.first.count()
            << " ticks.\n";

  auto pw = estimate_function_time(power_by_int<long double>, 1.0002, 1000000);
  std::cout << "Computing 1.02^100000=" << pw.second << " in "
            << pw.first.count() << " ticks.\n";

  auto factorial_100 = []() { return factorial((long double)100); };
  fn = estimate_function_time(factorial_100);
  std::cout << "Computing fact(100)=" << fn.second << " in " << fn.first.count()
            << " ticks.\n";

  auto power_10002_100000 = []() {
    return power_by_int<long double>(1.0002, 100000);
  };
  pw = estimate_function_time(power_10002_100000);
  std::cout << "Computing 1.02^1000000=" << pw.second << " in "
            << pw.first.count() << " ticks.\n";
}