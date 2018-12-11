#ifndef UTILS_K_WAY_MERGE
#define UTILS_K_WAY_MERGE

#include <vector>
#include <queue>
#include <functional>
#include <limits>

namespace common_utils {

  template <typename T>
  std::vector<T> merge_sort(
      std::vector<std::vector<T>>& vlist,
      std::function<bool(const T&, const T&)> greater,
      T maxT = std::numeric_limits<T>::max()) {

    using Iter = typename std::vector<T>::iterator;
    auto iter_cmp = [&greater](const Iter& lhs, const Iter& rhs) -> bool {
      return greater(*lhs, *rhs);
    };

    std::priority_queue<Iter, std::vector<Iter>, decltype(iter_cmp)> pq(iter_cmp);
    std::vector<T> ret;
    for (auto& v: vlist) {
      v.push_back(maxT);
      pq.push(v.begin());
    }

    while (*pq.top() < maxT) {
      auto it = pq.top();
      ret.push_back(*it);
      it ++;
      pq.pop();
      pq.push(it);
    }

    for (auto& v: vlist) {
      v.pop_back();
    }
    return ret;
  }
}

#endif
