#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <utils/k_way_merge.hpp>
#include <vector>

using namespace std;

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    os << " " << *ii;
  }
  os << "]";
  return os;
}

int main() {
  vector<vector<int>> vlist(3);
  vlist[0] = {3, 5, 6, 11, 14, 23, 40, 41, 49, 50};
  vlist[1] = {1, 5, 9, 10, 11, 30, 32, 40, 41, 90, 100, 121};
  vlist[2] = {2, 3, 4, 5, 7, 10, 11, 40, 40, 90, 100, 100, 122, 143};
  auto greater = [](const int &l, const int &r) { return l > r; };
  auto ret = common_utils::merge_sort<int>(vlist, greater);
  std::cout << ret << std::endl;
  return 0;
}
