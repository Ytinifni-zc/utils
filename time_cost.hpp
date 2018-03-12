//
// Created by Ytinifini-zc on 2018/03/12
//

#ifndef UTILS_TIME_COST_HPP
#define UTILS_TIME_COST_HPP

#include <string>
#include <chrono>
#include <iostream>
#include <cassert>

/**
 * Calculate runtime of a function
 * @param L lambda expression
 * @param lambda lambda expression
 * @param unit computation unit. Must be us, ms or s.
 */
template<typename L>
void cost(L lambda, const std::string &unit="ms") {

    assert(unit == "us" || unit=="ms" || unit=="s");

    auto start = std::chrono::system_clock::now();
    lambda();
    auto end = std::chrono::system_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    auto den = std::chrono::milliseconds::period::den;
    if (unit == "s") den = std::chrono::microseconds::period::den;
    else if (unit == "us") den = 1;
    std::cout << "[" << double(duration.count())
                        *std::chrono::microseconds::period::num / den
              << unit << "]" << std::endl;

}


#endif //UTILS_TIME_COST_HPP
