//
// Create by Ytinifni-zc on 2018-03-27
//

#ifndef UTILS_MAP_FILE_HPP
#define UTILS_MAP_FILE_HPP

#include <sys/mman.h>
#include <sys/stat.h>
#include <cstdio>
#include <fcntl.h>
#include <cstdlib>
#include <cstring>

void handle_error(const char* msg) {
  perror(msg);
  exit(255);
}

/**
 * Load file to memory by mmap.
 * @param filename
 * @param length Length of file (byte).
 * @return Pointer of the file in memory.
 */
template<typename T> 
T mmap_file(const char* filename, size_t& length) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    handle_error("open");
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    handle_error("fstat");
  }
  length = st.st_size;
  
  T addr = static_cast<T>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
  if (addr == MAP_FAILED) {
    handle_error("mmap");
  }

  return addr;
}

/**
 * Free the mmap memory.
 * @param addr The mmap memory pointer.
 * @param length Length of the chunk.
 */
void munmap_file(void* addr, size_t length) {
  if (munmap(addr, length) == -1)
    handle_error("munmap");
}

#endif // UTILS_MAP_FILE_HPP
