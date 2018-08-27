# utils

Useful utils in C++ programs, like computing of time cost.

## Install

`./install.sh all`
Details in `./install.sh --help` or `./install.sh -h`

## Usage

### Time cost

```
template<typename L>
void cost(L lambda, const std::string &unit="ms");
  // Calculate runtime of a function.
  @param L lambda expression
  @param lambda lambda expression
  @param unit computation unit. Must be us, ms or s.
```

### String Split

```
std::vector<std::string> string_split(std::string s, const char delimiter);
  // Split string by a signle character.
  @param s The string.
  @param delimiter Single character delimiter
  @return splited string.
```

### Map File

```
T mmap_file(const char* filename, size_t& length);
  // Load file to memory by mmap.
  @param filename
  @param length Length of file (byte).
  @return Pointer of the file in memory.

void munmap_file(void* addr, size_t length);
  // Free the mmap memory.
  @param addr The mmap memory pointer.
  @param length Length of the chunk.
```

### Type Name

```
std::string type_name<decltype(val)>();
```
