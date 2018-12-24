#include <iostream>
#include <utils/colormod.hpp>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "\033[1;31mbold red text\033[0m\n";
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);
  cout << "[" << green << "INFO" << def << "]: lalala.\n";
  return 0;
}
