#include <iostream>
#include <utils/split.hpp>

using namespace std;

int main(int argc, char const* argv[])
{
  string test_str = "asdf.asdf.asdf";
  auto list = string_split(test_str, '.');
  for (auto s : list) {
    cout << s << endl;
  }
  return 0;
}
