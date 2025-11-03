#pragma once
#include <algorithm>
#include <concepts>

template <typename T>
concept has_greater_op = requires(T a, T b) {
  { a > b } -> std::convertible_to<bool>;
};

template <typename iterator>
concept sortable = requires(iterator a, iterator b) {
  { a != b } -> std::convertible_to<bool>;
  { a++ } -> std::same_as<iterator>;
  { *a } -> has_greater_op<>;
  { *a } -> std::swappable<>;
  { std::swap(*a, *b) };
};

template <typename iterator> void simple_sort(iterator start, iterator end) {
  for (; start != end; start++) {
    auto it = start;
    it++;
    for (; it != end; it++) {
      // Compare si les deux elements sont dans le bon ordre.
      if (*start > *it)
        std::swap(*start, *it);
    }
  }
}