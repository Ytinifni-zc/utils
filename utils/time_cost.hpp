//
// Created by Ytinifini-zc on 2018/03/12
//

#ifndef UTILS_TIME_COST_HPP
#define UTILS_TIME_COST_HPP

#include <string>
#include <chrono>
#include <iostream>
#include <cassert>

namespace common_utils {

/**
 * Calculate runtime of a function.
 * @param L lambda expression
 * @param lambda lambda expression
 * @param unit computation unit. Must be us, ms or s.
 */
template<typename L>
double cost(L lambda, const std::string &unit="ms", bool print=true) {

  assert(unit == "us" || unit=="ms" || unit=="s");

  auto start = std::chrono::system_clock::now();
  lambda();
  auto end = std::chrono::system_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  auto den = std::chrono::milliseconds::period::den;
  if (unit == "s") den = std::chrono::microseconds::period::den;
  else if (unit == "us") den = 1;
  double ret = double(duration.count())
            *std::chrono::microseconds::period::num / den;
  if (print)
    std::cout << "[" << ret << unit << "]" << std::endl;
  return ret;

}

} // namespace common_utils

#endif //UTILS_TIME_COST_HPP
