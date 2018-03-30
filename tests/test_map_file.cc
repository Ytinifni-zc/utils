#include <utils/map_file.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace common_utils;

int main(int argc, char const* argv[])
{
  if (argc != 2) {
    string msg = "[Usage]: " + string(argv[0]) + " {arbitraty file}";
    handle_error(msg.c_str());
  }
  size_t length = 0;
  auto addr = mmap_file<const char*>(argv[1], length);
  cout << "Length: " << length << "B" << endl;
  cout << addr << endl;
  return 0;
}
