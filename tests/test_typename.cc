#include <utils/type_name.hpp>
#include <iostream>
#include <tuple>

int main(int argc, char *argv[]) {
  auto t = std::forward_as_tuple(20, 'a');
  std::cout << type_name<decltype(t)>() << std::endl;
  return 0;
}
